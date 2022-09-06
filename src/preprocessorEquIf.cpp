#include "preprocessorEquIf.h"
// Preprocessamento das diretivas EQU e IF: avaliacao no codigo + remocao
// das diretivas antes do codigo
void PreprocessorEquIf::preprocess(std::vector<Token*>* tokens) {
    Token *token, *last;
    int tokenIndex = 0;
    int begin, end, line;
    std::string str;
    std::regex labelRegex (".*:");
    std::unordered_map<std::string, std::string> equMap;

    while (tokenIndex < (int) tokens->size()) {
        
        token = tokens->at(tokenIndex);
        
        if (std::regex_match(token->GetContent(), labelRegex)) {
            
            last = token;
            
            tokenIndex++;
            token = tokens->at(tokenIndex);
            
            if(token->GetContent().compare("EQU") == 0) {
               
                str = last->GetContent();
                str.pop_back();
                
                tokenIndex++;
                token = tokens->at(tokenIndex);
                
                equMap[str] = token->GetContent();
                
                tokenIndex = 0;

                tokens->erase(tokens->begin(), tokens->begin() + 3);
            }
        }
        else {
            break;
        }
    }

    tokenIndex = 0;

    while(tokenIndex < (int) tokens->size()) {

        token = tokens->at(tokenIndex);

        if (token->GetContent().compare("IF") == 0) {

            begin = tokenIndex;
            tokenIndex++;
            token = tokens->at(tokenIndex);
            if (equMap.count(token->GetContent())){
                // IF avaliado como FALSE = remove linha do IF e proxima linha
                if (equMap[token->GetContent()].compare("1")) {
                    tokenIndex++;
                    token = tokens->at(tokenIndex);
                    line = token->GetLine();
                    while(line == token->GetLine()) {
                        tokenIndex++;
                        token = tokens->at(tokenIndex);
                    }
                    end = tokenIndex;
                    tokenIndex = tokenIndex - (end - begin);
                    tokens->erase(tokens->begin()+begin, tokens->begin()+end);
                }

                else {
                    // IF avaliado como TRUE = remove apenas linha do IF
                    tokenIndex++;
                    end = tokenIndex;
                    tokens->erase(tokens->begin()+begin, tokens->begin()+end);
                }
            } else {
                std::cout << "ERRO: IF avalia rotulo NAO DECLARADO." << std::endl;
            }
        } else {
            tokenIndex++;
        }
    }
}