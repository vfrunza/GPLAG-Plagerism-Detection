/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <set>
#include <string>
#include <cctype>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;

std::string toLower (std::string str) {
    for (auto &ch : str)
        ch = tolower(ch);
    return str;
}

void UbaciUIndeksPojmova (IndeksPojmova &pojmovi, std::string rijec, std::tuple<std::string, int, int> pozicija) {
    rijec = toLower(rijec);
    std::set<std::tuple<std::string, int, int>> pozicije;
    pozicije.insert(pozicija);
    std::pair<IndeksPojmova::iterator, bool> ret = pojmovi.insert({rijec, pozicije});
    if (ret.second == false)
        ret.first->second.insert(pozicija);
    return;
}

IndeksPojmova KreirajIndeksPojmova (Knjiga &knjiga) {
    IndeksPojmova pojmovi;
    for (Knjiga::iterator it = knjiga.begin() ; it != knjiga.end() ; it++) {
        std::string poglavlje = it->first;
        std::vector<std::string> stranice = it->second;
        for (int i = 0 ; i < stranice.size() ; i++) {
            for (int j = 0 ; j < stranice[i].length() ; j++) {
                int pocetak = j;
                int duzina = 0;
                while ((stranice[i][j] >= 'A' && stranice[i][j] <= 'Z') || (stranice[i][j]  >= 'a' && stranice[i][j] <= 'z') 
                       || (stranice[i][j] >= '0' && stranice[i][j] <= '9')) {
                           duzina++;
                           j++;
                }
                if (duzina > 0) {
                    std::string rijec = stranice[i].substr(pocetak, duzina);
                    std::tuple<std::string, int, int> pozicija { poglavlje, i + 1, pocetak };
                    UbaciUIndeksPojmova(pojmovi, rijec, pozicija);
                }
            }
        }
    }
    return pojmovi;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova (std::string pojam, IndeksPojmova pojmovi) {
    IndeksPojmova::iterator it = pojmovi.find(pojam);
    if (it == pojmovi.end())
        throw std::logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova (IndeksPojmova &pojmovi) {
    for (IndeksPojmova::iterator iti = pojmovi.begin() ; iti != pojmovi.end() ; iti++) {
        std::cout << iti->first << ": ";
        std::set<std::tuple<std::string, int, int>>::iterator posljednjaPozicija = iti->second.end();
        posljednjaPozicija--;
        for(std::set<std::tuple<std::string, int, int>>::iterator itj = iti->second.begin() ; itj != posljednjaPozicija ; itj++)
        std::cout << std::get<0>(*itj) << "/" << std::get<1>(*itj) << "/" << std::get<2>(*itj) << ", ";
        std::cout << std::get<0>(*posljednjaPozicija) << "/" << std::get<1>(*posljednjaPozicija) << "/" << std::get<2>(*posljednjaPozicija) << std::endl;
        
    }
}

void IspisiPozicije (std::set<std::tuple<std::string, int, int>> pozicije) {
    for (std::set<std::tuple<std::string, int, int>>::iterator it = pozicije.begin() ; it != pozicije.end() ; it++)
        std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << " ";
}


int main ()
{
    Knjiga knjiga;
    std::string poglavlje;
    std::cout << "Unesite naziv poglavlja: ";
    std::cin >> poglavlje;
    std::cin.ignore(10000, '\n');
    while (poglavlje != ".") {
        std::vector<std::string> stranice;
        std::string stranica;
        int i = 0;
        std::cout << "Unesite sadrzaj stranice " << i + 1 << ": ";
        std::getline(std::cin, stranica);
        i++;
        while (stranica != ".") {
            stranice.push_back(stranica);  
            std::cout << "Unesite sadrzaj stranice " << i + 1 << ": ";
            std::getline(std::cin, stranica);
            i++;
        }
        knjiga.insert({poglavlje, stranice});
        std::cout << "Unesite naziv poglavlja: ";
        std::cin >> poglavlje;
        std::cin.ignore(10000, '\n');
    }
    IndeksPojmova pojmovi = KreirajIndeksPojmova(knjiga);
    std::cout << std::endl << "Kreirani indeks pojmova: " << std::endl;
    IspisiIndeksPojmova(pojmovi);
    
    std::cout << std::endl << "Unesite rijec: ";
    std::string pojam;
    std::cin >> pojam;
    while (pojam != ".") {
        try {
            std::set<std::tuple<std::string, int, int>> pozicije = PretraziIndeksPojmova(pojam, pojmovi);
            IspisiPozicije(pozicije);
            std::cout << std::endl;
        } catch(std::logic_error e) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
        std::cout << "Unesite rijec: ";
        std::cin >> pojam;
        
    }
    
	return 0;
}
