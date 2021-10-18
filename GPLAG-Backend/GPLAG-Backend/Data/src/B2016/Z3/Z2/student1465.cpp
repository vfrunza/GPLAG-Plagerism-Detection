/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <utility>

//funckija koja pretvara sva slova u mala
void u_mala(std::string &rijec)
{
    for(int i{0}; i < rijec.length(); i++) 
    {
        if(rijec[i] >= 'A' && rijec[i] <= 'Z') 
            rijec[i] += 'a' - 'A';
    }
}

//Funkcija Kreiraj_indeks_pojmova
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> indeks_pojmova;
    std::set<int> pomocni_set{};
    bool pocela_rijec = true;
    int indeks_pocetka = 0;
    int indeks_kraja;
    for(int i{0}; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            if(!pocela_rijec)
            {
                indeks_pocetka = i;
                pocela_rijec = true;
            }
        }
        else
        {
            if(pocela_rijec)
            {
                indeks_kraja = i;
                if (indeks_kraja != indeks_pocetka)
                {
                    std::string rijec = s.substr(indeks_pocetka, indeks_kraja - indeks_pocetka);
                    u_mala(rijec);
                    if(!indeks_pojmova.count(rijec)) 
                    {
                        indeks_pojmova.insert(make_pair(rijec, pomocni_set));
                        indeks_pojmova[rijec].insert(indeks_pocetka);
                    }
                    else {
                        indeks_pojmova[rijec].insert(indeks_pocetka);
                    }
                }
                pocela_rijec = false;
            }
        }
    }
    if(pocela_rijec) {
        indeks_kraja = s.length();
        if(indeks_kraja != indeks_pocetka) 
        {
            std::string rijec = s.substr(indeks_pocetka, indeks_kraja - indeks_pocetka);
            u_mala(rijec);
            if(!indeks_pojmova.count(rijec)) {
                indeks_pojmova.insert(make_pair(rijec, pomocni_set));
                indeks_pojmova[rijec].insert(indeks_pocetka);
            }
            else {
                indeks_pojmova[rijec].insert(indeks_pocetka);
            }
        }
        pocela_rijec = false;
    }
    return indeks_pojmova;
}
    
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indeks_pojmova) {
    if(!indeks_pojmova.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    return indeks_pojmova[rijec];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indeks_pojmova) {
    for(auto x: indeks_pojmova) {
        std::cout << x.first << ": ";
        auto it_kraja = x.second.end();
        it_kraja--;
        for(auto it=x.second.begin(); it != it_kraja; it++) {
            std::cout << *it << ",";
        }
        std::cout << *it_kraja << std::endl;
    }
}
int main ()
{
    std::cout << "Unesite tekst: ";
    std::string tekst;
    getline(std::cin, tekst);
    auto indeks_pojmova = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(indeks_pojmova);
    std::string rijec = "";
    while(rijec != ".") {
        std::cout << "Unesite rijec: ";
        std::cin >> rijec;
        if(rijec == ".") break;
        try {
            auto pozicije = PretraziIndeksPojmova(rijec, indeks_pojmova);
            for(auto x: pozicije) {
                std::cout << x << " "; 
            }
            std::cout << std::endl;
        }
        catch(std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
        
    }
	return 0;
}