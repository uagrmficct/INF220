//---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
CSMemoria::CSMemoria(){
	for (int i = 0; i < MAX; i++) {
		MEM[i].link=i+1;
		MEM[i].dato=0;
		MEM[i].campo="";
	}
	MEM[MAX].link=-1;
	MEM[MAX].dato=0;
	MEM[MAX].campo="";

	libre=0;
}

void CSMemoria::crear(){
    	for (int i = 0; i < MAX; i++) {
		MEM[i].link=i+1;
		MEM[i].dato=0;
		MEM[i].campo="";
	}
	MEM[MAX].link=-1;
	MEM[MAX].dato=0;
	MEM[MAX].campo="";

	libre=0;
}

int CSMemoria::new_espacio(string pal){
	int dir= libre;
	int d= libre;
	string newpal;
	char x;
	int cant= contarpal(pal);
 if (espacio_disponible()>cant) {

	for (int i = 1; i< (cant); i++) {
		while (pal[0]!=','){
		x=tolower(pal[0]);
		newpal= newpal + x;
		pal.erase(0,1);
		}
	MEM[d].campo= newpal;
	pal.erase(0,1);
	newpal.clear();
	d= MEM[d].link;
	}
	libre= MEM[d].link;
	MEM[d].link=-1;
	MEM[d].campo=pal;
 }
 else{
  cout<<"Overflow uwu"<<endl;
 }
    return dir;
}

void CSMemoria::delete_espacio (int dir){
	int x= dir;
	while (MEM[x].link!=-1){
		x=MEM[x].link;
	}
	MEM[x].link= libre;
    libre=dir;
}

int  CSMemoria::espacio_disponible(){
	int x= libre;
	int c=0;
	while (x!=-1){
		c++;
		x=MEM[x].link;
	}
return c;
}

int CSMemoria::espacio_ocupado(){
	int c= (MAX+1)- espacio_disponible();
	return c;
}

bool CSMemoria::DireccionLibre(int dir){
	int x=libre;
	bool c= false;
	while ((x!=-1)&&( c==false)){
		if (x=dir)
			c=true;
		x=MEM[x].link;
	}
	return c;
}

void CSMemoria::poner_dato(int dir, string lugar, int valor){
	int z= dir;
		if (lugar[0]=='-' && lugar[1]=='>') { // solo admite con "->"
		lugar.erase(0,2);  // borrar "->"

		for (int j = 0; j < lugar.length(); j++) {
		lugar[j]= tolower(lugar[j]);
		}

		while (MEM[z].campo != lugar){
			z=MEM[z].link;
		}
		MEM[z].dato=valor;
	   }
	   else
	   cout<<"Coloque un dato valido"<<endl;

}

int CSMemoria::obtener_dato(int dir, string lugar){

	int z= dir;
	int res;
	if (lugar[0]=='-' && lugar[1]=='>') {
	lugar.erase(0,2);
		while (MEM[z].link!=-1) {
						if(MEM[z].campo == lugar){
				res=MEM[z].dato;
				}
				z=MEM[z].link;
				if(MEM[z].campo == lugar){
				res=MEM[z].dato;
				}
		}
	}

return res;
}

void CSMemoria::mostrar(){
cout<<endl<<  "libre "<<libre<<endl;
					cout<<"+------------------+"<<endl;
					cout<<" |DIR   DATO   LINK  ID|"<<endl;

						for (int i = 0; i < MAX+1; i++) {
						if (i<10){

						cout<<"  |"<<i<<" |   |"<<MEM[i].dato<<"|   |"<< MEM[i].link<<"|    |"<<MEM[i].campo<<"|" <<endl;
						}else{

						cout<<"  |"<<i<<"|   |"<<MEM[i].dato<<"|   |"<< MEM[i].link<<"|    |"<<MEM[i].campo<<"|" <<endl;
						}}

}


//contar palabras
int CSMemoria::contarpal(string pal){
string palabra= pal+",";
int cont=0;
while (palabra!=""){
	wchar_t x= palabra[0];
	wchar_t y= palabra[1];
	palabra.erase(0,1);
		if (x!=',' && y==',') {
		cont++;
		}
}
return cont;
}