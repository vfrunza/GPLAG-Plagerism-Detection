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
#include <limits>
#include <cmath>

bool Prostiline (long long int n){
	n=std::fabs(n);
	for (int i=std::sqrt(n); i>1; i--)
	if (n%i==0) return false;
	if(n==0) return false;
	return true; 
}

typedef std::vector<int> Vektor;

Vektor Ternarni(long long int clan){
	clan=std::fabs(clan);
	Vektor v;
	while(clan>=3){
	   v.push_back(clan%3);
	   clan=clan/3;}
	v.push_back(clan);
	return v;
}

bool Simetrican(Vektor v){
	for(int i=0; i<(v.size()/2); i++)
	if(v.at(i)!=v.at(v.size()-i-1)) return false;
	return true;
}

Vektor IzdvojiSimetricneTernarne(Vektor vektor, bool prostiline){
	for(int i=0; i<vektor.size(); i++){
		for(int j=0; j<vektor.size(); j++){
			if(i!=j && vektor.at(i)==vektor.at(j)){
			vektor.erase(vektor.begin()+j);
			j--;}
		}
	}
	Vektor final;
	
	if(prostiline){
		for(int i=0; i<vektor.size(); i++){
			if(Prostiline(static_cast<long long int>(vektor.at(i))) && vektor.at(i)!=1 && vektor.at(i)!=-1){
				Vektor v=Ternarni(static_cast<long long int>(vektor.at(i)));
				if(Simetrican(v)) final.push_back(vektor.at(i)); 
			}
		}
	}
	
	else{
		for(int i=0; i<vektor.size(); i++){
			if(!(Prostiline(static_cast<long long int>(vektor.at(i))))){
				Vektor v=Ternarni(static_cast<long long int>(vektor.at(i)));
				if(Simetrican(v)) final.push_back(vektor.at(i)); 
			}
		}
	}
	return final;
}

int main (){
	Vektor v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(int i=0; i<1000; i++){
		int p;
		while(!(std::cin >> p)) {
        std::cout << "Niste unijeli broj! Ponovite unos: ";
        std::cin.clear(); 
        std::cin.ignore(10000, '\n');}
		
		if(p!=-1) v.push_back(p);
		else break;
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;
	std::cin >> a;
	while(a!=0 && a!=1){
	std::cout << "Neispravan unos! Unesite ponovo: ";
	std::cin >> a;
	}
	Vektor vek(IzdvojiSimetricneTernarne(v, a));
	if(vek.size()){
		if(a==1) std::cout << "Prosti simetricni brojevi iz vektora su: ";
		else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<vek.size(); i++){
		if(i!=vek.size()-1) std::cout << vek.at(i) << ", ";
		else std::cout << vek.at(i) << ".";
	}}
	else if(a==1) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	return 0;
}