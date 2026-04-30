# Creating a New Board Configuration

## About this guide

This document walks through a common customer task: **bringing up a
new board with DDR memory, using DRAM chips from a vendor that is not
already represented in `configs/memory/`**. It is intended for
customers and integrators who have the SoC reference design plus a
DRAM datasheet in hand, and want to produce a working uMCTL2 + PUB
register configuration without rewriting any Ruby code.

**The procedure is the same on every supported platform** — sparx5,
lan966x, and lan969x. Only the file names, ECC mode, and bus width
change. To keep the examples concrete this guide uses **lan969x +
DDR4** throughout, but each step works identically on:

- **sparx5** (32-bit bus, sideband ECC, DDR3 or DDR4)
- **lan966x** (16-bit bus, inline ECC, DDR3 only)
- **lan969x** (16-bit bus, inline ECC, DDR3 or DDR4)

Where a platform-specific constraint applies (typically around inline
vs sideband ECC, or x8 vs x16 devices on the 16-bit bus) it is called
out explicitly.

Relevant background material before you start:

- `GETTING_STARTED.md` — building and running the generator
- `CLAUDE.md` — "Config pipeline architecture" section explains how the
  profile / board / memory YAMLs feed into `gen_cfg.rb`
- The JEDEC DDR3 / DDR4 specifications (for timing and address-map
  terminology)
- The DRAM vendor datasheet for the specific part being designed in

## The three input files

A config is built from three YAML files. How many you actually create
depends on whether the new vendor's part has the same organization as
one already supported.

| File                           | Scope                    | New for this customer? |
|--------------------------------|--------------------------|------------------------|
| `configs/profiles/<name>.yaml` | SoC + board + clock      | **Always new**         |
| `configs/boards/<name>.yaml`   | PCB + PHY ODT/drive      | **Usually new**        |
| `configs/memory/<name>.yaml`   | DRAM geometry (ADDRMAP)  | Reuse if geometry matches; new if not |

JEDEC timings (tRCD/tRP/tRAS/tFAW/tRFC/tWTR/…) are **not** per-vendor
inputs — they are looked up automatically from `:clock_speed` in
`scripts/ddr/ddr4.rb`. You only override a timing when the vendor's
datasheet deviates from JEDEC, which is rare.

## Step 1 — Create the profile

Copy `configs/profiles/lan969x_evb_ddr4.yaml` to a new file named for
the customer board, and edit from the DRAM datasheet:

```yaml
:platform:           lan969x
:mem_type:           DDR4
:mem_size_mbytes:    <total DRAM visible to the SoC>
:configured_density: <8G | 4G | 16G>                   # per chip
:device_bus_width:   <x8 | x16>
:active_ranks:       1
:ecc_mode:           4                                 # 4 = ECC enabled, 0 = disabled
:clock_speed:        <1600|1866|2133|2400>             # MT/s data rate
:mem_profile:        <address-map yaml basename>
:board:              <board yaml basename>
```

Verify that the DRAM part's supported speed grade is ≥ your
`:clock_speed`. The generator picks timings from that grade; asking for
a clock the part does not officially support will produce a config the
DRAM may not meet.

**Per-SoC production ceilings** (values in use by the reference
profiles today):

| Target SoC | Max supported `:clock_speed` |
|------------|------------------------------|
| sparx5     | 1667 MT/s (DDR3 and DDR4)    |
| lan966x    | 1200 MT/s (DDR3)             |
| lan969x    | 2400 MT/s (DDR4)             |

The generator will accept higher values (e.g. 2667 MT/s on lan969x),
but timing is **not closed** at those rates on the SoC side — they are
only useful for bring-up / stress testing, not for production
configurations.

**For other SoCs**, start from the matching reference profile and
adjust `:platform` and `:mem_type`:

| Target SoC | Reference profile to copy                         |
|------------|---------------------------------------------------|
| sparx5     | `pcb134_ddr4.yaml` / `pcb135_ddr3.yaml`           |
| lan966x    | `lan966x.yaml`                                    |
| lan969x    | `lan969x_evb_ddr4.yaml` / `lan969x_svb_ddr3.yaml` |

`:ecc_mode` is `4` to enable ECC or `0` to disable it, on every
platform — the field maps directly to `ECCCFG0.ECC_MODE`. Whether the
SoC uses sideband (sparx5) or inline (lan966x, lan969x) ECC is a
property of the platform, not of this field.

## Step 2 — Choose or create the memory profile

This file is **geometry only** — density, bank groups (BG0[/BG1]),
bank addresses (BA0–BA1), row bits, column bits, page size. It is
independent of vendor. From the new datasheet read off those numbers
and match them against existing files in `configs/memory/`:

