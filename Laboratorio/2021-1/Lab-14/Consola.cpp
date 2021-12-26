#include <iostream>
#include <string>
#include "SMemoria.h"
#include "UMatriz.h"
#include "UListaS.h"

using namespace std;

int main() {
	SMemoria* m = new SMemoria();
	matrizdispersa* M = new matrizdispersa();
	int x = m->new_espacio("Luishiño,Pericena,Choque");
	m->poner_dato(x,"->Pericena",666);
	M->dimensionar(30,30);
	M->mostrar();
	M->definir_valor_repetido(0);
	M->poner(3,2,300);
	m->mostrar();
	M->definir_valor_repetido(1);
	M->mostrar();
	M->poner(1,2,100);
	M->poner(2,3,200);
	m->mostrar();
	M->mostrar();
	M->poner(2,3,1);
    m->mostrar();
	system("pause");
	return 0;
}