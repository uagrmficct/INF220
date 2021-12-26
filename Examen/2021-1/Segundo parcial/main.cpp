#include <iostream>
#include "UCola.h"

using namespace std;

int main() {
	ColaGAV* coGAV = new ColaGAV();
	coGAV->poner(100);
	coGAV->poner(200);
	coGAV->poner(300);
	int e;
	coGAV->sacar(e);
	cout << e << endl;
	return 0;
}