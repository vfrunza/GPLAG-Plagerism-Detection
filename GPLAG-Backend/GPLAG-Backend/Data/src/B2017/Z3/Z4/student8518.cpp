/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <iterator>

enum class Boje{Pik=1, Tref=2, Herc=3, Karo=4};     //vrijesnoti enuma, da bi ih mogli sortirati

std::list<std::pair<Boje, std::string>> KreirajSpil()
{
    std::list<std::pair<Boje, std::string>> spil;
    
    std::vector<Boje> pomocni{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    std::vector<std::string> broj_karte {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"} ;
    
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<13; j++)
        {
            spil.push_back(  std::make_pair(pomocni.at(i), broj_karte.at(j) ) );
        }
    }
    
    return spil;
}

void SortirajSpil(std::list<std::pair<Boje,std::string>> &spil)  //prima spil po referenci da bi ga mogla mijenjati
{
    spil.sort([](const std::pair<Boje,std::string> &prvi_par, const std::pair<Boje,std::string> &drugi_par)
    {
        int prvi, drugi;
        
        if(prvi_par.second=="2" || prvi_par.second=="3"|| prvi_par.second=="4"|| prvi_par.second=="5"|| prvi_par.second=="6"|| prvi_par.second=="7"|| prvi_par.second=="8"|| prvi_par.second=="9"|| prvi_par.second=="10")
        prvi=std::stoi(prvi_par.second);       //"stoi()", string to intager naredba
        else if(prvi_par.second=="J")
        prvi=11;
        else if(prvi_par.second=="Q")
        prvi=12;
        else if(prvi_par.second=="K")
        prvi=13;
        else if(prvi_par.second=="A")
        prvi=14;
        
        if(drugi_par.second=="2" || drugi_par.second=="3"|| drugi_par.second=="4"|| drugi_par.second=="5"|| drugi_par.second=="6"|| drugi_par.second=="7"|| drugi_par.second=="8"|| drugi_par.second=="9"|| drugi_par.second=="10")
        drugi=std::stoi(drugi_par.second);              //"stoi()", string to intager naredba
        else if(drugi_par.second=="J")
        drugi=11;
        else if(drugi_par.second=="Q")
        drugi=12;
        else if(drugi_par.second=="K")
        drugi=13;
        else if(drugi_par.second=="A")
        drugi=14;
        
        return prvi<drugi;
    });
    
    spil.sort([](const std::pair<Boje,std::string> &prvi_par, const std::pair<Boje,std::string> &drugi_par)
    {
        return prvi_par.first < drugi_par.first;
    });
}

bool JeLiSortirana(std::list<std::pair<Boje,std::string>> spil)
{
    std::list<std::pair<Boje,std::string>> drugi=spil;
     
     //NE RADE FUKCIJE SORTIRANJA IZ "algorithm" ZA LISTE, ZATO STO ITERATORI NA LISTE NISU ITERATORI SA APSOLUTNIM PRISTUPOM, postoji samo "ime_liste.sort()",
     // s tim da to mora biti lista sa uporedivim tipom elmenata, a sortiranje se odvija po uzoru na "stable_sort"
     SortirajSpil(spil);
     
    typename std::list<std::pair<Boje, std::string>>::iterator it1, it2;
    it1=spil.begin();
    it2=drugi.begin();
     
    do{
        if(it1->first!=it2->first || it1->second!=it2->second)
        return false;
        
        it1++;
        it2++;
    }while(it1!=spil.end());
     
 return true;   
}

bool BesmisleniPodaci(std::list<std::pair<Boje,std::string>> spil)
{
    typename std::list<std::pair<Boje, std::string>>::iterator it1;
    it1=spil.begin();
     
    do{
        if((it1->first!=Boje::Pik && it1->first!=Boje::Tref && it1->first!=Boje::Herc && it1->first!=Boje::Karo) || (it1->second!="2"&& it1->second!="3"&& it1->second!="4"&& it1->second!="5"&& it1->second!="6"&& it1->second!="7"&& it1->second!="8"&& it1->second!="9"&& it1->second!="10"&& it1->second!="J"&& it1->second!="Q"&& it1->second!="K"&& it1->second!="A"))
        return false;
        
        it1++;
    }while(it1!=spil.end());
    return true;
}

