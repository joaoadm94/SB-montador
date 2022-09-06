#ifndef PREPROCESSOR_MACRO
#define PREPROCESSOR_MACRO

#include "preprocessor.h"

class PreprocessorMacro: public Preprocessor {
    public:
        PreprocessorMacro();
        void preprocess(std::vector<Token*>* tokens);
};

#endif