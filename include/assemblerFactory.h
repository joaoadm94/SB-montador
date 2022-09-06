#include "assembler.h"

class AssemblerFactory {
    public:
        Assembler* criarAssembler(char* args[]);
};