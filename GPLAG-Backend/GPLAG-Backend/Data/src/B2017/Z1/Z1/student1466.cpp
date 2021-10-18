#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> IntVector;
//Provjera za prost broj
bool prost(int broj)
{
	long int test=broj;
	if(test<0) test*=-1;
	if(test==0) return false;
	for(int i=2; i<test; i++) {
		if(test%i==0) return false;
	}
	return true;
}         
IntVector IzdvojiSimetricneTernarne(IntVector x, bool on_off)
{
	IntVector c;
	for(int i=0; i<x.size(); i++) {
		if(x.at(i)==1 || x.at(i)==-1) continue;
		if(on_off==prost(x.at(i))) {
			
			long int temp=x.at(i);
			//Pretvaranje u ternarni broj
			IntVector ternar;
			while(temp!=0) {
				int cifra=0;
				cifra=temp%3;
				ternar.push_back(cifra);
				temp/=3;
			}
			//Provjera da li je broj simetrican
			bool truth=true;
			for(int l=0; l<(ternar.size()/2); l++){
				if(ternar.at(l)!=ternar.at(ternar.size()-1-l)){
					truth=false;
					break;
				}	
			}
			if(truth) {
				c.push_back(x.at(i));
			}
		}
	}
	//Izbacivanje clanova koji se ponavljaju
	for(int i=0; i<c.size(); i++){
		for(int j=i+1; j<c.size(); j++){
			if(c.at(i)==c.at(j)){
				c.erase(c.begin()+j);
				j--;
			}
		}
	}
	return c;
}
int main ()
{
	IntVector a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
		std::cin>>broj;
		if(broj!=-1) a.push_back(broj);
	} while(broj!=-1);

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool prekidac;
	int istina;
	do {
		std::cin>>istina;
		if(!(istina>=0 && istina<=1 )) std::cout<<"Neispravan unos! Unesite ponovo: ";

	} while(!(istina>=0 && istina<=1));
	prekidac=istina;
	IntVector c;
	c=IzdvojiSimetricneTernarne(a, prekidac);
	if(c.size()==0 && prekidac==true) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(c.size()==0 && prekidac==false) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else if(prekidac==true) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else if(prekidac==false) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	
	for(int i=0; i<c.size(); i++) {
		std::cout<<c.at(i);
		if(i<c.size()-1) std::cout<<", ";
		else std::cout<<".";
	}


	return 0;
}
