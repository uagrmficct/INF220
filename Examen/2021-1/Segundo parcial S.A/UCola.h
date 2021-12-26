// ---------------------------------------------------------------------------

#ifndef UColaH
#define UColaH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UMemoria.h"

const string datos = "ant,elem,sig";
const string ant = "->ant";
const string elem = "->elem";
const string sig = "->sig";

class cola {
private:
	CSMemoria* mem;
	int ini;
	int fin;

public:
	cola();
	cola(CSMemoria* m);
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif