// ---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemorialpc.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
CSMemorialpc::CSMemorialpc() {
  MiMemlpc = new NodoMem[MAX];
  for (int i = 0; i < MAX; i++) {
    MiMemlpc[i].link = i + 1;
  }
  MiMemlpc[MAX - 1].link = -1;
  this->libre = 0;
}

int CSMemorialpc::numero_ids(string id) {
  if (id.length() == 0)
    return 0;
  int cont = 0;
  for (int i = 0; i < id.length(); i++) {
    if (id[i] == ',')
      cont++;
  }
  return cont + 1;
}


int CSMemorialpc::new_espacio(string cadena) {
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
      MiMemlpc[d].id = id;
      d = MiMemlpc[d].link;
      cadena.erase(0, pos + 1);
    }
    this->libre = MiMemlpc[aux].link;
    MiMemlpc[aux].link = -1;
    return dir;
  }
  else {
      cout << REDB "ERROR: ESPACIOS INSUFICIENTES " NC<< endl; 
    return NULO;
  }
}

void CSMemorialpc::delete_espacio(int dir) {
  int x = dir;
  while (MiMemlpc[x].link != -1)
    x = MiMemlpc[x].link;
  MiMemlpc[x].link = libre;
  libre = dir;
}

void CSMemorialpc::poner_dato(int dir, string cadena_id, int valor) {
  int z = dir;
  cadena_id = cadena_id.substr(2, cadena_id.length() - 2);
  while (z != NULO) {
    if (MiMemlpc[z].id == cadena_id) {
      MiMemlpc[z].dato = valor;
      break;
    }
    z = MiMemlpc[z].link;
  }
}

int CSMemorialpc::obtener_dato(int dir, string cadena_id) {
  int z = dir;
  cadena_id = cadena_id.substr(2, cadena_id.length() - 2);
  // Elimina la flecha
  while (z != NULO) {
    if (MiMemlpc[z].id == cadena_id)
      return MiMemlpc[z].dato;
    z = MiMemlpc[z].link;
  }
}

int CSMemorialpc::espacio_disponible() {
  int x = libre;
  int c = 0;
  while (x != -1) {
    c++;
    x = MiMemlpc[x].link;
  }
  return c;
}

int CSMemorialpc::espacio_ocupado() {
  int c = MAX - espacio_disponible();
  return c;
}

bool CSMemorialpc::dir_libre(int dir) {
  int x = libre;
  bool c = false;
  while (x != -1 && c == false) {
    if (x == dir)
      c = true;
    x = MiMemlpc[x].link;
  }
  return c;
}


void CSMemorialpc::mostrar_memoria() {
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
    rel = edat - to_string(MiMemlpc[i].dato).length();
    string dat = string(rel, ' ') + to_string(MiMemlpc[i].dato);
    rel = eid - MiMemlpc[i].id.length();
    string id = string(rel, ' ') + MiMemlpc[i].id;
    rel = edir - to_string(MiMemlpc[i].link).length();
    string lnk = "  " + string(rel, ' ') + to_string(MiMemlpc[i].link) + " ";
    out += "|" + dir + "|" + dat + "|" + id + "|" + lnk + "|\n";
       

  }
  out += lin;
  cout << out;
  cout << RED " [*] Libre = " NC + to_string(libre)<< endl;
  cout << RED " [*] Espacios libres = " NC + to_string(espacio_disponible())<< endl;
  cout << RED " [*] Espacios ocupados = " NC + to_string(espacio_ocupado())<< endl;


}