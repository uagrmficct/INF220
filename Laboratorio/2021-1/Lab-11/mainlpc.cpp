#include <iostream>
#include <string>
#include "PoliS.h"
#include "Memoria.h"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

using namespace std;

bool es_completo(PoliS* p);
int main() {
	CSMemoria  *mem= new CSMemoria();
	PoliS *pl= new PoliS (mem);

	pl->poner_termino(15,8);
	pl->poner_termino(23,0);
	pl->poner_termino(2,1);
	
   if(es_completo(pl) == true){
       
   cout <<GRN "Es polinomio completo" NC<< endl;
   }else
    cout <<REDB "    No esta completo  " NC<< endl;


	
	
	return 0;
}
bool es_completo(PoliS* p) {
	int grado = p->grado();
	int nt = p->numero_terminos();
	bool completo = true;
	if (nt == grado + 1) {
		for (int i = 1; i <= nt; i++) {
			int exp = p->exponente(i);
			if (exp > grado) {
				completo = false;
				break;
			}
		}
		
		return completo;
	}
	return false;
}