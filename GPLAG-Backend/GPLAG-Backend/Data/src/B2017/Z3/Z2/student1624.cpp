/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <utility>
#include <algorithm>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::vector<std::tuple<std::string, int, int>>> IndeksPojmova;

bool NijeInterpunkcija(char c)
{
    return (c>=48 && c<=57) || (c>=97 && c<=122);
}

std::map<std::string, std::vector<int>>PronadjiPojmove(std::string s)
{
    std::map<std::string, std::vector<int>> Pojmovi;

    auto start = s.begin();
    bool rijec = false;
    int a=0, b=0;

    while(start != s.end()) {
        while(!NijeInterpunkcija(*start) && start != s.end()) {
            start++;
            a++;
        }

        auto end=start;

        while(NijeInterpunkcija(*end) && end != s.end()) {
            end++;
            b++;
            rijec = true;
        }

        if(end == s.end() && !rijec) break;

        if(rijec && b>0) {
            std::map<std::string, std::vector<int>>::iterator i = Pojmovi.find(s.substr(a, b));
            if(i == Pojmovi.end()) {
                Pojmovi.insert(std::pair<std::string, std::vector<int>>(s.substr(a, b), {a}));
            } else {
                i->second.push_back(a);
            }
        }

        start=end;
        a+=b;
        b=0;
    }
    return Pojmovi;
}

IndeksPojmova KreirajIndeksPojmova(Knjiga knjiga)
{
    IndeksPojmova IndeksPojmova;
    auto poglavlje = knjiga.begin();

    while(poglavlje!=knjiga.end()) {
        int str=1;

        for(auto stranica : poglavlje->second) {
            auto pojmovi = PronadjiPojmove(stranica);

            for(auto pojam : pojmovi) {
                for(int pozicija : pojam.second) {
                    std::tuple<std::string, int, int> trojka(poglavlje->first, str, pozicija);

                    auto pozicije_pojma = IndeksPojmova.find(pojam.first);
                    if(pozicije_pojma == IndeksPojmova.end()) {
                        std::vector<std::tuple<std::string, int, int>> trojke = {trojka};
                        IndeksPojmova.insert(std::pair<std::string, std::vector<std::tuple<std::string, int, int>>>(pojam.first, trojke));
                    } else {
                        pozicije_pojma->second.push_back(trojka);
                    }
                }
            }
            str++;
        }
        poglavlje++;
    }
    return IndeksPojmova;
}

void IspisiIndeksPojmova(IndeksPojmova indeks)
{
    std::cout << std::endl;
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    for(auto pojam : indeks) {
        std::cout << pojam.first << ": ";
        int n=0;
        for (auto pozicija:pojam.second) {
            n++;
            std::cout << std::get<0>(pozicija) << "/" << std::get<1>(pozicija) << "/" << std::get<2>(pozicija);
            if(n < pojam.second.size()) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}

void IspisiIndeksPojmova(std::string pojam, std::vector<std::tuple<std::string, int, int>> pozicije)
{
    int n=0;
    for(auto pozicija : pozicije) {
        n++;
        std::cout << std::get<0>(pozicija) << "/" << std::get<1>(pozicija) << "/" << std::get<2>(pozicija);
        if(n < pozicije.size()) std::cout << " ";
    }
    std::cout << std::endl;
}

std::vector<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string pojam, IndeksPojmova indeks)
{
    auto pozicije_pojma = indeks.find(pojam);
    if(pozicije_pojma!=indeks.end()) {
        return pozicije_pojma->second;
    } else throw std::logic_error("Pojam nije nadjen");
}

int main ()
{
    Knjiga knjiga;

    while(true) {
        std::string a, b;
        std::vector<std::string> stranice;

        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, a);
        if(a == ".") break;
        int k = 1;
        while(true) {
            std::cout << "Unesite sadrzaj stranice " << k++ <<": ";
            std::getline(std::cin, b);
            if(b != ".") {
                std::transform(b.begin(), b.end(), b.begin(), ::tolower);
                stranice.push_back(b);
            } else break;
        }
        knjiga.insert(std::pair<std::string, std::vector<std::string>>(a, stranice));
    }

    auto indeksPojmova = KreirajIndeksPojmova(knjiga);
    IspisiIndeksPojmova(indeksPojmova);

    while(true) {
        std::string a;

        std::cout << "Unesite rijec: ";
        std::getline(std::cin, a);
        if(a == ".") break;

        try {
            IspisiIndeksPojmova(a, PretraziIndeksPojmova(a, indeksPojmova));
        } catch(std::logic_error izuzetak) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }

    return 0;
}
