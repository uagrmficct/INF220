#include <iostream>
#include "UCola.h"

using namespace std;

int main() {
	CSMemoria* m = new CSMemoria();
	m->new_espacio("examen,final");
	cola* c = new cola(m);
	c->poner(100);
	m->mostrar();
	c->poner(200);
	m->mostrar();
	int e;
	c->sacar(e);
	cout << e << endl;
	m->mostrar();
	return 0;
}