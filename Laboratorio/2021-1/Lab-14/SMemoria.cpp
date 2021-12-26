//---------------------------------------------------------------------------

#pragma hdrstop

#include "SMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

SMemoria::SMemoria() {
	mem = new NodoMem[MAX];
	for (int i = 0; i < MAX; i++) {
		mem[i].link = i + 1;
	}
	mem[MAX - 1].link = -1;
	this->libre = 0;
}

int SMemoria::numero_ids(string id) {
	if (id.length() == 0)
		return 0;
	int cont = 0;
	for (int i = 0; i < id.length(); i++) {
		if (id[i] == ',')
			cont++;
	}
	return cont + 1;
}

int SMemoria::new_espacio(string cadena) {
	int num = numero_ids(cadena);
	if (num <= espacio_disponible()) {
		int d = this->libre;
		int dir = d;
		int aux;
		while (cadena.length() > 0) {
			int pos = cadena.find_first_of(",");
			if (pos == -1) {
				pos = cadena.length();
				aux = d;
			}
			string id = cadena.substr(0, pos);
			mem[d].id = id;
			d = mem[d].link;
			cadena.erase(0, pos + 1);
		}
		this->libre = mem[aux].link;
		mem[aux].link = -1;
		return dir;
	}
	else {
		cout << "ERROR: ESPACIOS INSUFICIENTES\n";
		return NULO;
	}
}

void SMemoria::delete_espacio(int dir) {
	int x = dir;
	while (mem[x].link != -1)
		x = mem[x].link;
	mem[x].link = libre;
	libre = dir;
}

void SMemoria::poner_dato(int dir, string cadena_id, int valor) {
	int z = dir;
	cadena_id = cadena_id.substr(2, cadena_id.length() - 2);
	// Elimina la flecha
	while (z != NULO) {
		if (mem[z].id == cadena_id) {
			mem[z].dato = valor;
			break;
		}
		z = mem[z].link;
	}
}

int SMemoria::obtener_dato(int dir, string cadena_id) {
	int z = dir;
	cadena_id = cadena_id.substr(2, cadena_id.length() - 2);
	// Elimina la flecha
	while (z != NULO) {
		if (mem[z].id == cadena_id)
			return mem[z].dato;
		z = mem[z].link;
	}
}

int SMemoria::espacio_disponible() {
	int x = libre;
	int c = 0;
	while (x != -1) {
		c++;
		x = mem[x].link;
	}
	return c;
}

int SMemoria::espacio_ocupado() {
	int c = MAX - espacio_disponible();
	return c;
}

bool SMemoria::dir_libre(int dir) {
	int x = libre;
	bool c = false;
	while (x != -1 && c == false) {
		if (x == dir)
			c = true;
		x = mem[x].link;
	}
	return c;
}

void SMemoria::mostrar() {
	string cab = "       | DIR |  DATO  |    ID    | LINK |\n";
	string lin = "       +" + string(cab.length() - 10, '-') + "+\n";
	string out = lin + cab + lin;
	int edir = 3, edat = 8, eid = 10; // eid lo cambian
	for (int i = 0; i < MAX; i++) {
		string ocup = !dir_libre(i) ? "ocupado" : "       ";
		//
		int rel = edir - to_string(i).length();
		string dir = " " + string(rel, '0') + to_string(i) + " ";
		rel = edat - to_string(mem[i].dato).length();
		string dat = string(rel, ' ') + to_string(mem[i].dato);
		rel = eid - mem[i].id.length();
		string id = string(rel, ' ') + mem[i].id;
		rel = edir - to_string(mem[i].link).length();
		string lnk = "  " + string(rel, ' ') + to_string(mem[i].link) + " ";
		out += ocup + "|" + dir + "|" + dat + "|" + id + "|" + lnk + "|\n";
	}
	out += lin;
	out += "Libre = " + to_string(libre) + "\n";
	out += "Espacios libres = " + to_string(espacio_disponible()) + "\n";
	out += "Espacios ocupados = " + to_string(espacio_ocupado()) + "\n";
	cout << out;
}