/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stdexcept>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cctype>

int duzina (int pocetak, std::string tekst) {
    int rezultat(0);
    for (int i=pocetak; i<tekst.length(); i++) {
        if(isalnum(tekst[i])) {
            rezultat++;
        }
        else break;
    }
    return rezultat;
}

std::string podstring (int pocetak, int kraj, std::string tekst) {
    std::string rezultat = "";
    for (int i=pocetak; i<tekst.length(); i++){
        if(isalnum(tekst[i])) {
            rezultat=rezultat+tekst[i];
        }
        else break;
    }
    return rezultat;
}

bool uListi(std::vector<std::string> lista, std::string element) {
    
    for (int i = 0; i < lista.size(); i++) {
        if (element == lista[i])
            return true;
    }
    return false;
}


std::vector<std::string> IzdvojiRijeci(std::string tekst) {
    std::vector <std::string> rijeci;
    
    int start {0};
    bool status = false;

    
    for (int i=0; i < tekst.length(); i++) {
        if (!isalnum(tekst[i]) && !status) {
            std::string rijec = tekst.substr(start, i-start);
            rijeci.push_back(rijec);
        }
        
        if (isalnum(tekst[i])) {
            status = false;
            if (i==tekst.length() - 1) {
                std::string rijec = tekst.substr(start, (i + 1) - start);
                rijeci.push_back(rijec);
            }
            continue;
        }
        
        start = i + 1;
        status = true;
        
        
    }
    return rijeci;
}

std::vector<std::string> UkloniDuplikate(std::vector<std::string> rijeci) {
    
    std::vector<std::string> rezultat;
    for (int i = 0; i < rijeci.size(); i++) {
        if (!uListi(rezultat, rijeci[i]))
            rezultat.push_back(rijeci[i]);
    }
    
    return rezultat;
}

std::set <int> DajIndeks(std::string tekst, std::string pojam) {
    
    std::set <int> pozicije;
    int p = tekst.find(pojam, 0);
    
    while (p != std::string::npos) {
        if (pojam.length()==1) {
            if(p>0 && !isalnum(tekst[p+1]) && !isalnum(tekst[p-1])) {
                pozicije.insert(p);
            }
        }
        if(pojam.length()>1) {
            int d=duzina(p,tekst);
            std::string potencijalnarijec=podstring(p,d,tekst);
            if(potencijalnarijec==pojam){
            pozicije.insert(p);
            }
        }
        p = tekst.find(pojam, p+1);
    }
    return pozicije;
}


std::set <int> PretraziIndeksPojmova(std::string rijec, std::map <std::string, std::set<int>> pojmovi) {
    
    for (auto it = pojmovi.begin(); it != pojmovi.end(); it++) {
        if (rijec == it -> first) {
            return it -> second;
        }
    }
    
    throw std::logic_error("Pojam nije nadjen");
}

std::map <std::string, std::set <int>> KreirajIndeksPojmova(std::string tekst) {
    std::transform (tekst.begin(), tekst.end(), tekst.begin(), tolower);
    std::vector <std::string> rijeci = IzdvojiRijeci(tekst);
    
    std::vector<std::string> r = UkloniDuplikate(rijeci);
    
    std::map <std::string, std::set <int>> rezultat;
    
    for (int i = 0; i < r.size(); i++) {
        std::set<int> indeksi = DajIndeks(tekst, r[i]);
        rezultat[r[i]] = indeksi;
    }
    
    return rezultat;
}

void IspisiIndeksPojmova(std::map <std::string, std::set <int>> rijeci) {
    
    //std::cout << std::endl;
    
    for (const auto& par : rijeci) {
        std::cout << par.first << ": ";
        for (auto iter = par.second.begin(); iter != par.second.end(); iter++) {
            if (*iter == *par.second.rbegin())
                std::cout << *iter;
            else std::cout << *iter << ",";
                    
        }
        std::cout << "\n";
    }
    
}

bool Pronadji(std::string pojam, std::map <std::string, std::set <int>> pojmovi) {
    for (auto it = pojmovi.begin(); it != pojmovi.end(); it++) {
        if (pojam == it -> first)
            return true;
    }
    return false;
}


void IspisiIndeks(std::set <int> indeksi) {
    
    for (auto iter = indeksi.begin(); iter != indeksi.end(); iter++) {
        if (*iter == *indeksi.rbegin()) 
            std::cout << *iter << std::endl;
        else std::cout << *iter << ",";
    }
}


int main() {
    std::string tekst;
    std::string unos;
    std::set <int> indeksi;
    
    std::cout << "Unesite tekst: ";
    std::getline (std::cin, tekst);
    std::transform(tekst.begin(), tekst.end(), tekst.begin(), tolower);
    
    
    std::map <std::string, std::set <int>> rijeci = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(rijeci);
    
    
    while (true) {
        std::cout << "Unesite rijec: ";
        std::getline (std::cin, unos);
        std::transform(unos.begin(), unos.end(), unos.begin(), tolower);
        
        if (unos == ".") break;
        if (!Pronadji(unos, rijeci))
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        else {
            indeksi = PretraziIndeksPojmova(unos, rijeci);
            for (auto a: indeksi) 
                std::cout << a << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
