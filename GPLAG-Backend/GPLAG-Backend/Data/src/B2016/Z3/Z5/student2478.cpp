#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <new>

struct Dijete {
    std::string Ime;
    Dijete *sljedeci;
};

int Prebroj(std::string s){
    int brojac(0);
    for(int i(0); i < s.length(); i++)
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            brojac++;
    return brojac;
}


Dijete *Vrti(Dijete *pocetak, Dijete *&prethodni, int duzina){
    
    for(int i(0); i < duzina; i++) pocetak = pocetak -> sljedeci;
    prethodni = pocetak;
    pocetak = pocetak-> sljedeci;
    return pocetak;
    
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Imena, int broj_timova){
    if(broj_timova < 1 || broj_timova > Imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> Timovi(broj_timova);
    
    int broj_vecih = Imena.size() % broj_timova;
    int broj = Imena.size() / broj_timova;
    
    int velicina;
    
    Dijete *pocetak = nullptr, *prethodni;
    int indeks(0);
    for(;;){
        Dijete *novi;
        try{
        novi = new Dijete;
        }catch(...){
            throw;
        }
        novi->Ime = Imena[indeks];
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni -> sljedeci = novi;
        prethodni = novi;
        indeks++;
        if(indeks == Imena.size()) break;
    }
    prethodni -> sljedeci = pocetak;
    
    Dijete *Obrisi_me = nullptr;
    for(int i(0); i < broj_timova; i++){
        if(i < broj_vecih)velicina = broj+1;
        else velicina = broj;
        
        for(int j(0); j < velicina; j++){
        
            Timovi[i].insert(pocetak->Ime);
            prethodni -> sljedeci = pocetak-> sljedeci;
            Obrisi_me = pocetak;
            
            int velicina = Prebroj(pocetak -> Ime);
            
            pocetak = Vrti(pocetak, prethodni, velicina - 1);
            
            delete Obrisi_me;
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
    }catch(std::bad_alloc){
    };
    
	return 0;
}