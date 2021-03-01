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

Warning: not completely working yet, there is no exit instruction so it will infinitely fetch instructions

Run `emulator` to see CLI parameters:

Usage: ./build/emulator <input_file>

## License

See LICENSE
