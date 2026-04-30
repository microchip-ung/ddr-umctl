# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo does

DDR memory controller configuration generator for Microchip SoCs using the Synopsys uMCTL2 DDR controller and associated MultiPHY (PUB). It produces register configuration artifacts (C structs, YAML, devicetree, JavaScript) from human-readable YAML profile + memory + board files.

Supported platforms: **sparx5** (32-bit bus, sideband ECC), **lan966x** (16-bit bus, inline ECC, DDR3 only), **lan969x** (16-bit bus, inline ECC, DDR3/DDR4).

## Build

```bash
cd build
cmake ..
make
```

CMake drives two things: generating `output/*.yaml` and `src/*_config.c` via `scripts/gen_cfg.rb`, then compiling the standalone `sparx5_ddr_umctl` test binary from `src/`.

`src/*_config.c` files are **generated** — do not edit them by hand.

## Generating configs manually

```bash
# YAML output (human-readable, for inspection and diffing)
./scripts/gen_cfg.rb -f yaml configs/profiles/<profile>.yaml

# C source output (for the driver)
./scripts/gen_cfg.rb -f source configs/profiles/<profile>.yaml

# Devicetree output
./scripts/gen_cfg.rb -f devicetree configs/profiles/<profile>.yaml
```

Add `-v` for verbose (INFO) or `-d` for debug logging to stderr.

## Diffing two configs

```bash
./scripts/diff_cfg.rb output/pcb134_ddr4.yaml output/pcb134_ddr4_half_ecc.yaml
# or pipe gen_cfg output directly:
./scripts/gen_cfg.rb -f yaml configs/profiles/A.yaml | \
  ./scripts/diff_cfg.rb -p sparx5 - output/B.yaml
```

## Regenerating C headers

The per-platform headers under `include/<platform>/` (ddr_config.h, ddr_reg.h, ddr_xlist.h) and the JavaScript register map files are generated from ERB templates + SoC YAML:

```bash
./scripts/make_headers.rb
```

## Downstream target repositories

Generated configs are committed to separate repos per platform:

| Platform | Repo    | Path                                          | Format      |
|----------|---------|-----------------------------------------------|-------------|
| sparx5   | U-Boot  | `arch/arm/dts/mscc,sparx5_ddr{3,4}.dtsi`     | devicetree  |
| lan966x  | TFA     | `plat/microchip/lan966x/common/lan966x_ddr_config.c` | C struct |
| lan969x  | TFA     | `plat/microchip/lan969x/fdts/lan969x-ddr{,3}.dtsi`  | devicetree  |

Commit message prefix conventions: `arm: dts: sparx5:` for U-Boot; `plat/microchip: lan966x:` / `plat/microchip: lan969x:` for TFA.

## Config pipeline architecture

A profile YAML (`configs/profiles/<name>.yaml`) references:
- `:platform` — selects the SoC (`sparx5`, `lan966x`, `lan969x`)
- `:board` — loads `configs/boards/<board>.yaml` (PHY impedance/ODT overrides)
- `:mem_profile` — loads `configs/memory/<profile>.yaml` (ADDRMAP register values)
- `:mem_type` — `DDR3` or `DDR4`

Board files have two sections: `:params` (feed into timing calculations — e.g. `odt_nom_ddr`, `drive_strength` — before `ddr3()`/`ddr4()` is called) and `:registers` (direct field overrides applied after all register values are computed). A stale generated output will not reflect board `:params` changes until regenerated.

`scripts/gen_cfg.rb` orchestrates:
1. Load profile + board + memory YAMLs, merge params
2. Call `ddr3()` or `ddr4()` (in `scripts/ddr/`) to compute JEDEC timing parameters in DDR clock cycles
3. Call `ddr_process()` to compute PHY/PLL init timing
4. Map all parameters to uMCTL2 and PUB register fields
5. Render via ERB template

**Half-rate core clock:** The uMCTL2 on these platforms runs at half the DDR data rate. All timing values in DDR clocks must be divided by 2 (ceiling-rounded) before writing to uMCTL2 registers. PHY/PUB registers use raw DDR clock values.

## SoC register abstraction (`scripts/soc/`)

- `chip.rb` defines three classes:
  - `SoC` — loads `scripts/soc/<platform>.yaml` (full register map with field definitions, addresses, and documentation)
  - `Config` — filters the register set to only those relevant for the platform (DDR3/DDR4, ECC type). `@@ddr4` lists registers excluded on DDR3-only platforms (includes ZQ0PR/ZQ1PR/ZQ2PR/ZQCR); `@@ddr3` lists registers excluded on DDR4-capable platforms.
  - `Chip` — top-level, exposes `find()`, `find_all()`, `fields()`, `has_field?()`, `regaddr()`, etc.
