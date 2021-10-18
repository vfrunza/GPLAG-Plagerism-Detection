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
int **AlocirajFragmentirano(const std::vector<Tip> vektor, int &koliko_puta)
{
	int **dvo_pok(nullptr);
	if(vektor.size()==0) throw "Prazan vektor!";
	for(auto x: vektor) if(x<=0) throw std::domain_error("Neispravan vektor!");
	int period(0);
	for(int i(1); i<vektor.size(); i++) {
		bool periodicna(true);
		for(int j(0); j<vektor.size()-i; j++) {
			if(vektor.at(j)!=vektor.at(j+i)) periodicna=false;
		}
		if(periodicna) {
			period=i;
			break;
		}
	}
	int brojac(0);
	try {
		if(period==0) {
			period=vektor.size();
			koliko_puta=2;
		} else {
			koliko_puta=vektor.size()/period;
			if(vektor.size()%period!=0) koliko_puta++;
		}
		int najduzi(0);
		for(int i(0); i<period; i++) {
			if(vektor.at(i)>najduzi) najduzi=vektor.at(i);
		}
		dvo_pok=new int* [period*koliko_puta] {};
		for(int i(0); i<koliko_puta; i++) {
			for(int j(0); j<period; j++) {
				dvo_pok[i*period+j]=new int [vektor.at(j)];
				brojac++;
				for(int k(0); k<vektor.at(j); k++) dvo_pok[i*period+j][k]=najduzi-vektor.at(j)+1+k;
			}
		}
	} catch(std::bad_alloc) {
		for(int i(0); i<brojac; i++) delete[] dvo_pok[i];
		delete[] dvo_pok;
		throw;
	}
	return dvo_pok;
}

template <typename Tip>
int **AlocirajKontinualno(const std::vector<Tip> vektor, int &koliko_puta)
{
	int **dvo_pok(nullptr);
	if(vektor.size()==0) throw "Prazan vektor!";
	for(auto x: vektor) if(x<=0) throw std::domain_error("Neispravan vektor!");
	int period(0);
	for(int i(1); i<vektor.size(); i++) {
		bool periodicna(true);
		for(int j(0); j<vektor.size()-i; j++) {
			if(vektor.at(j)!=vektor.at(j+i)) periodicna=false;
		}
		if(periodicna) {
			period=i;
			break;
		}
	}
	try {
		if(period==0) {
			period=vektor.size();
			koliko_puta=2;
		} else {
			koliko_puta=vektor.size()/period;
			if(vektor.size()%period!=0) koliko_puta++;
		}
		dvo_pok=new int* [period*koliko_puta+1] {};
		int prostor(0);
		for(int i(0); i<period; i++) prostor+=koliko_puta*vektor.at(i);
		dvo_pok[0]=new int [prostor];
		for(int i(0); i<koliko_puta; i++) {
			for(int j(0); j<period; j++) {
				for(int k(vektor.at(j)); k>=1; k--) dvo_pok[i*period+j][vektor.at(j)-k]=k;
				dvo_pok[i*period+j+1]=dvo_pok[i*period+j]+vektor.at(j);
			}
		}
	} catch(std::bad_alloc) {
		delete[] dvo_pok[0];
		delete[] dvo_pok;
		throw;
	}
	return dvo_pok;
}


int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	try {
		std::vector<int> vektor(n);
		std::cout << "Unesite elemente vektora: ";
		for(int i(0); i<n; i++) std::cin >> vektor.at(i);
		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int k;
		while(!(std::cin >> k), !(k==0 || k==1));
		if(k==0) {
			int p;
			int **dvo_pok(AlocirajKontinualno(vektor, p));
			std::cout << "Dinamicki alocirana matrica: \n";
			int period(0);
			for(int i(1); i<vektor.size(); i++) {
				bool periodicna(true);
				for(int j(0); j<vektor.size()-i; j++) {
					if(vektor.at(j)!=vektor.at(j+i)) periodicna=false;
				}
				if(periodicna) {
					period=i;
					break;
				}
			}
			if(period==0) period=vektor.size();
			for(int i(0); i<p*period; i++) {
				int *pom(dvo_pok[i]);
				while(pom!=dvo_pok[i+1]) {
					std::cout << std::setw(2) << std::left << *pom << " ";
					pom++;
				}
				std::cout << std::endl;
			}
			delete[] dvo_pok[0];
			delete[] dvo_pok;
		} else {
			int p;
			int **dvo_pok(AlocirajFragmentirano(vektor, p));
			std::cout << "Dinamicki alocirana matrica: \n";
			int period(0);
			for(int i(1); i<vektor.size(); i++) {
				bool periodicna(true);
				for(int j(0); j<vektor.size()-i; j++) {
					if(vektor.at(j)!=vektor.at(j+i)) periodicna=false;
				}
				if(periodicna) {
					period=i;
					break;
				}
			}
			if(period==0) period=vektor.size();
			int najduzi(0);
			for(int i(0); i<period; i++) {
				if(vektor.at(i)>najduzi) najduzi=vektor.at(i);
			}
			for(int i(0); i<p; i++) {
				for(int j(0); j<period; j++) {
					for(int k(0); k<vektor.at(j); k++) {
						std::cout << std::setw(2) << std::left << dvo_pok[i*period+j][k] << " ";
					}
					std::cout << std::endl;
					delete[] dvo_pok[i*period+j];
				}
			}
			delete[] dvo_pok;
		}
	} catch(std::domain_error p) {
		std::cout << "Izuzetak: " << p.what() << std::endl;
	} catch(const char *p) {
		std::cout << "Izuzetak: " << p << std::endl;
	} catch(std::bad_alloc) {
		std::cout << "Izuzetak: Nedovoljno memorije!\n";
	}
	return 0;
}
