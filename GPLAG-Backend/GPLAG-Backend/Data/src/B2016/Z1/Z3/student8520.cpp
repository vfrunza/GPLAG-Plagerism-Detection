/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> raste;
	if(v.size() == 0 || v.size() == 1) 
		return raste;
	for(int i=0; i<v.size()-1; i++)
	{
		std::vector<double> pomocni;
		while(v[i] <= v[i+1])
		{
			pomocni.push_back(v[i]);
			i++;
			if(i == v.size()-1) break;
		}
		if(v[i-1] <= v[i] && i > 0)  
		{
			pomocni.push_back(v[i]);
		}
		if(pomocni.size() != 0) 
		{
			raste.push_back(pomocni);
		}
	}
	return raste;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> opada;
	if(v.size() == 0)
		return opada;
	for(int i=1; i<v.size()-1; i++)
	{
		std::vector<double> pomocni; 
		while(v[i+1] <= v[i] && i<v.size()-1)
		{
			pomocni.push_back(v[i]);
			i++;
			if(i == v.size()-1) break;
		}
		if(v[i] <= v[i-1] && i > 0)
		{
			pomocni.push_back(v[i]);
		}
		if(pomocni.size() != 0)
		{
			opada.push_back(pomocni);
		}
	}
	return opada;
}

int main ()
{
	int n;
	std::vector<double> v;
	std::cout  << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	v.resize(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
	{
		std::cin >> v[i];
	}
	std::vector<std::vector<double>> raste = RastuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i=0; i<raste.size(); i++)
	{
		for(int j=0; j<raste[i].size(); j++)
		{
			std::cout << raste[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::vector<std::vector<double>> opada = OpadajuciPodnizovi(v);
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0; i<opada.size(); i++)
	{
		for(int j=0; j<opada[i].size(); j++)
		{
			std::cout << opada[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}