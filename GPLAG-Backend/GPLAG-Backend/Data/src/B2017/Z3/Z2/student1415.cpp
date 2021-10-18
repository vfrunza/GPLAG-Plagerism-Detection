/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set <std::tuple <std::string, int, int>>> Indeks;

bool TestirajSlovo (char s)
{
    return ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9'));
}

void PretvoriUMala (std::string &s)
{
    for(int i = 0; i < s.length(); i++)
        if(s.at(i) >= 'A' && s.at(i) <= 'Z') s.at(i) += ('a' - 'A');
}

Indeks KreirajIndeksPojmova (const Knjiga &kontejner)
{

    Indeks pojmovi;

    for(auto prvi = kontejner.begin(); prvi != kontejner.end() ; prvi++) {

        for(int j = 0; j < (prvi->second).size(); j++) {

            for(int k = 0; k < (prvi->second).at(j).size(); k++) {

                int broj (k);

                if(TestirajSlovo((prvi->second).at(j).at(k))) {
                    std::string trenutni {};
                    while (TestirajSlovo((prvi->second).at(j).at(k))) {
                        trenutni.push_back((prvi->second).at(j).at(k));
                        k++;
                        if(k == (prvi->second).at(j).size()) break;
                    }
                    k--;

                    if(!kontejner.count(trenutni)) {

                        PretvoriUMala(trenutni);
                        (pojmovi[trenutni]).insert(std::make_tuple(prvi->first, j + 1, broj));


                    }

                }
            }
        }

    }
    return pojmovi;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova (std::string rijec, Indeks pojmovi)
{

    PretvoriUMala(rijec);
    if(!pojmovi.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    return pojmovi[rijec];

}

void IspisiIndeksPojmova (Indeks pojmovi)
{
    for(auto it = pojmovi.begin(); it != pojmovi.end(); it++) {
        std::cout << it->first << ": ";
        for(auto iter = (it->second).begin(); iter != it->second.end(); iter++) {
            std::cout << std::get<0>(*iter) << "/" << std::get<1>(*iter) <<"/"<< std::get<2>(*iter);
            if(iter == --(it->second.end())) {
                std::cout << std::endl;
                break;
            }
            std::cout << ", ";
        }
    }
}

int main ()
{

    Knjiga ZlocinIKazna;

    std::cout <<"Unesite naziv poglavlja: ";
    std::string poglavlje;


    while(std::getline(std::cin, poglavlje), poglavlje != ".") {


        std::string trenutni;
        std::vector<std::string> tekst;
        int brojac (2);

        std::cout << "Unesite sadrzaj stranice 1: ";

        while(std::getline(std::cin, trenutni), trenutni != ".") {

            tekst.push_back(trenutni);
            std::cout << "Unesite sadrzaj stranice " << brojac <<": ";
            brojac++;

        }

        ZlocinIKazna[poglavlje] = tekst;
        std::cout << "Unesite naziv poglavlja: ";

    }

    auto pojmovi (KreirajIndeksPojmova(ZlocinIKazna));
    std::cout << std::endl << "Kreirani indeks pojmova: " << std::endl;
    IspisiIndeksPojmova(pojmovi);

    std::cout << std::endl;

    std::string trazena;
    std::cout << "Unesite rijec: ";

    while(std::getline(std::cin, trazena), trazena != ".") {
        try {
            auto zapis (PretraziIndeksPojmova(trazena, pojmovi));

            for(auto it = zapis.begin(); it != zapis.end(); it++)
                std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << " ";


            std::cout << std::endl << "Unesite rijec: ";

        } catch (std::logic_error e) {

            std::cout << "Unesena rijec nije nadjena! "<< std::endl;
            std::cout << "Unesite rijec: ";
            continue;
        }
    }

    return 0;
}
