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
#include <new>
#include <iomanip>
#include <stdexcept>
template <typename IntTip>
int Periodicnost(const std::vector<IntTip> &v)
{
	int p(0), period(0);
	for(;;) {
		p++;
		if(p>=v.size()) break;
		bool b(true);
		for(int i=0; i<v.size()-p; i++) {
			if(v.at(i)!=v.at(i+p)) {
				b=false;
				break;
			}
		}
		if(b) {
			period=p;
			break;
		}
	}
	return period;
}
template <typename IntTip>
int** AlocirajFragmentirano(const std::vector<IntTip> &v, int &koliko_puta)
{
	if(v.size()==0) throw ("Prazan vektor!");
	int period=Periodicnost(v),granica(0);
	if(period==0) {
		koliko_puta=2;
		granica=v.size();
	} else {
		koliko_puta=v.size()/period;
		if(v.size()/double(period)!=v.size()/period) koliko_puta++;
		granica=period;
	}
	try {
		int** a(nullptr);
		a=new int*[granica*koliko_puta] {};
		try {
			int max;
			for(int i=0; i<v.size(); i++) {
				if(v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
				if(i==0) max=v.at(i);
				else if(v.at(i)>max) max=v.at(i);
			}
			for(int i=0; i<granica*koliko_puta; i++) {
				int br_elemenata=i%granica;
				a[i]=new int[v.at(br_elemenata)];
				int temp=v.at(br_elemenata);
				for(int j=0; j<v.at(br_elemenata); j++) {
					a[i][j]=max-temp+1;
					temp--;
				}
			}

		} catch(std::domain_error e) {
			for(int i=0; i<period*koliko_puta; i++) delete[] a[i];
			delete[] a;
			throw;
		} catch(std::bad_alloc) {
			for(int i=0; i<period*koliko_puta; i++) delete[] a[i];
			delete[] a;
			throw;
		}
		return a;
	} catch(std::bad_alloc) {
		throw;
	}
}
template <typename IntTip>
int** AlocirajKontinualno(const std::vector<IntTip> &v, int &koliko_puta)
{
	if(v.size()==0) throw ("Prazan vektor!");
	int period=Periodicnost(v),granica(0);
	if(period==0) {
		koliko_puta=2;
		granica=v.size();
	} else {
		koliko_puta=v.size()/period;
		if(v.size()/double(period)!=v.size()/period) koliko_puta++;
		granica=period;
	}
	try {
		int** a(nullptr);
		a=new int*[granica*koliko_puta] {};
		try {
			int velicina(0);
			int max;
			for(int i=0; i<granica; i++) {
				if(v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
				if(i==0) max=v.at(i);
				else if(v.at(i)>max) max=v.at(i);
				velicina+=v.at(i);
			}
			velicina*=koliko_puta;
			a[0]=new int[velicina];
			for(int i=1; i<granica*koliko_puta; i++) {
				int br_elemenata=(i-1)%granica;
				a[i]=a[i-1]+v.at(br_elemenata);
			}
			for(int i=0; i<granica*koliko_puta; i++) {
				int br_elemenata=i%granica;
				int temp=v.at(br_elemenata);

				for(int j=0; j<v.at(br_elemenata); j++) {
					a[i][j]=temp--;
				}
			}

		} catch(std::domain_error e) {
			delete[] a;
			throw;
		} catch(std::bad_alloc) {
			delete[] a;
			throw;
		}
		return a;
	} catch(std::bad_alloc) {
		throw;
	}
}

int main ()
{
	try {
		int velicina, koliko_puta;
		std::cout<<"Unesite broj elemenata vektora: ";
		std::cin>>velicina;
		std::vector<int> v(velicina);
		std::cout<<"Unesite elemente vektora: ";
		for(auto &i:v) std::cin>>i;
		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int f;
		std::cin>>f;
		int period=Periodicnost(v);
		if(period==0) period=v.size();
		if(f==1) {
			auto a=AlocirajFragmentirano(v,koliko_puta);
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i=0; i<period*koliko_puta; i++) {
				int b=i%period;
				for(int j=0; j<v.at(b); j++) {
					std::cout<<std::left<<std::setw(3)<<a[i][j];
				}
				std::cout<<std::endl;
			}
			for(int i=0; i<period*koliko_puta; i++) delete[] a[i];
			delete[] a;
		} else if(f==0) {
			auto a=AlocirajKontinualno(v,koliko_puta);
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i=0; i<period*koliko_puta; i++) {
				int b=i%period;
				for(int j=0; j<v.at(b); j++) {
					std::cout<<std::left<<std::setw(3)<<a[i][j];
				}
				std::cout<<std::endl;
			}
			delete[] a[0];
			delete[] a;
		}

	} catch(std::domain_error e) {
		std::cout<<"Izuzetak: "<<e.what();
	} catch(std::bad_alloc) {

	} catch(const char e[]) {
		std::cout<<"Izuzetak: "<<e;
	}











	return 0;
}