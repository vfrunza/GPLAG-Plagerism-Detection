/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

bool ValidnoSlovo(char c) {
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}
std::map<std::string, std::set<int> > KreirajIndeksPojmova(std::string s) {
  s += ' ';
  std::vector<std::string> SpisakRijeci; 
  std::string TrenutnaRijec = "";
  std::map<std::string, std::set<int> > Mapa;
  
  for(int i = 0; i < s.length(); i++) {
    if (ValidnoSlovo(s[i])) TrenutnaRijec += s[i];
    else {
      if (TrenutnaRijec.length() > 0) {
        for (int i = 0; i < TrenutnaRijec.length(); i++) 
          if (TrenutnaRijec[i] >= 'A' && TrenutnaRijec[i] <= 'Z') TrenutnaRijec[i] += 32;
      
        SpisakRijeci.pb(TrenutnaRijec);
        int PocetakRijeci = i - TrenutnaRijec.length(); 
        Mapa[TrenutnaRijec].insert(PocetakRijeci);
        //std::cout << TrenutnaRijec << " = " << PocetakRijeci << "\n";
      }
      TrenutnaRijec = "";
    }
  }
  
  return Mapa;
}
void IspisiIndeksPojmova(const std::map<std::string, std::set<int> > &Mapa) {
  for(auto x = Mapa.begin(); x != Mapa.end(); x++) {
    std::cout << x->ff << ": ";
    int BrojElemenata = x->ss.size() - 1;
    for(auto j = x->ss.begin(); j != x->ss.end(); j++, BrojElemenata--) 
      if(BrojElemenata) std::cout << *j << ",";
      else std::cout << *j << "\n";
  }
}
std::set<int> PretraziIndeksPojmova(std::string query, const std::map<std::string, std::set<int> > &Mapa) {
  std::set<int> ret;
  bool postoji = 0;
  for (int i = 0; i < query.length(); i++)
    if (query[i] >= 'A' && query[i] <= 'Z') query[i] += 32;
  for(auto x = Mapa.begin(); x != Mapa.end(); x++) {
    if (x->ff == query) {
      postoji = 1;
      for (auto y = x->ss.begin(); y != x->ss.end(); y++) ret.insert(*y);
    }
  }
  if (!postoji) throw std::logic_error("Pojam nije nadjen");
  return ret;
}
int main () {
  std::cout << "Unesite tekst: "; std::string Tekst; getline(std::cin, Tekst);
  std::map<std::string, std::set<int> > M = KreirajIndeksPojmova(Tekst);
	IspisiIndeksPojmova(M);
	while (1) {
	  std::string upit;
	  std::set<int> Set;
	  std::cout << "Unesite rijec: "; std::cin >> upit;
	  if (upit == ".") break;
	  try {
	    Set = PretraziIndeksPojmova(upit, M);
	    for (auto x = Set.begin(); x != Set.end(); x++) std::cout << *x << " ";
	    std::cout << "\n";
	  }
	  catch(std::logic_error c) {
	    std::cout << "Unesena rijec nije nadjena!\n";
	  }
	}
	return 0;
}