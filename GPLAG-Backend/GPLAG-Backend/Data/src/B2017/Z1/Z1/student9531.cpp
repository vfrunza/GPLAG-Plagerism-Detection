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
#include <vector>
#include <cmath>
#include <deque>

bool Prost (int n) {
	for (int i = 2; i < std::sqrt(n); i++)
		if (std::abs(n % i == 0))
			return false;
	return true;
}

int TernarniZapis (int broj) {
	int cifra, stepen(1), ternar(0);
	while (broj != 0) {
		cifra = broj % 3;
		broj /= 3;
		ternar += (cifra * stepen);
		stepen *= 10;
	}
	return ternar;
}
bool Simetrican (int ternarni) {
	std::vector<int> prvi;
	int brojac(ternarni);
	int cifra;
	std::vector<int> drugi;
	while (ternarni != 0) {
		cifra = ternarni % 10;
		drugi.push_back(cifra);
		ternarni /= 10;
	}
	if(prvi == drugi)
		return true;
	return false;
	
}

/*std::vector<int> IzdvojiSimetricneTernare (std::vector<int> v, bool prost) {
	for (int i = 0; i < v.size(); i++) {
		if(Prost(v.at(i)) == prost) {
			int pom(v.at(i));
			v.at(i) = TernarniZapis(v.at(i));
			
		}
	}
	return zadnji;

} */
int main () {
	int broj;
	std::vector<int> vek;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> broj	;
		if (broj != -1)
			vek.push_back(broj);
	} while(broj != -1);
	int logicka;
	std::cout << "Unesite 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> logicka;
	bool prostmain(true);
	if (logicka == 0)
		prostmain = false;
	//std::vector<int> ternar = TernarniZapis(vek);
	//std::vector<int> prost = IzdvojiSimetricneTernare(vek, prostmain);
	std::cout << Simetrican(210002);
	//	brTr = TernarniZapis(broj);
	std::cout << "TEST!!!";
	return 0;
}