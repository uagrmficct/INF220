//---------------------------------------------------------------------------

#ifndef ColaH
#define ColaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAXVC3 = 9;

class Cola{
	private:
		int* v;
        int ini, fin;

        int siguiente(int dir);
	public:
		Cola();
		bool vacia();
		void poner(int e);
		void sacar(int &e);
		int primero();
		string to_str();
};
#endif