
#include "UPoliV.h"
#include <iostream>
#include <string>
#pragma package(smart_init)
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
using namespace std;

bool espolinomiocompleto(UPoliV* p )
{
    bool completo=false;
    for(int i=p->grado();i>=0; i--)
    {
        for(int j=0; j<p->numero_terminos(); j++)
        {
            if(p->exponente(j)==i)
            {
                completo=true;
                j=p->numero_terminos();
                
            }
            else
            {
                completo=false;
            }
        }
        if(completo==false)
        {
            i=-1;
        }
    }
    return completo;
}
int main()
{
 UPoliV* p;
p=new UPoliV();
p->poner_termino(15,2); 
p->poner_termino(23,0);
p->poner_termino(2,1);
cout <<GRN " Polinomio:" NC + p->toStr() <<endl;
bool s=espolinomiocompleto(p);
if (s==true){
cout <<GRN "Es polinomio completo" NC<< endl;
}
else{
cout <<REDB "    No esta completo  " NC<< endl;
}
}




