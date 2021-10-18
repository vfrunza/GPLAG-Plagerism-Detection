/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>


bool DaLiJeStepenBrojaDva (int broj)
{
	bool stepen(false);
	
	if (broj%2 == 0)
	{
		while (broj > 2) broj = broj/2;
		
		if (broj%2 == 0) stepen = true;
	}
	
	return stepen;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer rastuci_opadajuci)
{
	std::deque<std::vector<int>> vektor_d;
	
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (
		}
	}
}


int main ()
{
	int broj_elemenata;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	
	std::vector<int> v(broj_elemenata);
	
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < v.size(); i++)
	{
		std::cin >> v.at(i);
	}
	
	enum Smjer {rastuci = 1, opadajuci = 2};
	Smjer rastuci_ili_opadajuci;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	
	std::deque<int> d;
	//d = MaksimalniPodnizoviStepenaDvojke(v,rastuci_ili_opadajuci);
	
	
	return 0;
}