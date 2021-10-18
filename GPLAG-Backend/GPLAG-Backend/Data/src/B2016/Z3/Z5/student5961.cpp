#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>
#include <iomanip>
#include <functional>
#include <set>
#include <map>
#include <list>

struct Cvor {
    std::string ime;
    Cvor *sljedeci;
};

int duzinaStringa(std::string dijete){
    int brojac(0);
    for(int i(0); i < dijete.length(); i++){
        if((dijete[i] >= 'A' && dijete[i] <= 'Z') || (dijete[i] >= 'a' && dijete[i] <= 'z') || (dijete[i] >= '0' && dijete[i] <= '9'))
            brojac++;
    }
    return brojac-1;
}

void unistiCvorove(Cvor *djeca){
    Cvor* p = djeca;
    while(p != nullptr){
        Cvor* prethodni = p;
        p = p->sljedeci;
        delete prethodni;
    }
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int br_timova){
    if(br_timova > djeca.size() || br_timova < 1) throw std::logic_error("Razvrstavanje nemoguce");
    int ukupan_broj_djece = djeca.size();
    Cvor *pocetak(nullptr), *prethodni;
    for(int i(0); i < djeca.size(); i++) {
        try{
            Cvor *novi(new Cvor);
            novi->ime = djeca[i]; novi->sljedeci = nullptr;
            if(!pocetak) pocetak = novi;
            else prethodni->sljedeci = novi;
            prethodni = novi;
            if(i == djeca.size()-1)
                novi->sljedeci = pocetak;
        }
        catch(...){
            unistiCvorove(pocetak);
            throw;
        }
    }
    std::vector<std::set<std::string>> grupe;
    int po_timu = djeca.size() / br_timova, prvih(0);
    if(djeca.size() % br_timova) prvih = djeca.size() % br_timova;
    grupe.resize(br_timova);
    int i(0), br_unesene_djece(0);
    Cvor* p = pocetak;
    while(true){
        grupe[i].insert(p->ime);
        br_unesene_djece++;
        ukupan_broj_djece--;
        Cvor* tmp = p;
        p = p->sljedeci;
        prethodni->sljedeci = p;
        int br_pomjeranja = duzinaStringa(tmp->ime);
        delete tmp;
        if(!ukupan_broj_djece) break;
        for(int i(0); i < br_pomjeranja; i++){
            p = p-> sljedeci;
            prethodni = prethodni->sljedeci;
        }
        if((i < prvih && br_unesene_djece == po_timu+1) || ( i >= prvih && br_unesene_djece == po_timu)){
            br_unesene_djece = 0; i++;
        }
    }
    return grupe;
}

int main (){
    std::cout << "Unesite broj djece: ";
    int br_djece;
    std::cin >> br_djece;
    std::cout << "Unesite imena djece:" << std::endl;
    std::vector<std::string> djeca;
    std::cin.ignore(10000, '\n');
    for(int i(0); i < br_djece; i++){
        std::string dijete;
        std::getline(std::cin, dijete);
        djeca.push_back(dijete);
    }
    std::cout << "Unesite broj timova: ";
    int br_timova, i(1);
    std::cin >> br_timova;
    try{
        for(auto tim: Razvrstavanje(djeca, br_timova)){
            std::cout << "Tim " << i << ":" ;
            for(auto it = tim.begin(); it != tim.end(); it++){
                std::cout << " " << *it;
                auto p = it;
                p++;
                if(p != tim.end()) std::cout << ",";
            }
            i++;
            std::cout << std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}