/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> vektor)
{
	std::vector<double> neki;
	Matrica matrica;
	for(int i = 1; i < vektor.size(); i++)
	{
		neki.clear();
		
		if(vektor.at(i) >= vektor.at(i - 1))
		{
			neki.push_back(vektor.at(i - 1));
			
			while(i < vektor.size() && vektor.at(i - 1) <= vektor.at(i))
			{
				neki.push_back(vektor.at(i));
				i++;
			}
			
			if(neki.size() > 1)
				matrica.push_back(neki);
		}
	}
	return matrica;
}

Matrica OpadajuciPodnizovi(std::vector<double> vek)
{
	std::vector<double> neki;
	Matrica matrica;
	
	for(int i = 1; i < vek.size(); i++)
	{
		neki.clear();
		if(vek.at(i) <= vek.at(i - 1))
		{
			neki.push_back(vek.at(i - 1));
			
			while(i < vek.size() && vek.at(i - 1) >= vek.at(i))
			{
				neki.push_back(vek.at(i));
				i++;
			}
			
			if(neki.size() > 1)
				matrica.push_back(neki);
		}
	}
	return matrica;
}

int main()
{
	std::vector<double> vek;
	int n;
	
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n; i++)
	{
		double x;
		std::cin >> x;
		vek.push_back(x);
	}
	
	std::cout << "Maksimalni rastuci podnizovi: \n";
	
	Matrica matrica(RastuciPodnizovi(vek));
	
	for(int i = 0; i < matrica.size(); i++)
	{
		for(int j = 0; j < matrica.at(i).size(); j++)
			std::cout << matrica.at(i).at(j) << " ";
			
		std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	
	Matrica opet(OpadajuciPodnizovi(vek));
	
	for(int i = 0; i < opet.size(); i++)
	{
		for(int j = 0; j < opet.at(i).size(); j++)
			std::cout << opet.at(i).at(j) << " ";
			
		std::cout << std::endl;
	}
	
	return 0;
}