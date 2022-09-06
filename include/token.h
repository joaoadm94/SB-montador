#ifndef TOKEN
#define TOKEN

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

enum TokenType {
    NONE,
    LABEL,
    OPERATION,
    DIRECTIVE,
    OPERAND
};

class Token {
    private:
        std::string content;
        int line;
        int start;
        int length;
        int tableIndex;
        TokenType type;
    public:
        Token(std::string content, int line, int start);
        std::string GetContent();
        int GetLine();
        int GetStart();
        int GetLength();
        int GetTableIndex();
        TokenType GetType();
        void SetTableIndex(int index);
        void SetType(TokenType type);
        void SetAsOperation();
        void SetAsOperand();
        void SetAsComment();
        void RemoveLastCharacter();
};

class Tokenizer {
    private:
    public:
        std::vector<Token*>* Tokenize(std::fstream * const &file);  
};

#endif