#include <iostream>
#include <string>
#include "CConLPC.h"
#include "UMemoria.h"
using namespace std;

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

void ComplementoInterseccion(CConjunto* a, CConjunto* b, CConjunto* c) {
	CConjunto* aux1 = new CConjunto();
	CConjunto* aux2 = new CConjunto();
	while (!a->vacio()){
		int k= a->muestrea();
		aux2->inserta(k);
		if(!b->pertenece(k))
			c->inserta(k);
		a->suprime(k);
	}
	while (!aux1->vacio()){
		int k= aux1->muestrea();
		a->inserta(k);
		aux2->suprime(k);
	}
	while (!b->vacio()){
		int k= b->muestrea();
		aux2->inserta(k);
		if(!a->pertenece(k))
			c->inserta(k);
		b->suprime(k);
	}
	while (!aux2->vacio()){
		int k= aux2->muestrea();
		b->inserta(k);
		aux2->suprime(k);
	}
}
int main() {
	 CSMemoria* m=new CSMemoria();
	 m->new_espacio("grupo,sd");
	 CConjunto* alpc = new CConjunto(m);
	 CConjunto* blpc = new CConjunto(m);
	 CConjunto* clpc = new CConjunto(m);
	 alpc->inserta(10);
	 blpc->inserta(10);
	  blpc->inserta(30);
	 alpc->inserta(20);
	 ComplementoInterseccion(alpc, blpc, clpc);
	 cout << clpc->to_str() << endl;
	 cout << CYN "" << endl;
	 m->mostrar();
	 
	return 0;
}