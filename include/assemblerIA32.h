#include "assembler.h"

class AssemblerIA32: public Assembler {
    public:
        AssemblerIA32(char* args[]);
        ~AssemblerIA32();
        void run() override;
};
