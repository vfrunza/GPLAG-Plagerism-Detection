/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include <stack>
#include <utility>


enum class Boje{Pik, Tref, Herc, Karo};

std::vector<std::string> vrijednostiKarata{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};


struct Karta{
    Boje boja;
    std::string vrijednost;
};

struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};


void UnistiSpil(Cvor *prvi){
  
    if(prvi==nullptr) return;
    
    Cvor *p=prvi;
    p=p->sljedeci;
    if(p==prvi) {delete prvi; return;}
    prvi->sljedeci=nullptr;
   
    while(p){
        auto sl=p->sljedeci;
        delete p;
        p = nullptr;
        p=sl;
    }
}

void Izuzeci(Cvor *prvi){
    if(!prvi) return;
    Cvor *p=nullptr;
    Cvor *q=nullptr;
    p=prvi;
    int h=0;
    do{
        h++;
        if(p->sljedeci==nullptr) {UnistiSpil(prvi); throw std::logic_error("Neispravna lista!");}
        p=p->sljedeci;
        if(h>52)  {UnistiSpil(prvi); throw std::logic_error("Neispravna lista!");}
    }while(p!=prvi);
    int koliko(0);
 
    do{
        p=p->sljedeci;
        koliko++;
    }while(p!=prvi);
    
    if(koliko>52) {UnistiSpil(prvi); throw std::logic_error("Neispravna lista!");}
    
    p=prvi;
    //neispravni
    do{
        if(p->karta.boja!=Boje::Pik && p->karta.boja!=Boje::Tref && p->karta.boja!=Boje::Herc && p->karta.boja!=Boje::Herc && p->karta.boja!=Boje::Karo) {UnistiSpil(prvi); throw std::logic_error("Neispravna lista!");}
        int i=0;
        for(i=0; i<13; i++)
            if(p->karta.vrijednost==vrijednostiKarata.at(i)) break;
        
        if(i==13) {UnistiSpil(prvi); throw std::logic_error("Neispravna lista!");}
        p=p->sljedeci;
    }while(p!=prvi);
    
    p=prvi;
    q=prvi;
    q=q->sljedeci;
    //sort
    do{
        if(int(p->karta.boja)<=int(q->karta.boja)){
            p=p->sljedeci;
            q=q->sljedeci;
        } 
        else if(int(p->karta.boja)==int(q->karta.boja)){
            int broj1(0);
            int broj2(0);
            for(int i=0; i<13; i++){
                if(p->karta.vrijednost == vrijednostiKarata.at(i)) broj1=i;
                if(q->karta.vrijednost == vrijednostiKarata.at(i)) broj2=i;
            }
            if(broj2<=broj1) {UnistiSpil(prvi); throw std::logic_error("Neispravna lista!");}
        }
        else {UnistiSpil(prvi); throw std::logic_error("Neispravna lista!");}
    }while(q!=prvi);
}


Cvor *KreirajSpil(){
    Cvor* pocetak=nullptr, *prethodni;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            Cvor* novi=new Cvor;
            novi->karta.boja=Boje(i);
            novi->karta.vrijednost=vrijednostiKarata.at(j);
            novi->sljedeci=nullptr;
            if(!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
            if(i==3 && j==12) prethodni->sljedeci=pocetak;
        }
    }
    return pocetak;
}

void IzbaciKarte(Cvor *&prvi, std::multimap<Boje, std::string> &mapa){
    if(!prvi) return;
    Cvor *p=nullptr;
    Cvor *q=nullptr;
    p=prvi;
    try{
        Izuzeci(prvi);
    }
    catch(std::logic_error e){
        throw;
    }
     
    p=prvi;
    
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        p=prvi;
        q=prvi;
        q=q->sljedeci;
        do{
            if(q->karta.boja==it->first && q->karta.vrijednost==it->second){
                mapa.erase(it);
                p->sljedeci=q->sljedeci;
                if(q==prvi) prvi = q->sljedeci;
                delete q;
                break;
                
            }
            p=p->sljedeci;
            q=q->sljedeci;
        }while(1);
    }
    
    
}


