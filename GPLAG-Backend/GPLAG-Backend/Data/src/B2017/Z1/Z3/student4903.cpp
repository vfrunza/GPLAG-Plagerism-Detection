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


bool DaLiJeStepenDvojke (int x)
{
	
	if (x == 1)
		return true;
		
	if (x <= 0)
		return false;
		
	while (x > 1)
	{
		if (x%2 != 0)
			return false;
			
		x/=2;
	}
	
	
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer uslov)
{
	std::deque<std::vector<int>> rezultat;
	
	for (int i{}; i < v.size()-1; i++)
	{
		if (DaLiJeStepenDvojke(v.at(i)) == true && DaLiJeStepenDvojke(v.at(i+1)) == true)
		{
			std::vector<int> pomocni;
			
			if (v.at(i) <= v.at(i+1) && uslov == Smjer::Rastuci)
			{
				pomocni.push_back(v.at(i));
				pomocni.push_back(v.at(i+1));
				
				for (int j{i+1}; j < v.size()-1; j++)
				{
					if (v.at(j) > v.at(j+1))
						break;
						
					if (DaLiJeStepenDvojke(v.at(j+1)) == true && v.at(j) <= v.at(j+1))
						pomocni.push_back(v.at(j+1));
					else
						break;
					
						
					i = j;
				}
				
				
				rezultat.push_back(pomocni);
				
				
			}
			
			if (v.at(i) >= v.at(i+1) && uslov == Smjer::Opadajuci)
			{
				pomocni.push_back(v.at(i));
				pomocni.push_back(v.at(i+1));
				
				for (int j{i+1}; j < v.size()-1; j++)
				{
					if (v.at(j) < v.at(j+1))
						break;
						
					if (DaLiJeStepenDvojke(v.at(j+1)) == true && v.at(j) >= v.at(j+1))
						pomocni.push_back(v.at(j+1));
					else
						break;
						
					i = j;
				}
				
				
				rezultat.push_back(pomocni);
				
				
			}
		}
	}
	
	
	
	return rezultat;
}




int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> upis;
	
	for (int i{}; i < n; i++)
	{
		int x;
		std::cin>>x;
		upis.push_back(x);
	}
	
	
	Smjer uslov;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>n;
	
	while (true)
	{
		if (n == 1 || n == 2)
			break;
			
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>n;
	}
	
	if (n == 1)
		uslov = Smjer::Rastuci;
	if (n == 2)
		uslov = Smjer::Opadajuci;
	
	
	auto ispis = MaksimalniPodnizoviStepenaDvojke(upis,uslov);
	
	if (n == 1 && ispis.size() == 0)
		{
			std::cout<<"Nema maksimalnih rastucih podnizova.";
			return 0;
		}
		
	if (n == 1)
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	
	if (n == 2 && ispis.size() == 0)
		{
			std::cout<<"Nema maksimalnih opadajucih podnizova.";
			return 0;
		}
		
	if (n == 2)
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		
	
	for (int i{}; i < ispis.size(); i++)
	{
		auto v = ispis.at(i);
		
		for (auto x : v)
			std::cout<<x<<" ";
			
		std::cout<<std::endl;
	}
	
	
	return 0;
}