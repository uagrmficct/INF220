//---------------------------------------------------------------------------

#ifndef PoliLPH
#define PoliLPH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "ListaP.h"
using namespace std;

class Polinomio{
	private:
	CSLista KLPC;


	public:
	Polinomio();               //
	bool escero();        //
	void poner_termino(int exp, int coef);  //
	int coeficiente(int exp);        //
	int exponente(int term);          //
	int grado();                    //
//	int numero_terminos();
	void derivar();               //
	int evaluar(int x);           //
	void mostrar();               //
//	void mostrar_lista();
//	void suma(Polinomio s1,Polinomio s2);
//	void resta(Polinomio s1,Polinomio s2);


};

 #endif
