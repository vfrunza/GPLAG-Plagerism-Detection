/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
int main (){
    
long long niz[13];
 long long jmbg=1234567891012;
 long long pom=jmbg;
 int i(12);
 while(pom!=0){
     long long cifra=pom%10;
     pom/=10;
     niz[i]=cifra;
     i--;
 }
    
 std::cout<<niz[1];
    
    
	return 0;
}