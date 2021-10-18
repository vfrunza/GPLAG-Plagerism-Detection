/B2016/2017: Zadaća 3, Zadatak 4
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <list>

unsigned int PrebrojiModifikovanoIme (const std::string &ime) {
    unsigned int brojac(0);
    for (int i=0; i<ime.length(); ++i)
        if ((ime[i] >= 'a' and ime[i] <= 'z') or (ime[i] >= 'A' and ime[i] <= 'Z') or (ime[i] >= '0' and ime[i] <= '9'))
            brojac++; return brojac;
}

std::vector<std::list<std::string>> Razvrstavanje (const std::vector<std::string> &vektor_imena, const int &br_timova)
{
    if (br_timova<1 or br_timova>vektor_imena.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::list<std::string> lista_imena; for (const auto &x : vektor_imena) lista_imena.push_back(x);
    
    std::vector<int> size;
    for (int i=0; i<br_timova; ++i) size.push_back(vektor_imena.size()/br_timova);
    for (int i=0; i<(vektor_imena.size()%br_timova); ++i) size[i]++;
    
    std::list<std::string>::iterator it_ime (lista_imena.begin());
    std::vector<std::list<std::string>> razvrstana_lista;
    std::string posljednje_ime (*it_ime);
    
    unsigned int clockworks (PrebrojiModifikovanoIme(*it_ime));
    for (int x = 0; x < br_timova; ++x) {
        std::list<std::string> jedinstveni_tim;
        
        for (int y=0; y<size[x]; ++y) {
            clockworks = PrebrojiModifikovanoIme(*it_ime);
            jedinstveni_tim.push_back(*it_ime); it_ime = lista_imena.erase(it_ime);
            if (it_ime == lista_imena.end()) it_ime = lista_imena.begin();
            if (not(lista_imena.end() == ++lista_imena.begin())) {
                for (int br_iteracija = 0; br_iteracija < clockworks-1; ++br_iteracija) {
                    it_ime++; if (it_ime == lista_imena.end()) it_ime = lista_imena.begin();
                }
            }
        }   jedinstveni_tim.sort();
        razvrstana_lista.push_back(jedinstveni_tim);
    }   return razvrstana_lista;
}

int main ()
{
    int broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.ignore(10000, '\n');
    
    std::vector<std::string> imena;
    std::cout << "Unesite imena djece: " << std::endl;
    for (int i=0; i<broj_djece; ++i) {
        std::string input;  std::getline (std::cin, input); imena.push_back(input);
    }   std::cout << "Unesite broj timova: ";   int br_timova;  std::cin >> br_timova;
    try {
        std::vector<std::list<std::string>> lista_timova (Razvrstavanje(imena, br_timova));
        for (int i=0; i<lista_timova.size(); ++i) { std::cout << "Tim " << i+1 << ": ";
            for (auto it = lista_timova[i].begin(); it != lista_timova[i].end(); ++it) {
                std::cout << *it; if (it != --lista_timova[i].end()) std::cout << ", ";
            }   std::cout << std::endl;
        }
    }   catch (std::logic_error txt) {  
        std::cout << "Izuzetak: " << txt.what() << std::endl;
    }   return 0;
}