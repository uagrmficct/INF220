// ---------------------------------------------------------------------------

#ifndef UListaH
#define UListaH
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UMemoria.h"

using namespace std;

class ListaLPC {
private:
	int ptr_lista;
	int longi;
	CSMemoria* m;

	void desenlazar(int P);

public:
	ListaLPC();
	ListaLPC(CSMemoria* mem);
	int fin();
	int primero();
	int siguiente(int P);
	int anterior(int P);
	bool vacia();
	int recupera(int P);
	int longitud();
	void inserta(int P, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void ordenar();
	void suprime(int P);
	void modifica(int P, int e);
	string to_str();

};
#endif