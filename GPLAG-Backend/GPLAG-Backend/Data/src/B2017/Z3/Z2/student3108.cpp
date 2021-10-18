/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <algorithm>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool DaLiJeSlovoIliCifra (char c) {
    return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>=0 && c<=9);
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova (Knjiga k) {
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa;
    auto it = k.begin();
    for (auto it = k.begin(); it != k.end(); it++) { // it ide kroz mapu k
       std::vector<std::string> v = it->second;
        for (int i = 0; i < v.size(); i++) { // i ide kroz clanove vektora sto predstavljaju stranice
            for (int j = 0; j < v[i].length(); j++) { // j ide kroz svaku stranicu vektora (kroz tekst koji se nalazi na stranici)
                int poc, kraj;
                if (DaLiJeSlovoIliCifra(v[i][j])) {
                    poc = j;
                    while (j < v[i].length() && DaLiJeSlovoIliCifra(v[i][j])) j++;
                    kraj = j;
                    std::string str = v[i].substr(poc, kraj-poc);
                    std::transform (str.begin(), str.end(), str.begin(), ::tolower);
                    auto itmapa = mapa.find(str);
                    if (itmapa != mapa.end())  itmapa->second.insert (std::make_tuple(it->first, i+1, poc)); 
                    else {
                        std::set<std::tuple<std::string, int, int>> set;
                        set.insert (std::make_tuple (it->first, i+1, poc));
                        mapa.insert (std::make_pair (str, set));
                    }
                }
            }
        }
    }
    return mapa;
}
 

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> indekspojmova) {
    std::transform (rijec.begin(), rijec.end(), rijec.begin(), ::tolower);
     if (!indekspojmova.count(rijec)) throw std::logic_error ("Pojam nije nadjen");
     std::set<std::tuple<std::string, int, int>> indeksi;
     auto it = indekspojmova.find (rijec);
     indeksi = it->second;
     return indeksi;
 }
 
 
void IspisiIndeksPojmova (std::map<std::string, std::set<std::tuple<std::string, int, int>>> indekspojmova) {
      for (auto it = indekspojmova.begin(); it != indekspojmova.end(); it++) {
          std::cout << std::endl << it->first << ": " ;
          auto kraj = it->second.end() --;
          kraj--;
          auto it2 = it->second.begin();
          for (it2 = it->second.begin(); it2 != kraj; it2++) {
            std::cout << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2) << ", ";
          }
          std::cout << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2);
          
      }
  }

int main ()
{
    std::vector<std::string> v;
    Knjiga k;
    std::string poglavlje;
    std::string str1;
    do {
        std::cout << "Unesite naziv poglavlja: ";
        std::getline (std::cin, poglavlje);
        int i = 1;
        if (poglavlje != ".") {
            do {
                std::cout << "Unesite sadrzaj stranice " << i << ": ";
                std::getline (std::cin, str1);
                if (str1 != ".") {
                   v.push_back (str1); 
                   k.insert (std::make_pair (poglavlje, v));
                } 
                i++;
            } while (str1 != ".");
        }
        
    } while (poglavlje != ".");
    std::cout << std::endl << "Kreirani indeks pojmova:";
    auto indeks = KreirajIndeksPojmova (k);
    IspisiIndeksPojmova (indeks);
    std::string rijec;
    do {
        std::cout << std::endl << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if (rijec != ".") {
            try {
                auto indeksi = PretraziIndeksPojmova (rijec, indeks);
                for (auto it = indeksi.begin(); it != indeksi.end(); it++) std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << " ";
            } catch (std::logic_error e) {
                std::cout << "Unesena rijec nije nadjena!";
            }
        }
    } while (rijec != ".");
    
	return 0;
}
