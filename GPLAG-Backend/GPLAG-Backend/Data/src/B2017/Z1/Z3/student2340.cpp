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

enum Smjer{Rastuci=1, Opadajuci=2};


bool StepenDvice(int n)
{
	for(int i=0; i<n; i++)
		if(int(pow(2,i))==n) return true;
	 return false;
}

typedef std::deque<std::vector<int>> Matrica;

Matrica MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer(smjerovi))
{
	int br_redova(0);
	
	for(int i(0); i<v.size()-1; i++)
	{
		if(v.at(i)<=v.at(i+1) && StepenDvice(v.at(i) && StepenDvice(v.at(i+1))))
		{
			while(v.at(i)<=v.at(i+1) && i<v.size()-1 && StepenDvice(v.at(i)) && StepenDvice(v.at(i+1)))
				i++;
			br_redova++;
		}
	}
	Matrica M(br_redova, std::vector<int> (0));
	std::vector<int> v1;
	int k(0);
	
	for(int i(0); i<v.size()-1; i++)
	{
		if(v.at(i)<=v.at(i+1) && StepenDvice(v.at(i)) && StepenDvice(v.at(i+1)))
		{
			v1.resize(0);
			while(v.at(i)<=v.at(i+1) && i<v.size()-2 && StepenDvice(v.at(i)) && StepenDvice(v.at(i+1)))
			{
				v1.push_back(v.at(i));
				i++;
			}
			v1.push_back(v.at(i));
			
			if(v.size()-2==i && v.at(i)>=v.at(i-1) && StepenDvice(v.at(v.size()-1)) && StepenDvice(v.at(v.size()-2)))
				v1.push_back(v.at(i+1));
			
			M.at(k).resize(v1.size());
			for(int j(0); j<v1.size(); j++)
				M.at(k).at(j)=v1.at(j);
			
			k++;
		}
	}
	
	
	int br_redova2(0);
	
	for(int i(0); i<v.size()-1; i++)
	{
		if(v.at(i)>=v.at(i+1) && StepenDvice(v.at(i)) && StepenDvice(v.at(i+1)))
		{
			while(v.at(i)>=v.at(i+1) && i<v.size()-2 && StepenDvice(v.at(i)) && StepenDvice(v.at(i+1)))
				i++;
			br_redova2++;
		}
	}
	
	Matrica N(br_redova2, std::vector<int> (0));
	std::vector<int> v2;
	int z(0);
	
	for(int i(0); i<v.size()-1; i++)
	{
		if(v.at(i)>=v.at(i+1) && StepenDvice(v.at(i)) && StepenDvice(v.at(i+1)))
		{
			v2.resize(0);
			while(v.at(i)>=v.at(i+1) && i<v.size()-2 && StepenDvice(v.at(i)) && StepenDvice(v.at(i+1)))
			{
				v2.push_back(v.at(i));
				i++;
			}
			v2.push_back(v.at(i));
			
			if(v.size()-2==i && v.at(i)<=v.at(i-1) && StepenDvice(v.at(v.size()-1)) && StepenDvice(v.at(v.size()-2))) 
				v2.push_back(v.at(i+1));
			
			N.at(z).resize(v2.size());
			for(int j(0); j<v2.size(); j++)
				N.at(z).at(j)=v2.at(j);
			
			z++;
		}
	}
	
	if(smjerovi==Rastuci)
		return M;
	else return N;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<int> v;
	int a;
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i<n; i++)
	{
		std::cin>>a;
		v.push_back(a);
	}
	
	int broj;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>broj;
	
	Smjer smjerovi;
	if(broj==1) smjerovi=Rastuci;
	else if(broj==2) smjerovi=Opadajuci;
	
	Matrica M(MaksimalniPodnizoviStepenaDvojke(v,Smjer(smjerovi)));
	
	if(broj==1)
		std::cout<<"Maksimalni rastuci podnizovi: ";
	else if(broj==2)
		std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
			std::cout<<M[i][j]<<" ";
		std::cout<<std::endl;
	}
	
	//std::cout<<StepenDvice(7);
	
	return 0;
}