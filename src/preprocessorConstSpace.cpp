#include "preprocessorConstSpace.h"

// Coloca as diretivas CONST e SPACE ao fim do codigo
void PreprocessorConstSpace::preprocess() {
    int tokenIndex = 0;
    std::string tokenContent;

    while(tokenIndex < (int) tokens->size()) {
        tokenContent = tokens->at(tokenIndex)->GetContent();
        if (tokenContent.compare("CONST") == 0) {
            tokens->push_back(tokens->at(tokenIndex - 1));
            tokens->push_back(tokens->at(tokenIndex));
            tokens->push_back(tokens->at(tokenIndex + 1));
            tokens->erase(tokens->begin()+tokenIndex-1, tokens->begin()+tokenIndex+2);
            tokenIndex--;
        }
        else if (tokenContent.compare("SPACE") == 0) {
            tokens->push_back(tokens->at(tokenIndex - 1));
            tokens->push_back(tokens->at(tokenIndex));
            tokens->erase(tokens->begin()+tokenIndex-1, tokens->begin()+tokenIndex+1);
            tokenIndex++;
        } else {
            tokenIndex++;
        }

    }
    ShowTokens();
}
