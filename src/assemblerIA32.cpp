#include "assemblerIA32.h"

AssemblerIA32::AssemblerIA32(char* args[]) : Assembler(args){
    std::cout << "Assembler IA32" << std::endl;
}

AssemblerIA32::~AssemblerIA32() {}

void AssemblerIA32::requestTokens() {
}

void AssemblerIA32::run(){}