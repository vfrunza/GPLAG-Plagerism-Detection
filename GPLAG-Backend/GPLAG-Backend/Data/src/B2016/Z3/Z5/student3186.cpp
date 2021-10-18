/B2016/2017: Zadaća 3, Zadatak 5
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <new>

struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

unsigned int PrebrojiModifikovanoIme(const std::string &ime) {
    unsigned int brojac(0);
    for (int i=0; i<ime.length(); ++i)
        if ((ime[i] >= 'a' and ime[i] <= 'z') or (ime[i] >= 'A' and ime[i] <= 'Z') or (ime[i] >= '0' and ime[i] <= '9'))
            brojac++;   return brojac;
}

std::vector<std::multiset<std::string>> Razvrstavanje (const std::vector<std::string> &vektor_imena, const int &br_timova)
{
    if (br_timova<1 or br_timova>vektor_imena.size())   throw std::logic_error ("Razvrstavanje nemoguce");
    
    std::vector<int> size;
    for (int i=0; i<br_timova; ++i) size.push_back(vektor_imena.size()/br_timova);
    for (int i=0; i<(vektor_imena.size()%br_timova); ++i)   size[i]++;
    
    Dijete *pocetak(nullptr), *prethodni;
    for (int i=0; i<vektor_imena.size(); ++i) {
        Dijete *novi (new Dijete);
        novi->ime = vektor_imena[i]; novi->sljedeci = pocetak;
        if (not(pocetak)) pocetak = novi;
        else prethodni-> sljedeci = novi;
        prethodni = novi;
    }
    
    int vel (vektor_imena.size());
    std::vector<std::multiset<std::string>> razvrstana_lista;
    unsigned int clockworks (PrebrojiModifikovanoIme(pocetak->ime));
    for (int i=0; i<br_timova; ++i) {
        std::multiset<std::string> jedinstveni_tim;
        
        for (int x=0; x<size[i]; ++x) {
            clockworks = PrebrojiModifikovanoIme(pocetak->ime);
            jedinstveni_tim.insert(pocetak->ime);
            
            if (vel > 1) {      --vel;
                Dijete *preuzmi_pocetni (prethodni); preuzmi_pocetni = preuzmi_pocetni -> sljedeci -> sljedeci;
                delete pocetak; pocetak = nullptr; pocetak = preuzmi_pocetni; prethodni -> sljedeci = pocetak;
            
                for (int br_iteracija = 0; br_iteracija < clockworks-1; ++br_iteracija) {
                    pocetak = pocetak -> sljedeci;  prethodni = prethodni -> sljedeci;
                }
            }   else {  delete pocetak; pocetak = nullptr; }
        }   razvrstana_lista.push_back(jedinstveni_tim);
    }   return razvrstana_lista;
}

int main ()
{
    int broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.ignore (10000, '\n');
    
    std::vector<std::string> imena;
    std::cout << "Unesite imena djece: " << std::endl;
    for (int i=0; i<broj_djece; ++i) {
        std::string input;  std::getline (std::cin, input); imena.push_back(input);
    }   std::cout << "Unesite broj timova: ";   int br_timova;  std::cin >> br_timova;
    try {
        std::vector<std::multiset<std::string>> lista_timova {Razvrstavanje(imena, br_timova)};
        for (int i=0; i<lista_timova.size(); ++i) { std::cout << "Tim " << i+1 << ": ";
            for (auto it = lista_timova[i].begin(); it != lista_timova[i].end(); ++it) {
                std::cout << *it; if (it != --lista_timova[i].end()) std::cout << ", ";
            }   std::cout << std::endl;
        }
    }   catch (std::logic_error txt) {
        std::cout << "Izuzetak: " << txt.what() << std::endl;
    }   return 0;
}