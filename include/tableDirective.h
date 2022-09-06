#include <string>
#include <vector>
#include <iostream>

class Directive {
    private:
        std::string mnemonic;
        uint16_t operandAmount;
        uint16_t wordSize;
    public:
        Directive(std::string mnemonic, uint16_t operandAmount, uint16_t wordSize);
        uint16_t GetWordSize();
        uint16_t GetOperandAmount();
        bool MnemonicIsEqual(std::string token);
};

class DirectiveTable {
    private:
        std::vector<Directive*> directiveTable;
    public:
        DirectiveTable();
        int FindDirective(std::string token);
        Directive* GetDirective(int index);
};
