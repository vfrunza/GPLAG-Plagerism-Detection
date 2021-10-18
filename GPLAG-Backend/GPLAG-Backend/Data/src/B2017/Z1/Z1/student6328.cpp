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

int Ternarni(int broj)
{
	int n(broj),i(1),ostatak,rez(0);
	while(n!=0) 
	{
		ostatak=n%3;
		n/=3;
		rez+=ostatak*i;
		i*=10;
	}
	return rez;
}

bool Simetrican(int broj)
{
	int n(broj),temp(0),a;
	while(broj!=0) 
	{
		a=broj%10;
		broj/=10;
		temp=temp*10+a;
	}
	if(n==temp) return true;
	return false;
}

bool Prost(int broj)
{
	if(broj==0) return false;
	if(broj<2) return false;
	if(broj==2) return true;
	if(broj%2==0) return false;
	for(int i=3; i<=sqrt(broj); i+=2) {
		if(broj%i==0) return false;
	}
	return true;
}

bool NijeProst(int broj)
{
	if(broj==0) return true;
	if(broj<1) return true;
	if(broj==2) return false;
	if(broj%2==0) return true;
	for(int i=3; i<=sqrt(broj); i++) {
		if(broj%i==0) return true;
	}
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a,bool n)
{
	std::vector<int> novi;
	if(n==true) {
		for(int i=0; i<a.size(); i++) {
			int s=Ternarni(a.at(i));
			if(Simetrican(s)) {
				int br=a.at(i);
				if(Prost(br)) novi.push_back(br);
			} 
		}
	} 
	else if(n==false) {
		for(int i=0; i<a.size(); i++) {
			int s=Ternarni(a.at(i));
			if(Simetrican(s)) {
				int br=a.at(i);
				if(NijeProst(br)) novi.push_back(br);
			} 
		}
	}

	return novi;
}


int main ()
{
	int n;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int>a;
	for(;;) {
		int br;
		std::cin>>br;
		if(br==-1) break;
		a.push_back(br);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>n;
	for(;;) {
		if(n==1 || n==0) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>n;
	}
	std::vector<int>niz;
	niz=IzdvojiSimetricneTernarne(a,n);
	if(niz.size()==0 && n==1) {
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(niz.size()==0 && n==0) {
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(n==1) {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<niz.size(); i++) {
			std::cout<<niz.at(i);
			if (i<niz.size()-1) std::cout<<", ";
		}
		std::cout<<".";
		return 1;
	}
	if (n==0) {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<niz.size(); i++) {
			std::cout<<niz.at(i);
			if(i<niz.size()-1)std::cout<<", ";
		}
		std::cout<<".";
		return 1;
	}
	return 0;
}