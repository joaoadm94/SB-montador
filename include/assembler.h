#ifndef ASSEMBLER
#define ASSEMBLER

#include <cctype>
#include <unordered_map>
#include "tableEqu.h"
#include "tableOpcode.h"
#include "tableDirective.h"
#include "tableSymbol.h"
#include "token.h"
#include "preprocessor.h"

#define TOKEN_BUFFER_SIZE 99

class Assembler {
    private:
        char* mode;
        char* input;
        char* output;
        std::fstream* file;
        std::vector<Token*>* tokens;
        int lineCounter;
        Preprocessor* preprocessor;
        OpcodeTable opTable;
        DirectiveTable dirTable;
        SymbolTable symbolTable;
    public:
        // Constructor, Destructor
        Assembler(char* args[]);
        ~Assembler();
        // Getters, Setters
        std::vector<Token*>* getTokens();
        void setTokens(std::vector<Token*>* tokens);
        std::fstream* getFile();
        void setFile(std::fstream* file);
        char* getMode();
        void setMode(char* c);
        void setPreprocessor(Preprocessor* preprocessor);
        void setNextAsOperand(Token* token, int* tokenIndex, int operandAmount);
        // Outros metodos
        void preprocess();
        void formatPreprocessed();
        void loadFile(); // Abre o arquivo de entrada
        virtual void requestTokens() = 0; // Solicita os tokens do código
        void showTokens(); // Exibe os tokens armazenados
        void analyze(); // Faz a primeira passagem de análise pelo código
        void synthesize(); // Segunda passagem, gerando código objeto
        void writeToFile(std::string str); // Escreve o código objeto em arquivo
        virtual void run() = 0;
};

#endif