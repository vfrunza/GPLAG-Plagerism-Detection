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

bool DaLiJeProst(int n)
{
	int brojac(0);
	if(n<=1) return false;
	int m=std::sqrt(n);
	for(int i=1; i<=m; i++) {
		if(n%i==0)brojac++;
		if(brojac>1) return false;
	}
	if(brojac==1) return true;
}

bool DaLiJeSimetrican (int n)
{
	int broj=n;
	int suma(0);
	while(broj!=0) {
		int cifra=broj%10;
		suma=suma*10+cifra;
		broj/=10;
	}
	if(suma==n)return true;
	return false;
}
bool Ternarni(int v)
{
	int broj=v;
	int suma(0),suma1(0);
	while(broj!=0) {
		int ostatak=broj%3;
		suma=suma*10+ostatak;
		broj/=3;
	}
	while(suma!=0) {
		int cifra1=suma%10;
		suma1=suma1*10+cifra1;
		suma/=10;
	}
	if(DaLiJeSimetrican(suma1))return true;
	return false;

}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool n)
{
	std::vector<int> prosti, slozeni,prosti1,slozeni1;

	for (int i=0; i<v.size(); i++) {
		if(DaLiJeProst(v.at(i)) && Ternarni(v.at(i))) prosti.push_back(v.at(i));
		if(!DaLiJeProst(v.at(i)) && Ternarni((v.at(i)))) slozeni.push_back(v.at(i));
	}
	
	for(int i=0;i<prosti.size();i++){
		bool isti=false;
		for(int j=0;j<prosti1.size();j++){
			if(prosti.at(i)==prosti1.at(j) && i!=0){
				isti=true;
				break;
			}
		}
		if(!isti)prosti1.push_back(prosti.at(i));
	}
	for(int i=0;i<slozeni.size();i++){
		bool isti=false;
		for(int j=0;j<slozeni1.size();j++){
			if(slozeni.at(i)==slozeni.at(j) && i!=0){
				isti=true;
				break;
			}
		}
		if(!isti)slozeni1.push_back(slozeni.at(i));
	}

	if(n) return prosti1;
	return slozeni1;
}
int main ()
{
	std::vector<int> v,pomocni;
	std::cout<< "Unesite elemente vektora (-1 za kraj): ";
	int broj,n;
	do {
		std::cin>>broj;
		if(broj!=-1) v.push_back(broj);
	} while(broj!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>n;
	while(n!=0 && n!=1) {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>n;
	}

	pomocni=IzdvojiSimetricneTernarne(v,n);
	if(n==1) {
		if(pomocni.size()==0)std::cout<<"Nema prostih simetricnih brojeva u vektoru. ";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<pomocni.size(); i++) {
				if(i==pomocni.size()-1)std::cout<<pomocni.at(i)<<".";
				else std::cout<<pomocni.at(i)<<", ";
			}
		}
	}

	if(n==0) {
		if(pomocni.size()==0)std::cout<<"Nema slozenih simetricnih brojeva u vektoru. ";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";

			for(int i=0; i<pomocni.size(); i++) {
				if(i==pomocni.size()-1)std::cout<<pomocni.at(i)<<".";
				else std::cout<<pomocni.at(i)<<", ";
			}
		}
	}

	return 0;
}