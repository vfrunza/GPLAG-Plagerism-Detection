#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename KontTip>
KontTip Red(const KontTip &red, int x) {
	KontTip sat_red;
	for (int i = x; i < red.size() - x; i++) sat_red.push_back(red.at(i));
	return sat_red;
}

template <typename KontTip>
KontTip Sat_Matrica(const KontTip &matrica) {
	KontTip sat_matrica;
	int i(0);
	for (; i < (matrica.size()+1)/2; i++) sat_matrica.push_back(Red(matrica.at(i), i));
	for (; i < matrica.size(); i++) sat_matrica.push_back(Red(matrica.at(i), matrica.size() - i - 1));
	return sat_matrica;
}

template <typename KontTip>
KontTip Matrica(const KontTip &matrica) {
	KontTip mat;
	for (int i = 0; i < matrica.size(); i++) mat.push_back(Red(matrica.at(i), 0));
	return mat;
}

template <typename KontTip>
KontTip Preslikaj(const KontTip &matrica) {
	auto preslikana(Matrica(matrica));
	for (int i = 0; i < (preslikana.size()+1)/2; i++)
		for (int j = 0; j < preslikana.size(); j++) {
			auto t(preslikana.at(i).at(j));
			preslikana.at(i).at(j) = preslikana.at(preslikana.size()-i-1).at(j);
			preslikana.at(preslikana.size()-i-1).at(j) = t;
		}
	return preslikana;
}

template <typename KontTip>
KontTip Rotiraj(const KontTip &matrica) {
	auto rotirano(Matrica(matrica));
	for (int i = 0; i < rotirano.size(); i++) 
		for (int j = i+1; j < rotirano.size(); j++) {
				auto t(rotirano.at(i).at(j));
				rotirano.at(i).at(j) = rotirano.at(j).at(i);
				rotirano.at(j).at(i) = t;
		}
	return rotirano;
}

template <typename KontTip>
void NpNz(const KontTip &kocka, KontTip &pjescani, SmjerKretanja smjer = SmjerKretanja::NaprijedNazad) {
	for (int i = 0; i < kocka.size(); i++) {
		decltype(Matrica(kocka.at(i))) matrica;
		for (int j = 0; j < kocka.size(); j++) 
			matrica.push_back(kocka.at(j).at(i));
		if (smjer == SmjerKretanja::NazadNaprijed) matrica = Preslikaj(matrica);
		pjescani.push_back(Sat_Matrica(matrica));
	}
}

template <typename KontTip>
bool IspravanFormat(const KontTip &matrica, int n) {
	if (matrica.size() != n) return false;
	for (int i = 0; i < matrica.size(); i++) 
		if (matrica.at(i).size() != n) return false;
	return true;
}

template <typename KontTip>
KontTip PjescaniSat(const KontTip &kont, SmjerKretanja smjer) {
	for (int i = 0; i < kont.size(); i++) 
		if (!IspravanFormat(kont.at(i), kont.size())) throw std::domain_error("3D matrica nema oblik kocke");
	if (kont.size() % 2 == 0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	KontTip pjescani;
	switch (smjer) {
		case SmjerKretanja::DesnoLijevo :
			for (int i = 0; i < kont.size(); i++) pjescani.push_back(Sat_Matrica(Preslikaj(Rotiraj(kont.at(i)))));
			break;
		case SmjerKretanja::LijevoDesno :
			for (int i = 0; i < kont.size(); i++) pjescani.push_back(Sat_Matrica(Rotiraj(kont.at(i))));
			break;
		case SmjerKretanja::GoreDolje :
			for (int i = 0; i < kont.size(); i++) pjescani.push_back(Sat_Matrica(kont.at(i)));
			break;
		case SmjerKretanja::DoljeGore :
			for (int i = 0; i < kont.size(); i++) pjescani.push_back(Sat_Matrica(Preslikaj(kont.at(i))));
			break;
		case SmjerKretanja::NaprijedNazad :
			NpNz (kont, pjescani);
			break;
		case SmjerKretanja::NazadNaprijed :
			NpNz (kont, pjescani, SmjerKretanja::NazadNaprijed);
			break;
	}
	return pjescani;
}

int main ()
{
	try {
		int n;
		std::cout << "Unesite dimenziju (x/y/z): ";
		while (std::cin >> n, n < 1) std::cout << "Dimenzija nije ispravna, unesite opet: ";
		std::vector<std::deque<std::deque<int>>> vdd(n, std::deque<std::deque<int>> (n, std::deque<int>(n)));
		std::cout << "Unesite elemente kontejnera: ";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					std::cin >> vdd.at(i).at(j).at(k);
		int smjer;
		std::cout << "Unesite smjer kretanja [0 - 5]:";
		while (std::cin >> smjer, smjer < 0 || smjer > 5) std::cout << " Smjer nije ispravan, unesite opet: ";
		std::cout << std::endl;
		auto pjescani(PjescaniSat(vdd, SmjerKretanja(smjer)));
		std::cout << "Pjescani sat unesene matrice je:" << std::endl << std::endl;
		for (int i = 0; i < pjescani.size(); i++) {
			for (int j = 0; j < pjescani.at(i).size(); j++) {
				for (int k = 0; k < pjescani.at(i).at(j).size(); k++) {
					for (int l = 0; l < (n - pjescani.at(i).at(j).size())/2; l++) std::cout << "    ";
					std::cout << std::setw(4) << pjescani.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch(std::length_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch(std::overflow_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch(std::bad_alloc) {
		std::cout << "Izuzetak: Alokacija nije uspjela"; 
	}
	return 0;
}