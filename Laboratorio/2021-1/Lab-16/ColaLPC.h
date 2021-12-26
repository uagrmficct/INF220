
#ifndef ColaLPCH
#define ColaLPCH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CSMemoria.h"

const string datosC = "elemento,sig";
const string elementoC = "->elemento";
const string sigC = "->sig";

class ColaLPC {
private:
 CSMemoria* mem;
 int ini, fin;

public:
 ColaLPC();
 ColaLPC(CSMemoria* m);
 bool vacia();
 void poner(int e);
 void sacar(int &e);
 int primero();
 string to_str();
};
#endif