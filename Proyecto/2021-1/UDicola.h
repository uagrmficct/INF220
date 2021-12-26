// ---------------------------------------------------------------------------

#ifndef UDicolaV2H
#define UDicolaV2H
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAXVD2 = 20;

class ClaseDicola {
private:
	int* v;
	int ini, fin;

public:
	ClaseDicola();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
	string mostrar();
};
#endif