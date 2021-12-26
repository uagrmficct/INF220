#include "ColaPrioridadLPC.h"

ColaPrioridadLPC::ColaPrioridadLPC()
{
colaAct=0;
cant=0;
vc= new CPLPC*[MAX];
vf = new int[MAX];
for (int i = 0; i < MAX; i++) {
		vc[i] = new CPLPC();
		vf[i] = 1;
	}
}
ColaPrioridadLPC::ColaPrioridadLPC(CSMemoria *m)
{
colaAct=0;
cant=0;
vc= new CPLPC*[MAX];
vf = new int[MAX];
for (int i = 0; i < MAX; i++) {
		vc[i] = new CPLPC(m);
		vf[i] = 1;
	}
}

bool ColaPrioridadLPC::vacia()
{
	int cont;
	for (int i = 0; i < MAX; i++) {

		if (vc[i]->Vacia())
		{
			cont++;
		}
	}
	if(cont==MAX)
	{
        cout<<"LA Cola ESTA VACIA";
		return true;
	}
	else
	{
	return false;

	}
}
int ColaPrioridadLPC::primero()
{
   if (vacia())
		cout << "Cola Vacia" << endl;
	else {
		int colaInicio = colaAct;
		bool termino = false;
		while (!termino) {
			if (!vc[colaAct]->Vacia() && cant < vf[colaAct])
				return vc[colaAct]->Primero();
			colaAct = (colaAct + 1) % MAX;
			cant = 0;
			if (colaAct == colaInicio)
				termino = true;
		}
	}
}
void ColaPrioridadLPC::poner( int E, int prioridad)
{
  vc[prioridad]->Poner(E);
}
void ColaPrioridadLPC::Asignar_frecuencia_Prioridad( int frec, int prioridad)
{
	 vf[prioridad] = frec;
}
void ColaPrioridadLPC::sacar(int &E )
{
if (!vacia()) {
		if (!vc[colaAct]->Vacia()) {
			if (cant < vf[colaAct]) {
				cant++;
				vc[colaAct]->Sacar(E);
				if (cant == vf[colaAct]) {
					colaAct = (colaAct + 1) % MAX;
					cant = 0;
				}
			}
		}
		else {
			colaAct = (colaAct + 1) % MAX;
			cant = 0;
			sacar(E);
		}
	}
}