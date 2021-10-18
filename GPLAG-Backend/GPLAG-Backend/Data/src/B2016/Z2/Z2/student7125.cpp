// B 16/17, Zadaća 2, Zadatak 2
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::deque<std::deque<int>>> kontri;
typedef std::deque<std::deque<int>> kontdva;
typedef std::deque<int> kont;

enum class SmjerKretanja
{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore, LijevoDesno,DesnoLijevo
};
template <typename T>
auto IzdvojiDijagonale3D(T kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type;
template <typename T>
void Resize(T &kont, unsigned int n, unsigned int m);
template <typename T>
int Pogresanformat(T &kont);

int main ()
{
    std::cout<< "Unesite dimenzije (x y z): ";
    int x, y ,z;
    std::cin >> x>>y>>z;
    if(x < 0 || y < 0 || z < 0) {
        std::cout <<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout<<"Unesite elemente kontejnera: ";

    kontri kontejner(x,kontdva(y,kont(z)));

    for(int i(0); i < x; i++)
        for(int j(0); j < y; j++)
            for(int k(0); k < z; k++)
                std::cin >> kontejner.at(i).at(j).at(k);
    int smjer;

    std::cout<<std::endl<<"Unesite smjer kretanja [0 - 5]: ";
    std::cin >> smjer;
    if(smjer < 0 || smjer > 5) {
        std::cout<<"Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }

    try {
        auto kontejner2(IzdvojiDijagonale3D(kontejner,SmjerKretanja(smjer)));
        switch(smjer) {
        case 0:
            std::cout<< "NaprijedNazad: "<<std::endl;
            break;
        case 1:
            std::cout<< "NazadNaprijed: "<<std::endl;
            break;
        case 2:
            std::cout<< "GoreDolje: "<<std::endl;
            break;
        case 3:
            std::cout<< "DoljeGore: "<<std::endl;
            break;
        case 4:
            std::cout<< "LijevoDesno: "<<std::endl;
            break;
        case 5:
            std::cout<< "DesnoLijevo: "<<std::endl;
            break;
        }
        for(auto &i : kontejner2) {
            for(auto &j : i)
                std::cout <<std::setw(4)<< j;
            std::cout<<std::endl;
        }
    } catch(std::domain_error error) {
        std::cout <<  error.what();
    }

    return 0;
}
template <typename T>
void Resize(T &kont, unsigned int n, unsigned int m)
{
    //mjenjamo veličinu kont na onu koja nam treba
    for(int i(0); i < m; i++) {
        kont.push_back(typename std::remove_reference<decltype(kont.at(0))>::type(n));
    }
}
template <typename T>
int Pogresanformat(T &kont)
{

    //ako redovi nemaju isti broj elemanata vrati 0
    for(int i(0); i < kont.size(); i++)
        for(int j(0); j < kont[i].size(); j++)
            if(kont.at(0).at(0).size() != kont.at(i).at(j).size())
                return 0;


    //ako plohe nisu iste veličine vrati -1
    for(int i(0); i < kont.size(); i++)
        if(kont.at(0).size() != kont.at(i).size())
            return -1;



    return 1;
}

template <typename T>
auto IzdvojiDijagonale3D(T kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    typename std::remove_reference<decltype(kont.at(0))>::type izlaz;
    bool nijepromjenjenavelicina(true);

    //testiraj i eventualno baci izuzetak
    if(!Pogresanformat(kont))  throw std::domain_error("Redovi nemaju isti broj elemenata");
    else if(Pogresanformat(kont) == -1) throw std::domain_error("Plohe nemaju isti broj redova");

//Za neke smjerove dodaje u obrnutom smjeru da bi dobili ispravan redoslijed elemenata
    for(int i(0); i < kont.size(); i++)
        for(int j(0); j < kont.at(0).size(); j++)
            for(int k(0); k < kont.at(0).at(0).size(); k++)
                if(smjer == SmjerKretanja::NaprijedNazad) {
                    if(j == k) {
                        if(nijepromjenjenavelicina) {
                            if(kont.at(0).at(0).size() >= kont.at(0).size()) {  //uslov za dodavanje elementa nekog
                                Resize(izlaz,kont.at(0).size(),kont.size());
                                nijepromjenjenavelicina = false;    //samo jednom mjenjaj veličinu
                            } else {
                                Resize(izlaz,kont.at(0).at(0).size(),kont.size());  //javljaju se anomalije kada je y > z, ovo ih ispravlja
                                nijepromjenjenavelicina = false;
                            }
                        }


                        izlaz.at(i).at(j) = kont.at(i).at(j).at(k); //dodaj elemente koji ispunjavaju uslov
                    }
                } else if (smjer == SmjerKretanja::NazadNaprijed) {
                    if(j == kont.at(0).at(0).size()-1-k) {  //uslov za dodavanje elementa nekog
                        if(nijepromjenjenavelicina) { 
                            if(kont.at(0).at(0).size() >= kont.at(0).size()) {
                                Resize(izlaz,kont.at(0).size(),kont.size());
                                nijepromjenjenavelicina = false;
                            } else {
                                Resize(izlaz,kont.at(0).at(0).size(),kont.size()); //javljaju se anomalije kada je y > z, ovo ih ispravlja
                                nijepromjenjenavelicina = false;
                            }
                        }

                        izlaz.at(kont.size()-1-i).at(j) = kont.at(i).at(j).at(k); //dodaj elemente koji ispunjavaju uslov

                    }
                } else if(smjer == SmjerKretanja::GoreDolje) {
                    if(k == kont.size()-1 - i) {  //uslov za dodavanje elementa nekog
                        if(nijepromjenjenavelicina) {
                            if( kont.at(0).size() >= kont.size()) {
                                Resize(izlaz,kont.size(),kont.at(0).size());
                                nijepromjenjenavelicina = false;
                            } else {
                                Resize(izlaz,kont.at(0).size(),kont.at(0).size()); //javljaju se anomalije kada je x > y, ovo ih ispravlja
                                nijepromjenjenavelicina = false;
                            }
                        }

                        izlaz.at(j).at(kont.size()-1-i) = kont.at(i).at(j).at(k); //dodaj elemente koji ispunjavaju uslov

                    }
                } else if (smjer == SmjerKretanja::DoljeGore) {
                    if(k == kont.at(0).at(0).size() - kont.size() + i) {  //uslov za dodavanje elementa nekog
                        if(nijepromjenjenavelicina) {
                            if( kont.at(0).size() >= kont.size()) {
                                Resize(izlaz,kont.size(),kont.at(0).size());
                                nijepromjenjenavelicina = false;
                            } else {
                                Resize(izlaz,kont.at(0).size(),kont.at(0).size());  //javljaju se anomalije kada je x > y, ovo ih ispravlja
                                nijepromjenjenavelicina = false;
                            }
                        }

                        izlaz.at(kont.at(0).size()-1-j).at(kont.size()-1-i) = kont.at(i).at(j).at(k); //dodaj elemente koji ispunjavaju uslov
                    }
                } else if(smjer == SmjerKretanja::LijevoDesno) {
                    if(j == kont.size()-1-i) {      //uslov za dodavanje elementa nekog
                        if(nijepromjenjenavelicina) {
                            if(kont.at(0).at(0).size() >= kont.size()) {
                                Resize(izlaz,kont.size(),kont.at(0).at(0).size());
                                nijepromjenjenavelicina = false;
                            } else {
                                Resize(izlaz,kont.at(0).size(),kont.at(0).at(0).size());    //javljaju se anomalije kada je x > z, ovo ih ispravlja
                                nijepromjenjenavelicina = false;
                            }
                        }

                        izlaz.at(k).at(kont.size()-1-i) = kont.at(i).at(j).at(k);       //dodaj elemente koji ispunjavaju uslov
                    }
                } else if (smjer == SmjerKretanja::DesnoLijevo) {
                    if(j == i) {  //uslov za dodavanje elementa nekog
                        if(nijepromjenjenavelicina) {
                            if(kont.at(0).at(0).size() >= kont.size()) {
                                Resize(izlaz,kont.size(),kont.at(0).at(0).size());
                                nijepromjenjenavelicina = false;
                            } else {
                                Resize(izlaz,kont.at(0).size(),kont.at(0).at(0).size());    //javljaju se anomalije kada je x > z, ovo ih ispravlja
                                nijepromjenjenavelicina = false;
                            }
                        }

                        izlaz.at(kont.at(0).at(0).size()-1-k).at(i) = kont.at(i).at(j).at(k); //dodaj elemente koji ispunjavaju uslov
                    }
                }
    return izlaz;
}