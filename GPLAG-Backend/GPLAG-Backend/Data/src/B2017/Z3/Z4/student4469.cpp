/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <queue>
enum class Boje {Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje,std::string>> Spil;
std::vector<Boje>vektorboja={Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
std::vector<std::string>vektorbrojeva ={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};


bool uporedikarte(std::pair<Boje,std::string> prva, std::pair<Boje, std::string> druga) {
    
    if(prva.first<druga.first)return true;
    if(prva.first==druga.first) {
        
        auto it1=vektorbrojeva.begin();
        for(;it1!=vektorbrojeva.end();it1++) {
            if(*it1==prva.second)break;
        }
        int distanca1=std::distance(it1,vektorbrojeva.end());
        
        auto it2=vektorbrojeva.begin();
        for(;it2!=vektorbrojeva.end();it2++) {
            if(*it2==druga.second)break;
        }
        int distanca2=std::distance(it2,vektorbrojeva.end());
        return distanca1>distanca2;
    }
     return false;
}

void provjerispil(Spil spil) {
    if (spil.size()>52) throw std::logic_error("Neispravna lista!");
    auto it=spil.begin();
    auto pomocna=*it; it++;
    for(;it!=spil.end();it++) {
       
          if(uporedikarte(*it,pomocna))throw std::logic_error("Neispravna lista!");
       
        if(std::count(vektorboja.begin(),vektorboja.end(),it->first)==0)throw std::logic_error("Neispravna lista!");
        if(std::count(vektorbrojeva.begin(),vektorbrojeva.end(),it->second)==0)throw std::logic_error("Neispravna lista!");
        pomocna=*it;
    }
    
    for(auto it=spil.begin();it!=spil.end();it++) {
    
      if(std::count_if(it,spil.end(),[it] (std::pair<Boje, std::string>par){
               if(it->first==par.first && it->second==par.second)return true; return false;
      } )>1  )throw std::logic_error("Neispravna lista!");
    }
    
}

void provjerikartu(std::pair<std::string,std::string> karta) {
    if(karta.first!= "Karo" && karta.first!="Herc" && karta.first!="Tref" && karta.first!="Pik")throw std::logic_error("Neispravne karte!");
 int i=0;
 for(;i<vektorbrojeva.size();i++) {
     if(vektorbrojeva[i]==karta.second)break;
 }
 if(i==vektorbrojeva.size())throw std::logic_error("Neispravne karte!");
}

Boje vratiboju(std::string rijec) {
    if(rijec=="Karo")return Boje::Karo;
    if(rijec=="Pik")return Boje::Pik;
    if(rijec=="Herc")return Boje::Herc;
    return Boje::Tref;
}
std::string vratistring(Boje boja) {
    if(boja==Boje::Pik)return("Pik");
    if(boja==Boje::Karo)return("Karo");
    if(boja==Boje::Herc)return("Herc");
    return ("Tref");
}

void sortirajspil(Spil &spil) {
    
       for(int i=0;i<spil.size();i++) {
   
       auto it=spil.begin(); std::advance(it,i);
       auto pomocni=*it; while(it!=spil.end()) {
           if(uporedikarte(*it,pomocni))pomocni=*it;
           it++;
       }
       it=spil.begin();std::advance(it,i);
       while(it!=spil.end()) {
           if(it->first==pomocni.first &&it->second==pomocni.second){it=spil.erase(it);break;}
           it++;
       }
       auto it2=spil.begin();
       while(it2!=spil.end() && uporedikarte(*it2,pomocni))it2++;
       spil.insert(it2,pomocni);
   }
    
}

Spil KreirajSpil(){
    Spil spil;
    auto it=spil.begin();
    for(int i=0;i<4;i++) {
        for(int j=0;j<13;j++) {
            spil.insert(it,std::make_pair(vektorboja[i],vektorbrojeva[j]));
            it++;
        }
    }
   
sortirajspil(spil);
   return spil;
}

void IzbaciKarte (Spil& spil, std::multimap<Boje,std::string> &mapa){
    
   
        provjerispil(spil);
    for(auto it=spil.begin();it!=spil.end();it++){
        for(auto it2=mapa.begin();it2!=mapa.end();it2++) {
            if(it->first==it2->first && it->second == it2->second) {
                spil.erase(it);
                //brisanje ostalih takvih iz multimape
                auto it3=it2;
                while(it3!=mapa.end()) { 
                    if(*it3==*it2 && it3!=it2)mapa.erase(it3);
                    it3++;
                }
                mapa.erase(it2);
            }
        }
    }
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(Spil &spil,const short int&r, const int&b) {
    if(r<1 || r>52 || b<1)throw std::logic_error("Neispravni elementi za izbacivanje!");
   provjerispil(spil);
    
    std::queue<std::pair<std::string,std::string>> red;
    auto it=spil.begin();
    int brojac=0,kraj=spil.size();
    while(brojac!=b) {
        
       int broj=std::distance(it,spil.end());
       if(broj>=r) {
           std::advance(it,r-1); std::string pomocni;
           pomocni=vratistring(it->first);
           red.push(std::make_pair(pomocni,it->second));
           it=spil.erase(it);brojac++;if(it==spil.end())it--; 
           if(brojac==kraj)brojac=b;
       }
        else if(broj<r) {
            int broj2=r-1;
            while(broj2>0) {
                it++; if(it==spil.end())it=spil.begin();
                broj2--;
            }
            std::string pomocni;
           pomocni=vratistring(it->first);
           red.push(std::make_pair(pomocni,it->second));
            it=spil.erase(it);brojac++;if(it==spil.end())it--;
            if(brojac==kraj)brojac=b;
        }
    }
    return red;
}

void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string,std::string>> &red,int n) {
    
    if(n<0 || n>52)throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    provjerispil(spil);
    for(int i=0;i<n;i++){
       provjerikartu(red.front());
        auto it=spil.begin();
        auto pomocna=*it; pomocna.first=vratiboju(red.front().first);pomocna.second=red.front().second;
        while(it!=spil.end() && uporedikarte(*it,pomocna))it++;
        if(it!=spil.end() && it->first==vratiboju(red.front().first) && it->second==red.front().second)red.pop();
         else if(it!=spil.end()) {
             std::pair<Boje,std::string> pomocni; pomocni.first=vratiboju(red.front().first);
             pomocni.second=red.front().second;
             spil.insert(it,pomocni); red.pop();
         }
    }
    sortirajspil(spil);
}

int main ()
{
    try{
    std::cout<<"Unesite korak razbrajanja: ";
    short int r; std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b; std::cin>>b;
    Spil spil=KreirajSpil();
    
    std::queue<std::pair<std::string,std::string>>red= IzbaciKarteRazbrajanjem(spil,r,b);
  
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
    auto it=spil.begin();
    while(it!=spil.end()) {
        std::string pomocni=vratistring(it->first);
        std::cout<<vratistring(it->first)<<": ";
        while(it!=spil.end()&&pomocni==vratistring(it->first)){std::cout<<it->second<<" ";it++;}
        std::cout<<std::endl;
    }
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: "; int vracanje; std::cin>>vracanje;
        VratiPrvihNKarata(spil,red,vracanje);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
        it=spil.begin();
        while(it!=spil.end()) {
        std::string pomocni=vratistring(it->first);
        std::cout<<vratistring(it->first)<<": ";
        while(it!=spil.end()&&pomocni==vratistring(it->first)){std::cout<<it->second<<" ";it++;}
        if(it!=spil.end())std::cout<<std::endl;
    } 
     
  
    } 
   
   
   catch(std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
     catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } 
     catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }

	return 0;
}
