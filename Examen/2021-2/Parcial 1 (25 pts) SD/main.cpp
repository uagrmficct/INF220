#include "Conjunto.h"
#include <iostream>
using namespace std;
int main()
{
   Conjunto* C=new Conjunto("Datos.txt");
   C->inserta(2);
   C->inserta(3);
   cout<<C->cardinal();
   C->To_Str();
   C->suprime(2);
    C->To_Str();
   cout<<C->cardinal();
}