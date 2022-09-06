#include <string>
#include <vector>
#include <iostream>

class Symbol {
    private:
        std::string label;
        uint16_t position;
        //std::vector<int> pending;
        //bool defined;
    public:
        Symbol(std::string label, uint16_t position);
        std::string GetLabel();
        int GetPosition();
        void AddPending(int pending);
};

class SymbolTable {
    private:
        std::vector<Symbol*> symbols;
        int FindSymbol(std::string label);
    public:
        int AddSymbol(std::string label, uint16_t position);
        Symbol* GetSymbol(int index);
        int GetSymbolPositionByName(std::string name);
        int GetSize();
        void ShowSymbolTable();
};