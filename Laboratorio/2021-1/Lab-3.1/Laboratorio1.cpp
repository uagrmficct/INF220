#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void crear_archivo();
void pregunta1();
int cantidad_vocales(string cad);

int main(){
    
    crear_archivo();
    pregunta1();
    system("pause");
    return 0;

}
void crear_archivo(){
    ofstream archivo;
    string frase;
    archivo.open("datos.txt", ios::out);
    if(archivo.fail()){
        cout<< "No se pudo abrir el archivo";
    }
    cout<< "Digite texto para el archivo: ";
    getline(cin, frase);
    archivo<<frase;
    getline(cin, frase);
    archivo<<frase;
    
}
void pregunta1(){
    ifstream archivo;
    archivo.open("datos.txt", ios::in);
    string cadena = " ";
    while (!archivo.eof()){
        string linea;
        getline(archivo, linea);
        cadena += linea + " ";
    }
    int cant = cantidad_vocales(cadena);
    cout<< "El texto contiene " << cant << " vocales mayusculas"
    <<endl;
}
int cantidad_vocales(string cadena){
    string vocales = "AEIOU";
    int n = cadena.length();
    int cant = 0;
    for (int i=0; i<n; i++){
        if (vocales.find_first_of(cadena[i]) != -1)
           cant++;
    }
    return cant;
}