// ------------------------------------------------ ---------------------------

# ifndef Pila
# define  Pila
// ------------------------------------------------ ---------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAX_VP = 50;

class Pila{
    private:
        int* v;
        int tope;
    
    public:
        Pila();
        bool vacia();
        void poner(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};


# endif