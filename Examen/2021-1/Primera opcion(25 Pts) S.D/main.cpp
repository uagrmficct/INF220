#include "TDAconjuntoCSMemoria.h"
#include "CSMemoria.h"
#include "UPoliListaSm.h"
#include "UPoliListaSm.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    CSMemoria* mem=new CSMemoria();
	ListaSM* L=new ListaSM(mem);
	ConjuntoSM* c=new ConjuntoSM(mem);
	PoliListaSm* p=new PoliListaSm(mem);
	int A=mem->New_Espacio("Luishiño");
	int B=mem->New_Espacio("Pericena");
	int C=mem->New_Espacio("Choque");
	mem->Delete_Espacio(A);
	L->inserta(L->primero(),100);
	L->inserta(L->primero(),90);
	mem->Delete_Espacio(B);
	c->inserta(88);

	p->poner_termino(9,3);
	p->poner_termino(5,1);
	p->poner_termino(4,7);
	L->inserta(L->fin(),95);
	mem->mostrar_memoria();
	 cout<<p->toStr()<<endl;
	 p-> derivada();
	 cout<<p->toStr()<<endl;
     c->To_Str();
     mem->mostrar_memoria();
	return 0;
}