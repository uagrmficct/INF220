// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UMatriz.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

matrizdispersa::matrizdispersa() {
	k = new ListaS();
	repe = df = dc = 0;
}

void matrizdispersa::dimensionar(int f, int c) {
	df = f;
	dc = c;
}

int matrizdispersa::dimension_fila() {
	return df;
}

int matrizdispersa::dimension_columna() {
	return dc;
}

int matrizdispersa::numero_terminos() {
	return k->longitud() / 3;
}

int matrizdispersa::buscar(int f, int c) {
	int aux = k->primero();
	while (aux != NULO) { // aux != NULO
		if (k->recupera(aux) == f && k->recupera(k->siguiente(aux)) == c)
			return aux;
		aux = k->siguiente(k->siguiente(k->siguiente(aux)));
	}
	return NULO; // return NULO
}

void matrizdispersa::poner(int f, int c, int valor) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		if (numero_terminos() == 0 && valor != repe) {
			k->inserta_ultimo(f);
			k->inserta_ultimo(c);
			k->inserta_ultimo(valor);
		}
		else {
			int aux = buscar(f, c);
			if (aux == NULO && valor != repe) {
				k->inserta_ultimo(f);
				k->inserta_ultimo(c);
				k->inserta_ultimo(valor);
			}
			else {
				int Datos = k->siguiente(k->siguiente(aux));
				k->modifica(Datos, valor);
				if (valor == repe) {
					k->suprime(Datos);
					k->suprime(k->siguiente(aux));
					k->suprime(aux);
				}
			}
		}
	}
}

int matrizdispersa::elemento(int f, int c) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int dir = buscar(f, c);
		if (dir != NULO) {
			int Datos = k->siguiente(k->siguiente(dir));
			return k->recupera(Datos);
		}
		else
			return repe;
	}
}

void matrizdispersa::definir_valor_repetido(int valor) {
	bool re = false;
	int aux = k->primero();
	while (aux != NULO) {
		int nd = k->siguiente(k->siguiente(aux));
		if (k->recupera(nd) == valor) {
			re = true;
			break;
		}
		aux = k->siguiente(k->siguiente(k->siguiente(aux)));
	}
	if (numero_terminos() == 0 || re == false) {
		repe = valor;
	}
	else {
		int nRep = valor, aRep = repe;
		for (int i = 1; i <= df; i++) {
			for (int j = 1; j <= dc; j++) {
				int e = elemento(i, j);
				if (e == nRep) {
					int aux = buscar(i, j);
					k->suprime(k->siguiente(k->siguiente(aux)));
					k->suprime(k->siguiente(aux));
					k->suprime(aux);
				}
				else if (e == aRep) {
					k->inserta_ultimo(i);
					k->inserta_ultimo(j);
					k->inserta_ultimo(e);
				}
			}
		}
		repe = valor;
	}
}

void matrizdispersa::mostrar() {
	string r = "";
	r += "df: " + to_string(df) + "\n";
	r += "dc: " + to_string(dc) + "\n";
	r += "repe: " + to_string(repe) + "\n";
	r += "NT: " + to_string(numero_terminos()) + "\n";
	cout<< r;
}