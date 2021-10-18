/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stdexcept>

typedef std::map<std::string, std::set<int>> T_mapa;
bool SlovoCifra(char x) {
    return((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9'));
}

std::string U_mala(std::string s) {
    for(int i=0; i<s.length(); i++)
        if(s[i] >='A' && s[i]<='Z')
            s[i]+='a'-'A';
    return s;
}
T_mapa KreirajIndeksPojmova (std::string tekst) {
    T_mapa pojmovi;
    for(int i=0; i<tekst.length(); i++) {
        int j(i);
        if(SlovoCifra(tekst[j])){
        while(j<tekst.length() && SlovoCifra(tekst[j]))
            j++;
        bool pronadjeno(false);
        for(auto it(pojmovi.begin()); it != pojmovi.end(); it++) {
            if(U_mala(tekst.substr(i, j-i)) == it->first && j-i != 0) {
                pronadjeno = true;
                break;
            }
        }
        if(!pronadjeno) pojmovi.insert(std::make_pair(U_mala(tekst.substr(i, j-i)), std::set<int>{i}));
        if (pronadjeno) pojmovi[U_mala(tekst.substr(i, j-i))].insert(i);
        i=j-1;
    }
    }
    return pojmovi;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, T_mapa pojmovi) {
        for(auto it(pojmovi.begin()); it != pojmovi.end(); it++)
            if(it->first == U_mala(rijec))
                return it->second;
        throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(T_mapa pojmovi) {
    for(auto it(pojmovi.begin()); it != pojmovi.end(); it++) {
        std::cout<<it->first<<": ";
        auto it2(it->second.begin());
        while(it2 != it->second.end()) {
            std::cout<<*it2;
            if(++it2 != it->second.end())
                std::cout<<",";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    auto pojmovi (KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(pojmovi);
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        getline(std::cin, rijec);
        if(rijec == ".")
            break;
        try{
        auto sk(PretraziIndeksPojmova(rijec, pojmovi));
            for(auto x : sk) std::cout<<x<<" ";
        }catch(std::logic_error) {
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }
	return 0;
}