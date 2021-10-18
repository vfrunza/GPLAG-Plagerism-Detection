/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <stdexcept>

template <typename TipElemenata>
    class DatotecniKontejner {
        std::fstream tok;
    public:
        DatotecniKontejner(const std::string &ime_datoteke) {
            tok.open(ime_datoteke, std::ios::in | std::ios::binary);
            if (!tok) {
                tok.clear();
                tok.open(ime_datoteke, std::ios::out | std::ios::binary);
                if (!tok) {
                    tok.clear();
                    throw std::logic_error("Problemi prilikom kreiranja ili otvaranja datoteke");
                }
            }
            tok.close();
            tok.open(ime_datoteke, std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);
            if (!tok) {
                tok.clear();
                throw std::logic_error("Problemi prilikom kreiranja ili otvaranja datoteke");
            }
        }
        void DodajNoviElement(const TipElemenata &element) {
            tok.seekp(0, std::ios::end);
            tok.write(reinterpret_cast<const char*>(&element), sizeof element);
            if (!tok) {
                tok.clear();
                throw std::logic_error("Problemi prilikom pristupa datoteci");
            }
            tok.seekp(0, std::ios::end);
            tok.seekg(0, std::ios::end);
        }
        int DajBrojElemenata() {
            tok.seekg(0, std::ios::end);
            int duzina_datoteke(tok.tellg());
            int broj_el(duzina_datoteke/sizeof(TipElemenata));
            return broj_el;
        }
        TipElemenata DajElement(int pozicija) {
            if (pozicija<0) throw std::range_error("Neispravna pozicija");
            if (pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
            tok.seekg(pozicija*sizeof(TipElemenata));
            TipElemenata element;
            tok.read(reinterpret_cast<char*>(&element), sizeof element);
            if (!tok) {
                tok.clear();
                throw std::logic_error("Problemi prilikom pristupa datoteci");
            }
            return element;
        }
        void IzmijeniElement(int pozicija, const TipElemenata &element) {
            if (pozicija<0) throw std::range_error("Neispravna pozicija");
            if (pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
            tok.seekp(pozicija*sizeof(TipElemenata));
            tok.write(reinterpret_cast<const char*>(&element), sizeof element);
            if (!tok) {
                tok.clear();
                throw std::logic_error("Problemi prilikom pristupa datoteci");
            }
        }
        void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij=std::less<TipElemenata>()) {
            int min_indeks(0);
            for (int i=0; i<DajBrojElemenata()-1; i++) {
                min_indeks=i;
                for (int j=i+1; j<DajBrojElemenata(); j++) {
                    if (kriterij(DajElement(j), DajElement(min_indeks))) {
                        min_indeks=j;
                    }
                }
                TipElemenata temp;
                temp=DajElement(i);
                IzmijeniElement(i, DajElement(min_indeks));
                IzmijeniElement(min_indeks, temp);
            }
        }
    };

int main ()
{
    DatotecniKontejner<double> nova("nadatt.bin");
    nova.DodajNoviElement(4);
    nova.DodajNoviElement(5);
    nova.DodajNoviElement(0.5);
    nova.DodajNoviElement(9.8);
    
    std::cout << "Treba ispisati drugi element: " << std::endl;
    std::cout << nova.DajElement(1) << std::endl << std::endl;
    
    std::cout << "Nesortirano: ";
    for (int i=0; i<nova.DajBrojElemenata(); i++) {
        std::cout << nova.DajElement(i) << " ";
    }
    std::cout << std::endl << std::endl;
    
    nova.Sortiraj(std::greater<double>());
    
    std::cout << "Sortirano opadajuce: ";
    for (int i=0; i<nova.DajBrojElemenata(); i++) {
        std::cout << nova.DajElement(i) << " ";
    }
    
    nova.Sortiraj();
    
    std::cout << std::endl << "Sortirano rastuce: ";
    for (int i=0; i<nova.DajBrojElemenata(); i++) {
        std::cout << nova.DajElement(i) << " ";
    }
	return 0;
}
