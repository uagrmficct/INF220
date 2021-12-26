#ifndef CPoliLPH
#define CPoliLPH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CListaP.h"

using namespace std;

class PoliLP {
private:
	ListaP* K;

	direccionP buscar_exponente(int exp);
	int expo(int i);

public:
	PoliLP();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro);
	string mostrarPoli();
	void derivar();
};
#endif