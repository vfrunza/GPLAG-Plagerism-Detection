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

enum Smjer {Rastuci = 1, Opadajuci = 2};

bool StepenDvojke(int a)
{
	if(a < 0) return false;
	a = std::abs(a);
	
	int stepen(0);
	
	for(int i=0; i<a; i++)
	{
		stepen = std::pow(2, i);
		
		if(stepen == a) return true;
	}
/*
	int stepen(1);
	
	while(stepen < a)
	{
		stepen = stepen * 2;
		
		if(stepen == a) return true;
	}
	*/
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, int smjer)
{
	std::deque<std::vector<int>> deq;

// Rastuci podnizovi
	if(smjer == 1)
	{
		for(int i=0; i<v.size()-1; i++)
		{
			std::vector<int> pod_nizr(1, v.at(i));
			
			for(int j=i+1; j<v.size(); j++)
			{
				int a(v.at(i));
				int b(v.at(j));
				
				
				if(v.at(j)>v.at(i) && StepenDvojke(a)==true && StepenDvojke(b)==true)
				{
					pod_nizr.push_back(v.at(j));
					i++;
				}
				else 
				{
					break;
				}
			}
			if(pod_nizr.size()>1) 
				deq.push_back(pod_nizr);
		}
		
	}

//Opadajuci podnizovi	
	else if(smjer == 2)
	{
		for(int i=0; i<v.size()-1; i++)
		{
			std::vector<int> pod_nizo(1, v.at(i));
			for(int j=i+1; j<v.size(); j++)
			{
				int a(v.at(i));
				int b(v.at(j));
				
				if(v.at(j) < v.at(i) && StepenDvojke(a)==true && StepenDvojke(b)==true)
				{
					pod_nizo.push_back(v.at(j));
					i++;
				}
				else 
				{
					break;
				}
			}
			if(pod_nizo.size()>1) 
				deq.push_back(pod_nizo);
		}
	}
	
//Brijsanje elemenata koji nisu stepen dvojke	
	for(int i=0; i<deq.size(); i++)
	{
		for(int j=0; j<deq.at(i).size(); j++)
		{
			bool a;
			int b(deq.at(i).at(j));
			a = StepenDvojke(deq.at(i).at(j));
			if(a == false || b < 0)
			{
				deq.at(i).erase(deq.at(i).begin() + j);
			}
		}
	}
	
//Brisanje vektora iz deka koji nemaju 2 ili vise elemenata
	for(int i=0; i<deq.size(); i++)
	{
		if(deq.at(i).size() < 2)
			deq.erase(deq.begin() + i);
	}
	
	return deq;
}

int main ()
{
	std::vector<int> v;
	int br, pravac;
	
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> br;
	
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<br; i++)
	{
		int a;
		std::cin >> a;
		v.push_back(a);
	}
	/*
	
	for(int i=0; i<v.size(); i++)
	{
		int a = v.at(i);
		int b;
		
	//	b=StepenDvojke(a);
		
	//	if(a<0 || b==false)
	//	{
	//		v.erase(v.begin() + i);
	//	}
		
	}*/
	
	
	
	
	
	Smjer s;
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> pravac;
	
	if(pravac == 1) s=Rastuci;
	else if(pravac == 2) s=Opadajuci;
	
	if(s == Rastuci)
	{
		std::deque<std::vector<int>> D;
		
		D = MaksimalniPodnizoviStepenaDvojke(v, s);
		
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		
		for(int i=0; i<D.size(); i++)
		{
			for(int j=0; j<D.at(i).size(); j++)
			{
				std::cout << D.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
		
	}
	else if(s == Opadajuci)
	{
		std::deque<std::vector<int>> D;
		
		D = MaksimalniPodnizoviStepenaDvojke(v, s);
		
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		
		for(int i=0; i<D.size(); i++)
		{
			for(int j=0; j<D.at(i).size(); j++)
			{
				std::cout << D.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	
	return 0;
}