#include <iostream>
#include<list>
#include<vector>//   ZA IMENA KARATA
#include<queue>
#include<iterator>
#include<stdexcept>
#include<algorithm>
#include<map>
std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
enum  Boje {Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje,std::string>> Spil;
Spil KreirajSpil(){
    Spil spil(52);
    Spil::iterator it(spil.begin());
    Boje  boja=Pik;
    for(int i=0;i<52;i++){
        if(i>12)boja=Tref;
        if(i>25)boja=Herc;
        if(i>38)boja=Karo;
     it->first=boja;
     it->second=v[i%13];
     it++;
    }
   return spil;
}
bool je_li_validan(Spil spil){
    auto it(spil.begin());
    auto prijasnji(it->first);
    it++;
    for(int i=1;i<spil.size();i++){
        if(prijasnji>it->first)return false;
        it++;
    }
    auto it2(spil.begin());
    for(int i=0;i<spil.size();i++){
        bool jest(false);
        for(int j=0;j<v.size();j++){if(it2->second==v[j])jest=true;}
        it2++;
        if(jest==false)return false;
    }
    return true;
}
std::queue<std::pair<Boje,std::string>>  IzbaciKarteRazbrajanjem (Spil &spil,const short int &r,const int &b){
    if(r<1||r>52||b<1)throw std::logic_error{"Neispravni elementi za izbacivanje!"};
    if(spil.size()>52)throw std::logic_error{"Neispravna lista!"};
    if(!(je_li_validan(spil)))throw std::logic_error{"Neispravna lista!"};
    std::queue<std::pair<Boje,std::string>> izbacene;
    Spil::iterator it(spil.begin());
    it--;
    for(int i=0;i<b;i++){
       for(int j=0;j<r;j++){
           it++;
           if(it==spil.end())it=spil.begin();
       }
       izbacene.push(*it);
       it=spil.erase(it);
       if(spil.size()==0)break;
       it--;
   }
  
    return izbacene;
}
bool je_li_validan_red(std::queue<std::pair<Boje,std::string>>  izbacene){
    auto copy(izbacene);
    int rekt(izbacene.size());
    auto prije(copy.front().first);
    for(int i=0;i<rekt;i++){
        if(prije>copy.front().first)return false;
        copy.pop();
        prije=copy.front().first;
    }
   for(int i=0;i<rekt;i++){
        bool jest(false);
        for(int j=0;j<v.size();j++){if(izbacene.front().second==v[j])jest=true;}
        izbacene.pop();
        if(jest==false)return false;
    }
    return true;
}
void ispisi(Spil s){
    auto it(s.begin());
    std::cout << "U spilu trenutno ima "<<s.size()<<" karata, i to:" << std::endl;
    std::cout << "Pik: " ;
    while(it->first==Pik){std::cout << it->second<<" ";it++;}
     std::cout << "\nTref: " ;
    while(it->first==Tref){std::cout << it->second<<" ";it++;}
    std::cout << "\nHerc: " ;
    while(it->first==Herc){std::cout << it->second<<" ";it++;}
    std::cout << "\nKaro: " ;
    while(it->first==Karo){std::cout << it->second<<" ";it++;if(it==s.end())break;}
    std::cout << std::endl;
}
bool dobro(std::string a,std::string b){
    if(a==b)return false;
    int i,j;
    for(i=0;i<v.size();i++){
        if(a==v[i])break;
    }
    for(j=0;j<v.size();j++){
        if(b==v[j])break;
    }
    return i>j;
}
void sortiraj(Spil &s){
    for (auto i = s.begin(); i != s.end(); ++i) {
        for (auto j = i; j != s.end(); ++j) {
           if(i->first>j->first){auto temp(*i);*i=*j;*j=temp;}
        }
    }
    auto it(s.begin());
    while(it->first==Pik){
        auto it2(it);
        while (it2->first==Pik) {
            if(dobro(std::string(it->second),std::string(it2->second))){auto temp(*it);*it=*it2;*it2=temp;}
            it2++;
        }
        it++;
    }
     
    while(it->first==Tref){
        auto it2(it);
        while (it2->first==Tref) {
            if(dobro(std::string(it->second),std::string(it2->second))){auto temp(*it);*it=*it2;*it2=temp;}
            it2++;
        }
        it++;
    }
   
   while(it->first==Herc){
       auto it2(it);
        while (it2->first==Herc) {
            if(dobro(std::string(it->second),std::string(it2->second))){auto temp(*it);*it=*it2;*it2=temp;}
            it2++;
        }
        it++;
   }
  
   while(it->first==Karo){
       auto it2(it);
        while (it2->first==Karo) {
            if(dobro(std::string(it->second),std::string(it2->second))){auto temp(*it);*it=*it2;*it2=temp;}
            it2++;
             if(it2==s.end())break;
        }
        it++;
       if(it==s.end())break;
       
   }
  
}
void VratiPrvihNKarata(Spil &spil,std::queue<std::pair<Boje,std::string>> &izbacene,int n ){
    if(!(je_li_validan(spil)))throw std::logic_error{"Neispravna lista!"};
    if(n<0)throw std::domain_error {"Broj n je besmislen!"};
    if(n>izbacene.size())throw std::range_error{"Nedovoljno karata u redu!"};
    if(spil.size()>52)throw std::logic_error{"Neispravna lista!"};
    if(!(je_li_validan_red(izbacene)))throw std::logic_error{"Neispravne karte!"};
    
    
    for(int i=0;i<n;i++){
     auto it(spil.begin());
     bool jest(true);
     for(int j=0;j<spil.size();j++){
         if(izbacene.front()==*it){jest==false;break;}
         it++;
     }
     if(jest==false){izbacene.pop();continue;}
     spil.insert(spil.begin(),izbacene.front());
     izbacene.pop();
    }
    sortiraj(spil);
}
void IzbaciKarte(Spil &spil,std::multimap<Boje, std::string> &mapa){
    if(spil.size()>52)throw std::logic_error{"Neispravna lista!"};
    if(!(je_li_validan(spil)))throw std::logic_error{"Neispravna lista!"};
    auto iter(mapa.begin());
    auto broj(mapa.size());
    for(int i=0;i<broj;i++){
        bool a=false;
        auto it2(spil.begin());
        for(int j=0;j<spil.size();j++){
            if(it2->first==iter->first&&it2->second==iter->second){a=true;break;}
            it2++;
        }if(a==false){iter++;continue;}
        auto it(spil.begin());
        for(int i=0;i<spil.size();i++){
            if(it2->first==iter->first&&it2->second==iter->second){iter=mapa.erase(iter);spil.erase(it);break;}
                it++;
            }
        }
    }

int main (){
    try{int n;
    auto spil(KreirajSpil());
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> n;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int m;
    std::cin >> m;
    
    auto red(IzbaciKarteRazbrajanjem(spil,n,m));
    ispisi(spil);
    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    int e;
    std::cin >> e;
    VratiPrvihNKarata(spil,red,e);
    ispisi(spil);
    }catch(std::domain_error er){
        std::cout << "Izuzetak: "<<er.what() << std::endl;
    }catch(std::logic_error er){
        std::cout << "Izuzetak: "<<er.what() << std::endl;
    }catch(std::range_error er){
        std::cout << "Izuzetak: "<<er.what() << std::endl;
    }
    
	return 0;
}

