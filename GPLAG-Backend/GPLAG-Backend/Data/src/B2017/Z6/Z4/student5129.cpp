w/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>

#include <functional>

#include <stdexcept>

template <typename TipEl>
class DatotecniKontejner {
    std::fstream io;
public:
    DatotecniKontejner(const std::string &naziv_datoteke);
    
    void DodajNoviElement(const TipEl &el);
    int DajBrojElemenata();
    TipEl DajElement(int poz);
    void IzmijeniElement(int poz, const TipEl &el);
    
    void Sortiraj(std::function<bool(const TipEl&, const TipEl&)> kriterij = std::less<TipEl>());
};

int main ()
{
    DatotecniKontejner<double> dk1("ime3.DAT");
    DatotecniKontejner<double> dk2("ime3.DAT");
    
    dk1.DodajNoviElement(5);
    
    std::cout << dk1.DajBrojElemenata() << " " << dk2.DajBrojElemenata() << std::endl;
    
	return 0;
}

template <typename TipEl>
DatotecniKontejner<TipEl>::DatotecniKontejner(const std::string &naziv_datoteke) :
    io(naziv_datoteke, std::ios::in | std::ios::out) {
        if (!io) {
            io.clear();
            io.open(naziv_datoteke, std::ios::out);
            
            io.close();
            io.open(naziv_datoteke, std::ios::in | std::ios::out);
        }
        
        if (!io) {
            io.clear();
            throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
        }
}

template <typename TipEl>
void DatotecniKontejner<TipEl>::DodajNoviElement(const TipEl &el) {
    io.seekp(0, std::ios::end);
    io.write(reinterpret_cast<const char*>(&el), sizeof(el));
    io.flush();
    
    if (!io)
        throw std::logic_error("Problemi prilikom pristupa datoteci");
}

template <typename TipEl>
int DatotecniKontejner<TipEl>::DajBrojElemenata() {
    io.seekg(0, std::ios::end);
    int poz = io.tellg();
    
    if (!io)
        throw std::logic_error("Problemi prilikom pristupa datoteci");
    
    io.seekg(0);
    return poz / sizeof(TipEl);
}

template <typename TipEl>
TipEl DatotecniKontejner<TipEl>::DajElement(int poz) {
    if (poz < 0 || poz >= DajBrojElemenata())
        throw std::range_error("Neispravna pozicija");
        
    TipEl res;
    io.seekg(poz * sizeof(TipEl));
    io.read(reinterpret_cast<char *>(&res), sizeof(res));
    
    if (!io)
        throw std::logic_error("Problemi prilikom pristupa datoteci");
    
    io.seekg(0);
    return res;
}

template <typename TipEl>
void DatotecniKontejner<TipEl>::IzmijeniElement(int poz, const TipEl &el)
{
    if (poz < 0 || poz >= DajBrojElemenata())
        throw std::range_error("Neispravna pozicija");
    
    io.seekp(poz * sizeof(TipEl));
    io.write(reinterpret_cast<const char *>(&el), sizeof(el));
    io.flush();
    
    if (!io)
        throw std::logic_error("Problemi prilikom pristupa datoteci");
    
    io.seekg(0);
}

template <typename TipEl>
void DatotecniKontejner<TipEl>::Sortiraj(std::function<bool(const TipEl&, const TipEl&)> kriterij) {
    int n = DajBrojElemenata();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            TipEl prvi(DajElement(i));
            TipEl drugi(DajElement(j));
            
            if (kriterij(drugi, prvi)) {
                IzmijeniElement(i, drugi);
                IzmijeniElement(j, prvi);
            }
        }
}