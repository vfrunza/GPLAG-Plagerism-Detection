/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <tuple>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

/*std::map<std::string, std::tuple<std::string, int, int>> KreirajIndeksPojmova(Knjiga analiza) { 
    std::map<std::string, std::tuple<std::string, int, int>> trojke;
    
}*/

std::map<std::string, std::tuple<std::string, int, int>>KreirajIndeksPojmova(Knjiga tekst) {
    std::map<std::string, std::tuple<std::string, int, int>> mapa;
    std::vector<std::string>s;
    std::vector<int>s1;
    for(auto it1=tekst.begin(); i1!=tekst.end(); it1++) {
        
    }
    throw std::logic_error("Pojam nije nadjen");
}

int main () {
    Knjiga s;
    std::cout << "Unesite naziv poglavlja: ";
    std::string poglavlje;
    std::cin >> poglavlje;
    int i=1;
    std::vector<std::string>stranice;
    for(;;) {
        std::cout << "Unesite sadrzaj stranice " << i << ": ";
        std::string s;
        if(s[0]!='.') stranice.push_back(std::getline(std::cin, s));
        else break;
    }
    std::map<std::string, std::tuple<std::string, int, int>> rez(KreirajIndeksPojmova(s));
//    mape=KreirajIndeksPojmova(s);
	return 0;
}
