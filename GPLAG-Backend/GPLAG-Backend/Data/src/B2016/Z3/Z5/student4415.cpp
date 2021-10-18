/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>
#include <iterator>


struct Dijete {
    std::string ime;
    Dijete* sljedeci = nullptr;
};

int duzina_imena (std::string ime )
{
    int brojac(0);
    for (auto &i : ime) {
        if ((i >= 'A' and i <= 'Z')or (i >= 'a' and i <= 'z') or (i >= '0' and i <= '9')) brojac++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djeca2, int br_tim)
{
    if (br_tim < 1 or br_tim > djeca2.size()) throw std::logic_error("Razvrstavanje nemoguce");     // check is number of teams correct
    
    std::vector<std::set<std::string>> Timovi(0);       // vector of sets of strings
    std::set<std::string> tim;                          // temporary team
    // number of teams and size of team
    int br_tim_1(djeca2.size()%br_tim);
    int br_clanova_1((djeca2.size()/br_tim)+1);
    int br_clanova_2(djeca2.size()/br_tim);
    
    Dijete *pocetak(nullptr), *prethodni(nullptr);
    for (auto &i : djeca2) {
        Dijete *novi = new(Dijete);
        novi->ime = i; novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni-> sljedeci = novi;
        prethodni = novi;
    }
    prethodni->sljedeci = pocetak;
    auto klizeci(pocetak);
    auto temp(klizeci->ime);
    while (true) {
        temp = klizeci -> ime;
        // pravimo skupove
        if (Timovi.size() < br_tim_1) {
            if (tim.size() < br_clanova_1)
                tim.insert(temp);
            else {
                Timovi.push_back(tim);
                tim.clear();
                tim.insert(temp);
            }
        } else {
            if (tim.size() < br_clanova_2)
                tim.insert(temp);
            else {
                Timovi.push_back(tim);
                tim.clear();
                tim.insert(temp);
            }
        }
        
        if(prethodni == (prethodni->sljedeci)) {
            delete prethodni;
            if (tim.size() != 0) Timovi.push_back(tim);
            break;
        } else {
            (prethodni->sljedeci) = (klizeci ->sljedeci);
            delete klizeci;
            klizeci = prethodni-> sljedeci;
        }
        int brojac(duzina_imena(temp) -1);
        for (int i = 0; i < brojac; i++) {
            klizeci = (klizeci-> sljedeci);
            prethodni = (prethodni-> sljedeci);
        }
    }
    return Timovi;
}
int main ()
{
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cout << "Unesite imena djece: " << std::endl;
    std::cin.ignore(1000,'\n');
    std::vector<std::string> v1(n);
    for (auto &i : v1) {
        std::getline(std::cin,i);
        
    }
    std::cout << "Unesite broj timova: ";
    std::cin >> n;
    try {
        auto Timovi(Razvrstavanje(v1,n));
    
    
   int brojac(1);
    for (auto &i : Timovi) {
        auto zadnji(i.end());
        zadnji--;
        std::cout << "Tim " << brojac << ": ";
        brojac++;
        for (auto j = i.begin(); j != i.end(); j++) {
            if (j == zadnji) std::cout << *j;
            else std::cout << *j << ", ";
        }
        std::cout  << std::endl;
    }
    }
    catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
        
    }
	return 0;
}