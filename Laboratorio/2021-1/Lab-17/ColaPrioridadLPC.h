
#ifndef ColaPrioridadLPCH
#define ColaPrioridadLPCH
#include "CPLPC.h"
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const int MAX=10;
class ColaPrioridadLPC
{
private:
 CPLPC** vc;
 int *vf;
 int colaAct;
 int cant;
 public:
 ColaPrioridadLPC();
 ColaPrioridadLPC(CSMemoria *m);
 bool vacia();
 int primero();
 void poner( int E, int prioridad);
 void Asignar_frecuencia_Prioridad( int frec, int prioridad);
 void sacar(int &E );
};
#endif