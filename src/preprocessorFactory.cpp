#include "preprocessorFactory.h"
#include "preprocessorEquIf.h"
#include "preprocessorConstSpace.h"
#include "preprocessorMacro.h"

Preprocessor*  PreprocessorFactory::criarPreprocessor(char mode) {
    Preprocessor* preprocessor;
    switch (mode) {
        case 'p':
            preprocessor = new PreprocessorEquIf();
            break;
        case 'm':
            preprocessor = new PreprocessorMacro();
            break;
        case 'o':
            preprocessor = new PreprocessorConstSpace();
            break;
    }
    return preprocessor;
}