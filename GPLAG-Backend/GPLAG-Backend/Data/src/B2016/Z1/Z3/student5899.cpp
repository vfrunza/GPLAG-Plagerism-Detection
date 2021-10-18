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

Matrica RastuciPodnizovi(std::vector<double> v)
{
	std::vector<double>lol ;
	Matrica brat;
	
	for(int i=0;i<v.size();i++)
	{
		if((i+1)==v.size())break;
		if(v.at(i)<=v.at(i+1))
		{
			do
			{
				lol.push_back(v.at(i));
				i++;
			}
			while ((i+1)!=v.size() && v.at(i)<=v.at(i+1)); 
		}
		lol.push_back(v.at(i));
		if(lol.size()>1)
			brat.push_back(lol);
			lol.resize(0);
	}
	return brat;
}

Matrica OpadajuciPodnizovi(std::vector<double> v)
{
	Matrica kupus;
	std::vector<double> omg;
	for(int i=0;i<v.size();i++)
	{
		if((i+1)==v.size())break;
		if(v.at(i)>=v.at(i+1))
		{
			do
			{
				omg.push_back(v.at(i));
				i++;
			}
			while((i+1)!=v.size() && v.at(i)>=v.at(i+1));
		}
		omg.push_back(v.at(i));
		if(omg.size()>1)
		kupus.push_back(omg);
		omg.resize(0);
	}
	return kupus;
}
int main ()
{
	Matrica kupus;
	Matrica krompir;
	std::vector<double> hrana;
	int broj;
	double element;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin>>broj;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0;i<broj;i++)
	{
		std::cin>>element;
		hrana.push_back(element);
	}
	
	kupus=RastuciPodnizovi(hrana);
	krompir=OpadajuciPodnizovi(hrana);
	std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<kupus.size();i++)
	{
		for(int j=0;j<kupus.at(i).size();j++)
		std::cout << kupus.at(i).at(j)<<" ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<krompir.size();i++)
	{
		for(int j=0;j<krompir.at(i).size();j++)
		std::cout << krompir.at(i).at(j)<<" ";
		std::cout << std::endl;
	}
	return 0;
}