#include "token.h"

class TokenizerIA32: public Tokenizer {
    public:
        TokenizerIA32();
        ~TokenizerIA32();
        void tokenize(std::fstream * const &file, std::vector<Token*>* tokens);  
};