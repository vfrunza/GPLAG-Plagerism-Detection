/B2016/2017: Zadaća 3, Zadatak 2

#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>
#include <map>
#include <set>

char malo(char a)
{
    if(a>='A' && a<='Z')
        return a+32;
    return a;
}

bool SlovoIliCifra(char a)
{
    return ((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'));
}

std::string SveMalo(std::string rijec)
{

    for(int i=0; i<rijec.size(); i++) {
        rijec[i]=malo(rijec[i]);
    }
    return rijec;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string recenica)
{

    std::map<std::string, std::set<int>> mapa;

    for(int i=0 ; i<recenica.size() ; i++) {

        int brojac(0);
        if(SlovoIliCifra(recenica[i])) {
            int pocetak=i;
            while(i<recenica.size() && SlovoIliCifra(recenica[i])) {
                brojac++;
                i++;
            }
            std::string indeks=SveMalo(recenica.substr(pocetak, brojac));
            auto it(mapa.find(indeks));
            if(it == mapa.end()) {
                std::set<int> skup;
                skup.insert(pocetak);
                mapa.insert(std::make_pair(indeks,skup));
            } else {
                (it->second).insert(pocetak);
            }
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa)
{

    auto it(mapa.find(SveMalo(rijec)));
    if(it == mapa.end()) {
        throw std::logic_error("Pojam nije nadjen");
    } else {
        return it->second;
    }
}

void IspisiSkup(std::set<int> skup)
{

    auto it(skup.begin());
    if(it==skup.end()) {
        return;
    } else {
        std::cout<<*it;
        it++;
        while(it!=skup.end()) {
            std::cout<<","<<*it;
            it++;
        }
    }
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa)
{

    auto it(mapa.begin());

    while(it!=mapa.end()) {

        std::cout<<it->first<<": ";

        IspisiSkup(it->second);
        std::cout<<std::endl;

        it++;
    }
}

int main ()
{

    /*std::string recenica;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, recenica);

    auto mapa=KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(mapa);

    std::string rijec;
    for( ;  ; ) {
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") {
            break;
        } else {
            try {
                auto skup=PretraziIndeksPojmova(rijec,mapa);
                auto it=skup.begin();
                while(it!=skup.end()) {
                    std::cout<<*it<<" ";
                    it++;
                }
                std::cout<<std::endl;
            }

            catch(std::logic_error izuzetak) {
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
        }
    }*/

    return 0;
}
