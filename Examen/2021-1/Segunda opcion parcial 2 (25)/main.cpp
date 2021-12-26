#include <iostream>
#include <string>
#include "ULista.h"

using namespace std;

int main() {
	CSMemoria* m = new CSMemoria();
	ListaLPC* l = new ListaLPC(m);
	l->inserta_primero(100);
	l->inserta_primero(200);
	l->inserta(l->fin(), 150);
	m->mostrar();
	l->ordenar();
	m->mostrar();
	return 0;
}