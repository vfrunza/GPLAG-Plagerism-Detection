#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <queue>

enum class Boje {Pik, Tref, Herc, Karo}; 

typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::multimap<Boje, std::string> Mapa;
typedef std::queue<std::pair<std::string, std::string>> Qu;

void IspravnaLista(const Spil &spil)
{
    std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    auto kraj=spil.end();
    kraj--;
    for(auto it=spil.begin();it!=spil.end();it++)
    {
        auto itt=std::find(v.begin(),v.end(),it->second);
        if(itt==v.end()) throw std::logic_error("Neispravna lista!");
        if(it!=kraj)
        {
            std::pair<Boje,std::string> a;
            a.first=it->first;
            a.second=it->second;
            
            auto temp=it;
            temp++;
            
            std::pair<Boje,std::string> b;
            b.first=temp->first;
            b.second=temp->second;
            
            if(int(a.first)>int(b.first)) throw std::logic_error("Neispravna lista!");
            else if(int(a.first)==int(b.first))
            {
                auto it1=std::find(v.begin(),v.end(),a.second);
                auto it2=std::find(v.begin(),v.end(),b.second);
                
                if(it1>=it2) throw std::logic_error("Neispravna lista!");
            }
        }
    }
}

Spil KreirajSpil()
{
    std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    Spil spil;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            std::pair<Boje, std::string> unos;
            unos={Boje(i),v.at(j)};
            spil.insert(spil.end(),unos);
        }
    }
    return spil;
}

void IzbaciKarte(Spil &spil, Mapa &mapa)
{
    if(mapa.size()==0) return;
    try
    {
        IspravnaLista(spil);
    }
    catch(...)
    {
        throw;
    }
    for(auto it=spil.begin();it!=spil.end();it++)
    {
        auto itf=std::find_if(mapa.begin(),mapa.end(),
        [it](std::pair<Boje,std::string> par)
        {
            return (par.first==it->first && par.second==it->second);
        });
        if(itf!=mapa.end())
        {
           it=spil.erase(it);
           it--;
           std::pair<Boje,std::string> par;
           par.first=itf->first;
           par.second=itf->second;
           
           auto itm=mapa.begin();
           while(true)
           {
               if(itm==mapa.end()) break;
               if(itm->first==par.first && itm->second==par.second)
               {
                   itm=mapa.erase(itm);
               }
               else itm++;
           }
        }
    }
}

Qu IzbaciKarteRazbrajanjem(Spil &spil, short int &r, int &b)
{
    try
    {
        IspravnaLista(spil);
    }
    catch(...)
    {
        throw;
    }
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    Qu red;
    int broj(0);
    auto it=spil.begin();
    std::vector<std::string> v{"Pik","Tref","Herc","Karo"};
    
    while(true)
    {
        for(int i=0;i<r-1;i++)
        {
            it++;
            if(it==spil.end()) it=spil.begin();
        }
        std::pair<std::string,std::string> par;
        par.first=v.at(int(it->first));
        par.second=it->second;
        red.push(par);
        
        
        it=spil.erase(it);
        broj++;
        
        if(broj==b) break;
        if(it==spil.end())
        {
            if(broj<b && spil.size()>0) it=spil.begin();
            else break;
        }
    }
    return red;
}

void VratiPrvihNKarata(Spil &spil, Qu &red, int n)
{
    int vel=red.size();
    if(n>vel) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    std::vector<std::string> v1{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0;i<vel;i++)
    {
        auto karta=red.front();
        if(!(karta.first=="Pik" || karta.first=="Tref" || karta.first=="Herc" || karta.first=="Karo")) throw std::logic_error("“Neispravne karte!");
        red.pop();
        auto it=std::find(v1.begin(),v1.end(),karta.second);
        if(it==v1.end()) throw std::logic_error("Neispravne karte!");
        red.push(karta);
    }
    try
    {
        IspravnaLista(spil);
    }
    catch(...)
    {
        throw;
    }
    
    
    for(int i=0;i<n;i++)
    {
        auto karta=red.front();
        red.pop();
        int broj(0);
        if(karta.first=="Pik") broj=0;
        else if(karta.first=="Tref") broj=1;
        else if(karta.first=="Herc") broj=2;
        else if(karta.first=="Karo") broj=3;
        auto it=spil.begin();
        while(true)
        {
            if(it==spil.end()) break;
            if(int(it->first)<broj) it++;
            else break;
        }
        if(int(it->first)==broj)
        {
            auto itf1=std::find(v1.begin(),v1.end(),karta.second);
            auto itf2=std::find(v1.begin(),v1.end(),it->second);
            if(itf1!=itf2)
            {
                while(true)
                {
                    auto itt=std::find(v1.begin(),v1.end(),it->second);
                    auto itk=std::find(v1.begin(),v1.end(),karta.second);
                    if(itt>itk) break;
                    if(int(it->first)>broj) break;
                    else it++;
                }
                if(karta.second==it->second) continue;
                std::pair<Boje,std::string> par;
                par.first=Boje(broj);
                par.second=karta.second;
                spil.insert(it,par);
            }
        }
        else
        {
            while(true)
            {
                auto itt=std::find(v1.begin(),v1.end(),it->second);
                auto itk=std::find(v1.begin(),v1.end(),karta.second);
                if(itt>itk) break;
                if(int(it->first)>broj) break;
                else it++;
            }
            std::pair<Boje,std::string> par;
            par.first=Boje(broj);
            par.second=karta.second;
            spil.insert(it,par);
        }
        
    }

}

void Ispis(Spil &spil)
{
    int n=spil.size();
    std::cout<<"U spilu trenutno ima "<<n<<" karata, i to: ";
    std::cout<<std::endl;
    auto it=spil.begin();
    std::cout<<"Pik: ";
    for(int i=0;i<n;i++)
    {
        if(it==spil.end()) break;
        if(int(it->first)==0) std::cout<<it->second<<" ";
        else break;
        it++;
    }
    std::cout<<std::endl;
    std::cout<<"Tref: ";
    for(int i=0;i<n;i++)
    {
        if(it==spil.end()) break;
        if(int(it->first)==1) std::cout<<it->second<<" ";
        else break;
        it++;
    }
    std::cout<<std::endl;
    std::cout<<"Herc: ";
    for(int i=0;i<n;i++)
    {
        if(it==spil.end()) break;
        if(int(it->first)==2) std::cout<<it->second<<" ";
        else break;
        it++;
    }
    std::cout<<std::endl;
    std::cout<<"Karo: ";
    for(int i=0;i<n;i++)
    {
        if(it==spil.end()) break;
        if(int(it->first)==3) std::cout<<it->second<<" ";
        else break;
        it++;
    }
    std::cout<<std::endl;
}

int main ()
{
    try
    {
        short int r;
        int b;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        Spil s;
        s=KreirajSpil();
        auto red=IzbaciKarteRazbrajanjem(s,r,b);
        Ispis(s);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(s,red,n);
        Ispis(s);
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    catch(std::range_error izuzetak)
    {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    catch(std::logic_error izuzetak)
    {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}