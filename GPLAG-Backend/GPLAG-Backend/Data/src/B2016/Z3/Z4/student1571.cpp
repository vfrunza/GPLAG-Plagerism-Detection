#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <utility>
#include <set>

void ispisi_vek_set (std::vector<std::set<std::string>> v_s) {
    int i(1);
    for (auto const &a : v_s) {
       std::cout << "Tim " << i << ": ";
       i++;
       int brojac(0);
        for (auto b : a) {
            brojac++;
            if (brojac == a.size())  std::cout << b;
            else std::cout << b << ", ";
        }
        std::cout << std::endl;
    }
}
double mod (double n, double k) {
    return std::fmod(n, k);
}
int cijeli_dio (double n, double k) {
    return (n / k);
}
int duzina_koraka (std::string s) {
    int duzina(0);
    for (int i=0; i<s.length(); i++) {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <='z'))
            duzina++;
    }
    return duzina;
}
std::list<std::string> kopiraj_u_listu (std::vector<std::string> vek) {
    std::list<std::string> kopija;
    for (auto it=vek.begin(); it!=vek.end(); it++) 
        kopija.push_back (*it);
    return kopija;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n) {
    if (n < 1 || n > v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::list<std::string> kopija_vektora(kopiraj_u_listu(v));
    std::vector<std::set<std::string>> glavna;
    auto iterator_kroz_djecu (kopija_vektora.begin());
    int m(v.size());
    int modulo(mod(m, n)), cijeli(cijeli_dio(m, n));
    int prvi(cijeli+1);
    
    for (int i=0; i<n; i++) {
        int djeca_trenutni;
        if (i+1 <= modulo) djeca_trenutni = prvi;
        else  djeca_trenutni = cijeli;
        std::set<std::string> tim_pomocni;
        for (int j=0; j<djeca_trenutni; j++) {
            tim_pomocni.insert(*iterator_kroz_djecu);
            int br_slova(duzina_koraka(*iterator_kroz_djecu));
            auto pom_iterator(iterator_kroz_djecu);
            pom_iterator++;
            if (pom_iterator == kopija_vektora.end()) {
                kopija_vektora.erase(iterator_kroz_djecu);
                iterator_kroz_djecu = kopija_vektora.begin();
            }
            else  iterator_kroz_djecu = kopija_vektora.erase(iterator_kroz_djecu);
            if (kopija_vektora.size() == 0) break;
            int k(0);
            while (k != br_slova - 1) {
                iterator_kroz_djecu++;
                if (iterator_kroz_djecu == kopija_vektora.end()) 
                    iterator_kroz_djecu = kopija_vektora.begin();
                k++;
            }
        }
        glavna.push_back(tim_pomocni);
    }
    return glavna;
}
int main() {
    std::cout << "Unesite broj djece: ";
    int br;
    std::cin >> br;
    try {
        std::cout << "Unesite imena djece: " << std::endl;
        std::cin.ignore(10000,'\n');
        std::vector<std::string> vek;
        for (int i=0; i<br; i++) {
            std::string ime;
            std::getline(std::cin, ime);
            vek.push_back(ime);
        }
        std::cout << "Unesite broj timova: ";
        int timovi;
        std::cin >> timovi;
        std::vector<std::set<std::string>> lista(Razvrstavanje(vek, timovi));
        ispisi_vek_set(lista);
    }
    catch (std::logic_error poruka) {
        std::cout << "Izuzetak: " << poruka.what();
    }
    return 0;
}