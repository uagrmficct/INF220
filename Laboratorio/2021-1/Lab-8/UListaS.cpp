#pragma hdrstop

#include "UListaS.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaS::ListaS() {
	ptr_elementos = NULO;
	longit = 0;
	MiMemlpc = new lpcCSMemoria();
}

ListaS::ListaS(lpcCSMemoria* m) {
	ptr_elementos = NULO;
	longit = 0;
	MiMemlpc = m;
}

int ListaS::fin() {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		int x = ptr_elementos;
		int ptr_fin;
		while (x != NULO) {
			ptr_fin = x;
			x = MiMemlpc->obtener_dato(x, sigNL);
		}
		return ptr_fin;
	}
}

int ListaS::primero() {
	if (!vacia())
		return ptr_elementos;
	else
		cout << "ERROR: LISTA VACIA\n";
}

int ListaS::siguiente(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == fin())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return MiMemlpc->obtener_dato(d, sigNL); // d->sig;
	}
}

int ListaS::anterior(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == primero())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else {
			int x = ptr_elementos;
			int ant = NULO;
			while (x != NULO) {
				if (x == d)
					return ant;
				ant = x;
				x = MiMemlpc->obtener_dato(x, sigNL); // x->sig;
			}
			return NULO;
		}
	}
}

bool ListaS::vacia() {
	return longit == 0;
}

int ListaS::recupera(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		return MiMemlpc->obtener_dato(d, elemNL);
}

int ListaS::longitud() {
	return longit;
}

void ListaS::inserta(int d, int e) {
	int x = MiMemlpc->new_espacio(datosNL);
	if (x != NULO) {
		MiMemlpc->poner_dato(x, elemNL, e);
		MiMemlpc->poner_dato(x, sigNL, NULO);
		if (vacia()) {
			ptr_elementos = x;
			longit = 1;
		}
		else {
			longit++;
			if (d == primero()) {
				MiMemlpc->poner_dato(x, sigNL, d);
				ptr_elementos = x;
			}
			else {
				int ant = anterior(d);
				MiMemlpc->poner_dato(ant, sigNL, x);
				MiMemlpc->poner_dato(x, sigNL, d);
			}

		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::inserta_primero(int e) {
	int x = MiMemlpc->new_espacio(datosNL);
	if (x != NULO) {
		MiMemlpc->poner_dato(x, elemNL, e);
		MiMemlpc->poner_dato(x, sigNL, ptr_elementos);
		ptr_elementos = x;
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::inserta_ultimo(int e) {
	int x = MiMemlpc->new_espacio(datosNL);
	if (x != NULO) {
		MiMemlpc->poner_dato(x, elemNL, e);
		MiMemlpc->poner_dato(x, sigNL, NULO);
		if (vacia())
			ptr_elementos = x;
		else
			MiMemlpc->poner_dato(fin(), sigNL, x);
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}


void ListaS::suprime(int d) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d == ptr_elementos) {
		int x = ptr_elementos;
		ptr_elementos = MiMemlpc->obtener_dato(ptr_elementos, sigNL);

		MiMemlpc->delete_espacio(x);
	}
	else {
		int ant = anterior(d);
		MiMemlpc->poner_dato(ant, sigNL, MiMemlpc->obtener_dato(d, sigNL));

		MiMemlpc->delete_espacio(d);
	}
	longit--;
}

void ListaS::modifica(int d, int e) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		MiMemlpc->poner_dato(d, elemNL, e);
}

string ListaS::to_str() {

	string s = "[";
	int aux = ptr_elementos;
	while (aux != NULO) {
		int el = MiMemlpc->obtener_dato(aux, elemNL);
		s += to_string(el);
		aux = MiMemlpc->obtener_dato(aux, sigNL);
		if (aux != NULO)
			s += ",";
	}
	return s + "]";
}

int ListaS::localiza(int e) {
	int aux = ptr_elementos;
	while (aux != NULO) {
		if (MiMemlpc->obtener_dato(aux, elemNL) == e)
			return aux;
		aux = MiMemlpc->obtener_dato(aux, sigNL);
	}
	return NULO;
}

void ListaS::elimina_dato(int e) {
	int aux = ptr_elementos;
	while (aux != NULO) {
		if (MiMemlpc->obtener_dato(aux, elemNL) == e) {
			int sup = aux;
			aux = MiMemlpc->obtener_dato(aux, sigNL);
			suprime(sup);
		}
		else
			aux = MiMemlpc->obtener_dato(aux, sigNL);
	}
}

void ListaS::anula() {
	ptr_elementos = NULO;
	longit = 0;
}
