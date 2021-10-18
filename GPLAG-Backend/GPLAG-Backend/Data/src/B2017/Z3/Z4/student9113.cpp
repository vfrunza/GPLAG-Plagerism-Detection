/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <string>
#include <list>
#include <sstream>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <iterator>
enum class Boje{Pik, Tref, Herc, Karo}; 
template <typename T> std::string PretvoriUString(T x) {    std::ostringstream s; s << x; return s.str();    }  
std::list<std::pair<Boje,std::string>> KreirajSpil(){
    std::list<std::pair<Boje,std::string>> spil;
    for(int i=0;i<9;i++){
        std::pair<Boje,std::string> a;
        std::string broj=PretvoriUString(i+2);
        a=std::make_pair(Boje::Pik,broj);
        spil.push_back(a);
    }
    std::pair<Boje,std::string> a;
    a=std::make_pair(Boje::Pik,'J');
    spil.push_back(a);
    a=std::make_pair(Boje::Pik,'Q');
    spil.push_back(a);
    a=std::make_pair(Boje::Pik,'K');
    spil.push_back(a);
    a=std::make_pair(Boje::Pik,'A');
    spil.push_back(a);
     for(int i=0;i<9;i++){
        std::pair<Boje,std::string> a;
        std::string broj=PretvoriUString(i+2);
        a=std::make_pair(Boje::Tref,broj);
        spil.push_back(a);
    }
    a=std::make_pair(Boje::Tref,'J');
    spil.push_back(a);
    a=std::make_pair(Boje::Tref,'Q');
    spil.push_back(a);
    a=std::make_pair(Boje::Tref,'K');
    spil.push_back(a);
    a=std::make_pair(Boje::Tref,'A');
    spil.push_back(a);
     for(int i=0;i<9;i++){
        std::pair<Boje,std::string> a;
        std::string broj=PretvoriUString(i+2);
        a=std::make_pair(Boje::Herc,broj);
        spil.push_back(a);
    }
    a=std::make_pair(Boje::Herc,'J');
    spil.push_back(a);
    a=std::make_pair(Boje::Herc,'Q');
    spil.push_back(a);
    a=std::make_pair(Boje::Herc,'K');
    spil.push_back(a);
    a=std::make_pair(Boje::Herc,'A');
    spil.push_back(a);
     for(int i=0;i<9;i++){
        std::pair<Boje,std::string> a;
        std::string broj=PretvoriUString(i+2);
        a=std::make_pair(Boje::Karo,broj);
        spil.push_back(a);
    }
    a=std::make_pair(Boje::Karo,'J');
    spil.push_back(a);
    a=std::make_pair(Boje::Karo,'Q');
    spil.push_back(a);
    a=std::make_pair(Boje::Karo,'K');
    spil.push_back(a);
    a=std::make_pair(Boje::Karo,'A');
    spil.push_back(a);
    return spil;
}
void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &mapica){
    auto it(spil.begin());
    int br(0);
    while(it!=spil.end()){
        br++;
        if(br<=13 && it->first!=Boje::Pik) throw std::logic_error("Neispravna lista");
        if(br>13 && br<=26 && it->first!=Boje::Tref) throw std::logic_error("Neispravna lista");
        if(br>26 && br<=39 && it->first!=Boje::Herc) throw std::logic_error("Neispravna lista");
        if(br>39 && br<=52 && it->first!=Boje::Karo) throw std::logic_error("Neispravna lista");
        it++;
    }
    if(br>52) throw std::logic_error("Neispravna lista");
    it=spil.begin();
    while(it!=spil.end()){
        auto prva=it->first;
        auto druga=it->second;
        auto it1(mapica.find(prva));
        if(it1!=mapica.end() ) { it=spil.erase(it); it1=mapica.erase(it1);}
        it++;
    }
    
}
std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil, short int &r,int &b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
     auto it(spil.begin());
    int br(0);
    while(it!=spil.end()){
        br++;
        if(br<=13 && it->first!=Boje::Pik) throw std::logic_error("Neispravna lista");
        if(br>13 && br<=26 && it->first!=Boje::Tref) throw std::logic_error("Neispravna lista");
        if(br>26 && br<=39 && it->first!=Boje::Herc) throw std::logic_error("Neispravna lista");
        if(br>39 && br<=52 && it->first!=Boje::Karo) throw std::logic_error("Neispravna lista");
        it++;
    }
    if(br>52) throw std::logic_error("Neispravna lista");
    std::queue<std::pair<std::string,std::string>> red;
    br=0;
    int n(52/r);
    int m(52%r);
    it=spil.begin();
    while(br<b){
       /* while(it!=spil.end()){
            if(br1=r) { 
            }
            it++;*/
            if(br==n) {it=spil.begin(); std::advance(it,r-m-1); 
        std::pair<std::string,std::string> s; 
        if(it->first==Boje::Pik) s=std::make_pair("Pik",it->second); else if(it->first==Boje::Herc) s=std::make_pair("Herc",it->second);else if(it->first==Boje::Karo) s=std::make_pair("Karo",it->second); else if(it->first==Boje::Tref) s=std::make_pair("Tref",it->second);
        red.push(s);
        it=spil.erase(it);
        br++;
            }
        else{
          std::advance(it,r-1);            
        std::pair<std::string,std::string> s; 
        if(it->first==Boje::Pik) s=std::make_pair("Pik",it->second); else if(it->first==Boje::Herc) s=std::make_pair("Herc",it->second);else if(it->first==Boje::Karo) s=std::make_pair("Karo",it->second); else if(it->first==Boje::Tref) s=std::make_pair("Tref",it->second);
        red.push(s);
        it=spil.erase(it);
        //it++;
        br++;
        }
        }
    return red;
}
int Broj_Karata(std::list<std::pair<Boje,std::string>> spil){
    auto it(spil.begin());
    int br(0);
    while(it!=spil.end()){
        br++;
        it++;
    }
    return br;
}
void IspisiKarte(std::list<std::pair<Boje,std::string>> spil){
    auto it(spil.begin());
    std::cout<<"Pik: ";
    while(it->first==Boje::Pik && it!=spil.end()) {std::cout<<it->second<<" "; it++;}
    std::cout<<std::endl<<"Tref: ";
    while(it!=spil.end() && it->first==Boje::Tref){ std::cout<<it->second<<" "; it++;}
    std::cout<<std::endl<<"Herc: ";
    while(it!=spil.end() && it->first==Boje::Herc){std::cout<<it->second<<" "; it++;}
    std::cout<<std::endl<<"Karo: ";
    while(it!=spil.end() && it->first==Boje::Karo){std::cout<<it->second<<" ";it++;}
}
Boje VratiBoju(std::string s){
    if(s=="Pik") return Boje::Pik;
    else if(s=="Tref") return Boje::Tref;
    else if(s=="Herc") return Boje::Herc;
    return Boje::Karo;
}
int PretvoriUBroj(std::string s){
    int br(0),k(1);
    for(int i=s.size()-1;i>=0;i--){
        br+=(s[i]-'0')*k;
        k*=10;
    }
    return br;
}
bool VidiJelImaUSpilu(std::list<std::pair<Boje,std::string>> spil,Boje a,std::string s){
    auto it(spil.begin());
    while(it!=spil.end()){
        if(it->first==a && it->second==s) return false;
        it++;
    }
    return true;
}
void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil, std::queue<std::pair<std::string,std::string>> &red, int n){
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(red.size()<n) throw std::range_error("Nedovoljno karata u redu!");
    int br(0);
    if(n!=0){
    while(!red.empty() && br<n){
        std::pair<Boje,std::string> par;
        par.first=VratiBoju(red.front().first);
        par.second=red.front().second;
        auto it(spil.begin());
        while(it->first!=par.first && it!=spil.end()) it++;
        while(it->first==par.first){
            int br(PretvoriUBroj(par.second));
            if(br==2 && VidiJelImaUSpilu(spil,par.first,par.second)) {spil.insert(it,par);}
            if(br>2 && br<=9){int br1(PretvoriUBroj(it->second)); if(br-1==br1 && VidiJelImaUSpilu(spil,par.first,par.second)){it++; spil.insert(it,par);}}
            else {
                if(par.second=="10" && it->second=="9" && VidiJelImaUSpilu(spil,par.first,par.second)){ it++; spil.insert(it,par);}
                if(par.second=="J" && it->second=="10" && VidiJelImaUSpilu(spil,par.first,par.second)){it++; spil.insert(it,par);}
                if(par.second=="Q" && it->second=="J" && VidiJelImaUSpilu(spil,par.first,par.second)) {it++; spil.insert(it,par);}
                if(par.second=="K" && it->second=="Q" && VidiJelImaUSpilu(spil,par.first,par.second)){it++; spil.insert(it,par);}
                if(par.second=="A" && it->second=="K" && VidiJelImaUSpilu(spil,par.first,par.second)){it++; spil.insert(it,par);}
          }
            it++;
        }
        red.pop();
        br++;
    }
    }
}
int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    short int br_razbr(0);
    std::cin>>br_razbr;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int br_karata(0);
    std::cin>>br_karata;
    try{
    std::list<std::pair<Boje,std::string>> spil(KreirajSpil());
    std::queue<std::pair<std::string,std::string>> red (IzbaciKarteRazbrajanjem(spil,br_razbr,br_karata));
    int br(Broj_Karata(spil));
    std::cout<<"U spilu trenutno ima "<<br<<" karata, i to: "<<std::endl;
    IspisiKarte(spil);
    std::cout<<std::endl;
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int n(0);
    std::cin>>n;
    VratiPrvihNKarata(spil,red,n);
    br=Broj_Karata(spil);
    std::cout<<"U spilu trenutno ima "<<br<<" karata, i to: "<<std::endl; 
    IspisiKarte(spil);
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    catch(std::range_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}
