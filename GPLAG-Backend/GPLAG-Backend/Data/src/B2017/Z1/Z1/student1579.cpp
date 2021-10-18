/*B 2017/2018, Zadaća 1, Zadatak 1

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
#include <cmath>

bool DaLiJeSimetrican(int n)
{
	int pomocna(n);
	int broj(0);

//simetricnost ternarnog elementa
	do {
		broj=broj*10+n%10;
		n/=10;
	} while(n!=0);

	if(pomocna==broj) {
		return true;
	} else {
		return false;
	}
}

bool DaLiJeProst(int n)
{
	bool pomoc_prost(true);
	int pomocna=abs(n);		//ne uzimam u obzir predznak broja

	for(int i=2; i<=sqrt(pomocna); i++) {	//provjeravam element
		if(n%i==0) {
			pomoc_prost=false;
			break;
		}
	}


	if(pomoc_prost) {
		return true;
	} else {
		return false;
	}
}


std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v, bool prost)
{

//Brisanje duplih elemenata
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.size(); j++) {
			if((v.at(i)==v.at(j)) && (i!=j)) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}

	std::vector<int>izdvojen;

	for(auto element: v) {		//ucitavam element

		int pomocna(element);	//pomocna var. da sacuvam element
		bool pomocna_prost(DaLiJeProst(pomocna));	//provjera da li je element iz vektora prost

		int suma(0);
		int dec(1);
		while(element!=0) {	//pretvaram el u tern
			int x;
			x=abs(element)%3;
			element/=3;
			suma=suma+x*dec;	//pretvaram el u ternarni broj
			dec*=10;
		}

		bool simetrican(DaLiJeSimetrican(suma));		//provjera simetrije

		if(simetrican && prost && pomocna_prost) {
			izdvojen.push_back(pomocna);
		} else if(simetrican && prost==false && pomocna_prost==false) {
			izdvojen.push_back(pomocna);
		}

	}

	return izdvojen;
}

int main ()
{

	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int>vektor;
	int el;

	do {
		std::cin>>el;
		if(el!=-1) vektor.push_back(el);
	} while(el!=-1);


	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int broj;
	std::cin>>broj;

	while(!std::cin) {	//neispravan tok
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		std::cin>>broj;
	}

	while(broj!=1 && broj!=0) {		//pogresan unos, ispravan tok
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>broj;
	}

	std::vector<int>izdvojeni(IzdvojiSimetricneTernarne(vektor,broj));

	if(izdvojeni.size()==0) {	//vektor bez elemenata
		if(broj==1) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 1;
		} else {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 1;
		}
	}

	if(broj==1) {
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
	} else {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}

	for(int i=0; i<izdvojeni.size()-1; i++) {
		std::cout<<izdvojeni.at(i)<<", ";
	}
	std::cout<<izdvojeni.at(izdvojeni.size()-1)<<".";

	return 0;
}