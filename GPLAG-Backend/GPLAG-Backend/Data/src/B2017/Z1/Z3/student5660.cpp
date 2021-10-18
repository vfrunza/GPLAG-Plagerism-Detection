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
#include <cmath>

typedef std::deque<std::vector<int>> DekVektora;
typedef std::vector<int> Vektor;

void IspisiDekVektora (DekVektora dv)
{
	for (int i = 0; i < dv.size(); i++)
	{
		for (int j = 0; j < dv.at(i).size(); j++)
		{
			std::cout << dv.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
}

DekVektora Kreiraj (int br_redova, int br_kolona)
{
	return DekVektora(br_redova, Vektor(br_kolona));
}

int BrojDjeljivSamoSaDva (int n)
{
	int brojac(0);
	if (n%2 == 0){
	for (;;)
	{
		n /= 2;
		brojac++; std::cout << "brojac " << brojac << std::endl;
		if (n/2 == 0) break;
	}
	}
	return brojac;
}
bool DjeljivSaDva (int n)
{
	if (n & (n-1)) return false;
	else return true;
}

Vektor StepenDvojke (Vektor v)
{
	Vektor dvojka; 
	int baza(2), rezultat(1), eksponent(0);
	for (int i = 0; i < v.size(); i++)
	{
		//if(v.at(i) % 2 == 0) {
		eksponent = BrojDjeljivSamoSaDva(v.at(i)); std::cout << eksponent << std::endl;
		while (eksponent >= 0)
		{
			rezultat *= baza;
			--eksponent;
			dvojka.push_back(rezultat);
		}
		//}
		
	}
	return dvojka;
}

Vektor MaxRastuci (Vektor v)
{
	Vektor rastuci;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) <= v.at(i+1))
		{
			rastuci.resize(v.size());
			rastuci.push_back(v.at(i));
			if (i == v.size() - 1) std::cout << v.at(i) << std::endl;
			else std::cout << v.at(i) << " ";
		}
		if (StepenDvojke(v) == rastuci) rastuci = StepenDvojke(v);
		
	}
	//for (int x : v) rastuci.resize(x);
	
	return rastuci;
}

Vektor MaxOpadajuci (Vektor v)
{
	Vektor opadajuci;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) >= v.at(i+1) )
		{
			opadajuci.resize(v.size());
			opadajuci.push_back(v.at(i));
			if (i == v.size() - 1) std::cout << v.at(i) << std::endl;
			else std::cout << v.at(i) << " ";
		}
		if (StepenDvojke(v) == opadajuci) opadajuci = StepenDvojke(v);
	}
	//for (int x : v) opadajuci.resize(x);
	
	return opadajuci;
}

DekVektora MaksimalniPodnizoviStepenaDvojke (Vektor v, bool Smjer)
{
	DekVektora max; Vektor v1, v2;
	if (Smjer == true)
	{
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				//v1 = MaxRastuci(v);
				//max.at(i).at(j) = Kreiraj(v1.size(), v1.size());
			}
		}
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				//v2 = MaxOpadajuci(v);
				//max.at(i).at(j) = Kreiraj(v2.size(), v2.size());
			}
		}
	}
	return max;
}


int main ()
{
	Vektor v;
	int n, broj;
	
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		v.push_back(a);
	}
	
	/*Vektor vek(MaxRastuci(v));
	for (int i = 0; i < vek.size(); i++)
	{
		std::cout << vek.at(i) << " ";
	}
	Vektor vek1(MaxOpadajuci(v));
	for (int i = 0; i < vek1.size(); i++)
	{
		std::cout << vek1.at(i) << " ";
	}*/
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> broj;
	
	bool pravac(true);
	
	if (broj == 1)
	{
		if (pravac)
		{
			std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
			//IspisiDekVektora(MaxRastuci(v));
		}
		
		//MaxRastuci(v);
	}
	else if (broj == 2)
	{
		if (!pravac)
		{
			std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
			//(MaxOpadajuci(v));
		}
		
		//MaxOpadajuci(v);
	}
	
	return 0;
}