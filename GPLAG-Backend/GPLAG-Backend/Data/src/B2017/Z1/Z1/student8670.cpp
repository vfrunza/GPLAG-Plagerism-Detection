/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include <cmath>
// Funkcija za pretvorbu broja iz dekadskog u ternarni
int Ter (int n)
{
	unsigned long long int ternarni(0), i(1);
	while (n != 0) 
	{
	ternarni += (n%3)*i;
	n /= 3;
	i *= 10;
	}
	return ternarni;
}

// Funkcija za ispitivanje broja, da li je prost
bool Prost (int n)
{
	if(n < 0)
	{
		n *= -1;
	}
	
	if (n < 2) return false;
	
	 for(int i = 2; i <= sqrt(n); i++)
	 {
	 	if (n % i == 0) 
	 	{
	 	return false;
	 	}
	 }
	 	return true;
	 }
	 
	 
	 // Funkcija za ispitivanje simetricnosti broja
	 bool Simetrican (int n)
	 {
	 	
	 	std::vector < int > v;
	 	bool simetrican(true);
	 	while (n != 0)
	 	{
	 		int cifra = n % 10;
	 		v.push_back(cifra);
	 		n /= 10;
	 	}
	 	int i, j;
	 	for(i = 0, j = v.size()-1; i <= (v.size())/2 && j >= (v.size())/2; i++, j--)
	 	{
	 		if(v.at(j) != v.at(i))
	 		{
	 		simetrican = false;
	 		break;
	 		}
	 	}
	 
	 	return simetrican;
	 }
// Funkcija za izdvajanje Simetricnih Ternarnih 
 std::vector < int > IzdvojiSimetricneTernarne (std::vector < int > a, bool Logika)
 {
 	std::vector < int > ProstiTernarni;
 	std::vector < int > SlozeniTernarni;
 	for (int i = 0; i < a.size(); i++)
 	{
 		if(Prost(a.at(i)) && Simetrican(Ter(a.at(i))))
 		{
 			ProstiTernarni.push_back(a.at(i));
 		}
 		if (!Prost(a.at(i)) && Simetrican(Ter(a.at(i))))
 		{
 			SlozeniTernarni.push_back(a.at(i));
 		}
 	}
 	for(int l = 0; l < ProstiTernarni.size(); l++)
 	{
 		for(int k = 0; k < ProstiTernarni.size(); k++)
 		{
 			if(ProstiTernarni.at(l) == ProstiTernarni.at(k) && l != k)
 			{
 				ProstiTernarni.erase(ProstiTernarni.begin() + k);
 				k--;
 			}
 		}
 	}
 	
 	for(int l = 0; l < SlozeniTernarni.size(); l++)
 	{
 		for(int k = 0; k < SlozeniTernarni.size(); k++)
 		{
 			if(SlozeniTernarni.at(l) == SlozeniTernarni.at(k) && l != k)
 			{
 				SlozeniTernarni.erase(SlozeniTernarni.begin() + k);
 				k--;
 			}
 		}
 	}
 	
 	if (Logika)
 	return ProstiTernarni;
 	else
 	return SlozeniTernarni;
 }
 
 
int main ()
{
	
	std::vector < int > v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	int a;
	
   for (int i = 0; ;i++)
	{
		std::cin >> a;
		if(a != (-1))
		{
		 v.push_back(a);
		}
		else break;
	}
	
	
	int ulaz;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> ulaz;
		if(ulaz != 1 && ulaz != 0)
	{
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> ulaz;
	}
    std::vector < int > prosti;
	prosti = IzdvojiSimetricneTernarne(v,true);
	if (ulaz == 1)
	{
		if(prosti.size() == 0)
		{
			std::cout << "Nema prostih simetricnih brojeva u vektoru. ";
		}
		else
		{
	std::cout << "Prosti simetricni brojevi iz vektora su: ";
	for(int i = 0; i < prosti.size(); i++)
	{
		if(i == prosti.size() -1)
		{
	std::cout << prosti.at(i) << ".";
		}
		else
		std::cout << prosti.at(i) << ", ";
	}
	}
}
	std::vector < int > slozeni;
	slozeni = IzdvojiSimetricneTernarne(v,false);
	if(ulaz == 0)
	{
	if(slozeni.size() == 0) 
	{
std::cout << "Nema slozenih simetricnih brojeva u vektoru. ";
}
else
{
	std::cout << "Slozeni simetricni brojevi iz vektora su: ";

	for (int i = 0; i < slozeni.size(); i++)
	{
	if (i == slozeni.size() - 1)
	{
		std::cout << slozeni.at(i) << ".";
		}
		else 
		std::cout << slozeni.at(i) << ", ";
	}
	}
	}

	return 0;
}