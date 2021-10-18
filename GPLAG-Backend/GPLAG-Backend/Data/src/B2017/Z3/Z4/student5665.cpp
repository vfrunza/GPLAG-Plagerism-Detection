/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <queue>
#include <algorithm>


enum class Boje {Pik, Tref, Herc, Karo};
std::vector<std::string> Naziv {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; 

typedef std::list <std::pair<Boje, std::string>> Lista;
typedef std::multimap <Boje, std::string> Multimapa;
typedef std::queue <std::pair<std::string, std::string>> Queue;


void IspisiKarte (Lista spil) {
    
    auto it=std::begin(spil);
    std::cout << "Pik: ";
    while (it!=std::end(spil) && it->first==Boje::Pik) {
        std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
    
    std::cout << "Tref: ";
    while (it!=std::end(spil) && it->first==Boje::Tref) {
        std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
    
    std::cout << "Herc: ";
    while (it!=std::end(spil) && it->first==Boje::Herc) {
        std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
    
    std::cout << "Karo: ";
    while (it!=std::end(spil) && it->first==Boje::Karo) {
        std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
}


void TestirajListu (Lista spil) {

    if (spil.size()>52) throw 0;
    
    //provjera smislenosti podataka (samo po vrijednostima)
    for (Lista::iterator it=std::begin(spil); it!=std::end(spil); it++)
        if (it->second!="2" && it->second!="3" && it->second!="4" && it->second!="5" && it->second!="6" && it->second!="7" && it->second!="8" && it->second!="9" && it->second!="10" && it->second!="J" && it->second!="Q" && it->second!="K" && it->second!="A")
            throw 0;
    
    //provjera sortiranosti
    for (Lista::iterator it=std::begin(spil); it!=--std::end(spil); it++) {
        auto sljedeci=++it; it--;
        if (it->first>(sljedeci)->first)
            throw 0;
    }
    
    auto it=std::begin(spil);
    
    while (it!=--std::end(spil) && it->first==Boje::Pik) {
        auto sljedeci=++it; it--;
        auto vectit=std::find(std::begin(Naziv), std::end(Naziv), it->second);
        auto sljvectit=std::find(std::begin(Naziv), std::end(Naziv), sljedeci->second);
        if (sljvectit<vectit) 
            throw 0;
        it++;
    }

    while (it!=--std::end(spil) && it->first==Boje::Tref) {
        auto sljedeci=++it; it--;
        auto vectit=std::find(std::begin(Naziv), std::end(Naziv), it->second);
        auto sljvectit=std::find(std::begin(Naziv), std::end(Naziv), sljedeci->second);
        if (sljvectit<vectit) 
            throw 0;
        it++;
    }

    while (it!=--std::end(spil) && it->first==Boje::Herc) {
        auto sljedeci=++it; it--;
        auto vectit=std::find(std::begin(Naziv), std::end(Naziv), it->second);
        auto sljvectit=std::find(std::begin(Naziv), std::end(Naziv), sljedeci->second);
        if (sljvectit<vectit) 
            throw 0;
        it++;
    }

    while (it!=--std::end(spil) && it->first==Boje::Karo) {
        auto sljedeci=++it; it--;
        auto vectit=std::find(std::begin(Naziv), std::end(Naziv), it->second);
        auto sljvectit=std::find(std::begin(Naziv), std::end(Naziv), sljedeci->second);
        if (sljvectit<vectit) 
            throw 0;
        it++;
    }
}


Boje StringUBoju (std::string s) {
    
    if (s=="Pik") return Boje::Pik;
    if (s=="Tref") return Boje::Tref;
    if (s=="Herc") return Boje::Herc;
    return Boje::Karo;
}

std::string BojaUString (Boje boja) {
    
    if (boja==Boje::Pik) return "Pik";
    if (boja==Boje::Tref) return "Tref";
    if (boja==Boje::Herc) return "Herc";
    return "Karo";
}

Lista KreirajSpil () {
    Lista spil;
    
    for (int i=0; i<4; i++)
        for (int j=0; j<13; j++)
            spil.push_back(std::make_pair(Boje(i), Naziv[j]));
    
    return spil;
}

void IzbaciKarte (Lista &spil, Multimapa &mapa) {
    
    try { TestirajListu(spil); }
    catch (...) {
        throw std::logic_error ("Neispravna lista!");
    }
    
    for (Lista::iterator it=std::begin(spil); it!=std::end(spil);) {
        Boje boja(it->first);
        std::string oznaka(it->second);
        
        auto ima(mapa.find(boja));
        bool obrisano(0);
        if (ima!=std::end(mapa))
            for (auto brisi=mapa.lower_bound(boja); brisi!=mapa.upper_bound(boja); brisi++)
                if (brisi->second==oznaka) {
                    it=spil.erase(it);
                    mapa.erase(brisi);
                    obrisano=1;
                    break;
                }
        if (obrisano==0) it++; 
    }
}


Queue IzbaciKarteRazbrajanjem (Lista &spil, const short int &r, const int &b) {
    
    if (r<1 || r>52 || b<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    
    try { TestirajListu(spil); }
    catch (...) {
        throw std::logic_error ("Neispravna lista!");
    }
    
    
    Queue red;
    Multimapa mapa;
    
    for (int i=0; i<b; i++);
        
    
    
    IzbaciKarte(spil, mapa);
    
    
    // red.push(std::make_pair(BojaUString(boja), vrijednost);
    
    return red;
}


void VratiPrvihNKarata (Lista &spil, Queue &red, int n) {
    
    if (n>red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    if (n<=0) throw std::domain_error ("Broj n je besmislen!");
    
    try { TestirajListu(spil); }
    catch (...) {
        throw std::logic_error ("Neispravna lista!");
    }
    
    for (int i=0; i<n; i++) {
        std::pair<std::string, std::string> par(red.front());
        Boje boja=StringUBoju(par.first);
        std::string vrijednost(par.second);
        
        auto it(std::find(std::begin(spil), std::end(spil), std::make_pair(boja, vrijednost)));
        if (it==std::end(spil)) spil.push_back(std::make_pair(boja, vrijednost));
        
        red.pop();
    }
} 






int main ()
{
    Lista spil(KreirajSpil());
    
    int m, n, x;
    
    try {
        for (;;) {
            std::cout << "Unesite korak razbrajanja: ";
            std::cin >> x;
            const short int r(x);
            std::cout << "Unesite broj karata koje zelite izbaciti: ";
            std::cin >> m;
            const int b(m);
            Queue red=IzbaciKarteRazbrajanjem(spil, r, b);
            std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: " << std::endl;
            IspisiKarte(spil);
            
            std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
                std::cin >> n;
            VratiPrvihNKarata(spil, red, n);
            std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: " << std::endl;
            IspisiKarte(spil);
                
            std::cout << "--------------------------------------------------" << std::endl;
    
        }
    }
    catch (...) {
        std::cout << "Izuzetak: " << std::endl;
    }
    
	return 0;
}
