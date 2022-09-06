#include "assembler.h"

Assembler::Assembler(char* args[]) {
    this->mode =  args[1];
    this->input =  args[2];
    this->output =  args[3];
}

Assembler::~Assembler(){};

std::vector<Token*>* Assembler::getTokens() {
    return tokens;
}

void Assembler::setTokens(std::vector<Token*>* tokens) {
    this->tokens = tokens;
}

std::fstream* Assembler::getFile() {
    return file;
}

void Assembler::setFile(std::fstream* file) {
    this->file = file;
}

char* Assembler::getMode() {
    return mode;
}

void Assembler::setMode(char* mode) {
    this->mode = mode;
}

void Assembler::setPreprocessor(Preprocessor* preprocessor){
    this->preprocessor = preprocessor;
}


void Assembler::loadFile(){

    std::fstream* file = new std::fstream();    
    file->open(input);

    if (file->good()) {
        std::cout << "Arquivo " << input << " aberto com sucesso.\n";
        setFile(file);
        return;
    } else {
        std::cout << "Falha ao abrir arquivo.\n";
        return;
    }
}

void Assembler::showTokens() {
    Token *token;
    int position = 0;
    while(position < (int) tokens->size()) {
        token = tokens->at(position);
        //std::cout << "Token:  " << position << std::endl;
        //std::cout << "Content: " << token->GetContent() << std::endl;
        std::cout << token->GetContent() << std::endl;
        //std::cout << "Line: " << token->GetLine() << std::endl;
        //std::cout << "Column: " << token->GetStart() << std::endl;
        //std::cout << "Length: " << token->GetLength() << std::endl;
        position += 1;
    }
}

void Assembler::preprocess() {
    this->preprocessor->preprocess(tokens);
}

void Assembler::formatPreprocessed() {
    Token* token;
    int line, tokenIndex = 0;
    std::string str;

    line = tokens->at(tokenIndex)->GetLine();
    while (tokenIndex < (int) tokens->size()) {
        token = tokens->at(tokenIndex);
        if (token->GetLine() != line) {
            str.append("\n");
        }
        line = token->GetLine();
        str.append(token->GetContent() + " ");
        tokenIndex++;
    }
    writeToFile(str);
}

// Define os proximos n tokens como operandos
void Assembler::setNextAsOperand(Token* token, int* tokenIndex, int operandAmount) {
    while (operandAmount > 0) {
        *tokenIndex = *tokenIndex + 1;
        operandAmount--;
        token = tokens->at(*tokenIndex);
        token->SetType(OPERAND);
    }
    *tokenIndex = *tokenIndex + 1;
}

