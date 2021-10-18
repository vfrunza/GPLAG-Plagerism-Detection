/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int kolkoslova(std::string s) {
 int brojac(0);  
   for (int i = 0; i < s.length(); i++) {
      
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z' )|| ( s[i]>= '0' && s[i] <= '9')) brojac++;
      
      
      
   }
  return brojac; 
   
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> vektor, int broj) {
   
  if (broj < 1 or broj > vektor.size()) throw std::logic_error("Razvrstavanje nemoguce");
   int n=vektor.size();
   std::list<std::string> lista;
   std::vector<std::set<std::string>> novi;
   int broj_vise=n%broj;
   int broj_manje=broj-broj_vise;
   int broj_normalnih=int(n/broj);

   for (int i = 0; i < vektor.size(); i++) lista.push_back(vektor[i]);
       
       auto it = lista.begin();
     
     if(broj_vise == 0) {
     while (!lista.empty()) {

      for ( int i = 0; i < broj; i++) {
            std::set<std::string> setic;

      for ( int j = 0; j < broj_normalnih; j++) {
 setic.insert(*it);
int a=kolkoslova(*it);

      it=lista.erase(it);
      if (it == lista.end()) { 
 it=lista.begin(); 
 }

for (int m = 0; m < a-1; m++) {

 it++;
  if (it == lista.end()) { 
 it=lista.begin(); 
 }
}


      }
      novi.push_back(setic);

     }
     }

}

   if(broj_vise != 0) {
     while (!lista.empty()) {

      for ( int i = 0; i < broj_vise; i++) {
            std::set<std::string> setic;

      for ( int j = 0; j < (broj_normalnih+1); j++) {
 setic.insert(*it);
int a=kolkoslova(*it);

     it=lista.erase(it); 
     if (it == lista.end()) { 
 it=lista.begin(); 
 }

for (int m = 0; m < a-1; m++) {

 it++;
  if (it == lista.end()) { 
 it=lista.begin(); 
 }
}


      }
      novi.push_back(setic);

      
      }
        for ( int i = 0; i < broj_manje; i++) {
 
          std::set<std::string> setic;

      for ( int j = 0; j < broj_normalnih; j++) {
 setic.insert(*it);
int a=kolkoslova(*it);

it=lista.erase(it);
if (it == lista.end()) { 
 it=lista.begin(); 
 }

for (int m = 0; m < a-1; m++) {

 it++;
  if (it == lista.end()) { 
 it=lista.begin(); 
 }

}


      }
      novi.push_back(setic);

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