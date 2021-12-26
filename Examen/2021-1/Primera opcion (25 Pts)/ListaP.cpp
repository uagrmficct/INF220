//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaP.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

#include <iostream>
using namespace std;

CSLista::CSLista(){
crear();
}

void CSLista::crear(){
longitude=0;
PTRelementos= NULL;
}

bool CSLista::vacia(){
return (PTRelementos==NULL);
}

direccion CSLista::fin(){
Nodo *x;
Nodo *ptrfin;
if (vacia()){}
   //	cout<<"Lista vacia"<<endl;
		else{
			x=PTRelementos;
			while (x!=NULL){
			ptrfin=x;
			x=x->siguiente;
			}
		return ptrfin;
		}
return ptrfin;
}

direccion CSLista::primero(){
if (!vacia())
	return PTRelementos;
		else{
	  //	cout<<"Lista vacia"<<endl;
			 return 0;
		}

}

direccion CSLista::siguiente(direccion p){
if (vacia()){}
   //	cout<<"Lista vacia"<<endl;
		else if(p==fin()){
	 //		cout<<"Direccion Error"<<endl;
		}
			else{
				return p->siguiente;
			}
return 0;
}

direccion CSLista::anterior(direccion p){
Nodo *x= new Nodo;
Nodo *ant=new Nodo;
ant=NULL;
x=PTRelementos;
/*if (vacia()){}
	cout<<"Lista vacia"<<endl;
		else if (p==primero()) {
		 cout<<"Error primera direccio"<<endl;
			 }
				else{ */

					while (x!=NULL){
						if (x==p) {
						return ant;
						}
                        ant=x;
						x=x->siguiente;

					}

return ant;
}

int CSLista::recupera(direccion p){
return p->elemento;
}

int CSLista::longitud(){

return longitude;
}

void CSLista::inserta(direccion p, int dato){
Nodo *x= new Nodo;
Nodo *ant;
	if (x!=NULL) {
	x->elemento=dato;
	x->siguiente= NULL;
		if (vacia()) {
			PTRelementos =x;
			longitude=1;
		}
			else{
				longitude++;
					if (p==primero()) {
						x->siguiente=p;
						PTRelementos=x;
					}
						else{
						ant=anterior(p);
						ant->siguiente=x;
						x->siguiente=p;
						}
			}
	}
}

//void CSLista::mostrarlista(){
//Nodo *x= new Nodo;
//x=PTRelementos;
//	if (longitude==0) {
//	cout<<"<>"<<endl;
//	}
//		else{
//		cout<<'<'<<x->elemento;
//		x=siguiente(x);
//			while (x!=NULL){
//            cout<<',';
//			cout<<x->elemento;
//			x=siguiente(x);;
//
//			}
//		cout<<'>'<<endl;
//		}
//
//}


void CSLista::suprime(direccion p){
Nodo *x= new Nodo;
Nodo *ant;
if (longitude==0)
cout<<"Lista vacia"<<endl;
	else if (p==PTRelementos) {
	x=PTRelementos;
	PTRelementos=PTRelementos->siguiente;
    delete x;
	}
		else if(p==fin()){
		ant=anterior(p);
		ant->siguiente=NULL;
		delete x;
		}
			else{
			ant=anterior(p);
			ant->siguiente=siguiente(p);
			delete x;
			}
longitude--;
}

void CSLista::eliminaDato(int p){
Nodo *x= new Nodo;
x=PTRelementos;
	while(x->elemento!=p){
	x=x->siguiente;
	}
suprime(x);
}

direccion CSLista::localiza(int dato){
Nodo *resp=PTRelementos;
	while (resp->elemento!= dato){
	resp=resp->siguiente;
	}
return resp;
}

void CSLista::modifica(direccion dir ,int dato){
dir->elemento=dato;
}







