/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <stdexcept>

template <typename TipElemenata>
class DatotecniKontejner {
    std::fstream tok;
    public:
    DatotecniKontejner(const std::string &ime_datoteke) {
        tok.open(ime_datoteke, std::ios::binary);
        if(!tok) throw std::logic_error 
                        ("Problemi prilikom otvaranja ili kreiranja datoteke"); 
    }
    void DodajNoviElement(const TipElemenata &element);
    int DajBrojElemenata();
    TipElemenata DajElement(int pozicija);
    void IzmjeniElement(int pozicija, const TipElemenata &element);
    //void Sortiraj(std::function<bool(const TipElemenata & ,
    //              const TipElemenata & )> kriterij=std::less<TipElemenata>() );
};

int main ()
{
	return 0;
}
