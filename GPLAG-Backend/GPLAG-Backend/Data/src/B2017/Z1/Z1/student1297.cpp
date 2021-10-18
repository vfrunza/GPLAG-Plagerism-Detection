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
#include <iomanip>
#include <cmath>

std::vector<int> Filtriraj(std::vector<int> q) {
	std::vector<int> filtriran;
	for(int i=0;i<q.size();i++) {
		for(int j=i+1;j<q.size();j++){
			if(q.at(i) == q.at(j)) {
				for(int k=j+1;k<q.size();k++) {
					q.at(k-1) = q.at(k);
				}
				q.resize(q.size()-1);
				j--;
			}
	}
}
	
	filtriran = q;
	
	return filtriran;
}



std::vector<int> Ternaran(int x) {
	std::vector<int> d;
	int c{0};
	while(x!=0) {
		c = x%3;
		d.push_back(c);
		x = x/3;
	}
	
	return d;
}

bool Simetrican(int broj) {
	std::vector<int> r{Ternaran(broj)};
	std::vector<int> u;
	
	for(int i=int(r.size())-1; i>=0; i--) {
		u.push_back(r.at(i));
	}
	
	if(r==u) return true;
	
	return false;

}

bool Prost(int element) {
	int a{1};
	for(int i=2;i<element;i++) {
		if(element % i == 0) {
			a=0;
			return a;
		}
	}
	
	return a;
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> o, bool a) {
	std::vector<int> k;
	std::vector<int> w;
	
	w = Filtriraj(o);

	
	if(a) {
		for(int i=0; i <= int(w.size()) - 1; i++) {
			if( Prost(w.at(i)) && Simetrican(w.at(i)) ) {
				k.push_back(w.at(i));
			}
		}
	}
	
	else {
		for(int i=0; i <= int(w.size()) - 1; i++) {
			if( !Prost(w.at(i)) && Simetrican(w.at(i)) ) {
				k.push_back(w.at(i));
			}
		}
	}
	
	
	return k;
	
}



int main ()
{
	int a;
	std::vector<int> vektor;
	std::vector<int> p;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	for(;;) {
		int broj;
		std::cin>>broj;
		if(broj==-1) break;
		vektor.push_back(broj);
	}
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;) {
		std::cin>>a;
		if(a==0 || a==1) break; 
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		
		}
		
		p = IzdvojiSimetricneTernarne(vektor,a);

	
	if(a==0) {
		
		if(p.size() == 0) {
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
		}
		
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			int i;
	for(i=0;i<int(p.size())-1; i++) {
		std::cout<<p.at(i)<<", ";
	}
	std::cout<<p.at(i)<<".";
	}
	
	}
	
	else {
		
		if(p.size() == 0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		
		else { 
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			int i;
	   for(i=0;i<int(p.size())-1; i++) {
		std::cout<<p.at(i)<<", ";
	}
	std::cout<<p.at(i)<<".";
	
	}
	
	}
	

	return 0;
}