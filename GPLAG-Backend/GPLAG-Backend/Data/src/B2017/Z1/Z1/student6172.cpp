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
#include <iomanip>
bool Prost(int n)
{
	n=std::abs(n);
	if(n<=1) return false;
	for(int i=2; i<=std::sqrt(n); i++) {
		if(n%i==0) return false;
	}
	return true;
}
int Ternarni(int x)
{
	int predznak(1);
	if(x<0) {
		predznak=-1;
		x=-x;
	}
	int pomocni(0),br(0);
	while(x!=0) {
		pomocni+=(x%3)*std::pow(10,br);
		br++;
		x=x/3;
	}
	return predznak*pomocni;
}
bool Simetrican(int x)
{
	if(x<0) x=-x;
	int temp(x);//pamtim vrijednost broja x da kasnije mogu uporediti je li jednak dobijenom naopakom broju
	int broj(0);
	while(temp!=0) {
		broj=(temp%10)+broj*10;//dobijamo broj okrenut naopako
		temp=temp/10;
	}
	return(x==broj);
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>v,bool p)
{
	std::vector<int>k;

	for(int i=0; i<v.size(); i++) {
		int n=v.at(i);//radi lakseg pisanja
		if(p==Prost(n)) {
			bool postoji(false);//pretpostavimo da se broj n ne nalazi u vektoru k
			for(int j=0; j<k.size(); j++) {
				if(n==k.at(j)) postoji=true;
			}//provjeravamo da li se broj n vec nalazi u vektoru k
			if(!postoji) {
				if(Simetrican(Ternarni(n))) k.push_back(n);//ternarni vraca broj,fji simetrican prosljedjujemo broj,ona vraca logicku vrijednost
			}

		}
	}
	return k;
}

int main ()
{
	std::vector<int>v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int x;
	for(;;) {

		std::cin>>x;

		if(x==-1) break;
		else v.push_back(x);
	}
	bool p;
	int y;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>y;
	while(y!=0 && y!=1) {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin.clear();
		std::cin>>y;
	}
	p=y;
	std::vector<int>k(IzdvojiSimetricneTernarne(v,p));
	if(k.size()==0) {
		if(p) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	} else {
		if(p==1)
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<k.size(); i++) {
			if(i==k.size()-1) std::cout<<k.at(i)<<".";
			else std::cout<<k.at(i)<<", ";
		}
	}
	return 0;
}