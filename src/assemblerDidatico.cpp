#include "assemblerDidatico.h"
#include "tokenizerDidatico.h"

AssemblerDidatico::AssemblerDidatico(char* args[]) : Assembler(args) {
    PreprocessorFactory pf;
    setMode(&args[1][1]);
    setPreprocessor(pf.criarPreprocessor(getMode()));
    setTokenizer(new TokenizerDidatico());
}

AssemblerDidatico::~AssemblerDidatico() {}

void AssemblerDidatico::run() {
    std::cout << "Oi" << std::endl;
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

