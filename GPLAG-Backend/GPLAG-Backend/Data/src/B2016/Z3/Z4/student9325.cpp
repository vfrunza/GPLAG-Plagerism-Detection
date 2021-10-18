/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <set>

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
    
    std::list<std::string> djeca;
    for(const auto &x : vs) djeca.push_back(x);
    Timovi timovi; 
    
    auto pomocni = djeca.begin();
    for(int i = 0;  i < v.size(); i++) {
        std::set<std::string> tim;
        for(auto it = pomocni; it != djeca.end();) {
            int broj_slova = -1;
            for(auto x : *it)
                if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) broj_slova++;
            
            tim.insert(*it);
            it = djeca.erase(it);
            pomocni = it;
            
            if(it == djeca.end()) {
                it = djeca.begin();
                pomocni = it;
            }
            
            for(int j = 0; j < broj_slova; j++) {
                it++;
                pomocni = it;
                if(it == djeca.end()) {
                    it = djeca.begin();
                    pomocni = it;
                }
            }
            v[i]--;
            if(v[i] == 0) break;
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
        std::cout <<"Tim " << i+1 << ": ";
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