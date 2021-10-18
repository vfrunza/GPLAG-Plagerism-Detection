#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>

void PrebaciUMala(std::string &recenica){
    
    for(int i(0); i < recenica.length(); i++){
        if(recenica.at(i) >= 'A' && recenica.at(i) <= 'Z') recenica.at(i) += 32;
    }
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> Mapa){
    std::set<int> Novi;
    
    PrebaciUMala(rijec);
    auto i = Mapa.find(rijec);
    if(i == Mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else
    Novi = i->second;
    
    return Novi;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string recenica){
    std::map<std::string, std::set<int>> IndeksPojmova;
    
    PrebaciUMala(recenica);
    std::string prazan = {};
    for(int i(0); i < recenica.length(); i++){
        std::string rijec;
        if((recenica.at(i) >= 'a' && recenica.at(i) <= 'z') || (recenica.at(i) >= '0' && recenica.at(i) <= '9')){
            
            while((recenica.at(i) >= 'a' && recenica.at(i) <= 'z') || (recenica.at(i) >= '0' && recenica.at(i) <= '9')){
                rijec = rijec + recenica.at(i);
                i++;
                if(i == recenica.length()) break;
            }
        }
        if(rijec != prazan)
        IndeksPojmova[rijec] = {};
    }
    
    for(auto i(IndeksPojmova.begin()); i != IndeksPojmova.end(); i++){
        
        for(int j(0); j < recenica.length(); j++){
            std::string rijec;
            if((recenica.at(j) >= 'a' && recenica.at(j) <= 'z') || (recenica.at(j) >= '0' && recenica.at(j) <= '9')){
                int indeks = j;
                while((recenica.at(j) >= 'a' && recenica.at(j) <= 'z') || (recenica.at(j) >= '0' && recenica.at(j) <= '9' )){
                    rijec  = rijec + recenica.at(j);
                    j++;
                    if(j == recenica.length())break;
                }
                if(rijec == i->first) IndeksPojmova[rijec].insert(indeks);
            }
        }
        
        
    }
    return IndeksPojmova;
}

int Br_el(std::set<int> Set){
    
    int br_el{};
    for(auto i(Set.begin()); i != Set.end(); i++) br_el++;
    
    return br_el;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> IndeksPojmova){
    
    for(auto i(IndeksPojmova.begin()); i != IndeksPojmova.end(); i++){
        std::cout << i->first<< ": ";
        
        auto k = i->second.begin();
        if(Br_el(i->second) > 1) k = --(i->second.end());
        for(auto j(i->second.begin()); j != i->second.end(); j++){
            if(j == k) std::cout << *j;
            else std::cout << *j << ",";
        }
        std::cout << std::endl;
    }
}


int main ()
{
        
        std::cout << "Unesite tekst: ";
        std::string tekst;
        std::getline(std::cin, tekst);
    
        auto Mapa = KreirajIndeksPojmova(tekst);
        IspisiIndeksPojmova(Mapa);
        
        for(;;){
            
            std::cout << "Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin, rijec);
            if(rijec == ".") break;
            
            try{
            auto Skup = PretraziIndeksPojmova(rijec, Mapa);
            
            for(auto i(Skup.begin()); i != Skup.end(); i++)
            std::cout <<*i << " ";
            std::cout << std::endl;
        }catch(std::logic_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
        }
        }
	return 0;
}