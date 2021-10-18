#include <iostream>
using namespace std;
int main() {
   int i=0,brojac=0,djeljivoSa3i4=0,zadovoljavaUslov1=0,zadovoljavaUslov2=0,proizvod=1;
   cout <<"Unesite brojeve"<< endl;
   
   while(i<100){
       cin>>i;
       if(i%3==0 && i%4==0)djeljivoSa3i4++;
       if(i<10)zadovoljavaUslov1++;
       if(i>10)zadovoljavaUslov2++;
       if(i%2!=0)proizvod*=i;
   }
  
  //cout<<"Ukupno brojeva djeljivih sa pet je: "<<djeljivoSaPet<<endl;
   cout<<"Ukupno brojeva koji su manji od 10 ima: "<<zadovoljavaUslov1<<endl;
    cout<<"Ukupno brojeva koji su veci od 10 ima: "<<zadovoljavaUslov2<<endl;
    cout<<"Proizvod neparnih brojeva: "<<proizvod<<endl;
    return 0;
}