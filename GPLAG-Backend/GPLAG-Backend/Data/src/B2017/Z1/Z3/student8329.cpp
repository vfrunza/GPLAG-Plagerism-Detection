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

enum Smjer {Rastuci = 1, Opadajuci};

bool DaLiJeStepenDvojke(int n)
{
	if(n<=0)return false;
	for(int i(0);i<=sqrt(n)+1;i++)
	{
		if(int(pow(2,i))>n)break;
		if(int(pow(2,i))==n)return true;
	}
	return false;
}

std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int>v, Smjer AE)
{
	if(v.size()<=1)return {};

	if(AE==Rastuci)
	{
		std::deque<std::vector<int>>a;
		a.resize(1);
		int j(0);
		for(int i(0);i<v.size()-1;i++)
		{
			if(v.at(i)<=v.at(i+1) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)))
			{
				while((i+1)!=v.size() && v.at(i)<=v.at(i+1) && DaLiJeStepenDvojke(v.at(i)))
				{
					a.at(j).push_back(v.at(i));
					i++;
				}
			if((v.at(i)>=v.at(i-1) || i+1==v.size())&& DaLiJeStepenDvojke(v.at(i)))a.at(j).push_back(v.at(i));
				a.resize(a.size()+1);
				j++;
			}
		}
		if(a.size()==1 && a.at(0).size()==0)return{};
			return a;
	}
	
	else if(AE==Opadajuci)
	{
		std::deque<std::vector<int>>a;
		a.resize(1);
		int j(0);
		for(int i(0);i<v.size()-1;i++)
		{
			if(v.at(i)>=v.at(i+1) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)))
			{
				while(i+1!=v.size() && v.at(i)>=v.at(i+1) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)))
				{
					a.at(j).push_back(v.at(i));
					i++;
				}
				if((i+1==v.size() || v.at(i)<=v.at(i-1)) && DaLiJeStepenDvojke(v.at(i)))a.at(j).push_back(v.at(i));
				a.resize(a.size()+1);
				j++;
			}
		}
		if(a.size()==1 && a.at(0).size()==0)return{};
		return a;
	}
	return {};
}

int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int broj;
    std::cin>>broj;
    std::cout<<"Unesite elemente vektora: ";
    std::vector<int>E;
    for(int i(0);i<broj;i++)
    {
    	int element;
    	std::cin>>element;
    	E.push_back(element);
    }
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int vr;
    std::cin>>vr;
    Smjer RO;
    RO=Smjer(vr);
    if(RO==Rastuci)
    {
    	std::deque<std::vector<int>>v(MaksimalniPodnizoviStepenaDvojke(E,RO));
    	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    	for(int i(0);i<v.size();i++)
    	{
    		for(int j(0);j<v.at(i).size();j++)std::cout<<v.at(i).at(j)<<" ";
    		std::cout<<std::endl;
    	}
    }
    else if(RO==Opadajuci)
    {
    	std::deque<std::vector<int>>v(MaksimalniPodnizoviStepenaDvojke(E,RO));
    	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    	for(int i(0);i<v.size();i++)
    	{
    		for(int j(0);j<v.at(i).size();j++)std::cout<<v.at(i).at(j)<<" ";
    		std::cout<<std::endl;
    	}
    	
    }
    
	return 0;
}