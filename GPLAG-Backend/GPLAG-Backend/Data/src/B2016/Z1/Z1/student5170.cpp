/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> Vektor;

Vektor IzdvojiGadne (Vektor vektor, bool vrijednost)
{
	Vektor povratni(0);
	if (vektor.size()!=0) {
		for (int i=0; i<vektor.size()-1; i++) {
			for (int j=i+1; j<vektor.size(); j++) {
				if (vektor[j]==vektor[i]) {
					vektor.erase(vektor.begin() + j);
					j--;
				}
			}
		}
		Vektor pomocni;
		int a, nula, kec, dvica;
		for (int x: vektor) {
			if (x==0 && vrijednost) continue;
			else if (x==0 && !vrijednost) povratni.push_back(x);
			else {
				pomocni.resize(0);
				a=abs(x);
				while(a!=0) {
					pomocni.push_back(a%3);
					a/=3;
				}
				nula=0;
				kec=0;
				dvica=0;
				for (int y: pomocni) {
					if (y==0) nula++;
					if (y==1) kec++;
					if (y==2) dvica++;
				}
				if (!vrijednost)
					if ((nula%2!=0 || nula==0) && (kec%2!=0 || kec==0) && (dvica%2!=0 || dvica==0)) povratni.push_back(x);
				if (vrijednost)
					if (nula%2==0 && kec%2==0 && dvica%2==0) povratni.push_back(x);
			}
		}
	}
	return povratni;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int a;
	Vektor vektor;
	do {
		std::cin >> a;
		if (a!=0) vektor.push_back(a);
	} while (a!=0);
	Vektor opaki(IzdvojiGadne(vektor, true));
	Vektor odvratni(IzdvojiGadne(vektor, false));
	std::cout << "Opaki: ";
	for (int x: opaki) std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for (int x: odvratni) std::cout << x << " ";
	return 0;
}