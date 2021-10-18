/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include<queue>
#include <stdexcept>
#include <algorithm>
#include <iterator>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

std::vector<std::string> karte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

std::list<std::pair<Boje,std::string>> KreirajSpil()
{
    std::list<std::pair<Boje,std::string>> a;
    std::pair<Boje,std::string> par;
    Boje x;
    std::string s;
    for(int i=0; i<4; i++) {
        if(i==0) x=Boje::Pik;
        else if(i==1) x=Boje::Tref;
        else if(i==2) x=Boje::Herc;
        else x=Boje::Karo;

        for(int i=2; i<=10; i++) {
            par.first=x;
            s=std::to_string(i);
            par.second=s;
            a.push_back(par);
        }
        par.first=x;
        par.second="J";
        a.push_back(par);
        par.first=x;
        par.second="Q";
        a.push_back(par);
        par.first=x;
        par.second="K";
        a.push_back(par);
        par.first=x;
        par.second="A";
        a.push_back(par);
    }
    return a;
}

void IzbaciKarte(std::list<std::pair<Boje,std::string>> &lista, std::multimap<Boje,std::string> &multimapa)
{
    if(lista.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it=multimapa.begin(); it!=multimapa.end(); it++) {
        for(auto it1=lista.begin(); it1!=lista.end(); it1++) {
            if(it->first==it1->first) {
                it1=lista.erase(it1);
                it=multimapa.erase(it);
            }
        }
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &lista,short int &r, int b)
{
    std::queue<std::pair<std::string, std::string>> red;

    if(r<1 || r>52 || b<1 || lista.size()>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    auto it=lista.begin();
    std::pair<std::string,std::string>par;

    for(int i=0; i<b; i++) {
        for(int j=0; j<r-1; j++) {
            it++;
            if(it==lista.end()) it=lista.begin();
        }

        if(it->first==Boje::Pik) par.first="Pik";
        else if(it->first==Boje::Tref) par.first="Tref";
        else if(it->first==Boje::Karo) par.first="Karo";
        else par.first="Herc";
        par.second=it->second;
        red.push(par);
        it=lista.erase(it);
    }

    return red;
}

void VratiPrvihNKarata (std::list<std::pair<Boje,std::string>> &lista, std::queue<std::pair<std::string,std::string>> &red, int n)
{

    int r=red.size();
    if(n>r) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(lista.size()>52) throw std::logic_error("Neispravna lista!");

    std::pair<std::string,std::string> par;
    std::pair<Boje,std::string>ParListe;
    for(int i=0; i<n; i++) {
        par=red.front();
        red.pop();
        if(par.first=="Pik") ParListe.first=Boje::Pik;
        else if(par.first=="Tref")ParListe.first=Boje::Tref;
        else if(par.first=="Herc")ParListe.first=Boje::Herc;
        else if(par.first=="Karo") ParListe.first=Boje::Karo;
        ParListe.second=par.second;
        lista.push_back(ParListe);
        
    }


   lista.sort( [](std::pair<Boje,std::string> par1, std::pair<Boje,std::string> par2) {
        if(par1.first<par2.first) return true;
        else if(par1.first==par2.first) {
            int p1,p2;
            for(p1=0; p1<13; p1++) if(karte[p1]==par1.second) break;
            for(p2=0; p2<13; p2++) if(karte[p2]==par2.second) break;
            if(p1<p2) return true;
            else return false;
        }
        return false;
    });
}

void Ispis(std::list<std::pair<Boje,std::string>> &lista)
{
    auto it=lista.begin();
    std::cout<<"Pik: ";

    while(it->first==Boje::Pik) {
        std::cout<<it->second<<" ";
        it++;
    } 

    std::cout<<std::endl<<"Tref: ";
    while(it->first==Boje::Tref){
        std::cout<<it->second<<" ";
        it++;
    } 

    std::cout<<std::endl<<"Herc: ";
    while(it->first==Boje::Herc){
        std::cout<<it->second<<" ";
        it++;
    } 

    std::cout<<std::endl<<"Karo: ";
    while(it->first==Boje::Karo) {
        std::cout<<it->second<<" ";
        it++;
    } 
    std::cout<<std::endl;
}

int main ()
{
    try {
        std::list<std::pair<Boje,std::string>> spil;
        spil=KreirajSpil();
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        int b;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        std::queue<std::pair<std::string,std::string>> red(IzbaciKarteRazbrajanjem(spil,r,b));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        Ispis(spil);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(spil,red,n);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        Ispis(spil);

    }

    catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }

    catch(std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
   
    catch(std::domain_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    
    return 0;
}
