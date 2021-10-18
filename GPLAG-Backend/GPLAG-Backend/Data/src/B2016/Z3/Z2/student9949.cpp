/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <utility>
#include <stdexcept>

std::string PretvaraSlova(std::string rijec){
    for(int i=0; i<rijec.length(); i++){
        if(isupper(rijec[i])){
            rijec[i]=tolower(rijec[i]);
        }
    }return rijec;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s1){
    std::map<std::string, std::set<int>> Nova_mapa;
    s1=PretvaraSlova(s1);
    for(int i=0; i<s1.length(); i++){
        std::string Novi;
        int j=i;
        while((s1[i]>='a' && s1[i]<='z') || (s1[i]>='0' && s1[i]<='9')){
            Novi.push_back(s1[i]);
            i++;
        }
    Nova_mapa[Novi].insert(j);
    }
    return Nova_mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s1, std::map<std::string, std::set<int>> Nova_mapa){
    if(!(Nova_mapa.count(s1)>0)) throw std::logic_error("Pojam nije nadjen");
    return Nova_mapa[s1];
}


void IspisiIndeksPojmova(std::map<std::string, std::set<int>> Nova_mapa){
    for(auto it=Nova_mapa.begin(); it!=Nova_mapa.end(); it++){
        std::cout << (*it).first << ": ";
        auto it2(it->second.begin());
        for(int i=0; i<it->second.size(); i++){
            if(i>0) std::cout << "," << *it2;
            else std::cout << *it2;
        it2++;
        }
        std::cout << std::endl;
    }
}

int main ()
{
  //  try{
        std::cout << "Unesite tekst: ";
        std::string Tekst;
        std::getline(std::cin, Tekst);
        std::map<std::string, std::set<int>>Mapa;
        Mapa=KreirajIndeksPojmova(Tekst);
        IspisiIndeksPojmova(Mapa);
        std::string Novi_tekst;
        for(;;){
            
            std::cout << "Unesite rijec: ";
            std::getline(std::cin, Novi_tekst);
            if(Novi_tekst==".") break;
            try{
            std::set<int> Nesto;
            Nesto=PretraziIndeksPojmova(Novi_tekst, Mapa);
            for(int x: Nesto){
                std::cout << x << " ";
            }  
            }
            catch(std::logic_error izuzetak){
                std::cout << "Unesena rijec nije nadjena!";
            }
            std::cout << std::endl;
       }
//    } catch(std::logic_error izuzetak){
  //      std::cout << "Unesena rijec nije nadjena!";
	return 0;
}