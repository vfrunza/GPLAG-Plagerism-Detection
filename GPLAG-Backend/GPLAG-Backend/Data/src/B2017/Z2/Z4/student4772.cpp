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
#include <stdexcept>
#include <algorithm>
#include <type_traits>

bool Prost (int x) {
	if(x<=0) return false;
	for (int i=2; i<x; i++) 
		if (x%i==0) return false;
		
	return true;
}

template <typename TipElemenata1>
	int BrojProstihFaktora (TipElemenata1 x) {
		int br(0);
		if(x==1) return 1;
		if(x<=0) return 0;
		else {
			for (int i=2; i<=x; i++) {
				if (x%i==0 && Prost(i)) {
					while (x%i==0) {
						br++;
						x/=i;
					}
				}
			}
		}
		return br;
	}

template <typename TipElemenata1>
	bool Kriterij (TipElemenata1 x, TipElemenata1 y) {
		if(BrojProstihFaktora(x)==BrojProstihFaktora(y))
			return x>y;
		return BrojProstihFaktora(x)>BrojProstihFaktora(y);
	}

template <typename TipElemenata1>
	int f (TipElemenata1 x, TipElemenata1 y) {
		return -2*x + y;
	}


template <typename Tip1, typename Tip2, typename Tip3, typename TipElemenata1, typename TipElemenata3>
	void SortirajPodrucjeVrijednosti (Tip1 poc, Tip1 kraj, Tip2 p2, Tip3 p3, TipElemenata3 f(TipElemenata1, TipElemenata1), bool Kriterij (TipElemenata1, TipElemenata1) ) {
	 	int vel=kraj-poc;
	 	std::sort (poc, kraj, Kriterij);
	 	std::sort (p2, p2+vel, Kriterij);
	 	
	 	for (int i=0; i<vel; i++) {
	 		if(std::find(p3, p3+vel, f(*(poc+i), *(p2+i))) == p3+vel) 
	 			throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	 		else {
	 			int stara_pozicija=std::find(p3, p3+vel, f(*(poc+i), *(p2+i))) - p3;
	 			TipElemenata1 pomocna=*(p3+i);
	 			*(p3+i)=f(*(poc+i), *(p2+i));
	 			*(p3+stara_pozicija)=pomocna;
	 		}
		}
		
	}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente prvog vektora: ";
	std::vector<int>v1(n);
	int broj;
	bool nalazise(false);
	for (int i=0; i<n; i++) {
		std::cin >> broj;
		nalazise=false;
		for (int j=0; j<i; j++) 
			if(v1.at(j)==broj) {
				i--;
				nalazise=true;
				break;
			}
		if(!nalazise) v1.at(i)=broj;
	}
	
	std::cout << "Unesite elemente drugog vektora: ";
	std::vector<int>v2(n);
	for (int i=0; i<n; i++) {
		std::cin >> broj;
		nalazise=false;
		for (int j=0; j<i; j++) {
			if(v2.at(j)==broj) {
				nalazise=true;
				i--;
				break;
			}
		}
		if(!nalazise) v2.at(i)=broj;
	}
	
	std::cout << "Unesite elemente treceg vektora: ";
	std::vector<int>v3(n);
	for (int i=0; i<n; i++) {
		std::cin >> broj;
		nalazise=false;
		for (int j=0; j<i; j++) {
			if(v3.at(j)==broj) {
				nalazise=true;
				i--;
				break;
			}
		}
		if(!nalazise) v3.at(i)=broj;
	}
	
	try {
		SortirajPodrucjeVrijednosti (v1.begin(), v1.end(), v2.begin(), v3.begin(), f<int>, Kriterij<int>);
	}
	catch (std::logic_error izuzetak) {
		std::cout << std::endl << "Izuzetak: " << izuzetak.what() << std::endl;
		return 0;
	}
	std::cout << std::endl << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
	for (int i=0; i<n; i++) std::cout << "f(" << v1[i] << ", " << v2[i] << ") = " << v3[i] << std::endl;
	
	return 0;
}