#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <stdexcept>

std::string tolower_za_string (std::string s) {
    std::string pomocni(s);
    for (int i=0; i<s.length(); i++) {
        if (pomocni[i] != ' ') {
            if (pomocni[i] >= 'A' && pomocni[i] <= 'Z')
                pomocni[i] +=  32;
        }
    }
    return pomocni;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s) {
    std::map<std::string, std::set<int>> mapa;
    s = tolower_za_string(s);
    std::string prazni, pom;
    int brojac(0);
    bool uslov(true);
    for (int i=0; i<s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            pom += s[i];
            brojac ++;
            uslov = false;
        }
        if ((!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) && uslov == false) ||  ((i == s.length() - 1) && uslov == false)) {
            uslov = true;
            if (i == s.length() - 1) i++;
            mapa[pom].insert (std::abs(i - brojac));
            brojac = 0;
            pom = prazni;
        }
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> mapa) {
    std::set<int> povratni;
    s = tolower_za_string(s);
    auto it1 = mapa.find(s);
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        if (it1 == mapa.end()) throw std::logic_error ("Pojam nije nadjen");
        else {
            for (auto it2=it1->second.begin(); it2!=it1->second.end(); it2++)
            povratni.insert(*it2);
        }
    }
    return povratni;
}
void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout << it->first <<  ": ";
        int brojac(0);
        for (auto it1=it->second.begin(); it1!=it->second.end(); it1++) {
            brojac++;
            if (brojac == it->second.size()) std::cout << *it1;
            else std::cout << *it1 << ",";
        }
        std::cout << std::endl;
    }
}
int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline (std::cin, s);
    s = tolower_za_string(s);
    auto kreirano = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(kreirano);
    for(;;) {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline (std::cin, rijec);
        rijec = tolower_za_string(rijec);
        if (rijec == ".") break;
        try {
            auto indeks = PretraziIndeksPojmova(rijec, kreirano);
            for (auto it=indeks.begin(); it!=indeks.end(); it++)    
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        catch (std::logic_error poruka) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}