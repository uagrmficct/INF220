#include <iostream>
#include "Pila.h"
#include "UMemoria.h"

using namespace std;
int x;
int elem;
int main() {
	CSMemoria * m = new CSMemoria();
	ListaS* L = new ListaS(m);
	Pila* p=new Pila(L);
	x= m->new_espacio("Luishiño,Pericena,Choque");
	m->poner_dato(x,"->Luishiño",666);
	p->poner(10);
	p->poner(20);
    m->mostrar();
    cout << p->to_str() << endl;
    p->sacar(elem);
    cout<<elem<<endl;
    m->mostrar();
    cout << p->to_str() << endl;
    
    
	return 0;
}