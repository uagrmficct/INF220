// ---------------------------------------------------------------------------

#pragma hdrstop

#include "CP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

CP::CP() {
	vc = new ColaS*[MAXCP];
	vf = new int[MAXCP];
	for (int i = 1; i <= MAXCP; i++) {
		vc[i] = new ColaS();
		vf[i] = 1;
	}
	colaAct = 0;
	cant = 0;
}

CP::CP(CSMemoria* m) {
	vc = new ColaS*[MAXCP];
	vf = new int[MAXCP];
	for (int i = 1; i <= MAXCP; i++) {
		vc[i] = new ColaS(m);
		vf[i] = 1;
	}
	colaAct = 0;
	cant = 0;
}

bool CP::vacia() {
	for (int i = 1; i <= MAXCP; i++) {
		if (!vc[i]->vacia())
			return false;
	}
	return true;
}

int CP::primero() {
	if (!vacia()) {
		int ca = cant;
		int act = colaAct;
		bool saco = false;
		while (!saco) {
			if (ca == vf[act] || vc[act]->vacia()) {
				if (act == MAXCP)
					act = 0;
				else
					act++;
				ca = 0;
			}
			else
				return vc[act]->primero();
		}
	}
}

void CP::poner(int e, int prioridad) {
	vc[prioridad]->poner(e);
}

void CP::asignar_frec_prioridad(int frec, int prioridad) {
	vf[prioridad] = frec;
}

void CP::sacar(int &e) {
	if (!vacia()) {
		bool saco = false;
		while (!saco) {
			if (cant == vf[colaAct] || vc[colaAct]->vacia()) {
				if (colaAct == MAXCP)
					colaAct = 0;
				else
					colaAct++;
				cant = 0;
			}
			else {
				cant++;
				vc[colaAct]->sacar(e);
				saco = true;
			}
		}
	}
}

string CP::to_str() {
	string s = "";
	for (int i = 1; i <= MAXCP; i++)
		s += vc[i]->to_str() + "\n";
	return s;
}