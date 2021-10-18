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
#include <stdsxcept>
template<typename tip1, typename tip2, typename tip3>
  SortirajPodrucjeVrijednosti()
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::vector<int> v1,v2,v3;
	std::cout<<"Unesite elemenate prvog vektora: ";
	for(int i=0; i<n; i++){
		int pom;
		std::cin>>pom;
		v1.push_back(pom);
	}
	std::cout<<"Unesite elemenate drugog vektora: ";
	for(int i=0; i<n; i++){
		int pom;
		std::cin>>pom;
		v2.push_back(pom);
	}
	std::cout<<"Unesite elemenate treceg vektora: ";
	for(int i=0; i<n; i++){
		int pom;
		std::cin>>pom;
		v3.push_back(pom);
	}
	SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), )
	return 0;
}