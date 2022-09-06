#include "assembler.h"

class AssemblerIA32: public Assembler {
    private:
        void RequestTokens();
    public:
        AssemblerIA32(char* args[]);
        void Run();
};
