#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include <utility>
#include <set>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
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
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            duzina++;
    }
    return duzina;
}
//NE RADI CURENJE MEMORIJE 
std::shared_ptr<Dijete> kreiraj_dijete (std::string Ime) {
    std::shared_ptr<Dijete> novo_dijete(new Dijete); //OPET CURENJE NEGDJE OVO NASTAJE WHY?????? HEJT 
    novo_dijete->ime = Ime;
    novo_dijete->sljedeci = nullptr;
    return novo_dijete;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n) {
    if (n < 1 || n > v.size()) throw std::logic_error ("Razvrstavanje nemoguce");

    std::shared_ptr<Dijete> pocetak(kreiraj_dijete(v[0])), kraj = nullptr, iterator(pocetak);
    for (int i=1; i<v.size(); i++) {
        iterator->sljedeci = kreiraj_dijete(v[i]);
        iterator = iterator->sljedeci; 
    }
    kraj = iterator;
    kraj->sljedeci = pocetak;
    std::vector<std::set<std::string>> glavna;
    int broj_djece(v.size()), kopija_broja(broj_djece);
    iterator = pocetak;
    int modulo(mod(broj_djece, n)), cijeli(cijeli_dio(broj_djece, n));
    int prvi(cijeli+1);
    std::vector<std::string> pomocni_vek(v);
    for (int i=0; i<n; i++) {
        int djeca_trenutni;
        if (i+1 <= modulo) djeca_trenutni = prvi;
        else  djeca_trenutni = cijeli;
        std::set<std::string> tim_pomocni;
        for (int j=0; j<djeca_trenutni; j++) {
            tim_pomocni.insert(iterator->ime);
            int br_slova(duzina_koraka(iterator->ime));
            std::shared_ptr<Dijete> pom_iterator (pocetak);
            while (pom_iterator->sljedeci != iterator) pom_iterator = pom_iterator->sljedeci;
            pom_iterator->sljedeci = iterator->sljedeci;
            if (iterator == pocetak) pocetak = iterator->sljedeci;
            iterator = pom_iterator->sljedeci; //WHY YOU NO WORK
            kopija_broja--;
            pomocni_vek.resize(pomocni_vek.size()-1);
            if (!kopija_broja) break;
            int k(0);
            while (k != br_slova - 1) {
                iterator = iterator->sljedeci;
                k++;
            }
        }
        if (pomocni_vek.size() == 0) iterator->sljedeci = nullptr;
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
    catch (std::bad_alloc) {
       // std::cout << "Memorija";
        return 0;
    }
    return 0;
}