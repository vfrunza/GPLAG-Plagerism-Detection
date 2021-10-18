/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>

template <typename Tip>

bool DaLiJePeriodican (std::vector<Tip> v, int p)
{
	bool periodican(true);
	
	if (p == 0 || v.size() == 1 || v.size() == p) periodican = false;
	
	for (int i = 0; i < v.size()-p; i++)
	{
		if (i+p > v.size()) break;
		if (v[i] != v[i+p]) periodican = false;
	}
	
	return periodican;
	
	
}

template<typename Tip>
int OdrediOsnovniPeriod (std::vector<Tip> v)
{
	for (int i = 1; i <= v.size(); i++)
	{
		if (DaLiJePeriodican(v,i)) return i;
	}
}
int **AlocirajFragmentirano (std::vector<Tip> v, int &koliko_puta)
{
	for (int i = 0; i < v.size(); i++)
	{
		int broj = OdrediOsnovniPeriod(v)
		{
			for (int j = v.size(); j < v.size()+broj; j++)
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
	for (int i = 0; i < broj_elemenata; i++)
	{
		std::cin >> v[i];
	}
	
	bool alokacija;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> alokacija;
	
	if(alokacija) 
	return 0;
}