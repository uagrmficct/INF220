#include <iostream>
#include "CPoliLP.h"

int main() {
    
	 PoliLP* P = new PoliLP();
	 P->poner_termino(4, 7);
     P->poner_termino(5, 1);
	 P->poner_termino(9, 3);
	 cout << P->mostrarPoli() << endl;
	 P->derivar();
	 cout << P->mostrarPoli() << endl;

	return 0;
}