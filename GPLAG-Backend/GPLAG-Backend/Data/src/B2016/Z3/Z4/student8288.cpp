#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdexcept>
#include <new>
#include <vector>
#include <set>
#include <algorithm>
#include <list>
#include <forward_list>

 std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v,int n) {
    try {
    if(n<1 || n>v.size()) {
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    std::forward_list<std::string> lista;
   for(int i=0;i<v.size();i++) {
       lista.insert(v[i]);
   }
    std::forward_list<std::string>::iterator it(lista.begin());
    std::forward_list<std::string>::iterator it2(lista.before_begin());
    std::forward_list<std::string>::iterator it3(lista.end());
std::vector<std::set<std::string>> rezultat;
int broj(0);
int cijeli(v.size()/n);
int ost(v.size()%n);
for(int j=0;j<n;j++) {
    broj=0;
    if(j<ost) {
        std::set<std::string> pomoc;
        int duz;
        broj=0;
    while(broj<cijeli+1 && it!=lista.end()) {
        pomoc.insert(*it);
        duz=(*it).length();
          broj++;
          it2++;
          if(it!=it3) {
          it.erase_after(it);
          }
          else 
          it2=lista.begin();
          delete *it;
          it=it2;
      for(int k=0;k<duz-1;k++) {
        it++;
        it2++;
         if(it==lista.end()) {
        it=lista.begin();
     }
    }
    }
    rezultat.push_back(pomoc);
   }
    else {
        std::set<std::string> usput;
        int slova(0);
         while(broj<cijeli && it!=lista.end()) {
    usput.insert(*it);
    broj++;
    slova=(*it).length();
     if(it!=it3) {
          it.erase_after(it);
          }
          else 
          it2=lista.begin();
          delete *it;
          it=it2;
     for(int k=0;k<slova-1;k++) {
        it++;
           if(it==lista.end()) {
        it=lista.begin();
     }
    }
         }
    rezultat.push_back(usput);
    }
}
return rezultat;
}
catch(std::logic_error e) {
    std::cout<<e.what()<<std::endl;
}
}

int main() {
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cin.ignore(1000,'\n');
    std::vector<std::string> v;
    std::cout<<"Unesite imena djece: ";
    for(int u=0;u<n;u++) {
        std::string ulaz;
        std::getline(std::cin,ulaz);
        if(ulaz.length()!=0) {
            v.push_back(ulaz);
        }
    }
  
    std::cout<<std::endl<<"Unesite broj timova: ";
    int z;
    std::cin>>z;
    auto vrsta(Razvrstavanje(v,z));
    for(int f=0;f<vrsta.size();f++) {
         std::cout<<"Tim "<<f+1<<": ";
         std::set<std::string>::iterator it(vrsta[f].end());
         it--;
        for(std::string izlaz: vrsta[f]) {
            if(izlaz!=*it) 
            std::cout<<izlaz<<", ";
            else 
            std::cout<<izlaz;
        }    
        std::cout<<std::endl;
    }
    return 0;
    }
    