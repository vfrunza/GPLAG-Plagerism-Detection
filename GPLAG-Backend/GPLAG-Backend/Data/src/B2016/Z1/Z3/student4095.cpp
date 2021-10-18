/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> vektor_podnizova;

vektor_podnizova RastuciPodnizovi (std::vector<double> v)
{
	vektor_podnizova mon_rastuca;
	for (int i=0; i<int(v.size())-1; i++)
	{
		std::vector<double> pomocni;
		if (v[i]<=v[i+1])
		{
			for (int j=i; j<int(v.size())-1; j++)
			{
				if (j==int(v.size())-2 && v[j]<=v[j+1])
				{
					pomocni.push_back(v[j]);
					pomocni.push_back(v[j+1]);
					i=j;
					break;
				}
				else if (v[j]<=v[j+1])
					pomocni.push_back(v[j]);
				else
				{
					pomocni.push_back(v[j]);
					i=j;
					break;
				}
			}
			mon_rastuca.push_back(pomocni);
		}
	}
	return mon_rastuca;
}

vektor_podnizova OpadajuciPodnizovi (std::vector<double> v)
{
	vektor_podnizova mon_opadajuci;
	for (int i=0; i<int(v.size())-1; i++)
	{
		if (v[i]>=v[i+1])
		{
			std::vector<double> pomocni;
			for (int j=i; j<int(v.size())-1; j++)
			{
				if (j==int(v.size())-2 && v[j]>=v[j+1])
				{
					pomocni.push_back(v[j]);
					pomocni.push_back(v[j+1]);
					i=j;
					break;
				}
				else if (v[j]>=v[j+1])
					pomocni.push_back(v[j]);
				else
				{
					pomocni.push_back(v[j]);
					i=j;
					break;
				}
			}
			mon_opadajuci.push_back(pomocni);
		}
	}
	return mon_opadajuci;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<v.size(); i++)
		std::cin>>v[i];
	vektor_podnizova mon_rastuca(RastuciPodnizovi(v));
	vektor_podnizova mon_opadajuci(OpadajuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for (int i=0; i<mon_rastuca.size(); i++)
	{
		for (int j=0; j<mon_rastuca[i].size(); j++)
			std::cout<<mon_rastuca[i][j]<<" ";
		std::cout<<std::endl;	
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for (int i=0; i<mon_opadajuci.size(); i++)
	{
		for (int j=0; j<mon_opadajuci[i].size(); j++)
			std::cout<<mon_opadajuci[i][j]<<" ";
		std::cout<<std::endl;	
	}
	return 0;
}