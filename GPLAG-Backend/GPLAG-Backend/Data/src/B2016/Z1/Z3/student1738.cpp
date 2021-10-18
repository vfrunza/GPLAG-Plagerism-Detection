#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

typedef std::vector<std::vector<double>> matrica;
typedef std::vector<double> vektor;

constexpr double eps(0.000000000001);


matrica OpadajuciPodnizovi (vektor v)
{
	vektor v1;
	vektor rp(v);
	matrica m;
	for (int i=0;i<int(v.size());i++)
	{
		v=rp;
		v1.resize(0);
		for (int j=0;j<int(v.size());j++)
		{
			if ( (j!=int(v.size()-1)) && ((v.at(j)>v.at(j+1)) || (std::fabs(v[j]-v[j+1])<eps)) )
			{
				v1.push_back(v[j]);
				rp.erase(rp.begin()+0);
				if (i>0) i--;
			}
			else
			{
				v1.push_back(v[j]);
				rp.erase(rp.begin()+0);
				if (i>0) i--;
				break;
			}
		}
		if (int(v1.size())>1)
		m.push_back(v1);
	}
	return m;
}

matrica RastuciPodnizovi (vektor v)
{
	vektor v1;
	vektor rp(v);
	matrica m;
	for (int i=0;i<int(v.size());i++)
	{
		v=rp;
		v1.resize(0);
		for (int j=0;j<int(v.size());j++)
		{
			if ((j!=int(v.size()-1)) && (v.at(j)<=v.at(j+1)||(std::fabs(v[j]-v[j+1])<eps)))
			{
				v1.push_back(v[j]);
				rp.erase(rp.begin()+0);
				if (i>0) i--;
			}
			else 
			{
				v1.push_back(v[j]);
				rp.erase(rp.begin()+0);
				if (i>0) i--;
				break;
			}
		}
		if (int(v1.size())>1)
		m.push_back(v1);
	}
	return m;
}


int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	if (n<1)
	{
		return 0;
	}
	std::cout <<"Unesite elemente vektora: ";
	vektor v;
	for (int i=0;i<n;i++)
	{
		int br;
		std::cin>>br;
		v.push_back(br);
		if (i==n-1) break;
	}
	std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
	matrica m(RastuciPodnizovi(v));
	for (vektor x:m)
	{
		for (double y:x)
		{
			std::cout << y<<" ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl<< "Maksimalni opadajuci podnizovi: "<<std::endl;
	m=OpadajuciPodnizovi(v);
	for (vektor x:m)
	{
		for (double y:x)
		{
			std::cout << y<<" ";
		}
		std::cout << std::endl;
	}
	return 0;
}