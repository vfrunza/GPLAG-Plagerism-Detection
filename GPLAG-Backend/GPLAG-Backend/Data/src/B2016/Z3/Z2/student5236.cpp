/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>

int main ()
{
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,tekst);
    
    int b(0);
    int a(0);
    std::string rijec;
   for(int i=0;i<tekst.length();i++){
       if(tekst[i]!=' '){
           b++;
       }
       else if(tekst[i]==' '){
           rijec=tekst.substr(a,b);
           b++;
           a=b+1;
       }
  
   }
   std::cout<<rijec;
	return 0;
}