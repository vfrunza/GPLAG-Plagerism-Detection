/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <utility>
#include <stdexcept>

std::map<std::string, int> KreirajIndeksPojmova(std::string s) {
    
}

PretraziIndeksPojmova(std::string, std::map<int> m) {
    
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(std::map<set<int>> m) {
    
}

int main ()
{
    try {
        std::string tekst;
        std::cout << "Unesite tekst: ";
        std::getline(std::cin, tekst);
        std::string rijec;
        do {
            std::cout << "Unesite rijec: ";
            std::cin >> rijec;
            if(rijec=='.') break;
        } while(rijec!='.');
    }
    
    catch(std::logic_error e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}