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
#include <exception>
std::vector<int> SviSuPozitivni (std::vector <int> v){
	for (int i=0;i<v.size();i++){
		if (v.at(i)<0) v.at(i)=abs(v.at(i));
	}
	return v;
}
std::vector<int> IzbaciElement (std::vector <int> v,int x){
		std::vector<int> v1;
		for (int i=0; i<v.size(); i++) {
		if (v.at(i)!=x) v1.push_back(v.at(i));
		}
	return v1;
}
std::vector<int> IzbaciJednakeElemente (std::vector <int> v)
{
	std::vector<int> v1;
	for (int i=0; i<v.size(); i++) {
		int brojac(0);
		for (int j=0; j<i; j++) {
			if (v.at(i)==v.at(j)) brojac++;
		}
		if (brojac==0) v1.push_back(v.at(i));
	}
	return v1;
}
bool DaLiJeProst (int a)
{
	if(a<=1) return false;
	for (int i=2;i<=sqrt(a);i++)
	if (a%i==0) return false;
	return true;
}
int BrojNaopacke (int n)
{
	int novi;
	novi=n%10;
	while(n!=0) {
		n/=10;
		novi=10*novi+n%10;
		if (n==0) break;
	}
	novi/=10;
	return novi;
}
int PretvoriUTernarni (int n)
{
	int ternarni;
	ternarni=n%3;
	while(n!=0) {
		n/=3;
		if (n%3==0) ternarni*=10;
		else ternarni=ternarni*10+n%3;
	}
	ternarni=BrojNaopacke(ternarni);
	return ternarni;
}
std::vector <int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a)
{
	v=IzbaciJednakeElemente(v);
	v=IzbaciElement(v,1);
	std::vector<int> vrati(0);
	for (auto x:v) {
		if ((a==true) && (DaLiJeProst(x)==true) && ((PretvoriUTernarni(x))==BrojNaopacke(PretvoriUTernarni(x))) ) {
			vrati.push_back(x);
		}
		if ((a==false) && (DaLiJeProst(x)==false) && (PretvoriUTernarni(x))==BrojNaopacke(PretvoriUTernarni(x))) {
			vrati.push_back(x);
		}
	}
	return vrati;
}
int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	int pom;
	std::cin>>pom;
	while (pom!=-1) {
		v.push_back(pom);
		std::cin>>pom;
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prost1;
	do {
		std::cin>>prost1;
		if(prost1!=0 && prost1!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(prost1!=0 && prost1!=1);
	bool prost=prost1;
	if (IzdvojiSimetricneTernarne(v,prost).empty()){
		if (prost==true)  std::cout<< "Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	} 
	else{v=IzdvojiSimetricneTernarne(v,prost);
		if (prost==true) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<v.size()-1; i++) std::cout<<v.at(i)<<", ";
		std::cout<<v.at(v.size()-1)<<".";
	}
	return 0;
}