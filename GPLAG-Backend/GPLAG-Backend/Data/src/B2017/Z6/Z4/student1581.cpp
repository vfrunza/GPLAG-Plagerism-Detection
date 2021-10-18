/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>
#include <string>

using std::string;

//sort obaviti poput selection sort koristeci funkciju kriterija function<bool(type, type)> f

template<typename TipElementa>
class DatotecniKontejner {
    std::fstream tok;
    void ErrorCheck() {
        if(!tok) throw std::logic_error("Probemi prilikom pristupa datoteci");
    }
public:
    DatotecniKontejner(const string &ime_datoteke);
    void DodajNoviElement(const TipElementa &element);
    int DajBrojElemenata();
    TipElementa DajElement(int pozicija);
    void IzmijeniElement(int pozicija, const TipElementa &element);
    void Sortiraj(std::function<bool(const TipElementa&, const TipElementa&)> kriterij  = std::less<TipElementa>());
};

template<typename TipElementa>
DatotecniKontejner<TipElementa>::DatotecniKontejner(const string &ime_datoteke) {
    tok.open(ime_datoteke, std::ios::in | std::ios::binary);
    
    if(!tok){
        tok.clear();
        tok.open(ime_datoteke, std::ios::out | std::ios::binary);
        
        if(!tok)
            throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
    
    tok.close();
    tok.open(ime_datoteke, std::ios::in | std::ios::out | std::ios::binary);
    tok.seekp(0);
    tok.seekg(0);
}

template<typename TipElementa>
void DatotecniKontejner<TipElementa>::DodajNoviElement(const TipElementa &element) {
    tok.seekp(0, std::ios::end);
    tok.write(reinterpret_cast<const char*>(&element), sizeof(element));
    tok.seekg(0, std::ios::end);
    ErrorCheck();
}

template<typename TipElementa>
int DatotecniKontejner<TipElementa>::DajBrojElemenata() {
    tok.seekg(0, std::ios::end);
    int br_elem = tok.tellg()/sizeof(TipElementa);
    tok.seekp(0, std::ios::end);
    ErrorCheck();
    return br_elem;
}

template<typename TipElementa>
TipElementa DatotecniKontejner<TipElementa>::DajElement(int pozicija) {
    if(pozicija < 0 || pozicija >= DajBrojElemenata())
        throw std::range_error("Neispravna pozicija");
    
    tok.seekg(pozicija * sizeof(TipElementa));
    TipElementa var;
    tok.read(reinterpret_cast<char*>(&var), sizeof(TipElementa));
    
    ErrorCheck();
    return var;
}

template<typename TipElementa>
void DatotecniKontejner<TipElementa>::IzmijeniElement(int pozicija, const TipElementa &element) {
    if(pozicija >= DajBrojElemenata())
        throw std::range_error("Neispravna pozicija");
    
    tok.seekp(pozicija * sizeof(TipElementa));
    tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElementa));
    
    ErrorCheck();
}

template<typename TipElementa>
void DatotecniKontejner<TipElementa>::Sortiraj(std::function<bool(const TipElementa&, const TipElementa&)> kriterij) {
    int size = DajBrojElemenata();
    
    for(int i = 0; i < size-1; i++){
        int idx = i;
        for(int j = i+1; j < size; j++){
            if(kriterij(DajElement(j), DajElement(idx)) )
                idx = j;
        }
        if(idx != i){
            TipElementa temp = DajElement(idx);
            IzmijeniElement(idx, DajElement(i));
            IzmijeniElement(i, temp);
        }
        
        ErrorCheck();
    }
}

int main () {
    DatotecniKontejner<int> dtc("data.bin");
    DatotecniKontejner<int> dtc2("data.bin");
    int temp;
    
    while(true){
        std::cin >> temp;
        if(temp == -1) break;
        dtc.DodajNoviElement(temp);
    }
    
    std::cout << "Broj elemenata: " << dtc.DajBrojElemenata() << ":" << dtc2.DajBrojElemenata() << std::endl;
    
    std::cout << dtc.DajBrojElemenata() << std::endl;
    std::cout << dtc2.DajBrojElemenata() << std::endl;
    std::cout << dtc.DajBrojElemenata() << std::endl;
    std::cout << dtc.DajBrojElemenata() << std::endl;
    std::cout << dtc2.DajBrojElemenata() << std::endl;
    
    
    // std::cout << "dtc ima " << dtc.DajBrojElemenata() << " elemenata: ";
    // for(int i = 0; i < dtc.DajBrojElemenata(); i++)
    //     std::cout << dtc.DajElement(i) << " ";
    
    
    // std::cout << std::endl << "dtc2 ima " << dtc2.DajBrojElemenata() << " elemenata: ";
    // for(int i = 0; i < dtc2.DajBrojElemenata(); i++)
    //     std::cout << dtc2.DajElement(i) << " ";
    
    
	return 0;
}