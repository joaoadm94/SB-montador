#include "tableDirective.h"

Directive::Directive(std::string mnemonic, uint16_t operandAmount, uint16_t wordSize) {
    this->mnemonic = mnemonic;
    this->operandAmount = operandAmount;
    this-> wordSize = wordSize;
} 

DirectiveTable::DirectiveTable() {
    directiveTable.push_back(new Directive("SPACE", 0, 1));
    directiveTable.push_back(new Directive("CONST", 1, 1));
    directiveTable.push_back(new Directive("EQU", 1, 0));
    directiveTable.push_back(new Directive("IF", 1, 0));
    directiveTable.push_back(new Directive("MACRO", 0, 0));
    directiveTable.push_back(new Directive("ENDMACRO", 0, 0));
}


bool Directive::MnemonicIsEqual(std::string token) {
    if (mnemonic.compare(token) == 0) {
        return true;
    }
    return false;
}

int DirectiveTable::FindDirective(std::string token) {
    int i = 0;
    Directive *dir;
    while(i < (int) directiveTable.size()) {
        dir = directiveTable.at(i);
        if (dir->MnemonicIsEqual(token)) {
            return i;
        }
        i++;
    }
    return -1;
}

Directive* DirectiveTable::GetDirective(int index) {
    return directiveTable.at(index);
}

uint16_t Directive::GetWordSize() {
    return wordSize;
}

uint16_t Directive::GetOperandAmount() {
    return operandAmount;
}