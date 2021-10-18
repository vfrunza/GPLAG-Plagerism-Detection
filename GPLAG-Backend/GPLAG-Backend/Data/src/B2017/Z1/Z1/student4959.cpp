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

bool DaLiJeProst(int n){
	if(n<=1)return false; // ukoliko je broj manji od dva on nije prost

	// zadnja izmjena linija 18 "izbacena"
	
	for(int i = 2; i <= std::sqrt(n); i++){
		if(n==2)return true;
		if( n%i == 0)return false;
	}
	return true;	
}
std::vector<int> ternarni(int n){
	std::vector<int> broj;
	
	do{
		broj.push_back(std::abs(n%3));
		n/=3;
	}while(n);
	
	return broj;
}
bool Simetrican(int n){
	// pretvoriti broj i testirati simetricnost
	auto v(ternarni(n));
	
	for(int i(0); i < v.size(); i++)
		if(v.at(i)!=v.at(v.size()-1-i))return false;
	return true;	
	
}
bool NePonavljaSe(std::vector<int> p, int n){
	for(int i(0);i<p.size();i++)
		if(n==p.at(i))return false;
	return true;	
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool prost){
	std::vector<int> povratni;

	for(int i(0); i < v.size(); i++)
		if(DaLiJeProst(v.at(i)) == prost && NePonavljaSe(povratni,v.at(i)) && Simetrican(v.at(i)))
		povratni.push_back(v.at(i));
	return povratni;	
}

int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	for(;;){
		int n;
		std::cin>>n;
		if(n==-1)break;
		v.push_back(n);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prost;
	// treba osigurati unos na tacno 0 tj tacno 1
	do{
		std::cin>>prost;
		if(prost!=0 && prost!=1)std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(prost!=0 && prost!=1);
	
	auto v1 = IzdvojiSimetricneTernarne(v,bool(prost));
	
	if(prost && v1.size()){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i(0);i<v1.size();i++){
			if(i==v1.size()-1)std::cout<<v1.at(i)<<".";
			else std::cout<<v1.at(i)<<", ";
		}
	}
	else if(!prost && v1.size()){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i(0);i<v1.size();i++)
			if(i==v1.size()-1)std::cout<<v1.at(i)<<".";
			else std::cout<<v1.at(i)<<", ";
			
	}else if(prost && !v1.size())
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(!prost && !v1.size())
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		
	return 0;
}