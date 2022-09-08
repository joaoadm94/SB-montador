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