#ifndef CListaPH
#define CListaPH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoL {
	int elemento;
	NodoL* sig;
};

typedef NodoL* direccionP;

class ListaP {
private:
	direccionP ptr_elementos;
	int longit;

public:
	ListaP();
	direccionP fin();
	direccionP primero();
	direccionP siguiente(direccionP d);
	direccionP anterior(direccionP d);
	bool vacia();
	int recupera(direccionP d);
	int longitud();
	void inserta(direccionP d, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(direccionP d);
	void modifica(direccionP d, int e);
	string mostrL();
	direccionP localiza(int e);
	void elimina_dato(int e);
	void anula();
};

#endif