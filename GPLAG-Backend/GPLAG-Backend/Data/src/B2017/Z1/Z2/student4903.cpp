/*B 2017/2018, Zadaća 1, Zadatak 2
	
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
#include <stdexcept>
#include <iomanip>


std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> rezultat;
	
	if (matrica.size() == 0)
		return rezultat;
		
	for (int i{}; i<matrica.size(); i++)
	{
		if (matrica.at(i).size() == 0)
			return rezultat;
	}
	
	for (int i{}; i<matrica.size(); i++)
	{
		if (matrica.at(0).size() != matrica.at(i).size())
			throw std::domain_error ("Matrica nije korektna");
	}
	
	
	std::vector<std::vector<std::vector<double>>> skup_matrica;
	std::vector<double> vrhovi_planine;
	std::vector<std::vector<int>> koordinate;
	
	int dimenzija = 3;															///Početna dimenzija matrica za planine.
	while (true)
	{
		if (dimenzija > matrica.size())
			break;
			
		int pocetak_i = 0;
		int kraj_i = dimenzija;
		
		while (true)
		{
			if (kraj_i > matrica.size())
				break;
			
			int pocetak_j = 0;
			int kraj_j = dimenzija;
			
			while (true)
			{
				if (kraj_j > matrica.at(0).size())
					break;
					
				std::vector<std::vector<double>> pomocna;
				for (int i{pocetak_i}; i<kraj_i; i++)
				{
					std::vector<double> pomocna_2;
					for (int j{pocetak_j}; j<kraj_j; j++)
						{
							if (matrica.at(i).at(j) < 0)
								throw std::domain_error ("Matrica nije korektna");
								
							pomocna_2.push_back(matrica.at(i).at(j));
						}
					pomocna.push_back(pomocna_2);
				}
				
				
				bool planina = true;											///Test da li je pronadjena matrica planina.
				int sredina_i = pomocna.size()/2;
				int sredina_j = pomocna.at(0).size()/2;
				double sredisnji = pomocna.at(sredina_i).at(sredina_j);
				
				std::vector<double> zbirovi;
				int a = 0;
				int b = pomocna.size();
				
				while (true)
				{
					if (a == sredina_i)
						break;
					
					double zbir = 0;
					for (int i{a}; i<b; i++)
					{
						for (int j{a}; j<b; j++)
						{
							if (j == a || j == b-1)
								zbir += pomocna.at(i).at(j);
							else if (i == a || i == b-1)
								zbir += pomocna.at(i).at(j);
							
						}
					}
					
					zbirovi.push_back(zbir);
					a++;
					b--;
				}
				
				zbirovi.push_back(sredisnji);
				sredisnji = zbirovi.at(0);
				
				for (int i{1}; i<zbirovi.size(); i++)
					{
						if (sredisnji >= zbirovi.at(i))
							planina = false;
							
						sredisnji = zbirovi.at(i);
					}
					
				if (planina == true)
					{
						skup_matrica.push_back(pomocna);
						vrhovi_planine.push_back(zbirovi.size()-1);
						std::vector<int> v {pocetak_i,pocetak_j};
						koordinate.push_back(v);
					}
				
				pocetak_j++;
				kraj_j++;
			}
				
				
			
			pocetak_i++;
			kraj_i++;
		}
		
		
		
		
		
		
		dimenzija += 2;															///Mora dimenzija biti neparna.
	}
	
	
	if (skup_matrica.size() == 0)												///Ako se ne pronadje niti jedna, trazi se najveci broj (matrica 1x1).
	{
		double najveci = matrica.at(0).at(0);
		
		for (int i{};i<matrica.size();i++)
		{
			for (int j{};j<matrica.at(0).size();j++)
			{
				if (matrica.at(i).at(j) > najveci)
					najveci = matrica.at(i).at(j);
			}
		}
		
		std::vector<double> pomocna {najveci};
		rezultat.push_back(pomocna);
		return rezultat;
	}
	
	int najveca_dimenzija = 0;													///Testiranje velicina planina.
	
	for (int i{}; i<skup_matrica.size(); i++)
	{
		std::vector<std::vector<double>> pomocna = skup_matrica.at(i);
		if (najveca_dimenzija < pomocna.size())
			najveca_dimenzija = pomocna.size();
	}
	
	std::vector<int> pozicije;
	for (int i{}; i<skup_matrica.size();i++)
	{
		std::vector<std::vector<double>> pomocna = skup_matrica.at(i);
		if (pomocna.size() == najveca_dimenzija)
			pozicije.push_back(i);
	}
	
	if (pozicije.size() == 1)													///Ako postoji samo jedna planina sa najvecom dimenzijom.
	{
		rezultat = skup_matrica[pozicije.at(0)];
		return rezultat;
	}
	
	double najveci_vrh = 0;
	for (int i{}; i<pozicije.size(); i++)
	{
		int indeks = pozicije.at(i);
		if (najveci_vrh < vrhovi_planine.at(indeks))
			najveci_vrh = vrhovi_planine.at(indeks);
		
	}
	
	std::vector<int> pozicije_vrhova;
	for (int i{}; i<pozicije.size(); i++)
	{
		int indeks = pozicije.at(i);
		if (najveci_vrh == vrhovi_planine.at(indeks))
			pozicije_vrhova.push_back(indeks);
	}
	
	if (pozicije_vrhova.size() == 1)
	{
		rezultat = skup_matrica.at(pozicije_vrhova.at(0));
		return rezultat;
	}
	
	int najmanje_i = matrica.size();
	for (int i{}; i<pozicije_vrhova.size(); i++)
	{
		int indeks = pozicije_vrhova.at(i);
		std::vector<int> pomocni = koordinate.at(indeks);
		if (najmanje_i > pomocni.at(indeks));
			najmanje_i = pomocni.at(indeks);
	}
	
	std::vector<int> pozicije_koordinate_i;
	for (int i{}; i<pozicije_vrhova.size(); i++)
	{
		int indeks = pozicije_vrhova.at(i);
		std::vector<int> pomocni = koordinate.at(indeks);
		if (najmanje_i == pomocni.at(indeks));
			{
				rezultat = skup_matrica.at(indeks);
				return rezultat;
			}
	}
	
	return rezultat;
}


int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	
	if (m < 0 || n < 0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout<<"Unesite elemente matrice: ";
	std::vector<std::vector<double>> matrica;
	
	for (int i{}; i<m; i++)
	{
		std::vector<double> red;
		for (int j{}; j<n; j++)
		{
			double x;
			std::cin>>x;
			red.push_back(x);
		}
		
		matrica.push_back(red);
	}
	
	
	auto rezultat = NajvecaPlaninaMatrice(matrica);
	
	std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
	
	for (int i{}; i<rezultat.size(); i++)
	{
		for (int j{};j<rezultat.at(i).size();j++)
			std::cout<<std::right<<std::setw(6)<<rezultat.at(i).at(j);
		
		std::cout<<std::endl;
	}
	
	
	
	
	
	return 0;
}









