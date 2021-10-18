#include <cmath>
#include <iostream>
#include <vector>

bool Prost(int x)
{
	if(x<=1) return false;
	for(int i=2; i<x; i++) if(x%i==0) return false;
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool b)
{
	std::vector<int> p, s, p1, s1;
	
	for(int x:v)
	{
		if(Prost(x)) p.push_back(x);
		else s.push_back(x);
	}
	
	if(b==true)
	{
		for(int k:p)
		{
			int z=0, i=0, kk=k;
			do
			{
				int y=k%3;
				z+=y*pow(10,i);
				i++;
				k/=3;
		
			}while(k!=0);
			
			int zz=0, zzz=z;
			
			do
			{
				int l=zzz%10;
				zz+=l*pow(10, i);
				i--;
				zzz/=10;
			}while(zzz!=0);
			zz/=10;
			
			if(z==zz) p1.push_back(kk);
			
		}
	}
	
	else
	{
		for(int k:s)
		{
			int z=0, i=0, kk=k;
			do
			{
				int y=k%3;
				z+=y*pow(10,i);
				i++;
				k/=3;
		
			}while(k!=0);
			
			int zz=0, zzz=z;
			
			do
			{
				int l=zzz%10;
				zz+=l*pow(10, i);
				i--;
				zzz/=10;
			}while(zzz!=0);
			zz/=10;
			
			if(z==zz) s1.push_back(kk);
			
		}
	}
	
	if(b) return p1;
	return s1;
}

int main ()
{

	std::vector<int> v;
	bool b;
	int x;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	for(int i=0; i<1000; i++)
	{
		int y;
		std::cin>>y;
		if(y==-1) break;
		v.push_back(y);
	}
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	for(int l=0; l<100; l++)
	{
		std::cin>>x;
		if(x!=0 && x!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
		else break;
	}
	
	if(x==1) b=true;
	else b=false;
	
	std::vector<int> t=IzdvojiSimetricneTernarne(v, b);
	
	int j=0;
	
	for(int z:t)
	{
		j++;
	}
	
	int k=0;
	
	if(j==0)
	{
		if(b==true) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	
	if(b==true) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	
	for(int zz:t)
	{
		if(k<j-1) std::cout<<zz<<", ";
		else std::cout<<zz<<".";
		k++;
	}
	
	return 0;
}