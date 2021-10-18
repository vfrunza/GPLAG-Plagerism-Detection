/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <utility>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stdexcept>

enum class Boje
{
    Pik, Tref, Herc, Karo
};
std::string Nazivi[] {"2","3", "4", "5","6","7", "8", "9", "10", "J", "Q", "K", "A"};
typedef std::list<std::pair<Boje, std::string>> Spil;
bool kriterij(std::pair<Boje, std::string> prvi, std::pair<Boje, std::string> drugi)
{
    if(prvi.first!=drugi.first) return prvi.first<drugi.first;
    int poz1(0),poz2(0);
    for(int i=0; i<13; i++) {
        if(prvi.second==Nazivi[i]) poz1=i;
        if(drugi.second==Nazivi[i]) poz2=i;
    }
    return poz1<poz2;
}
std::list<std::pair<Boje, std::string>>sortirano(Spil karte)
{
    karte.sort(kriterij);
    return karte;
}
Spil KreirajSpil()
{
    Spil kreirani;

    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) kreirani.push_back(std::make_pair(Boje(i), Nazivi[j]));
    }
    return kreirani;
}
void izuzetak(std::pair<Boje, std::string> prvi)
{
    bool nadjeno(false),nadjeno2(false);
    for(int i=0; i<4; i++) if(Boje(i)==prvi.first) nadjeno=true;
    for(int i=0; i<13; i++) if(Nazivi[i]==prvi.second) nadjeno2=true;
    if(!(nadjeno &&nadjeno2)) throw std::logic_error("Izuzetak");
}

void provjera(Spil & karte)
{
    if(!std::equal(karte.begin(), karte.end(), sortirano(karte).begin()) || karte.size()>52) throw std::logic_error("Neispravna lista!");
    try {
        std::for_each(karte.begin(), karte.end(), izuzetak);
    } catch(...) {
        throw std::logic_error("Neispravna lista!");
    }
}

void IzbaciKarte(Spil &karte, std::multimap<Boje, std::string>& mapa)
{
    provjera(karte);
    bool poc(false);
     auto it=mapa.begin();
   do {
        if(poc) it=mapa.begin();
        poc=false;
      if(mapa.empty()) return;
       auto pokazivac(std::find(karte.begin(), karte.end(), std::make_pair(it->first, it->second)));
       if(pokazivac!=karte.end()) {
             auto pok(it);
                if(it!=mapa.begin()) pok--;
                
                else poc=true;
                mapa.erase(it);
                it=pok;
                karte.erase(pokazivac);
           
       } else it++;
   } while( it!=mapa.end());         
           
            }

std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(Spil & karte, const short int & r,const  int & b)
{
    if(r<1 || r>52 || b<1) throw std:: logic_error("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<Boje, std::string>> red ;
    provjera(karte);

    int broj_izbacenih(0);
    auto it=karte.begin();
    int predjeno(1);
    bool pocetak(false);
    while(broj_izbacenih<b && karte.size()>0) {
        pocetak=false;
        while(predjeno<r) {
            if(it==karte.end()) it=karte.begin();
            it++;
            predjeno++;
        }
        predjeno=0;
        if(it==karte.end()) it=karte.begin();
        auto pozicija=it;
        if(pozicija!=karte.begin())    pozicija--;
        else pocetak=true;
        red.push(*it);
        karte.erase(it);
        if(pocetak) it=karte.begin();
        else it=pozicija;


        broj_izbacenih++;

    }
    return red;
}
void VratiPrvihNKarata(Spil &karte, std::queue<std::pair<Boje, std::string>>&red, int n)
{
    int s(red.size());
    if(n>s) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    for(int i=0; i<red.size(); i++) {
        bool nadjeno1(false),nadjeno2(false);
        std::pair<Boje, std::string> pomocni(red.front());
        for(int j=0; j<4; j++) if(pomocni.first==Boje(j)) nadjeno1=true;
        for(int k=0; k<13; k++)
            if(pomocni.second==Nazivi[k]) nadjeno2=true;
        if(!(nadjeno2 && nadjeno1)) throw std::logic_error("Neispravne karte");
        red.pop();
        red.push(pomocni);

    }
    provjera(karte);
    int broj_ubacenih(0);
    while(broj_ubacenih<n) {
        if(std::find(karte.begin(),karte.end(),red.front())==karte.end())  {
            karte.insert(karte.end(), red.front());
            broj_ubacenih++;
        }
        red.pop();

    }
    karte=sortirano(karte);

}
void Ispisi(Spil karte)
{
    const char* imena[4]= {"Pik","Tref","Herc","Karo"};

    for(auto it=karte.begin(); it!=karte.end(); it++) {
        for(int i=0; i<4; i++) {
            if(it->first==Boje(i)) {
                std::cout<<imena[i]<<": ";
                while(it!=karte.end() && it->first==Boje(i)) {
                    std::cout<<it->second<<" ";
                    it++;
                }
                std::cout<<std::endl;
                it--;
            }
        }
    }
}

int main ()
{

    try {
        Spil karte(KreirajSpil());
        
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        int b;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        std::queue<std::pair<Boje, std::string>> red (IzbaciKarteRazbrajanjem(karte, r,b));
        std::cout<<"U spilu trenutno ima "<<karte.size()<<" karata, i to: "<<std::endl;
        Ispisi(karte);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>b;
        VratiPrvihNKarata(karte, red, b);
        std::cout<<"U spilu trenutno ima "<<karte.size()<<" karata, i to: "<<std::endl;
        Ispisi(karte);

        
       
    }

    catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }


    catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }

    return 0;
}