// Realiza a primeira analise do codigo para montagem
void Assembler::analyze() {
    std::regex labelRegex (".*:");
    std::regex beginsWithNumber ("[0-9].*");
    int memoryPosition = 0;
    int tokenIndex = 0;
    int index = -1;
    int line = -1;
    Token *token;

    while (tokenIndex < (int) tokens->size()) {
        token = tokens->at(tokenIndex);
        // Se encontrou ROTULO
        if (std::regex_match(token->GetContent(), labelRegex)) {
            // Confere se rotulo comeca com numero
            if (std::regex_match(token->GetContent(), beginsWithNumber)) {
                std::cout << "ERRO: Token \"" << token->GetContent() << "\" invalido: iniciado com numero";
                std::cout << " (linha " << token->GetLine() << ", erro LEXICO)" << std::endl;
                tokenIndex++;
            } else {
                token->RemoveLastCharacter();
                // Confere se rotulo ja foi definido
                if (!symbolTable.AddSymbol(token->GetContent(), memoryPosition)) {
                    // Associa rotulo ao token
                    token->SetType(LABEL);
                    token->SetTableIndex(symbolTable.GetSize()+1);
                    tokenIndex++;
                }
            }
        } else {
            // Procura token na tabela de instrucoes
            index = opTable.FindOpcode(token->GetContent()); 
            if (index > -1) {
                token->SetType(OPERATION);
                token->SetTableIndex(index+1);
                line = token->GetLine();
                Opcode* op = opTable.GetOpcode(index);
                memoryPosition += op->GetWordSize();
                setNextAsOperand(token, &tokenIndex, op->GetOperandAmount());
                // Conferir se tem mais tokens na mesma linha
                while(tokenIndex < (int) tokens->size()) {
                    if(tokens->at(tokenIndex)->GetLine() == line) {
                        std::cout << "ERRO: comando possui mais operandos que o permitido ";
                        std::cout << "(linha " << line << ", erro SINTATICO);" << std::endl;
                        tokenIndex++;
                    } else {
                        break;
                    }
                }
            } else {
                // Procura token na tabela de diretivas
                index = dirTable.FindDirective(token->GetContent());
                if (index > -1) {
                    token->SetType(DIRECTIVE);
                    token->SetTableIndex(index);
                    line = token->GetLine();
                    Directive* dir = dirTable.GetDirective(index);
                    // chamar subrotina que executa a diretiva
                    memoryPosition += dir->GetWordSize();                       
                    setNextAsOperand(token, &tokenIndex, dir->GetOperandAmount());
                    // Conferir se tem mais tokens na mesma linha   
                    while (tokenIndex < (int) tokens->size()) {
                        if(tokens->at(tokenIndex)->GetLine() == line) {
                            std::cout << "ERRO: comando possui mais operandos que o permitido ";
                            std::cout << "(linha " << line << ", erro SINTATICO);" << std::endl;
                            tokenIndex++;
                        } else {
                            break;
                        }
                    }
                } else {
                    // Retorna 1 (status de erro) se token nao for operacao ou diretiva valida
                    std::cout << "ERRO: operação \"" << token->GetContent() << "\" não identificada";
                    std::cout << "(linha " << token->GetLine() << ");" << std::endl;
                    tokenIndex++;
                    //return;
                }
            }
        }
    }
    //symbolTable.ShowSymbolTable();
    return;
}


void Assembler::synthesize() {
    std::string objectCode;
    std::string spaceConst;
    Token* token;
    TokenType tt;
    int tokenIndex = 0;

    while(tokenIndex < (int) tokens->size()){
        token = tokens->at(tokenIndex);
        tt = token->GetType();
        switch(tt) {
            case NONE:
                std::cout << "Token nao identificado: " << token->GetContent() << std::endl;
                break;
            case LABEL:
                break;
            case OPERATION:
                objectCode.append(std::to_string(token->GetTableIndex()));
                objectCode.push_back(' ');
                break;
            case OPERAND:
                if (symbolTable.GetSymbolPositionByName(token->GetContent()) == -1) {
                    objectCode.push_back('X');
                    objectCode.push_back(' ');   
                } else {
                    objectCode.append(std::to_string(symbolTable.GetSymbolPositionByName(token->GetContent())));
                    objectCode.push_back(' ');
                }
                break;
            case DIRECTIVE:
                int dir = token->GetTableIndex();
                switch(dir){
                    case 0: // Diretiva SPACE
                        objectCode.append(std::to_string(token->GetTableIndex()));
                        objectCode.push_back(' ');
                        break;
                    case 1: // Diretiva CONST
                        tokenIndex++;
                        token = tokens->at(tokenIndex);
                        objectCode.append(token->GetContent());
                        objectCode.push_back(' ');
                        break;
                }
            break;
        }
        tokenIndex++;
    }
    writeToFile(objectCode);
    return;
}

void Assembler::writeToFile(std::string str) {
    std::fstream* file = getFile();
    if(file) {
        file->close();
    }
    file->open(output, std::ios::out);
    if(!file) {
        std::cout << "Erro ao criar arquivo de saida." << std::endl;
    }
    else {
        file->write(str.c_str(), str.size());
        file->close();
        std::cout << "Arquivo de saída escrito com sucesso!" << std::endl;
    }
}