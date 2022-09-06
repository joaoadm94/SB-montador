#include <string>
#include <vector>
#include <iostream>

class Equ {
    private:
        std::string label;
        std::string sinonym;
    public:
        Equ(std::string label, std::string synonym);
};

class EquTable {
    private:
        std::vector<Equ*> equs;
    public:
        void AppendEqu();
        void GetEqu();
};
