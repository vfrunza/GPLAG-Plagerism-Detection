/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <stdexcept>

std::string PretvoriUMalaSlova(std::string s) {
    int duzina=s.size();
    s.c_str();
    for (int i=0; i<duzina+1; i++)
        s[i]=std::tolower(s[i]);
    return std::string(s);
}

bool SlovoIliBroj(char znak) {
    if ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9')) return true;
    return false;
}

void IzbaciPonavljanja(std::vector<std::string> &s) {
    for (int i=0; i<s.size(); i++)
        for (int j=i+1; j<s.size(); j++)
            if (s[i]==s[j]) {
                s.erase(s.begin()+j);
                j--;
            }
}

std::vector<std::string> IzdvojiRijeci(std::string s) {
    std::vector<std::string> v;
    for (int i=0; i<s.size(); i++) {
        int duzina(0);
        if (SlovoIliBroj(char(s[i]))) {
            int pocetak=i;
            while (SlovoIliBroj(char (s[i])) && i<s.size()) {
                duzina++;
                i++;
            }
            v.push_back(s.substr(pocetak,duzina));
        }
    }
    IzbaciPonavljanja(v);
    return v;
}

std::vector<std::set<int>> IzdvojiPonavljanja(std::string s, std::vector<std::string> vs) {
    std::vector<std::set<int>> rez(vs.size());
    for (int i=0; i<vs.size(); i++) {
        for (int j=0; j<s.size(); j++) {
            int duzina(0);
            if (SlovoIliBroj(char(s[j]))) {
                int pocetak=j;
                while(SlovoIliBroj(char(s[j])) && j<s.size()) {
                    duzina++;
                    j++;
                }
                if (vs[i]==s.substr(pocetak,duzina)) rez[i].insert(pocetak);
            }
        }
    }
    return rez;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s) {
    auto v1=IzdvojiRijeci(s);
    auto v2=IzdvojiPonavljanja(s,v1);
    std::map<std::string,std::set<int>> mapa;
    for (int i=0; i<v1.size(); i++) {
        v1[i]=PretvoriUMalaSlova(v1[i]);
        mapa.insert(std::make_pair(v1[i],v2[i]));
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>> indeks_pojmova) {
    auto it(indeks_pojmova.find(PretvoriUMalaSlova(rijec)));
    if (it==indeks_pojmova.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(const std::map<std::string, std::set<int>> &indeks_pojmova) {
    for (auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++) {
        std::cout << it->first << ": ";
        int broj_elemenata_skupa=std::distance(it->second.begin(), it->second.end()), brojac(0);
        for (auto x:it->second) {
            if (brojac!=broj_elemenata_skupa-1) std::cout << x << ",";
            else std::cout << x << std::endl;
            brojac++;
        }
    }
}

int main () {
    std::string string;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, string);
    auto m=KreirajIndeksPojmova(string);
    IspisiIndeksPojmova(m);
    std::string unos;
    do {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, unos);
        if (unos==".") return 0;
        std::set<int> s;
        try{
            s=PretraziIndeksPojmova(unos, m);
        }
        catch(std::logic_error izuzetak) {
            std::cout << "Unesena rijec nije nadjena!";
        } 
        for (auto x:s) std::cout << x << " ";
        std::cout << std::endl;
    } while(1);
	return 0;
}