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

template <typename tip_1, typename tip_2>
tip_2 f(tip_1 x, tip_1 y)
{
	//return x + 2 * y;
	return -2*x + y;
}


template <typename tip_1>

bool f_sort(tip_1 a, tip_1 b)
{
	if (a<0) a*=(-1);
	if(b<0) b*=(-1);
	int brojac_a(0), brojac_b(0);
	for(tip_1 i=2; i<a; i++) {
		if(a%i==0) {
			int prost(true);
			for(int j=2; j<i; j++) {
				if(j%i==0) {
					prost=false;
					break;
				}
			}
			if(prost) brojac_a++;
		}
	}
	for(tip_1 i=2; i<b; i++) {
		if(b%i==0) {
			int prost(true);
			for(int j=2; j<i; j++) {
				if(j%i==0) {
					prost=false;
					break;
				}
			}
			if(prost) brojac_b++;
		}
	}
	if(brojac_a == brojac_b) return a > b;
	return brojac_a>brojac_b;
}


template <typename tip_1, typename tip_2, typename tip_3>

void SortirajPodrucjeVrijednosti (tip_1 pocetak, tip_1 kraj, tip_2 blok2, tip_3 blok3, typename std::remove_reference<decltype(*blok3)>::type f(typename std::remove_reference<decltype(*pocetak)>::type, typename std::remove_reference<decltype(*pocetak)>::type),
bool f_sort(typename std::remove_reference<decltype(*pocetak)>::type, typename std::remove_reference<decltype(*pocetak)>::type))
{
	std::sort(pocetak, kraj, f_sort);
	std::sort(blok2, (blok2+int(kraj-pocetak)), f_sort);
	auto pocetak1(pocetak);
	while(pocetak!=kraj) {
		auto rezultat = f(*pocetak, *blok2);
		auto pomocni(blok3);
		int broj_elemenata(kraj - pocetak1);
		bool nadjena(false);
		for(int i(0); i < broj_elemenata; i++) {
			if(rezultat == *(blok3 + i)) {
				nadjena = true;
				int indeks = (pocetak - pocetak1);
				auto temp = *(blok3 + i);
				*(blok3 + i) = *(blok3 + indeks);
				*(blok3 + indeks) = temp;
				break;
			}
		}
		if (!nadjena) {
			throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		pocetak++;
		blok2++;
	}
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;

	std::vector<int> S1, S2, S3;
	std::cout<<"Unesite elemente prvog vektora: ";
	for(int i=0; i<n; i++) {
		int x;
		std::cin>>x;
		bool nadjena(false);
		for(int j(0); j < S1.size(); j++) {
			if(x == S1.at(j)) {
				nadjena = true;
				break;
			}
		}
		if(nadjena) {
			i--;
			continue;
		}
		else S1.push_back(x); 
	}
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int i=0; i<n; i++) {
		int x;
		std::cin>>x;
		bool nadjena(false);
		for(int j(0); j < S2.size(); j++) {
			if(x == S2.at(j)) {
				nadjena = true;
				break;
			}
		}
		if(nadjena) {
			i--;
			continue;
		}
		else S2.push_back(x);
	}
	std::cout<<"Unesite elemente treceg vektora: ";
	for(int i=0; i<n; i++) {
		int x;
		std::cin>>x;
		bool nadjena(false);
		for(int j(0); j < S3.size(); j++) {
			if(x == S3.at(j)) {
				nadjena = true;
				break;
			}
		}
		if(nadjena) {
			i--;
			continue;
		}
		else S3.push_back(x);
	}
	try {
		SortirajPodrucjeVrijednosti(S1.begin(), S1.end(), S2.begin(), S3.begin(), f, f_sort);
		std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
		for(int i=0;i<S1.size();i++){
			std::cout<<"f("<<S1.at(i)<<", "<<S2.at(i)<<") = "<<S3.at(i)<<std::endl; 
		}
	} catch(std::logic_error izuzetak) {
		std::cout<<std::endl <<"Izuzetak: " << izuzetak.what() << std::endl;
		return 0;
	}
	return 0;
}