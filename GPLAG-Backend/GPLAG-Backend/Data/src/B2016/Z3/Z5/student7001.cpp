/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include <string>

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};

int BrojSlovaUImenu(std::string ime) {
    int brojac(0);
    for (int i=0; i<ime.size(); i++)
        if ((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9')) brojac++;
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &imena_djece, int broj_timova) {
    if (broj_timova<1 || broj_timova>imena_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<int> duzine_timova;
    for (int i=0; i<imena_djece.size()%broj_timova; i++)
        duzine_timova.push_back(int(imena_djece.size()/broj_timova)+1);
    for (int i=0; i<broj_timova-imena_djece.size()%broj_timova; i++)
        duzine_timova.push_back(int(imena_djece.size()/broj_timova));
    std::vector<std::set<std::string>> rezultat(broj_timova);
    Dijete *pocetak(nullptr), *prethodni;
    int brojac_uspjesnih_alokacija(0);
    try {
        for (int i=0; i<imena_djece.size(); i++) {
            Dijete *novo(new Dijete);
            brojac_uspjesnih_alokacija++;
            novo->ime=imena_djece[i];
            novo->sljedeci=nullptr;
            if (!pocetak) pocetak=novo;
            else prethodni->sljedeci=novo;
            if (i==imena_djece.size()-1) {
                prethodni=novo;
                prethodni->sljedeci=pocetak;
                break;
            }
            else prethodni=novo;
        }
    }
    catch(std::bad_alloc) {
        if (brojac_uspjesnih_alokacija!=0) {
            prethodni=nullptr;
            for (int i=0; i<brojac_uspjesnih_alokacija; i++) {
                Dijete *tmp(pocetak);
                pocetak=pocetak->sljedeci;
                pocetak->sljedeci=nullptr;
                delete tmp;
            }
        }
        throw;
    }
    int broj_djece=imena_djece.size(), indeks(0);
    Dijete *it(pocetak);
    while(indeks!=broj_timova) {
        int brojac=duzine_timova[indeks];
        while(brojac!=0) {
            int trenutna_duzina=BrojSlovaUImenu(it->ime);
            rezultat[indeks].insert(it->ime);
            Dijete *tmp(it);
            it=it->sljedeci;
            pocetak=it; 
            delete tmp;
            brojac--;
            broj_djece--;
            if(broj_djece==0) break;
            for (int i=0; i<broj_djece-1; i++)
                it=it->sljedeci;
            prethodni=it;
            it=pocetak;
            prethodni->sljedeci=pocetak;
            for (int i=0; i<trenutna_duzina-1; i++)
                it=it->sljedeci;
        }
        indeks++;
    }
    return rezultat;
}

int main () {
    int broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.ignore(10000,'\n');
    std::vector<std::string> imena_djece(broj_djece);
    std::cout << "Unesite imena djece: " << std::endl;
    for (int i=0; i<broj_djece; i++)
        std::getline(std::cin, imena_djece[i]);
    int broj_timova;
    std::cout << "Unesite broj timova: ";
    std::cin >> broj_timova;
    std::vector<std::set<std::string>> skup;
    try {
        skup=Razvrstavanje(imena_djece,broj_timova);
    }
    catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    catch(std::bad_alloc) {
        return 0;
    }
    for (int i=0; i<skup.size(); i++) {
        std::cout << "Tim " << i+1 << ": ";
        int duzina=std::distance(skup[i].begin(),skup[i].end()), brojac(0);
        for (auto x:skup[i]) {
            if (brojac!=duzina-1) std::cout << x << ", ";
            else std::cout << x;
            brojac++;
        }
        std::cout << std::endl;
    }
	return 0;
}