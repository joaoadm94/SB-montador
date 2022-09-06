#include <cctype>
#include <unordered_map>
#include "tableEqu.h"
#include "tableOpcode.h"
#include "tableDirective.h"
#include "tableSymbol.h"
#include "token.h"

#define TOKEN_BUFFER_SIZE 99

class Assembler {
    private:
        char* mode;
        char* input;
        char* output;
        std::fstream* file;
        std::vector<Token*>* tokens;
        int lineCounter;
        OpcodeTable opTable;
        DirectiveTable dirTable;
        SymbolTable symbolTable;
    public:
        std::vector<Token*>* getTokens();
        void setTokens(std::vector<Token*>* tokens);
        std::fstream* getFile();
        void setFile(std::fstream* file);
        char* getMode();
        void setMode(char* c);
        void SetNextAsOperand(Token* token, int* tokenIndex, int operandAmount);
        void PreprocessEquIf();
        void PreprocessMacro();
        void PreprocessConstSpace();
        void FormatPreprocessed();
        void LoadFile(); // Abre o arquivo de entrada
        virtual void RequestTokens() = 0; // Solicita os tokens do código
        void ShowTokens(); // Exibe os tokens armazenados
        void Analyze(); // Faz a primeira passagem de análise pelo código
        void Synthesize(); // Segunda passagem, gerando código objeto
        void WriteToFile(std::string str); // Escreve o código objeto em arquivo
        Assembler(char* args[]);
        virtual void Run() = 0;
};