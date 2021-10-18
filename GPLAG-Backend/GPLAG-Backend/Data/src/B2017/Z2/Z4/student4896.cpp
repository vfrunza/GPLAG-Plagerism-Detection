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
#include <algorithm>
#include <vector>
#include <cmath>
#include <type_traits>

template <typename Tip1, typename Tip2>

Tip2 f(Tip1 x, Tip1 y)
{
	Tip2 rez;
	rez=-2*x+y;
	return rez;
}

template <typename Tip>

bool f1(Tip x, Tip y)
{
	Tip x1(x), y1(y);
	int br_pr_f(0);
	if(x1==0) br_pr_f=0;
	else if(x1>0){
		int i(2);
		while(x1!=1) {
			if(x1%i==0) {
				x1/=i;
				br_pr_f++;
			} else {
				i++;
			}
		}
	}
	int br_pr_f1(0);
	if(y1==0) br_pr_f1=0;
	else if(y1>0){
		int i(2);
		while(y1!=1) {
			if(y1%i==0) {
				y1/=i;
				br_pr_f1++;
			} else {
				i++;
			}
		}
	}
	if(br_pr_f1==br_pr_f) return y<x;
	return br_pr_f1<br_pr_f;
}

template <typename ItPok1, typename ItPok2, typename ItPok3>

void SortirajPodrucjeVrijednosti(ItPok1 p1, ItPok1 p2, ItPok2 p3, ItPok3 p4, decltype(*p4+*p4) f(decltype(*p1+*p1), decltype(*p4+*p4)), bool f1(decltype(*p1+*p1), decltype(*p1+*p1)))
{
	ItPok1 pom(p1);
	int br_elem(0);
	while(pom!=p2) {
		br_elem++;
		pom++;
	}
	std::sort(p1,p2,f1);
	ItPok2 pom1(p3);;
	int br_elem1(0);
	while(br_elem1!=br_elem) {
		br_elem1++;
		pom1++;
	}
	std::sort(p3,pom1,f1);
	ItPok3 pom2(p4);
	int br_elem2(0);
	while(br_elem2!=br_elem) {
		br_elem2++;
		pom2++;
	}
	ItPok1 P(p1);
	ItPok2 P1(p3);
	while(P!=p2) {
		ItPok3 pom4(p4);
		while(pom4!=pom2) {
			if(*pom4==f(*P,*P1)) break;
			else pom4++;
			if(pom4==pom2) throw std::logic_error("Izuzetak: Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		P++;
		P1++;
	}
	std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
	while(p1!=p2) {
		std::cout << "f(" << *p1 << ", " << *p3 << ") = " << f(*p1,*p3) << std::endl;
		p1++;
		p3++;
	}
}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int br_elem;
	std::cin >> br_elem;
	std::cout << "Unesite elemente prvog vektora: ";
	std::vector<int> V1;
	for(int i=0; i<br_elem; i++) {
		int k;
		std::cin >> k;
		if(i==0) V1.push_back(k);
		else {
			for(int j=0; j<V1.size(); j++) {
				if(V1.at(j)==k) {
					i--;
					break;
				}
				if(j==V1.size()-1) {
					V1.push_back(k);
					break;
				}
			}
		}
	}
	std::cout << "Unesite elemente drugog vektora: ";
	std::vector<int> V2;
	for(int i=0; i<br_elem; i++) {
		int k;
		std::cin >> k;
		if(i==0) V2.push_back(k);
		else {
			for(int j=0; j<V2.size(); j++) {
				if(V2.at(j)==k) {
					i--;
					break;
				}
				if(j==V2.size()-1) {
					V2.push_back(k);
					break;
				}
			}
		}
	}
	std::cout << "Unesite elemente treceg vektora: ";
	std::vector<int> V3;
	for(int i=0; i<br_elem; i++) {
		int k;
		std::cin >> k;
		if(i==0) V3.push_back(k);
		else {
			for(int j=0; j<V3.size(); j++) {
				if(V3.at(j)==k) {
					i--;
					break;
				}
				if(j==V3.size()-1) {
					V3.push_back(k);
					break;
				}
			}
		}
	}
	std::cout << std::endl;
	try {
		SortirajPodrucjeVrijednosti(V1.begin(),V1.end(),V2.begin(),V3.begin(),f,f1);
	} catch(std::logic_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}