std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Cvor *&prvi, short int &r, int &b){
    try{
        Izuzeci(prvi);
    }
    catch(std::logic_error e){
        throw;
    }
    if(r<1 || r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    else if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    std::stack<std::pair<std::string, std::string>> povratni;
    int koliko(0);
    Cvor *p=prvi;
    Cvor *q=prvi;
    q=q->sljedeci;
    int k=0;
    
    do{
        p=p->sljedeci;
        k++;
    }while(p!=prvi);
    
    if(b>k) {
        p=prvi;
        do{
            std::string pomocni;
                if(p->karta.boja==Boje::Pik) pomocni="Pik";
                else if (p->karta.boja==Boje::Tref) pomocni="Tref";
                else if (p->karta.boja==Boje::Herc) pomocni="Herc";
                else if (p->karta.boja==Boje::Karo) pomocni="Karo";
                povratni.push(std::make_pair(pomocni, p->karta.vrijednost));
        p=p->sljedeci;
       
    }while(p!=prvi);
    UnistiSpil(prvi);
    return povratni;
    }
    
    
    p=prvi;
    while(koliko!=b){
        int dokle(1);
        while(dokle!=r){
            dokle++;
            if(dokle==r){
                std::string pomocni;
                if(q->karta.boja==Boje::Pik) pomocni="Pik";
                else if (q->karta.boja==Boje::Tref) pomocni="Tref";
                else if (q->karta.boja==Boje::Herc) pomocni="Herc";
                else if (q->karta.boja==Boje::Karo) pomocni="Karo";
                
                povratni.push(std::make_pair(pomocni, q->karta.vrijednost));
                p->sljedeci=q->sljedeci;
                if(q==prvi) prvi = q->sljedeci;
                delete q;
                
                
            }
            p=p->sljedeci;
            q=p->sljedeci;
        }
        koliko++;
    }
    return povratni;
}
bool TacanStek(std::stack<std::pair<std::string, std::string>> stek){
    int vel=stek.size();
    for(int i=0; i<vel; i++){
        bool logicka=false;
        std::pair<std::string, std::string> pom=stek.top();
        if(pom.first!="Pik" && pom.first!="Tref" && pom.first!="Herc" && pom.first!="Karo") return false;
        for(int j=0; j<13; j++)
            if(pom.second==vrijednostiKarata.at(j)) logicka=true;
        
        if(!logicka) return false;
        stek.pop();
    }
}
void VratiPosljednjihNKarata(Cvor *&prvi, std::stack<std::pair<std::string, std::string>> &stek, int n){
    
    if(n>(int)stek.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    
   /* if(!TacanStek(stek)){
        UnistiSpil(prvi);
        throw std::logic_error("Neispravne karte!");
    }*/
    
    
    Izuzeci(prvi);
    
    Cvor *p=prvi;
    Cvor *q=prvi;
    q=prvi->sljedeci;
    
    
    int i=0;
    while(i<=n){
       
        std::pair<std::string, std::string> pomocni=stek.top();
        Boje ubaciBoju;
        if(pomocni.first=="Pik") ubaciBoju=Boje::Pik;
        else if(pomocni.first=="Tref") ubaciBoju=Boje::Tref;
        else if(pomocni.first=="Herc") ubaciBoju=Boje::Herc;
        else if(pomocni.first=="Karo") ubaciBoju=Boje::Karo;
        
        std::string ubaciString=pomocni.second;
        int kojiString;
        for(int i=0; i<13; i++) if(ubaciString==vrijednostiKarata.at(i)) kojiString=i;
        int ubacujem;
        for(int i=0; i<13; i++) if(p->karta.vrijednost==vrijednostiKarata.at(i)) ubacujem=i;
        p=prvi;
        bool nema=false;
        do{
            
            if(p->karta.boja==ubaciBoju && p->karta.vrijednost==ubaciString){ nema=true; break;}
            p=p->sljedeci;
        }while(p!=prvi);
        
        p=prvi;
       if(!nema){
            i++;
            
            int broj(0);
            for(int i=0; i<13; i++) if(q->karta.vrijednost==vrijednostiKarata.at(i)) broj=i;
            do{
                q=p->sljedeci;
                if(p->karta.boja<ubaciBoju){
                   Cvor *novi=new Cvor;
                   novi->sljedeci=p->sljedeci;
                   p->sljedeci=novi;
                   p=p->sljedeci;
                   novi->karta.boja=ubaciBoju;
                   novi->karta.vrijednost=ubaciString;
                   break;
                }
                else if(p->karta.boja==ubaciBoju && ubacujem<kojiString && broj>kojiString){
                    Cvor *novi=new Cvor;
                   novi->sljedeci=p->sljedeci;
                   p->sljedeci=novi;
                   p=p->sljedeci;
                   novi->karta.boja=ubaciBoju;
                   novi->karta.vrijednost=ubaciString;
                   break;
                }
                
                p=p->sljedeci;
            }while(p!=prvi);
        }
        stek.pop();
    }
}
int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    short int r(0);
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin>>b;
    Cvor *prvi;
    prvi=KreirajSpil();
    std::stack<std::pair<std::string, std::string>> stek;
    try{
    stek=IzbaciKarteRazbrajanjem(prvi, r, b);
    }
    catch(std::logic_error e){
        std::cout<<e.what();
        return 0;
    }
    std::cout<<"U spilu ima trenutno "<<52-stek.size()<<" karata, i to:"<<std::endl;
    Cvor *p=prvi;
    do{
        if(p->karta.boja==Boje::Pik) std::cout<<"Pik: ";
        while(p->karta.boja==Boje::Pik) {
            std::cout<<p->karta.vrijednost<<" ";
            p=p->sljedeci;
        }
        std::cout<<std::endl;
        if(p->karta.boja==Boje::Tref) std::cout<<"Tref: ";
        while(p->karta.boja==Boje::Tref) {
            std::cout<<p->karta.vrijednost<<" ";
            p=p->sljedeci;
        }
        std::cout<<std::endl;
        if(p->karta.boja==Boje::Herc) std::cout<<"Herc: ";
        while(p->karta.boja==Boje::Herc) {
            std::cout<<p->karta.vrijednost<<" ";
            p=p->sljedeci;
        }
        std::cout<<std::endl;
        if(p->karta.boja==Boje::Karo) std::cout<<"Karo: ";
        while(p->karta.boja==Boje::Karo) {
            std::cout<<p->karta.vrijednost<<" ";
            p=p->sljedeci;
        }
        
    }while(p!=prvi);
    std::cout<<std::endl;
    p=prvi;
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int n(0);
    std::cin>>n;
    int k(0);
   
    p=prvi;
  
     try{
    VratiPosljednjihNKarata(prvi,stek,  n);
    }
    
   
    catch(std::range_error e){
        std::cout<<e.what();
        return 0;
    }
    catch(std::domain_error e){
        std::cout<<e.what();
        return 0;
    }
    catch(std::logic_error e){
        std::cout<<e.what();
        return 0;
    }
     do{
        p=p->sljedeci;
        k++;
    }while(p!=prvi);
    std::cout<<"U spilu trenutno ima "<<k<<" karata, i to:"<<std::endl;
    p=prvi;
    std::cout<<"Pik: ";
    do{
        if(p->karta.boja==Boje::Pik) std::cout<<p->karta.vrijednost<<" ";
        p=p->sljedeci;
    }while(p!=prvi);
    std::cout<<std::endl;
      p=prvi;
    std::cout<<"Tref: ";
    do{
        if(p->karta.boja==Boje::Tref) std::cout<<p->karta.vrijednost<<" ";
        p=p->sljedeci;
    }while(p!=prvi);
    
    std::cout<<std::endl;
    
      p=prvi;
    std::cout<<"Herc: ";
    do{
        if(p->karta.boja==Boje::Herc) std::cout<<p->karta.vrijednost<<" ";
        p=p->sljedeci;
    }while(p!=prvi);
    std::cout<<std::endl;
      p=prvi;
    std::cout<<"Karo: ";
    do{
        if(p->karta.boja==Boje::Karo) std::cout<<p->karta.vrijednost<<" ";
        p=p->sljedeci;
    }while(p!=prvi);
    
    UnistiSpil(prvi);
	return 0;
}
