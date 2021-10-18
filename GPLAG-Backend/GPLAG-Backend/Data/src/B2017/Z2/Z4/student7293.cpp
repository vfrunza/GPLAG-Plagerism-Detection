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
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <deque>
#include <set>
#include <string>


int ProstiFaktori (int n) {
	if (n<=0) return 0;
	int brojac(0), i(2);
	while (true) {
		if (n%i==0) {
			brojac++;
			n /= i;
		}
		else i++;
		if (n==1) break;
	}
	return brojac;
}

bool Kriterij (int x1, int x2) {
	int r1 = ProstiFaktori(x1);
	int r2 = ProstiFaktori(x2);
	if (r1==r2) return x1>x2;
	return r1>r2;
}

int f (int x, int y) {
	int z = -2*x + y;
	return z;
}

template <typename T1, typename T2, typename T3>
void SortirajPodrucjeVrijednosti (T1 poc1, T1 iza_kraja, T2 poc2, T3 poc3, 
									typename std::remove_reference<decltype(*poc3)>::type fun1 (typename std::remove_reference<decltype(*poc1)>::type a, typename std::remove_reference<decltype(*poc2)>::type b),
									bool fun2 (typename std::remove_reference<decltype(*poc1)>::type a, typename std::remove_reference<decltype(*poc2)>::type b)) {
/*void SortirajPodrucjeVrijednosti (T1 poc1, T1 iza_kraja, T2 poc2, T3 poc3,
									typename decltype(*poc3+*poc3) fun1 (typename decltype(*poc1+*poc1) a, typename decltype(*poc2+*poc2) b),
									bool fun2 (typename decltype (*poc1+*poc1) a, typename decltype (*poc2+*poc2) b)) {*/
	auto pom(poc1);								
	int vel(0);
	while (pom!=iza_kraja) {
		vel++;
		pom++;
	}
	std::sort(poc1, iza_kraja, fun2);
	std::sort(poc2, poc2+vel, fun2);
	for (int i=0; i<vel; i++) {
		auto temp = fun1(*(poc1+i), *(poc2+i));
		int br(0);
		for (int j=0; j<vel; j++) {
			br=0;
			if (temp==*(poc3+j)) {
				br=1;
				std::swap(*(poc3+i), *(poc3+j));
				break;
			}
		}
		if (br!=1) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
}

int main ()
{
	try {
		int n;
		std::cout << "Unesite broj elemenata: ";
		std::cin >> n;
		std::vector<int> v1, v2, v3;
		
		std::cout << "Unesite elemente prvog vektora: ";
		for (int i=0; i<n; i++) {
			int broj;
			std::cin >> broj;
			if (i==0) {
				v1.push_back(broj);
				i++;
			}
			for (int j=0; j<v1.size(); j++) {
				if (v1.at(j)==broj) {
					i--;
					break;
				}
				if (j==v1.size()-1) {
					v1.push_back(broj);
					break;
				}
			}
		}
		
		std::cout << "Unesite elemente drugog vektora: ";
		for (int i=0; i<n; i++) {
			int broj;
			std::cin >> broj;
			if (i==0) {
				v2.push_back(broj);
				i++;
			}
			for (int j=0; j<v2.size(); j++) {
				if (broj==v2.at(j)) {
					i--;
					break;
				}
				if (j==v2.size()-1) {
					v2.push_back(broj);
					break;
				}
			}
		}
		
		std::cout << "Unesite elemente treceg vektora: ";
		for (int i=0; i<n; i++) {
			int broj;
			std::cin >> broj;
			if (i==0) {
				v3.push_back(broj);
				i++;
			}
			for (int j=0; j<v3.size(); j++) {
				if (broj==v3.at(j)) {
					i--;
					break;
				}
				if (j==v3.size()-1) {
					v3.push_back(broj);
					break;
				}
			}
		}
		
		std::cout << std::endl;
		
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), f, Kriterij);
		
		std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
		std::cout << std::endl;
		for (int i=0; i<n; i++) {
			std::cout << "f(" << v1.at(i) << ", " << v2.at(i) << ") = " << v3.at(i) << std::endl;
		}
		
		
		//for (int i=0; i<n; i++) std::cout << v3[i] << " ";
		
		
		
	}
	catch (std::logic_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	return 0;
}