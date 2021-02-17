#include "Decoder.h"

void (*instructionsCallback[64])(Instruction_t) = {
    // 0
    arithmetic,
    // 1
    bltz,
    // 2
    jump,
    // 3
    jal,
    // 4
    beq,
    // 5
    bne,
    // 6
    blez,
    // 7
    bgtz,
    // 8
    addi,
    // 9
    addiu,
    // 10
    slti,
    // 11
    sltiu,
    // 12
    andi,
    // 13
    ori,
    // 14
    xori,
    // 15
    lui,
    // 16
    0x0,
    // 17
    0x0,
    // 18
    0x0,
    // 19
    0x0,
    // 20
    0x0,
    // 21
    0x0,
    // 22
    0x0,
    // 23
    0x0,
    // 24
    0x0,
    // 25
    0x0,
    // 26
    0x0,
    // 27
    0x0,
    // 28
    0x0,
    // 29
    0x0,
    // 30
    0x0,
    // 31
    0x0,
    // 32
    lb,
    // 33
    0x0,
    // 34
    0x0,
    // 35
    lw,
    // 36
    0x0,
    // 37
    0x0,
    // 38
    0x0,
    // 39
    0x0,
    // 40
    sb,
    // 41
    0x0,
    // 42
    0x0,
    // 43
    sw,
    // 44
    0x0,
    // 45
    0x0,
    // 46
    0x0,
    // 47
    0x0,
    // 48
    0x0,
    // 49
    0x0,
    // 50
    0x0,
    // 51
    0x0,
    // 52
    0x0,
    // 53
    0x0,
    // 54
    0x0,
    // 55
    0x0,
    // 56
    0x0,
    // 57
    0x0,
    // 58
    0x0,
    // 59
    0x0,
    // 60
    0x0,
    // 61
    0x0,
    // 62
    0x0,
    // 63
    0x0};

void (*getInstructionCallback(Instruction_t instruction))(Instruction_t) {
  u_int32_t opCode = instruction >> 26;

  return instructionsCallback[opCode];
}