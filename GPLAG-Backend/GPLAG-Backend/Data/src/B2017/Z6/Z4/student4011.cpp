/B2017/2018: Zadaća 6, Zadatak 4
// TPZ6Z4.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <functional>

template <typename TipElemenata>
class DatotecniKontejner {
	std::fstream tok;
	void ProvjeraIspravnosti() { if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci"); }
	bool UOpsegu(int pozicija) { tok.seekg(0, std::ios::end); return (pozicija >= 0 && pozicija * sizeof(TipElemenata) <= tok.tellg()); }
	int DajVelicinuDatoteke() { tok.seekg(0, std::ios::end); return tok.tellg(); }
public:
	DatotecniKontejner(const std::string &ime_datoteke);
	void DodajNoviElement(const TipElemenata &element);
	int DajBrojElemenata();
	TipElemenata DajElement(int pozicija);
	void IzmijeniElement(int pozicija, const TipElemenata &element);
	void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>kriterij = std::less<TipElemenata>());
};

int main()
{
	std::string ime_datoteke("BROJEVI.DAT");
	DatotecniKontejner <int>datoteka1(ime_datoteke);
	datoteka1.DodajNoviElement(5);
    datoteka1.DodajNoviElement(2);
    datoteka1.DodajNoviElement(4);
    datoteka1.DodajNoviElement(123);
    datoteka1.DodajNoviElement(7);
    datoteka1.DodajNoviElement(6);
    datoteka1.DodajNoviElement(22);
    datoteka1.DodajNoviElement(13);    
    datoteka1.DodajNoviElement(88);
    datoteka1.DodajNoviElement(1);
    datoteka1.DodajNoviElement(223);
    datoteka1.IzmijeniElement(10, 100);
    std::cout << datoteka1.DajBrojElemenata() << std::endl;
    datoteka1.Sortiraj(std::greater<int>());
    std::cout << datoteka1.DajElement(8) << std::endl;
    std::cout << datoteka1.DajElement(1) << " " << datoteka1.DajElement(2) << " " << datoteka1.DajElement(3) << " " << datoteka1.DajElement(4) << " " <<
    datoteka1.DajElement(5) << " " << datoteka1.DajElement(6) << " " << datoteka1.DajElement(7) << " " << datoteka1.DajElement(8) << " " << datoteka1.DajElement(9) 
    << " " << datoteka1.DajElement(10) << " " << datoteka1.DajElement(11) << " " << datoteka1.DajElement(12);
    return 0;
}

template<typename TipElemenata>
DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke) {
	tok.open(ime_datoteke, std::ios::binary | std::ios::out | std::ios::in | std::ios::ate);
}
template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element) {
	tok.write(reinterpret_cast<const char*>(&element), int(sizeof (TipElemenata)));
}
template<typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata() {
	int brel = DajVelicinuDatoteke()/int(sizeof(TipElemenata));
	return brel;
}
template<typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija) {
	pozicija--;
	tok.seekg(pozicija * int(sizeof(TipElemenata)));
	TipElemenata element;
	tok.read(reinterpret_cast<char*>(&element), int(sizeof (element)));
	return element;
}
template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata & element) {
	pozicija--;
	TipElemenata element1(element);
	tok.seekp(pozicija * int(sizeof(TipElemenata)));
	tok.write(reinterpret_cast<char*>(&element1), int(sizeof (TipElemenata)));
}
template<typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj(std::function<bool(const TipElemenata&, const TipElemenata&)> kriterij) {
	for (int i(0); i < DajBrojElemenata() - 1; i++) {
		for (int j(0); j < DajBrojElemenata() - 1 - i; j++) {
			TipElemenata prvi, drugi;
			tok.seekg(int(sizeof prvi)*j, std::ios::beg);
			tok.read(reinterpret_cast<char*>(&prvi), sizeof prvi);
			tok.seekg(int(sizeof drugi)*(j+1), std::ios::beg);
			tok.read(reinterpret_cast<char*>(&drugi), sizeof drugi);
			if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
			if(!kriterij(prvi, drugi)) {
				tok.seekp(int(sizeof drugi)*j, std::ios::beg);
				tok.write(reinterpret_cast<char*>(&drugi), sizeof drugi);
				tok.seekp(int(sizeof prvi)*(j+1),std::ios::beg);
				tok.write(reinterpret_cast<char*>(&prvi), sizeof prvi);
				if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
			}
		}
	}
}

