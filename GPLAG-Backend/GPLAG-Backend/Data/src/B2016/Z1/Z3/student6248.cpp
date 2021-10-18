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

bool JesuLiJednaki(double x, double y, double eps=1e-10)
{
	return std::fabs(x-y) <= eps*(std::fabs(x)+std::fabs(y));
}

int BrojRastucihPodnizova(std::vector<double> v)
{
	int br(0);
	for(int i(0); i<int(v.size()-1); i++)
	{
		if(v.at(i)<=v.at(i+1) || JesuLiJednaki(v.at(i),v.at(i+1)))
		{
			while(v.at(i)<=v.at(i+1)  || JesuLiJednaki(v.at(i),v.at(i+1)))
			{
				i++;
				if(i==int(v.size()-1)) break;
			}
			br++;
			if(i==int(v.size()-1)) break;
		}
	}
	return br;
}

int BrojOpadajucihPodnizova(std::vector<double> v)
{
	int br(0);
	for(int i(0); i<int(v.size()-1); i++)
	{
		if(v.at(i)>=v.at(i+1))
		{
			while(v.at(i)>=v.at(i+1))
			{
				i++;
				if(i==int(v.size()-1)) break;
			}
			br++;
			if(i==int(v.size()-1)) break;
		}
	}
	return br;
}

Matrica RastuciPodnizovi(std::vector<double> v)
{
	int n;
	n=BrojRastucihPodnizova(v);
	
	if(n==0) return std::vector<std::vector<double>> (0, std::vector<double> (0));
	Matrica rastuci(n);
	int j(0);
    for(int i(0); i<int(v.size()-1); i++)
    {
    	if(v.at(i)<=v.at(i+1) || JesuLiJednaki(v.at(i),v.at(i+1)))
    	{
    		while(v.at(i)<=v.at(i+1) || JesuLiJednaki(v.at(i),v.at(i+1)))
    		{
    			rastuci.at(j).push_back(v.at(i));
    			i++;
    			if(i==int(v.size()-1)) break;
    		}
    		rastuci.at(j).push_back(v.at(i)); // i onaj posljednji ubacujemo
    		j++;
    	    if(j==n) break;
    	}
    	if(i==int(v.size()-1)) break;   // brisati intove
    }
	return rastuci;
}

Matrica OpadajuciPodnizovi(std::vector<double> v)
{
	int n;
	n=BrojOpadajucihPodnizova(v);
	if(n==0) return std::vector<std::vector<double>> (0, std::vector<double> (0));
	Matrica opadajuci(n);
	int j(0);
	for(int i(0); i<int(v.size()-1); i++)
	{
		if(v.at(i)>=v.at(i+1) || JesuLiJednaki(v.at(i),v.at(i+1)))
		{
			while(v.at(i)>=v.at(i+1) || JesuLiJednaki(v.at(i),v.at(i+1)))
			{
				opadajuci[j].push_back(v.at(i));
				i++;
				if(i==int(v.size()-1)) break;
			}
			opadajuci.at(j).push_back(v.at(i));
			j++;
			if(j==n) break;
		}
		if(i==(v.size()-1)) break;
	}
	return opadajuci;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v;
	for(int i(0); i<n; i++)
	{
		double a;
		std::cin >> a;
		if(a<0) a=fabs(a);   // neg
		v.push_back(a);
	}
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	Matrica rastuci(BrojRastucihPodnizova(v));
	rastuci=RastuciPodnizovi(v);
	for(int i(0); i<rastuci.size(); i++)
	{
		for(int j(0); j<rastuci.at(i).size(); j++)
		{
			std::cout << rastuci.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	Matrica opadajuci(BrojOpadajucihPodnizova(v));
	opadajuci=OpadajuciPodnizovi(v);
	for(int i(0); i<opadajuci.size(); i++)
	{
		for(int j(0); j<opadajuci.at(i).size(); j++)
		{
			std::cout << opadajuci.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}