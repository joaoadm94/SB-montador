#include "assemblerIA32.h"
#include "tokenizerIA32.h"

AssemblerIA32::AssemblerIA32(char* args[]) : Assembler(args){
    setTokenizer(new TokenizerIA32());
}

AssemblerIA32::~AssemblerIA32() {}

void AssemblerIA32::run(){
    loadFile();
    requestTokens();
    showTokens();
}