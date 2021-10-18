/*B 2017/2018, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <cmath>
#include <vector>

int DekadniUTernarni (int broj)
{
	int testni (broj), brojac (0), rezultat (0);

	while(testni != 0) {
		rezultat += (testni % 3) * pow(10, brojac);
		brojac++;
		testni /= 3;
	}
	return rezultat;
}

bool ProvjeraZaProste (int broj)
{
	long int provjeri (broj);
	if(broj < 0) provjeri*= -1;
	if(provjeri < 2) return false;

	for(int i = 2; i <= int(sqrt(provjeri)); i++) {
		if(provjeri % i == 0) return false;
	}
	return true;
}

bool ProvjeraSimetricnosti (int ternarni)
{
	int suprotni(0), trenutni (ternarni), brojac(0);

	while (trenutni != 0) {
		brojac++;
		trenutni /= 10;
	}

	trenutni = ternarni;
	brojac--;

	while (trenutni != 0) {
		suprotni += (trenutni % 10) * pow(10, brojac);
		brojac--;
		trenutni /= 10;
	}
	if(suprotni == ternarni) return true;

	return false;
}

std::vector<int> ObrisiDuple (std::vector<int> v)
{

	std::vector<int> novi (v);
	if(v.size() == 0) return v;

	for(int i = 0; i < v.size() - 1; i++) {
		for(int j = i + 1; j < v.size(); j++) {
			if(v.at(i) == v.at(j)) {
				v.erase(v.begin() + j);
				j--;
			}
		}
	}

	return v;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool logicka)
{

	std::vector<int> rezultat;
	int ternarni;

	if(logicka == true) {
		for(int x: v) {
			ternarni = DekadniUTernarni(x);
			if(ProvjeraSimetricnosti(ternarni) && (ProvjeraZaProste(x))) rezultat.push_back(x);
		}
	}

	else {
		for(int x: v) {
			ternarni = DekadniUTernarni(x);
			if(ProvjeraSimetricnosti(ternarni) && !ProvjeraZaProste(x)) rezultat.push_back(x);
		}
	}

	return ObrisiDuple(rezultat);
}

int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";

	std::vector<int> v;

	for(;;) {

		int privremena(0);
		std::cin >> privremena;
		if(privremena == -1) break;
		v.push_back(privremena);
	}

	bool logicka;
	long int testna;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";


	std::cin >> testna;

	while(testna != 1 && testna != 0) {

		std::cout << "Neispravan unos! Unesite ponovo: " ;
		std::cin >> testna;
	}

	logicka = testna;

	std::vector<int> finalni (IzdvojiSimetricneTernarne(v, logicka));

	if(logicka) {
		if(finalni.size() == 0)
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";

		else
			std::cout << "Prosti simetricni brojevi iz vektora su: ";

	} else {

		if(finalni.size() == 0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	}

	for(int i = 0; i < finalni.size(); i++) {
		if(i == finalni.size() - 1) {
			std::cout << finalni.at(i) << ".";
			break;
		}
		std::cout << finalni.at(i) << ", ";
	}

	return 0;
}
