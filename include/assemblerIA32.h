#include "assembler.h"

class AssemblerIA32: public Assembler {
    private:
        void requestTokens();
    public:
        AssemblerIA32(char* args[]);
        void run();
};
