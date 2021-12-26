// ---------------------------------------------------------------------------

#ifndef UMatrizH
#define UMatrizH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaS.h"

using namespace std;

class matrizdispersa {
private:
	ListaS* k;
	int repe, df, dc;
	// int nt;

	//int buscar(int f, int c);
	int buscar(int f, int c);
public : matrizdispersa();
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	int numero_terminos();
	void definir_valor_repetido(int valor);
	void mostrar();
};

#endif