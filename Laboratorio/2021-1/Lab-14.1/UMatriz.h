// ---------------------------------------------------------------------------

#ifndef UMatrizH
#define UMatrizH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaS.h"

using namespace std;

class MatrizDispersaLRHC {
private:
	ListaS* k;
	int repe, df, dc;

	int buscar(int f, int c);

public:
	MatrizDispersaLRHC();
	MatrizDispersaLRHC(CSMemoria* m);
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int valor);
	void mostrar();
	string to_str();

};
#endif