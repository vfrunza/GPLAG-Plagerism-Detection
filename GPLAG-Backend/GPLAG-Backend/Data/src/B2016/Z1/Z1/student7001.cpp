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

Vektor UkloniPonavljanjeElemenata(Vektor pocetni_vektor) {
	Vektor novi_vektor;
	for (int i=0; i<pocetni_vektor.size(); i++) 
		for (int j=i+1; j<pocetni_vektor.size(); j++)
			if (pocetni_vektor[i]==pocetni_vektor[j]) {
				pocetni_vektor.erase(pocetni_vektor.begin()+j);
				j--;
			}
	return pocetni_vektor;
}

Vektor IzdvojiGadne(Vektor pocetni_vektor, bool logicka_promjenljiva) {
	pocetni_vektor=UkloniPonavljanjeElemenata(pocetni_vektor);
	Vektor novi_vektor;
	if (logicka_promjenljiva) {
		for (int i=0; i<pocetni_vektor.size(); i++) {
			int pomocna_promjenljiva{}, brojac_0{}, brojac_1{}, brojac_2{}, ostatak{};
			pomocna_promjenljiva=pocetni_vektor[i];
			do {
				ostatak=abs(pomocna_promjenljiva%3);
				if (ostatak==1) brojac_1++;
				else if (ostatak==0) brojac_0++;
				else brojac_2++;
				pomocna_promjenljiva/=3;
			} while (pomocna_promjenljiva!=0);
			if (brojac_0%2==0 && brojac_1%2==0 && brojac_2%2==0)
				novi_vektor.push_back(pocetni_vektor[i]);
		}
	}
	else {
		for (int i=0; i<pocetni_vektor.size(); i++) {
			int pomocna_promjenljiva{}, brojac_0{}, brojac_1{}, brojac_2{}, ostatak{};
			pomocna_promjenljiva=pocetni_vektor[i];
			do {
				ostatak=abs(pomocna_promjenljiva%3);
				if (ostatak==1) brojac_1++;
				else if (ostatak==0) brojac_0++;
				else brojac_2++;
				pomocna_promjenljiva/=3;
			} while (pomocna_promjenljiva!=0);
			if ((brojac_0%2!=0 || brojac_0==0) && (brojac_1%2!=0 || brojac_1==0) 
				&& (brojac_2%2!=0 || brojac_2==0))
				novi_vektor.push_back(pocetni_vektor[i]);
		}
	}
	return novi_vektor;
}

int main() {
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int broj;
	Vektor v;
	do {
		std::cin >> broj;
		if (broj!=0) v.push_back(broj);
	} while (broj!=0);
	Vektor v1(IzdvojiGadne(v,true));
	Vektor v2(IzdvojiGadne(v,false));
	std::cout << "Opaki: ";
	for (int i=0; i<v1.size(); i++)
		std::cout << v1[i] << " ";
	std::cout << std::endl << "Odvratni: ";
	for (int i=0; i<v2.size(); i++)
		std::cout << v2[i] << " ";
	return 0;
}