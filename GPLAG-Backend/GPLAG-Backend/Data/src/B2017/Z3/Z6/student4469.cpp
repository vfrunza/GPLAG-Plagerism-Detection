/B2017/2018: Zadaća 3, Zadatak 6

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <utility>
#include <stdexcept>
#include <memory>
#include <algorithm>

enum class Boje {Pik,Tref,Herc,Karo};
std::vector<Boje>vektorboja={Boje::Pik,Boje::Tref,Boje::Herc,Boje::Karo};
std::vector<std::string>vektorbrojeva={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
   std::shared_ptr<Cvor> sljedeci=nullptr;
};

std::string vratistring(Boje boja) {
 if(boja==Boje::Pik)return ("Pik");
 if(boja==Boje::Tref)return ("Tref");
 if(boja==Boje::Herc)return ("Herc");
 return ("Karo");
}

Boje vratiboju(std::string rijec){
 if(rijec=="Pik")return Boje::Pik;
 if(rijec=="Tref")return Boje::Tref;
 if(rijec=="Herc")return Boje::Herc;
 return Boje::Karo;
}

bool uporedikarte(Cvor karta1, std::pair<std::string,std::string>karta2) {
 
   
   if(karta1.karta.boja!=vratiboju(karta2.first)) {
    return karta1.karta.boja<vratiboju(karta2.first);
   }
   auto it1=vektorbrojeva.begin();
   while(it1!=vektorbrojeva.end() && karta1.karta.vrijednost!=*it1)it1++;
   int distanca1=std::distance(it1,vektorbrojeva.end());
   auto it2=vektorbrojeva.begin();
   while(it2!=vektorbrojeva.end() && karta2.second!=*it2 )it2++;
   int distanca2=std::distance(it2,vektorbrojeva.end());
   return distanca1>distanca2;

return false; 
}

void provjerispil(std::shared_ptr<Cvor>pok) {
 
 auto pomocna=pok,start=pok; pok=pok->sljedeci; int brojac=0;
 while(pok!=start) {
  brojac++; if(brojac==53)throw std::logic_error("Neispravna lista!");
  auto pomocna_karta=std::make_pair(vratistring(pomocna->karta.boja),pomocna->karta.vrijednost);
  if(uporedikarte(*pok,pomocna_karta) )throw std::logic_error("Neispravna lista!");
  
  if(std::count(vektorboja.begin(),vektorboja.end(),vratiboju(pomocna_karta.first))==0)throw std::logic_error("Neispravna lista!");
  if(std::count(vektorbrojeva.begin(),vektorbrojeva.end(),pomocna_karta.second)==0)throw std::logic_error("Neispravna lista!");
  pomocna=pok;
  pok=pok->sljedeci;
 }
 
 pok=start->sljedeci;
 while(pok!=start) {
    pomocna=pok->sljedeci;
    while(pomocna!=pok) {
     if(pok->karta.boja==pomocna->karta.boja&&pok->karta.vrijednost==pomocna->karta.vrijednost)throw std::logic_error("Neispravna lista!");
     pomocna=pomocna->sljedeci;
    }
    pok=pok->sljedeci;
 }
 
}

void provjerikartu(std::pair<std::string,std::string> karta){
 if(std::count(vektorboja.begin(),vektorboja.end(),vratiboju(karta.first))==0)throw std::logic_error("Neispravne karte!");
 if(std::count(vektorbrojeva.begin(),vektorbrojeva.end(),karta.second)==0)throw std::logic_error("Neispravne karte!");
 
}



