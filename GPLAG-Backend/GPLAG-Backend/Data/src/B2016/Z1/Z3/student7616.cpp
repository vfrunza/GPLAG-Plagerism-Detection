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
#include <iomanip> 
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v)
{
	const double Eps(1e-10);
	std::vector<double> rastuci;
	Matrica m(200);
	double red(0);
	int i;
	for(i=0; i<v.size()-1; i++)
	{
		if((v[i] <= v[i+1]) || (std::fabs(v[i] - v[i+1]) <= Eps * (std::fabs(v[i]) + std::fabs(v[i+1])))) rastuci.push_back(v[i]);
		else if(rastuci.size() >= 1)
		{
			rastuci.push_back(v[i]);
			m[red].resize(rastuci.size());
			for(int j=0; j<rastuci.size(); j++)
			m[red][j]=rastuci[j];
			rastuci.resize(0);
			red++;
		}
	}
	if(rastuci.size() >= 1)
	{
		rastuci.push_back(v[i]);
		m[red].resize(rastuci.size());
		for(int j=0; j<rastuci.size(); j++)
		m[red][j]=rastuci[j];
	}
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v)
{
	std::vector<double> rastuci;
	Matrica m(200);
	double red(0),i;
	for(i=0; i<v.size()-1; i++)
	{
		if(v[i] >= v[i+1]) rastuci.push_back(v[i]);
		else if(rastuci.size() >= 1)
		{
			rastuci.push_back(v[i]);
			m[red].resize(rastuci.size());
			for(int j=0; j<rastuci.size(); j++)
			m[red][j]=rastuci[j];
			rastuci.resize(0);
			red++;
		}
	}
	if(rastuci.size() >= 1)
	{
		rastuci.push_back(v[i]);
		m[red].resize(rastuci.size());
		for(int j=0; j<rastuci.size(); j++)
		m[red][j]=rastuci[j];
	}
	return m;
}

int main()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> v(n);
	if(n<0) return 0;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++)
	{
		std::cin>>v[i];
	}
	Matrica a(RastuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi: " <<std::endl;;
	for(int i=0; i<a.size(); i++)
	{
		for(int j=0; j<a[i].size(); j++)
		{
			std::cout<<std::setprecision(12)<<a[i][j] <<" ";
		}
		std::cout<<std::endl;
	}
	Matrica b(OpadajuciPodnizovi(v));
	std::cout<<"Maksimalni opadajuci podnizovi: " <<std::endl;;
	for(int i=0; i<b.size(); i++)
	{
		for(int j=0; j<b[i].size(); j++)
		{
			std::cout<<std::setprecision(12)<< b[i][j] <<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
	