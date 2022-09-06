#include "preprocessor.h"

class PreprocessorFactory {
    public:
        Preprocessor* criarPreprocessor(char mode);
};