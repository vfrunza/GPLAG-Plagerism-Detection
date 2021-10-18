/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <new>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

int DuzinaStringa (std::string rijec) {
    int duzina=rijec.length();
    auto it(rijec.begin());
    while(it!=rijec.end()) {
        if(!((*it>='A' && *it<='Z') || (*it>='a' && *it<='z') || (*it>='0' && *it<='9'))) duzina--;
        it++;
    }
    return duzina;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> vektor, int br_timova) {
    if(br_timova<1 || br_timova>vektor.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> pocetni(nullptr), prethodni(nullptr);
    for(int i(0); i<vektor.size(); i++) {
        std::shared_ptr<Dijete> novi(nullptr);
        try {
            novi=std::make_shared<Dijete>();
        } catch(...) {
            throw;
        }
        novi->ime=vektor[i];
        novi->sljedeci=nullptr;
        if(!pocetni) pocetni=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetni;
    std::vector<std::set<std::string>> novi(br_timova); 
    int modul=vektor.size()%br_timova;
    int broj_cl=vektor.size()/br_timova;
    std::vector<int> pomocni;
    for(int i(0); i<br_timova; i++) {
        if(i<modul) pomocni.push_back(broj_cl+1);
        else pomocni.push_back(broj_cl);
    }
    auto it(pocetni);
    int brojac(0);
    int i(0), tim(0);
    int koliko_mjesta(0), pomjereno(0), uneseno(0);
    for(;;) {
        if(brojac==0) { novi[tim].insert(it->ime); uneseno++; brojac++; koliko_mjesta=DuzinaStringa(it->ime); if(it==it->sljedeci) {it->sljedeci=nullptr; break;} prethodni->sljedeci=it->sljedeci; it=prethodni->sljedeci; pomjereno=1;} 
        if(uneseno==pomocni[i]) {uneseno=0; i++; tim++; }
        while(pomjereno!=koliko_mjesta) {
            it=it->sljedeci;
            prethodni=prethodni->sljedeci;
            pomjereno++; 
        }
        if(pomjereno==koliko_mjesta) { novi[tim].insert(it->ime); uneseno++; koliko_mjesta=DuzinaStringa(it->ime); if(it==it->sljedeci) {it->sljedeci=nullptr; break;} prethodni->sljedeci=it->sljedeci; it=prethodni->sljedeci; pomjereno=1; }
        if(tim==br_timova-1 && uneseno==pomocni[i]) break;
    }
    return novi;
}

int main () {
    std::cout << "Unesite broj djece: ";
    int broj;
    std::cin >> broj;
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> vektor;
    for(int i(0); i<broj; i++) {
        std::string pomocni;
        std::cin >> std::ws;
        std::getline(std::cin, pomocni);
        vektor.push_back(pomocni);
    }
    std::cout << "Unesite broj timova: ";
    int br_timova;
    std::cin >> br_timova;
    try {
        auto v(Razvrstavanje(vektor, br_timova));
        for(int i(0); i<v.size(); i++) {
            std::cout << "Tim " << i+1 << ": ";
            int brojac(0);
            for(auto x: v[i]) {
                if(brojac==0) { std::cout << x; brojac++; }
                else std::cout << ", " << x;
            }
            std::cout << std::endl;
        }
    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(...) {
        std::cout << "Izuzetak: Problemi sa memorijom" << std::endl;
    }
	return 0;
}