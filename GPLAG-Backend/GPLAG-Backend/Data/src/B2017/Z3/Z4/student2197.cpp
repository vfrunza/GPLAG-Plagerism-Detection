/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <queue>
enum class Boje {Pik,Tref, Herc, Karo};


std::list<std::pair<Boje, std::string>> KreirajSpil(){
    std::list<std::pair<Boje, std::string>> rezultat;
    std::vector<std::string> nazivi{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0; i<nazivi.size(); i++){
         std::pair<Boje, std::string> par1=std::make_pair(Boje::Pik,nazivi[i]);
           rezultat.push_back(par1);
    }
     for(int i=0; i<nazivi.size(); i++){
           std::pair<Boje, std::string> par1=std::make_pair(Boje::Tref,nazivi[i]);
           rezultat.push_back(par1);
        }
       for(int i=0; i<nazivi.size(); i++){
           std::pair<Boje, std::string> par1=std::make_pair(Boje::Herc,nazivi[i]);
           rezultat.push_back(par1);
        }
        for(int i=0; i<nazivi.size(); i++){
           std::pair<Boje, std::string> par1=std::make_pair(Boje::Karo,nazivi[i]);
           rezultat.push_back(par1);
        }
    
    return rezultat;
}
    
  void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &m){
      //uslov za besmislene podatke i ne sortiranu listu
  if(spil.size()>52) throw std::logic_error("Neispravna lista!");
  
   /* for(auto it1 = m.begin(); it1 != m.end(); it1++){
        std::pair<Boje,std::string> par=std::make_pair(it1->first,it1->second);
        auto iterator = std::find(spil.begin(),spil.end(),par);
        if(iterator != spil.end()){
            iterator = spil.erase(iterator);
        }
        it1 = m.erase(it1);
    }
    */
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil, const short int &r, const int &b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Izuzetak: Neispravni elementi za izbacivanje!");
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    std::queue<std::pair<std::string, std::string>> rez;
 
   /* for(auto it=spil.begin(); it!=spil.end(); it++){
        for(int i=0; i<b; i++){
            int br(1);
            while(br<=r && it!=spil.end()){
                    if(br == r) {
                        std::pair<std::string, std::string> par;
                        par=std::make_pair(it->first,it->second);
                        rez.push(par);
                        it=spil.erase(it); 
                    }
                    br++;
                    it++;
            }
        }
    }
    */
    return rez;
}


std::list<std::pair<std::string, std::string>> VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil, std::queue<std::pair<std::string,std::string>> &red, int n){
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
   std::list<std::pair<std::string, std::string>> rezultat;
   
    if(n < 0 || n > 52) throw std::domain_error("Broj n je besmislen!");
   /* for(int i=0; i<n; i++){
       while(!red.empty()){
            auto x=red.front();
            red.pop();
            auto y= red.front();
            auto it1 = spil.begin();
            auto it2 = spil.begin();
            it2 = ++it1;
            while(it2!=spil.end()){
            if(*it1 < x && *it2 > x){
               std::pair<std::string, std::string> par;
              // par=std::make_pair(x);
                //it1++;
                //it2++;
                    //auto pretraziit = spil.find(par); 
                   // if(pretraziit== spil.end()) continue;
                   spil.insert(x);
                    
                }
                else {
                    it1++; 
                    it2++;
                
                }
            }
        }
    }
    */
    return rezultat;
}

int main()

{
   
        short int r;
        int b;
    try{
   
            std::cout<<"Unesite korak razbrajanja: ";
            std::cin>>r;
           try{
            std::cout<<"Unesite broj karata koje zelite izbaciti: ";
            std::cin>>b;
                 try{
                        std::cout<<"U spilu trenutno ima "<<52-b<<" karata, i to: \n";
                        std::list<std::pair<Boje, std::string>> spil=KreirajSpil();
                        std::queue<std::pair<std::string, std::string>> rezultat;
                        rezultat=IzbaciKarteRazbrajanjem(spil,r,b);
                     }
                        catch(std::domain_error e) {
                            std::cout<<e.what();
                        }
           }
              catch(std::range_error e) {
                std::cout<<e.what();
            }
    }
             catch(std::logic_error e) {
                std::cout<<e.what();
            }
        
    
	return 0;
	
}


















