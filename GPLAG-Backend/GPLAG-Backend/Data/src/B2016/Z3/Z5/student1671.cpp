/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <cctype>

int DuzinaImena(std::string s) {
    int brojac(0);
    for (int i = 0; i < s.size(); i++)
        if ((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || (s[i] >= '0' && s[i] <= '9')) brojac++;
    return brojac;
}
struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece, int broj_timova) {
    if (broj_timova < 1 || broj_timova > imena_djece.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr), *prethodni(nullptr);
    for (int i = 0; i < imena_djece.size(); i++) {
        Dijete *novi(new Dijete);
        novi->ime = imena_djece[i];
        novi->sljedeci = nullptr;
        if (i == imena_djece.size() - 1) novi->sljedeci = pocetak;
        if (!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    std::vector<std::set<std::string>> rezultat;
    auto pok(pocetak);
    for (int i = 0; i < broj_timova; i++) {
        int test(0);
        int brojac_clanova(0);
        if (i < (imena_djece.size()%broj_timova)) test = 1;
        std::set<std::string> skup;
        while (brojac_clanova < imena_djece.size()/broj_timova + test) {
            skup.insert(pok->ime);
            auto duzina(DuzinaImena(pok->ime));
            prethodni->sljedeci = pok->sljedeci;
            delete pok;
            if (++brojac_clanova == imena_djece.size()/broj_timova + test && i == broj_timova - 1) break;
            pok = prethodni->sljedeci;
            for (int i = 0; i < duzina - 1; i++) pok = pok->sljedeci, prethodni = prethodni->sljedeci;
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
	catch(std::logic_error izuzetak) {
	    std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	return 0;
}