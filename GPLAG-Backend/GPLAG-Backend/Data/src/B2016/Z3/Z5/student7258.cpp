/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>


struct Dijete {
    std::string ime;
    Dijete* sljedeci;
};


int BrojSlova(std::string ime) {
    int br(0);
    for(int i=0;i<ime.length();i++) {
        if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='0' && ime[i]<='9')) br++;
    }
    return br;
}

std::vector<int> BrojUTimu(int broj_imena, int broj_timova) {
    int mod(broj_imena%broj_timova);
    std::vector<int> br_clanova;
    for(int i=0;i<mod;i++) {
        br_clanova.push_back(int(broj_imena/broj_timova)+1);
    }
    for(int i=mod;i<broj_timova;i++) {
        br_clanova.push_back(int(broj_imena/broj_timova));
    }
    return br_clanova;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int broj_timova) {
    if(broj_timova<1 || broj_timova>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr),*prethodni;
    std::vector<std::set<std::string>> povratni;
    for(int i=0;i<imena.size();i++) {
        Dijete *novi(new Dijete);
        novi->ime=imena[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    std::vector<int> v(BrojUTimu(imena.size(),broj_timova));
    int brojac(0),i(0);
    while(brojac!=imena.size()) {
        std::set<std::string> tim;
        for(int j=0;j<v[i];j++) {
            brojac++;
            if(brojac==imena.size()) {
                tim.insert(pocetak->ime);
                prethodni=nullptr;
                delete pocetak;
            }
            else {
                auto *p(pocetak);
                tim.insert(p->ime);
                int br(BrojSlova(p->ime));
                pocetak=pocetak->sljedeci;
                delete p;
                prethodni->sljedeci=pocetak;
                for(int k=0;k<br-1;k++) {
                    pocetak=pocetak->sljedeci;
                    prethodni=prethodni->sljedeci;
                }
                
            }
        }
        i++;
        povratni.push_back(tim);
    }
    return povratni;
}

int main ()
{
    std::vector<std::string> imena;
    int broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.ignore(1000,'\n');
    std::string ime;
    std::cout << "Unesite imena djece: " << std::endl;
    int i(0);
    do {
        std::getline(std::cin,ime);
        imena.push_back(ime);
        i++;
    } while(i<broj_djece);
    int broj_timova;
    std::cout << "Unesite broj timova: ";
    std::cin >> broj_timova;
    try {
        std::vector<std::set<std::string>> v(Razvrstavanje(imena,broj_timova));
        for(int i=0;i<v.size();i++) {
            std::set<std::string> skup(v[i]);
            std::cout << "Tim " << i+1 << ": ";
            std::vector<std::string> pomocni;
            for(auto x : skup) { 
                pomocni.push_back(x);
            }
            int j;
            for(j=0;j<pomocni.size()-1;j++) {
                std::cout << pomocni[j] << ", ";
            }
            std::cout << pomocni[j] << std::endl;
        }
    }
    catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    
	return 0;
}