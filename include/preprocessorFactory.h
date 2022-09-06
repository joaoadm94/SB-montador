#include "preprocessor.h"
#include "preprocessorConstSpace.h"
#include "preprocessorEquIf.h"
#include "preprocessorMacro.h"

class PreprocessorFactory {
    public:
        Preprocessor* criarPreprocessor(char* mode);
};