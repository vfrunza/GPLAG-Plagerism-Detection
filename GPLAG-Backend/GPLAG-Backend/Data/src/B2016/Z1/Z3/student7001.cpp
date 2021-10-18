/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<double> Vektor;
typedef std::vector<Vektor> VektorVektora;

bool JesuLiJednaki(double x, double y, double Eps=1e-10) {
	if ((x<0 && y>0) || (x>0 && y<0)) return false;
	return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
}

VektorVektora RastuciPodnizovi(Vektor pocetni_vektor) {
	VektorVektora rezultat;
	for (int i=0; i<pocetni_vektor.size(); i++) {
		Vektor pomocni_vektor;
		pomocni_vektor.push_back(pocetni_vektor[i]);
		int brojac{};
		for (int j=i+1; j<pocetni_vektor.size(); j++) {
			if ((pomocni_vektor[brojac]<=pocetni_vektor[j]) || JesuLiJednaki(pomocni_vektor[brojac],pocetni_vektor[j])) {
				pomocni_vektor.push_back(pocetni_vektor[j]);
				brojac++;
			}
			else break;
		}
		if (brojac>=1) {
			rezultat.push_back(pomocni_vektor);
			i+=brojac;
		}
	}
	return rezultat;
}

VektorVektora OpadajuciPodnizovi(Vektor pocetni_vektor) {
	VektorVektora rezultat;
	for (int i=0; i<pocetni_vektor.size(); i++) {
		Vektor pomocni_vektor;
		pomocni_vektor.push_back(pocetni_vektor[i]);
		int brojac{};
		for (int j=i+1; j<pocetni_vektor.size(); j++) {
			if ((pomocni_vektor[brojac]>=pocetni_vektor[j]) || JesuLiJednaki(pomocni_vektor[brojac],pocetni_vektor[j])) {
				pomocni_vektor.push_back(pocetni_vektor[j]);
				brojac++;
			}
			else break;
		}
		if (brojac>=1) {
			rezultat.push_back(pomocni_vektor);
			i+=brojac;
		}
	}
	return rezultat;
}

int main() {
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	Vektor pocetni_vektor(n);
	for (int i=0; i<n; i++)
		std::cin >> pocetni_vektor[i];
	auto max_rastuci_podnizovi(RastuciPodnizovi(pocetni_vektor));
	auto min_rastuci_podnizovi(OpadajuciPodnizovi(pocetni_vektor));
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for (int i=0; i<max_rastuci_podnizovi.size(); i++) {
		for (int j=0; j<max_rastuci_podnizovi[i].size(); j++)
			std::cout << max_rastuci_podnizovi[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i=0; i<min_rastuci_podnizovi.size(); i++) {
		for (int j=0; j<min_rastuci_podnizovi[i].size(); j++)
			std::cout << min_rastuci_podnizovi[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}