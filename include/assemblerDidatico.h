#include "assembler.h"
#include "preprocessorFactory.h"

class AssemblerDidatico: public Assembler {
    private:
    public:
        AssemblerDidatico(char* args[]);
        ~AssemblerDidatico();
        void requestTokens() override;
        void run() override;
};