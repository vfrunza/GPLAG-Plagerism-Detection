/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <stdexcept>
#include <queue>
#include <algorithm>

enum class Boje
{
    Pik,Tref,Herc,Karo
};

const std::vector<std::string> Karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

void IspisiSpil(std::list<std::pair<Boje,std::string>> &KreiraniSpil){
        std::cout << "U spilu trenutno ima " << KreiraniSpil.size() << " karata, i to:" << std::endl;
        std::cout << "Pik: ";
        for(auto it=KreiraniSpil.begin(); it!=KreiraniSpil.end(); it++) if(it->first==Boje::Pik) std::cout << it->second << " ";
        std::cout << std::endl;

        std::cout << "Tref: ";
        for(auto it=KreiraniSpil.begin(); it!=KreiraniSpil.end(); it++) if(it->first==Boje::Tref) std::cout << it->second << " ";
        std::cout << std::endl;

        std::cout << "Herc: ";
        for(auto it=KreiraniSpil.begin(); it!=KreiraniSpil.end(); it++) if(it->first==Boje::Herc) std::cout << it->second << " ";
        std::cout << std::endl;

        std::cout << "Karo: ";
        for(auto it=KreiraniSpil.begin(); it!=KreiraniSpil.end(); it++) if(it->first==Boje::Karo) std::cout << it->second << " ";
        std::cout << std::endl;
}

void PredSortiranje(std::list<std::pair<Boje,std::string>> &RefNaSpil){
    
    for(auto it=RefNaSpil.begin();it!=RefNaSpil.end();it++){
        if(it->second==std::string("10")) it->second=std::string("B");
        if(it->second==std::string("J")) it->second=std::string("C");
        if(it->second==std::string("Q")) it->second=std::string("D");
        if(it->second==std::string("K")) it->second=std::string("E");
        if(it->second==std::string("A")) it->second=std::string("F");
        
    }
}

void VratiNaPravaImena(std::list<std::pair<Boje,std::string>> &RefNaSpil){
    for(auto it=RefNaSpil.begin();it!=RefNaSpil.end();it++){
    if(it->second==std::string("B")) it->second=std::string("10");
        if(it->second==std::string("C")) it->second=std::string("J");
        if(it->second==std::string("D")) it->second=std::string("Q");
        if(it->second==std::string("E")) it->second=std::string("K");
        if(it->second==std::string("F")) it->second=std::string("A");
    }
}

std::list<std::pair<Boje,std::string>> KreirajSpil()
{

    std::list<std::pair<Boje,std::string>> Spil(52);

    for(auto it=Spil.begin(); it!=Spil.end();) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<13; j++) {
                it->first=Boje(i);
                it->second=Karte[j];
                it++;
            }
        }
    }

    return Spil;
}

void IzbaciKarte(std::list<std::pair<Boje,std::string>> &RefNaSpil,std::multimap<Boje,std::string> &RefNaMMapu)
{

    if(RefNaSpil.size()<0 || RefNaSpil.size()>52) throw std::logic_error("Neispravna lista!");

    try {

        for(auto its=RefNaSpil.begin(); its!=RefNaSpil.end(); its++) {

            for(auto itm=RefNaMMapu.begin(); itm!=RefNaMMapu.end();) {
                if((itm->first==its->first) && (itm->second==its->second)) {

                    while(itm!=RefNaMMapu.end()) {
                        if((itm->first==its->first)&&(itm->second==its->second))
                            itm=RefNaMMapu.erase(itm);
                        else itm++;
                    }
                    its=RefNaSpil.erase(its);
                }

                else itm++;
            }
        }

    } catch (...) {
        throw std::logic_error("Neispravna lista!");
    }


}

std::queue<std::pair<Boje,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &RefNaSpil, const short int &r, const int &b)
{

    std::queue<std::pair<Boje,std::string>> PovratniRed;
    if(r<1 || r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");

    auto it=RefNaSpil.begin();
    int brojac1(0),brojac2(0);

    for(;;) { //Izbacivanje karata iz ŠPILA razbrajanjem
        if(it==RefNaSpil.end()) it=RefNaSpil.begin();
        // brojac1++;

        if(brojac1==r-1) {
            PovratniRed.push({it->first,it->second});
            it=RefNaSpil.erase(it);
            brojac1=0;
            brojac2++;
        }

        brojac1++;
        if(brojac2==b) break;
        it++;
    }

    return PovratniRed;
}

void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &RefNaSpil, std::queue<std::pair<Boje,std::string>> &RefNaRed, int n)
{
    
    if(n<0) throw std::logic_error("Broj n je besmislen!");
    if(n>RefNaRed.size()) throw std::range_error("Nedovoljno karata u redu!");
    
    while(n!=0){
        RefNaSpil.push_back(RefNaRed.front());
        RefNaRed.pop();
        n--;
    }
    
    PredSortiranje(RefNaSpil);
    RefNaSpil.sort();
    VratiNaPravaImena(RefNaSpil);
    

}

int main ()
{
    try {
        auto KreiraniSpil(KreirajSpil());

        int KorakRazbrajanja, KarteZaIzbacivanje;
        std::cout << "Unesite korak razbrajanja: " ;
        std::cin >> KorakRazbrajanja;
        std::cout << "Unesite broj karata koje zelite izbaciti: " ;
        std::cin >> KarteZaIzbacivanje;

        auto RedIzbacenihKarata = IzbaciKarteRazbrajanjem(KreiraniSpil,KorakRazbrajanja,KarteZaIzbacivanje);
        
        IspisiSpil(KreiraniSpil);

        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int BrojVracenihKarata;
        std::cin >> BrojVracenihKarata;
        
        VratiPrvihNKarata(KreiraniSpil,RedIzbacenihKarata,BrojVracenihKarata);
        
        IspisiSpil(KreiraniSpil);
        
    } catch (std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() ;
        return 0;
    } catch (std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() ;
        return 0;
    }
    return 0;
}
