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

int duzinaStringa(std::string dijete){
    int brojac(0);
    for(int i(0); i < dijete.length(); i++){
        if((dijete[i] >= 'A' && dijete[i] <= 'Z') || (dijete[i] >= 'a' && dijete[i] <= 'z') || (dijete[i] >= '0' && dijete[i] <= '9'))
            brojac++;
    }
    return brojac-1;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int br_timova){
    if(br_timova > djeca.size() || br_timova < 1) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(auto dijete: djeca)
        lista.push_back(dijete);
    std::vector<std::set<std::string>> grupe;
    int po_timu = djeca.size() / br_timova, prvih(0);
    if(djeca.size() % br_timova) prvih = djeca.size() % br_timova;
    grupe.resize(br_timova);
    auto it = lista.begin();
    int i(0), br_unesene_djece(0);
    while(i < br_timova){
        grupe[i].insert(*it);
        br_unesene_djece++;
        int br_pomjeranja = duzinaStringa(*it);
        if(it != lista.end()) it = lista.erase(it);
        else {
            lista.erase(it); it = lista.begin();
        }
        while(br_pomjeranja != 0 && lista.begin() != lista.end()){
            while(it != lista.end() && br_pomjeranja != 0){
                it++; br_pomjeranja--;
            }
            if(br_pomjeranja != 0 || it == lista.end())
                it = lista.begin();
            
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