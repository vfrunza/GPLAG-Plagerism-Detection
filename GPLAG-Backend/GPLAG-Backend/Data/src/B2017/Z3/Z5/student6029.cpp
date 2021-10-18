/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <stdexcept>


using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

struct Karta
{
    Boje boje;
    string vrijednost;
};

struct Cvor
{
    Karta karta;
    Cvor *sljedeci;
};

void UnistiSpil(Cvor* spil)
{
    Cvor* poc=spil;
    Cvor* pom=spil->sljedeci;
    while(pom->sljedeci!=spil)
    {
        delete poc;
        poc=pom;
        pom=pom->sljedeci;
    }
    delete poc;
    delete pom;
}


int PrebrojiKarte(Cvor *spil)
{
    if (spil==nullptr) return 0;
    Cvor *pom=spil;
    int br=1;
    while(pom->sljedeci!=spil)
    {
        br++;
        pom=pom->sljedeci;
    }
    return br;
}

void IspisiListu(Cvor *karte)
{
    Cvor *pom=karte;
    while(pom->sljedeci!=karte)
    {
        cout<<pom->karta.vrijednost<<" ";
        pom=pom->sljedeci;
    }
    cout<<pom->karta.vrijednost<<endl;
}

void IspisiStack(stack<pair<string, string>> karte)
{
    while(!karte.empty())
    {
        pair<string, string> pom=karte.top();
        cout<<pom.first<<" "<<pom.second<<endl;
        karte.pop();
    }
}

Cvor* KreirajSpil()
{
    vector<string> v1={"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}, v2={"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    Cvor *karta=nullptr;
    Cvor *t=karta;
    try
    {
        Cvor *novi=new Cvor;
        novi->karta.vrijednost=v1[0];
        novi->karta.boje=Boje(0);
        karta=novi;
        t=novi;
        try
        {   
            for(int k=0; k<4; k++)
            {
                vector<string> v=v1;
                if(k==0) v=v2;
                for(int i=0; i<v.size(); i++)
                {
                    Cvor *novi= new Cvor;
                    novi->karta.vrijednost=v[i];
                    novi->karta.boje=Boje(k);
                    t->sljedeci=novi;
                    t=novi;
                    //delete novi;
                }
            }
            t->sljedeci=karta;
            return karta;
        }
        catch(...){ throw "Izuzetak"; }
    }
    catch(...){ throw bad_alloc(); }
}


Cvor* IzbaciKarte(Cvor* &spil, multimap<Boje, string> &karte)
{
    Cvor *pom=spil;
    while (pom->sljedeci!=spil)
    {
        for(auto i=karte.begin(); i!=karte.end(); i++)
        {
            if(pom->karta.boje==i->first && pom->karta.vrijednost==i->second)
            {
                Cvor *pom2=pom->sljedeci;
                
                while(pom2->sljedeci!=pom)
                    pom2=pom2->sljedeci;
                pom2->sljedeci=pom->sljedeci;
                if(pom!=nullptr)
                    delete pom;
                pom=pom2;
            }
        }
    pom=pom->sljedeci;
    }
    //Zadnja karta
    for(auto i=karte.begin(); i!=karte.end(); i++)
        if(pom->karta.boje==i->first && pom->karta.vrijednost==i->second)
        {
             Cvor *pom2=pom->sljedeci;
            
             while(pom2->sljedeci!=pom)
                pom2=pom2->sljedeci;
             pom2->sljedeci=pom->sljedeci;
            if(pom!=nullptr)
                delete pom;
            pom=pom2;
        }
    pom=pom->sljedeci;
    //delete pom; 
    return pom;
}


stack<pair<string, string>> IzbaciKarteRazbrajanjem(Cvor* &spil, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1) UnistiSpil(spil);
    if(r<1 || r>52 || b<1) throw logic_error ("Neispravni elementi za izbacivanje!");
    
    int korak_razbrajanja=r, broj_karata_za_izbacivanje=b;
    
    if(broj_karata_za_izbacivanje>PrebrojiKarte(spil)) 
        broj_karata_za_izbacivanje=PrebrojiKarte(spil);
    
    stack<pair<string, string>> karte;
    int brojac=1;
    Cvor *pom=spil;
    while(broj_karata_za_izbacivanje>0)
    {
        if(brojac==korak_razbrajanja)
        {
            if(pom->karta.boje==Boje::Pik) karte.push(make_pair("Pik", pom->karta.vrijednost));
            else if(pom->karta.boje==Boje::Tref) karte.push(make_pair("Tref", pom->karta.vrijednost));
            else if(pom->karta.boje==Boje::Herc) karte.push(make_pair("Herc", pom->karta.vrijednost));
            else  karte.push(make_pair("Karo", pom->karta.vrijednost));
            
            Cvor *pom2=pom->sljedeci, *pom3=spil;
            
            while(pom3->sljedeci!=pom)
                pom3=pom3->sljedeci;
                
            pom3->sljedeci=pom2;
            delete pom;
            pom=pom3;
            
            brojac=0;
            broj_karata_za_izbacivanje--;
        }
        pom=pom->sljedeci; brojac++;
    }
    return karte;
}

