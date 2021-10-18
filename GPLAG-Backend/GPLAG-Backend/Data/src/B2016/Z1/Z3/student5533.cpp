/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector <std::vector <double>> Matrica ;
Matrica RastuciPodnizovi (std::vector<double> v)
{
	Matrica mat;
	std::vector<double> k,novi;
	for (int i=0; i<v.size()-1; i++)
	{
		k=novi;
		if (v[i]<=v[i+1])
		{
			while (v[i]<=v[i+1])
			{
				k.push_back(v[i]);
				i++;
				if (i==v.size()-1) { 
					k.push_back(v[i]);
					break;
				}
				else if (v[i]>v[i-1] && v[i]>v[i+1]) k.push_back (v[i]);
				
			}
			mat.push_back(k);
		}
	}
	return mat;
}
Matrica OpadajuciPodnizovi (std::vector<double> v)
{
	Matrica mat;
	std::vector<double> v1,novi1;
	for (int i=0; i<v.size()-1; i++)
	{
		v1=novi1;
		if (v[i]>=v[i+1])
		{
			while (v[i]>=v[i+1])
			{
				v1.push_back (v[i]);
				i++;
				if (i==v.size()-1){ 
					v1.push_back (v[i]);
					break;
				}
				else if (v[i]<v[i-1] && v[i]<v[i+1]) v1.push_back (v[i]);
			}
			mat.push_back(v1);
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
	std::vector <double> v(n);
	for (int i=0; i<v.size(); i++)
	{
		std::cin>>v[i];
	}
	Matrica mat=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	for (int i=0; i<mat.size(); i++)
	{
		for (int j=0; j<mat[i].size(); j++)
		{
			std::cout <<mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	Matrica mat1=OpadajuciPodnizovi(v);
	for (int i=0; i<mat1.size(); i++)
	{
		for (int j=0; j<mat1[i].size();j++)
		{
			std::cout<<mat1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}