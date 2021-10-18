/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <list>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <deque>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

enum class Boje {Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje, std::string>> lista;

lista KreirajSpil() {
    lista rez;
    std::string temp;
    for(auto i=0; i<4; i++) {
        for(int j=2; j<=14; j++) {
            if(j>10 && j<=14) {
                if(j==11) temp='J';
                if(j==12) temp='Q';
                if(j==13) temp='K';
                if(j==14) temp='A';
            } else {
                temp=std::to_string(j);
            }
            rez.push_back(std::make_pair(Boje(i), temp));
        }
    }
    return rez;
}
void IzbaciKarte(lista &parovi, std::multimap<Boje, std::string> &mapa) {
    std::multimap<Boje, std::string>::iterator it;
    std::list<std::pair<Boje, std::string>>::iterator it1(parovi.begin());
    while(it1!=parovi.end()) {
        it=mapa.begin();
        while(it!=mapa.end()) {
            if((*it).first==(*it1).first) {
                if((*it).second==(*it1).second) {
                    parovi.erase(it1++);
                    break;
                } else it++;
            } else it++;
        }
        it1++;
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(lista &parovi, const short int &broj, int &b) {
    if(broj<1 || broj>52 || b<1 || parovi.size()>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<std::string, std::string>> red;
    int tempbroj=0;
    int tempb=0;
    std::list<std::pair<Boje, std::string>>::iterator it(parovi.begin());
    //std::list<std::pair<Boje, std::string>>::iterator baza(parovi.begin());
    while(1) {
        if(tempb==b) break;
        if(parovi.empty()) break;
        tempbroj++;
        if(tempbroj==broj) {
            int i=int(Boje((*it).first));
            std::string temp=std::to_string(i);
            std::string temp1=(*it).second;
            red.push(std::make_pair(temp, temp1));
            it=parovi.erase(it);
            tempb++;
            tempbroj=0;
        } else it++;
        if(it==parovi.end()) it=parovi.begin();
    }
    return red;
}


void VratiPrvihNKarata(lista &parovi, std::queue<std::pair<std::string, std::string>> red, int n) {
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
        
}

int main() {
    try {
        lista rez=KreirajSpil();
        std::list<std::pair<Boje, std::string>>::iterator it1;
        std::cout << "Unesite korak razbrajanja: ";
        short int korak;
        std::cin >> korak;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        int broj;
        std::cin >> broj;
        std::queue<std::pair<std::string, std::string>>rez1=IzbaciKarteRazbrajanjem(rez, korak, broj);
        std::cout << "U spilu trenutno ima " << 52-broj << " karata, i to: " << std::endl;
        
        //if(rez.size()>-1 && rez.size()<53) {
            std::cout << "Pik: ";
            for(auto it=rez.begin(); it != rez.end(); it++) {
                if((*it).first==Boje::Pik) {
                    std::cout << (*it).second << " ";
                }
            }
        
            std::cout << std::endl;
            std::cout << "Tref: ";
            for(auto it=rez.begin(); it != rez.end(); it++) {
                if((*it).first==Boje::Tref) {
                    std::cout << (*it).second << " ";
                }
            }
        
            std::cout << std::endl;
            std::cout << "Herc: ";
            for(auto it=rez.begin(); it != rez.end(); it++) {
                if((*it).first==Boje::Herc) {
                    std::cout << (*it).second << " ";
                }
            }
            
            std::cout << std::endl;
            std::cout << "Karo: ";
            for(auto it=rez.begin(); it != rez.end(); it++) {
                if((*it).first==Boje::Karo) {
                    std::cout << (*it).second << " ";
                }
            }
       // }
        /*std::cout << std::endl;
        for(auto it=rez1.begin(); it!=rez1.end(); it++) {
            std::cout << (*it).sec << " ";
        }
        std::cout << std::endl;*/
        std::cout << std::endl;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int vrati;
        std::cin >> vrati;
        VratiPrvihNKarata(rez, rez1, vrati);
        std::cout << "U spilu trenutno ima " << 52-broj+vrati << " karata, i to: " << std::endl;
        //VratiPrvihNKarata(rez, rez1, vrati);
        std::cout << "Pik: ";
        for(auto it=rez.begin(); it != rez.end(); it++) {
            if((*it).first==Boje::Pik) {
                std::cout << (*it).second << " ";
            }
        }
        
        std::cout << std::endl;
        std::cout << "Tref: ";
        for(auto it=rez.begin(); it != rez.end(); it++) {
            if((*it).first==Boje::Tref) {
                std::cout << (*it).second << " ";
            }
        }
        
        std::cout << std::endl;
        std::cout << "Herc: ";
        for(auto it=rez.begin(); it != rez.end(); it++) {
            if((*it).first==Boje::Herc) {
                std::cout << (*it).second << " ";
            }
        }
        
        std::cout << std::endl;
        std::cout << "Karo: ";
        for(auto it=rez.begin(); it != rez.end(); it++) {
            if((*it).first==Boje::Karo) {
                std::cout << (*it).second << " ";
            }
        }
    }catch(std::domain_error jedan) {
        std::cout << "Izuzetak: " << jedan.what() << std::endl;
    }catch(std::range_error dva) {
        std::cout << "Izuzetak: " << dva.what() << std::endl;
    }catch(std::logic_error tri) {
        std::cout << "Izuzetak: " << tri.what() << std::endl;
    }
    
return 0;
}

//KreirajSpil, IzbaciKarte, IzbaciKarteRazbrajanjem i VratiPrvihNKarata. 