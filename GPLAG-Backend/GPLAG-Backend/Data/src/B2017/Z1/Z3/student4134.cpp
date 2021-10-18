#include <iostream>
#include <deque>
#include <vector>



enum Smjer { Rastuci, Opadajuci };

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> V, Smjer s )
{
	std::deque<std::vector<int>>  DEKRA;
	std::deque<std::vector<int>>  DEKOP;

	if(s==Rastuci) {
		int i,j=0;

		for( i=0 ; i < V.size()-1; i++ ) 
		{
			if(V.at(i)<V.at(i+1))
			{
				std::vector<int> V1;
				for(j=i; j<V.size()-1; j++)
				{
					if(jeStepenDva(V.at(j)) && V.at(j)<V.at(j+1)) V1.push_back(V.at(j));
					else 
					{
						if(jeStepenDva(V.at(j))) V1.push_back(V.at(j));
						break;
					}
					if(j==V.size()-2)
					{
						if(jeStepenDva(V.at(j+1))) V1.push_back(V.at(j+1));
						break;
					}
				}
				if(V1.size()>1) DEKOP.push_back(V1);
				i=j;
			}
		}

	} else if(s==Opadajuci) {
		int i,j=0;

		for( i=0 ; i < V.size()-1; i++ ) 
		{
			if(V.at(i)>V.at(i+1)) 
			{
				std::vector<int> V1;
				for(j=i; j<V.size()-1; j++)
				{
					if(jeStepenDva(V.at(j)) && V.at(j)>V.at(j+1)) V1.push_back(V.at(j));
					else 
					{
						if(jeStepenDva(V.at(j))) V1.push_back(V.at(j));
						break;
					}
					if(j==V.size()-2)
					{
						if(jeStepenDva(V.at(j+1))) V1.push_back(V.at(j+1));
						break;
					}
				}
				if(V1.size()>1) DEKOP.push_back(V1);
				i=j;
			}
		}

	}

	if(Rastuci)
		return DEKRA;
	else if(Opadajuci)
		return DEKOP;
}

int main ()
{
	std::vector<int> V;
	int a,b;
	int unos;

	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>a;

	std::cout<<"Unesite elemente vektora: ";
	
	for(int i=0; i<a; i++) {
		std::cin>>b;
		V.push_back(b);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>unos;

	if(unos==1) {
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		for(auto prom: MaksimalniPodnizoviStepenaDvojke(V,Rastuci)) 
		{
			for(auto x: prom) 
			{
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	} 
	else 
	{
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		for(auto prom: MaksimalniPodnizoviStepenaDvojke(V,Opadajuci)) 
		{
			for(auto x: prom)
			{
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}
