#include <iostream>
#include <string>
#include "UMemoria.h"
using namespace std;

int main() {
    int x,y,z;
     CSMemoria MiMen; 
     MiMen.CSMemoria();
     x=MiMen.new_espacio("uno");
     MiMen.poner_dato(x,"->uno",100);
     y=MiMen.new_espacio("dos");
     MiMen.delete_espacio(x);
     z=MiMen.new_espacio("Luishiño,Pericena,Choque");
     MiMen.poner_dato(x,"->Luishiño",MiMen.obtener_dato(z,"->Luishiño")+5);
      MiMen.mostrar();
    
 return 0;
}