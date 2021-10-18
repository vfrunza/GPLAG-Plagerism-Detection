/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tuple>

#include <utility>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Indeks;

bool Slovo (char znak) {
    return ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9'));
}

void PretvoriUMala (std::string &s) {
    for (int i=0; i<s.length(); i++) {
        if (s.at(i)>='A' && s.at(i)<='Z') s.at(i)=s.at(i)+'a'-'A';
    }
    return;
}

Indeks KreirajIndeksPojmova (Knjiga k) {
    Indeks indeks;
    
    for (auto par: k) {
        for (int m=0; m<par.second.size(); m++) {
            std::string tekst;
            tekst=par.second.at(m);
            
            
            for (int b=0; b<tekst.length(); b++) {
                std::string rijec;
                std::set<std::tuple<std::string, int, int>> skup;
                
                while (b<tekst.length()) { if (Slovo(tekst.at(b))) break; b++; }
                if (b==tekst.length()) continue;
                
                while (b<tekst.length()) { if (!Slovo(tekst.at(b))) break; rijec.push_back(tekst.at(b)); b++; }
                b--;
                
                PretvoriUMala(rijec);
                if (rijec.length() && indeks.find(rijec)==indeks.end()) {
                
                    for (auto it=k.begin(); it!=k.end(); it++) {
                        for (int i=0; i<it->second.size(); i++) {
                            std::string s;
                            s=(it->second).at(i);
                                
                            bool razmak(true);
                            for (int k=0; k<s.length(); k++) {
                                if (!Slovo(s.at(k))) razmak=true;
                                else if (razmak) {
                                    std::string str(s.substr(k, rijec.length()));
                                    PretvoriUMala(str);
                                        
                                    if (str==rijec) {
                                        if (k+rijec.length()==s.length()) { skup.insert(std::make_tuple(it->first, i+1, k)); }  
                                        else if (!Slovo(s.at(k+rijec.length()))) { skup.insert(std::make_tuple(it->first, i+1, k)); }
                                    }
                                    razmak=false;
                                }
                            }
                        }
                    }
                    indeks.insert({rijec, skup});
                }
            }
        }
    }
    return indeks;
}

void IzbaciRazmake (std::string &s) {
    
    std::string pomocni;
    
    for (int i=0; i<s.length(); i++) {
        
        while (!Slovo(s.at(i))) { 
            i++; 
            if (i==s.length()) {
                s=pomocni; 
                return;
            }
        }
        while (i!=s.length()) {
            pomocni.push_back(s.at(i));
            i++;
        }
    }
    int vel(pomocni.length());
    do {
        std::string::iterator it(pomocni.end()-1);
        if (Slovo(*it)) { s=pomocni; return; }
        pomocni.resize(vel-1);
        vel--;
    } while (vel);
    s=pomocni;
    return;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova (std::string s, Indeks indeks) {
    PretvoriUMala(s);
    IzbaciRazmake(s);
    if (indeks.find(s)==indeks.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    auto it(indeks.find(s));
    
    return it->second;
}

void IspisiTrojku(std::tuple<std::string, int, int> x) {
    std::cout << std::get<0>(x) << "/" << std::get<1>(x) << "/" << std::get<2>(x);
}

void IspisiIndeksPojmova (Indeks indeks) {
    
    for (auto it=indeks.begin(); it!=indeks.end(); it++) {
        std::cout << it->first << ": ";
        int br_elemenata(1);
        for (auto trojka: it->second) {
            IspisiTrojku(trojka);
            if (br_elemenata!=it->second.size()) std::cout << ", ";
            br_elemenata++;
        }
        std::cout << std::endl;
    }
    return;
}

int main ()
{
    Knjiga k;
    std::string poglavlje, tekst, s;
    std::vector<std::string> v;
    
    for (;;) {
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, poglavlje);
        if (poglavlje==".") break;
        
        int i(1);
        v.resize(0);
        for (;;) {
            std::cout << "Unesite sadrzaj stranice " << i++ << ": ";
            std::getline(std::cin, tekst);
            if (tekst==".") break;
            v.push_back(tekst);
        }
        k.insert({poglavlje, v});
    }
    
    auto indeks(KreirajIndeksPojmova(k));
    std::cout << std::endl << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(indeks);
    
    for (;;) {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, s);
        
        if (s==".") break;
        
        try {
            auto skup(PretraziIndeksPojmova(s, indeks));
            
            for (auto trojka: skup) {
                IspisiTrojku(trojka);
                std::cout << " ";
            }
        }
        catch(std::logic_error &izuzetak) {
            std::cout << izuzetak.what();
        }
        std::cout << std::endl;
    }
    
	return 0;
}
