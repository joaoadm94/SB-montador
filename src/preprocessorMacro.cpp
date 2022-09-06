#include "preprocessorMacro.h"

// Preprocessamento das Macro: expansao no codigo + remocao
// das diretivas antes do codigo
void PreprocessorMacro::preprocess(std::vector<Token*>* tokens) {
    std::regex labelRegex (".*:");
    Token* token;
    std::string macroLabel;
    int begin = -1, end = -1;
    int tokenIndex = 0;

    while(tokenIndex < (int)  tokens->size()) {
        token = tokens->at(tokenIndex);
        if (token->GetContent().compare("MACRO") == 0) {
            begin = tokenIndex - 1;
            token = tokens->at(tokenIndex - 1);
            macroLabel = token->GetContent();
            while(tokenIndex < (int) tokens->size()) {
                token = tokens->at(tokenIndex);
                if (token->GetContent().compare("ENDMACRO") == 0){
                    end = tokenIndex + 1;
                    break;
                }
                tokenIndex++;
            }
        }
        else {
            tokenIndex++;
        }
    }

    if (begin == -1) {
        std::cout << "ERRO: Diretiva MACRO nao encontrada. MACRO nao processada." << std::endl;
        return;
    }

    if (end == -1) {
        std::cout << "ERRO: Diretiva ENDMACRO nao encontrada. MACRO nao processada." << std::endl;
        return;
    }

    if(std::regex_match(macroLabel, labelRegex)){
        macroLabel.pop_back();
    }

    tokenIndex = 0;

    while(tokenIndex < (int) tokens->size()) {
        token = tokens->at(tokenIndex);
        if (token->GetContent().compare(macroLabel) == 0) {
            tokens->erase(tokens->begin()+tokenIndex);
            tokens->insert(tokens->begin()+tokenIndex, tokens->begin()+begin+2, tokens->begin()+end-1);
            std::cout << "MACRO processada com sucesso." << std::endl;
            break;
        } else {
            tokenIndex++;
        }
    }
    std::cout << "ERRO: MACRO nao utilizada. MACRO nao processada." << std::endl;
}