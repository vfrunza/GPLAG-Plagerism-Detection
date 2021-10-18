/*B 2017/2018, Zadaća 2, Zadatak 3
	
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
#include <vector> 
template <typename T>
	void izuzetak (std::vector<T> &vektor ){
		for (auto x: vektor) {
			if (x<=0 ) throw std::domain_error ("Neispravan vektor!");
		}
	}

template <typename T>
	void AlocirajFragmentirano (std::vector<T> &vektor, int &koliko_puta ){
		izuzetak(vektor);
	}
template <typename T>
	void AlocirajKontinualno (std::vector<T> &vektor, int &koliko_puta ){
		izuzetak(vektor); 
	}

int main ()
{
 
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n; 
	std::cout<<"Unesite elemente vektora: "; 
	std::vector<int> v ;
	for (int i=0; i<n; i++){
		int x;
		std::cin>>x;
		v.push_back(x); 
	}
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: "; 
	int a; 
	std::cin>>a;
	try {
	if (a==1) AlocirajFragmentirano(v, a);
	}
	catch (std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
	}
	return 0;
}