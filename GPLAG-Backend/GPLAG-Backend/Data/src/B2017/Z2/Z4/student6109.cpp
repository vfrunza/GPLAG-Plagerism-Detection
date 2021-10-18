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
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <typeinfo>
#include <type_traits>

int formula(int x, int y) {
	return y-2*x;
}

bool DaLiJeProst(int broj) {
	int suma=0;
	for(int i=1; i<=broj; i++) {
		if(broj%i==0) suma++;
	}
	return suma;
}

bool Sume(int x, int y) {
	int suma1, suma2;
	suma1=DaLiJeProst(x);
	suma2=DaLiJeProst(y);
	if(suma1!=suma2) return suma1>suma2;
	return x>y;
}

template <typename T1, typename T2, typename T3>
void SortirajPodrucjeVrijednosti(T1 start, T1 end, T2 p1, T3 p2, typename std::remove_reference<decltype(*p2)>::type f(typename std::remove_reference<decltype(*end)>::type, typename std::remove_reference<decltype(*end)>::type), bool f1(typename std::remove_reference<decltype(*end)>::type, typename std::remove_reference<decltype(*end)>::type)) {
	T1 a=start;
	T2 b=p1;
	T3 c=p2;
	int test=0;
	
	std::sort(start, end, f1);
	std::sort(p1, p1+(end-start), f1);
	
	while(a!=end) {
		auto x=*a;
		auto y=*b;
		auto kraj=find(p2, p2+(end-start), f(x,y));
		if(kraj!=p2+(end-start)) {
			auto temp=*kraj;
			*kraj=*p2;
			*p2=temp;
		} else {
			throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		test++;
		a++;
		b++;
		c++;
		if(a==p2+(end-start)) break;
		if(test) break;
	}
}

int main () {
	std::cout << "Unesite broj elemenata: ";
	int element;
	std::cin >> element;
	std::vector<int>v1(element);
	std::vector<int>v2(element);
	std::vector<int>v3(element);
	std::cout << "Unesite elemente prvog vektora: ";
	for(int i=0; i<element; i++) {
		int broj;
		std::cin >> broj;
		v1.push_back(broj);
	}
	std::cout << "Unesite elemente drugog vektora: ";
	for(int i=0; i<element; i++) {
		int broj;
		std::cin >> broj;
		v2.push_back(broj);
	}
	std::cout << "Unesite elemente treceg vektora: ";
	for(int i=0; i<element; i++) {
		int broj;
		std::cin >> broj;
		v3.push_back(broj);
	}
	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), formula, Sume);
//		std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
//		for(int i=0; i<element; i++) {
//			if((v2.at(i)-2*(v1.at(i)))==v3.at(i)) std::cout << "f(" << v1.at(i) << ", " << v2.at(i) << ") = " << v3.at(i) << std::endl;
//		}
	}catch(std::logic_error jedan) {
		std::cout << "Izuzetak: " << jedan.what() << std::endl;
	}
	return 0;
}