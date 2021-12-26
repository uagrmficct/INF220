// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ULista.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaLPC::ListaLPC() {
	m = new CSMemoria();
	ptr_lista = -1;
	longi = 0;
}

ListaLPC::ListaLPC(CSMemoria* mem) {
	m = mem;
	ptr_lista = -1;
	longi = 0;
}

int ListaLPC::fin() {
	if (!vacia())
		return m->obtener_dato(ptr_lista, "->ant");
}

int ListaLPC::primero() {
	return ptr_lista;
}

int ListaLPC::siguiente(int P) {
	int p_sig = m->obtener_dato(P, "->sig");
	if (!vacia() && p_sig != primero())
		return p_sig;
}

int ListaLPC::anterior(int P) {
	int p_ant = m->obtener_dato(P, "->ant");
	if (!vacia() && p_ant != fin())
		return p_ant;
}

bool ListaLPC::vacia() {
	return longi == 0;
}

int ListaLPC::recupera(int P) {
	if (!vacia())
		return m->obtener_dato(P, "->dato");
}

int ListaLPC::longitud() {
	return longi;
}

void ListaLPC::inserta_primero(int e) {
	int nuevo = m->new_espacio("ant,dato,sig");
	if (nuevo != -1) {
		m->poner_dato(nuevo, "->dato", e);
		if (vacia()) {
			m->poner_dato(nuevo, "->ant", nuevo);
			m->poner_dato(nuevo, "->sig", nuevo);
			ptr_lista = nuevo;
			longi = 1;
		}
		else {
			m->poner_dato(nuevo, "->ant", fin());
			m->poner_dato(nuevo, "->sig", ptr_lista);
			int final = fin();
			m->poner_dato(final, "->sig", nuevo);
			m->poner_dato(ptr_lista, "->ant", nuevo);
			ptr_lista = nuevo;
			longi++;
		}
	}
}

void ListaLPC::inserta_ultimo(int e) {
	int nuevo = m->new_espacio("ant,dato,sig");
	if (nuevo != -1) {
		m->poner_dato(nuevo, "->dato", e);
		if (vacia()) {
			m->poner_dato(nuevo, "->ant", nuevo);
			m->poner_dato(nuevo, "->sig", nuevo);
			ptr_lista = nuevo;
			longi = 1;
		}
		else {
			m->poner_dato(nuevo, "->ant", fin());
			m->poner_dato(nuevo, "->sig", ptr_lista);
			int final = fin();
			m->poner_dato(final, "->sig", nuevo);
			m->poner_dato(ptr_lista, "->ant", nuevo);
			longi++;
		}
	}
}

void ListaLPC::inserta(int P, int e) {
	int nuevo = m->new_espacio("ant,dato,sig");
	if (nuevo != -1) {
		m->poner_dato(nuevo, "->ant", -1);
		m->poner_dato(nuevo, "->sig", -1);
		m->poner_dato(nuevo, "->dato", e);
		if (vacia()) {
			m->poner_dato(nuevo, "->ant", nuevo);
			m->poner_dato(nuevo, "->sig", nuevo);
			ptr_lista = nuevo;
			longi = 1;
		}
		else {
			if (P == primero() || longi == 1) {
				m->poner_dato(nuevo, "->sig", P);
				m->poner_dato(nuevo, "->ant", fin());
				ptr_lista = nuevo;
				m->poner_dato(P, "->ant", ptr_lista);
				int final = fin();
				m->poner_dato(final, "->sig", ptr_lista);
			}
			else {
				int ant = m->obtener_dato(P, "->ant");
				m->poner_dato(ant, "->sig", nuevo);
				m->poner_dato(nuevo, "->ant", ant);
				m->poner_dato(nuevo, "->sig", P);
				m->poner_dato(P, "->ant", nuevo);
			}
			longi++;
		}
	}
}

void ListaLPC::suprime(int P) {
	if (!vacia()) {
		if (longi == 1)
			ptr_lista = -1;
		else if (P == primero()) {
			int fi = fin();
			ptr_lista = m->obtener_dato(ptr_lista, "->sig");
			m->poner_dato(ptr_lista, "->ant", fi);
		}
		else if (P == fin()) {
			int pen = m->obtener_dato(fin(), "->ant");
			m->poner_dato(pen, "->sig", ptr_lista);
			m->poner_dato(ptr_lista, "->ant", pen);
		}
		else {
			int ant = m->obtener_dato(P, "->ant");
			int sig = m->obtener_dato(P, "->sig");
			m->poner_dato(ant, "->sig", sig);
			m->poner_dato(sig, "->ant", ant);
		}
		m->delete_espacio(P);
		longi--;
	}
}

void ListaLPC::desenlazar(int P) {
	if (!vacia()) {
		if (longi == 1)
			ptr_lista = -1;
		else if (P == primero()) {
			int fi = fin();
			ptr_lista = m->obtener_dato(ptr_lista, "->sig");
			m->poner_dato(ptr_lista, "->ant", fi);
		}
		else if (P == fin()) {
			int pen = m->obtener_dato(fin(), "->ant");
			m->poner_dato(pen, "->sig", ptr_lista);
			m->poner_dato(ptr_lista, "->ant", pen);
		}
		else {
			int ant = m->obtener_dato(P, "->ant");
			int sig = m->obtener_dato(P, "->sig");
			m->poner_dato(ant, "->sig", sig);
			m->poner_dato(sig, "->ant", ant);
		}
		longi--;
	}
}

void ListaLPC::modifica(int P, int e) {
	if (!vacia())
		m->poner_dato(P, "->dato", e);
}

string ListaLPC::to_str() {
	int aux = ptr_lista;
	cout << "[";
	for (int i = 0; i < longi; i++) {
		cout << m->obtener_dato(aux, "->dato");
		if (i < longi - 1)
			cout << ",";
		aux = m->obtener_dato(aux, "->sig");
	}
	cout << "]" << endl;
	return "";
}

void ListaLPC::ordenar() {
	int n = longi;
	int mm = n;
	for (int i = 0; i < n; i++) {
		int aux = ptr_lista;
		int menor = aux;
		for (int j = 0; j < mm; j++) {
			int aux_dato = m->obtener_dato(aux, "->dato");
			int men_dato = m->obtener_dato(menor, "->dato");
			if (aux_dato < men_dato)
				menor = aux;
			aux = m->obtener_dato(aux, "->sig");
		}
		desenlazar(menor);
		aux = ptr_lista;
		for (int i = 0; i < longi - 1; i++)
			aux = m->obtener_dato(aux, "->sig");
		m->poner_dato(menor, "->ant", aux);
		m->poner_dato(menor, "->sig", ptr_lista);
		m->poner_dato(ptr_lista, "->ant", menor);
		m->poner_dato(aux, "->sig", menor);
		longi++;
		mm--;
	}
}