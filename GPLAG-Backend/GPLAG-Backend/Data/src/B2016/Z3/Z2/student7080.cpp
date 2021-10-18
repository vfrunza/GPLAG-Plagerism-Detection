/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> rjecnik;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, int> m) {
    
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m) {
    for(auto it1 = m.begin(); it1 != m.end(); it1++) {
      std::cout << it1 -> first << ": ";
      for(auto it2 = (it1 -> second).begin();  it2 != (it1 -> second).end(); it2++) {
          std::cout << *it2;
          if(it2 != --(it1 -> second).end()) std::cout << ",";    // !!!!!
      }
      std::cout << std::endl;
    }    
}

int main ()
{
    try {
        std::cout << "Unesite tekst: ";
        std::string s;
        std::getline(std::cin, s);
    }
    catch (std::logic_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    
	return 0;
}