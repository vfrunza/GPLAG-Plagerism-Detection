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

int Prost(int n)
{
	
	if(n<=1) return false;
	
	for(int i(2); i<n; i++)
		if(n%i==0) return false;
	
	return true;
}

bool Simetrican(int n)
{
	int p(n), q(0);
	
	while(p!=0)
	{
		q=q*10+p%10;
		p/=10;
	}
	if(q==n) return true;
	else return false;
}

int PretvoriUTernarni(int n)
{
	int temp(0), p(n);
	
	while(p!=0)
	{
		temp=temp*10+p%3;
		p=p/3;
	}
	while(temp!=0)
	{
		p=p*10+temp%10;
		temp/=10;
	}
	return p;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool vrijednost)
{
	std::vector<int> v1, v2;
	
	for(int i(0); i<v.size(); i++)
	{
		int predznak(1), broj2;
		if(v.at(i)<0) predznak*=(-1);
		broj2=std::abs(v.at(i));
		
		if(vrijednost && Prost(broj2) && Simetrican(PretvoriUTernarni(broj2)))
		{
			//int broj=PretvoriUTernarni(broj)*predznak;
			v1.push_back(v.at(i));
		}
		else if(!vrijednost && !Prost(broj2) && Simetrican(PretvoriUTernarni(broj2)))
		{
			v2.push_back(v.at(i));
		}
	}
	if(vrijednost) return v1;
	else return v2;
}

int main ()
{
	int n, broj;
	std::vector<int> v, v1;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	do
	{
		std::cin>>n;
		if(n!=-1) v.push_back(n);
	}while(n!=-1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>broj;
	while(broj!=1 && broj!=0)
	{
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>broj;
	}
	
	v1=IzdvojiSimetricneTernarne(v,broj);
	
	if(broj==1 && v1.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(broj==1)
	{
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i(0); i<v1.size(); i++)
		{
			if(v1.size()-i==1) std::cout<<v1.at(i)<<".";
			else std::cout<<v1.at(i)<<", ";
		}
	}
	else if(broj==0 && v1.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else if(broj==0)
	{
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i(0); i<v1.size(); i++)
		{
			if(v1.size()-1==i) std::cout<<v1.at(i)<<".";
			else std::cout<<v1.at(i)<<", ";
		}
	}
	
	return 0;
}