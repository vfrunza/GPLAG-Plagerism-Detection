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
#include <algorithm>
#include <iomanip>
#include <new>

template<typename tip>
bool TestPerioda(std::vector<tip> v, int p)
{
	if(p>=v.size() || p<1) return false;
	else if(v[0]!=v[p]) return false;
	else if(v[0]==v[p]) {
		for(int i=1; i<(v.size()-p); i++)
			if(v[i]!=v[i+p]) return false;
	}
	return true;
}

template<typename cjel_tip>
int **AlocirajFragmentirano(const std::vector<cjel_tip> &v, int &koliko_puta)
{
	if(v.size()==0) throw "Prazan vektor!";
	int T(v.size());
	for(int i=1; i<v.size(); i++)
		if(TestPerioda(v, i)) {
			T=i;
			break;
		}
	//koliko puta
	if(T!=v.size()) {
		for(int i=0; i<v.size(); i++)
			if((T*i)>=v.size()) {
				koliko_puta=i;
				break;
			}
	} else if(T==v.size()) koliko_puta=2;
	for(int i=0; i<v.size(); i++) {
		if(v[i]<=0) throw std::domain_error ("Neispravan vektor!");
	}
	//alokacija matrice
	try {
		int **pok(new int*[T*koliko_puta] {});
		try {
			int vvel(0);
			auto pocetak(pok);
			for(int i=0; i<T*koliko_puta; i++) {
				pok[i]=new int[v[vvel]];
				vvel++;
				if(vvel==T) vvel=0;
			}
			vvel=0;
			for(int i=0; i<T*koliko_puta; i++) {
				int maax=int(*std::max_element(v.begin(), v.end()));
				for(int j=v[vvel]-1; j>=0; j--)
					pok[i][j]=maax--;
				vvel++;
				if(vvel==T) vvel=0;
			}
			return pocetak;
		} catch(...) {
			for(int i=0; i<v.size(); i++)
				delete[] pok[i];
			delete[] pok;
			throw;
		}
	} catch(...) {
		throw;
	}
}

template<typename cjel_tip>
int **AlocirajKontinualno(const std::vector<cjel_tip> &v, int &koliko_puta)
{
	if(v.size()==0) throw "Prazan vektor!";
	int T(v.size()), duzina(0);
	for(int i=1; i<v.size(); i++)
		if(TestPerioda(v, i)) {
			T=i;
			break;
		}
	//prosiriti vektor
	if(T!=v.size()) {
		for(int i=0; i<v.size(); i++)
			if((T*i)>=v.size()) {
				koliko_puta=i;
				break;
			}
	} else if(T==v.size()) koliko_puta=2;
	for(int i=0; i<T; i++) {
		if(v[i]<=0) throw std::domain_error ("Neispravan vektor!");
		duzina+=v[i];
	}
	//alokacija matrice
	try {
		int **pok(new int*[T*koliko_puta] {});
		try {
			auto pocetak(pok);
			pok[0]=new int[duzina*koliko_puta];
			int vvel(0);
			for(int i=1; i<T*koliko_puta; i++) {
				pok[i]=pok[i-1]+v[vvel];
				vvel++;
				if(vvel==T) vvel=0;
			}
			vvel=0;
			for(int i=0; i<T*koliko_puta; i++) {
				int br(1);
				for(int j=v[vvel]-1; j>=0; j--) {
					pok[i][j]=br++;
				}
				vvel++;
				if(vvel==T) vvel=0;
			}
			return pocetak;
		} catch(...) {
			delete[] pok[0];
			delete[] pok;
			throw;
		}
	} catch(...) {
		throw;
	}
}

int main ()
{
	int n, alok, koliko_puta;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	try {
		std::vector<int> v(n);
		std::cout<<"Unesite elemente vektora: ";
		for(int i=0; i<n; i++) std::cin>>v[i];
		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		std::cin>>alok;
		int period(v.size());
		for(int i=1; i<v.size(); i++) {
			if(TestPerioda(v, i)) {
				period=i;
				break;
			}
		}
		int **pok, vvel(0);
		if(alok==0) pok=AlocirajKontinualno(v, koliko_puta);
		else if(alok==1) pok=AlocirajFragmentirano(v, koliko_puta);
		std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
		for(int i=0; i<period*koliko_puta; i++) {
			for(int j=0; j<v[vvel]; j++) std::cout<<std::left<<std::setw(3)<<pok[i][j];
			std::cout<<std::endl;
			vvel++;
			if(vvel==period) vvel=0;
		}
		if(alok==1) {
			for(int i=0; i<period*koliko_puta; i++)
				delete[] pok[i];
		} else if(alok==0) delete[] pok[0];
		delete[] pok;
	} catch(std::bad_alloc izuz) {
		std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
	} catch(std::domain_error izuz2) {
		std::cout<<"Izuzetak: "<<izuz2.what()<<std::endl;
	} catch(const char poruka[]) {
		std::cout<<"Izuzetak: "<<poruka<<std::endl;
	}
	return 0;
}