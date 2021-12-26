#include <iostream>
#include "Cola.h"
#include "Pila.h"

using namespace std;
void invertir(Cola *c) {
	if (!c->vacia()) {
		int e;
		c->sacar(e);
		invertir(c);
		c->poner(e);
	}
}
int main() {
	Cola* c;
	Pila* p;
    cout << "1. Crear cola" << endl;
	cout << "2. Poner en la cola" << endl;
	cout << "3. Mostrar Cola" << endl;
	cout << "4. Crear Pila" << endl;
	cout << "5. Poner en la  Pila" << endl;
	cout << "6. mostrar  Pila" << endl;
	cout << "7. Invertir Cola" << endl;
	cout << "8. Salir" << endl;
	bool sale = false;
	while (!sale) {
		int opcion;
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			c = new Cola();
			break;
		case 2: {
				int e;
				cout << "Elemento: ";
				cin >> e;
				c->poner(e);
			} break;
		case 3: {
				cout << c->to_str() << endl;
			} break;
		case 4: {
				p = new Pila();
			} break;
		case 5: {
				int e;
				cout << "Elemento: ";
				cin >> e;
				p->poner(e);
			} break;
		case 6: {
				cout << p->to_str() << endl;
			} break;
		case 7: {
				invertir(c);
			} break;
		case 8:
			sale = true;
			break;
		}
	}
}
	