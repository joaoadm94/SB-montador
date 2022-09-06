#ifndef ASSEMBLER_FACTORY
#define ASSEMBLER_FACTORY

#include "assemblerDidatico.h"
#include "assemblerIA32.h"

class AssemblerFactory {
    public:
        Assembler* criarAssembler(char* args[]);
};

#endif