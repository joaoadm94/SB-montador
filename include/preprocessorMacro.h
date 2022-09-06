#include "preprocessor.h"

class PreprocessorMacro: public Preprocessor {
    public:
        PreprocessorMacro();
        void preprocess(std::vector<Token*>* tokens);
};