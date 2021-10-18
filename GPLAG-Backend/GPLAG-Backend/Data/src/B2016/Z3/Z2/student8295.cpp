/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <stdexcept>

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> rjecnik) {
    for(auto it = rjecnik.begin(); it!=rjecnik.end(); it++) {
        std::cout<<it->first<<": ";
        int brojac(0);
        for(int x : it-> second) {
            brojac++;
        }
        int brojac2(0);
        for(int x : it->second) {
            if(brojac2==brojac-1){
                std::cout<<x;
                break;
            }
            std::cout<<x<<",";
            brojac2++;
        }
        std::cout<<std::endl;
    }
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa) {
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        if(it->first == rijec) return it->second;
    }
    throw std::logic_error("Unesena rijec nije nadjena!");
} 

void Umala(std::string &s) {
    for(int i(0); i<s.length(); i++) 
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    Umala(s);
    for(int i(0); i<s.length(); i++) 
        std::tolower(s[i]);
    std::map<std::string, std::set<int>> rez;
    for(int i(0); i<s.length(); i++) {
        //while (s[i]==' ') i++;
        if((s[i]>='a' && s[i]<='z') || (s[i]>='1' && s[i]<='9')) {
            int k=i;
            while (((s[i]>='a' && s[i]<='z') || (s[i]>='1' && s[i]<='9')) && i<s.length()) i++;
            std::string rijec(s.substr(k,i-k));
            std::set<int> skup;
            skup.insert(k);
            for(int j(i); j<s.length(); j++) {
                int l(0);
                if(s[j]==rijec[l] && !((s[j-1]>='a' && s[j-1]<='z') || (s[j-1]>='1' && s[j-1]<='9'))) {
                    int poc=j;
                    while (s[j]==rijec[l] && j<s.length()) {
                        l++;
                        j++;
                    }
                    if(l==rijec.length() && (!((s[j]>='a' && s[j]<='z') || (s[j]>='1' && s[j]<='9')) || j==s.length())) skup.insert(poc);
                }
            }
            //for(int x : skup) std::cout<<x<<" **";
            //std::cout<<std::endl;
            rez.insert(std::make_pair(rijec,skup));
        }
    }
    return rez;
}

int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> rjecnik;
    rjecnik=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(rjecnik);
    while (true) {
        std::string novi;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, novi);
        if(novi == ".") break;
        std::set<int> set;
        try { set = PretraziIndeksPojmova(novi,rjecnik);
        for(int x : set) std::cout<<x<<" ";
        }
        catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        }
        std::cout<<std::endl;
    }
	return 0;
}