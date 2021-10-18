#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <queue>

enum class Boje {Pik, Tref, Herc, Karo};

void DodajKarte(std::vector<std::string> &karte)
{
    karte.push_back("2"); karte.push_back("3");
    karte.push_back("4"); karte.push_back("5");
    karte.push_back("6"); karte.push_back("7");
    karte.push_back("8"); karte.push_back("9");
    karte.push_back("10"); karte.push_back("J");
    karte.push_back("Q"); karte.push_back("K");
    karte.push_back("A");
}

std::list<std::pair<Boje,std::string>> KreirajSpil()
{
    std::list<std::pair<Boje, std::string>> spil;
    Boje boja;
    std::vector<std::string> karte;
    DodajKarte(karte);
    for(int i=1; i<=52; i+=13)
    {
        if(i<=13) boja=Boje::Pik;
        else if(i>13 && i<=26) boja=Boje::Tref;
        else if(i>26 && i<=39) boja=Boje::Herc;
        else if(i>39 && i<=52) boja=Boje::Karo;
        for(int j=0; j<13; j++)
        {
            spil.push_back(std::make_pair(boja, karte[j]));
        }
    }
    return spil;
}

void IspisiKarte(const std::list<std::pair<Boje, std::string>> &spil)
{
    for(auto it=spil.begin(); it!=spil.end();)
    {
        if(int(it->first)==0)
        {
            std::cout << "Pik: ";
            while(int(it->first)==0)
            {
                std::cout << " " << it->second;
                it++;
            }
            std::cout << std::endl;
        }
        if(int(it->first)==1)
        {
            std::cout << "Tref: ";
            while(int(it->first)==1)
            {
                std::cout << " " << it->second;
                it++;
            }
            std::cout << std::endl;
        }
        if(int(it->first)==2)
        {
            std::cout << "Herc: ";
            while(int(it->first)==2)
            {
                std::cout << " " << it->second;
                it++;
            }
            std::cout << std::endl;
        }
        if(int(it->first)==3)
        {
            std::cout << "Karo: ";
            while(int(it->first)==3)
            {
                std::cout << " " << it->second;
                it++;
            }
            std::cout << std::endl;
        }
    }
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end();)
    {
        bool obrisan(false);
        for(auto it2=spil.begin(); it2!=spil.end();)
        {
            std::cout << int(it->first) << std::endl;
            if(it->first==it2->first && it->second==it2->second)
            {
                it2=spil.erase(it2);
                it=mapa.erase(it);
                obrisan=true;
            }
            else if(it->first!=it2->first)
            {
                while(it->first!=it2->first && it2!=spil.end()) it2++;
            }
            else
            {
                while(it->second!=it2->second && it2!=spil.end()) it2++;
            }
        }
        if(!obrisan) it++;
    }
}

void DodajKartu(std::list<std::pair<Boje, std::string>> &spil, std::pair<std::string, std::string> karta)
{
    Boje boja;
    if(karta.first=="Pik") boja=Boje::Pik;
    else if(karta.first=="Tref") boja=Boje::Tref;
    else if(karta.first=="Herc") boja=Boje::Herc;
    else if(karta.first=="Karo") boja=Boje::Karo;
    for(auto it=spil.begin(); it!=spil.end();)
    {
        int i=0;
        if(boja==it->first)
        {
            while(it->second!=karta.second) it++;
            spil.insert(it, std::make_pair(it->first, karta.second));
            break;
        }
        else
        {
            while(it->first!=boja) it++;
        }
    }
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<std::string,std::string>> &redIzbacenih, int n)
{
    if(n>redIzbacenih.size()) throw std::range_error("Nedovoljno karata u redu!");
    else if(n<1) throw std::domain_error("Broj n je besmislen!");
    for(int i=0; i<n; i++)
    {
        std::pair<std::string, std::string> karta=redIzbacenih.front();
        redIzbacenih.pop();
        DodajKartu(spil, karta);
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int &r, const int &b)
{
    std::queue<std::pair<std::string, std::string>> redIzbacenih;
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    int kolikoIzbaciti=b;
    for(auto it=spil.begin(); kolikoIzbaciti>0;)
    {
        if(it==spil.end()) it=spil.begin();
        int broj=1;
        while(broj<r)
        {
            if(it==spil.end()) it=spil.begin();
            it++;
            broj++;
        }
        std::pair<std::string, std::string> par;
        std::string boja;
        if(int(it->first)==0) boja="Pik";
        else if(int(it->first)==1) boja="Tref";
        else if(int(it->first)==2) boja="Herc";
        else if(int(it->first)==3) boja="Karo";
        par=std::make_pair(boja, it->second);
        redIzbacenih.push(par);
        it=spil.erase(it);
        kolikoIzbaciti--;
    }
    return redIzbacenih;
}



int main()
{
    std::list<std::pair<Boje, std::string>> spil=KreirajSpil();
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: " << std::endl;
    IspisiKarte(spil);
    std::cout << std::endl;
    int korak;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> korak;
    int brojKarata;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> brojKarata;
    /*std::multimap<Boje, std::string> mapa;
    std::pair<Boje, std::string> par=std::make_pair(Boje::Pik, "2");
    mapa.insert(par);
    par=std::make_pair(Boje::Tref, "K");
    mapa.insert(par);
    par=std::make_pair(Boje::Karo, "10");
    mapa.insert(par);
    IzbaciKarte(spil, mapa);
    IspisiKarte(spil);
    std::cout << std::endl;*/
    std::queue<std::pair<std::string, std::string>> redKarata=IzbaciKarteRazbrajanjem(spil, korak, brojKarata);
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: " << std::endl;
    IspisiKarte(spil);
    std::cout << std::endl;
    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    std::cin >> brojKarata;
    VratiPrvihNKarata(spil, redKarata, brojKarata);
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: " << std::endl;
    IspisiKarte(spil);
    return 0;
}
