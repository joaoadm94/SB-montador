#include "token.h"

class TokenizerDidatico: public Tokenizer {
    public:
        TokenizerDidatico();
        ~TokenizerDidatico();
        void tokenize(std::fstream * const &file, std::vector<Token*>* tokens);  
};