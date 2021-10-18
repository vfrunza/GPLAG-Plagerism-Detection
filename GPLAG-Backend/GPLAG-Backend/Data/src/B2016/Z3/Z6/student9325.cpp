/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <set>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::shared_ptr<Dijete> NapraviCvorove(std::vector<std::string> vs) {
    std::shared_ptr<Dijete> pocetak = nullptr, novi = nullptr, temp = nullptr;
    for(int i = 0; i < vs.size(); i++) {
        novi = std::make_shared<Dijete>();
        novi->ime = vs[i];
        
        if(pocetak == nullptr) pocetak = novi;
        else temp->sljedeci = novi;
        
        temp = novi;
        novi->sljedeci = nullptr;
    }
    return pocetak;
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
    std::shared_ptr<Dijete> prvi = pocetak;
    
    for(int i = 0; i < v.size(); i++) {
        std::set<std::string> tim;
        while(v[i] != 0) {
            tim.insert(pocetak->ime);
            int broj_slova = -1;
            for(auto x : pocetak->ime)
                if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
                    broj_slova++;
// ->
            std::shared_ptr<Dijete> pomocni5 = pocetak->sljedeci;
            
            if(prvi == pocetak) {
                prvi = pocetak->sljedeci;
            }
            else {
                std::shared_ptr<Dijete> pomoc = prvi;
                while(pomoc->sljedeci != pocetak) {
                    pomoc = pomoc->sljedeci;
                }
                pomoc->sljedeci = pomocni5;
            }
            pocetak = nullptr;
            pocetak = pomocni5;
// ->
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
    std::cin.ignore(10000, '\n');
    
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