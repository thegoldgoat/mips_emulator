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
    install: true,
    cpp_args : '-std=c++11'
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
    install: true,
    cpp_args : '-std=c++11'
)