//---------------------------------------------------------------------------

#pragma hdrstop

#include "PoliLP.h"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Polinomio::Polinomio(){
KLPC.crear();
}

bool Polinomio::escero(){
return (KLPC.vacia());
}

void Polinomio::poner_termino(int coef, int exp){
Nodo *existe=NULL;
int cont=0;
	if (KLPC.longitud()>0) {
	 KLPC.suprime(KLPC.primero());
	}
	Nodo *busca=KLPC.primero();
	while (cont<KLPC.longitud()){

		if (KLPC.recupera(KLPC.siguiente(busca))==exp) {
		existe=busca;
		}
		busca=KLPC.siguiente(KLPC.siguiente(busca));
		cont=cont+2;
	}


	if (existe !=NULL) {
	KLPC.modifica(existe,KLPC.recupera(existe)+coef);
		if (KLPC.recupera(existe)==0) {
			Nodo *aux=KLPC.siguiente(existe);
			KLPC.suprime(existe);
			KLPC.suprime(aux);
		}
	}
		else{
		KLPC.inserta(KLPC.primero(),exp);
		KLPC.inserta(KLPC.primero(),coef);
		}
	int resp=0;
	 cont=0;
	busca= KLPC.primero();
	while (cont<KLPC.longitud()){
		if (KLPC.recupera(KLPC.siguiente(busca))>resp) {
		resp = KLPC.recupera(KLPC.siguiente(busca));
		}
	busca=KLPC.siguiente(KLPC.siguiente(busca));
	cont=cont+2;
	}
		KLPC.inserta(KLPC.primero(),resp);
}


int Polinomio::coeficiente(int exp){
int resp=0;
int cont=0;
Nodo *busca= KLPC.primero();
	while (cont<KLPC.longitud()){
		if (KLPC.recupera(KLPC.siguiente(busca))==exp) {
		resp = KLPC.recupera(busca);
		}
	busca=KLPC.siguiente(KLPC.siguiente(busca));
	cont=cont+2;
	}
return resp;
}

int Polinomio::exponente(int term){
int resp=0;
int cont=1;
Nodo *busca= KLPC.primero();
	while (cont<=term*2){
	resp=KLPC.recupera(KLPC.siguiente(busca));
	busca=KLPC.siguiente(KLPC.siguiente(busca));
	cont=cont+2;
	}
return resp;
}



int Polinomio::grado(){
int resp=0;
int cont=0;
Nodo *busca= KLPC.primero();
	while (cont<KLPC.longitud()){
		if (KLPC.recupera(KLPC.siguiente(busca))>resp) {
		resp = KLPC.recupera(KLPC.siguiente(busca));
		}
	busca=KLPC.siguiente(KLPC.siguiente(busca));
	cont=cont+2;
	}
return resp;
}

//int Polinomio::numero_terminos(){
//return KLPC.longitud()/2;
//}


void Polinomio::derivar(){
int cont=1;
Nodo *busca= KLPC.siguiente(KLPC.primero());
	while (cont<KLPC.longitud()){
	KLPC.modifica(busca,KLPC.recupera(busca)*KLPC.recupera(KLPC.siguiente(busca)));
	KLPC.modifica(KLPC.siguiente(busca),KLPC.recupera(KLPC.siguiente(busca))-1);
		if (KLPC.recupera(busca)==0) {
			Nodo *existe=busca;
			Nodo *aux=KLPC.siguiente(existe);
			KLPC.suprime(existe);
			KLPC.suprime(aux);
		}

	busca=KLPC.siguiente(KLPC.siguiente(busca));
	cont=cont+2;
	}

    int resp=0;
	 cont=1;
	busca= KLPC.siguiente(KLPC.primero());
	while (cont<KLPC.longitud()){
		if (KLPC.recupera(KLPC.siguiente(busca))>resp) {
		resp = KLPC.recupera(KLPC.siguiente(busca));
		}
	busca=KLPC.siguiente(KLPC.siguiente(busca));
	cont=cont+2;
	}
	KLPC.modifica(KLPC.primero(), resp);
}

int Polinomio::evaluar(int x){
int resp=0;
int cont=0;
Nodo *busca= KLPC.primero();
	while (cont<KLPC.longitud()){
	int mult=1;
	int pot= KLPC.recupera(KLPC.siguiente(busca));
		while (pot>0){
		pot--;
		mult=mult*x;
		}
		resp=resp+(KLPC.recupera(busca)*mult);
	busca=KLPC.siguiente(KLPC.siguiente(busca));
	cont=cont+2;
	}
return resp;
}

void Polinomio::mostrar(){
int coef;
int exp;
//
Nodo *busca= KLPC.primero();
Nodo *x;
	if (KLPC.vacia()) {
	    cout << CYN "KLPC" << endl;
	cout<<"<>"<<endl;
	}
		else{
		cout<<"KLPC";
		cout<<'<'<<KLPC.recupera(busca);
		x = KLPC.siguiente(busca);
			while (x!=NULL){
            cout<<',';
			cout<<KLPC.recupera(x);
			x=KLPC.siguiente(x);
			}
		cout<<'>'<<endl;
		}

//
int cont=1;
busca= KLPC.siguiente(KLPC.primero());
	while (cont<KLPC.longitud()){
	exp= KLPC.recupera(KLPC.siguiente(busca));
	coef= KLPC.recupera(busca);
	busca=KLPC.siguiente(KLPC.siguiente(busca));
	cont=cont+2;

	cout<<coef<<"X^"<<exp;
		if (cont<KLPC.longitud()) {
		cout<<"+";
		}
	}
cout<<endl;
}

//void Polinomio::mostrar_lista(){
//cout<<"NT: "<<KJSVS.longitud()/2<<endl;;
//KJSVS.mostrarlista();
//}
//

