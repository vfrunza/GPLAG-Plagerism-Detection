/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <utility>
#include <iomanip>
#include <stdexcept>

template<typename TipElemenata>
class DatotecniKontejner {
protected:
std::fstream tok;
public:
DatotecniKontejner(const std::string &ime_datoteke) {
    tok(ime_datoteke, std::ios::in || std::ios::binary);
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
}
void DodajNoviElement(const TipElemenata &element) {
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    tok.seekg(0, std::ios::end);
    int temp(tok.tellp()/sizeof(TipElemenata));
    tok.seekg(temp*sizeof(TipElemenata) + sizeof(TipElemenata));
    tok.write((char*)&element, sizeof(element));
    tok.close();
    
}
int DajBrojElemenata() {
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    tok.seekp(0, std::ios::end);
    int temp(tok.tellp()/sizeof(TipElemenata));
    tok.close();
    return temp;
}
TipElemenata DajElement(int pozicija) {
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    if(pozicija<0 || pozicija>DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
    tok.seekp(0, std::ios::beg);
    tok.seekp(sizeof(TipElemenata)+pozicija*sizeof(TipElemenata));
    TipElemenata rez(tok.tellp());
    return rez;
}
void IzmjeniElement(int pozicija, const TipElemenata &element) {
    if(!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    if(pozicija<0 || pozicija>DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
    tok.seekp(0, std::ios::beg);
    tok.seekp(sizeof(TipElemenata)+pozicija*sizeof(TipElemenata));
    tok.write((char*)element, sizeof(element));
}
void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>kriterij=std::less<TipElemenata>());
};

int main () {
    
	return 0;
}
