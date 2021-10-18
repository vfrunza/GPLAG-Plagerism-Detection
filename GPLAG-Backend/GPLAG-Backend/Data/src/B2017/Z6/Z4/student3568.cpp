/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>
#include <string>

template <typename TipElemenata>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke);
    void DodajNoviElement(const TipElemenata &element);
    int DajBrojElemenata();
    TipElemenata DajElement(int pozicija);
    void IzmijeniElement(int pozicija, const TipElemenata &element);
    void Sortiraj(std::function<bool(const TipElemenata&, const TipElemenata&)>
                  kriterij = std::less<TipElemenata>());
};

template <typename TipElemenata>
DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke) 
{
    tok.open(ime_datoteke, std::ios::out | std::ios::binary);
    if(!tok)
        throw std::logic_error ("Problemi prilikom otvaranja ili kreiranja datoteke");
    tok.close();
    tok.open(ime_datoteke, std::ios::out | std::ios::in | std::ios::ate | std::ios::binary);
} 

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element){
    tok.seekp(DajBrojElemenata()*sizeof(TipElemenata));
    tok.write(reinterpret_cast<const char*>(&element), sizeof element);
    if(!tok)
        throw std::logic_error ("Problemi prilikom pristupa datoteci");
}

template <typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata(){
    tok.seekg(0, std::ios::end);
    int broj_elemenata(tok.tellg() / sizeof(TipElemenata));
    return broj_elemenata;
}

template <typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija){
    if(pozicija < 0 || pozicija >= DajBrojElemenata())
        throw std::range_error ("Neispravna pozicija");
    tok.seekg(pozicija*sizeof(TipElemenata));
    TipElemenata element;
    tok.read(reinterpret_cast<char*>(&element), sizeof element);
    if(!tok)
        throw std::logic_error ("Problemi prilikom pristupa datoteci");
    return element;
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element){
    if(pozicija < 0 || pozicija >= DajBrojElemenata())
        throw std::range_error ("Neispravna pozicija");
    tok.seekp(pozicija*sizeof(TipElemenata));
    tok.write(reinterpret_cast<const char*>(&element), sizeof element);
    if(!tok)
        throw std::logic_error ("Problemi prilikom pristupa datoteci");
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj(std::function<bool(const TipElemenata&, const TipElemenata&)>
                  kriterij){
    
    for(int i = 0; i< DajBrojElemenata()-1; i++){
    int najmanji_indeks(i);
        for(int j= i+1; j<DajBrojElemenata(); j++){
            if(kriterij(DajElement(j), DajElement(najmanji_indeks)) == true) 
                najmanji_indeks = j;
        }
        TipElemenata tmp(DajElement(i));
        IzmijeniElement(i, DajElement(najmanji_indeks));
        IzmijeniElement(najmanji_indeks, tmp);
    }
}

template <typename TipElemenata>
void IspisiSve(std::string ime_datoteke){
    std::fstream tok(ime_datoteke, std::ios::in | std::ios::binary);
    TipElemenata element;
    std::cout << "-----" << std::endl;
    while (tok.read(reinterpret_cast<char*>(&element), sizeof element)) {
        std::cout << element << std::endl;
    }
}

int main ()
{
    std::string ime_datoteke("BINARNA");
    DatotecniKontejner<int> dk(ime_datoteke);
    int a(10), b(15), c(2), d(14);
    dk.DodajNoviElement(a);
    dk.DodajNoviElement(b);
    dk.DodajNoviElement(c);
    dk.DodajNoviElement(d);
    std::cout << dk.DajBrojElemenata() << std::endl;
    IspisiSve<int>(ime_datoteke);
    dk.IzmijeniElement(2, 3);
    std::cout << dk.DajElement(2) << std::endl;
    IspisiSve<int>(ime_datoteke);
    dk.DodajNoviElement(-45);
    dk.Sortiraj(std::greater<int>());
    IspisiSve<int>(ime_datoteke);
    
    return 0;
}
