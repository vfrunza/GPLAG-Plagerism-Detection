#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

template <typename tip>
int periodican_niz(const std::vector<tip> &v)
{
	bool p = false;

	for(int i=1; i<v.size(); i++) {
		for(int j=0; j<v.size(); j++) {
			if(j+i<v.size()) p = v[j]==v[j+i];
			if(!p) break;
		}
		if(p) return i;
	}

	return 0;
}

template <typename T>
T **AlocirajFragmentirano(const std::vector<T> &v, int &koliko_puta)
{
	if(!v.size())
		throw "Prazan vektor!";

	for(auto i : v)
		if(i<=0) throw std::domain_error("Neispravan vektor!");

	int period = periodican_niz(v);
	int redova = 0;

	if(period) {
		koliko_puta=std::ceil(v.size()/(double)period);
	} else {
		koliko_puta = 2;
		period = v.size();
	}

	redova = koliko_puta*period;
	T najveci = *std::max_element(v.begin(), v.end());

	T **matrica(new T*[redova] {});

	try {
		for(int i=0; i<redova;) {
			for(int j=0; j<period; j++, i++)
				matrica[i] = new T[v[j]];
		}

		int index = 0;
		for(int i=0; i<redova; i++) {
			int k = najveci;

			if(index==period) index=0;
			for(int j=v[index]-1; j>=0; j--)
				matrica[i][j] = k--;
			index++;
		}
	} catch(...) {
		for(int i = 0; i < redova; i++)
			delete[] matrica[i];
		delete[] matrica;
		throw;
	}

	return matrica;
}

template <typename T>
T **AlocirajKontinualno(const std::vector<T> &v, int &koliko_puta)
{
	if(!v.size()) throw "Prazan vektor!";

	for(auto i : v)
		if(i<=0) throw std::domain_error("Neispravan vektor!");

	int period = periodican_niz(v);
	int redova = 0;

	if(period) {
		koliko_puta=std::ceil(v.size()/(double)period);
	} else {
		koliko_puta = 2;
		period = v.size();
	}

	redova = koliko_puta*period;

	int elemenata = 0;
	for(int i=0; i<period; i++)
		elemenata+=v[i];

	elemenata*=koliko_puta;

	T **a = new T*[redova];
	try {
		a[0] = new T[elemenata];

		int index = 0;
		for(int i = 1; i < redova; i++) {
			if(index==period) index=0;
			a[i] = a[i - 1] + v[index];
			index++;
		}

		index = 0;
		for(int i=0; i<redova; i++) {
			if(index==period) index=0;
			int k=1;
			for(int j=v[index]-1; j>=0; j--)
				a[i][j] = k++;
			index++;
		}
	} catch(...) {
		delete[] a;
		throw;
	}

	return a;
}

int main ()
{

	try {
		int n;
		std::cout << "Unesite broj elemenata vektora: ";
		std::cin >> n;
		std::vector<int> v;
		std::cout << "Unesite elemente vektora: ";

		for(int i=0; i<n; i++) {
			int temp;
			std::cin >> temp;
			v.push_back(temp);
		}

		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		std::cin >> n;

		int **matrica = nullptr;
		int koliko_puta = 0;
		if(n) matrica = AlocirajFragmentirano(v, koliko_puta);
		else matrica = AlocirajKontinualno(v, koliko_puta);

		std::cout << "Dinamicki alocirana matrica: " << std::endl;

		int redova = 0;
		int period = 0;

		if(!periodican_niz(v)) period = v.size();
		else period = std::ceil(v.size()/(double)koliko_puta);

		redova = koliko_puta*period;

		int index = 0;

		for(int i=0; i<redova; i++) {
			if(index==period)
				index=0;
			for(int j=0; j<v[index]; j++) {
				std::cout << std::left << std::setw(2) << matrica[i][j] << " ";
			}
			std::cout << std::endl;
			index++;
		}

		if(n) for(int i = 0; i < redova; i++) delete[] matrica[i];
		else delete[] matrica[0];

		delete[] matrica;

	} catch(const char poruka[]) {
		std::cout << "Izuzetak: " << poruka;
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}

	return 0;
}