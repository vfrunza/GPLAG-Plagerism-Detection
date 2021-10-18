/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <stdexcept>

bool Provjera(char slovo) {
    if((slovo>='0' && slovo<='9') || (slovo>='A' && slovo<='Z') || (slovo>='a' && slovo<='z')) return true;
    else return false;
}

std::string MalaSlova(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

std::vector<std::string> VeSt(std::string s) {
    std::vector<std::string> temp;
    for(int i=0; i<s.size(); i++) {
        std::string unos;
        int brojac=0;
        while(i<s.size() && (Provjera(s[i]))) {
            brojac++;
            i++;
        }
        unos=s.substr(i-brojac, brojac);
        temp.push_back(unos);
    }
    return temp;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string Analiza) {
    std::map<std::string, std::set<int>> maps;
    std::string temp(MalaSlova(Analiza));
    std::vector<std::string> rijec(VeSt(temp));
    std::sort(rijec.begin(), rijec.end());
    rijec.erase(unique(rijec.begin(), rijec.end()), rijec.end());
    
    for(int a=0; a<rijec.size(); a++) {
        std::set<int> temp1;
        int b;
        for(b=0; b<temp.size(); b++) {
            if(rijec[a]==temp.substr(b ,rijec[a].size())) temp1.insert(b);
        }
        maps.insert(std::make_pair(rijec[a], temp1));
    }
    return maps;
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> &maps) {
    for(auto it1=maps.begin(); it1!=maps.end(); it1++) {
        if((*it1).first == s) return (*it1).second;
    }
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> maps) {
    for(auto it1=maps.begin(); it1!=maps.end(); it1++) {
        auto it2(it1->second.begin());
        std::cout << (*it1).first << ": ";
        for(auto i=0; i<(*it1).second.size(); i++) {
            if(i!=(it1->second.size()-1)) {
                std::cout << *it2++ << ",";
            } else  {
                std::cout << *it2;
            }
        }
        std::cout << std::endl;
    }
}

int main () {
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> maps(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(maps);
    while(1) {
        std::string s1;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, s1);
        if(s1[0]=='.') break;
        try {
            std::set<int>temp(PretraziIndeksPojmova(s1, maps));
            auto it=temp.begin();
            for(int i=0; i<temp.size(); i++) {
                if(i!=temp.size()-1) {
                    std::cout << *it++ << " ";
                } else {
                    std::cout << *it;
                }
            }
            std::cout << std::endl;
        } catch (...) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}