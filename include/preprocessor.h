#ifndef PREPROCESSOR
#define PREPROCESSOR

#include <vector>
#include "token.h"

class Preprocessor {
    public:
        Preprocessor(){};
        virtual void preprocess(std::vector<Token*>* tokens) = 0;
};

#endif