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

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v1,bool prost) 
{	
	std::vector<int> v2;
	//if(prost){
	for ( int i = 0; i < v1.size(); i++) {
		bool s(true);
			for ( int j = 0; j < i; j++) {
				if(v1.at(j)==v1.at(i)){
					s=false;
					break;
				}
			}
		if(!s) continue;
		long long int a (v1.at(i));
		if(a<0)
			a=-a;
		if(a<2) continue;
		bool p(true);
		for ( int j = 2; j <= sqrt(a); j++) {
			if(a%j==0){ 
				p=false;
				break;
			}
		}
		if(!(p==prost)) continue;
		if(p==false) p=true;
		std::vector<int> v3;
		while (a>0) {
			v3.push_back(a%3);
			a/=3;
		}
		for ( int j = 0; j <= v3.size()/2; j++) {
			if(v3.at(j)!=v3.at(v3.size()-1-j)) {
				p=false;
				break;
			}
		}
		if(p) v2.push_back(v1.at(i));
/*	}
}else{
		for (int i = 0; i < v1.size(); i++) {
			int a(abs(v1.at(i)));
			bool s(false);
			if(a<2) continue;
			for (int j = 2; j <= sqrt(a); j++) {
				if(a%j==0) {
					s=true;
					break;
				}
			}
			if(!s) continue;
			std::vector<int> v3;
			while (a>0) {
				v3.push_back(a%3);
				a/=3;
			}
			for (int j = 0; j <= v3.size()/2; j++) {
				if(v3.at(j)!=v3.at(v3.size()-1-j)) {
					s=false;
					break;
				}
			}
				if(s) v2.push_back(v1.at(i));
		}*/
	}
	return v2;
}
	
int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): " ;
	std::vector<int> v1,v2 ;
	int a;
	while (std::cin >> a, a != -1) {
		v1.push_back(a);
	}
	std::cout <<  "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while (std::cin >> a, a!=0 && a!=1) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	if(a==1){
		v2=IzdvojiSimetricneTernarne(v1,true);
		if(v2.size()==0)
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else{
			std::cout << "Prosti simetricni brojevi iz vektora su:" ;
			for (int i = 0; i < v2.size()-1; i++) 
				std::cout << " " << v2.at(i) <<",";
			std::cout << " " << v2.at(v2.size()-1) <<".";
		}
	}else{
		v2=IzdvojiSimetricneTernarne(v1,false);
		if(v2.size()==0)
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else{
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i = 0; i < v2.size()-1; i++)
				std::cout << v2.at(i) << ", ";
			std::cout << v2.at(v2.size()-1) <<".";
		}
	}
		
	
	return 0;
}