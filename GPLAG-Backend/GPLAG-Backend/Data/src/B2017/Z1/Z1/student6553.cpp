
#include <iostream>
#include <cmath>
#include <vector>

long long int ternarno(int a)
{
	int  cifra(0),i(1);
	long long int broj(0);

	do {
		cifra=a%3;
		
		a/=3;
		broj=broj+cifra*i;
		i*=10;



	} while(a);


	return broj;
}

bool simetricnost (long long int a)
{
	long long int kopija(a),broj(0);
	int cifra(0);
	
	
	do {
		cifra=a%10;
		a/=10;
		broj=broj*10+cifra;


	} while(a);
	if(kopija==broj) return true;
	return false;
}

bool DaLiJeProst(int a)
{
	if(a<0) a=-a;

	if(a%2==0 && a!=2) return false;
	for(int i=2; i<=sqrt(a); i++) {
		if(a%i==0) return false;
	}
	return true;
}
bool DaLiSeNalazi(int a, std::vector<int> d)
{

	for(int i=0; i<d.size(); i++) {
		if(a==d.at(i)) return true;
	}
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>d, bool prost)
{
	std::vector<int> novi;
	for(int i=0; i<d.size(); i++) {
		if(simetricnost(ternarno(d.at(i))) && !DaLiSeNalazi(d.at(i), novi) && DaLiJeProst(d.at(i))==prost && d.at(i)!=1 && d.at(i)!=-1) novi.push_back(d.at(i));
	}

	return novi;

}

int main ()
{
	int a,prost;
	std::vector<int> d;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>a;
		if(a!=-1) d.push_back(a);
	} while (a!=-1);

	std:: cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>prost;
		if(prost!=0 && prost!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(prost!=0 && prost!=1);
	d=IzdvojiSimetricneTernarne(d,prost);
	if(d.size()) {
		if(prost) {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		} else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<d.size(); i++) {

			if(i!=d.size()-1) std::cout<<d.at(i)<<", ";
			else std::cout<<d.at(i)<<".";
		}
	}

	else if(prost) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	return 0;
}