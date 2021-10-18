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

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> vektor)
{
	const double eps = 0.00001;
	std::vector<double> pom;
	Matrica rezultat;
	for(int i = 1; i < vektor.size(); i++)
	{
		if(pom.size() == 0)
			pom.push_back(vektor[i - 1]);
		if(vektor[i - 1] < vektor[i] || std::fabs(vektor[i - 1] - vektor[i]) < eps)
		{
			pom.push_back(vektor[i]);
			if(i != vektor.size() - 1)
				continue;
		}
		if(pom.size() > 1)
			rezultat.push_back(pom);
		pom.resize(0);
	}
	return rezultat;
}

Matrica OpadajuciPodnizovi(std::vector<double> vektor)
{
	const double eps = 0.00001;
	std::vector<double> pom;
	Matrica rezultat;
	for(int i = 1; i < vektor.size(); i++)
	{
		if(pom.size() == 0)
			pom.push_back(vektor[i - 1]);
		if(vektor[i - 1] > vektor[i] || std::fabs(vektor[i - 1] - vektor[i]) < eps)
		{
			pom.push_back(vektor[i]);
			if(i != vektor.size() - 1)
				continue;
		}
		if(pom.size() > 1)
			rezultat.push_back(pom);
		pom.resize(0);
	}
	return rezultat;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n = 0;
	std::cin >> n;
	if(n < 0)
		return 0;
	std::vector<double> unos(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n; i++)
		std::cin >> unos[i];
	Matrica rastuci{RastuciPodnizovi(unos)}, opadajuci{OpadajuciPodnizovi(unos)};
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(std::vector<double> red : rastuci)
	{
		for(double element : red)
			std::cout << element << " ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(std::vector<double> red : opadajuci)
	{
		for(double element : red)
			std::cout << element << " ";
		std::cout << std::endl;
	}
	return 0;
}