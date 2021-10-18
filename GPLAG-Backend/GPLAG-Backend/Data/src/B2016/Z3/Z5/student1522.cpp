/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
struct Dijete {
    std::string ime;
    Dijete* sljedeci;    
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector <std::string> imena, int br_timova) {
    if (br_timova < 1 || br_timova > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr), *prethodni;
    for (int i = 0; i < imena.size(); i++) {
        Dijete* novi(new Dijete);
        novi -> ime = imena[i]; novi -> sljedeci = nullptr;
        if (!pocetak) pocetak = novi;
        else prethodni -> sljedeci = novi;
        prethodni = novi;
    }
    prethodni -> sljedeci = pocetak ;
    int broj_prvih_timova (imena.size()%br_timova);
    bool prvi_timovi (true);
    int broj_clanova (int (imena.size()/br_timova));
    int brojac (0);
    int brojac1 (0);
    int brojac_prvih_timova(0);
    bool djeljiv (!broj_prvih_timova);
    std::vector <std::set<std::string>> vektor (br_timova);
    auto it (pocetak);
    auto preth(prethodni);
    for (;;) {
        if (djeljiv && ((!prvi_timovi && brojac == broj_clanova-1) || (prvi_timovi && brojac == broj_clanova))) {
            brojac1++;
            broj_prvih_timova++;
            brojac = 0;
        }
        vektor[brojac1].insert(it -> ime);
        auto rijec (it -> ime);
        int br(0);
        for (int i = 0; i < rijec.length(); i++)
            if ((rijec[i]>='a' && rijec[i]<='z') || (rijec[i]>='A' && rijec[i] <='Z') || (rijec[i]>='0' && rijec[i]<='9')) br++;
        preth -> sljedeci = it ->sljedeci;
        auto pom(it);
        it = it -> sljedeci;
        pom -> sljedeci =nullptr;
        delete pom;
                if (brojac1 == br_timova-1 && 
                ( ( !djeljiv && ((!prvi_timovi && brojac == broj_clanova-1) || (prvi_timovi && brojac == broj_clanova))) || 
                ( djeljiv && ((!prvi_timovi && brojac == broj_clanova-1) || (prvi_timovi && brojac == broj_clanova-1))))) break;

        if (!djeljiv && brojac_prvih_timova == broj_prvih_timova) prvi_timovi = false;
        if (!djeljiv && ((!prvi_timovi && brojac == broj_clanova-1) || (prvi_timovi && brojac == broj_clanova))) {
            brojac1++;
            brojac_prvih_timova++;
            brojac=0;
            brojac--;
        }
        brojac++;  
        while (br != 1) {
            it = it -> sljedeci;
            preth = preth -> sljedeci;
            br--;
        } 
    }
    return vektor;

}

int main ()
{   try {
        std::cout << "Unesite broj djece: ";
        int n;
        std::cin >> n;
        std::cout << "Unesite imena djece: "<<std::endl;
        std::vector <std::string> imena(n);
        std::cin.ignore(10000,'\n');
        for (int i = 0; i < n; i++)
            std::getline (std::cin, imena[i]);
        std::cout << "Unesite broj timova: ";
        int m;
        std::cin >> m;
        std::vector <std::set<std::string>> Kontejner {Razvrstavanje(imena, m)};
        for (int i = 0; i < Kontejner.size(); i++) {
            std::cout << "Tim " << i+1 << ": ";
            auto it(Kontejner[i].begin());
            for (int j = 0; j < Kontejner[i].size()-1; j++) {
                std::cout << *it << ", ";
                it++;
            }
            std::cout << *it << std::endl;
        }
    }
    catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}