/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>
#include <string>
#include <utility>
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

// IMPLEMENTACIJA 
template <typename TipElemenata>
DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke) : tok(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc) {
	if (!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
}
template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element) {
	tok.seekp(0, std::ios::end);
	tok.write(reinterpret_cast<const char*>(&element), sizeof element);
	if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
}
template <typename TipElemenata>
int DatotecniKontejner<TipElemenata>::DajBrojElemenata() {
	tok.seekg(0, std::ios::end);
	int velicina = tok.tellg();
	TipElemenata test;
	return velicina / int(sizeof test);
}
template <typename TipElemenata>
TipElemenata DatotecniKontejner<TipElemenata>::DajElement(int pozicija) {
	if (pozicija < 0 || pozicija >= DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
    TipElemenata element;
	tok.seekg(pozicija*int(sizeof element), std::ios::beg);
	tok.read(reinterpret_cast<char*>(&element), sizeof element);
	if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
	return element;
}
template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element) {
	if (pozicija < 0 || pozicija >= DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
	tok.seekp(pozicija*int(sizeof element), std::ios::beg);
	tok.write(reinterpret_cast<char*>(&element), sizeof element);
	if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
}
template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij) {
	int vel = DajBrojElemenata();
	for (int i = 0; i < vel - 1; i++) {
		for (int j = 0; j < vel-i - 1; j++) {
			TipElemenata tip1,tip2;
			tok.seekg(j*int(sizeof tip1), std::ios::beg);
			tok.read(reinterpret_cast<char*>(&tip1), sizeof tip1);
			tok.seekg((j+1)*int(sizeof tip2), std::ios::beg);
			tok.read(reinterpret_cast<char*>(&tip2), sizeof tip2);
			if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
			if (!kriterij(tip1, tip2)) {
				tok.seekp(j*int(sizeof tip2), std::ios::beg);
				tok.write(reinterpret_cast<char*>(&tip2), sizeof tip2);
				tok.seekp((j+1)*int(sizeof tip1), std::ios::beg);
				tok.write(reinterpret_cast<char*>(&tip1), sizeof tip1);
				if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
			}
		}
	}
}

int main() {
	DatotecniKontejner<double> dat("brojevi.dat");
	dat.DodajNoviElement(5.124124);
		dat.DodajNoviElement(2.5125);
			dat.DodajNoviElement(1);
				dat.DodajNoviElement(999);
	std::cout << dat.DajBrojElemenata() << std::endl;
	std::cout << dat.DajElement(2) << std::endl;
	dat.Sortiraj();
	std::cout << dat.DajElement(0) << std::endl;
}