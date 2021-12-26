#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;


int main() {
     CSMemoria* MiMem = new CSMemoria();
     Lista* list = new Lista(MiMem);
     int z=MiMem->new_espacio("Luishiño,Pericena,Choque");
     MiMem->poner_dato(z,"->Luishiño",MiMem->obtener_dato(z,"->Luishiño")+2);
     list->inserta_primero(100);
     list->inserta_ultimo(200);
     list->inserta(list->fin(),150);
     MiMem->mostrar();
     cout << list->to_str() << endl;
    return 0;
}