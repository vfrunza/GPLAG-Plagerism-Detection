#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>

struct Dijete {
    std::string ime;
    Dijete *sljedeci = nullptr;
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
//NE RADI CURENJE MEMORIJE HEJT -_- 
Dijete *kreiraj_dijete (std::string Ime) {
    Dijete *novo_dijete;
    try {
        novo_dijete = new Dijete;
        novo_dijete->ime = Ime;
        novo_dijete->sljedeci = nullptr;
    }
    catch (...) {
        if (!novo_dijete) throw;
        auto pom_di (novo_dijete->sljedeci);
        while (pom_di != novo_dijete) {
            Dijete *neko = pom_di->sljedeci;
            delete pom_di;
            pom_di = neko;
        }
        delete pom_di;
        novo_dijete = nullptr;
        throw;
    }
    return novo_dijete;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n) {
    if (n < 1 || n > v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    Dijete *pocetak (kreiraj_dijete(v.at(0))), *kraj = nullptr, *iterator(pocetak);
    for (int i=1; i<v.size(); i++) {
        iterator->sljedeci = kreiraj_dijete(v.at(i));
        iterator = iterator->sljedeci; 
    }
    kraj = iterator;
    kraj->sljedeci = pocetak;
    std::vector<std::set<std::string>> glavna;
    std::vector<std::string> pomocni_vek(v);
   // auto iterator_kroz_djecu (kopija_vektora.begin());
    int broj_djece(v.size()), kopija_broja(broj_djece);
    iterator = pocetak;
    int modulo(mod(broj_djece, n)), cijeli(cijeli_dio(broj_djece, n));
    int prvi(cijeli+1);
    
    for (int i=0; i<n; i++) {
        int djeca_trenutni;
        if (i+1 <= modulo) djeca_trenutni = prvi;
        else  djeca_trenutni = cijeli;
        std::set<std::string> tim_pomocni;
        for (int j=0; j<djeca_trenutni; j++) {
            tim_pomocni.insert(iterator->ime);
            int br_slova(duzina_koraka(iterator->ime));
            Dijete *pom_iterator (pocetak);
            while (pom_iterator->sljedeci != iterator) pom_iterator = pom_iterator->sljedeci;
            pom_iterator->sljedeci = iterator->sljedeci;
            if (iterator == pocetak) pocetak = iterator->sljedeci;
            delete iterator;
            pomocni_vek.resize(pomocni_vek.size()-1);
            if (pomocni_vek.size() !=0 ) iterator = pom_iterator->sljedeci; //WHY YOU NO WORK mem greska
            kopija_broja--;
            if (!kopija_broja) break;
            int k(0);
            while (k != br_slova - 1) {
                iterator = iterator->sljedeci;
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
        std::cin.ignore(1000,'\n');
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
        //std::cout << "Alokacija nije uspjela";
        return 0;
    }
    return 0;
}