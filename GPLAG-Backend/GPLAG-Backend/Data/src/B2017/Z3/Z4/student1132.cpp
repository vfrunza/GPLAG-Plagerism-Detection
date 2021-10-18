/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <queue>
#include <stdexcept>
#include <algorithm>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;



enum class Boje {Pik, Tref, Herc, Karo}; 

typedef std::list<std::pair<Boje,std::string>> SpilKarata;

typedef std::pair<Boje,std::string> Karta;

const std::vector<std::string> Nazivi_karata{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

bool SortirajPolozaj(const Karta &karta1, const Karta &karta2){
    
    int pozicija1,pozicija2;
    
    for(int i=0;i<13;i++){
            if(karta1.second==Nazivi_karata.at(i)){
                pozicija1=i;
                break;
            }
        }
        
        for(int i=0;i<13;i++){
            if(karta2.second==Nazivi_karata.at(i)){
                pozicija2=i;
                break;
            }
        }
        
        return pozicija1<pozicija2;
}

template <typename TipBoje>
void SortirajBojuPoPolozaju(SpilKarata &spil, TipBoje boja){
    
    auto it(spil.begin());
    
    while(it->first!=boja) it++;
    
    auto iza_kraja(it);
    
    while(iza_kraja->first==boja) iza_kraja++;
    
    auto it_2(it);
    
    while(it_2!=iza_kraja){
        auto it_3(it_2);
        while(it_3!=iza_kraja){
            if(!(SortirajPolozaj(*it_2,*it_3))){
                
                auto temp(*it_2);
                *it_2=*it_3;
                *it_3=temp;
                
            }
            
            
            it_3++;
        }
        
        it_2++;
    }
    
    
}

int IspredPoBoji(const Karta &Karta1, const Karta &Karta2){
    
    if(Karta1.first==Karta2.first) return 0;
    
    if(Karta1.first==Boje::Pik && Karta2.first!=Boje::Pik) return 1;
    if(Karta1.first==Boje::Tref && Karta2.first!=Boje::Pik && Karta2.first!=Boje::Tref) return 1;
    if(Karta1.first==Boje::Herc && Karta2.first==Boje::Karo) return 1;
    
    return -1;
}

void SortirajSpilPoBoji(SpilKarata &spil){ //...... !!!!
    
    for(auto it=spil.begin();it!=spil.end();it++){
        
        
        
        
        
        
        auto it_2(it);

        it_2++;
        
        //if(it_2!=spil.end()){
        
        while(it_2!=spil.end()){
            
            if(IspredPoBoji(*it_2,*it)==1){
  
                Karta temp=*it;
                *it=*it_2;
                *it_2=temp;

                
            }
            
            it_2++;
        }
        
    //}
    

    }
    
}

SpilKarata KreirajSpil(){
    
    SpilKarata spil;
    
    for(int i=0;i<52;i++){
    if(i<13)
    spil.push_back(std::make_pair(Boje::Pik,Nazivi_karata.at(i)));
    if(i>=13 && i<26)
    spil.push_back(std::make_pair(Boje::Tref,Nazivi_karata.at(i-13)));
    if(i>=26 && i<39)
    spil.push_back(std::make_pair(Boje::Herc,Nazivi_karata.at(i-26)));
    if(i>=39)
    spil.push_back(std::make_pair(Boje::Karo,Nazivi_karata.at(i-39)));
    }
    
    return spil;
}


/* U slučaju da lista sadrži više od 52 elementa, ili ukoliko elementi u listi nisu sortirani kako bi trebali biti, 
ili ukoliko elementi liste sadrže besmislene podatke, funkcija treba baciti izuzetak tipa “logic_error” uz prateći tekst “Neispravna lista!”.
*/

void IzbaciKarte(SpilKarata &spil, std::multimap<Boje,std::string> karte_za_izbacivanje){
  
    int br_karata(0);
  
        for (auto it=spil.begin();it!=spil.end();it++){
            if(it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo ) throw std::logic_error("Neispravna lista!");
            else {
                bool ima_naziv{false};
                for(int i=0;i<13;i++){
                if(it->second==Nazivi_karata.at(i)) {ima_naziv=true; break;}
                }
                if(!ima_naziv) throw std::logic_error("Neispravna lista!");
            }
            br_karata++;
        }
        if(br_karata>52) throw std::logic_error("Neispravna lista!");
        
        if(br_karata!=0){
            
        auto it_spila(spil.begin());
        auto iza_it(it_spila);
        iza_it++;
        
        while(iza_it!=spil.end()){
            
   
            if( IspredPoBoji(*it_spila,*iza_it)==-1 ) throw std::logic_error("Neispravna lista!");
            else if(IspredPoBoji(*it_spila,*iza_it)==0 && !SortirajPolozaj(*it_spila,*iza_it)) throw std::logic_error("Neispravna lista!");
                
            it_spila++;
            iza_it++;
        }
        
        auto it(spil.begin());
        
        while(it!=spil.end()){
            auto it_2(karte_za_izbacivanje.find(it->first));
            if(it_2!=karte_za_izbacivanje.end() && it->second==it_2->second){
                
                while(it_2!=karte_za_izbacivanje.end() && it->second==it_2->second)
                it_2=karte_za_izbacivanje.erase(it_2);
                
                it=spil.erase(it);
                
            }
            
            else it++;
        }
        
        }
}

/* U slučaju da lista sadrži više od 52 elementa, ili ukoliko elementi u listi nisu sortirani kako bi trebali biti, 
ili ukoliko elementi liste sadrže besmislene podatke, funkcija treba baciti izuzetak tipa “logic_error” uz prateći tekst 
“Neispravna lista!”. U slučaju da se traži izbacivanje više karata od onog broja koliko ih zaista ima u špilu, 
postupak se prosto prekida kada špil ostane prazan (tj. izbacuje se onoliko karata koliko ih zaista ima, po opisanom postupku), 
bez prijave ikakve greške. */
 
 

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(SpilKarata &spil, const short int &r, const int &b){
    
    if (r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    
     int br_karata_poc(0);
  
        for (auto it=spil.begin();it!=spil.end();it++){
            if(it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo ) throw std::logic_error("Neispravna lista!");
            else {
                bool ima_naziv{false};
                for(int i=0;i<13;i++)
                if(it->second==Nazivi_karata.at(i)) {ima_naziv=true; break;}
                if(!ima_naziv) throw std::logic_error("Neispravna lista!");
            }
            br_karata_poc++;
        }
        if(br_karata_poc>52) throw std::logic_error("Neispravna lista!");
        
        
        
        auto it_spila(spil.begin());
        auto iza_it(it_spila);
        iza_it++;
        
        while(iza_it!=spil.end()){
            
            
            if( IspredPoBoji(*it_spila,*iza_it)==-1 ) throw std::logic_error("Neispravna lista!");
            else if(IspredPoBoji(*it_spila,*iza_it)==0 && !SortirajPolozaj(*it_spila,*iza_it)) throw std::logic_error("Neispravna lista!");
                
            it_spila++;
            iza_it++;
        }
    
    std::queue<std::pair<std::string, std::string>> red_izbacenih_karata;
    auto it(spil.begin());
   
    
    
    int cnt(0);
    int br_karata(0);
    for(it=spil.begin();it!=spil.end();it++) br_karata++;
    it=spil.begin();
    while(cnt!=b && br_karata!=0){
        for(int i=0;i<r-1;i++){
        if(it==spil.end()) it=spil.begin();
        it++;
        }
        if(it->first==Boje::Pik)
        red_izbacenih_karata.push(std::make_pair("Pik", it->second));
        else if(it->first==Boje::Tref)
        red_izbacenih_karata.push(std::make_pair("Tref", it->second));
        else if(it->first==Boje::Herc)
        red_izbacenih_karata.push(std::make_pair("Herc", it->second));
        else red_izbacenih_karata.push(std::make_pair("Karo", it->second));
        it=spil.erase(it);
        cnt++;
        br_karata--;
    }
    
    return red_izbacenih_karata;
}


 /*Ukoliko je broj n veći od broja elemenata reda, funkcija treba da baci izuzetak tipa “range_error” 
 uz prateći tekst “Nedovoljno karata u redu!”. Ukoliko broj  n ima besmislenu vrijednost, funkcija baca izuzetak tipa “domain_error” 
 sa pratećim tekstom „Broj n je besmislen!“. Ukoliko red sadrži bilo kakve besmislene podatke (tj. podatke koji 
 ne opisuju ni jednu smislenu kartu), funkcija treba da baci izuzetak tipa “logic_error” uz prateći tekst “Neispravne karte!”. 
 Također, slično kao i kod prethodne funkcije, i ovdje treba baciti izuzetak tipa “logic_error” uz prateći tekst “Neispravna lista!” 
 ukoliko lista sadrži preko 52 elemenata, ili ukoliko elementi nisu sortirani onako kako bi trebali biti, 
 ili ukoliko u listi postoje besmisleni elementi. U slučaju da se u steku nalazi neka karta koja se već nalazi u špilu, treba je prosto ignorirati. 
 */
 
void VratiPrvihNKarata(SpilKarata &spil, std::queue<std::pair<std::string,std::string>> &red_izbacenih_karata, int n )
{
    
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red_izbacenih_karata.size()) throw std::range_error("Nedovoljno karata u redu!");
    
    
    for(int i=0;i<red_izbacenih_karata.size();i++){
        auto it=&red_izbacenih_karata.front();
        if(it->first!="Pik" && it->first!="Tref" && it->first!="Herc" && it->first!="Karo") throw std::logic_error("Neispravne karte!");
            else {
                bool ispravna_karta {false};
                for(int i=0; i<13; i++) {
                    if(it->second==Nazivi_karata.at(i)) {
                        ispravna_karta=true;
                        break;
                    }
                }
                
                if(!ispravna_karta) throw std::logic_error("Neispravne karte!");
            }
            
            red_izbacenih_karata.push(*it);
            red_izbacenih_karata.pop();
    }
    
    
    int br_karata(0);
  
        for (auto it=spil.begin();it!=spil.end();it++){
            if(it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo ) throw std::logic_error("Neispravna lista!");
            else {
                bool ima_naziv{false};
                for(int i=0;i<13;i++)
                if(it->second==Nazivi_karata.at(i)) {ima_naziv=true; break;}
                if(!ima_naziv) throw std::logic_error("Neispravna lista!");
            }
            br_karata++;
        }
        if(br_karata>52) throw std::logic_error("Neispravna lista!");
        
        
        auto it_spila(spil.begin());
        auto iza_it(it_spila);
        iza_it++;
        
        while(iza_it!=spil.end()){
            
            
            if( IspredPoBoji(*it_spila,*iza_it)==-1 ) throw std::logic_error("Neispravna lista!");
            else if(IspredPoBoji(*it_spila,*iza_it)==0 && !SortirajPolozaj(*it_spila,*iza_it)) throw std::logic_error("Neispravna lista!");
                
            it_spila++;
            iza_it++;
        }
        
  
    
    for(int k=0;k<red_izbacenih_karata.size();k++){ 
        
        auto it_red=&red_izbacenih_karata.front();
        
        if(k<n){
        
    auto karta (std::make_pair(Boje::Pik,it_red->second));
  
    if(it_red->first=="Tref")
    karta = std::make_pair(Boje::Tref,it_red->second);
    
    else if(it_red->first=="Herc")
    karta = std::make_pair(Boje::Herc,it_red->second);
    
    else if(it_red->first=="Karo") 
    karta = std::make_pair(Boje::Karo,it_red->second);
    
   bool nalazi_se_u_spilu{false};
   
   for(auto it=spil.begin();it!=spil.end();it++){ 
   if(*it==karta){
       nalazi_se_u_spilu=true;
       break;
   }
   }
    if(!nalazi_se_u_spilu) //ako se karta ne nalazi u spilu
     spil.push_back(karta);// ubacujemo je u spil
     
        }
        

     red_izbacenih_karata.push(*it_red);
     red_izbacenih_karata.pop();
     
        
    }
    
   
    SortirajSpilPoBoji(spil);
    SortirajBojuPoPolozaju(spil,Boje::Pik);
     SortirajBojuPoPolozaju(spil,Boje::Tref);
      SortirajBojuPoPolozaju(spil,Boje::Herc);
       SortirajBojuPoPolozaju(spil,Boje::Karo);
    
}

int main ()
{
    auto spil(KreirajSpil());
   
    cout<<"Unesite korak razbrajanja: ";
    short int r;
    cin>>r;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    cin>>b;
    
    try{
    auto red_izbacenih_karata(IzbaciKarteRazbrajanjem(spil,r,b));
    
    int br_karata(0);
    for(auto it=spil.begin();it!=spil.end();it++) br_karata++;
    
    cout<<"U spilu trenutno ima "<<br_karata<<" karata, i to:"<<endl;
    
        auto it(spil.begin());
        
        if(it!=spil.end() && it->first==Boje::Pik){
            
        cout<<"Pik: ";
    while(it!=spil.end() && it->first==Boje::Pik){
        cout<<it->second<<" ";
        it++;
    }
        }
        cout<<endl;
        
        if(it!= spil.end() && it->first==Boje::Tref){
            cout<<"Tref: ";
        while(it!= spil.end() && it->first==Boje::Tref){
        cout<<it->second<<" ";
        it++;
        }
        }
        cout<<endl;
        
        if(it!=spil.end() && it->first==Boje::Herc){
            cout<<"Herc: ";
        while(it!=spil.end() && it->first==Boje::Herc){
        cout<<it->second<<" ";
        it++;
        }
        }
        cout<<endl;
        
        if(it!=spil.end() && it->first==Boje::Karo){
            cout<<"Karo: ";
        while(it!=spil.end() && it->first==Boje::Karo){
        cout<<it->second<<" ";
        it++;
        }
        }
        cout<<endl;
        
        
        try{
           
           cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int br_vracenih_karata;
        cin>>br_vracenih_karata;
           
           
        VratiPrvihNKarata(spil,red_izbacenih_karata,br_vracenih_karata); 
        
        int br_karata_2(0);
        for(auto it=spil.begin();it!=spil.end();it++) br_karata_2++;
        
        cout<<"U spilu trenutno ima "<<br_karata_2<<" karata, i to:"<<endl;
    
        auto it (spil.begin());
        
        if(it!=spil.end() && it->first==Boje::Pik){
            
        cout<<"Pik: ";
    while(it!=spil.end() && it->first==Boje::Pik){
        cout<<it->second<<" ";
        it++;
    }
        }
        cout<<endl;
        
        if(it!= spil.end() && it->first==Boje::Tref){
            cout<<"Tref: ";
        while(it!= spil.end() && it->first==Boje::Tref){
        cout<<it->second<<" ";
        it++;
        }
        }
        cout<<endl;
        
        if(it!=spil.end() && it->first==Boje::Herc){
            cout<<"Herc: ";
        while(it!=spil.end() && it->first==Boje::Herc){
        cout<<it->second<<" ";
        it++;
        }
        }
        cout<<endl;
        
        if(it!=spil.end() && it->first==Boje::Karo){
            cout<<"Karo: ";
        while(it!=spil.end() && it->first==Boje::Karo){
        cout<<it->second<<" ";
        it++;
        }
        }
        cout<<endl;
        
       }
       catch(std::domain_error izuzetak1){
           cout<<"Izuzetak: "<<izuzetak1.what()<<endl;
       }
       catch(std::range_error izuzetak2){
           cout<<"Izuzetak: "<<izuzetak2.what()<<endl;
       }
       catch(std::logic_error izuzetak3){
           cout<<"Izuzetak: "<<izuzetak3.what()<<endl;
       }
        
        
    }
    catch(std::logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what()<<endl;
        
    }

    
    
    
	return 0;
}
