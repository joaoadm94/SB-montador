#include "assemblerDidatico.h"

AssemblerDidatico::AssemblerDidatico(char* args[]) : Assembler(args){
    std::cout << "Assembler Didatico" << std::endl;
}

void AssemblerDidatico::RequestTokens() {
    Tokenizer t;
    setTokens(t.Tokenize(getFile()));
}

void AssemblerDidatico::Run() {
    if (std::strcmp(getMode(),"-p") == 0) {
        LoadFile();
        RequestTokens();
        PreprocessEquIf();
        FormatPreprocessed();
    }

    if (std::strcmp(getMode(),"-m") == 0) {
        LoadFile();
        RequestTokens();
        PreprocessMacro();
        //ShowTokens();
        FormatPreprocessed();
    }

    if (std::strcmp(getMode(),"-o") == 0) {
        LoadFile();
        RequestTokens();
        //ShowTokens();
        PreprocessConstSpace();
        Analyze();
        Synthesize();
    }
}

