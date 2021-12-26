//---------------------------------------------------------------------------

#ifndef ListaPH
#define ListaPH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoL {
	int elemento;
	NodoL* sig;
};

typedef NodoL* direccion;

class ListaP {
	private:
		direccion ptrElementos;
		int longi;
	public:
		ListaP();
		direccion fin();
		direccion primero();
		direccion siguiente(direccion);
		direccion anterior(direccion);
		int recupera(direccion);
		void inserta(direccion,int);
		void inserta_primero(int);
		void inserta_ultimo(int);
		void suprime(direccion);
		void modifica(direccion, int);
		bool vacia();
		int longitud();
		string mostrar();
		direccion localiza(int);
		void elimina_dato(int);
		void anula();
};

#endif