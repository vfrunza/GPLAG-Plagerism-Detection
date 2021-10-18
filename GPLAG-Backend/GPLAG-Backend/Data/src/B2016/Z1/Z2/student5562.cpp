/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector <std::vector <double>> Matrica;

Matrica HorizontalnoOgledalo(Matrica m)
{
	Matrica ogledalo;
	for (int i = 0; i < m.size(); i++)
	{	
		ogledalo.push_back(std::vector<double>(0));
		for (int j = static_cast <int> (m.at(i).size()) - 1; j >= 0; j--)
			ogledalo.at(i).push_back(m.at(i).at(j));
	}
	return ogledalo;
}

Matrica VertikalnoOgledalo(Matrica m)
{
	Matrica ogledalo;
	for (int i = static_cast <int>(m.size()) - 1; i >= 0; i--)
		ogledalo.push_back(m.at(i));
	
	return ogledalo;
}

Matrica OgledaloMatrica(Matrica m)
{
	for (int i = 0; i < static_cast <int> (m.size()) - 1; i++)
		if (m.at(i).size() != m.at(i + 1).size())
			throw std::domain_error("Matrica nije korektna"); 
		
	Matrica hor(HorizontalnoOgledalo(m));
	Matrica ver(VertikalnoOgledalo(m));
	Matrica mjes(VertikalnoOgledalo(hor));
	Matrica ogledalo;
	
	for(int i = 0; i < m.size(); i++)
	{
		ogledalo.push_back(std::vector<double>(0));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(i).push_back(mjes.at(i).at(j));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(i).push_back(ver.at(i).at(j));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(i).push_back(mjes.at(i).at(j));
	}
	
	for(int i = 0; i < m.size(); i++)
	{
		ogledalo.push_back(std::vector<double>(0));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(m.size() + i).push_back(hor.at(i).at(j));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(m.size() + i).push_back(m.at(i).at(j));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(m.size() + i).push_back(hor.at(i).at(j));
	}
	
	for(int i = 0; i < m.size(); i++)
	{
		ogledalo.push_back(std::vector<double>(0));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(2*m.size() + i).push_back(mjes.at(i).at(j));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(2*m.size() + i).push_back(ver.at(i).at(j));
		for (int j = 0; j < m.at(i).size(); j++)
			ogledalo.at(2*m.size() + i).push_back(mjes.at(i).at(j));
	}
	
	return ogledalo;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if (m < 0 || n < 0)
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
	else
	{
		Matrica mat;
		std::cout << "Unesite elemente matrice:\n";
		
		for (int i = 0; i < m; i++)
		{	
			mat.push_back(std::vector<double>(0));
			for (int j = 0; j < n; j++)
			{
				double broj;
				std::cin >> broj;
				mat.at(i).push_back(broj);
			}
		}
		Matrica ogledalo;
		try
		{
			ogledalo = OgledaloMatrica(mat);
			std::cout << "Rezultantna matrica:\n";
			for (std::vector<double>v:ogledalo)
			{
				for (double x:v)
					std::cout << std::setw(4) << std::right << x;
				std::cout << "\n";
			}
		}
		catch (std::domain_error izuzetak)
		{
			std::cout << izuzetak.what();
		}
	}	
	return 0;
}