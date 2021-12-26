#include <iostream>
#include "ColaLPC.h"
#include "PilaLPC.h"
#include "CSMemoria.h"
using namespace std;
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define NC "\e[41m"

void invertir(ColaLPC* cLPC) {
 PilaLPC* pLPC = new PilaLPC();
 while(!cLPC->vacia()){
  int x;
  cLPC->sacar(x);
  pLPC->meter(x);
 }
 while(!pLPC->vacia()){
  int x;
  pLPC->sacar(x);
        cLPC->poner(x);
 }
}

int main() {
    
 PilaLPC* pLPC;
 CSMemoria* m;     
 ColaLPC* cLPC;
 do {
     cout <<  "         MENU - PROYECTO-ED1 Lab-16           " << endl;
  cout << "1.-Crear Memoria\n";
  cout << "2.-Crear cola\n";
  cout << "3.-Poner en la cola\n";
  cout << "4.-Mostrar cola\n";
  cout << "5.-Crear pila\n";
  cout << "6.-Poner en la pila\n";
  cout << "7.-Mostrar pila\n";
  cout << "8.-Invertir cola\n";
  cout << "9.-Mostrar Memoria\n";
  cout << "10.-Salir\n";
  int opcion;
  cout << "Escriba su opcion: ";
  cin >> opcion;
  if (opcion == 1) {
   m = new CSMemoria();
  }
     else if (opcion == 2) {
   cLPC = new ColaLPC(m);
  }
  else if (opcion == 3) {
   int el;
   cout << "Ingrese Elemento: ";
   cin >> el;
   cLPC->poner(el);
  }
  else if (opcion == 4) {
   cout << cLPC->to_str() << endl;
  }
  else if (opcion == 5) {
   pLPC = new PilaLPC(m);
  }
  else if (opcion == 6) {
   int el;
   cout << "Ingrese Elemento: ";
   cin >> el;
   pLPC->meter(el);
  }
  else if (opcion == 7) {
   cout << pLPC->to_str() << endl;
  }
  else if (opcion == 8) {
            invertir(cLPC);
  }
  else if (opcion == 9) {
            m->mostrar();
  }
  else if (opcion == 10) {
   break;
  }
  cout << endl << endl;
 }
 while (true);
 
  
  
 return 0;
}