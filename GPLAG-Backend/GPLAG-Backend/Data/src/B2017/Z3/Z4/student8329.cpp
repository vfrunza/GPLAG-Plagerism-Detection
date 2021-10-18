/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <utility>
#include <map>
#include <queue>


enum class Boje {Pik, Tref, Herc, Karo};

template <typename T> std::string U_string(T x)
{
	std::ostringstream s;
	s<<x;
	return s.str();
}

std::string Pretvori(Boje boja)
{
    std::string s;
    if(boja==Boje(0))s="Pik";
    else if(boja==Boje(1))s="Tref";
    else if(boja==Boje(2))s="Herc";
    else if(boja==Boje(3))s="Karo";
    return s;
}

Boje Pretvori2(std::string s)
{
    Boje boja;
    if(s=="Pik")boja=Boje(0);
    else if(s=="Tref")boja=Boje(1);
    else if(s=="Herc")boja=Boje(2);
    else if(s=="Karo")boja=Boje(3);
    return boja;
}

int Pretvori1(std::string s)
{
    int broj;
    if(s=="J"){broj=11;return broj;}
    if(s=="Q"){broj=12;return broj;}
    if(s=="K"){broj=13;return broj;}
    if(s=="A"){broj=14;return broj;}
    else broj=std::stoi(s);
    return broj;
    
}

std::list<std::pair<Boje, std::string>> KreirajSpil()
{
    std::list<std::pair<Boje, std::string>> Spil;
    Boje trenutna_boja;
    for(int i(0);i<4;i++)
    {
        trenutna_boja=Boje(i);
        for(int j(2);j<=10;j++)
        {
            std::pair<Boje, std::string> tmp;
            tmp.first= trenutna_boja;
            tmp.second=U_string(j);
            Spil.push_back(tmp);
        }
        std::pair<Boje, std::string> tmp;
        tmp=std::make_pair(trenutna_boja, 'J');
        Spil.push_back(tmp);
        tmp=std::make_pair(trenutna_boja, 'Q');
        Spil.push_back(tmp);
        tmp=std::make_pair(trenutna_boja, 'K');
        Spil.push_back(tmp);
        tmp=std::make_pair(trenutna_boja, 'A');
        Spil.push_back(tmp);
        
    }
    
    return Spil;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &Spil, std::multimap<Boje, std::string>& Mapa)
{
    if(Spil.size()>52)throw std::logic_error("Neispravna lista!");
    for(auto x: Spil)
    {
        if(!(x.first==Boje::Pik || x.first==Boje::Herc || x.first==Boje::Tref || x.first==Boje::Karo))throw std::logic_error("Neispravna lista");
        if(!((x.second.at(0)>='0' && x.second.at(0)<='9') || x.second.at(0)=='K' || x.second.at(0)=='Q' || x.second.at(0)=='A' || x.second.at(0)=='J'))throw std::logic_error("Neispravna lista");
    }
    for(auto it(Spil.begin());it!=Spil.end();it++)
    {
        auto it2=Mapa.find(it->first);
        if(it2!=Mapa.end() && it->second==it2->second)
        {
            Mapa.erase(it2);
            it=Spil.erase(it);
        }
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &Spil, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(Spil.size()>52)throw std::logic_error("Neispravna lista!");
    for(auto x: Spil)
    {
        if(!(x.first==Boje::Pik || x.first==Boje::Herc || x.first==Boje::Tref || x.first==Boje::Karo))throw std::logic_error("Neispravna lista");
        if(!((x.second.at(0)>='0' && x.second.at(0)<='9') || x.second.at(0)=='K' || x.second.at(0)=='Q' || x.second.at(0)=='A' || x.second.at(0)=='J'))throw std::logic_error("Neispravna lista");
    }
    std::queue<std::pair<std::string, std::string>> red;
    int a(0);
    auto it=Spil.begin();

    while(!(Spil.size()==0 || a==b))
    {
        int brojac(0);
        while(brojac!=r)
        {
            brojac++;
            if(brojac==r)break;
            it++;
            if(it==Spil.end())it=Spil.begin();
            
        }
        std::string pomocni;
        if(it->first==Boje(0))pomocni="Pik";
        else if(it->first==Boje(1))pomocni="Tref";
        else if(it->first==Boje(2))pomocni="Herc";
        else if(it->first==Boje(3))pomocni="Karo";
        std::pair<std::string, std::string> temp;
        temp.first=pomocni;
        temp.second=it->second;
        red.push(temp);
        a++;
        it=Spil.erase(it);
        if(it==Spil.end())it=Spil.begin();
    }
    return red;
}


void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &Spil, std::queue<std::pair<std::string, std::string>> &Red, int n)
{
    if(Spil.size()>52)throw std::logic_error("Neispravna lista!");
    for(auto x: Spil)
    {
        if(!(x.first==Boje::Pik || x.first==Boje::Herc || x.first==Boje::Tref || x.first==Boje::Karo))throw std::logic_error("Neispravna lista");
        if(!((x.second.at(0)>='0' && x.second.at(0)<='9') || x.second.at(0)=='K' || x.second.at(0)=='Q' || x.second.at(0)=='A' || x.second.at(0)=='J'))throw std::logic_error("Neispravna lista");
    }
    if(n<0)throw std::domain_error("Broj n je besmislen!");
    if(n>Red.size())throw std::range_error("Nedovoljno karata u redu!");
    int a(0);
    while(a!=n)
    {
        if(a==n)break;
        for(auto it(Spil.begin());it!=Spil.end();it++)
        {
            if(a==n)break;
            if(Pretvori(it->first)==Red.front().first)
            {
                if(Pretvori1(it->second)>Pretvori1(Red.front().second))
                {
                    std::pair<Boje, std::string>Par;
                    Par=std::make_pair(Pretvori2(Red.front().first),Red.front().second);
                    Spil.insert(it,Par);
                    Red.pop();
                    a++;
                }
                
                else if(Pretvori1(it->second)<Pretvori1(Red.front().second) && Pretvori1(Red.front().second)==14 && Pretvori1(it->second)==13)
                {
                    it++;
                    std::pair<Boje, std::string>Par;
                    Par=std::make_pair(Pretvori2(Red.front().first),Red.front().second);
                    Spil.insert(it,Par);
                    Red.pop();
                    a++;
                }
            }
        }
    }
}

