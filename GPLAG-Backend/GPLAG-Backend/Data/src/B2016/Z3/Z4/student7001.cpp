/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

int BrojSlovaUImenu(std::string ime) {
    int brojac(0);
    for (int i=0; i<ime.size(); i++)
        if ((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9')) brojac++;
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &imena_djece, int broj_timova) {
    if (broj_timova<1 || broj_timova>imena_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista_imena;
    for (int i=0; i<imena_djece.size(); i++)
        lista_imena.push_back(imena_djece[i]);
    std::vector<int> duzine_timova;
    for (int i=0; i<imena_djece.size()%broj_timova; i++)
        duzine_timova.push_back(int(imena_djece.size()/broj_timova)+1);
    for (int i=0; i<broj_timova-imena_djece.size()%broj_timova; i++)
        duzine_timova.push_back(int(imena_djece.size()/broj_timova));
    std::vector<std::set<std::string>> rezultat(broj_timova);
    int indeks(0);
    auto it=lista_imena.begin();
    while (indeks!=broj_timova) {
        int brojac=duzine_timova[indeks];
        while (brojac!=0) {
            int trenutna_duzina=BrojSlovaUImenu(*it);
            rezultat[indeks].insert(*it);
            it=lista_imena.erase(it);
            if (it==lista_imena.end()) it=lista_imena.begin();
            brojac--;
            for (int i=0; i<trenutna_duzina-1; i++) {
                it++;
                if (it==lista_imena.end())
                    it=lista_imena.begin();
            }
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
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> imena_djece(broj_djece);
    for (int i=0; i<broj_djece; i++)
        std::getline(std::cin,imena_djece[i]);
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
    for (int i=0; i<skup.size(); i++) {
        std::cout << "Tim " << i+1 << ": ";
        int duzina=std::distance(skup[i].begin(), skup[i].end()), brojac(0);
        for (auto x:skup[i]) {
            if (brojac!=duzina-1) std::cout << x << ", ";
            else std::cout << x;
            brojac++;
        }
        std::cout << std::endl;
    }
    return 0;
}