/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

struct Dijete {  
std::string ime;
Dijete *sljedeci;
};

int kolkoslova(std::string s) {
 int brojac(0);  
   for (int i = 0; i < s.length(); i++) {
      
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z' )|| ( s[i]>= '0' && s[i] <= '9')) brojac++;
      
      
      
   }
  return brojac; 
   
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> vektor, int broj) {
   
   if (broj < 1 or broj > vektor.size()) throw std::logic_error("Razvrstavanje nemoguce");
   
   std::vector<std::set<std::string>> novi;
   int broj_vise=vektor.size()%broj;
   int broj_manje=broj-broj_vise;
   int broj_normalnih=int(vektor.size()/broj);

     Dijete *pocetak(nullptr), *prethodni;

   for (int i = 0; i < vektor.size(); i++) {
    
    
    Dijete *novi(new Dijete);
    novi -> ime = vektor[i];
    novi -> sljedeci = pocetak;
  
    if (!pocetak) pocetak=novi;
    else prethodni -> sljedeci = novi;

              prethodni = novi;
              

   }
   
   

int brojac(0);
int brojacovaj(0);
     if(broj_vise == 0) {
     
       for (Dijete *p=pocetak ; brojacovaj != vektor.size()-1; p=p->sljedeci )
         {
             prethodni=p->sljedeci;
             brojacovaj++;

         }

   while (brojac < vektor.size()) { 
       

for (Dijete *p=pocetak ; brojac != vektor.size(); ) {

            std::set<std::string> setic;

    for ( int j = 0; j < broj_normalnih; j++) {


 
 setic.insert(p->ime);
 brojac++;
    int a=kolkoslova(p->ime);
       
        auto pomocni = p;
p=p->sljedeci;
prethodni->sljedeci=p;

delete pomocni;

for (int m = 0; m < a-1; m++) {
if (prethodni==p) break;
 p=p->sljedeci;
  prethodni=prethodni->sljedeci;
}


      }
      novi.push_back(setic);

     }
     }

}

    if(broj_vise != 0) {
     
       for (Dijete *p=pocetak ; brojacovaj != vektor.size()-1; p=p->sljedeci )
         {
             prethodni=p->sljedeci;
             brojacovaj++;

         }

   while (brojac < vektor.size()) { 
       

for (Dijete *p=pocetak ; brojac != vektor.size(); ) {

for (int i = 0; i < broj_vise; i++) {
                std::set<std::string> setic;

    for ( int j = 0; j < broj_normalnih+1; j++) {

 setic.insert(p->ime);
 brojac++;
    int a=kolkoslova(p->ime);
        auto pomocni = p;
p=p->sljedeci;
prethodni->sljedeci=p;

delete pomocni;

for (int m = 0; m < a-1; m++) {

if (prethodni==p) break;
 p=p->sljedeci;
  prethodni=prethodni->sljedeci;
}


      }
      novi.push_back(setic);
}
     
     
     for (int i = 0; i < broj_manje; i++){

            std::set<std::string> setic;

    for ( int j = 0; j < broj_normalnih; j++) {

setic.insert(p->ime);
 brojac++;
    int a=kolkoslova(p->ime);
        auto pomocni = p;
p=p->sljedeci;
prethodni->sljedeci=p;

delete pomocni;

for (int m = 0; m < a-1; m++) {

if (prethodni==p) break;
 p=p->sljedeci;
  prethodni=prethodni->sljedeci;
}


      }
      novi.push_back(setic);
}
     }
   }
    }
return novi;

}






int main ()
{
   std::cout<<"Unesite broj djece: ";
   int n;
   std::cin>>n;
   std::cout<<"Unesite imena djece: "<<std::endl;
   std::vector<std::string> vektor;
std::cin.ignore(1000, '\n');
   for (int i = 0; i < n; i++) {

      std::string ime;
   getline(std::cin, ime);
      vektor.push_back(ime);
              std::cin.clear();
       
   }
     
   std::cout<<"Unesite broj timova: ";
   int broj;
   std::cin>>broj;

try {
std::vector<std::set<std::string>> novi=Razvrstavanje(vektor,broj);

for (int i = 0; i < broj; i++) {

std::cout << "Tim " << i+1 << ":";
        
        for (auto pok=novi[i].begin(); pok != novi[i].end(); pok++)
        
    {
            pok++;
                auto pomocni = pok;
                    pok--;
                        if(pomocni==novi[i].end()) std::cout<<" "<<*pok<<std::endl;
                        else std::cout<<" "<<*pok<<",";
       
       }

}
}

catch(std::logic_error e) {
    
   std::cout<<"Izuzetak: "<<e.what();
   return 0;
    
    
}



	return 0;
}