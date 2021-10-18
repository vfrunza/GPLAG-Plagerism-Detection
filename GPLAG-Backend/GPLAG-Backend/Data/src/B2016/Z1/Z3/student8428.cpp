/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <cmath>
#include <iostream>
#include <vector>

bool JesuLiJednaki( double x, double y, double eps = 1E-10)
{
	return std::fabs(x - y) < eps * (std::fabs(x) + std::fabs(y));
}

bool ManjiIliJednaki( double x, double y, double eps = 1E-10)
{
	return  x < y || JesuLiJednaki(x, y);
}

bool VeciIliJednaki( double x, double y, double eps = 1E-10)
{
	return  x > y || JesuLiJednaki(x, y);
}


std::vector<std::vector<double>> RastuciPodnizovi( std::vector<double> v)
{
	if(v.size() == 1U || v.size() == 0U)
		return {};
	std::vector<std::vector<double>> ret;
	std::vector<double> podniz;	
	bool prvi = true;
	for(int i = 1; i < int(v.size()); ++i)
	{
		if( ManjiIliJednaki(v[i - 1], v[i]) )
		{
			if(prvi)
				podniz.push_back(v[i - 1]);
			podniz.push_back(v[i]);
			prvi = false;
		}
		if((i != 1 && v[i - 1] > v[i]) || i == int(v.size()) - 1)
		{
			prvi = true;
			if( podniz.size() != 0U)
			{
				ret.push_back(podniz);
				podniz.resize(0);	
			}
		}
	}
	return ret;
}

std::vector<std::vector<double>> OpadajuciPodnizovi( std::vector<double> v)
{
	if(v.size() == 1U || v.size() == 0U)
		return {};
	std::vector<std::vector<double>> ret;
	std::vector<double> podniz;	
	bool prvi = true;
	for(int i = 1; i < int(v.size()); ++i)
	{
		if( VeciIliJednaki(v[i - 1], v[i]) )
		{
			if(prvi)
				podniz.push_back(v[i - 1] );
			podniz.push_back(v[i]);
			prvi = false;
		}
		if((i != 1 && v[i - 1] < v[i]) || i == int(v.size()) - 1)
		{
			prvi = true;
			if( podniz.size() != 0U)
			{
				ret.push_back(podniz);
				podniz.resize(0);	
			}
			
		}
	}
	return ret;
}



int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int br;
	std::cin >> br;
	std::vector<double> v(br);
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < br; ++i)
		std::cin >> v[i];
	std::cout << "Maksimalni rastuci podnizovi: \n";
	auto vv = RastuciPodnizovi(v);
	if( vv.size() != 0U)
	{
		int max_s = vv[0].size() ;
		for(int i = 1; i < int(vv.size()); ++i)
			if(int(vv[i].size()) > max_s)
				max_s = vv[i].size();
		for(int i = 0; i < int(vv.size()); ++i)
		{
			if(int(vv[i].size()) == max_s)
			{
				for(auto elem : vv[i])
					std::cout << elem << ' ';
				std::cout << '\n';
			}
				
		}	
	}
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	auto vo = OpadajuciPodnizovi(v);
	if(int(vo.size()) != 0)
	{
		int max_s = vo[0].size() ;
		for(int i = 1; i < int(vo.size()); ++i)
			if(int(vo[i].size()) > max_s)
				max_s = vo[i].size();
		for(int i = 0; i < int(vo.size()); ++i)
		{
			if(int(vo[i].size()) == max_s)
			{
				for(auto elem : vo[i])
					std::cout << elem << ' ';
				std::cout << '\n';
			}
		}	
	}
	
	return 0;
}