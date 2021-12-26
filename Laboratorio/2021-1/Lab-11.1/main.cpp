#include <iostream>
#include <string>
#include "PolinomioP.h"
using namespace std;

bool espolinomioord(PoliP* p){
bool ord=true;
    for(int i=1; i<p->numero_terminos();i++){
        int exp= p->exponente(i);
        if(ord==true && exp > p -> exponente(i+1))
        ord=true;
        else
        ord=false;
    }
    if (ord==false){
        ord=true;
    for(int i=1; i<p->numero_terminos();i++){
        int exp= p->exponente(i);
        if(ord==true && exp < p -> exponente(i+1))
        ord=true;
        else
        ord=false;
    }
    }
    return ord;
}

int main() {
  
     PoliP* p = new PoliP();
	p->poner_termino(15, 8);
	p->poner_termino(23, 3);
	p->poner_termino(2, 7);
  cout << p->to_str() << endl;
 if (espolinomioord(p)) {
            cout << "Es polinomio ordenado" << endl;}
        else{
            cout << "No esta ordenado el polinomio"<< endl;}
}  
 