#include "assembler.h"

class AssemblerDidatico: public Assembler {
    private:
        void requestTokens();
    public:
        AssemblerDidatico(char* args[]);
        void run();
};