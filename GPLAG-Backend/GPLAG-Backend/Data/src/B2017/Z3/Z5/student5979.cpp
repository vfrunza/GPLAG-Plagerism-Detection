/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <stack>
#include <algorithm>
typedef std::stack<std::pair<std::string,std::string>> RedKarata ;

typedef std::vector<std::string> VS;
enum class Boje {Pik, Tref, Herc, Karo};
struct Karta{
    Boje boja;
    std::string vrijednost;
};
struct Cvor{
    Karta karta;
    Cvor* sljedeci;
};


void ispravna_lista( Cvor* p1){
    if(p1!=nullptr){
    VS karteee={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::vector<Boje> sve_boje={Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
    Cvor *p2(p1);
    int brojac = 0;
        auto it2(karteee.begin());
        auto it3=sve_boje.begin();
        do{
            bool ispravan(false);
            while (it3!=sve_boje.end() && *it3!=p2->karta.boja ){
                it3++;
                it2=karteee.begin();
            }
            while (it2!=karteee.end() && *it2!=p2->karta.vrijednost )
                it2++;
            if(it2!=karteee.end() && it3!=sve_boje.end()  && *it2==p2->karta.vrijednost && *it3==p2->karta.boja)
                ispravan=true;
            if(!ispravan)
                throw std::logic_error("Neispravna lista!");
            brojac++;
            p2=p2->sljedeci;
            if(brojac>52)
                throw std::logic_error("Neispravna lista!");
        }while (p1!=p2);
    }
}


Cvor * KreirajSpil(){
    VS karteee={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    Cvor* pocetak=nullptr;
    Cvor* iza;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if(i==0 and j==0 ){
                pocetak=new Cvor{Karta{Boje(i),karteee[j]},nullptr };
                iza=pocetak;
            }
            else{
                iza->sljedeci=new Cvor{Karta{Boje(i),karteee[j]},pocetak };
                iza=iza->sljedeci;
            }
        }
    }
    return pocetak;
}
void IzbaciKarte(Cvor *&p1,std::multimap<Boje,std::string> &za_izbaciti){
    
    if(p1!=nullptr)
        throw std::logic_error("Neispravna lista!");
     Cvor *p2=p1,*p3 ;
     int velicina=za_izbaciti.size();
     while (p3->sljedeci!=p2) {
            p3=p3->sljedeci;
        }
     for (int i = 0; i < 4; i++) {
        while(p2->karta.boja!=Boje(i)&& p2->sljedeci!=p1) {
        p3=p2;
        p2=p2->sljedeci;
        }
        while (p2->karta.boja==Boje(i)) {
        auto  it = za_izbaciti.lower_bound(Boje(i));    
        while (it!=za_izbaciti.end()  &&(it->second)!=(p2->karta.vrijednost)&&it->first==Boje(i))   it++; 
        while (it!=za_izbaciti.end()  &&(it->second)==(p2->karta.vrijednost)&&it->first==Boje(i)){
            it=za_izbaciti.erase(it);
        }
        if(za_izbaciti.size()!=velicina)
            velicina=za_izbaciti.size();
        Cvor* p3=p2;
        if(p2==p2->sljedeci){
            delete p2;
            p1=nullptr;
            break;
        }else if(p2==p1){
            p3->sljedeci=p2->sljedeci;
            p1=p2->sljedeci;
            delete p2;
            p2=p1;
        }else{
            p3->sljedeci=p2->sljedeci;
            delete p2;
            p2=p3->sljedeci;
        }
        }
    }

}
std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(Cvor *&p1,int korak,int br_karata ){
    std::stack<std::pair<std::string,std::string>> Izbacene;
    if(p1==nullptr)
        throw std::logic_error("Neispravna lista!");
    if(korak<1 or br_karata<1 or korak>52)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
        Cvor* p2=p1,*p3=p1;
        VS znakovi{"Pik", "Tref", "Herc", "Karo"};
    while (p3->sljedeci!=p2) {
        p3=p3->sljedeci;
    }
    for (int i = 0; i <br_karata ; i++) {
        if(p2==nullptr)
            break;
        for (int j = 0; j < korak-1; j++) {
            p3=p2;
            p2=p2->sljedeci;
        }
        Izbacene.push(std::make_pair(znakovi[int(p2->karta.boja)],p2->karta.vrijednost));
        if(p2==p2->sljedeci){
            delete p2;
            p1=nullptr;
            p2=nullptr;
            break;
        }else if(p2==p1){
            p3->sljedeci=p2->sljedeci;
            p1=p2->sljedeci;
            delete p2;
            p2=p1;
        }else{
            p3->sljedeci=p2->sljedeci;
            delete p2;
            p2=p3->sljedeci;
        }
    }
    return Izbacene;
}

void VratiPosljednjihhNKarata(Cvor* &spil, RedKarata &vratiti, const int &n){
    VS karte={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    VS boje={"Pik","Tref","Herc","Karo"};
    if(n<0)
        throw std::domain_error("Broj n je besmislen!");
    if(n>vratiti.size())
        throw std::range_error("Nedovoljno karata u steku!");
    ispravna_lista(spil);
    Cvor*q=spil;
    for (int i = 0; i < n; i++) {
        
        auto it1=std::find(boje.begin(),boje.end(),vratiti.top().first);
        auto it3=std::find(karte.begin(),karte.end(),vratiti.top().second);
        if(it3==karte.end())
            throw std::logic_error("Neispravne karte!");
        if(it1==boje.end())
            throw std::logic_error("Neispravne karte!");
        int boja1=it1-boje.begin();
        vratiti.pop();
        if(spil!=nullptr){
             Cvor*q=spil;
        while (q->sljedeci!=spil) {
            q=q->sljedeci;
        }
        auto it=spil;
        
        Cvor *prethodna=q;
        while ( it->sljedeci != spil && int (it->karta.boja)< boja1  ) {prethodna=it; it=it->sljedeci;  }
        while( it->sljedeci != spil &&  it -> karta.boja ==Boje(boja1) && std::find(karte.begin(),karte.end(),it->karta.vrijednost)<it3)
        {prethodna=it; it=it->sljedeci;  }
        if(( it->sljedeci == spil &&  it -> karta.boja ==Boje(boja1) && std::find(karte.begin(),karte.end(),it->karta.vrijednost)<it3))
        {   prethodna=it;
            it=it->sljedeci;
        }
        if(std::find(karte.begin(),karte.end(),it->karta.vrijednost)==it3 && Boje(boja1)==it->karta.boja){}
        else{
            if(it==spil){
                prethodna->sljedeci=new Cvor{Karta{Boje(boja1),karte[it3-karte.begin()]},it};
            }else if(it->sljedeci==it){
                Cvor *aa=it->sljedeci;
                it->sljedeci=new Cvor{Karta{Boje(boja1),karte[it3-karte.begin()]},aa};
                try{
                    ispravna_lista(it);
                    spil=it;
                    q=it->sljedeci;
                }                    
                catch(std::logic_error a){
                        spil=it->sljedeci;
                        q=spil->sljedeci;
                }
            }else{
                prethodna->sljedeci=new Cvor{Karta{Boje(boja1),karte[it3-karte.begin()]},it};
            }
                
        }
            }else{
                spil=new Cvor{Karta{Boje(boja1),karte[it3-karte.begin()]},nullptr};
                spil->sljedeci=spil;
            }
            
        }
}
        
void UnistiSpil(Cvor *&p1){
    Cvor*p=p1;
    while (p->sljedeci!=p1) {
        p=p->sljedeci;
    }
    p->sljedeci=nullptr;
    while (p1!=nullptr) {
        p=p1;
        p1=p->sljedeci;
        delete p;
    }
    
}
int main ()
{
    int r,b;
    Cvor* spil=KreirajSpil(),*p;
    std::cout << "Unesite korak razbrajanja: " ;
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: " ;
    std::cin >> b;
    RedKarata red;
    try{
    red=IzbaciKarteRazbrajanjem(spil,r,b);
    }
    catch(std::logic_error izuzetak){
        UnistiSpil(spil);
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    int n(1);
    p=spil;
    if(p!=nullptr){
     while (p->sljedeci!=spil) {
        p=p->sljedeci;
        n++;
    }
    }else n=0;
    auto it=spil;
    std::cout << "U spilu trenutno ima " <<n <<" karata, i to: " << std::endl;
    for (int i = 0; i < 4; i++) {
        VS boje={"Pik: ","Tref: ","Herc: ","Karo: "};
        std::cout << boje[i];
        if(it!=nullptr){
        while ( it->sljedeci!=spil && it->karta.boja==Boje(i)) {
            std::cout << it->karta.vrijednost<<" ";
             if(it!=it->sljedeci)
             it=it->sljedeci;
             else break;
        }
        if(it->sljedeci==spil)
            std::cout << it->karta.vrijednost<<" ";
        }
        std::cout  << std::endl;
    }
    std::cout << "Unesite broj karata koje zelite vratiti u spil: " ;
    int d;
    std::cin >> d;
    try{
    VratiPosljednjihhNKarata(spil,red,d);
    }
    catch(std::domain_error izuzetak){
        UnistiSpil(spil);
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    catch(std::range_error izuzetak){
        UnistiSpil(spil);
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    catch(std::logic_error izuzetak){
        UnistiSpil(spil);
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    n=1;
    p=spil;
    if(spil!=nullptr){
    while (p->sljedeci!=spil) {
        p=p->sljedeci;
        n++;
    }}else n=0;
    it=spil;
    std::cout << "U spilu trenutno ima " <<n <<" karata, i to: " << std::endl;
    for (int i = 0; i < 4; i++) {
        VS boje={"Pik: ","Tref: ","Herc: ","Karo: "};
        std::cout << boje[i];
        if(it!=nullptr){
        while ( it->sljedeci!=spil && it->karta.boja==Boje(i)) {
            std::cout << it->karta.vrijednost<<" ";
             if(it!=it->sljedeci)
             it=it->sljedeci;
             else break;
        }
        if(it->sljedeci==spil && it->karta.boja==Boje(i))
            std::cout << it->karta.vrijednost<<" ";
        }
        std::cout  << std::endl;
    }
    UnistiSpil(spil);
	return 0;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    
    
    while (p->sljedeci!=spil) {
        p=p->sljedeci;
        n++;
    }
    std::cout << "U spilu trenutno ima " <<n <<" karata, i to: " << std::endl;
    IzbaciKarteRazbrajanjem(spil,1,60);
    Cvor* it=spil;
    for (int i = 0; i < 4; i++) {
        VS boje={"Pik: ","Tref: ","Herc: ","Karo: "};
        std::cout << boje[i];
        if(it!=nullptr){
        while ( it->sljedeci!=spil && it->karta.boja==Boje(i)) {
            std::cout << it->karta.vrijednost<<" ";
             if(it!=it->sljedeci)
             it=it->sljedeci;
             else break;
        }
        if(it->sljedeci==spil)
            std::cout << it->karta.vrijednost<<" ";
        }
        std::cout  << std::endl;
    }
    
	return 0;
}
*/