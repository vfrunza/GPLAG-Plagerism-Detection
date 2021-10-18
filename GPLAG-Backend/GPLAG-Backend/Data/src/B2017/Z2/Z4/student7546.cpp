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
#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>

template <typename ITERiliPOK1, typename ITERiliPOK2, typename ITERiliPOK3,
		  typename TipFun1, typename TipFun2>
		  
void SortirajPodrucjeVrijednosti(ITERiliPOK1 pocetak1, ITERiliPOK1 iza_kraja1, ITERiliPOK2 pocetak2, ITERiliPOK3 pocetak3, TipFun1 f1, TipFun2 f2) {
		ITERiliPOK1 t1(pocetak1);
		ITERiliPOK2 t2(pocetak2);
		ITERiliPOK3 t3(pocetak3);
		
		while(t1 != iza_kraja1) {
			t1++;
			t2++;
			t3++;
		}
		
		//sada t1, t2, t3 pokazuju iza kraja prvog, drugog i treceg bloka
		
		std::sort(pocetak1, iza_kraja1, f2);
		std::sort(pocetak2, t2, f2);
		
		ITERiliPOK1 citac1(pocetak1);
		ITERiliPOK2 citac2(pocetak2);
		ITERiliPOK3 citac3(pocetak3);
		
		while(citac1 != iza_kraja1) {
			auto vrijednost = f1(*citac1, *citac2);
			auto pom_citac = citac3;
			bool pretpostavka(false);
			while(pom_citac != t3) {
				if(*pom_citac == vrijednost) {
					pretpostavka=true;
					auto temp = *pom_citac;
					*pom_citac = *citac3;
					*citac3 = temp;
					break;
				}
				citac3++;
				pom_citac++;
			}
			if(pretpostavka) {
				citac1++;
				citac2++;
			}
		}
}
 
void UnosVektora(std::vector<int> &v, int br_elemenata) {
	for(int i=0; i<br_elemenata; i++) {
		int element(0);
		std::cin>>element;
		int j;
		for(j=0; j<i; j++) {
			if(v[j]==element) {
				i--;
				break;
			}
		}
		if(j==i) v[i]=element;
	}
}

bool JeLiProst(int n) {
	for(int i=2; i<n; i++) if(x%i == 0) return false;
	return true;
}

int main ()
{
	std::cout << "Unesite broj prvog vektora: ";
	int br_elemenata(0);
	std::cin >> br_elemenata;
	
	std::cout << "Unesite elemente prvog vektora: ";
	std::vector<int> prvi_vektor(br_elemenata);
	UnosVektora(prvi_vektor, br_elemenata);
	
	std::cout << "Unesite elemente drugog vektora: ";
	std::vector<int> drugi_vektor(br_elemenata);
	UnosVektora(drugi_vektor, br_elemenata);
	
	std::cout << "Unesite elemente treceg vektora: ";
	std::vector<int> treci_vektor(br_elemenata);
	UnosVektora(treci_vektor, br_elemenata);
	
	try {
		SortirajPodrucjeVrijednosti(prvi_vektor.begin(), prvi_vektor.end(), drugi_vektor.begin(), treci_vektor.begin()), 
		[] (int x, int y) { return y-2*x; },
		[] (int x, int y) {
			int prosti1(0);
			int prosti2(0);
			int x1(x);
			int y1(y);
			for(int i=2; i<abs(x); ++) {
				if(JeLiProst(i) && x1%i==0) {
					while(x1%i==0){
						prosti1++;
						x1=x1/i;
				}
			}
			if(abs(x1)==1) break;
		}
			for(int i=2; i<abs(y); ++) {
				if(JeLiProst(i) && y1%i==0) {
					while(y1%i==0){
						prosti2++;
						y1=y1/i;
				}
			}
			if(abs(y1)==1) break;
		}
		if(prosti2 == prosti1) return x>y;
		if (prosti1>prosti2) return true;
		return false;
	});
	
	auto prvi(prvi_vektor.begin());
	auto drugi(drugi_vektor.begin());
	auto treci(treci_vektor.begin());
	
	std::cout << std::endl;
	std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
	
	while (prvi_vektor.begin() != prvi_vektor.end()) {
		std::cout << "f(" << 
	}

	
	
	
	
	
	
	
}
