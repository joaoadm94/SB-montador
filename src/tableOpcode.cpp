#include "tableOpcode.h"

Opcode::Opcode(std::string mnemonic, uint16_t operandAmount, uint16_t opcode, uint16_t wordSize) {
    this->mnemonic = mnemonic;
    this->operandAmount = operandAmount;
    this->opcode = opcode;
    this-> wordSize = wordSize;
} 

OpcodeTable::OpcodeTable() {
    opcodeTable.push_back(new Opcode("ADD", 1, 1, 2));
    opcodeTable.push_back(new Opcode("SUB", 1, 2, 2));
    opcodeTable.push_back(new Opcode("MULT", 1, 3, 2));
    opcodeTable.push_back(new Opcode("DIV", 1, 4, 2));
    opcodeTable.push_back(new Opcode("JMP", 1, 5, 2));
    opcodeTable.push_back(new Opcode("JMPN", 1, 6, 2));
    opcodeTable.push_back(new Opcode("JMPP", 1, 7, 2));
    opcodeTable.push_back(new Opcode("JMPZ", 1, 8, 2));
    opcodeTable.push_back(new Opcode("COPY", 2, 9, 3));
    opcodeTable.push_back(new Opcode("LOAD", 1, 10, 2));
    opcodeTable.push_back(new Opcode("STORE", 1, 11, 2));
    opcodeTable.push_back(new Opcode("INPUT", 1, 12, 2));
    opcodeTable.push_back(new Opcode("OUTPUT", 1, 13, 2));
    opcodeTable.push_back(new Opcode("STOP", 0, 14, 1));
}

bool Opcode::MnemonicIsEqual(std::string token) {
    if (mnemonic.compare(token) == 0) {
        return true;
    }
    return false;
}

int OpcodeTable::FindOpcode(std::string token) {
    int i = 0;
    Opcode *op;
    while(i < (int) opcodeTable.size()) {
        op = opcodeTable.at(i);
        if (op->MnemonicIsEqual(token)) {
            return i;
        }
        i++;
    }
    return -1;
}

Opcode* OpcodeTable::GetOpcode(int index) {
    return opcodeTable.at(index);
}

uint16_t Opcode::GetWordSize() {
    return wordSize;
}

uint16_t Opcode::GetOperandAmount() {
    return operandAmount;
}