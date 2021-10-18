/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <queue>
#include <stdexcept>

enum class Boje {Pik, Tref, Herc, Karo};

const char *karte[13]{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

std::string PretvoriUString (Boje b)
{
    if (b==Boje::Pik) return "Pik";
    else if (b==Boje::Tref) return "Tref";
    else if (b==Boje::Karo) return "Karo";
    return "Herc";
}

Boje PretvoriUBoju (std::string s)
{
    if (s=="Pik") return Boje::Pik;
    else if (s=="Tref") return Boje::Tref;
    else if (s=="Herc") return Boje::Herc;
    return Boje::Karo;
}

bool Kriterij2 (std::string s1, std::string s2)
{
    std::string Fun (std::string s);
    s1=Fun(s1); s2=Fun(s2);
    if (s1.size()==s2.size())
    return s1>s2;
    return s1.size()>s2.size();
}

bool DaLiJeIspravnaLista (const std::list<std::pair<Boje,std::string>> &lista)
{
    if (lista.size()>52)
        return false;
    auto it(lista.begin()),kraj(lista.end());
    while (it!=kraj)
    {
        if (it->first!=Boje::Pik && it->first!=Boje::Karo && it->first!=Boje::Herc && it->first!=Boje::Tref)
            return false;
        bool ispravno(false);
        for (int i=0;i<13;i++)
        {
            if (it->second==karte[i])
            {
                ispravno=true;
                break;
            }
        }
        if (!ispravno)
            return false;
        it++;
    }
    it=lista.begin();
    while (it!=kraj)
    {
        auto temp(it);
        temp++;
        if (temp!=kraj)
        {
            if (it->first>temp->first)
            return false;
            else if (it->first==temp->first && Kriterij2(it->second,temp->second))
            return false;
        }
        it++;
    }
    return true;
}

std::list<std::pair<Boje,std::string>> KreirajSpil ()
{
    Boje niz[4]{Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
    std::list<std::pair<Boje,std::string>> vrati;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<13;j++)
            vrati.push_back({niz[i],karte[j]});
    }
    return vrati;
}
void IzbaciKarte (std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &mapa)
{
    if (!DaLiJeIspravnaLista(spil))
        throw std::logic_error ("Neispravna lista!");
    auto poc(spil.begin()),kraj(spil.end());
    while (poc!=kraj)
    {
        bool brisi(false);
        auto it(mapa.begin()),it2(mapa.end());
        while (it!=it2)
        {
            if (it->first==poc->first && it->second==poc->second)
            {
                brisi=true;
                it=mapa.erase(it);
                break;
            }
            else
            it++;
        }
        if (brisi)
        poc=spil.erase(poc);
        else
        poc++;
    }
}
std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje,std::string>> &spil, const short int &r, const int &b)
{
    if (!DaLiJeIspravnaLista(spil))
        throw std::logic_error ("Neispravna lista!");
    if (r<1 || r>52 || b<1)
        throw std::logic_error ("Neispravni elementi za izbacivanje!");
    auto it(spil.begin());
    std::queue<std::pair<std::string,std::string>> vrati;
    if (it!=spil.end()) {
    for (int i=0;i<b;i++)
    {
       for (int j=0;j<r-1;j++)
       {
            if (it==spil.end())
            it=spil.begin();
            it++;
       }
       if (it==spil.end())
       it=spil.begin();
       if (it!=spil.end()){
       vrati.push({PretvoriUString(it->first),it->second});
       it=spil.erase(it);}
    }}
    return vrati;
}
std::string Fun (std::string s)
{
    if (s=="J") s="11";
    if (s=="Q") s="12";
    if (s=="K")  s="13";
    if (s=="A")  s="14";
    return s;
}
bool Sortiraj (std::pair<Boje,std::string> a, std::pair<Boje,std::string> b)
{
    a.second=Fun(a.second); b.second=Fun(b.second);
    if (a.first==b.first)
    {
        if (a.second.size()==b.second.size())
        return a.second<b.second;
        return a.second.size()<b.second.size();
    }
    return a.first<b.first;
}

bool DaLiJeIspravanRed (std::queue<std::pair<std::string,std::string>> red)
{
    while (!red.empty())
    {
        auto temp(red.front());
        red.pop();
        if (temp.first!="Pik" && temp.first!="Karo" && temp.first!="Tref" && temp.first!="Herc")
            return false;
        bool ispravno(false);
        for (int i=0;i<13;i++)
        {
            if (temp.second==karte[i])
            {
                ispravno=true;
                break;
            }
        }
        if (!ispravno)
            return false;
    }
    return true;
}

void VratiPrvihNKarata (std::list<std::pair<Boje,std::string>> &spil,std::queue<std::pair<std::string,std::string>> &red, int n )
{
    if (n<0)
        throw std::domain_error ("Broj n je besmislen!");
    if (n>red.size())
        throw std::range_error ("Nedovoljno karata u redu!");
    if (!DaLiJeIspravnaLista(spil))
        throw std::logic_error ("Neispravna lista!");
    if (!DaLiJeIspravanRed(red))
        throw std::logic_error ("Neispravne karte!");
    for (int i=0;i<n;i++)
    {
        auto temp(red.front());
        red.pop();
        bool ubaci(true);
        auto poc(spil.begin()),kraj(spil.end());
        while (poc!=kraj)
        {
            if (poc->first==PretvoriUBoju(temp.first) && poc->second==temp.second)
            {
                ubaci=false;
                break;
            }
            poc++;
        }
        if (ubaci)
        spil.insert(spil.end(),{PretvoriUBoju(temp.first),temp.second});
    }
    spil.sort(Sortiraj);
}

void IspisiSpil (const std::list<std::pair<Boje,std::string>> &lista)
{
    if (lista.size()==0)
    {
        std::cout<<"Pik: \nTref: \nHerc: \nKaro: \n";
        return;
    }
    auto it(lista.begin()),kraj(lista.end());
    std::cout<<"Pik: ";
    while (it!=kraj && it->first==Boje::Pik)
    {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl<<"Tref: ";
    while (it!=kraj && it->first==Boje::Tref)
    {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl<<"Herc: ";
    while (it!=kraj && it->first==Boje::Herc)
    {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl<<"Karo: ";
    while (it!=kraj && it->first==Boje::Karo)
    {
        std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl;
}
int main()
{
   auto lista(KreirajSpil());
   try 
   {
       short int korak;
       int izbaci;
       std::cout<<"Unesite korak razbrajanja: ";
       std::cin>>korak;
       std::cout<<"Unesite broj karata koje zelite izbaciti: ";
       std::cin>>izbaci;
       auto red(IzbaciKarteRazbrajanjem(lista,korak,izbaci));
       std::cout<<"U spilu trenutno ima "<<lista.size()<<" karata, i to:\n";
       IspisiSpil(lista);
       int x;
       std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
       std::cin>>x;
       VratiPrvihNKarata(lista,red,x);
       std::cout<<"U spilu trenutno ima "<<lista.size()<<" karata, i to:\n";
       IspisiSpil(lista);
   }
   catch (std::domain_error izuz)
   {
       std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
   }
   catch (std::range_error izuz2)
   {
       std::cout<<"Izuzetak: "<<izuz2.what()<<std::endl;
   }
   catch (std::logic_error izuz3)
   {
       std::cout<<"Izuzetak: "<<izuz3.what()<<std::endl;
   }
   return 0;
}
