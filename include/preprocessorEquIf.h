#include "preprocessor.h"

class PreprocessorEquIf: public Preprocessor {
    public:
        PreprocessorEquIf();
        void preprocess(std::vector<Token*>* tokens);
};