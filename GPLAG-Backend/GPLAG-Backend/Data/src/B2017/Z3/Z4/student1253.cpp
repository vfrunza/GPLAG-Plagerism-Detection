/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <iterator>
#include <map>
#include <vector>
#include <queue>


enum class Boje
{
    Pik, Tref, Herc, Karo
};
bool PravilanZnak(std::string znak)
{
    std::vector<std::string> znakovi {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(int i=0; i<int(znakovi.size()); i++) {
        if(znak == znakovi.at(i)) {
            return true;
        }
    }
    return false;
}
bool PravilanRedoslijed(std::string s1, std::string s2)
{
    std::vector<std::string> znakovi {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int prvi(0), drugi(0);
    for(int i=0; i<int(znakovi.size()); i++) {
        if(s1 == znakovi.at(i)) prvi = i;
        if(s2 == znakovi.at(i)) drugi = i;
    }
    int razlika(prvi-drugi);
    return (razlika<0);
}

std::string NazivBoje(Boje boja)
{
    std::string povratni;
    if(boja>=Boje::Pik) {
        if(boja>=Boje::Tref) {
            if(boja>=Boje::Herc) {
                if(boja>=Boje::Karo) {
                    povratni = std::string("Karo");
                } else povratni = std::string("Herc");
            } else povratni = std::string("Tref");
        } else povratni = std::string("Pik");
    }
    return povratni;
}

bool IspravnaLista(const std::list<std::pair<Boje, std::string>> &lista)
{
    if(lista.size() > 52) return 0;
    Boje prethodna(Boje::Pik);
    std::string prethodni;
    bool promjena(1);
    bool pocetak;
    for(auto it=lista.begin(); it!=lista.end(); it++) {
        if(it->first != prethodna) promjena=true;
        if(promjena) {
            promjena = false;
            prethodna = it->first;   //boja
            pocetak = true;
        } else if(!promjena) {
            if(prethodna > it->first) return 0;
            if(pocetak) {
                pocetak = false;
                prethodni = it->second;  //znak
                if(!PravilanZnak(prethodni)) return 0;
            } else {
                if(!PravilanZnak(it->second)) return 0;
                if(!PravilanRedoslijed(prethodni, it->second)) return 0;
            }
        }
    }
    return 1;
}

bool IspravanRed(std::queue<std::pair<std::string, std::string>> red)
{
    while(!red.empty()) {
        if(!PravilanZnak(red.front().second)) return 0;
        if(red.front().first != NazivBoje(Boje::Pik) && red.front().first != NazivBoje(Boje::Tref) && red.front().first != NazivBoje(Boje::Herc) && red.front().first != NazivBoje(Boje::Karo)) {
            return 0;
        }
        red.pop();
    }
    return 1;
}

std::list<std::pair<Boje, std::string>> KreirajSpil()
{
    std::list<std::pair<Boje, std::string>> lista(52);
    auto it(lista.begin());
    Boje boja;
    for(int i=0; i<4; i++) {
        if(i==0) boja = Boje::Pik;
        else if(i==1) boja = Boje::Tref;
        else if(i==2) boja = Boje::Herc;
        else if(i==3) boja = Boje::Karo;
        std::vector<std::string> znak {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        for(int i=0; i<13; i++) {
            it->first = boja;
            it->second = znak.at(i);
            it++;
        }
        if(it==lista.end()) break;
    }
    return lista;
}


void IzbaciKarte( std::list<std::pair<Boje, std::string>> &lista, std::multimap<Boje, std::string> &m)
{
    if(!IspravnaLista(lista)) throw std::logic_error("Neispravna lista!");
    bool ima(0);
    auto it2(m.begin());
    while(it2!=m.end()) {
        ima = false;
        auto it=lista.begin();
        while(it!=lista.end()) {
            if(it->first == it2->first && it->second == it2->second) {
                it = lista.erase(it);
                ima = true;
            } else it++;
        }
        if(ima) {
            it2 = m.erase(it2);
        } else it2++;
        if( it2==m.end() ) break;
    }
}


std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &lista, short int &r, const int &b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(!IspravnaLista(lista)) throw std::logic_error("Neispravna lista!");
    int br_karte(0);
    int br_izbacenih(0);
    std::queue<std::pair<std::string, std::string>> red;

    while(br_izbacenih<b) {
        auto it=lista.begin();
        if(it==lista.end()) break;
        while(it!=lista.end() && br_izbacenih<b) {
            br_karte++;
            if(br_karte==r) {
                br_izbacenih++;
                br_karte=0;
                std::string s1(NazivBoje(it->first));
                std::string s2(it->second);
                red.push({s1, s2});
                it = lista.erase(it);
            } else it++;
        }
    }

    return red;
}


void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &lista, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>int(red.size())) throw std::range_error("Nedovoljno karata u redu!");
    if(!IspravnaLista(lista)) throw std::logic_error("Neispravna lista!");
    if(!IspravanRed(red)) throw std::logic_error("Neispravne karte!");
    int br_vracenih(0);


    while(br_vracenih<n) {
        bool ubaceno(1);
        auto it(lista.begin());
        auto temp(lista.begin());
        while(it!=lista.end() && br_vracenih<n) {
            if(NazivBoje(it->first) == red.front().first) {
                temp = it;  //da zapamtimo boju
                if(PravilanRedoslijed(it->second, red.front().second)) {
                    it++;
                    ubaceno = false;
                } else {
                    ubaceno = true;
                    lista.insert(it, {temp->first, red.front().second});
                    red.pop();
                    br_vracenih++;
                }
            } else {
                if(!ubaceno) {
                    lista.insert(it, {temp->first, red.front().second});
                    red.pop();
                    ubaceno = true;
                    br_vracenih++;
                }
                it++;
            }
        }
    }
}

int main ()
{
    try {
        std::list<std::pair<Boje, std::string>> lista;
        lista = KreirajSpil();
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        std::queue<std::pair<std::string, std::string>> red;
        red = IzbaciKarteRazbrajanjem(lista, r, b);
        std::cout<<"U spilu trenutno ima "<<int(lista.size())<<" karata, i to:";

        Boje prethodna(Boje::Pik);
        Boje boja;
        bool pocetak(1);
        for(auto it=lista.begin(); it!=lista.end(); it++) {
            boja = it->first;
            if(boja!=prethodna || pocetak) {
                pocetak = false;
                prethodna = boja;
                std::cout<<"\n"<<NazivBoje(boja)<<": ";
            }
            std::cout<<it->second<<" ";
        }

        std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(lista, red, n);
        std::cout<<"U spilu trenutno ima "<<int(lista.size())<<" karata, i to:";
        prethodna = Boje::Pik;
        pocetak = true;
        for(auto it=lista.begin(); it!=lista.end(); it++) {
            boja = it->first;
            if(boja!=prethodna || pocetak) {
                pocetak = false;
                prethodna = boja;
                std::cout<<"\n"<<NazivBoje(boja)<<": ";
            }
            std::cout<<it->second<<" ";
        }
        
    } catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch(std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
    return 0;
}