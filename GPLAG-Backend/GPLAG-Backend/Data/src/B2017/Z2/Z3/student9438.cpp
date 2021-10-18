/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

template <typename Tip>
bool periodican(const std::vector<Tip> &vek, int period) {
	for(int i(0); i < vek.size(); i++) {
		for(int j(i + period); j < vek.size(); j += period) {
			if(vek.at(j) != vek.at(i)) return false;
		}
	}
	return true;
}

template <typename Tip>
int period(const std::vector<Tip> &vek) {
	int period(-1);	
	for(int i(1); i <= vek.size() - 1; i++) {
		if(periodican(vek, i)) {
			period = i;
			break;
		}
	}
	return period;
}

template <typename Tip>
Tip maksimum(const std::vector<Tip> &vek) {
	Tip max(vek.at(0));
	for(int i(0); i < vek.size(); i++) {
		if(vek.at(i) > max) max = vek.at(i);
	}
	return max;
}

template <typename Tip>
int **AlocirajFragmentirano(const std::vector<Tip> &vek, int &koliko_puta) {
	if(vek.size() == 0) throw ("Prazan vektor!");
	for(int i(0); i < vek.size(); i++) {
		if(vek.at(i) < 1) throw std::domain_error("Neispravan vektor!");
	}
	int osnovni_period(period(vek));
	int rezultat, za_dodati;
	if(osnovni_period != -1) {
		rezultat = vek.size() % osnovni_period;
		za_dodati = osnovni_period - rezultat;
		if(za_dodati == osnovni_period) za_dodati = 0;
		koliko_puta = (vek.size() + za_dodati) / osnovni_period;
	}
	else {
		koliko_puta = 2;
		osnovni_period = vek.size();
	}
	try {
		int **matrica = new int*[osnovni_period * koliko_puta]{};
		try {
			for(int i(0); i < koliko_puta * osnovni_period; i++) {
				matrica[i] = new int[vek.at(i % osnovni_period)]{};
			}
			
			int maksimalni = maksimum(vek);
			for(int i(0); i < osnovni_period * koliko_puta; i++) {
			int vrijednost(vek.at(i % osnovni_period));
				for(int j(vrijednost - 1); j >= 0; j--) {
					if(j == vrijednost - 1) matrica[i][j] = maksimalni;
					else matrica[i][j] = matrica[i][j + 1] - 1;
				}
			}
			
			return matrica;
		}
		catch(...) {
			for(int i(0); i < koliko_puta * osnovni_period; i++) {
				delete[] matrica[i];
			}
			delete[] matrica;
			throw;
		}
	}
	catch(...) {
		throw;
	}
}

int main () {
	try {
		std::cout << "Unesite broj elemenata vektora: ";
		int n;
		std::cin >> n;
		std::cout << "Unesite elemente vektora: ";
		std::vector<int> vek(n);
		for(int i(0); i < n; i++) {
			std::cin >> vek.at(i);
		}
		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		bool f;
		std::cin >> f;
		int koliko_puta;
		int osnovni_period = period(vek);
		if(osnovni_period == -1) osnovni_period = vek.size();
		int **matrica = AlocirajFragmentirano(vek, koliko_puta);
		std::cout << "Dinamicki alocirana matrica: " << std::endl;
		for(int i(0); i < osnovni_period * koliko_puta; i++) {
			int vrijednost(vek.at(i % osnovni_period));
			for(int j(0); j < vrijednost; j++) {
				std::cout << std::setw(3) << std::left << matrica[i][j];
			}
			std::cout << std::endl;
		}
		for(int i(0); i < koliko_puta * osnovni_period; i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
	}
	
	catch(const char *poruka) {
		std::cout << "Izuzetak: " << poruka;
	}
	catch(std::domain_error e) {
		std::cout << "Izuzetak: " << e.what();
	}
	catch(...) {
		std::cout << "Izuzetak: " << "Neuspjela alokacija!";
	}
	
	return 0;
}