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
#include <cmath>
int max(std::vector<int> v)
{
	int m(v.at(0));
	for(int i(0); i<v.size(); i++)if(v.at(i)>m)m=v.at(i);
	return m;
}
int OdrediOsnovniPeriod(std::vector<int>);
int Suma(const std::vector<int> v, int koliko_puta)
{
	int suma(0);
	for(int j(0); j<koliko_puta; j++) {
		if(OdrediOsnovniPeriod(v)!=0)
			for(int i(0); i<OdrediOsnovniPeriod(v); i++) suma+=v.at(i);
		else
			for(int i(0); i<v.size(); i++) suma+=v.at(i);
	}
	return suma;
}
bool TestPerioda(std::vector<int> v, int p )
{
	const double nestomalo(0.000001);
	if(v.size()<=p or p < 1 ) return false;
	for(int i(0); i<v.size()-p; i++) {
		if(fabs(v.at(i)-v.at(i+p))>nestomalo) return false;
	}
	return true;
}

int OdrediOsnovniPeriod(std::vector<int> v)
{
	for(int i(0); i<v.size(); i++) {
		if(TestPerioda(v,i)==true) {
			return i;
		}
	}
	return v.size();
}

int VratiKolikoPuta(const std::vector<int> &v )
{
	int koliko_puta(0);
	int OsnovniPeriod(OdrediOsnovniPeriod(v));
	if(OsnovniPeriod==v.size()) return 2;

	for(int i(0); i<v.size(); i++) {
		if(koliko_puta*OsnovniPeriod>v.size()-OsnovniPeriod) {
			koliko_puta++;
			return koliko_puta;
		}
		for(int j(0); j<OsnovniPeriod-1; j++) {
			i++;
		}
		koliko_puta++;
	}
	return koliko_puta;
}

template<typename Tip>
int**AlocirajKontinualno( const std::vector<Tip> &v, int &koliko_puta)
{
	if(v.size()==0) throw("Prazan vektor!");
	for(int i(0); i<v.size(); i++) {
		if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	}
	int **pok=nullptr;
	koliko_puta=VratiKolikoPuta(v);
	try {
		pok=new int*[OdrediOsnovniPeriod(v)*koliko_puta] {};
	} catch(std::bad_alloc) {
		throw;
	}
	try {
		int sum(Suma(v,koliko_puta));
		pok[0]= new int[sum];
	} catch(std::bad_alloc) {
		delete[] pok;
		throw;
	}
	int j(0);
	for(int i(1); i<koliko_puta*OdrediOsnovniPeriod(v); i++) {
		pok[i]=pok[i-1]+v.at(j);
		j++;
		if(j==OdrediOsnovniPeriod(v)) j=0;
	}

	int k(0);
	for(int i(0); i<koliko_puta*OdrediOsnovniPeriod(v); i++) {
		for(int j(0); j<v.at(k); j++) {
			pok[i][j]=v.at(k)-j;
		}
		k++;
		if(k==OdrediOsnovniPeriod(v)) k=0;
	}

	return pok;
}
template<typename Tip>
int**AlocirajFragmentirano( const std::vector<Tip> &v, int &koliko_puta)
{
	if(v.size()==0)throw ("Prazan vektor!");
	for(int i(0); i<v.size(); i++) {
		if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	}
	koliko_puta=VratiKolikoPuta(v);
	int** pok=nullptr;
	try {
		pok= new int*[OdrediOsnovniPeriod(v)*koliko_puta] {};
	} catch(std::bad_alloc) {
		throw;
	}
	try {
		int j(0);
		for(int i(0); i<koliko_puta*OdrediOsnovniPeriod(v); i++) {
			pok[i]=new int [v.at(j)];
			j++;
			if(j==OdrediOsnovniPeriod(v)) j=0;
		}
	} catch(std::bad_alloc) {
		for(int i(0); i<OdrediOsnovniPeriod(v)*koliko_puta; i++) delete[] pok[i];
		delete[] pok;
		throw;
	}
	int m(0);
	for(int i(0); i<koliko_puta*OdrediOsnovniPeriod(v); i++) {
		int p(0);
		for(int j(v.at(m)-1); j>=0; j--) {
			pok[i][j]=max(v)-p;
			p++;
		}
		m++;
		if(m==OdrediOsnovniPeriod(v)) m=0;
	}

	return pok;
}
int main ()
{
	try {
		std::cout << "Unesite broj elemenata vektora: " ;
		int n;
		std::cin >> n;
		std::cout << "Unesite elemente vektora: " ;
		std::vector<int> v;
		for(int i(0); i<n; i++) {
			int x;
			std::cin >> x;
			v.push_back(x);
		}
		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: " ;
		int k;
		std::cin >> k;
		int**pok(nullptr);
		int koliko_puta;
		if(k==0) {
			pok=AlocirajKontinualno(v,koliko_puta);
			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			int m(0);
			for(int i(0); i<koliko_puta*OdrediOsnovniPeriod(v); i++) {
				for(int j(0); j<v.at(m); j++) {
					std::cout <<std::left<<std::setw(3)<< pok[i][j] ;
				}
				m++;
				if(m==OdrediOsnovniPeriod(v))m=0;
				std::cout  << std::endl;
			}
			delete[] pok[0];
			delete[] pok;
		} else {
			pok=AlocirajFragmentirano(v,koliko_puta);
			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			int m(0);
			for(int i(0); i<koliko_puta*OdrediOsnovniPeriod(v); i++) {
				for(int j(0); j<v.at(m); j++) {
					std::cout <<std::left<<std::setw(3)<< pok[i][j] ;
				}
				m++;
				if(m==OdrediOsnovniPeriod(v)) m=0;
				std::cout  << std::endl;
			}
			for(int i(0); i<koliko_puta*OdrediOsnovniPeriod(v); i++) delete[] pok[i];
			delete[] pok;
		}
	} catch(std::domain_error poruka) {
		std::cout <<"Izuzetak: "<< poruka.what() << std::endl;
	} catch(std::bad_alloc) {
		std::cout << "Problem sa memorijom" << std::endl;
	} catch(...) {
		std::cout << "Izuzetak: Prazan vektor!" << std::endl;
	}
	return 0;
}