/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

void UnesiUKnjigu(Knjiga &knjiga)
{
    std::string poglavlje, strana;
    for(auto it(knjiga.end());; it++) {
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, poglavlje);
        if(poglavlje==".") break;
        std::vector<std::string> strane;
        for(int i(0);; i++) {
            std::cout << "Unesite sadrzaj stranice " << i+1 << ": ";
            std::getline(std::cin, strana);
            if(strana==".") break;
            strane.push_back(strana);
        }
        knjiga.insert(it, std::make_pair(poglavlje, strane));
    }
}

void IspisiKnjigu(const Knjiga &knjiga)
{
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++) {
        std::cout << "Poglavlje: " << it->first << std::endl;
        int i(0);
        for(auto it1(it->second.begin()); it1!=it->second.end(); it1++) {
            std::cout << "Strana " << i+1 << ": " << *it1 << std::endl;
            i++;
        }
    }
}

bool Slovo(const char a)
{
    if((a>='a' && a<='z') || (a>='A' && a<='Z')) return true;
    return false;
}

std::string::iterator IzaKrajaRijeci(const std::string &recenica, std::string::iterator p)
{
    while(p!=recenica.end() && Slovo(*p)) p++;
    return p;
}

std::string NapraviRijec(std::string::iterator pocetak, std::string::iterator iza_kraja)
{
    auto pom(pocetak);
    std::string rijec;
    while(pom!=iza_kraja) {
        rijec.push_back(*pom);
        pom++;
    }
    for(char &x: rijec) {
        x=tolower(x);
    }
    return rijec;
}

int Razmak(std::string::iterator pocetak, std::string::iterator iza_kraja)
{
    int razmak(0);
    auto pom(pocetak);
    while(pom!=iza_kraja) {
        razmak++;
        pom++;
    }
    return razmak;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(const Knjiga &knjiga)
{
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indekspojmova;
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++) {
        int broj_stranice(1);
        for(auto it1(it->second.begin()); it1!=it->second.end(); it1++) {
            std::string strana(*it1);
            std::tuple<std::string, int, int> rijec;
            std::get<0>(rijec)=it->first;
            std::get<1>(rijec)=broj_stranice;
            int broj_u_stringu(0);
            for(auto it2(strana.begin()); it2!=strana.end(); it2++) {
                int broj(0);
                std::set<std::tuple<std::string, int, int>> ind;
                std::string rij;
                if(Slovo(*it2)) {
                    std::string::iterator iza_kraja(IzaKrajaRijeci(strana, it2));
                    rij=(NapraviRijec(it2, iza_kraja));
                    broj=Razmak(it2, iza_kraja);
                    it2=iza_kraja;
                    it2--;
                    std::get<2>(rijec)=broj_u_stringu;

                    auto p=std::find_if(indekspojmova.begin(), indekspojmova.end(),
                    [rij](std::pair<std::string, std::set<std::tuple<std::string, int, int>>> a) {
                        return a.first==rij;
                    });
                    if(p==indekspojmova.end()) {
                        ind.insert(rijec);
                        indekspojmova.insert(indekspojmova.end(), std::make_pair(rij, ind));
                        ind=std::set<std::tuple<std::string, int, int>>();
                    } else p->second.insert(rijec);
                }
                broj_u_stringu+=broj;
                if(broj!=0) broj_u_stringu++;
            }
            broj_stranice++;
        }
    }
    return indekspojmova;
}

void IspisiRijec(std::tuple<std::string, int, int> a)
{
    std::cout << std::get<0>(a) << "/" << std::get<1>(a) << "/" << std::get<2>(a);
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> indekspojmova)
{
    std::set<std::tuple<std::string, int, int>> skup;
    int b=std::count_if(indekspojmova.begin(), indekspojmova.end(),
    [rijec](std::pair<std::string, std::set<std::tuple<std::string, int, int>>> a) {
        return rijec==a.first;
    });
    if(b==0) throw std::logic_error("Unesena rijec nije nadjena!");
    std::for_each(indekspojmova.begin(), indekspojmova.end(),
    [rijec, &skup](std::pair<std::string, std::set<std::tuple<std::string, int, int>>> a) {
        if(rijec==a.first) skup=a.second;
    });
    return skup;
}

void IspisiIndeks(std::set<std::tuple<std::string, int, int>> a)
{
    int broj(0), i(0);
    for(auto it(a.begin()); it!=a.end(); it++) broj++;
    for(auto it(a.begin()); it!=a.end(); it++) {
        IspisiRijec(*it);
        i++;
        if(i!=broj) std::cout << ", ";
    }
}

void IspisiIndeks2(std::set<std::tuple<std::string, int, int>> a)
{
    for(auto it(a.begin()); it!=a.end(); it++) {
        IspisiRijec(*it);
        std::cout << " ";
    }
}

void IspisiIndeksPojmova(const std::map<std::string, std::set<std::tuple<std::string, int, int>>> &indekspojmova)
{
    std::cout << std::endl << "Kreirani indeks pojmova:" << std::endl;
    for(auto it(indekspojmova.begin()); it!=indekspojmova.end(); it++) {
        std::cout << it->first << ": ";
        IspisiIndeks(it->second);
        std::cout << std::endl;
    }
}

int main ()
{
    Knjiga knjiga;
    UnesiUKnjigu(knjiga);
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indekspojmova=KreirajIndeksPojmova(knjiga);
    IspisiIndeksPojmova(indekspojmova);
    while(true) {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try {
            auto skup=PretraziIndeksPojmova(rijec, indekspojmova);
            IspisiIndeks2(skup);
        } catch(std::logic_error p) {
            std::cout << p.what();
        }
        std::cout << std::endl;
    }
    return 0;
}
