#include <iostream>
#include "UMatriz.h"

using namespace std;

int main() {
	CSMemoria* m = new CSMemoria();
	MatrizDispersa* M = new MatrizDispersa(m);
	int x = m->new_espacio("Luishiño,Pericena,choque");
	m->poner_dato(x, "->Luishiño", 666);
	M->dimensionar(100000, 1000000);
	M->definir_valor_repetido(0);
	M->poner(3, 2, 300);
	m->mostrar();
	M->definir_valor_repetido(1);
	M->mostrar();
	M->poner(1, 2, 100);
	M->poner(2, 3, 200);
	m->mostrar();
	M->mostrar();
	M->poner(2, 3, 1);
	m->mostrar();
	system("pause");
	return 0;
}