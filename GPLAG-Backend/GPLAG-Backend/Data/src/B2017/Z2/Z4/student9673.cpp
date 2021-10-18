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
#include <type_traits>
#include <algorithm>


template <typename tip1, typename tip2, typename tip3>
void SortirajPodrucjeVrijednosti(tip1 pocetak, tip1 kraj, tip2 pocetak1, tip3 pocetak2, 
typename std::remove_reference<decltype(*pocetak2)>::type f(typename std::remove_reference<decltype(*pocetak)>::type, typename std::remove_reference<decltype(*pocetak)>::type),
bool f1(typename std::remove_reference<decltype(*pocetak)>::type, typename std::remove_reference<decltype(*pocetak)>::type)) {
	std::sort(pocetak, kraj, f1);
	int broj_el(0);
	auto pomocni(pocetak);
	while(pomocni != kraj) {
		broj_el++;
		pomocni++;
	}
	std::sort(pocetak1, pocetak1 + broj_el, f1);
	for(tip1 i(pocetak); i != kraj; i++) {
		auto rezultat(f(*i, *pocetak1));
		bool promjena = false;
		tip1 pomocna1(pocetak);
		int pozicija = 0;
		while(pomocna1 != i) {
			pozicija++;
			pomocna1++;
		}
		for(tip3 j(pocetak2); j != pocetak2 + broj_el; j++) {
			if(rezultat == *j) {
				promjena = true;
			auto pomocna=*j;
			*j=rezultat;
			rezultat=pomocna;
				// zamjena elementa na poziciji pozicija i onog na koji pokazuje j
			}
		}
		if(promjena == false) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		pocetak1++;
	}
}
double F(double &x,double &y){
  return -(x+2*y);
}

int main ()
{
	try{
		std::cout<<"Unesite broj elemenata: ";
		int n;
		std::cin>>n;
		std::cout<<"Unesite elemente prvog: ";
		std::vector<int> S1	;
		std::vector<int> S2 ;
		std::vector<int> S3;
		for(int i(0);i<n;i++){
			int x;
			std::cin>>x;
			S1.push_back(x);
		}
		std::cout<<std::endl<<"Unesite elemente drugog: ";
			for(int i(0);i<n;i++){
			int x;
			std::cin>>x;
			S2.push_back(x);
		}
		std::cout<<std::endl<<"Unesite elemente treceg: ";
			for(int i(0);i<n;i++){
			int x;
			std::cin>>x;
			S3.push_back(x);
		}
		SortirajPodrucjeVrijednosti(S1.begin(),S1.end(),S2.begin(),S3.begin(),F,Kriterij())
	}
	return 0;
}