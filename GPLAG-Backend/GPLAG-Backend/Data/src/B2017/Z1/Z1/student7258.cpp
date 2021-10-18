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

int prost (int broj) {
	
	if(broj==1)
		return 2;
	
	for(int i = 2; i<=std::sqrt(broj); i++){
		if(broj%i==0)
			return 0;
	}
	
	return 1;
}

std::vector<int> ternarni(int broj){
	
	std::vector<int> n;
	
	do{
		int ostatak=std::abs(broj%3);
		n.push_back(ostatak);
		broj/=3;
		
	}
	while(broj!=0);
	
	return n;
}

bool simetrican(std::vector<int> n){
	
	int i=0, j=n.size()-1;
	while(i<=j){
		if(n.at(i)!=n.at(j))
			return false;
		i++;
		j--;
	}
	
	return true;
}

bool imaUVektoru(std::vector<int> vec, int x){
	
	for(int i=0; i<vec.size();i++){
		if(x==vec.at(i))
			return true;}
			
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vec, bool prost1){
	
	std::vector<int> rez;
	
	if(prost1){
		
		for(int i=0;i<vec.size();i++){
			
			if(prost(vec.at(i))==1 && simetrican(ternarni(vec.at(i)))){
				if(imaUVektoru(rez,vec.at(i)))
					continue;
				rez.push_back(vec.at(i));
			}
		}
	}
	else{
		
		for(int i=0;i<vec.size();i++){
			
			if(prost(vec.at(i))==0 && simetrican(ternarni(vec.at(i)))){
				if(imaUVektoru(rez,vec.at(i)))
					continue;
				rez.push_back(vec.at(i));
			}
		}
		
	}
	
	return rez;
	
}

int main ()
{
	

	std::vector<int> b;
	
	int x;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do{
		
		std::cin >> x;
		if(x==-1) break;
		b.push_back(x);
	}
	while(x!=-1);
	
	
	int var;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> var;
	while (var != 1 && var != 0) {
		std::cout << "Neispravan unos! ";
		std::cout << "Unesite ponovo: ";
		std::cin >> var;
	}
	
	bool pr(var);
	
	auto a=	IzdvojiSimetricneTernarne(b,pr);
	
	if (a.size() == 0 && pr) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else if (a.size() == 0 && pr != 1) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	
	else {
	
	if (pr) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	
	for(int i = 0; i < a.size(); i++) {
		
		if (i == a.size()-1) std::cout << a.at(i) << ".";
		else std::cout << a.at(i) << ", ";
		
	}
	
	}
	
	return 0;
}