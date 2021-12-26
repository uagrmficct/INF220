// ---------------------------------------------------------------------------

#ifndef UColaH
#define UColaH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UPilaP.h"

using namespace std;

class Cola {
private:
	PilaP* k;

public:                    
	Cola();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif