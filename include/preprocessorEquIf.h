#ifndef PREPROCESSOR_EQU_IF
#define PREPROCESSOR_EQU_IF

#include "preprocessor.h"
#include <unordered_map>

class PreprocessorEquIf: public Preprocessor {
    public:
        PreprocessorEquIf();
        void preprocess(std::vector<Token*>* tokens);
};

#endif