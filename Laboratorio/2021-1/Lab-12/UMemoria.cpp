#pragma hdrstop

#include "UMemoria.h"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

CSMemoria::CSMemoria() {
	mem = new NodoMem[MAX];
	for (int i = 0; i < MAX; i++) {
		mem[i].link = i + 1;
	}
	mem[MAX - 1].link = -1;
	this->libre = 0;
}

int CSMemoria::numero_ids(string id) {
	if (id.length() == 0)
		return 0;
	int cont = 0;
	for (int i = 0; i < id.length(); i++) {
		if (id[i] == ',')
			cont++;
	}
	return cont + 1;
}

int CSMemoria::new_espacio(string cadena) {
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

void CSMemoria::delete_espacio(int dir) {
	int x = dir;
	while (mem[x].link != -1)
		x = mem[x].link;
	mem[x].link = libre;
	libre = dir;
}

void CSMemoria::poner_dato(int dir, string cadena_id, int valor) {
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

int CSMemoria::obtener_dato(int dir, string cadena_id) {
	int z = dir;
	cadena_id = cadena_id.substr(2, cadena_id.length() - 2);
	// Elimina la flecha
	while (z != NULO) {
		if (mem[z].id == cadena_id)
			return mem[z].dato;
		z = mem[z].link;
	}
}

int CSMemoria::espacio_disponible() {
	int x = libre;
	int c = 0;
	while (x != -1) {
		c++;
		x = mem[x].link;
	}
	return c;
}

int CSMemoria::espacio_ocupado() {
	int c = MAX - espacio_disponible();
	return c;
}

bool CSMemoria::dir_libre(int dir) {
	int x = libre;
	bool c = false;
	while (x != -1 && c == false) {
		if (x == dir)
			c = true;
		x = mem[x].link;
	}
	return c;
}


void CSMemoria::mostrar() {
string cab = GRN "| DIR |  DATO  |    ID    | LINK |\n" NC;
  string lin =  "*" + string(cab.length() - 3, '-') + "+\n";
  string out = lin + cab + lin;
   cout << NC "  " << endl; 
    cout << REDB "          PROYECTO-ED1            " NC << endl; 
    cout << NC "  " << endl; 
	int edir = 3, edat = 8, eid = 10;
	for (int i = 0; i < MAX; i++) {
		int rel = edir - to_string(i).length();
		string dir = " " + string(rel, '0') + to_string(i) + " ";
		rel = edat - to_string(mem[i].dato).length();
		string dat = string(rel, ' ') + to_string(mem[i].dato);
		rel = eid - mem[i].id.length();
		string id = string(rel, ' ') + mem[i].id;
		rel = edir - to_string(mem[i].link).length();
		string lnk = "  " + string(rel, ' ') + to_string(mem[i].link) + " ";
		out += "|" + dir + "|" + dat + "|" + id + "|" + lnk + "|\n";
	}
  out += lin;
  cout << out;
  cout << RED " [*] Libre = " NC + to_string(libre)<< endl;
  cout << RED " [*] Espacios libres = " NC + to_string(espacio_disponible())<< endl;
  cout << RED " [*] Espacios ocupados = " NC + to_string(espacio_ocupado())<< endl;
}