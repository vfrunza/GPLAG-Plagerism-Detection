/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <set>

struct Dijete {
    std::string ime;
    Dijete* sljedeci;
};

Dijete* NapraviCvorove(std::vector<std::string> vs) {
    Dijete *pocetak = nullptr, *novi = nullptr, *temp = nullptr;
    for(int i = 0; i < vs.size(); i++) {
        novi = new Dijete;
        novi->ime = vs[i];
        
        if(pocetak == nullptr) pocetak = novi;
        else temp->sljedeci = novi;
        
        temp = novi;
        novi->sljedeci = nullptr;
    }
    return pocetak;
}

Dijete* Izbrisi(Dijete** prvi, Dijete** pok) {
    Dijete* pomocni = (*pok)->sljedeci;
    
    if(*prvi == *pok) {
        *prvi = (*pok)->sljedeci;
    }
    else {
        Dijete* pomoc(*prvi);
        while(pomoc->sljedeci != *pok)
            pomoc = pomoc->sljedeci;
        pomoc->sljedeci = pomocni;
    }
    
    delete *pok;
    *pok = nullptr;
    return pomocni;
}

typedef std::vector<std::set<std::string>> Timovi;

Timovi Razvrstavanje(std::vector<std::string> vs, int broj_timova) {
    if(broj_timova < 1 || broj_timova > vs.size())
        throw std::logic_error("Razvrstavanje nemoguce");
        
    std::vector<int> v;
    for(int i = 0; i < broj_timova; i++) {
        if(i < vs.size() % broj_timova) {
            v.push_back(int(vs.size() / broj_timova) + 1);
            continue;
        }
        v.push_back(int(vs.size() / broj_timova));
    }
    Timovi timovi;
    auto pocetak = NapraviCvorove(vs);
    Dijete* prvi = pocetak;
    
    for(int i = 0; i < v.size(); i++) {
        std::set<std::string> tim;
        while(v[i] != 0) {
            tim.insert(pocetak->ime);
            int broj_slova = -1;
            for(auto x : pocetak->ime)
                if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
                    broj_slova++;
            
            pocetak = Izbrisi(&prvi, &pocetak);
            
            if(pocetak == nullptr) {
                pocetak = prvi;
            }
            
            for(int j = 0; j < broj_slova; j++) {
                if(pocetak) {
                    pocetak = pocetak->sljedeci;
                }
                if(pocetak == nullptr) {
                    pocetak = prvi;
                }
            }
            v[i]--;
        }
        timovi.push_back(tim);
    }
    return timovi;
}

int main() {
    std::cout << "Unesite broj djece: ";
    int broj_djece;
    std::cin >> broj_djece;
    
    std::cout << "Unesite imena djece:\n";
    
    std::vector<std::string> vs;
    
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    
    for(int i = 0; i < broj_djece; i++) {
        std::string temp;
        std::getline(std::cin, temp);
        vs.push_back(temp);
    }
    
    std::cout << "Unesite broj timova: ";
    int broj_timova;
    std::cin >> broj_timova;
    
    Timovi vset;
    
    try {
        vset = Razvrstavanje(vs, broj_timova);
    }
    catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    
    for(int i = 0; i < vset.size(); i++) {
        auto zadnji = vset[i].end(); zadnji--;
        std::cout << "Tim " << i+1 << ": ";
        
        for(auto j = vset[i].begin(); j != vset[i].end(); j++) {
            if(j == zadnji) {
                std::cout << *j;
                break;
            }
            else std::cout << *j << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}