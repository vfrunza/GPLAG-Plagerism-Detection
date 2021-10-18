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
std::vector<int>ProvjeriDaLiImaIstihElemenata(std::vector<int>v) {
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.size(); j++) {
			if(v.at(i)==v.at(j) && i!=j) v.erase(v.begin()+j);
			
		}
	}
	return v;
}
std::vector<int> PretvoriUTernarne(std::vector<int>v) {
	int cifra(0),broj(0);
	std::vector<int>y;
	for(int n:v){
	while(abs(n)!=0){
		cifra=abs(n)%3;
		broj=broj*10+cifra;
		n=abs(n)/3;
	}
	y.push_back(broj);
	broj=0;
	}
	return y;
}
int ObrnutBroj(int x) {
	int broj(0), cifra(0);
	while(x!=0) {
		 cifra=x%10;
		broj=broj*10+cifra;
		x=x/10;
	}
	return broj;
}
bool DaLiJeProst(int n) {
	if(n==1) return false;
	if(n!=1 && n<0) n=n*(-1);
	for(int i=2; i<=sqrt(n+1); i++) {
		if(n%i==0) return false;
	}
	return true;
}
bool DaLiJeSimetrican(int n) {
	int b(0);
	b=ObrnutBroj(n);
	if(n==b) return true;
	return false;
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>v, bool a) {
	std::vector<int>potrebniprosti;
	std::vector<int>potrebnislozeni;
	std::vector<int>y=PretvoriUTernarne(v);

		for(int i=0; i<v.size(); i++) {
			if(DaLiJeProst(v.at(i))&& DaLiJeSimetrican(y.at(i))) potrebniprosti.push_back(v.at(i));
			if(!(DaLiJeProst(v.at(i))) && DaLiJeSimetrican(y.at(i))) potrebnislozeni.push_back(v.at(i));
		}
		if(a) return potrebniprosti;
		return potrebnislozeni;
		
	}

int main ()
{
	std::vector<int>v;
	std::vector<int>pomocni;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(1) {
		int i;
		std::cin>>i;
		if(i!=-1) v.push_back(i);
		else break;
	}
	pomocni=ProvjeriDaLiImaIstihElemenata(v);
	int a;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>a;
	do {
		if(a==0 || a==1) break;
		while(a!=0 || a!=1) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin>>a;
			if(a==0 || a==1) break;
		}
		
	}while(1);

	std::vector<int>konacni;
	if(a==1) {
		konacni=IzdvojiSimetricneTernarne(pomocni, true);
		int x=konacni.size();
		if(x==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<konacni.size(); i++) {
				if(i==(konacni.size()-1)) std::cout<<konacni.at(i)<<".";
				else std::cout<<konacni.at(i)<<", ";
			}
		}
	}
	if(a==0) {
		konacni=IzdvojiSimetricneTernarne(pomocni, false);
		int x=konacni.size();
		if(x==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<konacni.size(); i++) {
				if(i==(konacni.size()-1)) std::cout<<konacni.at(i)<<".";
				else std::cout<<konacni.at(i)<<", ";
			}
		}
	}
	return 0;
}