std::shared_ptr<Cvor> KreirajSpil() {
 int brojacboja=0,brojackarti=0;
 std::shared_ptr<Cvor>pocetak=nullptr,zadnji;
  for(int i=0;i<52;i++) { 
     std::shared_ptr<Cvor>novi(std::make_shared<Cvor>());
      novi->karta.boja=vektorboja[brojacboja];
      novi->karta.vrijednost=vektorbrojeva[brojackarti];
      if(pocetak==nullptr)pocetak=novi;
    else zadnji->sljedeci=novi;
     if(i==51) novi->sljedeci=pocetak;
      zadnji=novi;
     brojackarti++; if(brojackarti==13){brojackarti=0;brojacboja++;}
  }
  return pocetak;
}

  void  IzbaciKarte(std::shared_ptr<Cvor> &prvi,std::multimap<Boje,std::string> &mapa){
   provjerispil(prvi);
   auto it=mapa.begin();
   while(it!=mapa.end()) {
       
      std::shared_ptr<Cvor> pok(prvi->sljedeci);
      std::shared_ptr<Cvor> prosli(prvi); int brojac=0;
       for(;pok!=prvi;pok=pok->sljedeci) {
           if(brojac==52)throw std::logic_error("Neispravna lista");
           if(it->first==pok->karta.boja && it->second==pok->karta.vrijednost){
               prosli->sljedeci=pok->sljedeci->sljedeci;
               std::shared_ptr<Cvor>zabrisanje(pok);
               pok=prosli;
               if(zabrisanje==prvi)prvi=prvi->sljedeci;
            //   delete zabrisanje;
           }
           else prosli=pok;
           brojac++;
       }
       it++;
   }
  }
   
 std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pok,const short int &r, const int &b ) {
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    provjerispil(pok);
    std::stack<std::pair<std::string,std::string>> stek;
    std::shared_ptr<Cvor>pomocni(pok->sljedeci); 
    std::shared_ptr<Cvor>prethodni(pok);
    int kraj=1;
    while(pomocni!=pok){kraj++;pomocni=pomocni->sljedeci;} //brojanje karata
     int brojac=0;
     pomocni=pok;

     while(brojac!=b) {
      
         
        for(int i=0;i<r-1;i++) {
         
          prethodni=pomocni;
          pomocni=pomocni->sljedeci;
        
         
         }
         std::shared_ptr<Cvor> zabrisanje(pomocni);
         prethodni->sljedeci=pomocni->sljedeci;
         if(zabrisanje==pok)pok=pok->sljedeci;
         stek.push(std::make_pair(vratistring(zabrisanje->karta.boja),zabrisanje->karta.vrijednost));
         pomocni=pomocni->sljedeci;
     //delete zabrisanje
         brojac++;
         
         if(brojac==kraj)brojac=b; 
         
         
     }
      return stek;
 }
 
 void VratiPosljednjihNKarata(std::shared_ptr<Cvor> &pok,std::stack<std::pair<std::string,std::string>> &stek,int n) {
   if(n<0 || n>52) throw std::domain_error("Broj n je besmislen!");
  if(n>stek.size()) throw std::range_error("Nedovoljno karata u steku!");
   provjerispil(pok);
    for(int i=0;i<n;i++) {
    std::shared_ptr<Cvor> prosli(pok);
    std::shared_ptr<Cvor>pomocni(pok->sljedeci);
     
     provjerikartu(stek.top());
     auto pomocnakarta=stek.top();
     while( pomocni!=pok && uporedikarte(*pomocni,pomocnakarta)) {
      
      prosli=prosli->sljedeci;
      pomocni=pomocni->sljedeci;
     }
     if(pomocni->karta.boja==vratiboju(pomocnakarta.first) && pomocni->karta.vrijednost==pomocnakarta.second)stek.pop();
    else { std::shared_ptr<Cvor>zaubacivanje(std::make_shared<Cvor>());
     zaubacivanje->karta.boja=vratiboju(pomocnakarta.first);
     zaubacivanje->karta.vrijednost=pomocnakarta.second;
     zaubacivanje->sljedeci=pomocni;
     prosli->sljedeci=zaubacivanje;
     
     stek.pop();
    }
    
    }
  
}



int main ()
{ std::shared_ptr<Cvor>pok=nullptr;
   try{ 
    std::cout<<"Unesite korak razbrajanja: ";
    short int r; std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b; std::cin>>b;
    pok=KreirajSpil();
    std::stack<std::pair<std::string,std::string>> stek=IzbaciKarteRazbrajanjem(pok,r,b);
    std::cout<<"U spilu trenutno ima "<<52-b<<" karata, i to:"<<std::endl;
   
    std::shared_ptr<Cvor>pomocni(pok);
   
    for(int i=0;i<4;i++) {
    std::string nazivboje=vratistring(pomocni->karta.boja);
    std::cout<<nazivboje<<": ";
    while(vratistring(pomocni->karta.boja)==nazivboje){
       std::cout<<pomocni->karta.vrijednost<<" ";
     pomocni=pomocni->sljedeci;
    }
    std::cout<<std::endl;
    }
    
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";int vracanje; std::cin>>vracanje;
    VratiPosljednjihNKarata(pok,stek,vracanje);
    std::cout<<"U spilu trenutno ima "<<52-b+vracanje<<" karata, i to:"<<std::endl;
    pomocni=pok;
    for(int i=0;i<4;i++) {
    std::string nazivboje=vratistring(pomocni->karta.boja);
    std::cout<<nazivboje<<": ";
    while(vratistring(pomocni->karta.boja)==nazivboje){
       std::cout<<pomocni->karta.vrijednost<<" ";
     pomocni=pomocni->sljedeci;
    }
    std::cout<<std::endl;
    } 
  
   }
   catch(std::logic_error &izuzetak) {
    std::cout<<"Izuzetak: "<<izuzetak.what();
   }
   catch(std::domain_error &izuzetak) {
    std::cout<<"Izuzetak: "<<izuzetak.what();
   }
   catch(std::range_error &izuzetak) {
    std::cout<<"Izuzetak: "<<izuzetak.what();
   }
   
   pok->sljedeci=nullptr;
   	return 0;
}

