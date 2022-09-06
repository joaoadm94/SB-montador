#include "assemblerFactory.h"

Assembler* AssemblerFactory::criarAssembler(char* args[]) {
    Assembler* assembler;
    if(std::strcmp(args[1], "-i") == 0) {
        std::cout << "Entrou" << std::endl;
        assembler = new AssemblerIA32(args);
        return assembler;
    }
    std::cout << "Nao Entrou" << std::endl;
    assembler = new AssemblerDidatico(args);
    return assembler;
}