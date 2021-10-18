/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <functional>
#include <algorithm>

template <typename TipElemenata>
 class DatotecniKontejner {
 std::fstream tok;
 public:
 DatotecniKontejner(const std::string &ime_datoteke);
 void DodajNoviElement(const TipElemenata &element);
 int DajBrojElemenata();
 TipElemenata DajElement(int pozicija);
 void IzmijeniElement(int pozicija, const TipElemenata &element);
 void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>());
 };

template <typename TipElemenata>
DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke){
    tok.open(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
    if(tok.fail()){
    tok.open(ime_datoteke, std::ios::binary | std::ios::out);
    tok.close();
    tok.open(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
    }
    if(!tok.is_open()) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element){
    int br_el(this->DajBrojElemenata());
    tok.seekg(sizeof(TipElemenata)*br_el, std::ios::beg);
    tok.write(const_cast<char*>(reinterpret_cast<const char*>(&element)), sizeof element);
    if(!tok.is_open()) throw std::logic_error("Problemi prilikom pristupa datoteci");
}

template <typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata(){
    tok.seekg(0, std::ios::end);
    if(!tok.is_open()) throw std::logic_error("Problemi prilikom pristupa datoteci");
    int duzina_dat(tok.tellg());
    int br_el(duzina_dat/sizeof(TipElemenata));
    return br_el;
}

template <typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija){
    int br_el(this->DajBrojElemenata());
    if(pozicija<0 || pozicija>br_el-1) throw std::range_error("Neispravna pozicija");
    tok.seekg(sizeof(TipElemenata)*pozicija, std::ios::beg);
    TipElemenata el;
    tok.read(reinterpret_cast<char*>(&el), sizeof el);
    //if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
    return el;
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element){
    int br_el(this->DajBrojElemenata());
    if(pozicija<0 || pozicija>br_el-1) throw std::range_error("Neispravna pozicija");
    tok.seekp(sizeof(TipElemenata)*pozicija, std::ios::beg);
    tok.write(reinterpret_cast<const char*>(&element), sizeof(TipElemenata));
    //if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij){
    int br(this->DajBrojElemenata());
    for(int i(0); i<br; i++){
        auto el1(DajElement(i));
        for(int j(i+1); j<br; j++){
            auto el2(DajElement(j));
            if(kriterij(el2, el1)){
                for(int k(j); k>i; k--){
                    auto el3(DajElement(k-1));
                    tok.seekp(k, std::ios::beg);
                    tok.write(reinterpret_cast<char*>(&el3), sizeof el3);
                }
            tok.seekp(i, std::ios::beg);
            tok.write(reinterpret_cast<char*>(&el2), sizeof el2);
        }
    }
}
}

int main ()
{
    DatotecniKontejner<double> dk1("ime3.DAT");
    DatotecniKontejner<double> dk2("ime3.DAT");
    DatotecniKontejner<double> dk3("ime4.DAT");
        
        dk1.DodajNoviElement(1.28);
        
        std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;
	return 0;
}
