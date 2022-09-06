#include "preprocessor.h"

class PreprocessorConstSpace: public Preprocessor {
    public: 
        void preprocess(std::vector<Token*>* tokens);
};