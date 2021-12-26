
#ifndef ConjuntoH
#define ConjuntoH
#include <iostream>
#include <string>
#include <fstream>
#include <string>

using namespace std;

class Conjunto
{
	  private:
            string Datos;
	  public:
      Conjunto(string dato);
	  bool vacio ();
	  bool pertenece(int e);
	  void inserta(int e);
	  int cardinal();
	  int ordinal(int e);
	  void suprime(int e);
	  int muestrea();
	  void To_Str();
};
#endif