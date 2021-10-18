/*B 2017/2018, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <vector>
typedef std::vector<int> Vektor;

bool StepenDvojke(int n)
{
	while(n!=1) {
		if (n%2!=0) return false;
		n/=2;
	}
	return true;
}


int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	int a;
	Vektor A;
	for(int i=0; i<n; i++) {
		std::cin>>a;
		A.push_back(a);
	}
	std::cout<<"Uneiste: 1 - za rastuce podnizive, 2 - za opadajuce podnizove: ";
	int broj;
	std::cin>>broj;
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<"Maksimalni opadajuci podnizovi:";
	return 0;
}