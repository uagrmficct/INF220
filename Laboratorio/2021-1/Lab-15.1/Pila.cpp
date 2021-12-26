//---------------------------------------------------------------------------

#pragma hdrstop

#include "Pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Pila::Pila(){
    L = new ListaS();
}
Pila::Pila(ListaS* J){
    L =J;
}
bool Pila::vacia(){
    return L->vacia();
}

void Pila::poner(int e){
    L->inserta(L->primero(), e);
}

void Pila::sacar(int& e){
    if(!vacia()){
        e = L->recupera(L->primero());
        L->suprime(L->primero());
    }
}

int Pila::cima(){
    if(!vacia()){
        return L->recupera(L->primero());
    }
}

string Pila::to_str(){
    string r = "";
    Pila* aux = new Pila();
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