#include "tokenizerDidatico.h"

TokenizerDidatico::TokenizerDidatico() : Tokenizer() {}

void TokenizerDidatico::tokenize(std::fstream * const &file, std::vector<Token*>* tokens) {
    std::regex validCharacter ("[A-Z0-9_:-]");
    std::regex semiColon (";");
    std::string line;
    std::string tokenBuffer;
    std::string cRegex;
    int start;
    char c;
    int lineCounter = 1;

    while(std::getline(*file, line)) {
        int lineSize = line.size();
        int position = 0;
        int previousCharacterValid = false;
        if (tokenBuffer.empty() == false) {
            tokenBuffer.clear();
        }
        while(position < lineSize) {
            c = line.at(position);
            c = toupper(c);
            cRegex = c;
            //std::cout << c << " " << position;
            
            // Se o caractere eh " ; " chegamos aos comentarios,
            // portanto ignoramos a linha a partir dali 
            if (std::regex_match(cRegex, semiColon)) {
                break;
            }
            // Se eh um caractere valido
            if (std::regex_match(cRegex, validCharacter)) {
                //std::cout << "Valid character: " << c <<"\n";
                // Adiciona caractere no buffer
                tokenBuffer.push_back(c);
                if (previousCharacterValid == false) {
                    start = position;
                    previousCharacterValid = true;
                }
            } else {
                //std::cout << "Invalid character: " << c <<"\n";
                if (previousCharacterValid == true) {
                    //std::cout << tokenBuffer << "\n";
                    tokens->push_back(new Token(tokenBuffer, lineCounter, start + 1));
                    tokenBuffer.clear();
                    previousCharacterValid = false;
                } 
            }
            // Incrementa indices do buffer e da linha
            position += 1;
        }
        if (previousCharacterValid == true) {
            //std::cout << tokenBuffer << "\n";
            tokens->push_back(new Token(tokenBuffer, lineCounter, start + 1));
            tokenBuffer.clear();
        }
        //feed line to assembler
        lineCounter +=1;
    }
    file->close();
}