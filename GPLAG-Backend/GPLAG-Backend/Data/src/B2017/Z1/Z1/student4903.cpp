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


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool uslov)
{
	std::vector<int> rezultat;
	
	for (int i{}; i<v.size(); i++)
	{
		int pomocni = v.at(i);
		
		if (pomocni < 0)
			pomocni*=-1;
			
		int brojac = 0;
		
		for (int j{1}; j<=pomocni;j++)
			{
				if (pomocni%j == 0)
					brojac++;
			}
		
		if (brojac == 2 && uslov == true)
			rezultat.push_back(v.at(i));
		if (brojac > 2 && uslov == false)
			rezultat.push_back(v.at(i));
	}
	
	
	std::vector<int> sredjen;
	
	for (int i{}; i<rezultat.size(); i++)
	{
		std::vector<int> zapis;
		long int pomocni = rezultat.at(i);
		
		if (pomocni < 0)
			pomocni*=-1;
			
		while (pomocni > 0)
		{
			zapis.push_back(pomocni%3);
			pomocni/=3;
		}
		
		
		int a = 0;
		int b = zapis.size() - 1;
		bool simetricni = true;
		
		while (true)
		{
			if (a >= b)
				break;
				
			if (zapis.at(a) != zapis.at(b))
				simetricni = false;
				
			a++;
			b--;
		}
		
		if (simetricni == true)
		{
			bool upisan = false;
			for (int j{}; j < sredjen.size(); j++)
			{
				if (sredjen.at(j) == rezultat.at(i))
					upisan = true;
			}
			
			if (upisan == false)
				sredjen.push_back(rezultat.at(i));
		}
		
		
		
	}
	
	
	
	
	
	return sredjen;
}






int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> upis;
	
	while (true)
	{
		int x;
		std::cin>>x;
		
		if (x == -1)
			break;
			
		upis.push_back(x);
	}
	
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int slucaj;
	std::cin>>slucaj;
	while (true)
	{
		if (slucaj == 0 || slucaj == 1)
			break;
			
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>slucaj;
	}
	
	
	auto ispis = IzdvojiSimetricneTernarne(upis,slucaj);
	
	if (slucaj == 1)
		{
			if (ispis.size() == 0)
			{
				std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
				return 0;
			}
			
			std::cout<<"Prosti ";
		}
	else
		{
			if (ispis.size() == 0)
			{
				std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
				return 0;
			}
			
			
			std::cout<<"Slozeni ";
		}
		
	std::cout<<"simetricni brojevi iz vektora su: ";
	
	for (int i{}; i < ispis.size(); i++)
	{
		if (i == ispis.size() - 1)
			std::cout<<ispis.at(i)<<".";
		else
			std::cout<<ispis.at(i)<<", ";
	}
	
	
	
	
	return 0;
}