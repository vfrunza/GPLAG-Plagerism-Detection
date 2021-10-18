/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int DuzinaRijeci(std::string s) {
    int brojac(0);
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9') brojac++;
    }
    //std::cout<<"Moja duzina je "<<brojac<<std::endl;
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int broj_timova) {
    if(broj_timova<1 || broj_timova>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");

    std::vector<std::set<std::string>> nova(broj_timova);
      std::list<std::string> lista;
      for(int i=0; i<imena.size(); i++) lista.push_back(imena[i]);
      
      int modul(imena.size()%broj_timova);
      int prvi_timovi((imena.size()/broj_timova)+1);
      
      std::vector<int> velicina(broj_timova);
      
      if(imena.size()%broj_timova==0) {
          velicina[0]=(imena.size()/broj_timova)-1;
          for(int i=1; i<broj_timova; i++) velicina[i]=(imena.size()/broj_timova);
      }
      else {
      velicina[0]=prvi_timovi-1;
      for(int i=1; i<broj_timova; i++) {
         while((modul-1)!=0) { velicina[i]=prvi_timovi;
          i++;
          modul--;
          }
         
         velicina[i]=prvi_timovi-1;
         
      }
      }

      
      auto x(lista.begin());
      nova[0].insert(*x);
      int duzina(DuzinaRijeci(*x));
      x=lista.erase(x);
      if(x==lista.end()) x=lista.begin();
      
      int z(0);
      
      while(lista.size()!=0) {
          if(lista.size()==1) break;
      for(int i=0; i<velicina[z]; i++) {
          
          for(int i=0; i<duzina-1; i++) {
              if(x==lista.end()) x=lista.begin();
              x++; 
          }
            if(x==lista.end()) x=lista.begin();
          if(i==velicina[z]-1 && x==lista.end()) x++;
           if(x==lista.end()) x=lista.begin(); 
          duzina=DuzinaRijeci(*x);
        
        
         nova[z].insert(*x);
         x=lista.erase(x);
         if(x==lista.end()) x=lista.begin(); 
      }
      z++;
      
     }
     if(x!=lista.end()) nova[z].insert(*x);
      return nova;
  }

int main ()
{
    int br;
    std::cout<<"Unesite broj djece: ";
    std::cin>>br;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::vector<std::string> vektor;
    std::cout<<"Unesite imena djece: "<<std::endl;
    
    for(int i=0; i<br; i++) {
        std::string string;
        std::getline(std::cin, string);
        vektor.push_back(string);
    }
    
    std::cout<<"Unesite broj timova: ";
    std::cin>>br;
    std::vector<int> elementi;
    elementi.resize(br);
    
    try{
        auto skup=Razvrstavanje(vektor,br);
        for(int i=0; i<skup.size(); i++) {
            std::cout<<"Tim "<<i+1<<": ";
            for(auto x=skup[i].begin(); x!=skup[i].end(); x++) {
                if(x!=(--skup[i].end())) std::cout<<*x<<", ";
                else std::cout<<*x;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error greska) {
        std::cout<< "Izuzetak: " << greska.what()<<std::endl;
    }
    
	return 0;
}
