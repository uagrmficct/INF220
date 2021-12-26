// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UMatriz.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

MatrizDispersaLRHC::MatrizDispersaLRHC() {
	k = new ListaS();
	df = dc = repe = 0;
}

MatrizDispersaLRHC::MatrizDispersaLRHC(CSMemoria* m) {
	k = new ListaS(m);
	df = dc = repe = 0;
}

int MatrizDispersaLRHC::buscar(int f, int c) {
	int aux = k->primero();
	while (aux != -1) {
		int fi = k->recupera(aux);
		if (fi == f) {
			int ci = k->recupera(k->siguiente(aux));
			if (ci == c)
				return aux;
		}
		aux = k->siguiente(k->siguiente(k->siguiente(aux)));
	}
	return -1;
}

void MatrizDispersaLRHC::dimensionar(int f, int c) {
	df = f;
	dc = c;
}

int MatrizDispersaLRHC::dimension_fila() {
	return df;
}

int MatrizDispersaLRHC::dimension_columna() {
	return dc;
}

void MatrizDispersaLRHC::poner(int f, int c, int valor) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int dir = buscar(f, c);
		if (dir == -1 && valor != repe) { // Dato nuevo
			k->inserta_ultimo(f);
			k->inserta_ultimo(c);
			k->inserta_ultimo(valor);
		}
		else {
			int dirDato = k->siguiente(k->siguiente(dir));
			k->modifica(dirDato, valor);
			if (valor == repe) {
				k->suprime(dirDato);
				k->suprime(k->siguiente(dir));
				k->suprime(dir);
			}
		}
	}
}

int MatrizDispersaLRHC::elemento(int f, int c) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int dir = buscar(f, c);
		if (dir != -1) {
			int dirDato = k->siguiente(k->siguiente(dir));
			return k->recupera(dirDato);
		}
		else
			return repe;
	}
}

void MatrizDispersaLRHC::definir_valor_repetido(int valor) {
	bool hayRepe = false;
	int aux = k->primero();
	while (aux != -1 && hayRepe == false) {
		int dirDato = k->recupera(k->siguiente(k->siguiente(aux)));
		if (k->recupera(dirDato) == valor)
			hayRepe = true;
		aux = k->siguiente(k->siguiente(k->siguiente(aux)));
	}
	if (aux == -1 || hayRepe == false) {
		repe = valor;
	}
	else {
		int nRep = valor;
		int aRep = repe;
		for (int i = 1; i <= df; i++) {
			for (int j = 1; j <= dc; j++) {
				int e = elemento(i, j);
				if (e == nRep) {
					int dir = buscar(i, j);
					int dirDato = k->siguiente(k->siguiente(dir));
					k->suprime(dirDato);
					k->suprime(k->siguiente(dir));
					k->suprime(dir);
				}
				else if (e == aRep) {
					k->inserta_ultimo(i);
					k->inserta_ultimo(j);
					k->inserta_ultimo(aRep);
				}
			}
		}
		repe = valor;
	}
}

string MatrizDispersaLRHC::to_str() {
	string r = "";
	for (int i = 1; i <= df; i++) {
		r += "| ";
		for (int j = 1; j <= dc; j++) {
			int e = elemento(i, j);
			r += to_string(e) + "  ";
		}
		r += "|\n";
	}
	return r;
}

void MatrizDispersaLRHC::mostrar() {
	cout << "K: " << k->to_str() << endl;
	cout << "DimF: " << df << endl;
	cout << "DimC: " << dc << endl;
	cout << "Repe: " << repe << endl;
}