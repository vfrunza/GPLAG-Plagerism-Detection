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
int Gadni (int broj) {
	int cifra (0), brojac_0 (0), brojac_1 (0), brojac_2 (0);
	if (broj < 0) {
		broj = abs(broj);
	}
	if (broj == 0) {
		return 0;
	}
	while (broj != 0) {
		cifra = broj % 3;
		if (cifra == 0) {
			brojac_0++;
		}
	
		else if (cifra == 1) {
			brojac_1++;
		}
		else brojac_2++;
		
		broj = broj / 3;
	}
	
	if (brojac_0 % 2 == 0 && brojac_1 % 2 == 0 && brojac_2 % 2 == 0) {
		return 1;
	}
	else if ((brojac_0 % 2 != 0 || brojac_0 == 0) && (brojac_1 % 2 != 0 || brojac_1 == 0) && (brojac_2 % 2 != 0 || brojac_2 == 0)) {
		return 0;
	}
	else return 2;
}
bool Isti (std::vector <int> v, int trazeni_broj) {
	for (int i=0; i < v.size(); i++) {
		if (trazeni_broj == v[i]) {
			return true;
		}
	}
	return false;
}
std::vector <int> IzdvojiGadne (std::vector <int> v, bool x) {
	std::vector <int> krajnji_vektor;
	if (x == true) {
		for (int i=0; i < v.size(); i++) {
			int opak = Gadni(v[i]);
				if (opak == true) {
					if (! Isti(krajnji_vektor,v[i])) {
					krajnji_vektor.push_back(v[i]);
	 			}
				}
		}
	}
	if (x == false) {
		for (int i=0; i < v.size(); i++) {
			int odvratan = Gadni(v[i]);
				if (odvratan == false) {
					if(!Isti(krajnji_vektor,v[i])){
					krajnji_vektor.push_back(v[i]);
				}
				}
		}
	}
	return krajnji_vektor;
}
int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector <int> v {56, 656, 20, 61, 552, -6384, 223, 8979, 80812, 26937, 240801, 15, 3608, 5904, 56, 656, 20, 61, 552, -6384, 223, 0};
	std::vector <int> v1 = IzdvojiGadne(v,true);
	std::vector <int> v2 = IzdvojiGadne(v,false);
	
	std::cout << "Opaki: ";
	for (int i=0; i < v1.size(); i++) {
			if (v1[i]==0) {
			break;
		}
	std::cout << v1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for (int i=0; i < v2.size(); i++) {
		if (v2[i]==0) {
			break;
		}
		std::cout << v2[i] << " ";
		
	}
//std::cout << Parnost(11002212001);
	return 0;
}