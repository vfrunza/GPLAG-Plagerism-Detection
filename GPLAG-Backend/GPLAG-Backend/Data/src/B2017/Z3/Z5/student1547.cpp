/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <stack>
#include <queue>
    
enum class Boje {Pik, Tref, Herc, Karo}; 

typedef std::multimap<Boje, std::string> Mapa;
typedef std::stack<std::pair<std::string, std::string>> Stak;
typedef std::queue<std::pair<std::string, std::string>> Qu;


struct Karta
{
    Boje boja;
    std::string vrijednost;
};

struct Cvor
{
    Karta karta;
    Cvor *sljedeci;
};
int BrojKarti(Cvor* spil)
{
    int broj=0;
    if(spil==nullptr) return 0;
    if(spil->sljedeci==nullptr || spil->sljedeci==spil) return 1;
    
    Cvor* pocetak=spil;
    
    while(true)
    {
        broj++;
        spil=spil->sljedeci;
        if(spil==pocetak) break;
    }
    return broj;
    
}
void IspravnaLista(Cvor * &spil)
{
    std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    if(BrojKarti(spil)==0) return;
    auto pocetak=spil;
    int br(0);
    while(true)
    {
        if(pocetak==spil) break;
        pocetak=pocetak->sljedeci;
        br++;
        if(br>52) throw std::logic_error("Neispravna lista!");
    }
    pocetak=spil;
    if(BrojKarti(spil)>52) throw std::logic_error("Neispravna lista!");
    /*auto kraj=spil.end();
    kraj--;*/

    auto it=spil;
    while(true)
    {
        auto itt=std::find(v.begin(),v.end(),it->karta.vrijednost);
        if(itt==v.end()) throw std::logic_error("Neispravna lista!");
        
        //if(it!=kraj)
        std::pair<Boje,std::string> a;
        a.first=it->karta.boja;
        a.second=it->karta.vrijednost;
        
        auto sljedeci=it->sljedeci;
        
        std::pair<Boje,std::string> b;
        b.first=sljedeci->karta.boja;
        b.second=sljedeci->karta.vrijednost;
        if(sljedeci==pocetak) break;
        if(int(a.first)>int(b.first)) throw std::logic_error("Neispravna lista!");
        
        else if(int(a.first)==int(b.first))
        {
            auto it1=std::find(v.begin(),v.end(),a.second);
            auto it2=std::find(v.begin(),v.end(),b.second);
            
            if(it1>=it2) throw std::logic_error("Neispravna lista!");
        }
        it=it->sljedeci;
        if(it==pocetak) break;
    }
}
Cvor* KreirajSpil()
{
    Cvor *pocetak(nullptr), *prethodni;
    int broj(0);
    std::vector<std::string> v1{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    
    while(true)
    {
        int brboje=broj/13;
        Karta karta;
        karta.boja=Boje(brboje);
        int brkarte=broj%13;
        karta.vrijednost=v1.at(brkarte);
        Cvor *novi(new Cvor{karta, nullptr});   
        if(!pocetak) pocetak = novi;  
        else prethodni->sljedeci = novi; 
        prethodni = novi;
        broj++;
        if(broj>51)  break;  //OVDJE TREBA 51 !!!!!!!!!!!!!!!!!
        
    }
    prethodni->sljedeci=pocetak;
    
    return pocetak;
}

void Izbrisi(Mapa &mapa, std::pair<Boje,std::string> clan)
{
    auto itm=mapa.begin();
    while(true)
    {
        auto kartaizmape=*itm;
        if(clan.first==kartaizmape.first && clan.second==kartaizmape.second)
        {
            auto pom=itm;
            pom++;
            mapa.erase(itm);
            itm=pom;
            if(itm==mapa.end()) break;
        }
        else
        {
            itm++;
            if(itm==mapa.end()) break;
        }
    }
}
void IzbaciKarte(Cvor* &s, Mapa &mapa)
{
    try
    {
        IspravnaLista(s);
    }
    catch(...)
    {
        throw;
    }
    auto itm=mapa.begin();
    while(true)
    {
        bool izbrisao=false;
        if(itm==mapa.end() || mapa.size()==0) break;
        auto its=s;
        auto prethodni=s->sljedeci;
        while(prethodni->sljedeci!=s) prethodni=prethodni->sljedeci;
        
        auto kartaizmape=*itm;
        
        while(true)
        {
            auto kartaizspila=its->karta;
            if(kartaizmape.first==kartaizspila.boja && kartaizmape.second==kartaizspila.vrijednost)
            {
                if(BrojKarti(s)>1)
                {
                    if(s==its) s=its->sljedeci; //GLAVNO
                    
                    auto pom=its;
                    its=its->sljedeci;
                    prethodni->sljedeci=its;
                    delete pom;
                }
                else
                {
                    delete s;
                    s=nullptr;
                }
                izbrisao=true;
                break;
            }
            
            prethodni=its;
            its=its->sljedeci;
            
            if(its==s) break;
        }
        if(izbrisao)
        {
            Izbrisi(mapa,*itm);
            itm=mapa.begin();
        }
        else itm++;
    }
}

Stak IzbaciKarteRazbrajanjem(Cvor* &spil, short int &r, int &b)
{
    Stak stek; 
    try
    {
        IspravnaLista(spil);
    }
    catch(...)
    {
        throw;
    }
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    int broj(0);
    auto it=spil;
    
    std::vector<std::string> v{"Pik","Tref","Herc","Karo"};
    while(true)
    {
        auto prethodni=it;
        prethodni=prethodni->sljedeci;
        if(prethodni==prethodni->sljedeci) 
        {
            std::pair<std::string,std::string> par;
            par.first=v.at(int(prethodni->karta.boja));
            par.second=prethodni->karta.vrijednost;
            stek.push(par);
            delete prethodni;
            spil=nullptr;
            break;
        }
        while(prethodni->sljedeci != spil) prethodni=prethodni->sljedeci;
        for(int i=0;i<r-1;i++)
        {
            prethodni=it;
            it=it->sljedeci;
        }
        std::pair<std::string,std::string> par;
        par.first=v.at(int(it->karta.boja));
        par.second=it->karta.vrijednost;
        stek.push(par);
        
        prethodni->sljedeci=it->sljedeci;
        if(it==spil) 
        {
            spil=it->sljedeci;
            prethodni->sljedeci=spil;
        }
        auto pom=it;
        it=it->sljedeci;
        delete pom;
        broj++;
        if(broj==b) break;
        if(BrojKarti(spil)==0) break;
    }
    return stek;
}
void Zamijeni(Cvor* prethodni1, Cvor* it,Cvor* prethodni2, Cvor* itt)
{
    if(itt!=it->sljedeci && prethodni2!=it) //nesusjedne karte
    {
        prethodni1->sljedeci=itt;
        auto pom=it->sljedeci;
        it->sljedeci=itt->sljedeci;
        itt->sljedeci=pom;
        prethodni2->sljedeci=it;
    }
    else //susjedne karte
    {
        prethodni1->sljedeci=itt;
        auto pom=itt->sljedeci;
        itt->sljedeci=it;
        it->sljedeci=pom;
    }
}
void SortirajSpil(Cvor* &spil)
{
    if(!spil) return;
    std::vector<std::string> v1{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto it=spil->sljedeci;
    
    while(it!=spil)
    {
        if(int(it->karta.boja)<int(spil->karta.boja)) spil=it;
        else if(int(it->karta.boja)==int(spil->karta.boja))
        {
            auto itf1=std::find(v1.begin(),v1.end(),spil->karta.vrijednost);
            auto itf2=std::find(v1.begin(),v1.end(),it->karta.vrijednost);
            if(itf2<itf1) spil=it;
        }
        it=it->sljedeci;
    }
    
    
    auto prethodni1=spil;
    it=prethodni1->sljedeci;
    while(it!=spil)
    {
        
        auto najmanjaprethodna=prethodni1;
        auto najmanja=it;
        
        auto itt=it->sljedeci;
        auto prethodni2=it;
        while(true)
        {
            if(itt==spil) break;
            if(int(najmanja->karta.boja)>int(itt->karta.boja))
            {
                najmanja=itt;
                najmanjaprethodna=prethodni2;
            }
            else if(int(najmanja->karta.boja)==int(itt->karta.boja))
            {
                auto itf1=std::find(v1.begin(),v1.end(),najmanja->karta.vrijednost);
                auto itf2=std::find(v1.begin(),v1.end(),itt->karta.vrijednost);
                if(itf2<itf1)
                {
                    najmanja=itt;
                    najmanjaprethodna=prethodni2;
                }
            }
            prethodni2=itt;
            itt=itt->sljedeci;
        }
        if(najmanja!=it)
        {
            Zamijeni(najmanjaprethodna,najmanja,prethodni1,it);
            it=najmanja;
            prethodni1=najmanjaprethodna;
        }
        else
        {
            prethodni1=it;
            it=it->sljedeci;
        }
    }
    
}
void VratiPosljednjihNKarata(Cvor* &spil, Stak &stek, int n)
{
    int vel=stek.size();
    
    /**********************Provjera ispravnosti*********************/
    if(n>vel) throw std::range_error("Nedovoljno karata u steku!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    std::vector<std::string> v1{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0;i<vel;i++)
    {
        auto karta=stek.top();
        if(!(karta.first=="Pik" || karta.first=="Tref" || karta.first=="Herc" || karta.first=="Karo")) throw std::logic_error("“Neispravne karte!");
        stek.pop();
        auto it=std::find(v1.begin(),v1.end(),karta.second);
        if(it==v1.end()) throw std::logic_error("Neispravne karte!");
        stek.push(karta);
    }
    
    try
    {
        IspravnaLista(spil);
    }
    catch(...)
    {
        throw;
    }
    /****************************************************************/
    
    /************************Ubacivanje******************************/
    for(int i=0;i<n;i++)
    {
        /**************'par' treba ubaciti u spil******************/
        auto karta=stek.top();
        stek.pop();
        Karta par;
        int broj(0);
        if(karta.first=="Pik") broj=0;
        else if(karta.first=="Tref") broj=1;
        else if(karta.first=="Herc") broj=2;
        else if(karta.first=="Karo") broj=3;
        par.boja=Boje(broj);
        par.vrijednost=karta.second;
        /*********************************************************/
        
        Cvor *novi(new Cvor{par, nullptr});   
        if(!spil)                                                                    
        {
            novi->sljedeci=novi;
            spil=novi;
        }
        
        else 
        {
            auto pom=spil->sljedeci;
            spil->sljedeci=novi;
            novi->sljedeci=pom;
        }
    }
    SortirajSpil(spil);
    
}
void UnistiSpil(Cvor* &spil)
{
    if(spil==nullptr) return;
    auto pom=spil;
    while(true)
    {
        auto pom2=pom;
        pom=pom->sljedeci;
        delete pom2;
        if(pom==spil) break;
    }
}
void Ispis(Cvor* &spil)
{
    int n=BrojKarti(spil);
    std::cout<<"U spilu trenutno ima "<<n<<" karata, i to: ";
    std::cout<<std::endl;
    auto it=spil;
    std::cout<<"Pik: ";
    for(int i=0;i<n;i++)
    {
        if(int(it->karta.boja)==0) std::cout<<it->karta.vrijednost<<" ";
        else break;
        it=it->sljedeci;
    }
    std::cout<<std::endl;
    std::cout<<"Tref: ";
    for(int i=0;i<n;i++)
    {
        if(int(it->karta.boja)==1) std::cout<<it->karta.vrijednost<<" ";
        else break;
        it=it->sljedeci;
    }
    std::cout<<std::endl;
    std::cout<<"Herc: ";
    for(int i=0;i<n;i++)
    {
        if(int(it->karta.boja)==2) std::cout<<it->karta.vrijednost<<" ";
        else break;
        it=it->sljedeci;
    }
    std::cout<<std::endl;
    std::cout<<"Karo: ";
    for(int i=0;i<n;i++)
    {
        if(int(it->karta.boja)==3) std::cout<<it->karta.vrijednost<<" ";
        else break;
        it=it->sljedeci;
    }
    std::cout<<std::endl;
}

int main ()
{/*
    auto s=KreirajSpil();
    Mapa mapa;
    std::pair<Boje,std::string> par;
    
    par.first=Boje(0);
    par.second="2";
    mapa.insert(par);
    mapa.insert(par);
    
    par.first=Boje(0);
    par.second="3";
    mapa.insert(par);
    mapa.insert(par);
    
    par.first=Boje(0);
    par.second="4";
    mapa.insert(par);
    mapa.insert(par);
    mapa.insert(par);
    mapa.insert(par);
    
    par.first=Boje(0);
    par.second="5";
    mapa.insert(par);
    mapa.insert(par);
    mapa.insert(par);
    
    par.first=Boje(0);
    par.second="6";
    mapa.insert(par);
    mapa.insert(par);
    
    par.first=Boje(1);
    par.second="7";
    mapa.insert(par);
    mapa.insert(par);
    
    std::cout<<"Velicina: "<<mapa.size()<<std::endl;
    IzbaciKarte(s,mapa);
    std::cout<<"Velicina: "<<mapa.size()<<std::endl;
    Cvor* pom=s;
    std::cout<<"Broj: "<<BrojKarti(s)<<std::endl;
    if(BrojKarti(s)>0)
    {
        while(true)
        {
            std::cout<<"("<<int(pom->karta.boja)<<","<<pom->karta.vrijednost<<") ";
            if(int(pom->karta.boja) != int(pom->sljedeci->karta.boja)) std::cout<<std::endl;
            pom=pom->sljedeci;
            if(pom==s) break;
        }
    }
    else std::cout<<"maa"<<std::endl;
    UnistiSpil(s);*/
    auto s=KreirajSpil();
    try
    {
        short int r;
        int b;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        auto red=IzbaciKarteRazbrajanjem(s,r,b);
        Ispis(s);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPosljednjihNKarata(s,red,n);
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
    
    UnistiSpil(s);
    return 0;
}