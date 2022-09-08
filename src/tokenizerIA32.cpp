#include "tokenizerIA32.h"

TokenizerIA32::TokenizerIA32() : Tokenizer() {}

void TokenizerIA32::tokenize(std::fstream * const &file, std::vector<Token*>* tokens) {
    std::regex validCharacter ("[0-9]");
    std::string line;
    std::string tokenBuffer;
    std::string cRegex;
    bool previousCharacterValid = false;
    int lineCounter = 0;
    int start = 0;
    char c;

    std::getline(*file, line);
    int lineSize = line.size();
    int position = 0;
    while (position < lineSize) {
        c = line.at(position);
        cRegex = c;
        if (std::regex_match(cRegex, validCharacter)) {
            tokenBuffer.push_back(c);
            if (previousCharacterValid == false) {
                previousCharacterValid = true;
            }
        }
        else {
            if (previousCharacterValid == true) {
                tokens->push_back(new Token(tokenBuffer, lineCounter, start));
                tokenBuffer.clear();
                previousCharacterValid = false;
            }
        }
        position++;
    }
    file->close();
}
