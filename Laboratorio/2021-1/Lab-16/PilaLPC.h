
#ifndef PilaLPCH
#define PilaLPCH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CSMemoria.h"

using namespace std;

const string datosP = "elemento,sig";
const string elementoP = "->elemento";
const string sigP = "->sig";

class PilaLPC{
    private:
        int tope;
        CSMemoria* mem;
    public:
        PilaLPC();
        PilaLPC(CSMemoria* m);
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};
#endif