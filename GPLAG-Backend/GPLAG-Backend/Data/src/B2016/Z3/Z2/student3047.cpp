/B2016/2017: Zadaća 3, Zadatak 2
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>

bool jel_znak(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'); 
}

std::string u_mala(std::string s)
{
    for(auto& c : s)
        c = std::tolower(c);
    return s;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(const std::string &recenica)
{
    std::map<std::string, std::set<int>> indeks_pojmova;
    for(int i = 0; i < int(recenica.size()); ++i){
        bool razmak = true;
        if(!jel_znak(recenica[i]))
            razmak = true;
        else if(razmak){
            razmak = false;
            int pocetak = i;
            while(jel_znak(recenica[i]) &&  i < int(recenica.size()))
                ++i;
            auto rijec = std::string(&recenica[pocetak], &recenica[i]);
            auto it = indeks_pojmova.find(u_mala(rijec));
            if(it != indeks_pojmova.end())
                it->second.insert(pocetak);
            else
                indeks_pojmova[u_mala(rijec)] = std::set<int>{pocetak};
        }
    }
    return indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova(const std::string &s, const std::map<std::string, std::set<int>>& ip)
{
    auto it = ip.find(s);
    if(it != ip.end())
        return it->second;
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(const std::map<std::string, std::set<int>>& ip)
{
    auto ispisi_set = [](const std::set<int>& s){
        auto it = s.begin();
        for(int i = 0; i < int(s.size()) - 1; ++i, ++it)
            std::cout << *it << ',';
        std::cout << *it << "\n";
    };
    for(const auto& elem : ip){
        std::cout << elem.first << ": ";
        ispisi_set(elem.second);
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    auto ip = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(ip);
    for(;;){
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec == ".")
            break;
        try {
            auto p = PretraziIndeksPojmova(rijec, ip);
            for(const auto &elem : p)
                std::cout << elem << ' ';
            std::cout << "\n";
        }
        catch (std::logic_error e) {
            std::cout << "Unesena rijec nije nadjena!\n";
        }
        
    }
	return 0;
}