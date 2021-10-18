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
#include <algorithm>
#include <iterator>
#include <cmath>
#include <stdexcept>
#include <vector>


template <typename IterTip1, typename IterTip2, typename IterTip3, typename FunTip1, typename FunTip2>
void SortirajPodrucjeVrijednosti (IterTip1 p1, IterTip1 k1,IterTip2 p2, IterTip3 p3,
                                  FunTip1 f1, FunTip2 f2)
{
	std::sort (p1,k1,f2);
	auto it(p2); 
	std::advance(it, std::distance(p1, k1));
	std::sort (p2, it, f2); 

	auto i(p1);
	auto j(p2); 
	auto k3(p3);
	auto p33(p3);
	std::advance(k3, std::distance(p1, k1));
	while (i != k1) {
		auto tmp(f1(*i, *j));
		i++;
		j++;

		auto pozicija(std::find(p3,k3,tmp));
		if(pozicija==k3)
			throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");

		auto pomocna(*p33);
		*p33=*pozicija;
		*pozicija=pomocna;
		p33++;

	}
}

bool Prost(int x)
{
	for(int i=2; i<sqrt(x); i++) {
		if(x%i == 0) return false;
	}
	return true;
}


int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int br_el;
	std::cin >> br_el;

	std::vector<int>v1(br_el);
	std::vector<int>v2(br_el);
	std::vector<int>v3(br_el);

	std::cout << "Unesite elemente prvog vektora: ";
	for(int i=0; i<br_el; i++) {
		int unos;
		std::cin >> unos;
		int j;
		for(j=0; j<i; j++) {
			if (v1[j] == unos) break;
		}
		if(j==i) v1[i] = unos;
		else i--;
	}
	std::cout << "Unesite elemente drugog vektora: ";
	for(int i=0; i<br_el; i++) {
		int unos;
		std::cin >> unos;
		int j;
		for(j=0; j<i; j++) {
			if (v2[j] == unos) break;
		}
		if(j==i) v2[i] = unos;
		else i--;
	}
	std::cout << "Unesite elemente treceg vektora: ";
	for(int i=0; i<br_el; i++) {
		int unos;
		std::cin >> unos;
		int j;
		for(j=0; j<i; j++) {
			if (v3[j] == unos) break;
		}
		if(j==i) v3[i] = unos;
		else i--;
	}

	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(),
		[](int x, int y) {
			return -2*x + y;
		}, [](int x, int y) {
			int br_prostih1(0), br_prostih2(0);
			int x1(x), y1(y);
			for(int i=2; i< abs(x); i++) {
				if(Prost(i) && x1%i==0) {
					while (x1%i == 0) {
						x1/=i;
						br_prostih1++;
					}
				}
				if (abs(x1) == 1) break;
			}
			for(int i=2; i< abs(y); i++) {
				if(Prost(i) && y1%i==0) { 
					while (y1%i == 0) {
						y1/=i;
						br_prostih2++;
					}
				}
				if (abs(y1) == 1) break;
			}

			if(br_prostih1==br_prostih2) return x > y;
			return br_prostih1 > br_prostih2;
		});

		std::cout << std::endl << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
		auto it1(v1.begin());
		auto it2(v2.begin());
		auto it3(v3.begin());
		while (it1 != v1.end()) {
			std::cout << "f(" << *it1 << ", " << *it2 << ") = " << *it3 << std::endl;
			it1++;
			it2++;
			it3++;
		}
	} catch (std:: logic_error izuzetak) {
		std::cout << std::endl << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	return 0;
}