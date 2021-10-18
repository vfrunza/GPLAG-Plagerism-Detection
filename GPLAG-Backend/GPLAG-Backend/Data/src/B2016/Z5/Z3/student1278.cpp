#include <iostream>
using namespace std;
int main() {
   int i=0,brojac=0,suma=0,arSredina;
   cout <<"Unesite cijele brojeve, "<< endl;
   
   while(i>0){
       cin>>i;
       if(i<30 && i>=5){
           suma+=i;
           brojac++;
       }
   }
   arSredina=suma/brojac;
  cout<<"Artimetička sredina sredina je: "<<arSredina;
    return 0;
}

