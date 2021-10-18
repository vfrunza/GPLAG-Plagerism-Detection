#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <set>
#include <stdexcept>
#include <cstring>
#include <algorithm>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::set<std::tuple<std::string, int, int>> Pojam;

std::string PretvoriUMala(const std::string &rijec) {
    std::string nova(rijec);
    for (char &c : nova) c = tolower(c);
    return nova;
}

bool Ponavljanje(const std::map<std::string, Pojam> &m, const std::string &rijec) {
    for (auto it = m.begin(); it != m.end(); it++)
        if (PretvoriUMala(it->first) == PretvoriUMala(rijec)) return true;
    return false;
}

bool SlovoBroj(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return true;
    return false;
}

std::map<std::string, Pojam> KreirajIndeksPojmova(const Knjiga &k) {
    std::map<std::string, Pojam> pojmovi;
    for (auto poglavlje = k.begin(); poglavlje != k.end(); poglavlje++) {
        const std::vector<std::string> &v(poglavlje->second);
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                while (j < v[i].size() && !SlovoBroj(v[i][j])) j++;
                int pocetak(j);
                while (j < v[i].size() && SlovoBroj(v[i][j])) j++;
                std::string rijec(PretvoriUMala(v[i].substr(pocetak, j-pocetak)));
                pojmovi[rijec].insert(std::make_tuple(poglavlje->first, i+1, pocetak));
            }
        }
    }
    return pojmovi;
}

Pojam PretraziIndeksPojmova(const std::string &rijec, const std::map<std::string, Pojam> &m) {
    auto p(m.find(rijec));
    if (p == m.end()) throw std::logic_error("Pojam nije nadjen");
    return p->second;
}

void IspisiIndeksPojmova(const std::map<std::string, Pojam> &m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << PretvoriUMala(it->first) << ": ";
        int br(0);
        for (auto s = it->second.begin(); s != it->second.end(); s++) {
            std::cout << std::get<0>(*s) << "/" << std::get<1>(*s)
            << "/" << std::get<2>(*s);
            if (br++ < it->second.size()-1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}


int main ()
{
    try {
        Knjiga k;
        std::string poglavlje;
        for (;;) {
            std::cout << "Unesite naziv poglavlja: "; 
            std::string poglavlje;
            if (std::getline(std::cin, poglavlje), poglavlje == ".") break;
            std::vector<std::string> v;
            for (int i = 1;; i++) {
                std::cout << "Unesite sadrzaj stranice " << i << ": ";
                std::string stranica;
                if (std::getline(std::cin, stranica), stranica == ".") break;
                v.push_back(stranica);
            }
            k[poglavlje] = v;
        }
        auto pojmovi(KreirajIndeksPojmova(k));
        std::cout << std::endl << "Kreirani indeks pojmova:" << std::endl;
        IspisiIndeksPojmova(pojmovi);
        std::cout << std::endl;
        for (;;) {
            std::cout <<"Unesite rijec: ";
            std::string rijec;
            if (std::cin >> rijec, rijec == ".") break;
            Pojam p;
            try {
                p = PretraziIndeksPojmova(rijec, pojmovi);
            }
            catch (std::logic_error e) {
                std::cout << "Unesena rijec nije nadjena!";
            }
            for (auto it = p.begin(); it != p.end(); it++)
                std::cout << std::get<0>(*it) << "/" << std::get<1>(*it)
                << "/" << std::get<2>(*it) << " ";
            std::cout << std::endl;
        }
    }
    catch (std::logic_error e) {
        std::cout << e.what();
    }
    catch (...) {
        
    }
	return 0;
}
