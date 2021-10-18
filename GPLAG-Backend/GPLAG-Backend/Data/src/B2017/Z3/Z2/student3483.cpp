/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <tuple>
#include <set>
#include <vector>
#include <string>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Mapa;

Mapa KreirajIndeksPojmova(Knjiga knjiga)
{
    Mapa mapa;
    std::set<std::tuple<std::string, int, int>> oznake;

    int pocetak(0), kraj(0);
    std::string rijec;
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++) {
        for(int i=0; i<(it->second).size(); i++) {
            for(int j=0; j<(it->second)[i].size(); j++) {
                while((it->second)[i][j]==' ') j++;
                pocetak=j;
                while((it->second)[i][j]!=' ' && j<(it->second)[i].size()) j++;
                kraj=j;

                rijec=(it->second)[i].substr(pocetak,kraj-pocetak);
                if(!mapa.count(rijec)) {
                    std::tuple<std::string, int, int> t(it->first,i,pocetak);
                    oznake.insert(t);

                    int pocetak1, kraj1;
                    std::string rijec1;
                    for(int k=0; k<(it->second)[i].size(); k++) {
                        while((it->second)[i][k]==' ') k++;
                        pocetak1=k;
                        while((it->second)[i][k]!=' ' && k<(it->second)[i].size()) k++;
                        kraj1=k;

                        rijec1=(it->second)[i].substr(pocetak1,kraj1-pocetak1);
                        if(rijec1==rijec) {
                            std::tuple<std::string, int, int> t1(it->first,i,pocetak1);
                            oznake.insert(t1);
                        }
                        k--;
                    }

                    mapa.insert({rijec,oznake});

                    j--;
                }
            }
        }
    }

    return mapa;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, Mapa mapa)
{
    if(mapa.find(rijec)==mapa.end()) throw std::logic_error("Pojam nije naden");
    auto it(mapa.find(rijec));

    return it->second;
}

void IspisiIndeksPojmova(Mapa pojmovi)
{
    for(auto it(pojmovi.begin()); it!=pojmovi.end(); it++) {
        std::cout << it->first << ": ";
        auto it1(it->second);
        auto pocetak(it1.begin());
        auto kraj(it1.end());
        auto prije_kraja=--it1.end();

        for(auto it2=pocetak; it2!=kraj; it2++) {
            if(it2!=prije_kraja) std::cout << std::get<0>(*it2) << "//" << std::get<1>(*it2) << "//" << std::get<2>(*it2) << ", ";
            else std::cout << std::get<0>(*it2) << "//" << std::get<1>(*it2) << "//" << std::get<2>(*it2) << std::endl;
        }

    }
}

int main ()
{
    Knjiga knjiga;
    std::string pogl;
    std::string poglavlje;
    std::vector<std::string> stranica;
    do {
        std::cout << "Unesite naziv poglavlja: ";
        std::cin >> pogl;
        poglavlje=pogl;
        std::cin.clear();
        std::cin.ignore(1000000,'\n');

        int i(0);
        std::string sadrzaj;
        do {
            std::cout << "Unesite sadrzaj stranice " << i+1 << ": ";
            std::getline(std::cin,sadrzaj);
            i++;
            stranica.resize(i);
            stranica[i-1]=sadrzaj;
        } while(sadrzaj!=".");
        
        knjiga.insert({poglavlje,stranica});
    } while(poglavlje!=".");
    
    Mapa indeks_pojmova(KreirajIndeksPojmova(knjiga));
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(indeks_pojmova);
    
    return 0;
}