int main ()
{

    try
    {
    std::cout<<"Unesite korak razbrajanja: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int broj;
    std::cin>>broj;
    std::list<std::pair<Boje, std::string>> Spil(KreirajSpil());
    std::queue<std::pair<std::string, std::string>> Red(IzbaciKarteRazbrajanjem(Spil,n,broj));
    
    std::cout<<"U spilu trenutno ima "<<Spil.size()<<" karata, i to:"<<std::endl;
    std::cout<<"Pik: ";
    for(auto it=Spil.begin();it!=Spil.end();it++)
    {
        if(it->first==Boje(0))std::cout<<it->second<<" ";
    }
    std::cout<<std::endl<<"Tref: ";
    for(auto it=Spil.begin();it!=Spil.end();it++)
    {
        if(it->first==Boje(1))std::cout<<it->second<<" ";
    }
    std::cout<<std::endl<<"Herc: ";
    for(auto it=Spil.begin();it!=Spil.end();it++)
    {
        if(it->first==Boje(2))std::cout<<it->second<<" ";
    }
    std::cout<<std::endl<<"Karo: ";
    for(auto it=Spil.begin();it!=Spil.end();it++)
    {
        if(it->first==Boje(3))std::cout<<it->second<<" ";
    }
    std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
    int br1;
    std::cin>>br1;
    VratiPrvihNKarata(Spil,Red,br1);
    
     std::cout<<"U spilu trenutno ima "<<Spil.size()<<" karata, i to:"<<std::endl;
    std::cout<<"Pik: ";
    for(auto it=Spil.begin();it!=Spil.end();it++)
    {
        if(it->first==Boje(0))std::cout<<it->second<<" ";
    }
    std::cout<<std::endl<<"Tref: ";
    for(auto it=Spil.begin();it!=Spil.end();it++)
    {
        if(it->first==Boje(1))std::cout<<it->second<<" ";
    }
    std::cout<<std::endl<<"Herc: ";
    for(auto it=Spil.begin();it!=Spil.end();it++)
    {
        if(it->first==Boje(2))std::cout<<it->second<<" ";
    }
    std::cout<<std::endl<<"Karo: ";
    for(auto it=Spil.begin();it!=Spil.end();it++)
    {
        if(it->first==Boje(3))std::cout<<it->second<<" ";
    }
        
    }
    catch(std::domain_error Izuzetak){
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
    }
    catch(std::logic_error Izuzetak){
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
    }
    catch(std::range_error Izuzetak){
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
    }
    
	return 0;
}
