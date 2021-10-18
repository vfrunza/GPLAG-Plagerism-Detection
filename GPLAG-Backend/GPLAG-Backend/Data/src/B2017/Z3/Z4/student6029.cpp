/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
#include <queue>
#include <vector>

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

void IspisiRed( queue<pair<string, string>> karte)
{
    while(!karte.empty())
    {
        auto k=karte.front();
        cout<<k.first<<" "<<k.second<<endl;
        karte.pop();
    }
}

list<pair<Boje, string>> KreirajSpil()
{
    list<pair<Boje, string>> spil;
    vector<string> karte={"2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(int i=0; i<4; i++)
        for(int j=0; j<karte.size(); j++)
                spil.push_back(make_pair(Boje(i), karte[j]));
                
    return spil;
}


void IzbaciKarte(list<pair<Boje, string>> &spil, multimap<Boje, string> &karte)
{
    if(spil.size()>52) throw logic_error("Neispravna lista!");
    
    for(auto i=spil.begin(); i!=spil.end(); i++)
        for(auto j=karte.begin(); j!=karte.end(); j++)
            if(i->first==j->first && i->second==j->second)
                    i=spil.erase(i);
   
}

queue<pair<string, string>> IzbaciKarteRazbrajanjem(list<pair<Boje, string>> &spil, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1) throw logic_error ("Neispravni elementi za izbacivanje!");
    
    int korak_razbrajanja=r, broj_karata_za_izbacivanje=b;
    
    if(broj_karata_za_izbacivanje>spil.size()) 
        broj_karata_za_izbacivanje=spil.size();
    
    queue<pair<string, string>> karte; 
    
    auto i=spil.begin(); int brojac=1;
    while(broj_karata_za_izbacivanje!=0)
    {
        if(i==spil.end())
            i=spil.begin();
        if(brojac==korak_razbrajanja)
            {
                if(i->first==Boje::Pik) karte.push(make_pair("Pik", i->second));
                else if(i->first==Boje::Tref) karte.push(make_pair("Tref", i->second));
                else if(i->first==Boje::Herc) karte.push(make_pair("Herc", i->second));
                else  karte.push(make_pair("Karo", i->second));
                
                i=spil.erase(i);
                i--;
                brojac=0;
                broj_karata_za_izbacivanje--;
            }
                
        brojac++; i++; 
        
    }
    
    return karte;
}

void VratiPrvihNKarata(list<pair<Boje, string>> &spil, queue<pair<string, string>> &izbacene_karte, int n)
{
    if(n<0 || n>52) throw domain_error ("Broj n je besmislen!");
    if (n>izbacene_karte.size()) throw range_error ("Nedovoljno karata u redu!");
     if(n==0) return;
     if(n==izbacene_karte.size())
     {
         spil=KreirajSpil();
         return;
     }
    //USLOV ZA BESMISLENE
     vector<string> v={"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
     queue<pair<string, string>> provjeri=izbacene_karte;
     while(!provjeri.empty())
     {
         bool uredu=false;
         pair<string, string> pom=provjeri.front();
         for(int i=0; i<v.size(); i++)
            if(pom.second==v[i])
                uredu=true;
        if(!uredu)
            throw logic_error("Neispravne karte!");
        
        if(pom.second!="Herc")
            if(pom.second!="Karo")
                if(pom.second!="Pik")
                    if(pom.second!="Tref")
                        throw logic_error("Neispravne karte!");
        provjeri.pop();
     }
 
    for(int i=0; i<n; i++)
        izbacene_karte.pop();

    Boje b;
    multimap<Boje, string> mapa;
    auto pom=izbacene_karte;
    while(!pom.empty())
    {
        auto k=pom.front();
        if(k.first=="Pik") b=Boje::Pik;
        if(k.first=="Tref") b=Boje::Tref;
        if(k.first=="Herc") b=Boje::Herc;
        if(k.first=="Karo") b=Boje::Karo;
        
        mapa.insert(make_pair(b, k.second));
        pom.pop();
    }
    auto pom_spil=KreirajSpil();
    IzbaciKarte(pom_spil, mapa);
    spil=pom_spil;
}


int main ()
{
    
    cout<<"Unesite korak razbrajanja: ";
    int korak;
    cin>>korak;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int br_karata_za_izbaciti;
    cin>>br_karata_za_izbaciti;
    try
    {
        list<pair<Boje, string>> spil;
        queue<pair<string, string>> izbacene_karte;
        
        spil=KreirajSpil();
        izbacene_karte=IzbaciKarteRazbrajanjem(spil, korak, br_karata_za_izbaciti);
        cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<endl;
        
        cout<<"Pik: ";
        for(auto i=spil.begin(); i!=spil.end(); i++)
            if(i->first==Boje::Pik)
                cout<<i->second<<" ";
        cout<<endl<<"Tref: ";
        for(auto i=spil.begin(); i!=spil.end(); i++)
            if(i->first==Boje::Tref)
                cout<<i->second<<" ";
        cout<<endl<<"Herc: ";
        for(auto i=spil.begin(); i!=spil.end(); i++)
            if(i->first==Boje::Herc)
                cout<<i->second<<" ";
        cout<<endl<<"Karo: ";
        for(auto i=spil.begin(); i!=spil.end(); i++)
            if(i->first==Boje::Karo)
                cout<<i->second<<" ";  
        
    cout<<endl<<"Unesite broj karata koje zelite vratiti u spil: ";
    int br_karata_za_vratiti;
    cin>>br_karata_za_vratiti;
    VratiPrvihNKarata(spil, izbacene_karte, br_karata_za_vratiti);
    cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<endl;
    
    cout<<"Pik: ";
        for(auto i=spil.begin(); i!=spil.end(); i++)
            if(i->first==Boje::Pik)
                cout<<i->second<<" ";
        cout<<endl<<"Tref: ";
        for(auto i=spil.begin(); i!=spil.end(); i++)
            if(i->first==Boje::Tref)
                cout<<i->second<<" ";
        cout<<endl<<"Herc: ";
        for(auto i=spil.begin(); i!=spil.end(); i++)
            if(i->first==Boje::Herc)
                cout<<i->second<<" ";
        cout<<endl<<"Karo: ";
        for(auto i=spil.begin(); i!=spil.end(); i++)
            if(i->first==Boje::Karo)
                cout<<i->second<<" "; 
    }
    catch(logic_error l) {cout<<"Izuzetak: "<<l.what();}
    catch(domain_error d) {cout<<"Izuzetak: "<<d.what();}
    catch(range_error r) {cout<<"Izuzetak: "<<r.what();}
	return 0;
}
