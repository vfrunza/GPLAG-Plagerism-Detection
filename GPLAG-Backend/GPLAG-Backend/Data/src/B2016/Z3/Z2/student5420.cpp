/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (const std::string &s) {
    std::map<std::string, std::set<int>> mapa;
    int p(0);
    for (int i=0; i<s.length(); i++) {
        if (tolower(s[i])>='a' && tolower(s[i])<='z' || s[i]>=0 && s[i]<10) {
            p=i;
            int t(p);
            while (tolower(s[i])>='a' && tolower(s[i])<='z' || s[i]>=0 && s[i]<10) t++;
        }
        int k=t;
        std::string s1(s.substr(p, k-p));
        int poc(0);
        
        
        for (int i=0; i<s.length(); i++) {
            if (tolower(s[i])>='a' && tolower(s[i])<='z' || s[i]>=0 && s[i]<10) {
                poc=i;
                int pom(poc);
                while (tolower(s[i])>='a' && tolower(s[i])<='z' || s[i]>=0 && s[i]<10) pom++;
            }
            int kraj=pom;
            if (s1==s.substr(poc, kraj-poc)) skup.insert(poc);
            i=pom;
        }
        
        
        for (int i=0; i<s1.length(); i++) {
            if (s1[i]>='A' && s1[i]<='Z') s1[i]=tolower(s1[i]);
        }
        mapa[s1]=skup;
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (const std::string &s, const std::map<std::string, std::set<int>> &mapa) {
    
}

void IspisiIndeksPojmova (const std::map<std::string, std::set<int>> &mapa) {
    
}

int main ()
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst));
    
    std::string rijec;
    std::cout << "Unesite rijec: ";
    std::getline(std::cin, rijec);
	return 0;
}