#include "CPLPC.h"

CPLPC::CPLPC()
{
	 mem= new  CSMemoria();
	 ini=-1;
	 fin=-1;
}
CPLPC::CPLPC(CSMemoria *m)
{
   mem=m;
   ini=-1;
   fin=-1;
}
bool CPLPC::Vacia()
{
	return ini==nulo;
}
void CPLPC::Poner(int E)
{
int aux= mem->New_Espacio("elemento,sig");
	if(aux!=nulo)
	{
	   mem->Poner_dato(aux,elementoC,E);
	   mem->Poner_dato(aux,sigC,nulo);
	   if(Vacia())
	   {
			ini=aux;
			fin=aux;
	   }
	   else
	   {
		   mem->Poner_dato(fin,sigC,aux);
		   fin=aux;
	   }
	}
}
void CPLPC::Sacar( int &E)
{
   if(!Vacia())
   {
	   E=mem->obtener_dato(ini,elementoC);
	   int x=ini;
	   ini=mem->obtener_dato(ini,sigC);
	   mem->Delete_Espacio(x);
   }

}
int CPLPC::Primero()
{
	 if(!Vacia())
	 {
		 return mem->obtener_dato(ini,elementoC);
	 }
}
string CPLPC::mostrar() {
  string s = "COLA\n+---+\n";
  int e;
  CPLPC* aux = new CPLPC();
  while (!Vacia()) {
	Sacar(e);
	aux->Poner(e);
	s += "| "+to_string(e)+" |\n";
  }
  while (!aux->Vacia()) {
	aux->Sacar(e);
	Poner(e);
  }
  return  "\n"+s+"+---+\n\n";
}