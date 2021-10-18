/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <new>
#include <cstring>
#include <algorithm>

std::vector<list>Razvrstavanje(std::string s, int tim) {
    
}

int main() {
    int broj_recenica;
    try {
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_recenica;
    std::cin.ignore(10000, '\n'); 
    std::vector<char*> recenice(broj_recenica);
    std::cout << "Unesite imena djece: ";
    for(int i = 0; i < broj_recenica; i++) {
        char radni_prostor[1000];
        std::cin.getline(radni_prostor, 1000);
        recenice[i] = new char[std::strlen(radni_prostor) + 1];
        std::strcpy(recenice[i], radni_prostor);
    }
    
    std::cout << "Unesite broj timova: ";
    int timovi;
    std::cin >> timovi;
    
    } catch (logic_error) {
        std::cout << "Razvrstavanje nemoguce";
    }
    
 
return 0;
}