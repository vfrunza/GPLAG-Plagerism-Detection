#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <new>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst) {
    std::map<std::string,std::set<int>> mapa;
    int polozaj(0);
    int rijec(0),pomak(0),n;
    for(int i=0;i<tekst.length();i++) {
        while((tekst[i]<'a' && tekst[i]>'z') && (tekst[i]<'A' && tekst[i]>'Z') && (tekst[i]<'0' && tekst[i]>'9')) {
            i++;
        }
        polozaj=i;
        n=i;
        int broj(0);
        while((((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='A' && tekst[i]<='Z')) || (tekst[i]>='0' && tekst[i]<='9')) && i<tekst.length()) {
            i++;
            broj++;
        }
        std::set<int> skup;
        skup.insert(polozaj);
        rijec++;
        std::string s=tekst.substr(polozaj,broj);
        pomak=broj;
        polozaj+=broj;
         while(polozaj<tekst.length()) {
             while((tekst[polozaj]==' ' || ((tekst[polozaj]<'a' && tekst[polozaj]>'z') && (tekst[polozaj]<'A' && tekst[polozaj]>'Z')) || (tekst[polozaj]<'0' && tekst[polozaj]>'9')) && polozaj<tekst.length()) {
            polozaj++;
                 }
    int mjesto(polozaj);
            broj=0;
           while(!(tekst[polozaj]==' ' || ((tekst[polozaj]<'a' && tekst[polozaj]>'z') && (tekst[polozaj]<'A' && tekst[polozaj]>'Z')) || (tekst[polozaj]<'0' && tekst[polozaj]>'9')) && polozaj<tekst.length()) {
            polozaj++;
            broj++;
           }
        std::string pomocni=tekst.substr(mjesto,broj);
    if(pomocni==s) {
        skup.insert(mjesto);
    }
        rijec++;
         }
         mapa.insert(std::make_pair(s,skup));
         polozaj=n+pomak;
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string, std::set<int>> mapa) {
    std::set<int> povratni;
    if(!mapa.count(rijec)) throw std::logic_error("Pojam nije pronaden");
    else {
        auto it(mapa.find(rijec));
        povratni=it->second;
        return povratni;
    }
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa) {
    auto it(mapa.begin());
    auto it3(mapa.end());
    it3--;
    while(it!=mapa.end()) {
        std::cout<<it->first<<": ";
        for(int x: it->second) {
            std::set<int>::iterator it2(it->second.end());
            it2--;
            if(x!=*(it2)) {
            std::cout<<x<<",";
            }
            else
            std::cout<<x;
          }
          if(it!=it3)
        std::cout<<std::endl;
        it++;
    }
}

int main() {
    std::cout<<"Unesite tekst: ";
    std::string ulaz;
    std::getline(std::cin,ulaz);
    IspisiIndeksPojmova(KreirajIndeksPojmova(ulaz));
      std::string rijec;
    do {
        std::cout<<std::endl<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        try {
    auto skup(PretraziIndeksPojmova(rijec,KreirajIndeksPojmova(ulaz)));
 for(int x: skup)
 std::cout<<x<<" ";
        }
        catch(std::logic_error e) {
            std::cout<<"Unesena rijec nije nadjena!";
        }
    }while(rijec!=".");
    return 0;
}
