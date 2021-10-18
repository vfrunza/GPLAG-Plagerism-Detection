/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double>v)
{
	Matrica mat;
	std::vector<double>v1;
	int pomocna = 0, pom = 0;
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = i; j < v.size(); j++)
		{
			if(v[i] <= v[j] && i != j && i == v.size()-2 && j == v.size()-1)
			{
				v1.push_back(v[i]);
				v1.push_back(v[j]);
				mat.push_back(v1);
				pom = 1;
				break;
			}
			else if(v[i] <= v[j] && i != j)
			{
				v1.push_back(v[i]);
				//v1.push_back(v[j]);
				pomocna = 1;
				break;
			}
			else if(v[i] > v[j] && pomocna == 1 && i != j)
			{
				v1.push_back(v[i]);
				pomocna = 0;
				mat.push_back(v1);
				v1.resize(0);
				break;
			}
			else if(v[i] > v[j] && i != j && pomocna == 0) 
				break;
		}
		if(pom)
			break;
	}
	return mat;
}

Matrica OpadajuciPodnizovi(std::vector<double>v)
{
	Matrica mat;
	std::vector<double>v1;
	int pomocna = 0, pom = 0;
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = i; j < v.size(); j++)
		{
			if(v[i] >= v[j] && i != j && i == v.size()-2 && j == v.size()-1)
			{
				v1.push_back(v[i]);
				v1.push_back(v[j]);
				mat.push_back(v1);
				pom = 1;
				break;
			}
			else if(v[i] >= v[j] && i != j)
			{
				v1.push_back(v[i]);
				pomocna = 1;
				break;
			}
			else if(v[i] < v[j] && pomocna ==1 && i != j)
			{
				v1.push_back(v[i]);
				pomocna = 0;
				mat.push_back(v1);
				v1.resize(0);
				break;
			}
			else if (v[i] < v[j] && i != j && pomocna == 0)
				break;
		}
		if(pom)
			break;
	}
	return mat;
}

int main ()
{
	std::vector<double>v;
	std::cout<<"Unesite broj elemenata vektora: ";
	int vel;
	std::cin>>vel;
	std::cout<<"Unesite elemente vektora: ";
	for(int i = 0; i < vel; i++)
	{
		int n;
		std::cin>>n;
		v.push_back(n);
	}
	
	auto mat = RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i = 0; i < mat.size(); i++)
	{
		for(int j = 0; j < mat[i].size(); j++)
		{	
			std::cout<<mat[i][j]<<" ";
		}
	std::cout<<std::endl;
	}
	auto mat1 = OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i = 0; i < mat1.size(); i++)
	{
		for(int j = 0; j < mat1[i].size(); j++)
		{
			std::cout<<mat1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}