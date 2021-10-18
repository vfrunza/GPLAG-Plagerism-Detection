/*B 2017/2018, Zadaća 1, Zadatak 3

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

bool StepenBrojaDva(int n)
{
	if(n<=0)
		return false;

	while(n!=1) 
	{
		if(n%2!=0) 
		return false;
		
		n/=2;
	}
	return true;
}




enum Smjer {Rastuci=1,Opadajuci=2};

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke( std::vector<int>a,enum Smjer d)
{
	std::deque<std::vector<int>>dek1;
	if(d==1) {
		std::vector<int>v;
		for(int i=0; i<a.size(); i++)
		{
			int p=a.at(i);
			bool m=StepenBrojaDva(p);
			if(m) {
				bool n;
				int k;
				if(i==a.size()-1)
				{
					n=true;
					k=p;
				}
				else 
				{
					k=a.at(i+1);
					n=StepenBrojaDva(k);
				}
				bool s=true;
		if(v.size()!=0 && v.at(v.size()-1)>p) 
				s=false;
				if(n && s && p<=k) 
				{
				v.push_back(p);
				if(i==a.size()-1 && v.size()>=2)
				dek1.push_back(v);
				} else 
				{
					v.push_back(p);
					if(v.size()>=2)
						dek1.push_back(v);
					v.resize(0);
				}
			}
		}
	}


	if(d==2) {
		std::vector<int>v1;
		for(int i=0; i<a.size(); i++) {

			int r=a.at(i);
			bool l=StepenBrojaDva(r);
			if(l) {
				bool g;
				int h;
				if(i==a.size()-1)
				{
					g=true;
					h=r;
				}
				else 
				{
					h=a.at(i+1);
					g=StepenBrojaDva(h);
				}
				bool w=true;
				if(v1.size()!=0 && v1.at(v1.size()-1)<r) 
				w=false;
				if(g && w && (r>=h))
				{
						v1.push_back(r);
						if(i==a.size()-1 && v1.size()>=2)
						dek1.push_back(v1);
				} else 
				{
					v1.push_back(r);
					if(v1.size()>=2)
						dek1.push_back(v1);
					v1.resize(0);
				}

			}
		}
	}
	return dek1;
}


int main ()
{
	int n,m;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int>a;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int broj;
		std::cin>>broj;
		a.push_back(broj);
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";


	do {
		std::cin>>m;
	} while(m!=1 && m!=2);
	
	
	std::deque<std::vector<int>>c;


	if(m==1) 
	{
		std::cout<<"Maksimalni rastuci podnizovi: ";
		c=MaksimalniPodnizoviStepenaDvojke(a,Smjer(Rastuci));
		std::cout<<std::endl;

	}
	if(m==2) 
	{
		c=MaksimalniPodnizoviStepenaDvojke(a,Smjer(Opadajuci));
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		std::cout<<std::endl;
	}

	for(auto x: c) 
	{
		for(int m: x)
		{
			std::cout<<m<< " ";
		}
		std::cout<<std::endl;
	}
	return 0;
}