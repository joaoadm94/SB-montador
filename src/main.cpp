#include "assembler.h"
#include "assemblerFactory.h"

int main(int argc, char* argv[]) {
    
    std::cout << "Universidade de Brasilia" << std::endl;
    std::cout << "Software de Sistema" << std::endl;
    std::cout << "Prof.: Bruno Macchiavello" << std::endl;
    std::cout << "Autor: Joao Antonio Desiderio de Moraes, Mat.: 160126975" << std::endl;
    std::cout << std::endl << "Montador Assembly Didatico\n" <<std::endl;
    std::cout << "Modo: " << argv[1] << std::endl;
    std::cout << "Arquivo de entrada: " << argv[2] << std::endl;
    std::cout << "Arquivo de saída: " << argv[3] << std::endl; 

    AssemblerFactory af;
    Assembler* a = af.criarAssembler(argv);

    a->run();

    return 0;
}