#include "tableSymbol.h"

Symbol::Symbol(std::string label, u_int16_t position) {
    this->label = label;
    this->position = position;
}

std::string Symbol::GetLabel() {
    return this->label;
}

int Symbol::GetPosition() {
    return this->position;
}

int SymbolTable::FindSymbol(std::string label) {
    int index = 0;
    Symbol *s;

    while (index < (int) symbols.size()) {
        s = symbols.at(index);
        if (s->GetLabel().compare(label) == 0) {
            return index;
        }
        index++;
    }
    return -1;

}

int SymbolTable::AddSymbol(std::string label, u_int16_t position) {
    if(FindSymbol(label) >= 0) {
        std::cout << "ERRO: símbolo " << label << " já definido" << std::endl;
        return 1;
    }
    symbols.push_back(new Symbol(label, position));
    return 0;
}

void SymbolTable::ShowSymbolTable() {
    int index = 0;
    Symbol* s;
    std::cout << "SYMBOL TABLE" << std::endl;
    while (index < (int) symbols.size()) {
        s = symbols.at(index);
        std::cout << s->GetLabel() << " " << s->GetPosition() << std::endl;
        index++;
    }
}

Symbol* SymbolTable::GetSymbol(int index) {
    return symbols.at(index);
}

int SymbolTable::GetSymbolPositionByName(std::string name) {
    int index = FindSymbol(name);
    if (index >= 0) {
        return symbols.at(index)->GetPosition();
    }
    std::cout << "ERRO: Simbolo " << name << " utilizado sem estar definido." << std::endl;
    return -1;
}

int SymbolTable::GetSize() {
    return (int) symbols.size();
}