/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stdexcept>

char toUpper(char c)
{
    if(c>='a' && c<='z') return c-('a' - 'A');
    return c;
}

int isSiliC(char c)
{
    if(c>='1' && c<='9') return true;
    c = toUpper(c);
    return c>='A' && c<='Z';
}

bool JesuliIsti(const std::string &a, const std::string &b)
{
    if(a.size() != b.size()) return false;
    for(int i=0; i < a.size(); i++) {
        if(toUpper(a[i]) != toUpper(b[i])) return false;
    }
    return true;
}

bool ImaluMapone(const std::map<std::string, std::set<int>> &mapa, const std::string &naziv)
{
    auto it(mapa.find(naziv));
    if(it == mapa.end()) return true;
    else return false;
}

void PuMala(std::string &s){
    for(int i=0; i < s.size(); i++){
        if(s[i]>='A' && s[i]<='Z') s[i] += 'a'-'A';
    }
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(const std::string &a)
{
    std::string s;
    s = a;
    PuMala(s);
    std::map<std::string, std::set<int>> zaVratit;

    for(unsigned int i=0; i < s.size(); i++) {
        std::set<int> novi;
        while(!isSiliC(s[i])) i++;
        unsigned int pocetak(i);
        while(isSiliC(s[i])) i++;
        std::string pomocni = s.substr(pocetak, i-pocetak);
        novi.insert(pocetak+0);

        for(auto j = i; j < s.size(); j++) {
            if(isSiliC(s[j])) {
                unsigned int pocetak2 = j;
                while(isSiliC(s[j])) j++;
                std::string pomocni2 = s.substr(pocetak2, j-pocetak2);
                if(JesuliIsti(pomocni, pomocni2)) {
                    novi.insert(pocetak2+0);
                }
            }
        }
        if(ImaluMapone(zaVratit, pomocni)) zaVratit.insert(std::make_pair(pomocni, novi));
    }
    return zaVratit;
}

std::set<int> PretraziIndeksPojmova(const std::string &s, const std::map<std::string, std::set<int>> &haloba)
{
    std::string a;
    a = s;
    PuMala(a);
    auto it(haloba.find(a));
    if(it == haloba.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(const std::map<std::string, std::set<int>> &haloba)
{
    auto it(haloba.begin());
    while(it != haloba.end()) {
        auto max = *std::max_element((it->second).begin(), (it->second).end());
        std::cout << it->first << ": ";
        for(auto x : it->second) {
            if( x == max) std::cout << x;
            else std::cout << x << ",";
        }
        std::cout << std::endl;
        it++;
    }
}

int main ()
{
    std::string str;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, str);
    auto z = KreirajIndeksPojmova(str);
    IspisiIndeksPojmova(z);
    std::string rijec;
    do {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec == ".") return 0;
        try {
            std::set<int> novi(PretraziIndeksPojmova(rijec, z));
            for(auto x : novi) std::cout << x << " ";
            std::cout << std::endl;
        } catch(std::logic_error exec) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    } while(rijec != ".");  
    return 0;
}