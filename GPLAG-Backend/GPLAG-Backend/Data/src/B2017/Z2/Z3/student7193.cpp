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

template <typename T>
bool periodP (std::vector<T> v, int p) {
	for (int i = 0; i < v.size()-p; i++) {
		if (v[i] != v[i+p]) {
			return false;
		}
	}
	return true;
}

template <typename T>
int period (std::vector<T> v) {
	int p(1);
	while (p != v.size()) {
		if (periodP(v, p)) {
			return p;
		} else {
			p++;
		}
	}
	if (p == v.size()) {
		return 0;
	}
	return 0;
}

template <typename T>
int maksimum(std::vector<T> v) {
	int max = v[0];
	for (auto i : v) {
		if (max < i) {
			max = i;
		}
	}
	return max;
}

template <typename T>
int** AlocirajFragmentirano (std::vector<T>& v, int& koliko_puta) {
	if (v.size() == 0) {
		throw "Prazan vektor!";
	}
	
	for (auto i : v) {
		if (i <= 0) {
			throw std::domain_error ("Neispravan vektor!");
		}
	}
	
	int periodVektora(period(v));
	
	if (periodVektora == 0) { //nije periodican --> duplo prosiriti
		int x(v.size());
		for (int i = 0; i < x; i++) {
			v.push_back(v[i]);
		}
		koliko_puta = 2;
		
	} else { //jeste periodican --> prosiriti ako treba
		int kolikoDodati;
		if (v.size()%periodVektora == 0) {
			kolikoDodati = 0;
		} else {
			kolikoDodati = periodVektora - v.size()%periodVektora;
		}
		koliko_puta = (v.size() + kolikoDodati) / periodVektora;
		
		while (kolikoDodati > 0) {
			v.push_back(v[periodVektora - kolikoDodati]);
			kolikoDodati--;
		}
		
	}
	
	int** matrica(new int*[v.size()]);
	for (int i = 0; i < v.size(); i++) {
		matrica[i] = new int[v[i]];
		int x(maksimum(v) - v[i] + 1);
		for (int j = 0; j < v[i]; j++) {
			matrica[i][j] = x++;
		}
	}
	
	
	
	return matrica;	
}

template <typename T>
int** AlocirajKontinualno (std::vector<T>& v, int& koliko_puta) {
	if (v.size() == 0) {
		throw "Prazan vektor!";
	}
	for (auto i : v) {
		if (i <= 0) {
			throw std::domain_error ("Neispravan vektor!");
		}
	}
	
	int periodVektora(period(v));
	
	if (periodVektora == 0) {
		int x(v.size());
		for (int i = 0; i < x; i++) {
			v.push_back(v[i]);
		}
		koliko_puta = 2;
	} else {
		int kolikoDodati;
		if (v.size()%periodVektora == 0) {
			kolikoDodati = 0;
		} else {
			kolikoDodati = periodVektora - v.size()%periodVektora;
		}
		while (kolikoDodati > 0) {
			v.push_back(v[periodVektora - kolikoDodati]);
			kolikoDodati--;
		}
	}
	
	int** matrica, brojElemenata(0);	
	
	for (int i = 0; i < v.size(); i++) {
		brojElemenata += v[i];
	}
	
	matrica = new int*[v.size()];
	matrica[0] = new int[brojElemenata];
	for (int i = 1; i < v.size(); i++) {
		matrica[i] = matrica[i-1] + v[i-1];
	}
	
	for (int i = 0; i < v.size(); i++) {
		int x(v[i]);
		for (int j = 0; j < v[i]; j++) {
			matrica[i][j] = x--;
		}
	}
	
	return matrica;
}

int main ()
{
	try {
		std::vector<int> v;
		int brojElemenata, f;
		std::cout << "Unesite broj elemenata vektora: ";
		std::cin >> brojElemenata;
		v.resize(brojElemenata);
		std::cout << "Unesite elemente vektora: ";
		for (int i = 0; i < brojElemenata; i++) {
			std::cin >> v[i];
		}
		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		std::cin >> f;
		
		int** matrica;
		if (f == 1) {
			matrica = AlocirajFragmentirano(v, brojElemenata);
		} else if (f == 0) {
			matrica = AlocirajKontinualno(v, brojElemenata);
		}
		std::cout << "Dinamicki alocirana matrica:" << std::endl;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i]; j++) {
				std::cout << std::left << std::setw(3) << matrica[i][j] ;
			}
			std::cout << std::endl;
		}
		
		if (f == 1) {
			for (int i = 0; i < v.size(); i++) {
				delete[] matrica[i];
			}
			delete[] matrica;
		} else if (f == 0) {
			delete[] matrica[0];
			delete[] matrica;
		}
		
	}
	catch (std::domain_error e) {
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	catch (const char e[]) {
		std::cout << "Izuzetak: " << e << std::endl;
	}
	
	
	return 0;
}