#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> Vektor;

//Da li je broj prost funkcija:
bool DaLiJeProst (int broj)
{

	bool prost=true;
	if (broj==1 || broj<=0) {
		prost=false;
		return prost;
	}

	for (unsigned int i = 2; i*i<=broj; i++) {
		if (i==broj) break;
		if (broj%i == 0) {
			prost=false;
			break;
		}
	}
	return prost;
}

//Pretvori broj u ternarni
int Pretvori(int broj)
{
	int cifra(0), i(0), broj_pretvoren(0);

	while(broj != 0) {
		cifra=broj%3;
		broj_pretvoren+=pow(10,i)*cifra;
		broj/=3;
		i++;
	}
	return broj_pretvoren;
}

//provjeri simetricnost
bool Simetrican(int broj_ter)
{
	bool promjenjiva_simetrican= true;
	broj_ter=Pretvori(broj_ter);
	Vektor vektor_cifara;
	while (broj_ter!=0) {
		vektor_cifara.push_back(broj_ter%10);
		broj_ter/=10;
	}
	int velicina_vektora(vektor_cifara.size());
	for (int i = 0; i <= velicina_vektora-1; i++) {
		if (vektor_cifara.at(i) != vektor_cifara.at(velicina_vektora-1-i) ) {
			promjenjiva_simetrican=false;
			break;
		}
	}
	return promjenjiva_simetrican;
}


Vektor IzdvojiSimetricneTernarne (Vektor vektor_pocetni, bool promjenjiva)
{
	Vektor vektor_vracen;
	if (promjenjiva) {
		for (int i = 0; i < vektor_pocetni.size(); i++) {
			if (DaLiJeProst(abs(vektor_pocetni.at(i))) && Simetrican(vektor_pocetni.at(i)))     //Da li je prost
				vektor_vracen.push_back(vektor_pocetni.at(i));
		}
	} else {
		for (int i = 0; i < vektor_pocetni.size(); i++) {
			if (!DaLiJeProst(abs(vektor_pocetni.at(i))) && vektor_pocetni.at(i)!=1  && Simetrican(vektor_pocetni.at(i)))  //Da li je slozen
				vektor_vracen.push_back(vektor_pocetni.at(i));
		}
	}

	return vektor_vracen;

}

int main ()
{
	Vektor v1;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
		std::cin >> broj;
		if(broj != -1) v1.push_back(broj);
	} while(broj != -1);
	int promjenjiva_main;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";

	do {
		std::cin >> promjenjiva_main;
		if (promjenjiva_main == 0 || promjenjiva_main==1) break;
		else {
			std::cout << "Neispravan unos! Unesite ponovo: ";
		}
	} while (promjenjiva_main != 0 && promjenjiva_main != 1);

	v1=IzdvojiSimetricneTernarne(v1, promjenjiva_main);

	if (promjenjiva_main) {
		if (v1.size() > 0)
			std::cout << "Prosti simetricni brojevi iz vektora su: ";

		else std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	}

	else {
		if (v1.size() > 0)
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";

		else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}

	for(int i = 0; i < v1.size(); i++) {
		if (i==v1.size()-1) std::cout << v1.at(i) << ".";
		else std::cout << v1.at(i) << ", ";
	}
	return 0;
}