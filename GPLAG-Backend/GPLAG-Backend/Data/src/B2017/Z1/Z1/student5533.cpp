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
bool JeLiProst (int n)
{
	if (n<0) {
		n*=-1;
	}
	for (int i=2; i<=sqrt(n); i++) {
		if (n%i==0) {
			return false;
			break;
		}
	}
	return true;
}

int Ternarni (int n)
{
int n1(0), k(1);
	while (n!=0) {
		n1+=k*(n%3);
		k*=10;
		n/=3;
	}
	return n1;
}
bool JeLiSimetrican (int n)
{
	int pom(n), sim(0);
	while (pom!=0) {
		sim=sim*10+pom%10;
		pom/=10;
	}
	if (sim==n) {
		return true;
	}
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool a)
{
	std::vector <int> v1;
	if (a) {
		for (int i=0; i<v.size(); i++) {
			if (JeLiProst(v.at(i)) && JeLiSimetrican(Ternarni(v.at(i)))) {
				v1.push_back (v.at(i));
			}
		}
	}
	if (!a) {
		for (int i=0; i<v.size(); i++) {
			if (!(JeLiProst(v.at(i))) && JeLiSimetrican(Ternarni(v.at(i)))) {
				v1.push_back (v.at(i));
			}
		}
	}
	return v1;
}

int main ()
{
	bool a;
	int broj, broj1;
	std::vector<int> v;
	std::vector<int> v1;
	std::cout <<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >>broj;
		if (broj!=-1) {
			v.push_back(broj);
		}
	} while (broj!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>broj1;
		if (broj1!=1 && broj1!=0) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
		if (broj1==1)
			a=true;
		if (broj1==0)
			a=false;
	} while (broj1!=1 && broj1!=0);
	v1=IzdvojiSimetricneTernarne(v,a);
	if (v1.size()==0) {
		if (a) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		}
		if (!a) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		}
	}
	else if (a) {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<v1.size(); i++) {
			if (i<v1.size()-1)
				std::cout << v1.at(i) <<", ";
			else
				std::cout<<v1.at(i)<<".";
		}
	}
	else if (!a) {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<v1.size(); i++) {
			if (i<v1.size()-1)
				std::cout << v1.at(i) <<", ";
			if (i==v1.size()-1)
				std::cout<<v1.at(i)<<".";
		}
	}
	return 0;
}