| Existing file                          | Organization              | Use case                         |
|----------------------------------------|---------------------------|----------------------------------|
| `ddr4_512Mx16_fullbus_2B.yaml`         | 8 Gb, x16, 2 BG           | x16 devices on full 16-bit bus   |
| `ddr4_512Mx8_fullbus.yaml` / `_2B`     | 8 Gb, x8                  | x8 devices, full 16-bit bus      |
| `ddr4_512Mx8_halfbus_lan969x.yaml`     | 8 Gb, x8, half-bus + ECC  | inline ECC half-bus (untested)   |

If the organization matches exactly, point `:mem_profile` at it and
skip to Step 3.

If the organization differs (for example a 16 Gb part, or a different
row/column split), copy the closest file and adjust the `ADDRMAP_*`
fields per the new mapping. For lan969x inline ECC, respect the
constraints in `CLAUDE.md` ("Half-bus memory profiles"):

- `MEMC_BURST_LENGTH = 16` is required.
- `BL_EXP_MODE` must be enabled; requires `BG_B0 = 0` (DDR4).
- `ADDRMAP_COL_B9 = 31` (disabled) for half-bus.
- `ADDRMAP_COL_B7 = 19`, `ADDRMAP_COL_B8 = 19` are valid only with
  inline ECC (`ecc_mode = 4`); they are **not** valid on sparx5
  sideband ECC.

## Step 3 — Create the board file

The board file is PCB- and DRAM-load-dependent, not a vendor recipe.
Copy `configs/boards/lan969x_evb969x.yaml` and set:

- `:odt_nom_ddr` — from the intersection of the DRAM datasheet's
  supported `RTT_NOM` values and your board's signal-integrity
  analysis (60 Ω is a common default).
- `:drive_strength` — SoC PHY drive strength (34 Ω or 40 Ω typical).
- `zq0pr` / `zq1pr` field overrides — set these only if SI analysis
  or first-silicon bring-up tells you the default pull-up / pull-down
  asymmetry is wrong.

If the customer has not done SI work yet, copy the EVB board file
unchanged and tune during bring-up.

**For other SoCs**, start from the corresponding reference board file:

| Target SoC | Reference board file(s)                       |
|------------|-----------------------------------------------|
| sparx5     | `pcb134.yaml` (DDR4) / `pcb135.yaml` (DDR3)   |
| lan966x    | `lan966x_ref.yaml`                            |
| lan969x    | `lan969x_evb969x.yaml` / `lan969x_svb969x.yaml` |

### What is "SI work"?

**SI = Signal Integrity.** At DDR4 data rates (1600–3200 MT/s) the
PCB traces between SoC and DRAM behave as transmission lines, and
small layout mistakes cause bit errors that manifest as random memory
corruption. SI work is the electrical-engineering effort to ensure
DQ / DQS / CK / CA signals arrive cleanly enough to be sampled
correctly.

Typical SI work for a new board includes:

- **Pre-layout simulation** — running the PCB layout through a tool
  like HyperLynx, Ansys SIwave, or Keysight ADS to model reflections,
  crosstalk, and eye diagrams on DQ / DQS / CK / CA lines *before*
  fabrication.
- **Termination tuning** — choosing ODT values (`RTT_NOM`, `RTT_PARK`,
  `RTT_WR` on the DRAM side; PHY ODT on the SoC side) that flatten
  reflections for this board's specific trace lengths and topology.
- **Drive-strength tuning** — picking SoC PHY drive (34 Ω vs 40 Ω) so
  the signal swing is large enough to meet DRAM input thresholds but
  not so large it rings.
- **Topology and length matching** — ensuring address / command
  fan-out (one SoC driving two or more DRAMs) and byte-lane length
  matching stay within budget.
- **Bench measurement** — probing DQ / DQS on first silicon with a
  high-bandwidth scope, capturing eye diagrams, and iterating on
  ODT / drive / VREF until the eye meets margin.

The board file exposes exactly the knobs SI analysis produces values
for: `:odt_nom_ddr`, `:drive_strength`, and the `zq0pr` / `zq1pr`
overrides. If no SI work has been done yet, the safe starting point is
to copy the reference-board file (which was tuned for *that* board's
SI) and revisit these numbers during bring-up once scope traces are
available.

## Step 4 — Generate and diff against a known-good config

Print the new config as YAML to inspect it:

```bash
./scripts/gen_cfg.rb -f yaml configs/profiles/<new>.yaml | less
```

To compare against a known-good reference profile, pipe one side of
the diff through `gen_cfg.rb` using `-` as the filename argument for
stdin — there is no need to write intermediate files:

```bash
./scripts/gen_cfg.rb -f yaml configs/profiles/<new>.yaml | \
    ./scripts/diff_cfg.rb -p lan969x - \
        <(./scripts/gen_cfg.rb -f yaml configs/profiles/lan969x_evb_ddr4.yaml)
```

