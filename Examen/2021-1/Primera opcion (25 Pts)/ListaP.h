//---------------------------------------------------------------------------

#ifndef ListaPH
#define ListaPH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
	int elemento;
	Nodo *siguiente;
};

typedef Nodo *direccion;

class CSLista
 {
  private:
  direccion PTRelementos;
  int longitude;


  public:
  CSLista();   
  void crear();   
  direccion fin();        
  direccion primero(); 
  direccion siguiente(direccion dir);
  direccion anterior(direccion dir);   
  bool vacia();                          
  int recupera(direccion dir);             
  int longitud();                            
  void inserta(direccion dir,int dato);        
  void suprime(direccion dir);                   
  void modifica(direccion dir ,int dato);          
  void eliminaDato(int dato);                          
  direccion localiza(int dato);                      


 };





#endif
