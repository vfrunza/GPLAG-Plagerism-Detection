/*B 2017/2018, Zadaća 2, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <algorithm>
#include<cmath>
#include <vector>

int funkcija(int x, int y)
{
	int a(y-2*x);
	return a;
}

bool prost(int a)
{
	int brojac(0);
	a=std::abs(a);
	for(int i=2; i<=std::sqrt(a); i++) {
		if(a%i==0) brojac++;
	}
	if(brojac==0) return true;
	return false;
}

int broj_prostih_faktora(int a)
{
	int brojac(0);
	for(int i=2; i<=a; i++) {
		if((a%i==0) && prost(i)) {
			int broj(a);
			while(broj!=0) {
				if((broj%i==0) && prost(i)) brojac++;
				broj/=i;
			}
		}
	}
	return brojac;
}

bool kriterij(int a, int b)
{
	if(broj_prostih_faktora(a)>broj_prostih_faktora(b)) return true;
	if(broj_prostih_faktora(a)==broj_prostih_faktora(b) && a>b) return true;
	return false;
}

template <typename Tip1, typename Tip2, typename Tip3>
void  SortirajPodrucjeVrijednosti(Tip1 p1, Tip1 p2, Tip2 q1, Tip3 z1,
                                  typename std::remove_reference<decltype(*z1)>::type prva (typename std::remove_reference<decltype(*p1)>::type,typename std::remove_reference<decltype(*q1)>::type),
                                  bool druga(typename std::remove_reference<decltype(*p1)>::type,typename std::remove_reference<decltype(*q1)>::type))
{
	decltype(p1) a(p1);
	int broj(0);
	while(a!=p2) {
		a++;
		broj++;
	}

	decltype(q1) q2(q1+broj);
	std::sort(p1, p2, druga);
	std::sort(q1, q2, druga);
	decltype(z1) t(z1);

	typename std::remove_reference<decltype(*z1)>::type rezultat;

	for(int i=0; i<broj; i++) {
		rezultat=prva(*p1,*q1);
		if(std::count(z1,z1+broj,rezultat)==0) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		else {
			for(int j=0; j<broj; j++) {
				if(*t==rezultat) {
					decltype(z1) zamjena(z1);
					int a(0);
					while(a++<i) zamjena++;
					typename std::remove_reference<decltype(*z1)>::type pomocna(*zamjena);
					*zamjena=*t;
					*t=pomocna;
				}
				t++;
			}
		}
		p1++;
		q1++;
		t=z1;
	}
}


int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int n;
	std::cin >> n;
	std::vector<int> S1;
	std::vector<int> S2;
	std::vector<int> S3;
	int unos;
	std::cout << "Unesite elemente prvog vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >>unos ;
		if(std::count(S1.begin(), S1.begin()+i, unos)!=0) {
			i--;
			continue;
		}
		S1.push_back(unos);
	}
	std::cout << "Unesite elemente drugog vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >>unos ;
		if(std::count(S2.begin(), S2.begin()+i, unos)!=0) {
			i--;
			continue;
		}
		S2.push_back(unos);
	}
	std::cout << "Unesite elemente treceg vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >>unos ;
		if(std::count(S3.begin(), S3.begin()+i, unos)!=0) {
			i--;
			continue;
		}
		S3.push_back(unos);
	}
	std::cout << std::endl;
	try {
		SortirajPodrucjeVrijednosti(S1.begin(), S1.end(), S2.begin(), S3.begin(), funkcija, kriterij);
		std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
		for(int i=0; i<n; i++) {
			std::cout << "f("<<S1.at(i)<<", "<< S2.at(i)<<") = " <<S3.at(i) << std::endl;
		}
	} catch(std::logic_error greska) {
		std::cout << "Izuzetak: "<< greska.what() << std::endl;
	}

	return 0;
}