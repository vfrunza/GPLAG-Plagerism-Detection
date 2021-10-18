/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> m;
	int br(1);
	int i(0);
	while(i<v.size()-1)
	{
		if(v[i]<=v[i+1])
		{
			m.resize(br);
			while(v[i]<=v[i+1])
			{
				m[br-1].push_back(v[i]);
				i++;
				if(i>=v.size()-1) break;
			}
			m[br-1].push_back(v[i]);
			br++;
			i++;
		}
		else i++;
	}
	return m;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> m;
	int br(1);
	int i(0);
	while(i<v.size()-1)
	{
		if(v[i]>=v[i+1])
		{
			m.resize(br);
			while(v[i]>=v[i+1])
			{
				m[br-1].push_back(v[i]);
				i++;
				if(i>=v.size()-1) break;
			}
			m[br-1].push_back(v[i]);
			br++;
			i++;
		}
		else i++;
	}
	return m;
}

int main ()
{
	std::vector<double> v;
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
	{
		int a;
		std::cin >> a;
		v.push_back(a);
	}
	std::vector<std::vector<double>> x, y;
	x=RastuciPodnizovi(v);
	y=OpadajuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i=0; i<x.size(); i++)
	{
		for(int j=0; j<x[i].size(); j++)
		{
			std::cout << x[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0; i<y.size(); i++)
	{
		for(int j=0; j<y[i].size(); j++)
		{
			std::cout << y[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}