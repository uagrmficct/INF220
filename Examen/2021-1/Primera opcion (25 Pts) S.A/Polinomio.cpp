//---------------------------------------------------------------------------

#pragma hdrstop

#include "Polinomio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Polinomio::Polinomio(){
    K = new ListaP();
}

direccion Polinomio::buscar_exponente(int exp){
	if(exp > grado())
		return NULL;
	direccion aux = K->primero();
	int cont = grado();
	while(aux != NULL) {
		if(exp == cont)
			return aux;
		cont--;
		aux = K->siguiente(aux);
	}
	return NULL;
}

direccion Polinomio::buscar_termino_n(int i){
	if(i<0 || i>numero_terminos())
		return NULL;
	direccion aux = K->primero();
	int cont = 0;
	while(aux != NULL) {
		if(K->recupera(aux)!=0) {
			cont++;
		if(cont == i)
			return aux;
		}
		aux = K->siguiente(aux);
	}
    return NULL;
}

bool Polinomio::es_cero(){
	return K->vacia();
}

int Polinomio::grado(){
	if(!es_cero())
		return K->longitud()-1;
	else
		cout<<"El Polinomio no tiene terminos...\n";
	
}

int Polinomio::exponente(int nrot){
	direccion exp = buscar_termino_n(nrot);
	if(exp!=NULL) {
		direccion aux = K->primero();
		int cont = grado();
		while(aux!=NULL) {
			if(aux == exp)
				return cont;
			cont--;
			aux = K->siguiente(aux);
		}
	}
}

int Polinomio::coeficiente(int exp){
	direccion aux = buscar_exponente(exp);
	int coef = K->recupera(aux);
	if(coef != 0)
		return coef;
}

void Polinomio::poner_termino(int coef, int exp){
	if(coef!=0 && exp>=0) {
		if(es_cero()) {
			K->inserta_ultimo(coef);
			for(int i=0; i<exp; i++)
				K->inserta_ultimo(0);
		}
		else {
			direccion aux = buscar_exponente(exp);
			if(aux == NULL) { 
				int cant = exp - grado();
				for(int i=0; i<cant; i++) 
					K->inserta_primero(0);
				K->modifica(K->primero(),coef);
            }
			else {
				int suma = K->recupera(aux)+coef;
				K->modifica(aux,suma);
				if(exp == grado()&& suma == 0) {
					direccion pri = K->primero();
					while(pri != NULL && K->recupera(pri) == 0) {
						direccion sig = K->siguiente(pri);
						K->suprime(pri);
						pri = sig;
					}
				}
			}
		}
	}
}

int Polinomio::numero_terminos(){
	int nro = 0;
	if(!es_cero()) {
		direccion aux = K->primero();
		while(aux!=NULL) {
			if(K->recupera(aux)!=0)
				nro++;
			aux = K->siguiente(aux);
        }
    }
	return nro;
}

void Polinomio::derivar(){
	Polinomio* aux = new Polinomio();
	while(!es_cero()) {
		int exp = exponente(1);
		int coef = coeficiente(exp);
		poner_termino(-coef,exp);
		aux->poner_termino(coef*exp,exp-1);
	}
	while(!aux->es_cero()) {
		int exp = aux->exponente(1);
		int coef = aux->coeficiente(exp);
		aux->poner_termino(-coef,exp);
		poner_termino(coef,exp);
	}
}

float Polinomio::evaluar(float x) {
	float suma = 0;
	for(int i=0; i<numero_terminos(); i++) {
		int exp = exponente(i+1);
		int coef = coeficiente(exp);
	    while(exp>1) {
	        coef=coef*coef;
	        exp--;
	    }
		suma = suma+(coef*x);
	}
	return suma;
}

void Polinomio::mostrar(){
	cout<< "K: "<< K->mostrar()<<endl;
	string r = "";
	int n = numero_terminos();
	for(int i=1; i<=n; i++) {
		int exp = exponente(i);
		int coef = coeficiente(exp);
		if(coef > 0)
			r += "+";
		r += to_string(coef)+"x^"+ to_string(exp);
	}
    cout<< r <<endl;
}