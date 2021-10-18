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

bool Simetrican (int n)
{
	int brojac=0;
	int brojac2=0;
	std::vector<int> broj;
	while (n>0) {
		int ostatak=n%3;
		n=n/3;
		broj.push_back(ostatak);
		brojac++;
	}
	
	for (int j=0; j<brojac/2; j++) {
		if (broj.at(j)==broj.at(brojac-1-j))
			brojac2++;
	}
	if (brojac2==brojac/2)
		return true;
	else
		return false;
}

bool DaLiJeProst (int n)
{
	if (n<1)
		n*=-1;
	if (n==1) return false;
	if (n==2) return true;
	if (n%2==0) return false;
	for (int i=3; i<n-1; i++) {
		if (n%i==0)
			return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool vrsta)
{
	std::vector<int> prosti;
	std::vector<int> slozeni;
	std::vector<int> terprosti;
	std::vector<int> terslozeni;

	for (int i=0; i<v.size(); i++) {
		if (Simetrican(v.at(i))) {
			if (DaLiJeProst(v.at(i)))
				prosti.push_back(v.at(i));
			else
				slozeni.push_back(v.at(i));
		}
	}
	if (vrsta==1)
		return prosti;
	if (vrsta==0)
		return slozeni;
}

int main ()
{

	std::vector<int> vprosti;
	int temp;
	int a;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		while (!(std::cin >> temp)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Neispravan unos! Unesite ponovo: ";
		}
		if (temp!=-1)
			vprosti.push_back(temp);
	} while (temp!=-1);
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin >> a;
		if (a!=0 && a!=1)
			std::cout << "Neispravan unos! Unesite ponovo: ";
	} while (a!=1 && a!=0);
	std::vector<int> proba=IzdvojiSimetricneTernarne (vprosti, bool (a));
	if (proba.size()==0 && a==1) {
		std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	if (proba.size()==0 && a==0) {
		std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	if (proba.size()>0 && a==1) {
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<proba.size()-1; i++)
			std::cout << proba.at(i) << ", ";
		std::cout << proba.at(proba.size()-1) << ".";
		return 0;
	}
	if (proba.size()>0 && a==0) {
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<proba.size()-1; i++)
			std::cout << proba.at(i) << ", ";
		std::cout << proba.at(proba.size()-1) << ".";
	}
	return 0;
}