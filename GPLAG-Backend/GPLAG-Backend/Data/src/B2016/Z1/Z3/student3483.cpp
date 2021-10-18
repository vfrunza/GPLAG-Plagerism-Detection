/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> niz)
{
	std::vector<std::vector<double>> rastuci;
	int pocetak(0), kraj(0), j(0);
	//Provjerav rastucih podnizova
	while(pocetak != niz.size())
	{
		int i(pocetak+1);
		while(i < niz.size())
		{
			if(niz[i] >= niz[kraj])
				kraj++;
			else
				i = niz.size();
			i++;
		}
		if(pocetak != kraj)
		{
			rastuci.resize(j+1);
			for(int i = pocetak; i <= kraj; i++)
				rastuci[j].push_back(niz[i]);
			j++;
			pocetak = kraj;
		}
		else
		{
			pocetak++;
			kraj++;
		}
	}
	return rastuci;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> niz)
{
std::vector<std::vector<double>> opadajuci;
	int pocetak(0), kraj(0), j(0);
	//Provjera opadajucih podnizova
	while(pocetak != niz.size())
	{
		int i(pocetak+1);
		while(i < niz.size())
		{
			if(niz[i] <= niz[kraj])
				kraj++;
			else
				i = niz.size();
			i++;
		}
		if(pocetak != kraj)
		{
			opadajuci.resize(j+1);
			for(int i = pocetak; i <= kraj; i++)
				opadajuci[j].push_back(niz[i]);
			j++;
			pocetak = kraj;
		}
		else
		{
			pocetak++;
			kraj++;
		}
	}
	return opadajuci;
} 

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> a(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i = 0; i < a.size(); i++)
		std::cin>>a[i];
	std::vector<std::vector<double>> rastuci, opadajuci;
	rastuci = RastuciPodnizovi(a);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i = 0; i < rastuci.size(); i++)
	{
		for(int j = 0; j < rastuci[i].size(); j++)
			std::cout<<rastuci[i][j]<<" ";
		std::cout<<std::endl;
	}
	opadajuci = OpadajuciPodnizovi(a);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i = 0; i < opadajuci.size(); i++)
	{
		for(int j = 0; j < opadajuci[i].size(); j++)
			std::cout<<opadajuci[i][j]<<" ";
	}
	return 0;
}