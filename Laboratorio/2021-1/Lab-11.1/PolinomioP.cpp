// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliP::PoliP() {
	ptr_poli = NULL;
	nt = 0;
}

NodoPo* PoliP::buscar_exponente(int exp) {
	NodoPo * aux = ptr_poli;
	while (aux != NULL) {
		if (aux->exp == exp)
			return aux;
		aux = aux->sig;
	}
	return NULL;
}

NodoPo* PoliP::buscar_termino_n(int i) {
	int c = 1;
	NodoPo * aux = ptr_poli;
	while (aux) {
		if (c == i)
			return aux;
		c++;
		aux = aux->sig;
	}
	return NULL;
}

bool PoliP::es_cero() {
	return ptr_poli == NULL;
}

int PoliP::grado() {
	if (!es_cero()) {
		int max = ptr_poli->exp;
		NodoPo * aux = ptr_poli;
		while (aux) {
			if (aux->exp > max)
				max = aux->exp;
			aux = aux->sig;
		}
		return max;
	}
}

int PoliP::coeficiente(int exp) {
	NodoPo* dir = buscar_exponente(exp);
	if (dir)
		return dir->coef;
	else
		cout << "No existe ese termino" << endl;
}

NodoPo* PoliP::anterior(NodoPo* dir) {
	NodoPo* aux = ptr_poli;
	NodoPo* ant = NULL;
	while (aux && aux != dir) {
		ant = aux;
		aux = aux->sig;
	}
	return ant;
}

void PoliP::suprime(NodoPo* dir) {
	if (dir == ptr_poli) {
		ptr_poli = ptr_poli->sig;
	}
	else {
		// --
		NodoPo* aux = ptr_poli;
		NodoPo* ant = NULL;
		while (aux && aux != dir) {
			ant = aux;
			aux = aux->sig;
		}
		// --
		NodoPo* ante = ant;
		ante->sig = dir->sig;
	}
	delete(dir);
}

void PoliP::asignar_coeficiente(int coef, int exp) {
	NodoPo* dir = buscar_exponente(exp);
	if (dir) {
		dir->coef = coef;
		if (coef == 0) {
			suprime(dir);
			nt--;
		}
	}
}

void PoliP::poner_termino(int coef, int exp) {
	NodoPo* dir = buscar_exponente(exp);
	if (!dir) {
		if (coef != 0) {
			NodoPo* nuevo = new NodoPo();
			nuevo->coef = coef;
			nuevo->exp = exp;
			nuevo->sig = ptr_poli;
			ptr_poli = nuevo;
			nt++;
		}
	}
	else {
		int new_coef = coef + dir->coef;
		dir->coef = new_coef;
		if (new_coef == 0) {
			suprime(dir);
			nt--;
		}
	}
}

int PoliP::numero_terminos() {
	return nt;
}

int PoliP::exponente(int nro_ter) {
	NodoPo* dir = buscar_termino_n(nro_ter);
	if (dir)
		return dir->exp;
	
}

string PoliP::to_str() {
	string r = "";
	int n = numero_terminos();
	for (int i = 1; i <= n; i++) {
		int exp = exponente(i);
		int coef = coeficiente(exp);
		if (coef > 0)
			r += "+";
		r += to_string(coef) + "x^" + to_string(exp);
	}
	return r;
}
void PoliP::derivada(PoliP *p) {
	for (int i = 0; i < numero_terminos(); i++) {
		int exp = exponente(i + 1);
		int coef = coeficiente(exp);
		p->poner_termino(coef*exp, exp - 1);
	}
}

void PoliP::mostrar_integral() {
	for (int i = 0; i < numero_terminos(); i++) {
		int exp = exponente(i + 1);
		int coef = coeficiente(exp);
		cout << "(" << coef << "x^" << (exp + 1) << ")/" << (exp + 1);
		if (i < numero_terminos() - 1)
			cout << "+";
	}
	cout << endl;
}

PoliP* PoliP::suma(PoliP* a, PoliP* b) {
	PoliP* p = new PoliP();
	for (int i = 0; i < a->numero_terminos(); i++) {
		int exp = a->exponente(i + 1);
		int coef = a->coeficiente(exp);
		p->poner_termino(coef, exp);
	}
	for (int i = 0; i < b->numero_terminos(); i++) {
		int exp = b->exponente(i + 1);
		int coef = b->coeficiente(exp);
		p->poner_termino(coef, exp);
	}
	return p;
}

PoliP* PoliP::resta(PoliP* a, PoliP* b) {
	PoliP* p = new PoliP();
	for (int i = 0; i < a->numero_terminos(); i++) {
		int exp = a->exponente(i + 1);
		int coef = a->coeficiente(exp);
		p->poner_termino(coef, exp);
	}
	for (int i = 0; i < b->numero_terminos(); i++) {
		int exp = b->exponente(i + 1);
		int coef = b->coeficiente(exp);
		p->poner_termino(-coef, exp);
	}
	return p;
}

PoliP* PoliP::producto(PoliP* a, PoliP* b) {
	PoliP* p = new PoliP();
	for (int i = 1; i <= b->numero_terminos(); i++) {
		int expB = b->exponente(i);
		int coefB = b->coeficiente(expB);
		for (int j = 1; j <= a->numero_terminos(); j++) {
			int expA = a->exponente(j);
			int coefA = a->coeficiente(expA);
			int new_coef = coefA * coefB;
			int new_exp = expA + expB;
			p->poner_termino(new_coef, new_exp);
		}
	}
	return p;
}
