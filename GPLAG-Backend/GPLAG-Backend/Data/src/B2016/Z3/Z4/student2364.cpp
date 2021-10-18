#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdexcept>

int Prebroj(std::string s){
    int brojac(0);
    for(int i(0); i < s.length(); i++)
        if((s[i]>= 'A' && s[i] <='Z') || (s[i] >= 'a' && s[i] <='z') || (s[i] >= '0' && s[i] <='9'))
            brojac++;
    return brojac;
}

std::list<std::string>::iterator Vrti(std::list<std::string> &ListaImena, std::list<std::string>::iterator pocetak){
    
    int broj_slova = Prebroj(*pocetak);
    pocetak = ListaImena.erase(pocetak);
    if(pocetak == ListaImena.end()) pocetak = ListaImena.begin();
    
    for(int i(0); i < broj_slova-1; i++){
        ++pocetak;
        if(pocetak == ListaImena.end()){
            pocetak = ListaImena.begin();
        }
    }
    auto novi = pocetak;
    return novi;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Imena, int broj_timova){
    if(broj_timova < 1 || broj_timova > Imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> Timovi(broj_timova);
    
    int broj_vecih = Imena.size() % broj_timova;
    int broj = Imena.size() / broj_timova;
    
    int velicina;
    
    std::list<std::string> ListaImena;
    
    for(int i(0); i < Imena.size(); i++) ListaImena.push_back(Imena[i]);
    
    auto pocetak = ListaImena.begin();
    std::list<std::string>::iterator novi;
    for(int i(0); i < broj_timova; i++){
        if(i < broj_vecih)velicina = broj+1;
        else velicina = broj;
        
        for(int j(0); j < velicina; j++){
            
            Timovi[i].insert(*pocetak);
            novi = Vrti(ListaImena, pocetak);
            pocetak = novi;
        }
    }
    return Timovi;
}

void IspisiSet(const std::set<std::string> &Set){
    
    for(auto i(Set.begin()); i != Set.end(); i++){
        if(i == --Set.end())std::cout << *i;
        else std::cout << *i << ", ";
    }
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int br_djece;
    std::cin >> br_djece;
    std::cin.ignore(1000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    try{
    std::vector<std::string> Imena;
    std::string pomocni;
    
    for(int i(0); i < br_djece; i++){
        std::getline(std::cin, pomocni);
        Imena.push_back(pomocni);
    }
    
    
    std::cout << "Unesite broj timova: ";
    int br_timova;
    std::cin>> br_timova;
    auto VecS = Razvrstavanje(Imena, br_timova);
    for(int i(0); i < VecS.size(); i++){
        std::cout << "Tim " << i+1 << ": ";
        IspisiSet(VecS[i]);
        std::cout << std::endl;
    }
    }catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }

	return 0;
}