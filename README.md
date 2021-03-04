# Super basic MIPS ISA emulator

MIPS emulator just for fun, this is more like an interpreter than an emulator

# Code architecture

## Program loading

Loading custom format executables compiled with [this](https://github.com/thegoldgoat/mips_compiler)

## Emulation engine

This emulator will interpret a single instruction at a time:

1. Read instruction (32 bit WORD)
2. Decode Op-code
3. Read registers/immediates
4. Execution
5. Store result

## Memory and registers

1. 32 32bit accessible registers
2. 3 32bit operation specific registers
3. 2 GB RAM for text, static data, dynamic data and stack

## Compile

Install dependencies first:

1. [meson](https://mesonbuild.com/)
2. [ninja](https://ninja-build.org/)
3. C++ compiler

```bash

# Setup build directory
meson setup build

# Enter build directory
cd build

# Build
ninja

# (optional) install into /usr/local/bin
sudo ninja install

```

## Usage

Run `emulator` to see CLI parameters:

Usage: ./build/emulator <input_file> [--debug]

## Debug

To run the VM in debugging mode, simply pass '--debug' as second CLI parameter

In the debugger CLI you have the following commands:

### Common

1. r: runs the executable
2. e: exit the debugger

### Breakpoints

1. b <address>: adds a breakpoint to the <address> instruction
2. sb: shows the active breakpoints
3. rb <address>: removes the breakpoint at <address>

### Flow

1. c: continues execution until breakpoint
2. n: executes just one instruction

### Registers

1. pr: prints all registers values
2. pr <reg>: prints <reg> register's value
3. wr <reg>: writes <reg> register's value

<reg> can either be the register number or mnemonic name

### Memory

1. pm <address>: print memory value at <address>
2. wm <address>: writes memory value at <address>

## License

See LICENSE
