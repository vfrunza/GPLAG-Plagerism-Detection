#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
bool ProstiBrojevi(int n)
{
	if(n<0) n=-n;
	if(n==0) return true;
	bool prost(true);
	for(int i=2; i<=std::sqrt(n); i++) {
		if(n%i==0) {
			prost=false;
			break;
		}


	}
	if(prost) return true;
	return false;
}

bool DaLiJeSimetrican(int n)
{
	if(n==0) return true;
	if(n<0) n=-n;
	std::deque<int> v1;
	std::deque<int> v2;
	while(n!=0) {
		v1.push_back(n%3);
		v2.push_front(n%3);
		n=n/3;

	}
	if(v1==v2) return true;
	return false;
}
bool NalaziSe(std::vector<int> v,int n)
{
	if(v.size()==0) return false;
	bool nalazi_se(false);
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)==n) {
			nalazi_se=true;
			break;
		}
	}

	if(nalazi_se) return true;

	return false;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v,bool p)
{
	std::vector<int> v1;
	if(p) {
		for(int i=0; i<v.size(); i++) {
			if(v.at(i)!=1 && ProstiBrojevi(v.at(i)) && DaLiJeSimetrican(v.at(i)) && !(NalaziSe(v1,v.at(i))))
				v1.push_back(v.at(i));
		}
	} else {
		for(int i=0; i<v.size(); i++) {
			if(v.at(i)!=1 && !(ProstiBrojevi(v.at(i))) && DaLiJeSimetrican(v.at(i)) && !(NalaziSe(v1,v.at(i))))
				v1.push_back(v.at(i));
		}
	}
	return v1;
}

int main()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	int broj;
	do {

		std::cin>>broj;
		if(broj!=-1)
			v.push_back(broj);

	} while(broj!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 -"<<" za slozene brojeve: ";
	int broj1;
	
	do
	{
	std::cin>>broj1;	
	if(broj1!=0 && broj1!=1)
	{
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
		
		
	}while(broj1!=0 && broj1!=1);
	std::vector<int> v1;
	if(broj1==1) {
		v1=IzdvojiSimetricneTernarne(v,true);
		if(v1.size()==0) 
		{
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size(); i++) {
			std::cout<<v1.at(i);
			if(i!=v1.size()-1)
				std::cout<<", ";
		}

	} else if(broj1==0) {
		v1=IzdvojiSimetricneTernarne(v,false);
		if(v1.size()==0) 
		{std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
		}
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size(); i++) {
			std::cout<<v1.at(i);
			if(i!=v1.size()-1)
			{
				std::cout<<", ";
}

		}
}
std::cout<<".";
return 0;

}
























