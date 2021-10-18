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
#include <new>
#include <iomanip>

template <typename Tip>
bool Period (const std::vector<Tip> &v, int p) {
	for (int i=0; i<v.size()-p; i++) {
		if (v.at(i)!=v.at(i+p)) return false;
	}
	return true;
}

template <typename Tip>
int OsnovniPeriod (const std::vector<Tip> &v, int &koliko_puta) {
	int i;
	for (i=1; i<v.size(); i++) {
		if (Period(v, i)) break;
	}
	
	if (i==v.size()) koliko_puta=2;
	else if (v.size()%i) koliko_puta=v.size()/i+1;
	else koliko_puta=v.size()/i;
	
	return i;
}

template <typename Tip>
void ProvjeriVrijednosti (const std::vector<Tip> &v) {
	if (!v.size()) throw ("Prazan vektor!");
	for (int i=0; i<v.size(); i++) if (v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	return;
}

template <typename Tip>
int **AlocirajFragmentirano (const std::vector<Tip> &v, int &koliko_puta) {
	
	ProvjeriVrijednosti(v);
	
	int period(OsnovniPeriod(v, koliko_puta));
	
	
	Tip **matrica(nullptr);
	
	try {
		matrica=new Tip*[koliko_puta*period]{};
		
		try {
			for (int i=0; i<koliko_puta*period; i++) matrica[i]=new Tip[v.at(i%period)];
		}
		catch(...) {
			if (matrica!=nullptr) {
				for (int i=0; i<koliko_puta*period; i++) delete[] matrica[i];
				delete[] matrica;
			}
			throw;
		}
		
		Tip max(0);
		for (int i=0; i<v.size(); i++) if (v.at(i)>max) max=v.at(i);
		
		for (int i=0; i<koliko_puta*period; i++) {
			for (int j=0; j<v.at(i%period); j++) {
				matrica[i][j]=std::abs(v.at(i%period)-max)+1+j;
			}
		}
	}
	catch(...) {
		throw;
	}
	return matrica;
	
}

template <typename Tip>
int **AlocirajKontinualno (const std::vector<Tip> v, int &koliko_puta) {
	
	ProvjeriVrijednosti(v);
	
	int period(OsnovniPeriod(v, koliko_puta));
	
	int velicina(0);
	for (int i=0; i<koliko_puta*period; i++) velicina+=v.at(i%period);
	
	Tip **matrica(nullptr);

	try {
		matrica=new Tip*[koliko_puta*period]{};
		try {
			matrica[0]=new Tip[velicina];
			for (int i=1; i<koliko_puta*period; i++) matrica[i]=matrica[i-1]+v.at((i-1)%period);
		}
		catch(...) {
			if (matrica!=nullptr) {
				delete[] matrica[0];
				delete[] matrica;
			}
			throw;
		}
		for (int i=0; i<koliko_puta*period; i++) {
			for (int j=0; j<v.at(i%period); j++) {
				matrica[i][j]=v.at(i%period)-j;
			}
		}
	}
	catch(...) {
		throw;
	}
	return matrica;
}


int main ()
{
	std::vector<int> v;
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	v.resize(n);
	std::cout << "Unesite elemente vektora: ";
	for (auto &x: v) std::cin >> x;
	
	int alokacija;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> alokacija;
	
	int **matrica, koliko_puta, period(OsnovniPeriod(v, koliko_puta));
	
	try {
		if (alokacija) matrica=AlocirajFragmentirano(v, koliko_puta);
		else matrica=AlocirajKontinualno(v, koliko_puta);
		
		std::cout << "Dinamicki alocirana matrica: " << std::endl;
		
		for (int i=0; i<koliko_puta*period; i++) {
			for (int j=0; j<v.at(i%period); j++) {
				std::cout << std::setw(3) << std::left << matrica[i][j];
			}
			std::cout << std::endl;
		}
		
		if (alokacija) for (int i=0; i<koliko_puta*period; i++) delete[] matrica[i];
		else delete[] matrica[0];
		delete[] matrica;
		
	}
	catch(std::bad_alloc) { std::cout << "Nedovoljno memorije"; }
	catch(const char* izuzetak) { std::cout << "Izuzetak: " << izuzetak; }
	catch(std::exception &izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	return 0;
}