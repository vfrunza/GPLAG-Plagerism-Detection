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

bool ProstBroj(int broj)
{
	if(broj<0) broj=-broj;
	if(broj==0 || broj==1) return false;
	for(int i((int)std::sqrt(broj)); i>1; i--) {
		if(broj%i==0) return false;
	}
	return true;
}

bool SimetricanTernarni(int broj)
{
	if(broj<0) broj=-broj;
	unsigned long long int ternarni(0);
	int i(0);
	while(broj!=0) {
		ternarni+=(broj%3)*pow(10, i);
		broj/=3;
		i++;
	}
	unsigned long long int okrenutternarni(0), pom(ternarni);
	while(pom!=0) {
		okrenutternarni=okrenutternarni*10+pom%10;
		pom/=10;
	}
	if(ternarni==okrenutternarni) return true;
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> ulazni, bool prosti)
{
	std::vector<int> izlazni;
	for(int i(0); i<ulazni.size(); i++) {
		int element=ulazni.at(i);
		int brojac=0;
		for(int j(0); j<i; j++) if(ulazni.at(i)==ulazni.at(j)) brojac++;
		if(ProstBroj(element)==prosti && std::abs(element)!=1 && brojac==0) {
			int broj(element);
			if(element<0) broj=-element;
			if(SimetricanTernarni(broj)) izlazni.push_back(element);
		}
	}
	return izlazni;
}


int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> pocetni;
	int n;
	for(;;) {
		std::cin >> n;
		if(n==-1) break;
		pocetni.push_back(n);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(!(std::cin >> n), !(n==1 || n==0)) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	bool prosti(true);
	if(n==0) prosti=false;
	std::vector<int> izdvojeni(IzdvojiSimetricneTernarne(pocetni, prosti));
	if(izdvojeni.size()==0 && prosti==true) {
		std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(izdvojeni.size()==0 && prosti==false) {
		std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(prosti) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	for(int i(0); i<izdvojeni.size(); i++) {

		std::cout << izdvojeni.at(i);
		if(i!=izdvojeni.size()-1) std::cout << ", ";
		else std::cout << ".";
	}
	return 0;
}