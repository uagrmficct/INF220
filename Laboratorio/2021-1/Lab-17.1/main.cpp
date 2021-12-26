#include <iostream>
#include "UColaS.h"
#include "CP.h"

using namespace std;
    int e ;
int main() {
    CSMemoria* m = new CSMemoria();
	CP* p = new CP(m);
    p->poner(10, 1);
    p->poner(200, 2);
    p->poner(1000, 3);
    p->poner(20, 1);
    p->poner(300, 2);
    p->asignar_frec_prioridad(1, 1);
    p->asignar_frec_prioridad(2, 2);
    p->asignar_frec_prioridad(1, 3);
	m->mostrar();
	p->sacar(e);
	cout <<e<<endl;
	p->sacar(e);
	cout <<e<<endl;
    p->sacar(e);
	cout <<e<<endl;
   	m->mostrar();

	return 0;
}