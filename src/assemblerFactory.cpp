#include "assemblerFactory.h"

Assembler* AssemblerFactory::criarAssembler(char* args[]) {
    Assembler* assembler;
    Tokenizer* tokenizer;
    if(std::strcmp(args[1], "-i") == 0) {
        std::cout << "Selecionado: Assembler Objeto para IA32" << std::endl;
        assembler = new AssemblerIA32(args);
        return assembler;
    }
    std::cout << "Selecionado: Assembler Didatico" << std::endl;
    assembler = new AssemblerDidatico(args);
    return assembler;
}