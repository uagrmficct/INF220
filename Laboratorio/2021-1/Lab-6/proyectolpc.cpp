#include <iostream>
#include <string>
#include "CSMemorialpc.h"


#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

using std::cout; using std::endl;

int main() {
CSMemorialpc* MiMemlpc=new CSMemorialpc();
	 int x,y,z;
	 x=MiMemlpc->new_espacio("uno");
	 MiMemlpc->poner_dato(x,"->uno",100);
	 y=MiMemlpc->new_espacio("dos");
	 MiMemlpc->delete_espacio(x);
	 z=MiMemlpc->new_espacio("Luishino,Pericena,Choque");
	 MiMemlpc->poner_dato(z,"->Luishino",MiMemlpc->obtener_dato(z,"->Luishino")+5);
	 MiMemlpc->mostrar_memoria();
	 	  cout << CYN "" << endl;
	system("pause");
	return 0;   
}