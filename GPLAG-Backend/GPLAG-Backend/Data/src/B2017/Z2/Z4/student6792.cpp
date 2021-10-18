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
typedef std::vector<int> Vektor;
int main ()
{
	try {
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog vektora: ";
	Vektor A;
	int element;
	for (int i=0; i<n; i++) {
		std::cin>>element;
		A.push_back(element);
	}
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int i=0; i<n; i++) 
	std::cout<<"Unesite elemente treceg vektora: ";
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "; }
	catch () {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}