#include "assembler.h"

class AssemblerDidatico: public Assembler {
    private:
        void RequestTokens();
    public:
        AssemblerDidatico(char* args[]);
        void Run();
};