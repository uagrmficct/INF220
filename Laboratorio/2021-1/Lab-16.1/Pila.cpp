// ---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#pragma hdrstop

#include "pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

pila::pila(){
    vJCAP = new int[MAX_VP];
    tope = 0;
}

bool pila::vacia(){
    return tope == 0;
}

void pila::poner(int e){
    if(tope < MAX_VP){
        vJCAP[tope] = e;
        tope++;
    }
}

void pila::sacar(int& e){
    if(!vacia()){
        e = vJCAP[tope - 1];
        tope--;
    }
}

int pila::cima(){
    if(!vacia()){
        return vJCAP[tope - 1];
    }
}

string pila::to_str(){
    string r = "";
    pila* aux = new pila();
    while(!vacia()){
        int e;
        sacar(e);
        r += "| "+to_string(e)+" |\n";
        aux->poner(e);
    }
    while(!aux->vacia()){
        int e;
        aux->sacar(e);
        poner(e);
    }
    r += "+---+\n";
    return r;
}