#pragma hdrstop
#pragma argsused
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
void test();
int _tmain(int argc, _TCHAR* argv[])
{
 test();
 system("pause");
}
void test(){
    int sum=0;
 ifstream file;
 string x = "datos.txt";
 file.open(x.c_str(), ios::in);
 while (file.eof()==false){ 
  string c="";
  string line;
  getline(file,line);
  c=c+line;
  int n=c.length();
  for(int i=0;i<n;i++){
      if (isdigit(c[i])){
          sum=sum+(c[i]-48);
      }
  }
 }
 cout<<sum<<endl;
}