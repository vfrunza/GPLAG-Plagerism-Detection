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
#include <deque>

bool prost(int n){
	if(n<=1) return false;
	for(int i=2; (unsigned int)(i*i)<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}
bool simetrican(int n){ //pretvara u ternarne pa provjerava simetr.
	int x;
	std::deque<int> d;
	
	while(n!=0){
		x=n%3;
		d.push_front(x);
		n/=3;
	}
	for(int i=0; i<d.size(); i++){
		if(d.at(i)!=d.at(d.size()-i-1)) return false;
	}
	
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a){
	std::vector<int> p;
	
	for(int i=0; i<v.size(); i++){
		if(a==prost(v.at(i)) && simetrican(v.at(i))) p.push_back(v.at(i));
	}
	return p;
}

int main ()
{
	std::vector<int> v;
	int br;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::cin>>br;
	while(br!=-1){
		if(br==-1) break;
		v.push_back(br);
		std::cin>>br;
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;
	std::cin>>a;
	for(;;){
		if(a==1 || a==0) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>a;
	}
	if(a==1){
		std::vector<int> prostis(IzdvojiSimetricneTernarne(v,true));
		if(prostis.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else{
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<prostis.size();  i++){
				if(i<prostis.size()-1) std::cout<<prostis.at(i)<<", ";
				else if(i==prostis.size()-1) std::cout<<prostis.at(i)<<".";
			}
		}
	}
	if(a==0){
		std::vector<int> slozenis(IzdvojiSimetricneTernarne(v,false));
		if(slozenis.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else{
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<slozenis.size();  i++){
				if(i<slozenis.size()-1) std::cout<<slozenis.at(i)<<", ";
				else if(i==slozenis.size()-1) std::cout<<slozenis.at(i)<<".";
			}
		}
	}
	return 0;
}