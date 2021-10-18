/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <tuple>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Pojmovi;
typedef std::vector<std::string> VekStr;

std::string PodString(int poz, std::string rec)
{
    std::string temp;
    for(int i(poz); i < rec.size(); i++) {
        while(rec[i] >= 'a' && rec[i] <= 'z' || rec[i] >= 'A' && rec[i] <= 'Z' || rec[i] >= '0' && rec[i] <= '9') {
            temp.push_back(rec[i]);
            i++;
        }
        if(!(rec[i] >= 'a' && rec[i] <= 'z' || rec[i] >= 'A' && rec[i] <= 'Z' || rec[i] >= '0' && rec[i] <= '9')) break;
    }
    return temp;
}

Pojmovi KreirajIndeksPojmova(Knjiga &knjiga)
{
    if(knjiga.empty()) return {{},{}};
    //pretvaramo sva slova u mala ukoliko to ona već nisu
    auto it(knjiga.begin());
    for(auto &x : it->second) {
        for(auto &y : x) y = tolower(y);
    }

    Pojmovi Indeks;
    int krug(1);
    //kretanje kroz knjigu
    for(auto it(knjiga.begin()); it != knjiga.end(); it++) {
        int stranica(0);
        std::string poglavlje {};
        int pozicija(0);
        std::tuple<std::string, int, int> trojka {};
        std::set<std::tuple<std::string, int, int>> skup {};
        poglavlje = it->first;
        //kretanje po stranicama
        for(int i(0); i < it->second.size(); i++) {
            stranica = krug;
            //Vadimo rijec po rijec i izvlacimo pozicije
            for(int j(0); j < it->second[i].size(); j++) {
                std::string pomocni {};
                if(j == it->second[i].size()-1 && it->second[i].size() > 1) break;
                while(it->second[i][j] == ' ') {
                    j++;
                    if(j == it->second[i].size()-1) break;
                }
                pozicija = j;
                pomocni = PodString(j, it->second[i]);
                if(pomocni.empty()) continue;
                trojka = std::make_tuple(poglavlje, stranica, pozicija);
                skup.insert(trojka);
                //Ubacujemo rijec, kao i skup sa poglavljem, brojem stranice i pozicijom riječu na stranici
                //Ako na drugoj stranici postoji isti string
                //auto it2(Indeks.begin());
                //auto str(it2->first);
                for(auto it2(Indeks.begin()); it2 != Indeks.end(); it2++) {
                    if(!Indeks.empty() && !it2->first.empty() && (it2->first == pomocni || it2->first.find(pomocni))) Indeks[pomocni].insert(trojka);
                }
                if(Indeks.empty()) Indeks.insert({pomocni, skup});
                trojka = {};
                skup = {};
                j+=pomocni.size();
                if(j == it->second[i].size()-1) break;
                /*
                //provjeravamo da li se podstring pojavljuje vise u tekstu
                std::string::size_type poc(0);
                std::vector<int> v1;
                while(std::string::npos != (poc = it->second[i].find(pomocni, poc))) {
                    v1.push_back(poc);
                    poc++;
                }
                if(!v1.empty()) {
                    //sada kad imamo pozicije, trebamo ih dodijeliti trojci, i ubaciti u skup
                    for(int k(0); k < v1.size(); k++) {
                        trojka = std::make_tuple(poglavlje, stranica, v1[k]);
                        skup.insert(trojka);
                        trojka = {};
                    }
                    for(auto &x : skup) Indeks[pomocni].insert(x);
                }
                */
                pomocni.clear();
                skup = {};
                //stranica++;
            }
            //for(auto )
            krug++;
            stranica = 0;
        }
    }
    return Indeks;

}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string s, const Pojmovi &mapa)
{
    if(!mapa.count(s)) throw std::logic_error("Pojam nije pronadjen");
    else {
        auto it(mapa.find(s));
        return it->second;
    }

}

void IspisiJedanPojam(const std::string &s, const std::set<std::tuple<std::string, int, int>> &skup)
{
    std::cout << s << ": ";
    int i(0);
    for(auto it(skup.begin()); it != skup.end(); it++, i++) {
        std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it);
        if(i != skup.size()-1) std::cout << ", ";
    }
}

void IspisiJedanPojam(const std::set<std::tuple<std::string, int, int>> &skup)
{
    int i(0);
    for(auto it(skup.begin()); it != skup.end(); it++, i++) {
        std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it);
        //if(i != skup.size()-1)
        std::cout << " ";
    }
}

void IspisiIndeksPojmova(const Pojmovi &mapa)
{
    for(auto it(mapa.begin()); it != mapa.end(); it++) {
        IspisiJedanPojam(it->first, it->second);
        std::cout << std::endl;
    }
}

int main ()
{
    Knjiga knjiga {};
    VekStr stranice_knjige {};
    int br_str(1);
    for(;;) {
        std::cout << "Unesite naziv poglavlja: ";
        std::string poglavlje;
        //Unos poglavlja u privremeni string
        std::getline(std::cin, poglavlje);
        if(poglavlje == ".") break;
        //Unos stranice u privremeni string
        while(1) {
            std::cout << "Unesite sadrzaj stranice " << br_str << ": ";
            std::string stranica;
            std::getline(std::cin, stranica);
            if(stranica == ".") {
                break;
            }
            stranice_knjige.push_back(stranica);
            br_str++;
        }
        poglavlje.erase(std::remove(poglavlje.begin(), poglavlje.end(), '.'), poglavlje.end());
        knjiga.insert({poglavlje, stranice_knjige});
        poglavlje.clear();
        stranice_knjige.clear();
        //std::cin.ignore(1000, '\n');
    }

    auto indeks_pojmova(KreirajIndeksPojmova(knjiga));

    //Sluzi za provjeru unosa sadrzaja Knjige
    /*for(auto it(knjiga.begin()); it != knjiga.end(); it++) {
        std::cout << "Naziv poglavlja: " << it->first;
        int str(1);
        for(int i(0); i < it->second.size(); i++){
        std::cout << std::endl << "Sadrzaj stranice " << str << " je: " << it->second[i];
        str++;
        }
        std::cout << std::endl;
    }*/
    std::cout << std::endl << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(indeks_pojmova);
    std::cout << "Unesite rijec: ";
    //std::cin.ignore(1000, '\n');
    while(1) {
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec == ".") break;
        /*try {
            auto pojam(PretraziIndeksPojmova(rijec, indeks_pojmova));
            IspisiJedanPojam(pojam);
        } catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what();
            return 0;
        }*/
        for(auto &x : rijec) x = tolower(x);
        if(!indeks_pojmova.count(rijec)) std::cout << "Unesena rijec nije nadjena!";
         else {
             auto it(indeks_pojmova[rijec]);
             IspisiJedanPojam(it);
         }
         //std::cout << std::endl << "Unesite rijec: ";
         //std::cin.ignore(1000, '\n');
        std::cout << std::endl << "Unesite rijec: ";
    }


    return 0;
}
