#include "assembler.h"

class Preprocessor {
    public:
        Preprocessor();
        virtual void preprocess(std::vector<Token*>* tokens) = 0;
};