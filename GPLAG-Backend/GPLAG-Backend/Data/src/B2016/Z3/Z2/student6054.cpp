/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <set>
#include <cctype>
#include <algorithm>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> indeks;
    

    for (int i = 0; i < s.length(); i++) {
        int pos(i);
        std::string rijec;
        
        while (std::isalnum(s[i]) && i < s.length()) {
            rijec.push_back(std::tolower(s[i]));
            i++;
        }
        
        if (!rijec.empty()) {
            indeks[rijec].insert(pos);
        }
    }
    
    return indeks;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> indeks) {
    
    if (indeks.find(s) == indeks.end()) {
        throw std::logic_error("Unesena rijec nije nadjena!");
    }
    
    return indeks[s];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indeks){

    for (auto x : indeks) {
        std::cout << x.first;
        std::cout << ": ";
        
        int i = 0;
        for (auto e : x.second) {
            std::cout << e;
            
            if (i < x.second.size() - 1) {
                std::cout << ",";
            }
            
            i++;
        }
        
        std::cout << "\n";
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string str;
    std::getline(std::cin,str);
    auto pojmovi(KreirajIndeksPojmova(str));
    IspisiIndeksPojmova(pojmovi);
    while(std::cout << "Unesite rijec: ", std::getline(std::cin,str), str != "."){
         try{
              auto temp (PretraziIndeksPojmova(str,pojmovi));
              for(auto i(temp.begin()); i!= temp.end(); i++)
                    std::cout << *i << " ";
               std::cout << std::endl;
         }catch(std::logic_error greska){
              std::cout << "Unesena rijec nije nadjena!" << std::endl;
         }
    }
	return 0;
}