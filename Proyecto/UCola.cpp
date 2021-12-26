// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaV1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ClaseCola::ClaseCola() {
	ini = fin = 0;
	v = new int[MAXVC1];
}

bool ClaseCola::vacia() {
	return ini == fin;
}

void ClaseCola::poner(int e) {
	if (fin < MAXVC1) {
		v[fin] = e;
		fin++;
	}
}

void ClaseCola::sacar(int &e) {
	if (!vacia()) {
		e = v[ini];
		ini++;
	}
}

int ClaseCola::primero() {
	if (!vacia())
		return v[ini];
}

string ClaseCola::mostrar() {
	string s = "Cola: <<";
	int e;
	ClaseCola* aux = new ClaseCola();
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
	/*
	 for(i = ini;i < fin; i++ )
	 s += to_string(v[i]) + ",";
	 */
	return s + "<<\n";
}