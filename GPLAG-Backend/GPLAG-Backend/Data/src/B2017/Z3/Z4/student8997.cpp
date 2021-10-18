/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <queue> 
#include <list>
#include <map>

enum class Boje {Pik, Tref, Herc, Karo};


std::list<std::pair<Boje,std::string>>  KreirajSpil() 
{
    std::list<std::pair<Boje,std::string>>  spil;
    
    std::vector<Boje> v= {Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
    std::vector<std::string> s = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    
    
    for(int i=0;i<4;i++){
        
        for(int j=0;j<13;j++){
            
          //  spil.insert(std::make_pair(Boje[i],s[j]));
            
            
            }
    }
    
    
    return spil;
    
    
}




     void   IzbaciKarte(std::list<std::pair<Boje,std::string>> &sp,std::multimap<Boje, std::string> &map)
{
 
 
 
 
 
 
 
 
 
 
 
    
}


std::queue<std::pair<Boje,std::string>>IzbaciKarteRazbrajanjem (std::list<std::pair<Boje,std::string>> &sp, const short int &a, const int &b)
        
{
    
 if(a<1 || a>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
 if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    
    
    
    
    
}




void VratiPrvihNKarata (std::list<std::pair<Boje,std::string>> &s, std::queue<std::pair<Boje,std::string>>   &r, int n )
{
    int br=0;
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>r.size()) throw std::range_error("Nedovoljno karata u redu!");
    
    for(auto it=s.begin();it!=s.end();it++){
        br++;
    }
    
    if(br>52) throw std::logic_error ("Neispravna lista!");
}

int main ()
{
  try{
  std::cout<<"Unesite korak razbrajanja: Unesite broj karata koje zelite izbaciti: U spilu trenutno ima 48 karata, i to:
Pik: 2 3 4 5 6 7 8 9 10 Q K A 
Tref: 2 3 4 5 6 7 9 10 J Q K A 
Herc: 2 3 4 6 7 8 9 10 J Q K A 
Karo: 3 4 5 6 7 8 9 10 J Q K A 
Unesite broj karata koje zelite vratiti u spil: Izuzetak: Broj n je besmislen!
        
    }
    catch(std::logic_error izuzetak1 ){
        std::cout<<izuzetak1.what()<<std::endl;
    }
     catch(std::domain_error izuzetak ){
        std::cout<<izuzetak.what()<<std::endl;
    }
     catch(std::range_error izuzetak2 ){
        std::cout<<izuzetak2.what()<<std::endl;
    }
    
	return 0;
}
