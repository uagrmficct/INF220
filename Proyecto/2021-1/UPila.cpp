//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include <string>
#include "UPilaV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ClasePila::ClasePila(){
    elementos = new int[MAX_VP];
    tope = 0;
}

bool ClasePila::vacia(){
    return tope == 0;
}

void ClasePila::meter(int e){
    if(tope < MAX_VP){
        elementos[tope] = e;
        tope++;
    }
}

void ClasePila::sacar(int& e){
    if(!vacia()){
        e = elementos[tope - 1];
        tope--;
    }
}

int ClasePila::cima(){
    if(!vacia()){
        return elementos[tope - 1];
    }
}

string ClasePila::mostrar(){
    string r = "Pila:\n";
    ClasePila* aux = new ClasePila();
    while(!vacia()){
        int e;
        sacar(e);
        r += "| "+to_string(e)+" |\n";
        aux->meter(e);
    }
    while(!aux->vacia()){
        int e;
        aux->sacar(e);
        meter(e);
    }
    r += "+---+\n";
    return r;
}