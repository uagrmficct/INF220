#include <stdio.h>
#include <iostream>
#include "CSMemoria.h"
#include "ColaPrioridadLPC.h"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
int main()
{
 int elem;
 CSMemoria *m= new CSMemoria();
 ColaPrioridadLPC* PLPC=new ColaPrioridadLPC(m);
 PLPC->poner(10,1);
 PLPC->poner(200,2);
 PLPC->poner(1000,3);
 PLPC->poner(300,2);
 PLPC->Asignar_frecuencia_Prioridad(2,1);
 PLPC->Asignar_frecuencia_Prioridad(2,2);
 PLPC->Asignar_frecuencia_Prioridad(1,3);
 m->mostrar_memoria();
 PLPC->sacar(elem);
 cout<<"Elemento= "<<elem<<endl;
 PLPC->sacar(elem);
 cout<<"Elemento= "<<elem<<endl;
 PLPC->sacar(elem);
 cout<<"Elemento= "<<elem<<endl;
 m->mostrar_memoria();
 system("PAUSE");
 return 0;
}