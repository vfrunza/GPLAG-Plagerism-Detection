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
#include <cmath>
enum Smjer{rastuci=1,opadajuci=2};

bool StepenDvojke(int n)
{
	for(int i=1;i<=n;i*=2)
	{
		if (i==n)
			return true;
	}
	return false;
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer m)
{
	std::deque<std::vector<int>> v1;
	int broj_redova(0);
	
	if(v.size()==0)
		return v1;
	
	if(m==1)
	{
	for(int i=0;i<v.size();i++)
	{
		int brojac(0);
		for(int j=i;j<v.size()-1;j++)
		{
			if((v.at(j)<=v.at(j+1)) && StepenDvojke(v[j]) && StepenDvojke(v[j+1]))
				brojac++;
            else
               break;
		}
		if(brojac>=1)
		{
			v1.resize(v1.size()+1);
			for(int k=0;k<=brojac;k++)
         		v1[broj_redova].push_back(v[k+i]);
        	broj_redova++;
		}
		i+=brojac;
	}	
	return v1;
	}
	else if(m==2)
	{
		for(int i=0;i<v.size();i++)
	{
		
		int brojac(0);
		for(int j=i;j<v.size()-1;j++)
		{
			if((v.at(j)>=v.at(j+1)) && StepenDvojke(v[j]) && StepenDvojke(v[j+1]))
				brojac++;
            else
               break;
		}
		if(brojac>=1)
		{
			v1.resize(v1.size()+1);
			for(int k=0;k<=brojac;k++)
            	v1[broj_redova].push_back(v[k+i]);
        	broj_redova++;
		}
		i+=brojac;
	}	
	return v1;
	}
	
	
}

void IspisiMatricu(std::deque<std::vector<int>> m)
{
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m[i].size();j++)
            std::cout<<m[i][j]<<" ";
        std::cout<<std::endl;    
    }
}


int main ()
{
	std::vector<int>v;
	std::deque<std::vector<int>> dv;
	int n,x;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	{
		int broj;
		std::cin>>broj;
		v.push_back(broj);
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>x;
	if(x==1)
	{
		dv=MaksimalniPodnizoviStepenaDvojke(v,Smjer(rastuci));
		if(dv.size()==0)
			return 0;
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		IspisiMatricu(dv);
	}
	else if(x==2)
	{
		dv=MaksimalniPodnizoviStepenaDvojke(v,Smjer(opadajuci));
		if(dv.size()==0)
			return 0;
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		IspisiMatricu(dv);
	}
		
	return 0;
}