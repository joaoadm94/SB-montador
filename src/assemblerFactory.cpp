#include "assemblerFactory.h"

Assembler* AssemblerFactory::criarAssembler(char* args[]) {
    if(std::strcmp(args[1], "-i") == 0) {
        std::cout << "Entrou" << std::endl;
        return new AssemblerIA32(args);
    }
    std::cout << "Nao Entrou" << std::endl;
    return new AssemblerDidatico(args);
}