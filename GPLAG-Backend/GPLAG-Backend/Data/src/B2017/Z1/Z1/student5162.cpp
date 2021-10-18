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

bool DaLiJeProst(long long int n)
{
	if (std::abs(n)<=1) return false;
	else {
		if(n<0) n=n*(-1);
		for(int i(2); i<=std::sqrt(n); i++) {
			if(n%i==0) return false;;
		}
	}
	return true;
}
bool DaLiJeSimetrican(int n)
{
	unsigned long long int ternarni(0);
	while(std::abs(n)!=0) {
		ternarni=ternarni*10+std::abs(n%3);
		n=n/3;
	}
	unsigned long long int ternarni2(0), pomocni(ternarni);
	while(pomocni!=0) {
		ternarni2=ternarni2*10+pomocni%10;
		pomocni=pomocni/10;
	}
	if(ternarni==ternarni2) return true;
	else return false;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, bool istina)
{
	std::vector<int> pravi;
	if(istina) {
		for(int i(0); i<a.size(); i++) {
			if(DaLiJeProst(a.at(i))) {
				if(DaLiJeSimetrican(a.at(i))) pravi.push_back(a.at(i));
			}
		}
	} else {
		for(int i(0); i<a.size(); i++) {
			if((!(DaLiJeProst(a.at(i)))) && (a.at(i)==0 || abs(a.at(i))>=2 )) {
				if(DaLiJeSimetrican(a.at(i))) pravi.push_back(a.at(i));
			}
		}
	}
	return pravi;
}
int main ()
{
	int x;
	int n;
	std::vector<int> a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>> x;
		if(x!=-1) a.push_back(x);
	} while(x!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>n;
		if(n!=0 && n!=1)
			std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(n!=0 && n!=1);
	if(n==1) {
		std::vector<int> finalni(IzdvojiSimetricneTernarne(a,true)); //Kreiramo vector kojeg nazivamo "finalni" i u njega postavljamo ono sto funkcija IzdvojiSimetricneTernarne vraca
		if(finalni.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i(0); i<finalni.size()-1; i++)
				std::cout<<finalni.at(i)<<", ";
			std::cout<<finalni.at(finalni.size()-1)<<".";
		}
	} else if(n==0) {
		std::vector<int> finalni(IzdvojiSimetricneTernarne(a,false)); //Kreiramo vector kojeg nazivamo "finalni" i u njega postavljamo ono sto funkcija IzdvojiSimetricneTernarne vraca
		if(finalni.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i(0); i<finalni.size()-1; i++)
				std::cout<<finalni.at(i)<<", ";
			std::cout<<finalni.at(finalni.size()-1)<<".";
		}
	}
	return 0;
}