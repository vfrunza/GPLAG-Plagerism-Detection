/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <cctype>
#include <stdexcept>

bool je_slovo (char x){
    return ((x>='a' && x<='z') ||(x>='A' && x<='Z') || (x>=0 && x<=9));
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string tekst){
    for(auto c: tekst) std::tolower(c);
    std::map<std::string, std::set<int>> mapa;
    
    for (int i=0; i<tekst.length(); i++){
        if (je_slovo(tekst[i])){
            int j=i;
            while (je_slovo(tekst[i]) && i!=tekst.length()){
                i++;
            }
            std::string pomocni(tekst.substr(j,i-j));
            auto it(mapa.find(pomocni));
            if (it == mapa.end()) mapa[pomocni].insert(j);
            else it->second.insert(j);
        }
    }
    
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa){
    for (auto c: rijec) std::tolower(c);
    auto it (mapa.find(rijec));
    if (it == mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa){
    for (auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<<": ";
            int n(0);
            for (auto it1=it->second.begin();it1!=it->second.end();it1++){
                n++;
                    if (n == it->second.size()) std::cout<<*it1<<std::endl;
               else  std::cout<<*it1<<",";
            }
    }
}


int main ()
{
  
        std::cout<<"Unesite tekst: ";
        std::string tekst;
        std::getline(std::cin, tekst);

        std::map<std::string, std::set<int>> mapa (KreirajIndeksPojmova(tekst));
        IspisiIndeksPojmova(mapa);
        std::cout<<"Unesite rijec: ";
        std::string rijec; 
        std::getline(std::cin, rijec);
        while (rijec!="."){
            try{
            for(auto x: PretraziIndeksPojmova(rijec,mapa)) std::cout<<x<<" ";
            std::cout<<std::endl;
            } catch (std::logic_error greska){
                std::cout<<greska.what()<<std::endl;
            }
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, rijec);
        }
 
	return 0;
}