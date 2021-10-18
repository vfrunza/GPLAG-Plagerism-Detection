/B2016/2017: Zadaća 3, Zadatak 2
#include <stdexcept>
#include <iostream>
#include <string>
#include <map>
#include <set>

bool SlovoIliBroj (const char &slovo) {
    if ((slovo >= 'a' and slovo <= 'z') or (slovo >= 'A' and slovo <= 'Z') or (slovo >= '0' and slovo <= '9'))
        return true; else return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (const std::string &recenica)
{
    std::map<std::string, std::set<int>> mapa;
    for (int i=0; i<recenica.length(); ++i) {
        if (i<recenica.length() and SlovoIliBroj(recenica[i])) {
            std::string rijec; int pocetni_index_rijeci(i);
            while (i < recenica.length() and SlovoIliBroj(recenica[i]))
                if (not(recenica[i] >= 'A' and recenica[i] <= 'Z') or (recenica[i] >= 'a' and recenica[i] <= 'z'))  
                    rijec += recenica[i++]; else rijec += recenica[i++] + 'z'-'Z';
                        mapa[rijec].insert(pocetni_index_rijeci);
        }
    }   return mapa;
}

void IspisiIndeksPojmova (const std::map<std::string, std::set<int>> &mapa) {
    for (auto it = mapa.begin(); it != mapa.end(); ++it) {
        std::cout << it->first << ": ";
        for (auto x = it->second.begin(); x != it->second.end(); ++x) {
            std::cout << *x; if (x != --it->second.end()) std::cout << ",";
        }   std::cout << std::endl;
    }
}

std::set<int> PretraziIndeksPojmova (const std::string &recenica, const std::map<std::string, std::set<int>> &maps) {
    std::set<int> povratni_set;  auto it (maps.find(recenica));
    if (it == maps.end()) throw std::logic_error ("Pojam nije nadjen");
    else for (const auto &x : it->second) povratni_set.insert(x); return povratni_set;
}

int main ()
{
    std::string input;
    std::cout << "Unesite tekst: ";
    std::getline (std::cin, input);
    IspisiIndeksPojmova(KreirajIndeksPojmova(input));
    for (;;) {
        std::cout << "Unesite rijec: ";
        std::string input_;
        std::getline (std::cin, input_);
        if (input_ == ".")   break;
        try {   std::set<int> trazeni_set {PretraziIndeksPojmova (input_, KreirajIndeksPojmova(input))};
                for (auto it = trazeni_set.begin(); it != trazeni_set.end(); ++it)
                    std::cout << *it << " ";    std::cout << std::endl;
        }   catch (std::logic_error) {  std::cout << "Unesena rijec nije nadjena!" << std::endl;   }
    }   return 0;
}