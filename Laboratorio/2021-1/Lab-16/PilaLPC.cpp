
#pragma hdrstop

#include "PilaLPC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilaLPC::PilaLPC(){
    mem = new CSMemoria();
    tope = NULO;
}

PilaLPC::PilaLPC(CSMemoria* m){
    mem = m;
    tope = NULO;
}

bool PilaLPC::vacia(){
    return tope == NULO;
}

void PilaLPC::meter(int e){
    int aux = mem->new_espacio(datosP);
    if(aux != NULO){
        mem->poner_dato(aux, elementoP, e);
        mem->poner_dato(aux, sigP, tope);
        tope = aux;
    }else
        cout << "ERROR NO HAY MEMORIA\n" << endl;
}

void PilaLPC::sacar(int& e){
    if(!vacia()){
        int x = tope;
        e = mem->obtener_dato(tope, elementoP);
        tope = mem->obtener_dato(tope, sigP);
        mem->delete_espacio(x);
    }
}

int PilaLPC::cima(){
    if(!vacia()){
        return mem->obtener_dato(tope, elementoP);
    }
}

string PilaLPC::to_str(){
    string r = "";
    PilaLPC* aux = new PilaLPC();
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
    r += "-----\n";
    return r;
}