void VratiPosljednjihNKarata(Cvor* &spil, stack<pair<string, string>> &izbacene, int n)
{
    if(n<0 || n>52) UnistiSpil(spil);
    if(n<0 || n>52) throw domain_error ("Broj n je besmislen!");
    if (n>izbacene.size()) UnistiSpil(spil);
    if (n>izbacene.size()) throw range_error ("Nedovoljno karata u steku!");
     if(n==0) return;
     if(n==izbacene.size())
     {
         UnistiSpil(spil);
         spil=KreirajSpil();
         return;
     }
     
     //USLOV ZA BESMISLENE
     vector<string> v={"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
     stack<pair<string, string>> provjeri=izbacene;
     while(!provjeri.empty())
     {
         bool uredu=false;
         pair<string, string> pom=provjeri.top();
         for(int i=0; i<v.size(); i++)
            if(pom.second==v[i])
                uredu=true;
        if(!uredu)
        {
            UnistiSpil(spil);
            throw logic_error("Neispravne karte!");
        }
        
        if(pom.first!="Herc")
            if(pom.first!="Karo")
                if(pom.first!="Pik")
                    if(pom.first!="Tref")
                    {
                        UnistiSpil(spil);
                        throw logic_error("Neispravne karte!");
                    }
        provjeri.pop();
     }
     
     provjeri=izbacene;
     int za_izbaciti=n;
     for(int i=0; i<za_izbaciti; i++)
        provjeri.pop();
    multimap<Boje, string> mapa;
     while(!provjeri.empty())
     {
         pair<string, string> s=provjeri.top();
         Boje b;
         if(s.first=="Pik") b=Boje::Pik;
         else if(s.first=="Karo") b=Boje::Karo;
         else if(s.first=="Tref") b=Boje::Tref;
         else b=Boje::Herc;
         
         mapa.insert(make_pair(b, s.second));
         provjeri.pop();
     }
     UnistiSpil(spil);
     spil=KreirajSpil();
     spil=IzbaciKarte(spil, mapa);
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
        Cvor* spil;
        stack<pair<string, string>> izbacene_karte;
        
        spil=KreirajSpil();
        izbacene_karte=IzbaciKarteRazbrajanjem(spil, korak, br_karata_za_izbaciti);
        cout<<"U spilu trenutno ima "<<PrebrojiKarte(spil)<<" karata, i to: "<<endl;
        Cvor *pom=spil;
        cout<<"Pik: ";
        while(pom->sljedeci!=spil)
        {
            if(pom->karta.boje==Boje::Pik)
                cout<<pom->karta.vrijednost<<" ";
            pom=pom->sljedeci;
        }
        cout<<endl<<"Tref: ";
        pom=spil;
        while(pom->sljedeci!=spil)
        {
            if(pom->karta.boje==Boje::Tref)
                cout<<pom->karta.vrijednost<<" ";
            pom=pom->sljedeci;
        }
        cout<<endl<<"Herc: ";
        pom=spil;
        while(pom->sljedeci!=spil)
        {
            if(pom->karta.boje==Boje::Herc)
                cout<<pom->karta.vrijednost<<" ";
            pom=pom->sljedeci;
        }
        cout<<endl<<"Karo: ";
        pom=spil;
        while(pom->sljedeci!=spil)
        {
            if(pom->karta.boje==Boje::Karo)
                cout<<pom->karta.vrijednost<<" ";
            pom=pom->sljedeci;
        }  
        if(pom->karta.boje==Boje::Karo)
                cout<<pom->karta.vrijednost<<" ";
    cout<<endl<<"Unesite broj karata koje zelite vratiti u spil: ";
    int br_karata_za_vratiti;
    cin>>br_karata_za_vratiti;
    VratiPosljednjihNKarata(spil, izbacene_karte, br_karata_za_vratiti);
    cout<<"U spilu trenutno ima "<<PrebrojiKarte(spil)<<" karata, i to: "<<endl;
    
    pom=spil;
        cout<<"Pik: ";
        while(pom->sljedeci!=spil)
        {
            if(pom->karta.boje==Boje::Pik)
                cout<<pom->karta.vrijednost<<" ";
            pom=pom->sljedeci;
        }
        cout<<endl<<"Tref: ";
        pom=spil;
        while(pom->sljedeci!=spil)
        {
            if(pom->karta.boje==Boje::Tref)
                cout<<pom->karta.vrijednost<<" ";
            pom=pom->sljedeci;
        }
        cout<<endl<<"Herc: ";
        pom=spil;
        while(pom->sljedeci!=spil)
        {
            if(pom->karta.boje==Boje::Herc)
                cout<<pom->karta.vrijednost<<" ";
            pom=pom->sljedeci;
        }
        cout<<endl<<"Karo: ";
        pom=spil;
        while(pom->sljedeci!=spil)
        {
            if(pom->karta.boje==Boje::Karo)
                cout<<pom->karta.vrijednost<<" ";
            pom=pom->sljedeci;
        }  
        if(pom->karta.boje==Boje::Karo)
                cout<<pom->karta.vrijednost<<" ";
    UnistiSpil(spil); 
    return 0;
    }
    catch(logic_error l) {cout<<"Izuzetak: "<<l.what();}
    catch(domain_error d) {cout<<"Izuzetak: "<<d.what();}
    catch(range_error r) {cout<<"Izuzetak: "<<r.what();}
}