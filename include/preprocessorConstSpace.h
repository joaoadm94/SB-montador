#ifndef PREPROCESSOR_CONST_SPACE
#define PREPROCESSOR_CONST_SPACE

#include "preprocessor.h"

class PreprocessorConstSpace: public Preprocessor {
    public: 
        PreprocessorConstSpace();
        void preprocess(std::vector<Token*>* tokens);
};

#endif