#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <queue>

enum class Boje {Pik, Tref, Herc, Karo}  ;
int brojkarata;

std::list<std::pair<Boje,std::string>> KreirajSpil () {
    std::list<std::pair<Boje, std::string>> Spil;
    Boje boje;
    
    for(int i = 0; i < 4; i++) {
        if(i==0) boje=Boje::Pik;
        else if (i==1) boje=Boje::Tref;
        else if(i==2) boje=Boje::Herc;
        else boje=Boje::Karo;
        
        std::pair<Boje,std::string> Karta;
        
        for (int j = 1; j <= 13 ; j++) {
            std::string S;
            if(j>=1 && j<=9) S=std::to_string(j+1);
            else if (j==10) S="J";
            else if(j==11) S="Q";
            else if(j==12) S="K";
            else if(j==13) S="A";
            Karta.first = boje;
            Karta.second = S;
            Spil.push_back(Karta);
        }
    }
    return Spil;
}

void IzbaciKarte (std::list<std::pair<Boje, std::string>> &Lista, std::multimap <Boje, std::string> &Multi) {
    if(Lista.size() > 52) throw std::logic_error("Neispravna lista!");
    
    bool TacniPodaci(true);
    for(auto it=Lista.begin(); it!=Lista.end(); it++) {
        if(it->first !=Boje::Pik || it->first != Boje::Herc || it->first != Boje::Karo || it->first!=Boje::Tref) TacniPodaci = false;
        if(it->second != "A" || it->second != "J" || it->second != "K" || it->second != "Q") TacniPodaci = false;
        if(it->second != "2" || it->second != "3" || it->second != "4" || it->second != "5" || it->second != "6" ) TacniPodaci = false;
        if(it->second != "7" || it->second != "8" || it->second != "9" ||it->second != "10" ) TacniPodaci = false;
        if(TacniPodaci = false ) throw std::logic_error("Neispravna lista");
    }
    
    std::pair<Boje, std::string> Karta;
    
    for(auto it=Multi.begin(); it != Multi.end(); it++) {
        Karta=(*it) ;
        for(auto it1=Lista.begin(); it1 != Lista.end(); it1++) {
            if(it->first == it1->first && it->second == it1->second) {
                Lista.remove(*it1);
                it1--;
                Multi.erase(it);
                it--;
            }
        }
    }
    
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje, std::string>> &spil, short int r, int b) {
    if(r<0 || r>52) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if(spil.size() >52) throw std::logic_error ("Neispravna lista!");
    if(b<0) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    bool TacniPodaci = true;
    for(auto it=spil.begin(); it!=spil.end(); it++) {
        if(it->first !=Boje::Pik || it->first != Boje::Herc || it->first != Boje::Karo || it->first!=Boje::Tref) TacniPodaci = false;
        if(it->second != "A" || it->second != "J" || it->second != "K" || it->second != "Q") TacniPodaci = false;
        if(it->second != "2" || it->second != "3" || it->second != "4" || it->second != "5" || it->second != "6" ) TacniPodaci = false;
        if(it->second != "7" || it->second != "8" || it->second != "9" ||it->second != "10" ) TacniPodaci = false;
        if(TacniPodaci = false ) throw std::logic_error("Neispravna lista");
    }
    std::queue<std::pair<std::string,std::string>> Red;
    std::string NekiString;
    int brojac(0);
    auto it=spil.begin();
    int br(0);
    while (brojac<b) {
        for(;;) {
            br++;
            if(br==r) break;
            if(it==spil.end()) it=spil.begin();
            it++;
        }
       
            if((*it).first == Boje::Pik) NekiString="Pik";
            else if((*it).first == Boje::Tref) NekiString="Tref";
            else if((*it).first == Boje::Herc) NekiString="Herc";
            else NekiString ="Karo";
            std::pair<std::string,std::string> Par;
            Par.first=NekiString;
            Par.second=(*it).second;
            Red.push(Par);
            auto pom=it;
            if(pom==spil.end()) pom=spil.end();
            else pom++;
            spil.erase(it);
            it=pom;
            if(spil.size()==0) break;
        brojac ++; 
        br=0;
        
    }
   
    
    return Red;
}

