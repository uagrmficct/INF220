#include "UPoliV.h"
UPoliV::UPoliV() {
 vc = new int[maxV];
 ve = new int[maxV];
 nt = 0;
}
void eliminar_posicion(int *v,int k,int nt){
 for(int i = k;i < nt - 1;i++){
  v[i] = v[i+1];
    }
}
bool UPoliV::es_cero() {
 return nt == 0;
}
void UPoliV::asignarCoeficiente(int Exp, int coef)
{
    int lug = existe_exponente(Exp);
    if(lug!=-1)
    {
        vc[lug]=coef;
        if(vc[lug]==0)
        {
          eliminar_posicion(vc, lug, nt);
   eliminar_posicion(ve, lug, nt);
   nt--;
        }
        
    }
    else
    {
    cout<<"POLINOMIO NO TIENE ESE TERMINO CON ESE EXP.";
    }
}
void UPoliV::poner_termino(int coef, int exp) {
 int lug = existe_exponente(exp);
 if (lug != -1) {
  vc[lug] = vc[lug] + coef;
  if (vc[lug] == 0) {
   eliminar_posicion(vc, lug, nt);
   eliminar_posicion(ve, lug, nt);
   nt--;
  }
 }
 else {
  nt++;
  vc[nt - 1] = coef;
  ve[nt - 1] = exp;
 }
}

int UPoliV::coeficiente(int exp) {
 if (exp >= 0 && exp <= grado()) {
  for (int i = 0; i < nt; i++) {
   if (ve[i] == exp)
    return vc[i];
  }
 }
 cout << "ERROR NO EXISTE TERMINO CON ESE EXPONENTE\n";
}

int UPoliV::exponente(int nro) {
 if (nro < nt)
  return ve[nro];
 else
  cout << "ERROR FUERA DE RANGO\n";
}

int UPoliV::grado() {
 if (nt > 0) {
  int max = ve[0];
  for (int i = 0; i < nt; i++) {
   if (ve[i] > max)
    max = ve[i];
  }
  return max;
 }
 else
  cout << "NO EXISTEN TERMINOS\n";
}

int UPoliV::numero_terminos() {
 return nt;
}

UPoliV* UPoliV::suma(UPoliV *otro) {
 UPoliV *pr = new UPoliV();
 for (int i = 0; i < nt; i++) {
  int exp1 = this->exponente(i);
  int coef1 = this->coeficiente(exp1);
  pr->poner_termino(coef1, exp1);
 }
 for (int i = 0; i < otro->nt; i++) {
  
  int exp2 = otro->exponente(i);
  int coef2 = otro->coeficiente(exp2);
  pr->poner_termino(coef2, exp2);
 }
 return pr;
}

UPoliV* UPoliV::resta(UPoliV *otro) {
 UPoliV *pr = new UPoliV();
 for (int i = 0; i < nt; i++) {
  int exp1 = this->exponente(i);
  int coef1 = this->coeficiente(exp1);
  pr->poner_termino(coef1, exp1);
 }
 for (int i = 0; i < otro->nt; i++) {
 
  int exp2 = otro->exponente(i);
  int coef2 = -otro->coeficiente(exp2);
  pr->poner_termino(coef2, exp2);
 }
 return pr;
}
UPoliV* UPoliV::multiplica(UPoliV *otro)
{
     UPoliV *pr = new UPoliV();
     UPoliV *mul= new UPoliV();
     for(int i=0; i<nt; i++)
     {
        int exp1 = this->exponente(i);
     int coef1 = this->coeficiente(exp1);
     pr->poner_termino(coef1, exp1); 
     }
     for (int i = 0; i < otro->nt; i++) {
 
  int exp2 = otro->exponente(i);
  int coef2 = otro->coeficiente(exp2);
  pr->poner_termino(coef2, exp2);
     }
        return pr;
}
int UPoliV::existe_exponente(int exp) {
 for (int i = 0; i < nt; i++) {
  if (ve[i] == exp)
   return i;
 }
 return -1;
}

string UPoliV::toStr() {
 string ret = "";
 for (int i = 0; i < nt; i++) {
  int exp = this->exponente(i);
  int coef = this->coeficiente(exp);
  string signo;
  if (coef > 0)
   signo = "+";
  else {
   signo = "-";
   coef = coef*-1;
  }
  ret = ret + signo + to_string(coef) + "x^" + to_string(exp);
 }
 return ret;
}