void IzbaciKarte( std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &m )
{
    typename std::list<std::pair<Boje,std::string>>::iterator itl=spil.begin();

    if(!JeLiSortirana(spil) || spil.size()>52 || !BesmisleniPodaci(spil))
    throw std::logic_error("Neispravna lista");
    
    typename std::multimap<Boje,std::string>::iterator itm=m.begin();
    
    do{
        itl=spil.begin();
        
        do{
            if(itl->first==itm->first && itl->second==itm->second)
            {
                itl=spil.erase(itl);
                m.erase(itm->first);
            }
            
            if(itl==spil.end())
            break;
            
            itl++;
        }while(itl!=spil.end());
        
        if(itm==m.end())
        break;
        
        itm++;
    }while(itm!=m.end());
    
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1)
    throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    std::queue<std::pair<std::string, std::string>> izbaceni;
    
    if(!JeLiSortirana(spil) || spil.size()>52 || !BesmisleniPodaci(spil))
    throw std::logic_error("Neispravna lista");
    
    typename std::list<std::pair<Boje,std::string>>::iterator it=spil.begin();
    
    std::vector<std::string> znak_karte {"Pik", "Tref", "Herc", "Karo"};
    int brojac(0);
    do{
        for(int i=0; i<r-1; i++)  /// bilo je do r
        {
            /*if(it!=spil.end())
            it++;                       STARO   
            else
            it=spil.begin();*/
            it++;
            if(it==spil.end()) 
            it=spil.begin();
        }
        if(it==spil.end())
        break;
        if(it->first==Boje::Pik)
        izbaceni.push(std::make_pair(znak_karte.at(0), it->second));
        if(it->first==Boje::Tref)
        izbaceni.push(std::make_pair(znak_karte.at(1), it->second));
        if(it->first==Boje::Herc)
        izbaceni.push(std::make_pair(znak_karte.at(2), it->second));
        if(it->first==Boje::Karo)
        izbaceni.push(std::make_pair(znak_karte.at(3), it->second));
        //it--;      zbog onog gore ovo ne treba
        
        it=spil.erase(it);
        
        brojac++;
        if(brojac==b)
        break;
        
    }while(it!=spil.end());
    
    return izbaceni;
}

bool BesmislenRed(std::queue<std::pair<std::string, std::string>> izbaceni)
{
    while(!izbaceni.empty())
    {
        if( (izbaceni.front().first!="Pik" && izbaceni.front().first!="Tref" && izbaceni.front().first!="Herc" && izbaceni.front().first!="Karo") || (izbaceni.front().second!="2"&& izbaceni.front().second!="3"&& izbaceni.front().second!="4"&& izbaceni.front().second!="5"&& izbaceni.front().second!="6"&& izbaceni.front().second!="7"&& izbaceni.front().second!="8"&& izbaceni.front().second!="9"&& izbaceni.front().second!="10"&& izbaceni.front().second!="J"&& izbaceni.front().second!="Q"&& izbaceni.front().second!="K"&& izbaceni.front().second!="A"))
        return false;
        
        izbaceni.pop();
    }
    
    return true;
}

