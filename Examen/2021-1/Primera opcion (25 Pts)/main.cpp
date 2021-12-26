
#include <stdio.h>
#include "PoliLP.h"
#include "ListaP.h"
#include <stdio.h>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
using namespace std;



int main(){
  
	Polinomio *PLPC= new Polinomio();
	PLPC->poner_termino(4,7);
	PLPC->poner_termino(5,1);
	PLPC->poner_termino(9,2);
	PLPC->mostrar();
	PLPC->derivar();
	PLPC->mostrar();
	return 0;
}


