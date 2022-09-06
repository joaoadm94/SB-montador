#include "assemblerDidatico.h"

AssemblerDidatico::AssemblerDidatico(char* args[]) : Assembler(args) {
    std::cout << "Assembler Didatico" << std::endl;
    PreprocessorFactory pf;
    setMode(&args[1][1]);
    setPreprocessor(pf.criarPreprocessor(getMode()));
}

AssemblerDidatico::~AssemblerDidatico() {}

void AssemblerDidatico::requestTokens() {
    Tokenizer t;
    setTokens(t.Tokenize(getFile()));
}

void AssemblerDidatico::run() {
    loadFile();
    requestTokens();
    preprocess();
    //ShowTokens();
    formatPreprocessed();

    if (std::strcmp(getMode(),"o") == 0) {
        analyze();
        synthesize();
    }
}

