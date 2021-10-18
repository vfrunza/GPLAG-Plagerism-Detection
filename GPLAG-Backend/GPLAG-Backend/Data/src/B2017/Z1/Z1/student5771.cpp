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

bool ProstBroj (int n){
	if (n<2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i==0) return false;
	}
	return true;
}

int Ternarni(int n){
	int m(n);
	int suma(0);
	int k(1);
	while(n!=0){
		m=n%3;
		n/=3;
		suma+=m*k;
		k*=10;
	}
	return suma;
}

bool Simetrican(int n){
	int m(n);
	int suma(0);
	while(n!=0){
		suma=suma*10 + n%10;
		n/=10;
	}
	if (suma==m) return true;
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a){
	std::vector<int>b_prosti;
	std::vector<int>c_slozeni;
	for (int i = 0; i < v.size(); i++) {
		if(ProstBroj(v.at(i))==true && Simetrican(Ternarni(v.at(i)))) b_prosti.push_back(v.at(i));
		if(ProstBroj(v.at(i))==false && Simetrican(Ternarni(v.at(i)))) c_slozeni.push_back(v[i]);
	}
	if (a) return b_prosti;
	return c_slozeni;
}

int main ()
{
	int n;
	std::vector<int>v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		std::cin>>n;
		if (n==-1) break;
		v.push_back(n);
	}while(n!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int biram;
	do{
		std::cin>>biram;
		if (biram==1) {
			std::vector<int>a(IzdvojiSimetricneTernarne(v, true));
			if (a.size()==0) {
				std::cout<<"Nema prostih simetricnih brojeva u vektoru."; 
				return 0;
			}
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for (int i = 0; i < a.size(); i++) {
				std::cout<<a.at(i);
				if (i!=a.size()-1) std::cout<<", ";
				if (i==a.size()-1) std::cout<<".";
			}
		} else if (biram==0) {
			std::vector<int>a(IzdvojiSimetricneTernarne(v, false));
			if (a.size()==0) {
				std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; 
				return 0;
			}
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
				for (int i = 0; i < a.size(); i++) {
					std::cout<<a.at(i);
					if (i!=a.size()-1) std::cout<<", ";
					if (i==a.size()-1) std::cout<<".";
				}
		} else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while (biram!=1 && biram!=0);
	
	return 0;
}