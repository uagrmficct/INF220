#include "Conjunto.h"

#include<stdlib.h>

Conjunto::Conjunto(string dato) {
	Datos = dato;
}
bool Conjunto::vacio() {
	ifstream filein(Datos);
	string strTemp;
	int cont = 0;
	while (filein >> strTemp)
	{
		return true;
	}
	return false;
	filein.close();
}
bool Conjunto::pertenece(int e) {
	ifstream infile(Datos);
	string line;
	while (getline(infile, line))
	{
		int expLine = atoi(line.c_str());
		if (expLine == e) {
			infile.close();
			return true;
		}
	}
	infile.close();
	return false;
}

void Conjunto::inserta(int e) {

	if (!pertenece(e)) {
		ofstream archivo;
		archivo.open("Datos.txt", ios::app);		
		archivo << to_string(e) << endl;
		archivo.close();
	}
}


int Conjunto::cardinal() {
	ifstream filein(Datos);
	string strTemp;
	int cont = 0;
	while (filein >> strTemp)
	{
		cont++;
	}
	filein.close();
	return cont;
}
int Conjunto::ordinal(int e) {
	if (vacio())
	{
	}
	return 0;
}


void Conjunto::suprime(int e) {
	if (pertenece(e))
	{
		ifstream filein(Datos);
		ofstream fileout("temp.txt");
		string strTemp;
		int cont = 0;
		while (filein >> strTemp)
		{
			int acoef = atoi(strTemp.c_str());
			if (acoef != e)
			{
				strTemp = to_string(acoef);
				if (strTemp != "")
					strTemp += "\n";
				fileout << strTemp;
			}

		}
		filein.close();
		fileout.close();
		filein.open("temp.txt");
		fileout.open(Datos);
		while (filein >> strTemp)
			fileout << strTemp << endl;
		filein.close();
		fileout.close();
	}

}
int Conjunto::muestrea() {
	srand(time(NULL));
	int lug = rand() % (cardinal());
	int cont = 0;
	return 0;
}

void Conjunto::To_Str() {
	ifstream filein(Datos);
	string strTemp;
	string cad="C<";
	while (filein >> strTemp)
	{
		
		cad = cad + strTemp+",";
	}
	cad = cad + ">";
	cout << cad<<endl;
	filein.close();

}