- `scripts/soc/<platform>.yaml` — large auto-generated register map (do not edit manually)

**Field names are platform-specific.** Even standard uMCTL2 registers can have different field names across controller revisions. Always look up field names from the platform's own YAML before decoding register values or writing commit messages. Known difference: RFSHTMG refresh interval field is `T_RFC_NOM_X32` on sparx5 but `T_RFC_NOM_X1_X32` on lan966x and lan969x.

**`RegSettings#set` validates field names** against the register definition and raises `RuntimeError` on unknown fields. Code-driven `set()` calls must use valid field names; YAML-sourced board/memory overrides silently skip absent fields (platform-specific fields are handled this way).

## Platform capabilities (chip.rb)

| Platform | `bus_width` | `only_ddr3` | `ecc_sideband` | `ecc_inline` |
|----------|-------------|-------------|----------------|--------------|
| sparx5   | 32          | false       | true           | false        |
| lan966x  | 16          | true        | false          | true         |
| lan969x  | 16          | false       | false          | true         |

ECC lane mapping (fixed by hardware bus width):
- 32-bit bus (sparx5): ECC byte at DQ[39:32] → **DX4**
- 16-bit bus: ECC byte at DQ[23:16] → DX2 (but 16-bit platforms use inline ECC, no dedicated PHY lane)

## Driver (`src/ddr_umctl.c`)

The C driver consumes a `struct ddr_config` (defined in `include/<platform>/ddr_config.h`) and initialises the controller in this sequence:
1. Write uMCTL2 registers (main, timing, mapping)
2. Write PHY registers; enable DX lanes based on effective bus width + ECC mode
3. PHY initialisation (PLL, impedance cal)
4. DRAM initialisation (by PUB)
5. Data training (write leveling, DQS gate, eye centering, VREF for DDR4)
6. ECC scrubbing (if ECC enabled)

Effective bus width = `cfg->info.bus_width >> MSTR.DATA_BUS_WIDTH`. The driver enables DX0–DX1 for 16-bit, DX0–DX3 for 32-bit, plus DX4 for ECC (sparx5 only).

## YAML loading

All YAML must be loaded with:
```ruby
YAML.safe_load_file(fname, permitted_classes: [Symbol])
```
Ruby 3.0 (the version in use) requires `permitted_classes:` — `symbolize_names:` is not available until Ruby 3.1.

## Half-bus memory profiles (`configs/memory/`)

Half-bus mode (`enable_half_bus: true` in the profile) halves the effective bus width. The memory profile (`mem_profile`) must match the device organization actually used — not the physical bus width of the board.

| File | Platform | Type | Status |
|------|----------|------|--------|
| `ddr4_512Mx8_halfbus_sparx5.yaml` | sparx5 | DDR4, x8, sideband ECC | tested |
| `ddr4_512Mx8_halfbus_lan969x.yaml` | lan969x | DDR4, x8, inline ECC | **NOT tested** |
| `ddr3_512Mx8_halfbus_lan9xxx.yaml` | lan969x + lan966x | DDR3, x8, inline ECC | **NOT tested** |

Key constraints for lan9xxx inline ECC half-bus maps:
- `MEMC_BURST_LENGTH=16` is required (lan966x has no BL=8 support at all).
- `BL_EXP_MODE` (PCCFG bit 8) must be enabled; requires `BG_B0=0` (DDR4) or `BA0=0` (DDR3).
- `ADDRMAP_COL_B9` must be 31 (disabled): half-bus maps A9→A11, which does not exist on 10-bit column devices.
- `ADDRMAP_COL_B7/B8=19` are inline ECC 'x' values — valid only when `MEMC_INLINE_ECC=1` and `ecc_mode=4`. These are **not** valid for sparx5 sideband ECC.
- The lan9xxx half-bus maps require boards with x8 DRAM devices. The lan966x and lan969x reference boards carry x16 devices, so these profiles cannot be used on them without hardware changes.
- `ADDRMAP7` and `ADDRMAP8` entries in `ddr3_512Mx8_halfbus_lan9xxx.yaml` are silently ignored when generating lan966x configs (lan966x is DDR3-only; these registers are in `chip.rb @@ddr4` exclusion list).
