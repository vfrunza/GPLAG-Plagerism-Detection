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
#include <vector>
#include <cmath>

bool Prost(int x) {
	if (x<2) return false;
	for (int i=2; i<=std::sqrt(x); i++) {
		if (x%i==0) return false;
	}
	return true;
}

int BrojProstihFaktora(int broj) {
	if (broj<2) return 0;
	int ukupno(0);
	for (int i=2; i<=broj; i++) {
		int a(broj);
		while (a!=1 && Prost(i)==true && a%i==0) {
			ukupno++;
			a/=i;
		}
	}
	return ukupno;
}

bool SortirajOpadajuce(int x, int y) {
	return (BrojProstihFaktora(x)>BrojProstihFaktora(y) || (BrojProstihFaktora(x)==BrojProstihFaktora(y) && x>y));
}

int f(int x, int y) {
	return x*(-2)+y;
}

template <typename IterTip1, typename IterTip2, typename IterTip3>
	void SortirajPodrucjeVrijednosti(IterTip1 pocetak1, IterTip1 iza_kraja1,
	IterTip2 pocetak2, IterTip3 pocetak3,
	typename std::remove_reference<decltype(*pocetak3)>::type fun
	(typename std::remove_reference<decltype(*pocetak1)>::type, typename std::remove_reference<decltype(*pocetak1)>::type), 
	bool Kriterij
	(typename std::remove_reference<decltype(*pocetak1)>::type, typename std::remove_reference<decltype(*pocetak1)>::type)) {
		int duzina(iza_kraja1-pocetak1);
		IterTip2 iza_kraja2(pocetak2+duzina);
		IterTip3 iza_kraja3(pocetak3+duzina);
		std::sort(pocetak1, iza_kraja1, Kriterij);
		std::sort(pocetak2, iza_kraja2, Kriterij);
		typename std::remove_reference<decltype(*pocetak1)>::type a;
		typename std::remove_reference<decltype(*pocetak2)>::type b;
		IterTip1 zapamti1(pocetak1);
		IterTip2 zapamti2(pocetak2);
		IterTip3 zapamti3(pocetak3);
		while (pocetak1!=iza_kraja1 && pocetak2!=iza_kraja2) {
			a=*pocetak1;
			b=*pocetak2;
			zapamti3=pocetak3;
			bool pronadjeno(false);
			while (pocetak3!=iza_kraja3) {
				typename std::remove_reference<decltype(*pocetak3)>::type rezultat=fun(a, b);
				if (rezultat==*pocetak3) {
					typename std::remove_reference<decltype(*pocetak3)>::type temp=*pocetak3;
					int pomaknuto(pocetak1-zapamti1);
					*pocetak3=*(zapamti3+pomaknuto);
					*(zapamti3+pomaknuto)=temp;
					pronadjeno=true;
					pocetak3=zapamti3;
					break;
				}
				pocetak3++;
			}
			pocetak3=zapamti3;
			if (pronadjeno==false) {
				throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
			}
			pocetak1++;
			pocetak2++;
		}
		pocetak1=zapamti1;
		pocetak2=zapamti2;
	}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::vector<int> v1, v2, v3;
	std::cout << "Unesite elemente prvog vektora: ";
	for (int i=0; i<n; i++) {
		int broj;
		std::cin >> broj;
		bool vec_postoji(false);
		for (int j=0; j<i; j++) {
			if (broj==v1.at(j)) {
				vec_postoji=true;
				i--;
				break;
			}
		}
		if (vec_postoji==false) v1.push_back(broj);
	}
	std::cout << "Unesite elemente drugog vektora: ";
	for (int i=0; i<n; i++) {
		int broj;
		std::cin >> broj;
		bool vec_postoji(false);
		for (int j=0; j<i; j++) {
			if (broj==v2.at(j)) {
				vec_postoji=true;
				i--;
				break;
			}
		}
		if (vec_postoji==false) v2.push_back(broj);
	}
	std::cout << "Unesite elemente treceg vektora: ";
	for (int i=0; i<n; i++) {
		int broj;
		std::cin >> broj;
		bool vec_postoji(false);
		for (int j=0; j<i; j++) {
			if (broj==v3.at(j)) {
				vec_postoji=true;
				i--;
				break;
			}
		}
		if (vec_postoji==false) v3.push_back(broj);
	}
	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), f, SortirajOpadajuce);
		std::cout << std::endl << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
		for (int i=0; i<n; i++) {
			std::cout << "f(" << v1.at(i) << ", " << v2.at(i) << ") = " << v3.at(i) << std::endl;
		}
	}
	catch(std::logic_error e) {
		std::cout << std::endl << "Izuzetak: " << e.what();
	}
	return 0;
}