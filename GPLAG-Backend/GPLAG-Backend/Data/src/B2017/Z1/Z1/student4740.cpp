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

int ternarni_naopako(int a)
{
	if(a%3==0) return 12;    /* ako broj da ostatak nula pri prvom dijeljenju sa 3 (znaci da ce mu zadnja cifra biti 0, tj sigurno nije simetrican
	                         jer mu prva cifra ne moze biti nula), odmah vracamo nesto sto takodjer sigurno nije simetricno, kako bismo osigurali
	                         da funkcija "simetrican" u nastavku programa vraca vrijednost false za takav broj */
	int broj(a);
	int ternarni_zapis(0);
	while(broj!=0) {
		ternarni_zapis*=10;
		ternarni_zapis+=broj%3;
		broj/=3;
	}

	return ternarni_zapis;
}

bool simetrican (int a)
{
	int broj(a);
	int novi(0); // "novi" ce biti broj a okrenut naopako
	while (broj!=0) {
		novi*=10;
		novi+=broj%10;
		broj/=10;
	}

	if(a==novi) return true;
	else return false;
}

bool prost_broj(int a)
{
//	if (a==1) return false;

	int brojac(0);
	int broj(abs(a));
	for(int i=2; i<=sqrt(broj); i++) if(broj%i==0) brojac++;

	if (brojac==0) return true;
	else return false;
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v, bool prost)
{
	std::vector<int> simetricni;

	for(int i=0; i<v.size(); i++) {
		if(prost && prost_broj(v.at(i)) && simetrican(ternarni_naopako(v.at(i)))) simetricni.push_back(v.at(i));
		else if(!prost && !(prost_broj(v.at(i))) && simetrican(ternarni_naopako(v.at(i)))) simetricni.push_back(v.at(i));
	}

	for(int i=0; i<simetricni.size(); i++) {             // petlja brise ponavljanja istih elemenata
		for(int j=i+1; j<simetricni.size(); j++)
			if(simetricni.at(i)==simetricni.at(j)) {
				simetricni.erase(simetricni.begin()+j);
				j--;
			}
	}

	return simetricni;
}

int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";

	std::vector<int> v;

	int broj(0);
	for(;;) {
		std::cin>>broj;
		if(broj==-1) break;
		else v.push_back(broj);
	}

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prosti;
	for(;;) {
		std::cin>>prosti;
		if(prosti==1 || prosti==0) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}

	std::vector<int> novi_vektor(IzdvojiSimetricneTernarne(v,prosti));

	if(prosti && novi_vektor.size()==0) {
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 1;
	} else if(!prosti && novi_vektor.size()==0) {
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 1;
	} else if(prosti) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else if(!prosti) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; i<novi_vektor.size(); i++) {
		if(i<novi_vektor.size()-1) std::cout<<novi_vektor.at(i)<<", ";
		else std::cout<<novi_vektor.at(i)<<".";
	}

	return 0;
}