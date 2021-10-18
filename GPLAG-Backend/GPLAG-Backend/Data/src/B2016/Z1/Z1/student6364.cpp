#include <iostream>
#include <cmath>
#include <vector>

typedef std::vector<int>vektor;
bool DaLiSeNalazi(vektor a, int b)
{
	int i(0);
	while(i<int(a.size()))
	{
		if(b==a[i])
			return true;
		i++;
	} return false;
}
vektor ternarni(int n)
{
	int a;
	vektor b; 
	if(n==0) b.push_back(0);
		while(n)
	{
		a=std::abs(n%3);
		b.push_back(a);
		n/=3;
	}
	return b;
}

int Parnost( int x)
{
	vektor b(ternarni(x));
	int brojac;
	vektor cifre{0, 1, 2};
	vektor c;
	for(int i=0; i < 3; i++)
	{
		brojac=0;
		if(DaLiSeNalazi(b, cifre[i]))
		{
			for(int j=0; j<b.size(); j++)
			{
				if(cifre.at(i)==b.at(j))
				brojac++;
			}
			c.push_back(!(brojac%2));
		}
	}
	int i=0;
	while(i < int(c.size())-1)
	{
		if(c.at(i) != c.at(i+1))
			return -1;
		i++;
	}
	
	return c.at(0);
}
vektor IzdvojiGadne (vektor v, bool a)
{
	vektor x;
	bool obrisano;
	for(int i=0; i<int(v.size()); i++)
	{
		if(Parnost(v.at(i)) == a)
			x.push_back(v[i]);
	}
	
	for(int i=0; i<int(x.size()); i++)
	{
		obrisano = false;
		for(int j=i+1; j<int(x.size()); j++)
		{
			if(x[i] == x[j])
			{
				x.erase(x.begin()+j);
				i=0;
				obrisano = true;
			}
		} if(obrisano)
		{
			obrisano = false;
			i = -1;
		}
	}
	
	return x;
}

int main ()
{
	int n;
	vektor v, a, b;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(std::cin>>n, n)
	{
		v.push_back(n);
	}
	a=IzdvojiGadne(v, true);
	b=IzdvojiGadne(v, false);
	std::cout<<"Opaki:";
	for(int i=0; i<a.size(); i++)
		std::cout<<" "<<a[i];
	std::cout<<std::endl<<"Odvratni:";
	for(int i=0; i<b.size(); i++)
		std::cout<<" "<<b[i]; 
	return 0; 
}