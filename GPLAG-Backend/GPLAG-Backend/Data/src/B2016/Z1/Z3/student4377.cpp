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


void IspisiMatricu(std::vector<std::vector<double>> m) 
{
	for(auto red : m) 
	{
		for(auto x : red) std::cout << std::right << x << " ";
 		std::cout << std::endl;
	}
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> matrica;
	bool niz  (false);
	double prosli (v[0]);
	int br_redova (0);
	
	for(int i = 0; i<v.size(); i++)
	{
		if(v[i] >= prosli)
		{
			if(niz == false)
			{
				matrica.resize(br_redova+1);
				matrica[br_redova].push_back(v[i]);
			}
			else 
			{
				matrica[br_redova].push_back(v[i]);
			}
			niz = true;
			prosli = v[i];
		}
		else
		{
			if(matrica[br_redova].size() > 1)
			{
				br_redova++;
			}
			else
			{
				matrica.erase(matrica.begin()+matrica.size() - 1);
			}
			niz = false;
			prosli = v[i];
			i--;
		}
	}
	
	if(matrica[br_redova].size() == 1)
	{
		matrica.erase(matrica.begin()+matrica.size() - 1);
	}
	
	return matrica;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> matrica;
	bool niz  (false);
	double prosli (v[0]);
	int br_redova (0);
	
	for(int i = 0; i<v.size(); i++)
	{
		if(v[i] <= prosli)
		{
			if(niz == false)
			{
				matrica.resize(br_redova+1);
				matrica[br_redova].push_back(v[i]);
			}
			else 
			{
				matrica[br_redova].push_back(v[i]);
			}
			niz = true;
			prosli = v[i];
		}
		else
		{
			if(matrica[br_redova].size() > 1)
			{
				br_redova++;
			}
			else
			{
				matrica.erase(matrica.begin()+matrica.size() - 1);
			}
			niz = false;
			prosli = v[i];
			i--;
		}
	}
	
	if(matrica[br_redova].size() == 1)
	{
		matrica.erase(matrica.begin()+matrica.size() - 1);
	}
	
	return matrica;
}


int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	if(std::cin >> n, n<=0) return 0;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v(n);
	for(int i=0; i<n; i++) std::cin >> v[i];
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	IspisiMatricu(RastuciPodnizovi(v));
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	IspisiMatricu(OpadajuciPodnizovi(v)); 
	
	return 0;
}