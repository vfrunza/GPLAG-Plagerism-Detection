#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

typedef std::map<std::string, std::vector<std:: string>> Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string,int,int>>> Index;
typedef std::set<std::tuple<std::string,int, int>> SkupPozicija;

void LowerCaseFun (std::string &capslock)
{
    for (int i(0); i<capslock.size(); i++) {
        if (capslock.at(i)>='A' && capslock.at(i)<='Z') capslock.at(i)+='a'-'A';
    }
}

bool DaLiJeTacka (const std::string &x)
{
    if (x==".") return true;
    return false;
}

bool PocetakRijeci (const char &x)
{
    if ((x>='A' && x<='Z') || (x>='a' && x<='z')  || (x>='0' && x<='9')) return true;
    return false;
}

int VratiVel (const std::string &str)
{
    int Velicina(0);

    for (int i(0); i<str.size(); i++) {
        if (PocetakRijeci(str[i])) Velicina++;
        else break;
    }
    return Velicina;
}


Index KreirajIndeksPojmova ( Knjiga &bok)
{
    Index izlazni;

    for (auto it=bok.begin(); it!=bok.end(); it++) {

        auto pitB(it->second.begin()), pitE(it->second.end());
        int brojach_stranica(0);
        while (pitB!=pitE) {
            std::string V= *pitB;
            LowerCaseFun(V);
            int VEL(V.size());
            ++brojach_stranica;
            for (int i(0); i<VEL; i++) {

                if (PocetakRijeci(V[i])) {
                    std::string zaf= V.substr (i, (V.size()-i));
                    int velicina=VratiVel(zaf);
                    std::string u_str= V.substr (i, velicina);
                    std::tuple<std::string,int ,int> pomocni= std::make_tuple (it->first, brojach_stranica ,i );
                    izlazni[u_str].insert(pomocni);
                    i+=velicina;
                }
            }
            pitB++;
        }
    }
    return izlazni;
}

void IspisiIndeksPojmova (const Index &Mapa)
{
    for (auto it=Mapa.begin(); it!=Mapa.end(); it++) {
        auto lista(it->second);
        std::cout<<it->first<<": ";
        int size(0), i(0);

        for (auto x: lista) {
            size=lista.size();
            if (i==size-1 || size==1) {
                std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
                break;
            }
            std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<", ";
            i++;
        }
        std::cout<<std::endl;
    }
}

SkupPozicija PretraziIndeksPojmova ( std::string Trazi, Index Pojmova)
{
    if (!Pojmova.count(Trazi)) throw std::logic_error("Unesena rijec nije nadjena!");

    auto it (Pojmova.find(Trazi));
    SkupPozicija Nadjeno= it->second;

    return Nadjeno;
}

int main ()
{
    Knjiga Unos;
    std::string KP;
    for (;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline (std::cin, KP);

        if (DaLiJeTacka(KP)) break;
        std::vector<std::string> Stranica;
        for (int i(1); ; i++) {

            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::string KPA;
            std::getline (std::cin, KPA);


            if (DaLiJeTacka(KPA)) {
                Unos[KP]=Stranica;
                break;
            } else {
                Stranica.push_back (KPA);
            }
        }
    }

    std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova: "<<std::endl;
    auto xer ( KreirajIndeksPojmova (Unos));
    IspisiIndeksPojmova (xer);
    while (1) {
        std::string trazi;
        int i(0);
        std::cout<<"Unesite rijec: ";
        std::getline (std::cin, trazi);
        if (DaLiJeTacka(trazi)) break;
        try {

            auto ee( PretraziIndeksPojmova(trazi, xer));
            int size= ee.size();
            for (auto x:ee) {
                if (i==size-1 || size==1) {
                    std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
                    break;
                }
                std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<" ";
                i++;
            }

        } catch (std::logic_error a) {
            std::cout<<a.what();

        }
        std::cout<<std::endl;
    }
    return 0;
}
