#include "token.h"

Token::Token(std::string content, int line, int start) {
    this->content = content;
    this->line = line;
    this->start = start;
    this->length = content.length();
    this->type = NONE;
}

std::string Token::GetContent() {
    //std::cout << this->content << std::endl;
    return this->content;
}

int Token::GetLine() {
    return this->line;
}

int Token::GetStart() {
    return this->start;
}

int Token::GetLength() {
    return this->length;
}

int Token::GetTableIndex() {
    return this->tableIndex;
}

TokenType Token::GetType() {
    return this->type;
}

void Token::SetTableIndex(int index) {
    this->tableIndex = index;
}

void Token::SetType(TokenType type) {
    if (this->type == NONE) {
        this->type = type;
    }
}

void Token::RemoveLastCharacter() {
    this->content.pop_back();
}

std::vector<Token*>* Tokenizer::Tokenize(std::fstream * const &file) {
    std::vector<Token*>* tokens = new std::vector<Token*>();
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
    return tokens;
}