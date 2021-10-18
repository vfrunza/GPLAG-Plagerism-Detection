/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <stdexcept>
#include <cctype>
#include <iterator>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga knjiga) {
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa;
    for (auto it=knjiga.begin(); it!=knjiga.end(); it++) {
        std::string naziv_poglavlja;
        naziv_poglavlja=it->first;
        std::vector<std::string> sadrzaj_poglavlja;
        sadrzaj_poglavlja=it->second;
        for (int broj_stranice=0; broj_stranice<sadrzaj_poglavlja.size(); broj_stranice++) {
            std::string sadrzaj_stranice;
            sadrzaj_stranice=sadrzaj_poglavlja.at(broj_stranice);
            std::string rijec;
            for (int indeks=0; indeks<sadrzaj_stranice.length(); indeks++) {
                while (indeks<sadrzaj_stranice.length() && std::isalnum(sadrzaj_stranice.at(indeks))==0) indeks++;
                int pocetni_indeks;
                if (indeks<sadrzaj_stranice.length()) {
                    pocetni_indeks=indeks;
                }
                else break;
                while (indeks<sadrzaj_stranice.length() && std::isalnum(sadrzaj_stranice.at(indeks))!=0) {
                    rijec.push_back(char(std::tolower(sadrzaj_stranice.at(indeks))));
                    indeks++;
                }
                if (mapa.begin()==mapa.end() || mapa.find(rijec)==mapa.end()) {
                    std::set<std::tuple<std::string, int, int>> skup_za_rijec;
                    std::tuple<std::string, int, int> podaci_za_rijec;
                    podaci_za_rijec=std::make_tuple(naziv_poglavlja, broj_stranice+1, pocetni_indeks);
                    skup_za_rijec.insert(podaci_za_rijec);
                    mapa[rijec]=skup_za_rijec;
                    rijec="";
                }
                else {
                    std::tuple<std::string, int, int> podaci_za_rijec;
                    podaci_za_rijec=std::make_tuple(naziv_poglavlja, broj_stranice+1, pocetni_indeks);
                    (mapa[rijec]).insert(podaci_za_rijec);
                    rijec="";
                }
                if (indeks==sadrzaj_stranice.length()) break;
                while (indeks<sadrzaj_stranice.length() && std::isalnum(sadrzaj_stranice.at(indeks))==0) indeks++;
                indeks--;
            }
        }
    }
    return mapa;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks) {
    std::string mala_rijec;
    for (int i=0; i<rijec.length(); i++) mala_rijec.push_back(char(std::tolower(rijec.at(i))));
    if (indeks.find(mala_rijec)==indeks.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return indeks[mala_rijec];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa) {
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::string rijec;
        rijec=it->first;
        std::set<std::tuple<std::string, int, int>> skup_za_rijec;
        skup_za_rijec=it->second;
        std::set<std::tuple<std::string, int, int>>::iterator kraj_skupa;
        kraj_skupa=skup_za_rijec.end();
        kraj_skupa--;
        std::cout << rijec << ": ";
        for (auto it_skupa=skup_za_rijec.begin(); it_skupa!=kraj_skupa; it_skupa++) {
            std::tuple<std::string, int, int> podaci_za_rijec;
            podaci_za_rijec=(*it_skupa);
            std::cout 
            << std::get<0>(podaci_za_rijec) << "/" 
            << std::get<1>(podaci_za_rijec) << "/" 
            << std::get<2>(podaci_za_rijec) << ", ";
        }
        std::tuple<std::string, int, int> podaci_za_rijec;
        podaci_za_rijec=(*kraj_skupa);
        std::cout 
        << std::get<0>(podaci_za_rijec) << "/" 
        << std::get<1>(podaci_za_rijec) << "/" 
        << std::get<2>(podaci_za_rijec);
        std::cout << std::endl;
    }
}

void IspisiTuple(std::tuple<std::string, int, int> ntorka) {
    std::cout 
    << std::get<0>(ntorka) << "/" 
    << std::get<1>(ntorka) << "/" 
    << std::get<2>(ntorka) << " ";
}

int main ()
{
    Knjiga knjiga;
    std::string naziv_poglavlja;
    do {
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, naziv_poglavlja);
        if (naziv_poglavlja==".") break;
        int brojac(1);
        std::vector<std::string> sadrzaj_poglavlja;
        std::string sadrzaj_stranice;
        do {
            std::cout << "Unesite sadrzaj stranice " << brojac++ << ": ";
            std::getline(std::cin, sadrzaj_stranice);
            if (sadrzaj_stranice==".") break;
            sadrzaj_poglavlja.push_back(sadrzaj_stranice);
        } while (sadrzaj_stranice!=".");
        knjiga[naziv_poglavlja]=sadrzaj_poglavlja;
    } while (naziv_poglavlja!=".");
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova;
    indeks_pojmova=KreirajIndeksPojmova(knjiga);
    std::cout << std::endl << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(indeks_pojmova);
    std::string rijec;
    do {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if (rijec==".") break;
        try {
            std::set<std::tuple<std::string, int, int>> skup;
            skup=PretraziIndeksPojmova(rijec, indeks_pojmova);
            for (auto it=skup.begin(); it!=skup.end(); it++) {
                std::tuple<std::string, int, int> ntorka=(*it);
                IspisiTuple(ntorka);
            }
        }
        catch(std::logic_error greska) {
            std::cout << greska.what();
        }
        std::cout << std::endl;
    } while (rijec!=".");
	return 0;
}
