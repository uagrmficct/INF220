#include <iostream>
#include <string>
#include "Polinomio.h"

using namespace std;

int main()
{
	Polinomio* pkct = new Polinomio();
	pkct->poner_termino(4,7);
	pkct->poner_termino(5,1);
	pkct->poner_termino(11,3);
	pkct->mostrar();
	pkct->derivar();
    pkct->mostrar();
}
