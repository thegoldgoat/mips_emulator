# Super basic MIPS ISA emulator

MIPS emulator just for fun, this will be more like an interpreter than an emulator

# Code architecture

## Program loading

Not defined yet

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
3. 2 GB RAM for text, data, dynamic and stack
