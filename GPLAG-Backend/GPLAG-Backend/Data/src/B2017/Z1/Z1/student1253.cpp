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
#include <cmath>
#include <vector>


typedef std::vector<int> vektor;

vektor IzdvojiSimetricneTernarne (vektor v, bool n)
{
	vektor nv;
	for(int x:v) { //ovom foreach petljom izdvajamo proste/slozene brojeve iz vektora "v" u nas novi vektor "nv"
		bool prost(1);
		bool negativan(0);
		if(x<0) {   //negativne brojeve privremeno pretvaramo u proste zbog funkcije "sqrt"
			x = -x;
			negativan=true;
		}
		if(x<2 && x>(-2)) {
			prost=false;
		}
		for(int i=2; i<=std::sqrt(x); i++) {
			if(x%i==0) {
				prost=false;
				break;
			}
		}
		if(n && prost) {
			if(negativan) x = -x;
			nv.push_back(x);
		} else if(!n && !prost) {
			if(negativan) x = -x;
			nv.push_back(x);
		}
	}
	vektor povratni;
	for(int x:nv) { //ovom foreach petljom provjeravamo koji su brojevi vektora "nv" simetricni u svojoj ternarnoj reprezentaciji
		int d(x);
		int o(0); //ostatak
		int a(0); //ternarni broj zapisan "unazad"
		int y(x); //nova promjenljiva jer "x" ne smijemo promijeniti
		do {  //zapisujemo ternarnu vrijednost broja "x" unazad u promjenljivu "a"
			a*=10;
			d = y/3;
			o = y - d*3;
			a += o;
			y=d;
		} while(d!=0);
		int t(0); //ternarni broj elementa vektora "nv"
		int b(a);
		do {
			t*=10;
			t += b%10;
			b=b/10;
		} while(b!=0);
		if(a==t) { //provjera da li je "t" simetrican
			povratni.push_back(x);
		}
	}

	for(int i=0; i<int(povratni.size()); i++) { //po uslovu zadatka, brojevi se ne trebaju ponavljati
		for(int j=i+1; j<int(povratni.size()); j++) {
			if(povratni.at(i)==povratni.at(j)) {
				povratni.erase(povratni.begin() + j);
				j--;   //moramo provjeriti novi elemenat koji se nalazi na "j-tom" mjestu
			}
		}
	}

	return povratni;
}

int main ()
{
	vektor v; //prvi parametar koji šaljemo funkciji
	int x;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;) {
		std::cin>>x;
		if(x==-1) break;
		if(std::cin) v.push_back(x);
		else {
			std::cout<<"Niste unijeli prirodan broj!\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool n; //drugi parametar koji šaljemo funkciji
	int testni;
	for(;;) {
		std::cin>>testni;
		if(std::cin) {
			if(testni==1 || testni==0) {
				n=testni;
				break;
			} else std::cout<<"Neispravan unos! Unesite ponovo: ";
		} else {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}

	vektor novi;
	novi = IzdvojiSimetricneTernarne(v, n);
	if(int(novi.size())==0) {
		if(n) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	} else {
		if(n) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int y:novi) {
			if(y!=novi.at(0)) { //ovo možemo uraditi jer se elementi vektora "novi", prema uslovu zadatka, ne ponavljaju
				std::cout<<", ";
			}
			std::cout<<y;
		}
		std::cout<<".";
	}
	return 0;
}