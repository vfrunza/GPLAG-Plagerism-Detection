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

bool ponovi(std::vector<int>c, int broj)
{
	int brojac(0);
	for(int i: c)
		if(broj==i) brojac++;
    if(brojac>=1) return true;
    else return false;
}

bool JeProst(int broj)
{
	if(broj<0) broj=broj*(-1);
	if(broj==0) return false;
	if(broj==2) return false;
	
	for(int i=2; i<=std::sqrt(broj);i++)
	{
		if(broj%i==0) return false;	
	}
	return true;
}

int SimetricniTernarni(int x)
{
	int y(0);
	while(x!=0)
	{
		y*=10;
		y+=std::abs(x%3);
		x/=3;
	}
 	return y;
}

int Ternarni(int x)
{
	int a=SimetricniTernarni(x);
	int t(0);
	while(a!=0)
	{
		t*=10;
		t+=std::abs(a%10);
		a/=10;
	}
	return t;
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v1,bool SuProsti)
{
	std::vector<int>v;
	std::vector<int>v2;
	if(SuProsti==true)
	{
		for(int x: v1)
		{
			if(JeProst(x))
			{
					if(x==1) continue;
						v2.push_back(x);
			}
		}
	}
	else if(SuProsti==false)
		{
		 for(int x: v1)
		 {
		 	if(JeProst(x)==false)
		 	{
				if(x==1) continue;
					v2.push_back(x);
		 	}
		 }
		}
	for(int y: v2)
	{
		if(SimetricniTernarni(y)==Ternarni(y))
		{
			if(ponovi(v,y)==false) 
			{
				 v.push_back(y);
			}
		}
	}
 	return v;
}

int main ()
{
	int n,x;
	std::vector<int>vekt;
	std::vector<int>vekt1;
	std::cout <<"Unesite elemente vektora (-1 za kraj): ";
	while(1)
	{
		std::cin >>n;
		if(n==-1) break;
		if(n==-1) continue;
		vekt.push_back(n);
	}
	std::cout <<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(1)
	{
		std::cin>>x;
		if(x==1 || x==0) break;
		std::cout <<"Neispravan unos! Unesite ponovo: ";
	}
		if(x==1)
		{
			vekt1=IzdvojiSimetricneTernarne(vekt,true);
			if(vekt1.size()==0)
			{
				std::cout <<"Nema prostih simetricnih brojeva u vektoru.";
				return 0;
			}
			std::cout <<"Prosti simetricni brojevi iz vektora su: ";
			for(int i(0);i<vekt1.size();i++)
			{
				if(i<vekt1.size()-1)std::cout << vekt1.at(i) << ", ";
				else std::cout << vekt1.at(i) << ".";
			}
		}
		else if(x==0)
		{
			vekt1=IzdvojiSimetricneTernarne(vekt,false);
			if(vekt1.size()==0) 
			{
				std::cout <<"Nema slozenih simetricnih brojeva u vektoru.";
				return 0;
			}
			std::cout <<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i(0);i<vekt1.size();i++)
			{
				if(i<vekt1.size()-1)std::cout << vekt1.at(i) <<", ";
				else std::cout << vekt1.at(i) <<".";
			}
		}
	return 0;
}