If you prefer files on disk, redirect to any path you like — the
generator has no hardcoded output directory:

```bash
./scripts/gen_cfg.rb -f yaml configs/profiles/<new>.yaml > /tmp/<new>.yaml
./scripts/gen_cfg.rb -f yaml configs/profiles/lan969x_evb_ddr4.yaml > /tmp/ref.yaml
./scripts/diff_cfg.rb /tmp/ref.yaml /tmp/<new>.yaml
```

Expect differences only where they should be: clock-dependent timings
if you changed `:clock_speed`, the address map if you used a different
`:mem_profile`, and ODT / drive fields if you changed the board file.
Anything else surprising is a clue that the profile is wrong.

Once the YAML looks right, regenerate the driver C source:

```bash
./scripts/gen_cfg.rb -f source configs/profiles/<new>.yaml
```

…or, for downstream U-Boot / TFA consumption, devicetree output:

```bash
./scripts/gen_cfg.rb -f devicetree configs/profiles/<new>.yaml
```

(See the "Downstream target repositories" table in `CLAUDE.md` for
where each generated artifact lands.)

## Step 5 — Inspect specific registers with `reg_show.rb`

`scripts/support/reg_show.rb` decodes raw 32-bit register values into
named fields, using the same SoC YAML (`scripts/soc/<platform>.yaml`)
the generator reads. It is useful for:

- Decoding a value read off silicon over JTAG / debugger and comparing
  it against the value the generator produced.
- Spot-checking one or two registers in a new config without reading
  through the whole generated YAML.
- Understanding what a hand-written override in a board file actually
  changes at the bit level.

`reg_show.rb` accepts input in two forms:

- **Register / value tuples on the command line** — one or more
  `<REG> <value>` pairs, for decoding individual values read from
  silicon or pulled from a log.
- **A complete generated YAML configuration file** — the same output
  `gen_cfg.rb -f yaml` produces, decoded in full with every register
  expanded into named fields.

### Decoding a single register value

```bash
./scripts/support/reg_show.rb -p lan969x MSTR 0x41040010
```

Output:

```yaml
---
MSTR:
  DDR3: 0
  DDR4: 1
  BURSTCHOP: 0
  EN_2T_TIMING_MODE: 0
  GEARDOWN_MODE: 0
  DATA_BUS_WIDTH: 0
  DLL_OFF_MODE: 0
  BURST_RDWR: 4
  ACTIVE_RANKS: 1
  DEVICE_CONFIG: 1
```

### Decoding several registers at once

Pass register/value pairs on the command line:

```bash
./scripts/support/reg_show.rb -p lan969x \
    MSTR    0x41040010 \
    RFSHTMG 0x0082008c \
    DRAMTMG0 0x12141a16
```

Values may be decimal or `0x`-prefixed hex.

### Decoding a YAML dump

`reg_show.rb` can decode an entire YAML register dump — either a file
captured from silicon, or the generator's output fed through a
temporary file:

```bash
./scripts/gen_cfg.rb -f yaml configs/profiles/<new>.yaml > /tmp/<new>.yaml
./scripts/support/reg_show.rb -p lan969x /tmp/<new>.yaml
```

Each top-level register becomes a block of field names and decoded
values.

### Useful flags

| Flag            | Effect                                                  |
|-----------------|---------------------------------------------------------|
| `-p <platform>` | Platform YAML to use (`sparx5`, `lan966x`, `lan969x`)   |
| `-z`            | Omit zero-valued fields (keeps output short)            |
| `-v` / `-d`     | Info / debug logging to stderr                          |

**Pick the right platform**. Field names and even the set of fields
inside the "same" register differ between controller revisions — for
example `RFSHTMG`'s refresh-interval field is `T_RFC_NOM_X32` on
sparx5 but `T_RFC_NOM_X1_X32` on lan969x / lan966x. Passing `-p
lan969x` against a sparx5 register dump will silently give you wrong
field names.

## When you might also need code changes

Leave `scripts/ddr/ddr4.rb` alone unless the vendor datasheet
requires non-JEDEC timings. If a new density is used that isn't in
`ddr4.rb`'s density table, add it there. Headers and the C driver
don't change per board.

## Minimum information to collect from the customer

1. Datasheet page with: density, device width, banks / bank groups,
   rows, columns, supported speed grades, `RTT_NOM` options.
2. Board schematic: number of DRAM devices, bus width actually routed,
   ODT topology, and whether SoC inline ECC is intended.
3. Target data rate in MT/s.

With those three inputs the profile / board / (optional) memory files
can usually be filled in under an hour, with the remaining time spent
on SI tuning during bring-up.
