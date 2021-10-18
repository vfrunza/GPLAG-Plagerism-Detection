#include <iostream>
#include <vector>
#include <string>

bool DaLiJeProst(int n)
{
	if(n<=1) return false;

	for(int i=2; (unsigned int)(i*i)<=n;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool jeProst)
{
	std::vector<int> t;
	for(int x : v)
	{
		long temp(x);
		if(temp<0) temp*=-1;
		if(DaLiJeProst(temp)==jeProst && temp != 1)
		{			
			std::vector<int> br;
			while(temp>0)
			{
				br.push_back(temp%3);
				temp/=3;
			}
			bool jeSimetrican=true;
			for(int i=0;i<br.size()/2;i++) 
			{
				if(br.at(i)!=br.at(br.size()-i-1)) 
				{
					jeSimetrican=false;
					break;
				}
			}
			if(jeSimetrican) 
			{
				bool ubaciti=true;
				for(int a : t)
				{
					if(a==x)
					{
						ubaciti=false;
						break;
					}
				}
				if(ubaciti) t.push_back(x);
			}
		}
	}
	return t;
}

int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	while(1)
	{
		int unos;
		std::cin>>unos;
		if(unos==-1) break;
		v.push_back(unos);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prosti;
	while(1)
	{
		std::cin>>prosti;
		if(prosti!=1 && prosti !=0) 
		{
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
		else break;
	}
	std::vector<int> t(IzdvojiSimetricneTernarne(v,prosti));
	if(prosti)
	{
		if(t.size()==0)
		{
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		}
		else
		{
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0;i<t.size();i++)
			{
				if(i<t.size()-1) std::cout<<t.at(i)<<", ";
				else std::cout<<t.at(i)<<".";
			}
		}
	}
	else
	{
		if(t.size()==0)
		{
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		}
		else
		{
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0;i<t.size();i++)
			{
				if(i<t.size()-1) std::cout<<t.at(i)<<", ";
				else std::cout<<t.at(i)<<".";
			}
		}
	}
}