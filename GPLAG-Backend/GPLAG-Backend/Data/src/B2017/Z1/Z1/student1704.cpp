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

bool DaLiJeProst(int n) {
	unsigned int x(abs(n));
	if(x==1) return false;
	for(int i=2; (unsigned int)(i*i)<=x; i++) 
		if(x%i==0) return false;
		
		return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool logicko) {
	std::vector<int> V;
	if(logicko) {
		for(int i=0; i<v.size(); i++) {
			if(DaLiJeProst(v.at(i)) && v.at(i)!=0) {
				int x(abs(v.at(i)));
				int ternar1(0);
				while(x>0) {
					ternar1=ternar1*10 + x%3;
					x/=3;
				}
				int ternar2(0);
				x=ternar1;
				while(x>0) {
					ternar2=ternar2*10 + x%10;
					x/=10;
				}
				if(ternar1==ternar2) {
					bool ponavljanje(true);
					for(int j=0; j<V.size(); j++) 
						if(V.at(j)==v.at(i)) ponavljanje=false;
					if(ponavljanje) V.push_back(v.at(i));
				}
			}
		}
	}
	else {
		for(int i=0; i<v.size(); i++) {
			if(!(DaLiJeProst(v.at(i))) && (abs(v.at(i)))!=1) {
				int x(abs(v.at(i)));
				int ternar1(0);
				while(x>0) {
					ternar1=ternar1*10 + x%3;
					x/=3;
				}
				int ternar2(0);
				x=ternar1;
				while(x>0) {
					ternar2=ternar2*10 + x%10;
					x/=10;
				}
				if(ternar1==ternar2) {
					bool ponavljanje(true);
					for(int j=0; j<V.size(); j++)
					if(V.at(j)==v.at(i)) ponavljanje=false;
					if(ponavljanje) V.push_back(v.at(i));
				}
			}
		}
	}
	
	
	return V;
}


int main ()
{
	std::vector<int> v;
	int broj;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(std::cin>>broj, broj!=-1) v.push_back(broj);
	
	int a;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(std::cin>>a, !(a==1 || a==0)) std::cout<<"Neispravan unos! Unesite ponovo: ";
	bool logicko;
	if(a==1) logicko=true;
	else logicko=false;
	
	std::vector<int> V(IzdvojiSimetricneTernarne(v,logicko));
	if(logicko==true && V.size()!=0) {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<V.size(); i++) {
			if(i==V.size()-1) std::cout<<V.at(i)<<".";
			else std::cout<<V.at(i)<<", ";
		}
	}
	else if(logicko==true && V.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(logicko==false && V.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else  {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<V.size(); i++) {
			if(i==V.size()-1) std::cout<<V.at(i)<<".";
			else std::cout<<V.at(i)<<", ";
		}
	}
	
	return 0;
}