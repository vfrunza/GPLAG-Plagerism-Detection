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

std::vector<int> PretvoriUTernarni (long long int n)
{
	std::vector<int> pom;
	int cifra;
	if (n < 0) n *= (-1);
	while (n > 0) {
		cifra = n % 3;
		pom.push_back(cifra);
		n /= 3;
	}
	std::vector<int> v_ternarnih;
	for (int i = pom.size() - 1 ; i >= 0 ; i--) {
		v_ternarnih.push_back(pom.at(i));
	}
	return v_ternarnih;
}

bool JeLiProst (long long int broj)
{
	if (broj < 2) return false;
	int broj_korijen = std::sqrt(broj);
	for (int i = 2 ; i <= broj_korijen ; i++) {
		if (broj % i == 0)
			return false;
	}
	return true;
}

bool JeLiSimetrican (long long int broj)
{
	std::vector<int> ternarni = PretvoriUTernarni(broj);

	for (int i = 0 ; i <= ternarni.size() / 2 ; i++) {
		if (ternarni.at(i) != ternarni.at(ternarni.size() - 1 - i))
			return false;
	}
	return true;
}

std::vector<unsigned int> IzdvojiSimetricneTernarne (std::vector<int> a, bool vrijednost)
{
	std::vector<int> b;
	for (int i = 0 ; i < a.size() ; i++) {
		int element = a.at(i);
		for (int j = 0 ; j < b.size() ; j++) {
			if (b.at(j) == element) break;
		}
		b.push_back(a.at(i));

	}
	std::vector<unsigned int> vek_prostih, vek_sozenih;
	for (int i = 0 ; i < b.size() ; i++) {
		if (JeLiProst(b.at(i)) == true && JeLiSimetrican(b.at(i)) == true)
			vek_prostih.push_back(b.at(i));
		if (JeLiProst(b.at(i)) == false && JeLiSimetrican(b.at(i)) == true)
			vek_sozenih.push_back(b.at(i));
	}
	if (vrijednost == true)
		return vek_prostih;
	else
		return vek_sozenih;

}

int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> vektor;
	int broj;
	do {
		std::cin >> broj;
		if (broj != -1)
			vektor.push_back(broj);


	} while (broj != -1);

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int n;
	std::cin >> n;
	if (n != 0 && n != 1) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> n;
	}
	if (n == 1) {
		std::vector<unsigned int> v_prostih;
		v_prostih = IzdvojiSimetricneTernarne(vektor, true);
		if (v_prostih.size() == 0)
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for (int i = 0 ; i < v_prostih.size() ; i++) {
				if (i < v_prostih.size() - 1)
					std::cout << v_prostih.at(i) << ", ";
				if (i == v_prostih.size() - 1)
					std::cout << v_prostih.at(i) << ".";
			}
		}
	} else if (n == 0) {
		std::vector<unsigned int> v_slozenih;
		v_slozenih = IzdvojiSimetricneTernarne(vektor, false);
		if (v_slozenih.size() == 0)
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i = 0 ; i < v_slozenih.size() ; i++) {
				if (i < v_slozenih.size() - 1)
					std::cout << v_slozenih.at(i) << ", ";
				if (i == v_slozenih.size() - 1)
					std::cout << v_slozenih.at(i) << ".";
			}
		}
	}


	return 0;
}