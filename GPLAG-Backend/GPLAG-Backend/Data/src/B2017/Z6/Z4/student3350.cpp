/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <functional>
#include <complex>
#include <iomanip>


template <typename TipElemenata>
    class DatotecniKontejner {
    std::fstream tok;
  public:
    DatotecniKontejner(const std::string &ime_datoteke) {
        
        tok.clear();
        std::ifstream tok1(ime_datoteke, std::ios::binary);
        
        if (tok1.fail()) {
            std::ofstream tok2(ime_datoteke, std::ios::binary);
            if (!tok2) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
            tok2.close();
        }
        else tok1.close();
        
        tok.open(ime_datoteke, std::ios::in | std::ios::out | std::ios::binary);
    }
    
    void DodajNoviElement(const TipElemenata &element) {
        tok.clear();
        tok.seekp(0, std::ios::end);
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.write(reinterpret_cast<const char*>(&element), sizeof (TipElemenata));
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.seekg(0);
    }
    
    
    int DajBrojElemenata() {
        tok.clear();
        tok.seekg(0, std::ios::end);
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        int duzina(tok.tellg());
        int broj_elemenata(duzina/sizeof(TipElemenata));
        tok.seekg(0);
        return broj_elemenata;
    }
    
    TipElemenata DajElement(int pozicija) {
        if (pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        tok.seekg(pozicija*sizeof(TipElemenata));
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        
        TipElemenata x;
        tok.read(reinterpret_cast<char*>(&x), sizeof (TipElemenata));
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        
        tok.seekg(0);
        
        return x;
    }
    void IzmijeniElement(int pozicija, const TipElemenata &element) {
        if (pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        
        tok.clear();
        tok.seekp(pozicija*sizeof(TipElemenata));
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        
        tok.clear();
        tok.write(reinterpret_cast<const char*>(&element), sizeof element);
        if (!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
        
        tok.seekg(0);
    }
    
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>()) {
        
        bool razmjena(true);
        int n(DajBrojElemenata());
        while (razmjena==true) {
            razmjena=false;
            for (int j=1; j<n; j++) {
                if (!kriterij(DajElement(j-1), DajElement(j))) {
                    TipElemenata temp(DajElement(j-1));
                    IzmijeniElement(j-1, DajElement(j));
                    IzmijeniElement(j, temp);
                    razmjena=true;
                }
            }
            n=n-1;
        }
        
    }
    
};


    
int main ()
{
    
    return 0;
}