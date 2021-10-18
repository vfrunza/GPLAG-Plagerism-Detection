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
#include<vector>
#include<deque>
#include<cmath>

bool dalijedvojka(int broj)
{
	
		for(int i=0;i<31;i++)
		{
			if(std::pow(2,i)==broj)
			return true;
			else if(std::pow(2,i)>broj)
			break;
		}
		return false;
}

enum Smjer{Rastuci,Opadajuci};
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor, Smjer smjer)
{
	std::deque<std::vector<int>>rastucipodnizovi;
	std::vector<int>rastuci;
	std::vector<int>opadajuci;
	std::deque<std::vector<int>> opadajucipodnizovi;
	
	if(smjer==0)
	{
		
	for(int i=0;i<vektor.size()-1;i++)
	{
		if(dalijedvojka(vektor.at(i))==true)
		{
			
			if(vektor.at(i)<=vektor.at(i+1) && dalijedvojka(vektor.at(i+1)))
			{//ubaci i
			rastuci.push_back(vektor.at(i));
				while((i+1)<vektor.size() && vektor.at(i)<=vektor.at(i+1) && dalijedvojka(vektor.at(i+1)))//dodat za 2
				{
					rastuci.push_back(vektor.at(i+1));
					i++;
				}
			}
		}
		if(rastuci.size()>1)
		rastucipodnizovi.push_back(rastuci);
		rastuci.resize(0);
	}
	return rastucipodnizovi;
	}
	
	 if(smjer==1)
	{ //std::cout<<"bla";
		for(int i=0;i<vektor.size()-1;i++)
		{
			if(dalijedvojka(vektor.at(i))==true)
			{
				if(vektor.at(i)>=vektor.at(i+1) && dalijedvojka(vektor.at(i+1)))
				{opadajuci.push_back(vektor.at(i));
					while((i+1)<vektor.size() && vektor.at(i)>=vektor.at(i+1) && dalijedvojka(vektor.at(i+1)))
					{
						opadajuci.push_back(vektor.at(i+1));
						if((i+1)>=vektor.size())
						{
							continue;
						}
						i++;
					}
				}
			}
			if(opadajuci.size()>1)
			opadajucipodnizovi.push_back(opadajuci);
			opadajuci.resize(0);
		}
		return opadajucipodnizovi;
	}
	
	
}
int main ()
{
	std::vector<int> vektor;
	std::cout<<"Unesite broj elemenata vektora: ";
	int broj1;
	std::cin>>broj1;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<broj1;i++)
	{
		int element;
		std::cin>>element;
		vektor.push_back(element);
	}
	std::deque<std::vector<int>> rastniz;
	std::deque<std::vector<int>> opadaniz;
	int opcija;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>opcija;
	
	if(opcija==1)
	{
		rastniz=MaksimalniPodnizoviStepenaDvojke(vektor,Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: ";
		std::cout<<std::endl;
		for(int i=0;i<rastniz.size();i++)
		{
			for(int j=0;j<rastniz.at(i).size();j++)
			{
				std::cout<<rastniz.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
		
	}
	if(opcija==2)
	{
		opadaniz=MaksimalniPodnizoviStepenaDvojke(vektor,Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		std::cout<<std::endl;
		for(int i=0;i<opadaniz.size();i++)
		{
			for(int j=0;j<opadaniz.at(i).size();j++)
			{
				std::cout<<opadaniz.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
	
}











