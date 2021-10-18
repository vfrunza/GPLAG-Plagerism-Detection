/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <utility>


bool JeLiSlovo(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    else return false;
}

bool JeLiCifra(char c) {
    if (c >= '0' && c <= '9') return true;
    else return false;
}

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;

IndeksPojmova KreirajIndeksPojmova(Knjiga k) {
    IndeksPojmova indeks;
    if (k.size() == 0) return indeks;
    for (auto it = k.begin(); it != k.end(); it++) {
        for (int i=0; i<it->second.size(); i++) {
            for (int j=0; j<it->second[i].length(); j++) {
                std::string pom;
                while ((JeLiSlovo(it->second[i][j]) || JeLiCifra(it->second[i][j])) && j != it->second[i].length()) {
                    pom.push_back(it->second[i][j]);
                    j++;
                }
                
                std::transform(pom.begin(), pom.end(), pom.begin(), (int(*) (int))std::tolower);
                 auto it2(indeks.find(pom));
                 if (indeks.count(pom) == 0) {
                     if (pom.length() != 0) {
                        int ind = j-pom.length();
                        indeks.insert(std::pair<std::string,
                        std::set<std::tuple<std::string, int, int>>>(pom, {std::make_tuple(it->first, i+1, ind)}));
                     }
                 }
                 else {
                     if (pom.length() != 0) {
                         int ind = j-pom.length();
                         (it2->second).insert(std::make_tuple(it->first, i+1, ind));
                     }
                 }
                
            }
            
        }
    }
    return indeks;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string s, IndeksPojmova i) {
    std::set<std::tuple<std::string, int, int>> rez;
    std::transform(s.begin(), s.end(), s.begin(), (int(*) (int))std::tolower);
    auto it(i.find(s));
    if (i.count(s) == 0) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova(IndeksPojmova i) {
    std::cout<<"Kreirani indeks pojmova: \n";
    for (auto it = i.begin(); it != i.end(); it++) {
        std::cout<<it->first<<": ";
        for (auto x=(it->second).begin(); x != (it->second).end(); x++) {
            if (x != (it->second).begin()) std::cout<<", ";
            std::cout<<std::get<0>(*x)<<"/"<<std::get<1>(*x)<<"/"<<std::get<2>(*x);
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string poglavlje, str;
    
    Knjiga k;
    do {
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin, poglavlje);
        if (poglavlje == ".") break;
        std::vector<std::string> v;
        int i=1;
        do {
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline(std::cin, str);
            v.push_back(str);
            if (str == ".") break;
            i++;
        }
        while (str != ".");
        k.insert(std::make_pair(poglavlje, v));
    }
    while (poglavlje != ".");
    std::cout<<std::endl;
    
    IndeksPojmova i = KreirajIndeksPojmova(k);
    IspisiIndeksPojmova(i);
    std::cout<<std::endl;
    
    std::string pom;
    do {
        try {
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, pom);
            if (pom == ".") break;
            std::set<std::tuple<std::string, int, int>> a = PretraziIndeksPojmova(pom, i);
            for (auto b:a) {
                std::cout<<std::get<0>(b)<<"/"<<std::get<1>(b)<<"/"<<std::get<2>(b)<<" ";
            }
            std::cout<<std::endl;
        }
        catch(std::logic_error e) {
            std::cout<<e.what()<<std::endl;
        }
    }
    while (pom != ".");
	return 0;
	
}



