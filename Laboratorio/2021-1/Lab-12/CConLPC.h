#ifndef CConLPCH
#define CConLPCH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UMemoria.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

const string datosCJ = "dato,sig";
const string datoCJ = "->dato";
const string sigCJ = "->sig";

class CConjunto {
private:
	CSMemoria* mem;
	int ptr_conj;
	int cant;

public:
	CConjunto();
	CConjunto(CSMemoria* m);
	bool vacio();
	bool pertenece(int e);
	void inserta(int e);
	int cardinal();
	int ordinal(int e);
	void suprime(int e);
	int muestrea();
	void unionC(CConjunto * a, CConjunto * b, CConjunto * &c);
	string to_str();
};
#endif