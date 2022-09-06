#include "assemblerDidatico.h"

AssemblerDidatico::AssemblerDidatico(char* args[]) : Assembler(args){
    std::cout << "Assembler Didatico" << std::endl;
    
}

void AssemblerDidatico::requestTokens() {
    Tokenizer t;
    setTokens(t.Tokenize(getFile()));
}

void AssemblerDidatico::run() {
    if (std::strcmp(getMode(),"-p") == 0) {
        loadFile();
        requestTokens();
        preprocessEquIf(Assembler::getTokens());
        formatPreprocessed();
    }

    if (std::strcmp(getMode(),"-m") == 0) {
        loadFile();
        requestTokens();
        preprocessMacro();
        //ShowTokens();
        formatPreprocessed();
    }

    if (std::strcmp(getMode(),"-o") == 0) {
        loadFile();
        requestTokens();
        //ShowTokens();
        preprocessConstSpace();
        analyze();
        synthesize();
    }
}

