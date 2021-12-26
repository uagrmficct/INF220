// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UCola.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Cola::Cola() {
	k = new PilaP();
}

bool Cola::vacia() {
	return k->vacia();
}

void Cola::poner(int e) {
	k->meter(e);
}

void Cola::sacar(int &e) {
	if (!vacia()) {
		PilaP* aux = new PilaP();
		while (!k->vacia()) {
			int x;
			k->sacar(x);
			aux->meter(x);
		}
		aux->sacar(e);
		while (!aux->vacia()) {
			int x;
			aux->sacar(x);
			k->meter(x);
		}
	}
}

int Cola::primero() {
	if (!vacia()) {
		PilaP* aux = new PilaP();
		while (!k->vacia()) {
			int x;
			k->sacar(x);
			aux->meter(x);
		}
        int e = aux->cima();
		while (!aux->vacia()) {
			int x;
			aux->sacar(x);
			k->meter(x);
		}
        return e;
	}
}

string Cola::to_str() {
	string s = "<<";
	int e;
	Cola* aux = new Cola();
	while (!vacia()) {
		sacar(e);
		aux->poner(e);
		s += to_string(e);
		if (!vacia())
			s += ",";
	}
	while (!aux->vacia()) {
		aux->sacar(e);
		poner(e);
	}
	return s + "<<";
}