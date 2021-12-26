//---------------------------------------------------------------------------

#ifndef UColaV1H
#define UColaV1H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAXVC1 = 12;

class ClaseCola{
	private:
		int* v;
        int ini, fin;
	public:
		ClaseCola();
		bool vacia();
		void poner(int e);
		void sacar(int &e);
		int primero();
		string mostrar();
};
#endif