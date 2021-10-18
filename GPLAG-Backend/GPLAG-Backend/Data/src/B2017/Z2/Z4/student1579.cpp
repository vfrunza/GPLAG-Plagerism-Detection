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
#include <stdexcept>
#include <vector>



bool DaLiJeProst(int n){
	bool prost(true);
	
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0){
			prost=false;
			break;
		}
	}
	
	if(n<2) prost=false;
	
	if(prost){
		return true;
	} else {
		return false;
	}
}

template <typename Tip1, typename Tip2>

void SortirajPodrucjeVrijednosti(Tip1 v1poc, Tip1 v1kraj, Tip1 v2poc, Tip2 v3poc, Tip2 f(Tip1 x, Tip1 y), bool f(Tip1 x, Tip1 y)){
	
	std::sort(v1poc, v1kraj, bool f)
	std::sort(v2)
	
}




int main ()
{
	try {

		std::cout << "Unesite broj elemenata: ";
		int broj_el;
		std::cin >> broj_el;

		std::cout << "Unesite elemente prvog vektora: ";
		std::vector<int>v1;

		int i=0;
		while(i!=broj_el) {
			int element;
			std::cin >> element;
			v1.push_back(element);
			i++;
		}

		std::cout << "Unesite elemente drugog vektora: ";
		std::vector<int>v2;

		i=0;
		while(i!=broj_el) {
			int element;
			std::cin >> element;
			v2.push_back(element);
			i++;
		}

		std::cout << "Unesite elemente treceg vektora: ";
		std::vector<int>v3;

		i=0;
		while(i!=broj_el) {
			int element;
			std::cin >> element;
			v3.push_back(element);
			i++;
		}
		
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(),  
		[](int x, int y){return -2*x+y;}, 
		[](int x, int y){ 
			DaLiJeProst(x)
			
			
			)
		
		std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
		
		for(int i=0; i<broj_el; i++){
			std::cout << "f(" << v1.at(i) <<", "<<v2.at(i)<<") = "<<v3.at(i);
		}
		
		

	} catch(std::logic_error izuzetak) {
		std::cout << "Vrijednost koja odgovara nekom od parova nije nadjena.";

	}

	return 0;
}