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

bool DaLiJeProst(int n){
	bool prost(true);
	int i;
	for(i=2; i<n; i++){
		if(n%i==0) prost=false;
	}
	return prost;
}
bool SimetricniTernarni(int n){
	bool Simetrican(true);
	std::vector<int> v;
	int i, x, y=0;
	while(n!=0){
		x=int(n/3);
		y=int(n%3);
		n=x;
		v.push_back(y);
	}
	for(i=0; i<v.size(); i++){
		if(v[i]!=v[v.size()-i]) Simetrican=false; break;
		//else Simetrican=false;
	}
	return Simetrican;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> x, bool TN){
	std::vector<int> v;
	int i;
	for(i=0; i<x.size(); i++){
	if(DaLiJeProst(x[i])==TN && SimetricniTernarni(x[i])==true) v.push_back(x[i]);
	}
	return v;
}

int main ()
{
	std::vector<int> v;
	int broj, n, i;
	std::cout<< "Unesite elemente vektora (-1 za kraj): ";
	do{
	std::cin>> broj;
	v.push_back(broj);
	} while(broj!=-1);
	std::cout<< "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>> n;
	
	std::vector<int> v1= IzdvojiSimetricneTernarne(v,n);
	if(v1.size()==0) std::cout<< "Nema slozenih simetricnih brojeva u vektoru.";
	else {
		std::cout<< "Prosti simetricni brojevi iz vektora su: ";
	for(i=0; i<v1.size(); i++){
		if(i==v1.size()-1)
		std::cout<< v1.at(i) << ".";
		else std::cout<< v1.at(i) << ", ";
		
	} }
	return 0;
}
/*#include <iostream>
#include <cmath>
#include <vector>

bool DaLiJeProst(int n){
	bool prosti(true);
	int i;
	for(i=2; i<n; i++){
		if(n%i==0) prosti=false;
	}
	return prosti;
}

bool SimetricniTernarni(int n){
	bool Simetrican(true);
	std::vector<int> v;
	int i, x, y;
	while(n!=0){
		x=int(n/3);
		y=(n%3);
		n=x;
		v.push_back(y);
	}
	for(i=0; i<v.size(); i++){
		if(v[i]==v[v.size()-(++i)]) Simetrican=true;
		else Simetrican=false;
	}
	return Simetrican;
}
int main()
{
    int n;
    std::cout<< "Unesite broj: ";
    std::cin>> n;
    std::cout<< "1 ili 0: " << DaLiJeProst(n);
    std::cout<< "\n1 ili 0: " << SimetricniTernarni(n);
    return 0;
}
*/