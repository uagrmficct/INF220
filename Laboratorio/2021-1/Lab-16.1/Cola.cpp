// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Cola.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Cola::Cola() {
	ini = 1;
	fin = 0;
	v = new int[MAXVC3];
}

bool Cola::vacia() {
	return siguiente(fin) == ini;
}

int Cola::siguiente(int dir) {
	if (dir == MAXVC3)
		return 1;
	else
		return dir + 1;
}

void Cola::poner(int e) {
	if (siguiente(siguiente(fin)) != ini) {
		fin = siguiente(fin);
		v[fin - 1] = e;
	}
}

void Cola::sacar(int &e) {
	if (!vacia()) {
		e = v[ini - 1];
		ini = siguiente(ini);
	}
}

int Cola::primero() {
	if (!vacia())
		return v[ini - 1];
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