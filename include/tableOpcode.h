#include <string>
#include <vector>
#include <iostream>

class Opcode {
    private:
        std::string mnemonic;
        uint16_t opcode;
        uint16_t operandAmount;
        uint16_t wordSize;
    public:
        Opcode(std::string mnemonic, uint16_t opcode, uint16_t operandAmount, uint16_t wordSize);
        uint16_t GetWordSize();
        uint16_t GetOperandAmount();
        bool MnemonicIsEqual(std::string token);
};

class OpcodeTable {
    private:
        std::vector<Opcode*> opcodeTable;
    public:
        int FindOpcode(std::string token);
        Opcode* GetOpcode(int index);
        OpcodeTable();
};