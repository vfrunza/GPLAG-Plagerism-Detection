/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <set>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <cctype>

bool DaLiJeIspravan(char c){
  
    if ((c>='A' && c<='z') || (c>='0' && c<='9') ) return true;
    else return false;
 
}

std::string malaslova(std::string rijec){
    std::string rez(rijec);
    for(int i=0; i<rijec.length();i++){
        rez[i]=std::tolower(rijec[i]);
    }
    return rez;
}


void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<<": ";
            for(auto it2=it->second.begin(); it2!=it->second.end(); it2++){
            if(it2==it->second.begin())
                std::cout<<*it2;
            else
                std::cout<<","<<*it2;
    }
    std::cout<<std::endl;
}
}


std::map<std::string,std::set<int>>  KreirajIndeksPojmova(std::string text){
    std::map<std::string,std::set<int>> Mapa;
    std::vector<std::string> rijeci;
    std::vector<int> v;

 
    for(int i=0; i<text.length();i++) 
    {
       std::string rijec1;
        int pozicija=i;
        while(DaLiJeIspravan(text[i])){
            rijec1+=text[i];
            i++;
        }
        if (rijec1!="")  Mapa[malaslova(rijec1)].insert(pozicija);
        
    }
    
    return Mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> Mapica){

   
    auto k(malaslova(rijec));
    auto it(Mapica.find(k));
    if (it == Mapica.end() )
        throw std::logic_error("Pojam nije nadjen");
    return Mapica[k];

}

int main ()
{
    std::string textic,rijec;
    std::vector<int> v;
    std::vector<std::string> s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,textic);
    
  auto d=KreirajIndeksPojmova(textic);
    IspisiIndeksPojmova(d);
    
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") break;
    
        try {
            auto pre=PretraziIndeksPojmova(rijec,d);
            for(int x : pre) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error e)  {
            std::cout << "Unesena rijec nije nadjena!"<<std::endl;
        }
        
    }
	return 0;
}