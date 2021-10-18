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

typedef std::vector <std::vector <double>> VektorVektora;

VektorVektora RastuciPodnizovi (std::vector <double> v)
{
	const double eps(1e-12);
	
	VektorVektora rastuci;
	int red(0), br_clanova(0);
	for (int i = 0; i < static_cast<int>(v.size()) - 1; i++)
	{
		if (v.at(i) <= v.at(i + 1) || (std::abs(v.at(i) - v.at(i + 1)) <= eps*(std::abs(v.at(i)) - std::abs(v.at(i + 1)))))
		{
			if (br_clanova == 0)
				rastuci.push_back(std::vector <double>(0));
			rastuci.at(red).push_back(v.at(i));
			if (i == v.size() - 2)
				rastuci.at(red).push_back(v.at(i + 1));
			br_clanova++;
		}
		else
		{
			if (br_clanova > 0)
			{
				rastuci.at(red).push_back(v.at(i));
				br_clanova = 0;
				red++;
			}
		}
	}
	return rastuci;
}

VektorVektora OpadajuciPodnizovi (std::vector <double> v)
{
	const double eps(std::pow(10, -13));
	VektorVektora opadajuci;
	int red(0), br_clanova(0);
	for (int i = 0; i < static_cast<int>(v.size()) - 1; i++)
	{
		if (v.at(i) >= v.at(i + 1) || (std::abs(v.at(i) - v.at(i + 1)) <= eps*(std::abs(v.at(i)) - std::abs(v.at(i + 1)))))
		{
			if (br_clanova == 0)
				opadajuci.push_back(std::vector <double>(0));
			opadajuci.at(red).push_back(v.at(i));
			if (i == v.size() - 2)
				opadajuci.at(red).push_back(v.at(i + 1));
			br_clanova++;
		}
		else
		{
			if (br_clanova > 0)
			{
				opadajuci.at(red).push_back(v.at(i));
				br_clanova = 0;
				red++;
			}
		}
	}
	return opadajuci;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double>v(n);
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < n; i++)
	{
		std::cin >> v.at(i);
	}
	std::cout << "Maksimalni rastuci podnizovi:\n";
	
	VektorVektora rastuci(RastuciPodnizovi(v));
	for (std::vector<double>k:rastuci)
		{
			for (double x:k)
				std::cout << x << " ";
			std::cout << "\n";
		}
	
	std::cout << "Maksimalni opadajuci podnizovi:\n";
	VektorVektora opadajuci(OpadajuciPodnizovi(v));
	for (std::vector<double>k:opadajuci)
		{
			for (double x:k)
				std::cout << x << " ";
			std::cout << "\n";
		}
	
	return 0;
}