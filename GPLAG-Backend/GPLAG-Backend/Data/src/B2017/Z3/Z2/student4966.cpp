/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <tuple>
#include <new>
#include <cctype>
typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::set<std::tuple<std::string, int, int>> SkupPozicija;
typedef std::map<std::string, SkupPozicija> IndeksPojmova;
bool DaLiJeSlovo (char znak) {
    if ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9')) return true;
    return false;
}
std::string MalaSlova(std::string s) {
    for (char &c : s) c=std::tolower(c);
    return s;
}
std::multimap<std::string, int> EkstraktujRijeci (std::string recenica) {
    auto it=recenica.begin();
    auto it2=recenica.begin();
    std::multimap<std::string, int> SpisakRijeci;
    int i(0);
    while (it!=recenica.end()) {
        while (it2!=recenica.end() && !DaLiJeSlovo(*it2)) { it2++; i++; }
        it=it2;
        while(it2!=recenica.end() && DaLiJeSlovo(*it2)) it2++;
        std::string rijec;
        std::copy(it, it2, back_inserter(rijec));
        if (rijec.length()) SpisakRijeci.insert({MalaSlova(rijec), i});
        i+=it2-it;
        it=it2;
    }
    return SpisakRijeci;
}
IndeksPojmova KreirajIndeksPojmova(Knjiga knjiga) {
    IndeksPojmova indeks;
    int i(1);
    for (auto poglavlje : knjiga) {
        for (auto stranica : poglavlje.second) {
            auto spisakrijeci=EkstraktujRijeci(stranica);
            for (auto rijec : spisakrijeci) {
                if (!indeks.count(rijec.first)) {
                    SkupPozicija skup;
                    skup.insert(std::tie(poglavlje.first, i, rijec.second));
                    indeks.insert({rijec.first, skup});
                }
                else {
                    indeks[rijec.first].insert(std::tie(poglavlje.first,i,rijec.second));
                }
            }
            i++;
        }
    }
    return indeks;
}
SkupPozicija PretraziIndeksPojmova(std::string rijec, IndeksPojmova indeks) {
    if (!indeks.count(MalaSlova(rijec))) throw std::logic_error("Pojam nije nadjen");
    return indeks.at(MalaSlova(rijec));
}
void IspisiIndeksPojmova (const IndeksPojmova &indeks) {
    for (auto x : indeks) {
        std::cout<<x.first<<": ";
        auto pozicije=x.second;
        int i(0);
        for (auto pozicija : pozicije) {
            std::cout<<std::get<0>(pozicija)<<"/"<<std::get<1>(pozicija)<<"/"<<std::get<2>(pozicija);
            if (i!=pozicije.size()-1) std::cout<<", ";
            i++;
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    Knjiga knjiga;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string nazivpoglavlja;
        std::getline(std::cin, nazivpoglavlja);
        if (nazivpoglavlja==".") break;
        std::vector<std::string> stranice;
        for (int i=1;;i++) {
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::string sadrzaj;
            std::getline(std::cin, sadrzaj);
            if (sadrzaj==".") break;
            stranice.push_back(sadrzaj);
        }
        knjiga.insert({nazivpoglavlja, stranice});
    }
    auto indekspojmova=KreirajIndeksPojmova(knjiga);
    std::cout<<std::endl<<"Kreirani indeks pojmova: "<<std::endl;
    IspisiIndeksPojmova(indekspojmova);
    for (;;) {
        std::cout<<"Unesite rijec: ";
        std::string unos, rijec;
        std::getline(std::cin, unos);
        std::copy_if(unos.begin(),unos.end(),std::back_inserter(rijec), [](char x) { return x!=' ';});
        if (rijec==".") break;
        try {
            auto pozicije=PretraziIndeksPojmova(MalaSlova(rijec),indekspojmova);
            for (auto pozicija : pozicije)
                std::cout<<std::get<0>(pozicija)<<"/"<<std::get<1>(pozicija)<<"/"<<std::get<2>(pozicija)<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error &e) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}
