/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string,int,int>>> Indeks_pojmova;

bool NijeSLovoNiCifra(char c)
{
    return (!((std::tolower(c)>='a' && std::tolower(c)<='z') || (c>='0' && c<='9')));
}

Indeks_pojmova KreirajIndeksPojmova(Knjiga k)
{
    Indeks_pojmova a;
    for(auto it=k.begin(); it!=k.end(); it++) {
        int str(0);
        for(auto br_stranice=0; br_stranice<it->second.size(); br_stranice++) {
            str++;
            std::string stranica=it->second.at(br_stranice);
            std::vector<std::string> rijeci;
            int neslovo(0);
            std::string rijec=std::string();
            for(int i=0; i<stranica.size(); i++) {
                if(NijeSLovoNiCifra(stranica.at(i))) {
                    neslovo=0;
                } else if(neslovo==0) {
                    int pocetak=i;
                    while(i<stranica.size() && !NijeSLovoNiCifra(stranica.at(i))) {
                        rijec.push_back(tolower(stranica.at(i)));
                        i++;
                    }
                    a[rijec].insert(std::make_tuple(it->first,str,pocetak));
                    rijec=std::string();
                    neslovo=1;
                    i--;
                }
            }
        }
    }
    return a;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec, Indeks_pojmova p)
{
    std::string s;
    for(int i=0;i<rijec.size();i++) s.push_back(std::tolower(rijec.at(i)));
    if(!p.count(s)) throw std::logic_error("Pojam nije nadjen");
    return p[s];
}

void Ispisi(std::set<std::tuple<std::string,int,int>> s)
{
    for(auto skup=s.begin(); skup!=s.end(); skup++)
        std::cout<<std::get<0>(*skup)<<"/"<<std::get<1>(*skup)<<"/"<<std::get<2>(*skup)<<" ";
    std::cout<<std::endl;
}

void IspisiJednog(std::set<std::tuple<std::string,int,int>> s)
{
    for(auto skup=s.begin(); skup!=s.end(); skup++) {
        std::cout<<std::get<0>(*skup)<<"/"<<std::get<1>(*skup)<<"/"<<std::get<2>(*skup);
        auto sljedeci=skup;
        sljedeci++;
        if(sljedeci!=s.end()) std::cout<<", ";
    }
    std::cout<<std::endl;
}

void IspisiIndeksPojmova(Indeks_pojmova p)
{
    for(auto it=p.begin(); it!=p.end(); it++) {
        std::cout<<it->first<<": ";
        IspisiJednog(it->second);
    }
}

int main ()
{
    Knjiga k;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline(std::cin,poglavlje);
        if(poglavlje==".") break;
        int brojac(0);
        std::vector<std::string> vektor_stranica;
        for(;;) {
            brojac++;
            std::cout<<"Unesite sadrzaj stranice "<<brojac<<": ";
            std::string sadrzaj_str;
            std::getline(std::cin,sadrzaj_str);
            if(sadrzaj_str==".") break;
            vektor_stranica.push_back(sadrzaj_str);
        }
        k[poglavlje]=vektor_stranica;
    }
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    auto a=KreirajIndeksPojmova((k));
    IspisiIndeksPojmova(a);
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string r;
        std::getline(std::cin,r);
        if(r==".") break;
        try {

            Ispisi(PretraziIndeksPojmova(r,a));
        } catch(std::logic_error e) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }

    return 0;
}
