/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <stdexcept>

typedef std::map <std::string, std::vector<std::string>> Knjiga;
typedef std::map <std::string, std::set<std::tuple<std::string, int, int>>> Index;
typedef std::set <std::tuple<std::string, int, int>> SkupPozicija;


Index KreirajIndeksPojmova (Knjiga k) {
    
    Index index;
    
    // pretvaranje u mala slova
    for (Knjiga::iterator it=std::begin(k); it!=std::end(k); it++)
        for (int i=0; i<it->second.size(); i++)
            for (int j=0; j<it->second[i].length(); j++)
                if (it->second[i][j]>='A' && it->second[i][j]<='Z')
                    it->second[i][j]+=32;

    
    for (Knjiga::iterator it=std::begin(k); it!=std::end(k); it++)
        for (int i=0; i<it->second.size(); i++)
            for (int j=0; j<it->second[i].length();) {
                std::string rijec;
                while (((it->second[i][j]>=0 && it->second[i][j]<'0') || (it->second[i][j]>'9' && it->second[i][j]<'A') || (it->second[i][j]>'Z' && it->second[i][j]<'a') || (it->second[i][j]>'z' && it->second[i][j]<=255)) && j<it->second[i].length())
                    j++;
                    
                int start=j;
                
                while (((it->second[i][j]>='A' && it->second[i][j]<='Z') || (it->second[i][j]>='a' && it->second[i][j]<='z') || (it->second[i][j]>='0' && it->second[i][j]<='9')) && j<it->second[i].length()) {
                    rijec.push_back(it->second[i][j]);
                    j++;
                }
                
                index[rijec].insert(std::make_tuple(it->first, i+1, start));
            }
    
    return index;
}


SkupPozicija PretraziIndeksPojmova (std::string rijec, Index index) {
    
    auto ima(index.find(rijec));
    
    if (ima == std::end(index)) throw std::logic_error ("Pojam nije nadjen");
    
    return ima->second;
}

void IspisiIndeksPojmova (Index index) {
    
    for (Index::iterator it=std::begin(index); it!=std::end(index); it++) {
        std::cout << it->first << ": ";
        for (auto rit=std::begin(it->second); rit!=std::end(it->second); rit++) {
            std::cout << std::get<0>(*rit) << "/" << std::get<1>(*rit) << "/" << std::get<2>(*rit);
            if (rit!=--std::end(it->second)) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}





int main ()
{
    Knjiga k;
    
    std::string poglavlje("*");
    
    while (poglavlje!=".") {
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, poglavlje);
        if (poglavlje==".") break;
        int i=0;
        std::string stranica("*");
        while (stranica!=".") {
            std::cout << "Unesite sadrzaj stranice " << i+1 << ": ";
            std::getline(std::cin, stranica);
            if (stranica==".") break;
            k[poglavlje].push_back(stranica);
            i++;
        }
    }
    
    std::cout << std::endl << "Kreirani indeks pojmova:" << std::endl;
    
    Index index;
    index=KreirajIndeksPojmova(k);
    IspisiIndeksPojmova(index); 
    
    std::string rijec("*");
    while (rijec!=".") {
        std::cout << "Unesite rijec: ";
        std::getline (std::cin, rijec);
        if (rijec==".") break;
        try {
            SkupPozicija s=PretraziIndeksPojmova(rijec, index);
            for (auto it=std::begin(s); it!=std::end(s); it++)
                std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << " ";
            std::cout << std::endl;
        }
        catch (...) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
    
    
	return 0;
}
