/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool NijeSlovo(char znak)
{
    return !((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9'));
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga tekst)
{
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks;
    for (auto poglavlje = tekst.begin(); poglavlje!=tekst.end(); poglavlje++) {
        for (int i = 0; i < (poglavlje->second).size(); i++) {
            std::string pomocni_string;
            for (int j = 0; j < (poglavlje->second).at(i).size(); j++) {
                if ((poglavlje->second).at(i).at(j)>='A' && (poglavlje->second).at(i).at(j)<='Z') {
                    pomocni_string.push_back((poglavlje->second).at(i).at(j)+'a'-'A');
                } else
                    pomocni_string.push_back((poglavlje->second).at(i).at(j));
            }
            for (int j = 0; j < pomocni_string.size(); j++) {
                if (!NijeSlovo(pomocni_string.at(j)) && (j==0 || NijeSlovo(pomocni_string.at(j-1)))) {
                    int k(j);
                    for (; k < pomocni_string.size(); k++)
                        if (NijeSlovo(pomocni_string.at(k)))
                            break;
                    std::set<std::tuple<std::string, int, int>> pomocni_skup;
                    pomocni_skup.insert(std::make_tuple(poglavlje->first, i+1, j));

                    if (!indeks.count(pomocni_string.substr(j, k-j)))
                        indeks.insert({pomocni_string.substr(j, k-j), pomocni_skup});
                    else {
                        indeks[pomocni_string.substr(j, k-j)].insert(std::make_tuple(poglavlje->first, i+1, j));
                    }
                }
            }
        }
    }
    return indeks;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks)
{
    if (!indeks.count(rijec))
        throw std::logic_error("Pojam nije nadjen");
    return indeks[rijec];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> tekst)
{
    for (auto poglavlje = tekst.begin(); poglavlje!=tekst.end(); poglavlje++) {
        std::cout << poglavlje->first << ": ";
        int br(0);
        for (auto it = (poglavlje->second).begin(); it!=(poglavlje->second).end(); it++) {
            br++;
            if (br==(poglavlje->second.size()))
                std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it);
            else
                std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << ", ";
        }
        std::cout << std::endl;
    }
}

int main ()
{
    Knjiga k;
    for (;;) {
        std::string poglavlje;
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, poglavlje);
        if (poglavlje==".")
            break;
        std::vector<std::string> pomocni;
        for (int i = 1; ; i++) {
            std::string stranica;
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::getline(std::cin, stranica);
            if (stranica==".")
                break;
            pomocni.push_back(stranica);
        }
        k.insert({poglavlje, pomocni});
    }
    auto indeks_pojmova(KreirajIndeksPojmova(k));
    std::cout << std::endl << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(indeks_pojmova);
    std::cout << std::endl;
    for (;;) {
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if (rijec==".")
            break;
        std::set<std::tuple<std::string, int, int>> skup;
        try {
            skup=PretraziIndeksPojmova(rijec, indeks_pojmova);
        } catch (const std::exception &greska) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
            continue;
        }
        for (auto it=skup.begin(); it!=skup.end(); it++)
            std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << " ";
        std::cout << std::endl;
    }
    return 0;
}
