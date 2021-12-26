#pragma hdrstop

#include "UCola.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

    cola::cola() {
	ini = NULO;
	fin = NULO;
	mem = new CSMemoria();
}

cola::cola(CSMemoria* m) {
	mem = m;
	ini = NULO;
	fin = NULO;
}

bool cola::vacia() {
	return ini == NULO && fin == NULO;
}

void cola::poner(int e) {
	int nuevo = mem->new_espacio(datos);
	mem->poner_dato(nuevo, elem, e);
	if (vacia()) {
		mem->poner_dato(nuevo, ant, nuevo);
		mem->poner_dato(nuevo, sig, nuevo);
		ini = nuevo;
		fin = nuevo;
	}
	else {
		mem->poner_dato(nuevo, ant, fin);
		mem->poner_dato(nuevo, sig, ini);
		mem->poner_dato(fin, sig, nuevo);
		mem->poner_dato(fin, ant, nuevo);
		fin = nuevo;
	}
}

void cola::sacar(int &e) {
	if (!vacia()) {
		int x = ini;
		e = mem->obtener_dato(ini, elem);
		if (ini == fin) {
			ini = NULO;
			fin = NULO;
		}
		else {
			ini = mem->obtener_dato(ini, sig);
			mem->poner_dato(ini, ant, fin);
			mem->poner_dato(fin, sig, ini);
		}
		mem->delete_espacio(x);
	}
}

int cola::primero() {
	if (!vacia()) {
		return mem->obtener_dato(ini, elem);
	}
}

string cola::to_str() {
	string s = "<<";
	int e;
	cola* aux = new cola();
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