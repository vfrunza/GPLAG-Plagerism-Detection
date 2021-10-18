#include<iostream>
#include<vector>
#include<iomanip>
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> vv;
	std::vector<double> pom;
	for( int i=0; i < v.size();i++)
	{
		if(pom.size() == 0) pom.push_back(v[i]);
		else if(pom[pom.size() - 1] <= v[i]) pom.push_back(v[i]);
		else 
		{
			if(pom.size()>=2) vv.push_back(pom);
			pom = {v[i]};
		}
	}
	if(pom.size()>=2) vv.push_back(pom);
	return vv;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> vv;
	std::vector<double> pom;
	for(int i=0; i < v.size();i++)
	{
		if(pom.size() == 0) pom.push_back(v[i]);
		else if(pom[pom.size() - 1] >= v[i]) pom.push_back(v[i]);
		else 
		{
			if(pom.size()>=2) vv.push_back(pom);
			pom = {v[i]};
		}
	}
	if(pom.size()>=2) vv.push_back(pom);
	return vv;
}
int main ()
{
	int N;
	std::cout<< "Unesite broj elemenata vektora: ";
	std::cin>> N;
	std::vector<double> v(N);
	std::cout<< "Unesite elemente vektora: ";
	for(int i=0;i<N;i++) std::cin>> v[i];
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	std::vector<std::vector<double>> vv = RastuciPodnizovi(v);
	for(auto vec:vv)
	{
		for(auto e:vec) std::cout<< std::setprecision(15)<<e<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	vv = OpadajuciPodnizovi(v);
	for(auto vec:vv)
	{
		for(auto e:vec) std::cout<< std::setprecision(15)<<e<<" ";
		std::cout<<std::endl;
	}
	return 0;
}