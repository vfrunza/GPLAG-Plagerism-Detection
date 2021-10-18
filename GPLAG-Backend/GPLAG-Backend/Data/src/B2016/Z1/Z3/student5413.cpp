/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
const double EPS(0.000000000000001);

bool ImaLiGa(const std::vector<std::vector<double>> &PodNiz, const std::vector<double> &v)
{
	for(int i(0); i < PodNiz.size(); i++)
	{
		if(PodNiz[i].size() <= v.size())
		  continue;
		for(int j(0); j < PodNiz[i].size(); j++)
		{
			bool Isti(true);
			if(fabs(PodNiz[i][j] - v[0]) <= EPS && PodNiz[i].size() - j >= v.size())
			{
				for(int k(0); k < v.size(); k++)
				{
					if(fabs(PodNiz[i][j + k] - v[k]) >= EPS)
					  Isti = false;
				}
				if(Isti)
				  return true;
			}
		}
	}
	return false;
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> PodNiz;
	for(int i(0); i < static_cast<int> (v.size() - 1); i++)
	{
		std::vector<double> pomocni;
		for(int k(i + 1); k < v.size(); k++)
		{
			if(k == i + 1 && v[i] <= v[k])
			{
				pomocni.push_back(v[i]);
				pomocni.push_back(v[k]);
			}
			else if(v[k] >= v[k - 1])
			  pomocni.push_back(v[k]);
			else
			  break;
		}
		if(pomocni.size() < 2)
		  continue;
		if(!ImaLiGa(PodNiz, pomocni))
		{
			PodNiz.resize(PodNiz.size() + 1);
			PodNiz[PodNiz.size() - 1] = pomocni;
		}
	}
	return PodNiz;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> PodNiz;
	for(int i(0); i < static_cast<int> (v.size() - 1); i++)
	{
		std::vector<double> pomocni;
		for(int k(i + 1); k < v.size(); k++)
		{
			if(k == i + 1 && v[i] >= v[k])
			{
				pomocni.push_back(v[i]);
				pomocni.push_back(v[k]);
			}
			else if(v[k] <= v[k - 1])
			  pomocni.push_back(v[k]);
			else
			  break;
		}
		if(pomocni.size() < 2)
		  continue;
		if(!ImaLiGa(PodNiz, pomocni))
		{
			PodNiz.resize(PodNiz.size() + 1);
			PodNiz[PodNiz.size() - 1] = pomocni;
		}
	}
	return PodNiz;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> v(n);
	std::cout << "Unesite elemente vektora: ";
	for(double &x : v)
	  std::cin >> x;
	
	auto Rastuci(RastuciPodnizovi(v));
	auto Opadajuci(OpadajuciPodnizovi(v));
	
	std::cout << "Maksimalni rastuci podnizovi:" << std::endl;
	for(auto niz : Rastuci)
	{
		for(auto x : niz)
		{
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi:" << std::endl;
	for(auto niz : Opadajuci)
	{
		for(auto x : niz)
		{
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}