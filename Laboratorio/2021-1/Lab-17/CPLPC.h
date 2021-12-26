
#ifndef CPEHAH
#define CPLPCH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const string elementoC="->elemento";
const string sigC="->sig";
using namespace std;
class CPLPC
{
	private:
		   CSMemoria *mem;
		   int ini, fin;
		   int siguiente(int e);
	public:
		  CPLPC();
		  CPLPC(CSMemoria *m);
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
		  string mostrar();
};
#endif