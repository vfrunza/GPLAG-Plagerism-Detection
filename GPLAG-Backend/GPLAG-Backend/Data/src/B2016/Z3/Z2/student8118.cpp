/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stdexcept>
std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s) {
    std::map<std::string, std::set<int>> mapa;
    int brojac1(0), brojac2(0), brojac(0);
    auto pok(s.begin());
    while (pok!=s.end()) {
        if (*pok>='A' && *pok<='Z') 
            *pok+=32;
            pok++;
    }
    pok=s.begin();
    while (pok!=s.end()) {
        std::string novi;
        novi.resize(0);
        while (pok!=s.end()) {
            if ((*pok<'a' || *pok>'z') && (*pok<'0' || *pok>'9')) {
                pok++;
                brojac1++;
            }
            else break;
        }
    if (pok==s.end()) break;
    auto pocetak(s.begin());
    auto pocetakrijeci(pok);
    brojac=pocetakrijeci-pocetak;
    while (pok!=s.end()) {
        if ((*pok>='a' && *pok<='z') || (*pok>='0' && *pok<='9')) {
            novi.push_back(*pok);
            pok++;
            brojac2++;
        }
        else break;
    }
    auto it(mapa.find(novi));
    if (it!=mapa.end()) {
        it->second.insert(brojac);
    }
    if (it==mapa.end()) {
    mapa.insert(std::make_pair(novi, std::set<int>{brojac}));
    }
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>>mapa) {
    std::set<int>skup;
    auto it(mapa.find(s));
    if (it!=mapa.end()) { 
    auto drugi(it->second.begin());
    for (int i=0; i<it->second.size(); i++) {
        skup.insert({*drugi});
        drugi++;
    }
    }
    else {
        throw std::logic_error ("Pojam nije nadjen");
    }
    return skup;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    auto prvi(mapa.begin());
    for (prvi=mapa.begin(); prvi!=mapa.end(); prvi++) {
        std::cout<<prvi->first<<": ";
    auto drugi(prvi->second.begin());
    for (int i=0; i<prvi->second.size()-1; i++){
        std::cout<<*drugi<<",";
        drugi++;
    }
    std::cout<<*drugi<<std::endl;
    }
}
int main ()
{
  std::cout<<"Unesite tekst: ";
  std::string s;
  std::getline(std::cin, s);
  std::map<std::string, std::set<int>>mapa(KreirajIndeksPojmova(s));
  IspisiIndeksPojmova(mapa);
  std::string rijec;
  for (;;) {
      std::cout<<"Unesite rijec: ";
      std::set<int> skup;
      std::getline(std::cin, rijec);
      if (rijec==".") break;
      try { 
         skup=(PretraziIndeksPojmova(rijec, mapa));
         for (auto x:skup) std::cout<<x<<" ";
         std::cout<<std::endl;
      }
      catch (std::logic_error ) {
          std::cout<<"Unesena rijec nije nadjena!\n";
      }
  }
	return 0;
}