void VratiPrviNKarata(std::list<std::pair<Boje,std::string>> &spil, std::queue<std::pair<std::string,std::string>> &izbaceni, int n)
{
    if(n<0)
    throw std::domain_error("Broj n je besmislen!");
    
    if(n>izbaceni.size())
    throw std::range_error ("Nedovoljno karata u redu!");
    
    if(!BesmislenRed(izbaceni))
    throw std::logic_error("Neispravne karte");
    
    if(!JeLiSortirana(spil) || spil.size()>52 || !BesmisleniPodaci(spil))
    throw std::logic_error("Neispravna lista");
    
    typename std::list<std::pair<Boje,std::string>>::iterator it1=spil.begin();
    
    /*for(int i=0; i<n; i++)
    {
        if(izbaceni.front().first=="Pik")
        {
            while(it1->first==Boje::Pik && izbaceni.front().second <= it1->second)
                it1++;
        }
        else if(izbaceni.front().first=="Tref")
        {
            while(it1!=spil.end() && it1->first==Boje::Pik)
            it1++;
            
            while(it1->first==Boje::Tref && izbaceni.front().second <= it1->second)
                it1++;
        }
        else if(izbaceni.front().first=="Herc")
        {
            while(it1!=spil.end() && it1->first!=Boje::Pik)
            it1++;
            while(it1!=spil.end() && it1->first!=Boje::Tref)
            it1++;
            
            while(it1->first==Boje::Herc && izbaceni.front().second <= it1->second)
                it1++;
        }
        else if(izbaceni.front().first=="Karo")
        {
            while(it1!=spil.end() && it1->first==Boje::Pik)
            it1++;
            while(it1!=spil.end() && it1->first==Boje::Tref)
            it1++;
            while(it1!=spil.end() && it1->first==Boje::Herc)
            it1++;
            
            while(it1->first==Boje::Karo && izbaceni.front().second <= it1->second)
                it1++;
            
        }
        
        
        if(it1->second==izbaceni.front().second)
        continue;
        else
        {
            spil.insert(it1, std::make_pair(Boje::Pik, izbaceni.front().second) );
        }
        
        izbaceni.pop();
        
        it1=spil.begin();
    }*/
    
    for(int i=0; i<n ;i++)
    {
        if(izbaceni.front().first=="Pik") 
        spil.insert(it1, std::make_pair(Boje::Pik, izbaceni.front().second) );
        else  if(izbaceni.front().first=="Herc")
        spil.insert(it1, std::make_pair(Boje::Herc, izbaceni.front().second) );
        else  if(izbaceni.front().first=="Tref") 
        spil.insert(it1, std::make_pair(Boje::Tref, izbaceni.front().second) );
        else
        spil.insert(it1, std::make_pair(Boje::Karo, izbaceni.front().second) );
        
        izbaceni.pop();
    }
    
    SortirajSpil(spil);
    
    typename std::list<std::pair<Boje,std::string>>::iterator it_spil1=spil.begin(), it_spil2;
    
    for(int i=0; i<spil.size(); i++)
    {
        if(i+1==spil.size())
        break;
        
        it_spil2 = it_spil1;
        std::advance(it_spil2, 1);
        
        for(int j=i; j<spil.size(); j++)           //nije morala ici dupla pelja, jer ako postoje isti elementi, jedan do drugog su, ali nema veze
        {
            if(it_spil1->first==it_spil2->first && it_spil1->second==it_spil2->second)
            {
                it_spil1 = spil.erase(it_spil1);
                i--;
                break;
            }
            
            std::advance(it_spil2, 1);
        }
    }
}

void IpisiListu(std::list<std::pair<Boje,std::string>> spil)
{
    typename std::list<std::pair<Boje, std::string>>::iterator it=spil.begin();
    
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
    
    do{
        if(it->first==Boje::Pik)
        {
            std::cout<<"Pik: ";
            while(it->first==Boje::Pik)
            {
                std::cout<< it->second<<" ";
                it++;
            }
            std::cout<<std::endl;
        }
        
        if(it->first==Boje::Tref)
        {
            std::cout<<"Tref: ";
            while(it->first==Boje::Tref)
            {
                std::cout<< it->second<<" ";
                it++;
            }
            std::cout<<std::endl;
        }
        
        if(it->first==Boje::Karo)
        {
            std::cout<<"Karo: ";
            while(it->first==Boje::Karo)
            {
                std::cout<< it->second<<" ";
                it++;
            }
            std::cout<<std::endl;
        }
        
        if(it->first==Boje::Herc)
        {
            std::cout<<"Herc: ";
            while(it->first==Boje::Herc)
            {
                std::cout<< it->second<<" ";
                it++;
            }
            std::cout<<std::endl;
        }
        
        if(it==spil.end())
        break;
        
    }while(it!=spil.end());
}

int main ()
{
    std::list<std::pair<Boje, std::string>> spil;
    
    spil=KreirajSpil();
    
    std::multimap<Boje, std::string> m;
    
    try
    {
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int br_karata;
        std::cin>>br_karata;
        
        std::queue<std::pair<std::string, std::string>> izbacene=IzbaciKarteRazbrajanjem(spil, r, br_karata);
        
        IpisiListu(spil);
        
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int vrati_karata;
        std::cin>>vrati_karata;
        
        VratiPrviNKarata(spil, izbacene, vrati_karata);
        IpisiListu(spil);
        
    }
    catch(std::domain_error poruka1)
    {
        std::cout<<"Izuzetak: "<<poruka1.what();
    }
    catch(std::logic_error poruka2)
    {
        std::cout<<"Izuzetak: "<<poruka2.what();
    }
    catch(std::range_error poruka3)
    {
        std::cout<<"Izuzetak: "<<poruka3.what();
    }
    
	return 0;
}
