//---------------------------------------------------------------------------

#ifndef UPilaVH
#define UPilaVH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAX_VP = 50;

class ClasePila{
    private:
        int* elementos;
        int tope;
    public:
        ClasePila();
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string mostrar();
};

#endif