void VratiPrvihNKarata (std::list <std::pair<Boje,std::string>> &spil, std::queue<std::pair<std::string,std::string>> &Red, int n ) {

if(spil.size() >52) throw std::logic_error ("Neispravna lista");
if(n<0) throw std::domain_error("Broj n je besmislen!");
    bool TacniPodaci = true;
    for(auto it=spil.begin(); it!=spil.end(); it++) {
        if(it->first !=Boje::Pik || it->first != Boje::Herc || it->first != Boje::Karo || it->first!=Boje::Tref) TacniPodaci = false;
        if(it->second != "A" || it->second != "J" || it->second != "K" || it->second != "Q") TacniPodaci = false;
        if(it->second != "2" || it->second != "3" || it->second != "4" || it->second != "5" || it->second != "6" ) TacniPodaci = false;
        if(it->second != "7" || it->second != "8" || it->second != "9" ||it->second != "10" ) TacniPodaci = false;
        if(TacniPodaci = false ) throw std::logic_error("Neispravna lista");
    }
if(n>Red.size()) throw std::range_error ("Nedovoljno karata u redu!");



std::list<std::pair<std::string,std::string>> RedSpil;
std::pair<std::string,std::string> Par;
std::string NekiString;
for(auto it=spil.begin();it!=spil.end();it++) {
    if((*it).first == Boje::Pik) NekiString="Pik";
            else if((*it).first == Boje::Tref) NekiString="Tref";
            else if((*it).first == Boje::Herc) NekiString="Herc";
            else NekiString ="Karo";
            std::pair<std::string,std::string> Par;
            Par.first=NekiString;
            Par.second=(*it).second;
            RedSpil.push_back(Par);
    
}
    int b(0);
    std::pair<std::string,std::string> Par1;
    while(b!=n) {
        bool NePostoji= true;
        Par1=Red.front();
        for(auto it=RedSpil.begin();it!=RedSpil.end();it++) {
            if(Par1==(*it)) NePostoji=false;
        }
        if(NePostoji==true)  {
            Boje boje;
            if(Par1.first == "Pik") boje=Boje::Pik;
            else if(Par1.first == "Tref") boje=Boje::Tref;
            else if(Par1.first == "Herc") boje=Boje::Herc;
            else boje =Boje::Karo;
            std::pair<Boje,std::string> Par2;
            Par2.first=boje;
            Par2.second=Par1.second;
            spil.push_back(Par2);
            Red.pop();
            
        } else if (NePostoji==false) Red.pop();
    b++;   
    }
    std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::vector<Boje> v1{Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
    spil.sort([v,v1] (std::pair<Boje,std::string> S1,std::pair<Boje,std::string> S2) {
        
        int z(0); int o(0);
        if(S1.first == S2.first) {
            for(int i =0 ; i<v.size();i++) {
            if(v.at(i)==S1.second) z=i;
            if(v.at(i)==S2.second) o=i;
            }
            if(z<o) return true;
            else return false;
        }
        int k(0); int l(0);
        for(int i = 0;i<v1.size();i++) {
            if(v1.at(i)==S1.first) k=i;
            if(v1.at(i)==S2.first) l=i;
        }
        if (k<l) return true;
        else return false;
        
    }); 
}

void IspisKarti(std::list<std::pair<Boje, std::string>> Lista) 
{
    auto it=Lista.begin();
    std::cout<<"Pik: ";
    while(int(it->first)==0) 
    {
        std::cout<<it->second<<" ";
        it++;
        if(it==Lista.end()) break;
    }
    std::cout<<std::endl;
    std::cout<<"Tref: ";
    while(int(it->first)==1) 
    {
        std::cout<<it->second<<" ";
        it++;
        if(it==Lista.end()) break;
    }
    std::cout<<std::endl;
    std::cout<<"Herc: ";
    while(int(it->first)==2) 
    {
        std::cout<<it->second<<" ";
        it++;
        if(it==Lista.end()) break;
    }
    std::cout<<std::endl;
    std::cout<<"Karo: ";
    while(int(it->first)==3) 
    {
        std::cout<<it->second<<" ";
        it++;
        if(it==Lista.end()) break;
    }
    std::cout<<std::endl;
}
int main ()
{
    try{
    auto spil = KreirajSpil();
    std::cout<<"Unesite korak razbrajanja: ";
    short int n;
    std::cin>>n;
    
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int a;
    std::cin>>a;
    //std::cout<<"U spilu trenutno ima "; 
    std::queue<std::pair<std::string,std::string>> Red;
    Red=IzbaciKarteRazbrajanjem(spil,n,a);
    std::cout<<"U spilu trenutno ima "; 
    std::cout<<spil.size()<<" karata, i to:\n";
    IspisKarti(spil);
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int b;
    std::cin>>b;
    VratiPrvihNKarata(spil,Red,b);
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:\n";
    IspisKarti(spil);
    } catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
        
            
        } 
    catch (std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch (std::logic_error izuzetak) {
         std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
	return 0;
}
