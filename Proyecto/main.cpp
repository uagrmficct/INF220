
#include <iostream>
#include "UColaV1.h"
#include "UDicolaV2.h"
#include "UPilaV.h"
#include <string>
#include <fstream>
using namespace std;

void Cargar(){
    
}
void Guardar(ClaseCola* C){
    ofstream archivo;
    string datos;
    
    archivo.open("Objetos.txt", ios::out);
    int e;
    while(!C->vacia()){
        C->sacar(e);
        datos += to_string(e);
		if (!C->vacia())
			datos += ",";    
    }
    
    archivo<<datos;
    archivo.close();
}


 int main()
{
	ClaseCola* C = new ClaseCola();
	ClasePilaeect* Peect = new ClasePilaeect();
	ClaseDicolaeect* Deect = new ClaseDicolaeect();
    Cargar();

	C->poner(100);
	Peect->meter(200);
	Deect->poner_frente(500);

	cout<<C->mostrar()<<endl;
	cout<<Peect->mostrar()<<endl;
	cout<<Deect->mostrar()<<endl;
	
	Guardar(C);

	return 0;
}