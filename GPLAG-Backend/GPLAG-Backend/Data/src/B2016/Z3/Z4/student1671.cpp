/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <set>
#include <string>
#include <list>
#include <vector>
#include <cctype>
#include <iterator>

int DuzinaImena(std::string s) {
    int brojac(0);
    for (int i = 0; i < s.size(); i++) if ((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || (s[i] >= '0' && s[i] <= '9')) brojac++;
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece, int broj_timova) {
    if (broj_timova < 1 || broj_timova > imena_djece.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for (int i = 0; i < imena_djece.size(); i++) 
        lista.push_back(imena_djece[i]);
    std::vector<std::set<std::string>> rezultat;
    auto it(lista.begin());
    for (int i = 0; i < broj_timova; i++) {
        int test(0);
        int brojac_clanova(0);
        if (i < (imena_djece.size()%broj_timova)) test = 1;
        std::set<std::string> skup;
        while (brojac_clanova < imena_djece.size()/broj_timova + test) {
            skup.insert(*it);
            auto duzina(DuzinaImena(*it));
            it = lista.erase(it);
            if (it == lista.end()) it = lista.begin();
            for (int i = 0; i < duzina-1; i++) {
                it++;
                if (it == lista.end()) it = lista.begin();
            }
            brojac_clanova++;
        }
        rezultat.push_back(skup);
    }
    return rezultat;
}
int main ()
{
	try {
	    int broj_djece;
	    std::cout << "Unesite broj djece: ";
	    std::cin >> broj_djece;
	    std::cin.ignore(10000, '\n');
	    std::vector<std::string> imena_djece(broj_djece);
	    std::cout << "Unesite imena djece: ";
	    for (int i = 0; i < broj_djece; i++) std::getline(std::cin, imena_djece[i]);
	    int broj_timova;
	    std::cout << "\nUnesite broj timova: ";
	    std::cin >> broj_timova;
	    auto kontejner(Razvrstavanje(imena_djece, broj_timova));
	    for (int i = 0; i < kontejner.size(); i++) {
	        std::cout << "Tim " << i + 1 << ": ";
	        for (auto it(kontejner[i].begin()); it != kontejner[i].end(); it++) {
	            std::cout << *it;
	            auto test(it);
	            if (++test != kontejner[i].end()) std::cout << ", ";
	        }
	        std::cout << std::endl;
	    }
	}
	catch (std::logic_error izuzetak) {
	    std::cout << "Izuzetak: " << izuzetak.what();
	}
	return 0;
}