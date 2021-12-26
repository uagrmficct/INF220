#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;
int main(){
    int i,n;
	cout<<"Ingrese el numero de elementos del arreglo :";
	cin>>n;
	 int *v=new int [n];
	for (i=0;i<n;i++){
		cout<<"ingrese el digito del vector";
		cin>>v[i];
	}
	int sum=0;
   for (i=0;i<n;i++){
		sum=sum+v[i];
   }
   double pro=0;
   pro=sum / n;
   cout<<pro;
  int men=999999;
	for (i=0;i<n;i++){
		 if (abs(pro-v[i])<men){
			 men=abs(pro-v[i]);
		 }
	}
   string  s="";
	for(i=0;i<n;i++){
		if (abs(pro-v[i])==men){
			string aux="";
			aux=aux+to_string(v[i]);
			s=s+aux+",";
		}
	}
    s.erase(s.length()-1,1);
    cout<<pro
    ;
    cout<<"     ";
    cout<<"se acerca mas :"; 
	cout<<s;
}
