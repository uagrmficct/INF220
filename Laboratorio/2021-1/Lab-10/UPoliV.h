#ifndef UPoliVH
#define UPoliVH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int maxV = 10;

class UPoliV {
private:
 int *vc; // int vc[max];
 int *ve; // int ve[max];
 int nt; // numero de terminos
 //metodos privados
    int existe_exponente(int Exp);
public:
 UPoliV();
 bool es_cero();
 int grado();
 void asignarCoeficiente(int Exp, int coef);
 void poner_termino(int coef, int Exp);
 int coeficiente(int Exp);
 int exponente(int nro);
 //string ordenado();
 
 int numero_terminos();
 UPoliV *suma(UPoliV *otro);
 UPoliV *resta(UPoliV *otro);
 UPoliV *multiplica(UPoliV *otro);
 
 string toStr();
};

#endif