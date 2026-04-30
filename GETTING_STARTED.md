# Configuring DDR Parameters Using the ddr-umctl Tool

## Overview

The ddr-umctl tool generates DDR controller configuration files for Microchip SoC platforms. It takes a human-readable configuration profile as input and produces platform-specific output (C source, devicetree, or YAML) that is committed to the target firmware repository.

It may be required to reconfigure DDR parameters when changing the DDR component, modifying the PCB layout, or porting to a new board design.

The tool is available on GitHub (https://github.com/microchip-ung/ddr-umctl).

## Requirements

- Linux or Windows machine (the Windows environment may require installing the WSL2 package to emulate Linux).
- Ruby scripting language.

> **Note:** These instructions are based on a Linux (Ubuntu) machine.

## Supported Platforms

This tool supports the following target SoC platforms:

| Platform | DDR types      | Bus width | ECC type  |
|----------|----------------|-----------|-----------|
| SparX5   | DDR3, DDR4     | 32-bit    | Sideband  |
| LAN966x  | DDR3 only      | 16-bit    | Inline    |
| LAN969x  | DDR3, DDR4     | 16-bit    | Inline    |

> **Note:** All platforms support a half-bus width mode where the effective bus width is halved. On LAN966x and LAN969x this requires a board with x8 DRAM devices; the existing evaluation boards for these platforms use x16 devices and cannot be used to test half-bus operation. SparX5 evaluation boards support half-bus mode.

## Repository Structure

```
configs/
  profiles/       Configuration profiles — one file per board/platform combination.
                  Each profile references a board file and a memory profile.
  boards/         Board files — PHY impedance, ODT, and drive strength settings,
                  plus optional direct register overrides.
  memory/         Memory address map files — ADDRMAP register values describing
                  how HIF address bits map to rank, bank, row, and column.

scripts/
  gen_cfg.rb      Main entry point: generates devicetree, C source, or YAML output
                  from a profile.
  diff_cfg.rb     Compares two YAML configs and shows changed register fields.
  fmt_cfg.rb      Converts an existing YAML config to devicetree or C source format
                  without recalculating timing.
  make_headers.rb Regenerates per-platform C headers and JavaScript register maps
                  from ERB templates and SoC YAML.
  ddr/            JEDEC timing calculation — ddr3.rb, ddr4.rb, ddr_process.rb.
  soc/            Register abstraction — chip.rb and per-platform register map YAMLs.
  templates/      ERB templates for all output formats and generated headers.
  support/        Utility scripts (log annotation, register analysis, etc.).

src/              C driver source (ddr_umctl.c). Built by CMake into a standalone
                  test binary. src/*_config.c files are generated — do not edit.

include/
  sparx5/         Generated C headers for sparx5 (ddr_config.h, ddr_reg.h, etc.)
  lan966x/        Generated C headers for lan966x.
  lan969x/        Generated C headers for lan969x.

doc/              User documentation: ddr-umctl.adoc (workflow and parameters),
                  registers.adoc (supported register reference).

build/            CMake build directory.
```

## Getting Started

### Generating a Configuration File

The configuration file is generated using the `gen_cfg.rb` Ruby script, located in the `scripts` folder.

```
./scripts/gen_cfg.rb -f <format> configs/profiles/<profile>.yaml
```

While generating the configuration file, `gen_cfg.rb` loads two additional `.yaml` files referenced from the profile: `:board` (board-specific calibration and drive settings, directory – `configs/boards`) and `:mem_profile` (memory address mapping, directory – `configs/memory`).

### Platform-Specific Output Targets

#### SparX5

Output format: devicetree (`.dtsi`). Target repository: U-Boot.

DDR4 example (pcb134):

```
./scripts/gen_cfg.rb -f devicetree configs/profiles/pcb134_ddr4.yaml > \
    <u-boot>/arch/arm/dts/mscc,sparx5_ddr4.dtsi
```

DDR3 example (pcb135):

```
./scripts/gen_cfg.rb -f devicetree configs/profiles/pcb135_ddr3.yaml > \
    <u-boot>/arch/arm/dts/mscc,sparx5_ddr3.dtsi
```

Commit message prefix convention: `arm: dts: sparx5:`

#### LAN966x

Output format: C source (`.c`). Target repository: Trusted Firmware-A (TFA).

```
./scripts/gen_cfg.rb -f source configs/profiles/lan966x.yaml > \
    <tfa>/plat/microchip/lan966x/common/lan966x_ddr_config.c
```

Commit message prefix convention: `plat/microchip: lan966x:`

#### LAN969x

Output format: devicetree (`.dtsi`). Target repository: Trusted Firmware-A (TFA).

DDR4 example (EVB):

```
./scripts/gen_cfg.rb -f devicetree configs/profiles/lan969x_evb_ddr4.yaml > \
    <tfa>/plat/microchip/lan969x/fdts/lan969x-ddr.dtsi
```

DDR3 example (SVB):

```
./scripts/gen_cfg.rb -f devicetree configs/profiles/lan969x_svb_ddr3.yaml > \
    <tfa>/plat/microchip/lan969x/fdts/lan969x-ddr3.dtsi
```

Commit message prefix convention: `plat/microchip: lan969x:`

## Adapting a Profile for a New Board

The easiest starting point is to copy an existing profile for the same platform and modify it.

1. Copy a profile close to your board design:
   ```
   cp configs/profiles/pcb134_ddr4.yaml configs/profiles/myboard_ddr4.yaml
   ```

2. Edit the new profile to point to your board file (`:board`) and adjust top-level parameters such as `:clock_speed`, `:mem_type`, and `:device_bus_width`.

3. Create or copy a board file in `configs/boards/` and adjust the `:params` section (ODT, drive strength) and `:registers` section (direct register overrides) to match your PCB layout.

4. Regenerate and compare against the baseline to review the effect of your changes:
   ```
   ./scripts/gen_cfg.rb -f yaml configs/profiles/myboard_ddr4.yaml > output/myboard_ddr4.yaml
   ./scripts/diff_cfg.rb output/pcb134_ddr4.yaml output/myboard_ddr4.yaml
   ```

Board `:params` (e.g. `odt_nom_ddr`, `drive_strength`) feed into timing calculations and must be set before regenerating — a stale generated output will not reflect changes to these values.

## Verifying a Configuration Before Committing

Always generate in YAML format first and inspect the result before writing to the target repository. YAML output is human-readable and easy to diff:

```
./scripts/gen_cfg.rb -f yaml configs/profiles/myboard_ddr4.yaml > output/myboard_ddr4.yaml
```

Compare against a known-good reference:

```
./scripts/diff_cfg.rb output/reference.yaml output/myboard_ddr4.yaml
```

A diff can also be produced by piping `gen_cfg.rb` output directly:

```
./scripts/gen_cfg.rb -f yaml configs/profiles/myboard_ddr4.yaml | \
    ./scripts/diff_cfg.rb -p sparx5 - output/reference.yaml
```

Only when the YAML output looks correct should the final `devicetree` or `source` output be generated and committed to the target repository.

## Debugging

> **Note:** The FWU (Firmware Update) tool, which is part of the ARM Trusted Firmware for LAN969x and LAN966x, has capabilities to load and apply DDR configurations at runtime without recompiling the firmware. This is useful for iterating on DDR parameters during bring-up or board validation.

Add `-v` (verbose) or `-d` (debug) to log calculated intermediate values to stderr while generating:

```
./scripts/gen_cfg.rb -d -f yaml configs/profiles/myboard_ddr4.yaml > output/myboard_ddr4.yaml
```

If you already have a YAML output and want to convert it to `source` or `devicetree` format without re-running all timing calculations, use `fmt_cfg.rb`:

```
./scripts/fmt_cfg.rb -f devicetree -p sparx5 output/myboard_ddr4.yaml
```

This is useful for quickly switching output format on a previously generated and verified YAML file.

## Reference

### Supported Clock Speeds

The `clock_speed` parameter (in MT/s) controls a large number of calculated timing values. Valid speeds per platform:

| Platform | Supported speeds (MT/s)      | Notes |
|----------|------------------------------|-------|
| SparX5   | 2000, 1667, 1250             | DDR4 tested up to 1667 MT/s on production boards |
| LAN966x  | 1200                         | Fixed clock, no other speeds supported |
| LAN969x  | 2660, 2400, 2133, 1866, 1600 | Default is 2400 MT/s |

Note: clock speed is given in MT/s as is customary with DDR memory; the actual clock runs at half this frequency.

### Further Reading

- `doc/ddr-umctl.adoc` — full workflow description and configuration parameter reference
- `doc/registers.adoc` — supported register and field reference

## Metadata

**Devices:** SparX5, LAN966x, LAN969x

**Keywords:** DDR configuration, SparX5, LAN969x, LAN966x, ddr_umctl, DDR3, DDR4

**Categories:** General Topic: Ethernet — Specific Topic: DDR configuration – Ethernet switches

**Visibility:** Internal App, Customer, Partner, Public Knowledge Base
