/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::set<std::tuple<std::string, int, int>> Set;
typedef std::map<std::string, Set> Mapa;

bool Slovo(char c){
    return (c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9');
}

std::string Mala(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

std::string VratiRijec(std::string s, int &i){
    std::string vrati{};
    while(i < s.size() && Slovo(s.at(i))){
        vrati += s.at(i);
        i++;
    }
    return vrati;
}

Mapa KreirajIndeksPojmova(Knjiga k){
    Mapa mapa;
    for(auto poglavlje(k.begin()); poglavlje != k.end(); poglavlje++){
        std::string ime_poglavlja(poglavlje->first);
        
        for(int stranica = 1; stranica <= (poglavlje->second).size(); stranica++){
            std::string tekst((poglavlje->second).at(stranica - 1));
            int pomak = 0; //Koristi se kao ofset u funkciji find, kako ne bi istu riječ ponovno nalazili
            for(int i = 0; i < tekst.size(); i++){
           
                if(Slovo(tekst.at(i))){
                    auto rijec(VratiRijec(tekst, i));
                    int pozicija = tekst.find(rijec, pomak);
                    //std::cout << rijec << pozicija << std::endl;
                    auto nt = make_tuple(ime_poglavlja, stranica, pozicija); //Uređeni par;
                    //Provjerava da li već postoji riječ u mapi;
                    //Ako postoji informacije se nanodaju u set, ako ne postoji onda se stvara
                    auto it(mapa.find(Mala(rijec)));
                    
                    if(it == mapa.end()){
                        Set set {nt}; //Pravi početni set uređenih parova
                        mapa.insert({Mala(rijec), set});
                    }else{
                        (it->second).insert(nt); //Dodaje u već postojeći set
                        //std::cout << rijec << ime_poglavlja << stranica << pozicija<< std::endl;
                    }
                    //std::cout << rijec << " " <<  pozicija << " " << pomak << std::endl;
                    pomak = pozicija + 1;
                }
                
            }
            
        }
    }
    return mapa;
}

Set PretraziIndeksPojmova(std::string s, Knjiga k){
    auto mapa(KreirajIndeksPojmova(k));
    auto it(mapa.find(Mala(s)));
    if(it != mapa.end()) return it->second;
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(Mapa k){
    auto kraj(k.end());
    for(auto it(k.begin()); it != k.end(); it++){
        std::cout << it->first << ": ";
        int brojac = 0;
        for(auto tapl : it->second){
            brojac++;
            std::cout << std::get<0>(tapl) << "/" << std::get<1>(tapl) << "/" << std::get<2>(tapl);
            if(brojac < (it->second).size()) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}


int main (){
    Knjiga k;
    std::string unos;
    do{
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, unos);
        if(unos == ".") break;
        std::string tekst;
        int stranica = 1;
        std::vector<std::string> v;
        do{
            std::cout << "Unesite sadrzaj stranice " << stranica << ": ";
            std::getline(std::cin, tekst);
            if(tekst == ".") break;
            v.push_back(tekst);
            stranica++;
        }while(tekst != ".");
        
        k.insert({unos, v});
    }while(unos != ".");
    std::cout << std::endl;
    
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(KreirajIndeksPojmova(k));
    std::cout << std::endl;
    
    std::string rijec;
    do{
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec == ".") break;
        try{
            auto set(PretraziIndeksPojmova(rijec, k));
            int brojac = 0;
            for(auto tapl : set){
                std::cout << std::get<0>(tapl) << "/" << std::get<1>(tapl) << "/" << std::get<2>(tapl);
                if(brojac < set.size()) std::cout << " ";
                brojac++;
            }
            std::cout << std::endl;
            
        }catch(...){
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
        
    }while(rijec != ".");
    
	return 0;
}
