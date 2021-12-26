//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaP::ListaP(){
	ptrElementos = NULL;
    longi = 0;
}

direccion ListaP::fin(){
	if(this->vacia())
		cout<<"Lista Vacia...\n";
	else  {
		direccion ptrFin;
		direccion x = ptrElementos;
		while(x != NULL) {
			ptrFin = x;
			x = x->sig;
		}
		return ptrFin;
	}
}

direccion ListaP::primero(){
	if(!this->vacia())
		return ptrElementos;
	else
		return NULL;
}

direccion ListaP::siguiente(direccion p){
	if(this->vacia())
		cout<<"Lista Vacia...\n";
	else {
		if(p->sig == NULL)
		   //	cout<<"Direccion Incorrecta...\n";
			return NULL;
       	else
			return p->sig;
	}
}

direccion ListaP::anterior(direccion p){
	if(this->vacia())
		cout<<"Lista Vacia...\n";
	else {
		if(p == this->primero())
			cout<<"Direccion Incorrecta...\n";
		else {
			direccion x = ptrElementos;
			direccion ant = NULL;
			while(x != NULL) {
				if(x == p)
					return ant;
				ant = x;
				x = x->sig;
			}  //return NULL;
        }
	}
}

int ListaP::recupera(direccion p){
	if(this->vacia())
	   cout<<"Lista Vacia...\n" ;
	else
		return p->elemento;
}

void ListaP::inserta(direccion p,int e){
	direccion x = new NodoL;
	if(x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if(this->vacia()) {
			ptrElementos = x;
			longi = 1;
		}
		else  {
			longi++;
			if(p == primero()) {
				x->sig = p;
				ptrElementos = x;
			}
			else {
				direccion ant = anterior(p);
				ant->sig = x;
				x->sig = p;
            }
        }
	}
	else
	cout<<"Existe espacio en memoria...\n";
}

void ListaP::inserta_primero(int e){
	direccion x = new NodoL;
	if(x != NULL) {
		x->elemento = e;
		x->sig = ptrElementos;
		longi++;
		ptrElementos = x;
	}
	else
		cout<<"Existe espacio en memoria...\n";
	  // resumido a inserta(ptrElementos,e);
}

void ListaP::inserta_ultimo(int e){
	direccion x = new NodoL;
	if(x != NULL) {
		x->elemento = e;
		x->sig = NULL;
	   //	longi++;
		if(vacia())   //  (longi != 0)
			ptrElementos = x;
			//fin()->sig = x;
		else
			fin()->sig = x;   //ptrElementos = x;
		longi++;
	}
	else
		cout<<"Existe espacio en memoria...\n";
}

void ListaP::suprime(direccion p){
	if(longi == 0) {
		cout<<"Lista Vacia...\n";
		return;
	}
	else {
		if(p == ptrElementos) {
			direccion x = ptrElementos;
			ptrElementos = ptrElementos->sig;
			delete(x);
		}
		else {
			direccion ant = anterior(p);
			ant->sig = siguiente(p); //p->sig;
			delete(p);
		}
	}
	longi--;
}

void ListaP::modifica(direccion p, int e){
	if(this->vacia())
		cout<<"Lista Vacia...\n";
	else
		p->elemento = e;
}

bool ListaP::vacia(){
	return longi == 0;  // ptrElementos == NULL;
}

int ListaP::longitud(){
	return longi;
}

string ListaP::mostrar(){
	string r ="<";
	direccion x = ptrElementos;
	while(x != NULL) {
		r += to_string(x->elemento);
		if(x->sig != NULL)
			r +=",";
			x = x->sig;
	}
	r = r+">";
	return r;
}

direccion ListaP::localiza(int e){
	direccion x = ptrElementos;
	while(x != NULL) {
		if(x->elemento == e)
			return x;
		x = x->sig;
	}
	return NULL;
}

void ListaP::elimina_dato(int e){
	direccion x = ptrElementos;
	while(x != NULL) {
		if(x->elemento == e) {
			direccion sup = x;
			x = x->sig;
			suprime(sup);
		}
		else
			x = x->sig;
	}
}

void ListaP::anula(){
	longi = 0;
	ptrElementos = NULL;
	while(!vacia())
		suprime(primero());
}
