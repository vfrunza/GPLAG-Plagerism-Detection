/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <tuple> 
#include <stdexcept>

typedef std::map < std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;

template <typename NekiTip>
bool Slovo(NekiTip x)
{ 
    return ((x >= 'a' && x <='z')||(x >= 'A' && x <='Z') || (x >='0' && x<='9'));
}

std::string UMalaSlova (std::string s)
{
    for(auto &slovo : s)
        if(slovo >='A' && slovo<='Z') slovo+= 'a' - 'A';
    return s;
}

IndeksPojmova KreirajIndeksPojmova (Knjiga k)
{
    IndeksPojmova indeks;
    for(auto it = k.begin(); it != k.end(); it++) { //iterira kroz mapu
        for(auto i = 0; i < (it->second).size(); i++) { //iterira kroz vektor
            auto iter((it->second)[i].begin());
            while (iter != (it->second)[i].end()) {
                auto pocetak(iter);
                while (iter != (it->second)[i].end() && Slovo(*iter)) {
                    iter++;
                }

                if(pocetak != (it->second)[i].end() && !Slovo(*pocetak)) {
                    iter++;
                    continue;
                }

                std::string tmp((it->second)[i].substr(pocetak - (it->second)[i].begin(), iter-pocetak));
                tmp=UMalaSlova(tmp);

                indeks[tmp].insert(std::make_tuple(it->first, i+1, pocetak - (it->second)[i].begin()));

                if(iter != (it->second)[i].end()) iter++;
                else break;
            }
        }
    }

    return indeks;

}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova (std::string rijec, IndeksPojmova indeks)
{
    if(indeks.find(rijec) == indeks.end()) throw std::logic_error("Pojam nije nadjen");
    return indeks[rijec];
}

void IspisiIndeksPojmova (IndeksPojmova indeks)
{
    for (auto it = indeks.begin(); it!=indeks.end(); it++) {
        std::cout << it->first << ": ";
        for(auto itt = (it->second).begin(); itt!=(it->second).end(); itt++) {
            std::cout << std::get<0>(*itt) << "/" << std::get<1>(*itt) << "/" << std::get<2>(*itt);
            if(itt!= --(it->second).end()) std::cout << ", ";
            else std::cout << std::endl;
        }
    }
}

int main ()
{
    Knjiga k;
    for(;;) {
        std::cout << "Unesite naziv poglavlja: ";
        std::string naziv_poglavlja;
        std::getline(std::cin, naziv_poglavlja);
        if(naziv_poglavlja == ".") break;
        int i(1);
        for(;;) { 
            std::string sadrzaj_stranice;
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::getline(std::cin, sadrzaj_stranice);
            if(sadrzaj_stranice == ".") break;
            k[naziv_poglavlja].push_back(sadrzaj_stranice);
            i++;
        }
    }
    std::cout << std::endl;
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    IndeksPojmova indeks(KreirajIndeksPojmova(k));
    IspisiIndeksPojmova(indeks);

    for(;;) {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec == ".") break;
        if(indeks.find(rijec) == indeks.end()) std::cout << "Unesena rijec nije nadjena!";
        for(auto trojka : indeks[rijec])
            std::cout << std::get<0>(trojka) << "/" << std::get<1>(trojka) << "/" << std::get<2>(trojka)<<" ";
        std::cout << std::endl;
    }
 


    return 0;
}
