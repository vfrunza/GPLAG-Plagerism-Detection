/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include <string>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
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
    std::shared_ptr<Dijete> pocetak, prethodni;
    int brojac_uspjesnih_alokacija(0);
    try {
        for (int i=0; i<imena_djece.size(); i++) {
            std::shared_ptr<Dijete> novo(new Dijete);
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
            novo=nullptr;
        }
    }
    catch(std::bad_alloc) {
        if (brojac_uspjesnih_alokacija!=0) prethodni=nullptr;
        throw;
    }
    int indeks(0);
    while(indeks!=broj_timova) {
        int brojac=duzine_timova[indeks];
        while (brojac!=0) {
            int trenutna_duzina=BrojSlovaUImenu(pocetak->ime);
            rezultat[indeks].insert(pocetak->ime);
            prethodni->sljedeci=pocetak->sljedeci;
            pocetak=pocetak->sljedeci;
            brojac--;
            for (int i=0; i<trenutna_duzina-1; i++) {
                if (i==trenutna_duzina-2) prethodni=pocetak;
                pocetak=pocetak->sljedeci;
            }
        }
        indeks++;
    }
    pocetak=nullptr;
    prethodni->sljedeci=nullptr;
    prethodni=nullptr;
    return rezultat;
}

int main() {
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