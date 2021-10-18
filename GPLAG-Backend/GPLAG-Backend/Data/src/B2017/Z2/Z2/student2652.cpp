/*B 2017/2018, Zadaća 2, Zadatak 2
	
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
#include <vector>
#include <deque> 
#include <stdexcept>

enum class SmjerKretanja {
NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename T>
	void izuzetak1(T kont){
		for (auto x: kont ){
			if (x.size()!=kont.at(0).size()) throw std::domain_error("\nIzuzetak: 3D matrica nema oblik kocke ");
			for (auto y : x){
				if (x.size()!=y.size() || x.size()!=kont.size()) throw std::domain_error("\nIzuzetak: 3D matrica nema oblik kocke ");
			}
		}
	}
template<typename T>
	void izuzetak2(T kont){
		for (auto x : kont ){
			if (x.size()%2 == 0) throw std::length_error("\nIzuzetak: 3D kontejner ne zadovoljava uvjet neparnosti ");
			for (auto y : x){
				if (y.size()%2 == 0) throw std::length_error("\nIzuzetak: 3D kontejner ne zadovoljava uvjet neparnosti ");
			}
		}
	}

template <typename T>
auto PjescaniSat (T kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont)>::type
{
	izuzetak1(kont);
	izuzetak2(kont); 
		return kont; 
	}

int main ()
{
	std::cout<<"Unesite dimenziju (x/y/z): "; 
	int n;
	std::cin>>n; 
	while (n<=0){
		std::cout<<"Dimenzija nije ispravna, unesite opet: ";
		std::cin>>n; 
	}
	std::cout<<"Unesite elemente kontejnera: ";
	std::vector<std::deque<std::deque<int>>> vektor; 
	std::deque<std::deque<int>> dek2;
	std::deque<int> dek1;
	for (int i=0; i<n; i++) 
		{
			dek2.resize(0);
			for (int j=0; j<n; j++){
				dek1.resize(0);
				for (int k=0; k<n; k++){
					int x;
					std::cin>>x;
					dek1.push_back(x); 
				}
			
				dek2.push_back(dek1);
			}
			vektor.push_back(dek2); 
		}
	std::cout<<"Unesite smjer kretanja [0 - 5]: "; 
	int smjer;
	std::cin>>smjer;
	while (smjer<0 || smjer>5) {
		std::cout<<"Smjer nije ispravan, unesite opet: ";
		std::cin>>smjer; 
	}
	
	try{
	PjescaniSat (vektor, SmjerKretanja(smjer));
	}
	catch (std::domain_error e)
	{
		std::cout<<e.what();
	}
	catch (std::length_error e) {
		std::cout<<e.what(); 
	}
	
	return 0;
}