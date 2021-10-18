/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vektor)
{
	int m, n(0);
	if(vektor.size()==0) m=0;
	else m=vektor.size()-1;
	std::vector<std::vector<double>> matrica(m);
	for(int i=0; i<=m; i++)
	{
		if(i+1<m && vektor[i]<vektor[i+1]) 
		{
			while(vektor[i]<vektor[i+1])
			{
				matrica[n].push_back(vektor[i]);
				if(vektor[i+1]>vektor[i+2]) matrica[n].push_back(vektor[i+1]);  //posljednji veći element
				i++;
			}
			if(i+1<m) n++; //ako je posljednji element nemoj ++
		}
		else if(i==m && vektor[i]>vektor[i-1])
		{
			matrica[n].push_back(vektor[i]); //ubacivanje posljednjeg elementa
		}
	}
	std::vector<std::vector<double>> nova;
	for(auto red: matrica) if(red.size()>0) nova.push_back(red);
	return nova;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vektor)
{
	int m, n(0);
	if(vektor.size()==0) m=0;
	else m=vektor.size()-1;
	std::vector<std::vector<double>> matrica(m);
	for(int i=0; i<=m; i++)
	{
		//izmijeniti fju tako da radi obrnuto od gornje
		if(i+1<m && vektor[i]>vektor[i+1]) 
		{
			while(vektor[i]>vektor[i+1])
			{
				matrica[n].push_back(vektor[i]);
				if(vektor[i+1]<vektor[i+2]) matrica[n].push_back(vektor[i+1]);  //posljednji manji element
				i++;
			}
			if(i+1<m) n++; //ako je posljednji element nemoj ++
		}
		else if(i==m && vektor[i]<vektor[i-1])
		{
			matrica[n].push_back(vektor[i]); //ubacivanje posljednjeg elementa
		}
	}
	std::vector<std::vector<double>> nova;
	for(auto red: matrica) if(red.size()>0) nova.push_back(red);
	return nova;
}

int main ()
{
	int b;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> b;
	std::vector<double> v(b);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<b; i++)
	{
		std::cin >> v[i];
	}
	std::vector<std::vector<double>> rastuci(RastuciPodnizovi(v));
	std::vector<std::vector<double>> opadajuci(OpadajuciPodnizovi(v));
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i=0; i<rastuci.size(); i++)
	{
		for(int j=0; j<rastuci[i].size(); j++)
		{
			std::cout << rastuci[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0; i<opadajuci.size(); i++)
	{
		for(int j=0; j<opadajuci[i].size(); j++)
		{
			std::cout << opadajuci[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}