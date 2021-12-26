//---------------------------------------------------------------------------

#ifndef PruebaPLPH
#define PruebaPLPH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "ListaP.h"

using namespace std;

class Polinomio {
	private:
		ListaP* K;
	public:
		Polinomio();
		direccion buscar_exponente(int exp);
		direccion buscar_termino_n(int i);
		bool es_cero();
		int grado();
		int exponente(int nrot);
		int coeficiente(int exp);
		void poner_termino(int coef, int exp);
		int numero_terminos();
		void derivar();
        float evaluar(float x);
		void mostrar();
};
#endif