/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool slovoilibroj (char a) {
    
    if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
    return true;
    return false;
    
}

std::map <std::string,std::vector<int>> KreirajIndeksPojmova (std::string tekst) {
    
    std::vector<std::vector<string>> matrica;
    std::map<std::string,std::vector<int>> mapa;
   int a=0,b=0;
    
    while(a<tekst.size()) {
        
        while (!slovoilibroj ( tekst[a] ))
        a++;
        b=a;
        
        while(slovoilibroj(tekst[b]))
        b++;
        
        
        matrica.push_back(tekst.substring(a,b));
        a=b;
    }
    
    a=0,b=0,int i=0;
    
         while(a<tekst.size()) {
        
        std::string pomocni;
        std::vector<int>vektor;
        
        while (!slovoilibroj ( tekst[a] ))
        a++;
        b=a;
        
        while(slovoilibroj(tekst[b]))
        b++;
        
        if (matrica[i]==tekst.substr(a,b)) {
            
            vektor.push_back(a);
            
        }
        
        a=b;
        i++;
    }
        
        
        
        
        
        
    
    
    
    return mapa;
    
}









int main ()
{
	return 0;
}