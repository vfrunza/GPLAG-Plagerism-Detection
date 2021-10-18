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

bool DaLiJeProst(int n)
{

	if(n==0 || n==1)return false;
	for(int i(2);i<=std::sqrt(std::llabs(n));i++)
	{
		if(std::llabs(n)%i==0)return false;
	}
	return true;
}

bool DaLiJeSimetrican(int n)
{
	std::vector<int>broj;
	while(n!=0)
	{
		int a;
		a=std::abs(n%3);
		broj.push_back(a);
		n/=3;
	}
	std::vector<int>broj1;
	for(int i=broj.size()-1;i>=0;i--){
		broj1.push_back(broj.at(i));
	}
	if(broj1!=broj)return false;
	return true;
	
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v, bool c)
{
	if(c)
	{
		std::vector<int>a;
		for(int i:v)
		{
			if(DaLiJeProst(i) && DaLiJeSimetrican(i))a.push_back(i);
		}
		if(a.size()<=1)return a;
		for(int i(0);i<a.size()-1;i++){
			for(int j(i+1);j<a.size();j++){
				if(a.at(i)==a.at(j))
				{
					a.erase(a.begin()+j);
					j--;
					
				}
			}
		}
		return a;
		
	}
	
	else
	{
		std::vector<int>e;
		for(int i:v)
		{
			if(!DaLiJeProst(i) && DaLiJeSimetrican(i))e.push_back(i);
		}
		if(e.size()<=1)return e;
		for(int i(0);i<e.size()-1;i++){
			for(int j(i+1);j<e.size();j++){
				if(e.at(i)==e.at(j))
				{
					e.erase(e.begin()+j);
					j--;
					
				}
			}
		}
		return e;
	}
}

int main ()
{
	std::vector<int>v;
	int broj;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do
	{
		std::cin>>broj;
		if(broj!=-1)v.push_back(broj);
		
	}while(broj!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int vr;
	std::cin>>vr;
	do
	{
	if(vr!=0 && vr!=1)
	{
	std::cout<<"Neispravan unos! Unesite ponovo: ";
	std::cin>>vr;
	}
	}while(vr!=0 && vr!=1);
	bool e(vr);
	if(e)
	{
		std::vector<int>v1(IzdvojiSimetricneTernarne(v,e));
		if(v1.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
		{
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i(0);i<v1.size();i++)
			{
				if(i!=v1.size()-1)std::cout<<v1.at(i)<<", ";
				else std::cout<<v1.at(i)<<".";
			}
		}
		
	}
	else
	{
		std::vector<int>v2(IzdvojiSimetricneTernarne(v,e));
		if(v2.size()==0)std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else
		{
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i(0);i<v2.size();i++)
			{
				if(i!=v2.size()-1)std::cout<<v2.at(i)<<", ";
				else std::cout<<v2.at(i)<<".";
			}
		}
	}
	return 0;
}