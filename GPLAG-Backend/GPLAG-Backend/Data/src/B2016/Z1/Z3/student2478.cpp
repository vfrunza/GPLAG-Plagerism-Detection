/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v)
	{
		std::vector<std::vector<double>> m;
		int i = 1;
		
		while (i < v.size())
		{
			std::vector<double> p;
			p.push_back (v.at(i - 1));
			while (i < v.size() && v.at(i) >= v.at(i - 1))
				p.push_back (v.at(i)), i++;
			if (p.size() > 1)
				m.push_back(p);
			++i;
		}
		return m;
	}
std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v)
	{
		std::vector<std::vector<double>> m;
		int i = 1; 
		 
		while (i < v.size())
		{
			std::vector<double> p;
			p.push_back (v.at(i - 1));
			while (i < v.size() && v.at(i) <= v.at(i - 1))
				p.push_back (v.at(i)), i++;
			if (p.size() > 1)
				m.push_back(p);
			++i;
		}
		return m;
	}
#include <limits>
int main ()
{
	std::cout << std::numeric_limits<long int>::max() << std::endl;
	return 0;
	auto v = std::vector<double>{1, 2, 3, 4, 3, 2, 1, 2, 3, 4};
	auto m = RastuciPodnizovi(v);
	std::cout << m.size() << " " << m.at(0).size() << std::endl;
	for (const auto &i : m)
		{
			for (const auto &j : i)
				std::cout << j << " ";
			std::cout << std::endl;
		}
	std::cout << std::endl << std::endl;
	auto m1 = OpadajuciPodnizovi(v);
	std::cout << m1.size() << " " << m1.at(0).size() << std::endl;
	for (const auto &i : m1)
		{
			for (const auto &j : i)
				std::cout << j << " ";
			std::cout << std::endl;
		}
	return 0;
}