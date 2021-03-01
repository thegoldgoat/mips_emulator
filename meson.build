project('mips_compiler', 'cpp')

executable('emulator', 'src/main.cpp',                 \
    'src/Instructions/Decoder.cpp',                    \
    'src/Instructions/Base/callbacks.cpp',             \
    'src/Instructions/Arithmetics/callbacks.cpp',      \
    'src/Instructions/Types/Instruction.cpp',          \
    'src/Instructions/Types/R_Instruction.cpp',        \
    'src/Instructions/Types/I_Instruction.cpp',        \
    'src/Memory/Memory.cpp',                           \
    'src/Registers/Registers.cpp' ,                    \
    'src/VirtualMachine/VirtualMachine.cpp' ,          \
    install: true,
    cpp_args : [
        '-std=c++11',
        '-DMEMORY_PROTECTION',
        '-DREGISTERS_PROTECTION',
        '-DPRINT_DEBUG'
    ]
)

executable('mytest', 'test/test.cpp',                  \
    'src/Instructions/Decoder.cpp',                    \
    'src/Instructions/Base/callbacks.cpp',             \
    'src/Instructions/Arithmetics/callbacks.cpp',      \
    'src/Instructions/Types/Instruction.cpp',          \
    'src/Instructions/Types/R_Instruction.cpp',        \
    'src/Instructions/Types/I_Instruction.cpp',        \
    'src/Memory/Memory.cpp',                           \
    'src/Registers/Registers.cpp',                     \

    'test/Instructions/Arithmetic.cpp',                \
    'test/Instructions/Memory.cpp',                    \
    'test/Instructions/Jump.cpp',                      \
    install: true,
    cpp_args : [
        '-std=c++11',
        '-DMEMORY_PROTECTION',
        '-DREGISTERS_PROTECTION',
        '-DPRINT_DEBUG'
    ]
)