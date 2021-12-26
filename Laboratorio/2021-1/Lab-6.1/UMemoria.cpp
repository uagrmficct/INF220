//---------------------------------------------------------------------------

#pragma hdrstop
#include "UMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void CSMemoria::CSMemoria() {
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
string* CSMemoria::vector_ids(string cad) {
 int n = numero_ids(cad);
 string* vids = new string[n];
 int c = 0;
 while (cad.length() > 0) { // "y,z"  --> "z"
  int pos = cad.find_first_of(",");
  if (pos == -1)
   pos = cad.length();
  string id = cad.substr(0, pos);
  vids[c] = id;
  c++;
  cad.erase(0, pos + 1);
 }
 return vids;
}
int CSMemoria::new_espacio(string cadena) {
 int cant = numero_ids(cadena); // cant = 3
 int dir = this->libre; // dir = 0
 int d = this->libre; // d = 0 --> 1  --> 2
 string* ids = vector_ids(cadena); // ["x", "y", "z"]
 int i = 0;
 for (i = 0; i < cant - 1; i++) { // i = 0, 1, 2
  mem[d].id = ids[i];
  d = mem[d].link;
 }
 mem[d].id = ids[i];
 this->libre = mem[d].link;
 mem[d].link = -1;
 return dir;
}
void CSMemoria::delete_espacio(int dir) {
 int x = dir; // x = 0
 while (mem[x].link != -1) //
   x = mem[x].link; // x = 0 -> 1 -> 2
 mem[x].link = libre;
 libre = dir; // libre = 0
}
void CSMemoria::poner_dato(int dir, string cadena_id, int valor) {
 int z = dir; // z = 0 , cad = "->z" --> "z"
 cadena_id = cadena_id.substr(2, cadena_id.length() - 2);
 // Elimina la flecha
 while (z != NULO) {
  if (mem[z].id == cadena_id) {
   mem[z].dato = valor;
   break;
  }
  z = mem[z].link; // z = 0 --> 1  --> 2
 }
}
int CSMemoria::obtener_dato(int dir, string cadena_id) {
 int z = dir; // z = 0 --> 1 --> 2
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
bool CSMemoria::dir_libre(int dir) { // dir = 2
 int x = libre; // x = 0 --> 1 --> 2 --> 5
 bool c = false; // c = false --> true
 while (x != -1 && c == false) { // T ->
  if (x == dir)
   c = true;
  x = mem[x].link;
 }
 return c;
}
void CSMemoria::mostrar() {
 cout << "DIR   DATO   ID   LINK\n";
 cout << "+--------------------+\n";
 for (int i = 0; i < MAX; i++) {
  cout << i << " |   " << mem[i].dato << " |     " << mem[i]
   .id << " |     " << mem[i].link << endl;
 }
 cout << "+--------------------+\n";
 cout << "Libre = " << libre << endl;
}
