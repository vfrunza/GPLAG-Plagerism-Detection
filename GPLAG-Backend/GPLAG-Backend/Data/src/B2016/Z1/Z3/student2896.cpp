/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9..
	
*/

#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> niz)
{
	std::vector<std::vector<double>> v(0);
	int n = niz.size();
	for(int i=0; i<n; i++)
	{
		int duzina = 1;
		for(int j=i+1; j<n; j++)
		{
			if(niz.at(j) >= niz.at(j-1))
			{
				duzina++;
			}
			else
			{
				break;
			}
		}
		if(duzina >= 2)
		{
			std::vector<double> temp(0);
			for(int j=i; j<i+duzina; j++)
			{
				temp.push_back(niz.at(j));
			}
			v.push_back(temp);
			i += duzina -1;
		}
	}
	return v;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> niz)
{
	std::vector<std::vector<double>> v(0);
	int n = niz.size();
	for(int i=0; i<n; i++)
	{
		int duzina = 1;
		for(int j=i+1; j<n; j++)
		{
			if(niz.at(j) <= niz.at(j-1))
			{
				duzina++;
			}
			else
			{
				break;
			}
		}
		if(duzina >= 2)
		{
			std::vector<double> temp(0);
			for(int j=i; j<i+duzina; j++)
			{
				temp.push_back(niz.at(j));
			}
			v.push_back(temp);
			i+=duzina -1;
		}
	}
	return v;
}



int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> niz(n);
	for(int i=0; i<n; i++)
	{
		double unos;
		std::cin >> unos;
		niz.at(i) = unos;
	}
	std::vector<std::vector<double>> v = RastuciPodnizovi(niz);
	std::vector<std::vector<double>> v2 = OpadajuciPodnizovi(niz);
	std::cout << "Maksimalni rastuci podnizovi: \n";
	for(int i=0; i<v.size(); i++)
	{
		for(double x : v.at(i))
		{
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	for(int i=0; i<v2.size(); i++)
	{
		for(double x: v2.at(i))
		{
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}