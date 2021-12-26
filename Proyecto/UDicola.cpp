// ---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include <string>
#include "UDicolaV2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ClaseDicola::ClaseDicola() {
	ini = fin = 0;
	v = new int[MAXVD2];
}

bool ClaseDicola::vacia() {
	return ini == fin;
}

void ClaseDicola::poner(int e) {
	if (fin < MAXVD2) {
		v[fin] = e;
		fin++;
	}
}

void ClaseDicola::sacar(int &e) {
	if (!vacia()) {
		e = v[0];
		for (int i = 0; i < fin; i++)
			v[i] = v[i + 1];
		fin--;
	}
}

int ClaseDicola::primero() {
	if (!vacia())
		return v[0];
}

int ClaseDicola::ultimo() {
	if (!vacia())
		return v[fin];
}

void ClaseDicola::poner_frente(int e) {
	if (fin < MAXVD2) {
		for (int i = fin; i > 0; i--)
			v[i] = v[i - 1];
		v[0] = e;
		fin++;
	}
}

void ClaseDicola::sacar_final(int &e) {
	if (!vacia()) {
		e = v[fin];
		fin--;
	}
}

string ClaseDicola::mostrar() {
	string s = "Dicola: <<";
	int e;
	ClaseDicola* aux = new ClaseDicola();
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
	return s + ">>\n";
}