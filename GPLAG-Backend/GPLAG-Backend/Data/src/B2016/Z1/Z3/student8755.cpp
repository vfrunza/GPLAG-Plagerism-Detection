/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>


typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v)
{
	Matrica mat;
	for(int i=0; i<int(v.size()-1); i++)
	{
		std::vector<double> temp;
		while(i+1!=v.size() && v[i]<=v[i+1])
		{
			temp.push_back(v[i]);
			i++;
		}
		if(temp.size()!=0)
		{
			temp.push_back(v[i]);
			mat.push_back(temp);
		}
	}
	return mat;
}
Matrica OpadajuciPodnizovi(std::vector<double>v)
{
	Matrica mat;
	for(int i=0; i<int(v.size()-1); i++)
	{
		std::vector<double> temp;
		while(i+1!=v.size() && v[i]>=v[i+1])
		{
			temp.push_back(v[i]);
			i++;
		}
		if(temp.size()!=0)
		{
			temp.push_back(v[i]);
			mat.push_back(temp);
		}
	}
	return mat;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v;
	for(int i=0; i<n; i++)
	{
		double x;
		std::cin>>x;
		v.push_back(x);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<RastuciPodnizovi(v).size(); i++)
	{
		for(int j=0; j<RastuciPodnizovi(v)[i].size(); j++)
			std::cout<<RastuciPodnizovi(v)[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<OpadajuciPodnizovi(v).size(); i++)
	{
		for(int j=0; j<OpadajuciPodnizovi(v)[i].size(); j++)
			std::cout<<OpadajuciPodnizovi(v)[i][j]<<" ";
		std::cout<<std::endl;
	}
}