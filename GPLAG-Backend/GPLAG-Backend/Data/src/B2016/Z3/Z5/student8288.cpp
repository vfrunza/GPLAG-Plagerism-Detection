#include <iostream>
#include <iomanip>
#include <string>
#include <new>
#include <vector>
#include <stdexcept>
#include <set>
#include <algorithm>
#include <cmath>
#include <list>

struct Dijete {
    std::string ime;
    Dijete* sljedeci=nullptr;
};
  std::vector<std::set<std::string>>  Razvrstavanje(std::vector<std::string> v,int n) {
  std::vector<std::set<std::string>> rezultat;
  try {
      if(n<=0 || n>v.size()) {
          throw std::logic_error("Razvrstavanje nemoguce");
      }
      Dijete * pocetak(nullptr),*prethodni(nullptr);
  
      for(int i=0;i<v.size();i++) {
        Dijete* novi(nullptr);
        novi=new Dijete;
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else {
          if(i==v.size()-1) {
            prethodni->sljedeci=pocetak;
          }
          else {
        prethodni->sljedeci=novi;
      }
        }
  }
  int cijeli(v.size()/n);
  int ost(v.size()%n);
  for(int j=0;j<n;j++) {
    for(auto p=pocetak;p->sljedeci!=pocetak;p=p->sljedeci) {
      int broj(0);
      if(j<ost) {
         std::set<std::string> pomocni;
        while(broj<cijeli+1) {
        pomocni.insert(p->ime);
        auto tu(p);
        while(p->sljedeci!=tu) {
          p=p->sljedeci;
        }
        p->sljedeci=tu->sljedeci;
        delete tu;
      p=p->sljedeci;
        broj++;
        int duz((p->ime).length());
        for(int i=0;i<duz-1;i++) {
          p=p->sljedeci;
        }
      }
      rezultat.push_back(pomocni);
    }
    else {
      broj=0;
      std::set<std::string> usput;
      while(broj<cijeli) {
        usput.insert(p->ime);
        auto prije(p);
        while(p->sljedeci!=prije) {
          p=p->sljedeci;
        }
        p->sljedeci=prije->sljedeci;
        delete prije;
        p=p->sljedeci;
        broj++;
        int pom((p->ime).length());
        for(int i=0;i<pom-1;i++) {
          p=p->sljedeci;
        }
      }
      rezultat.push_back(usput);
    }
  }
}
}
catch(std::logic_error e) {
  std::cout<<e.what()<<std::endl;
}
catch(std::bad_alloc) {
  std::cout<<"Neuspjela alokacija!"<<std::endl;
}
return rezultat;
}

int main() {
  std::cout<<"Unesite broj djece: ";
  int s;
  std::cin>>s;
  std::cin.ignore(1000,'\n');
  std::vector<std::string> v;
  std::cout<<"Unesite imena djece: ";
  for(int i=0;i<s;i++) {
    std::string  ulaz;
    std::getline(std::cin,ulaz);
    v.push_back(ulaz);
  }
  std::cout<<std::endl<<"Unesite broj timova: ";
  int d;
  std::cin>>d;
  
  auto vrsta(Razvrstavanje(v,d));
  for(int t=0;t<vrsta.size();t++) {
    std::cout<<"Tim "<<t+1<<": ";
    std::set<std::string>::iterator it(vrsta[t].end());
    it--;
    for(std::string izlaz: vrsta[t]) {
      if(izlaz!=*it) {
        std::cout<<izlaz<<", ";
        }
        else 
        std::cout<<izlaz;
    }
    std::cout<<std::endl;
  }
  return 0;
}