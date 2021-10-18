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

int main ()
{
	int n;
	int m;
	std::vector <int> r;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::cout << "Unesite elemente prvog vektora: ";
	for(int i=0;i<n;i++){
		std::cin >> m;
	}
	std::cout << "Unesite elemente drugog vektora: ";
	for(int i=0;i<n;i++){
		std::cin >> m;
	}
	std::cout << "Unesite elemente treceg vektora: ";
	for(int i=0;i<n;i++){
		std::cin >> m;
	}
	std::cout << "\nIzuzetak: Vrijednost koja odgovara nekom od parova nije nadjena";
	
	return 0;
}