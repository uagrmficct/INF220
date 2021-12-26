//---------------------------------------------------------------------------

#ifndef UPilaH
#define UPilaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaS.h"

using namespace std;
class Pila{
     private:
        ListaS* L;
    public:
        Pila();
        Pila(ListaS* J);
        bool vacia();
        void poner(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};
#endif