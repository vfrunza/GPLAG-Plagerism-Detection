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

template <typename Tip>
bool JelPeriodican(const std::vector<Tip> &vektor, int period)
{
	for(int i=0; i < vektor.size(); i++) {
		for(int j=i; j<vektor.size(); j+=period) {
			if(vektor.at(i) != vektor.at(j)) return false;
		}
	}
	return true;
}

template <typename Tip>
int Period(const std::vector<Tip> &vektor)
{
	for(int i = 1; i < vektor.size(); i++) {
		if(JelPeriodican(vektor, i)) return i;
	}
	return 0;
}
template<typename Tip>
int **AlocirajFragmentirano(const std::vector<Tip> &vektor, int &koliko_puta)
{
	if(vektor.size()==0) throw("Prazan vektor!");
	for(int i=0; i<vektor.size(); i++) {
		if(vektor.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	}
	int period=Period(vektor);

	if(period!=0) {
		int novaDuzina;
		if(vektor.size()%period!=0) {
			int dopuna=period-vektor.size()%period;
			novaDuzina = vektor.size()+dopuna;
		} else novaDuzina = vektor.size();

		koliko_puta=novaDuzina/period;
	} else {
		koliko_puta=2;
		period=vektor.size();
	}

	try {
		int **p;
		try {
			int suma(0);
			for(int i=0; i<period; i++) suma+=vektor.at(i);
			p=new int *[period*koliko_puta];
			for(int i=0; i<koliko_puta*period; i++) {
				p[i]=new int[vektor.at(i%period)];
			}
			for(int i=0; i<koliko_puta*period; i++) {
				for(int j=vektor.at(i%period)-1; j>=0; j--) {
					if(j==vektor.at(i%period)-1) p[i][j]=vektor.at(period-1);
					else p[i][j]=p[i][j+1] - 1;
				}
			}
			return p;
		} catch(...) {
			for(int i=0; i<period*koliko_puta; i++) delete[] p[i];
			delete[] p;
			throw;
		}
	} catch(...) {
		throw;
	}

}
template <typename Tip>
int **AlocirajKontinualno(const std::vector<Tip> &vektor, int &koliko_puta)
{
	if(vektor.size() == 0) throw ("Prazan vektor!");
	for(int i = 0; i < vektor.size(); i++) {
		if(vektor.at(i) <= 0) throw std::domain_error("Neispravan vektor!");
	}

	int period=Period(vektor);
	if(period!=0) {
		int novaDuzina;
		if(vektor.size()%period!=0) {
			int dopuna=period-vektor.size()%period;
			novaDuzina = vektor.size()+dopuna;
		} else novaDuzina = vektor.size();

		koliko_puta=novaDuzina/period;
	} else {
		koliko_puta = 2;
		period = vektor.size();
	}

	try {
		int **p;
		p = new int*[period*koliko_puta];
		try {
			int suma(0);
			for(int i=0; i<period; i++) suma+=vektor.at(i);
			p[0] = new int[suma*koliko_puta];
			for(int i=1; i<period*koliko_puta; i++) {
				p[i] = p[i-1] + vektor.at((i-1) % period);
			}
			for(int i=0; i < period * koliko_puta; i++) {
				for(int j=vektor.at(i%period) - 1; j >= 0; j--) {
					if(j==vektor.at(i%period)-1) p[i][j]=1;
					else p[i][j] = p[i][j+1] + 1;
				}
			}
			return p;
		} catch(...) {
			delete[] p;
			throw;
		}
	} catch(...) {
		throw;
	}
}

int main ()
{

	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;

	std::vector<int> vektor(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>vektor.at(i);
	}

	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int f;
	std::cin>>f;
//	while() std::cin>>f;

	int koliko_puta;
	try {
		int **pok;
		if(f==0) pok = AlocirajKontinualno(vektor, koliko_puta);
		if(f==1) pok = AlocirajFragmentirano(vektor, koliko_puta);
		std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
		int period(Period(vektor));

		if(f==0) {
			for(int i=0; i<period*koliko_puta; i++) {
				for(int j=0; j<pok[i][0]; j++)
					std::cout<<pok[i][j]<<"  ";
				std::cout<<std::endl;
			}
			delete[] pok[0];
			delete[] pok;
		}
		if(f==1) {
			for(int i=0; i<period*koliko_puta; i++) {
				for(int j=0; j<vektor.at(i%period); j++)
					std::cout<<pok[i][j]<<"  ";
				std::cout<<std::endl;
			}
			for(int i=0; i<koliko_puta*period; i++) delete[] pok[i];
			delete[] pok;
		}
	} catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	} catch(const char* izuzetak2) {
		std::cout<<"Izuzetak: "<<izuzetak2;
	}

	return 0;
}