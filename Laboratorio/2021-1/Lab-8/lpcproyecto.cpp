#include <iostream>
#include <string>
#include "UListaS.h"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"


using namespace std;

int main() {
	lpcCSMemoria* MiMemlpc= new lpcCSMemoria();
	int z = MiMemlpc->new_espacio ("Luishino,Pericena,Choque");
	MiMemlpc->poner_dato(z,"->Luishino",MiMemlpc->obtener_dato(z,"->Luishino")+2);
    ListaS* Llpc = new ListaS(MiMemlpc);
	Llpc->inserta_primero(100);
	Llpc->inserta_ultimo(200);
	Llpc->inserta(Llpc->fin(),150);
	MiMemlpc->mostrar();
		 	  cout << CYN "" << endl;
	system("pause");
	return 0;   
}