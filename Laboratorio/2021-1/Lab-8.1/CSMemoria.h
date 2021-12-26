//---------------------------------------------------------------------------

#ifndef CSMemoria
#define CSMemoria
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
const int MAX= 20;
const int NULO= -1;

struct NodoM{
	int dato;
	int link;
	string campo;
};

class CSMemoria{
	private:
		NodoM MEM[MAX+1];
		int libre;
	public:
		CSMemoria();
		void crear();
		int new_espacio(string pal);
		void delete_espacio (int dir);
		int  espacio_disponible();
		int espacio_ocupado();
		bool DireccionLibre(int dir);
		void poner_dato(int dir, string lugar, int valor);
		int obtener_dato(int dir, string lugar);
		int contarpal(string pal);
		void mostrar();


};
#endif