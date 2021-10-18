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
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu (int br_redova, int br_kolona)
{
	if (br_redova != br_kolona) throw std::domain_error ("Matrica nije korektna!");
	Matrica m(KreirajMatricu(br_redova, br_kolona));
	for (int i = 0; i<br_redova; i++)
	{
		for (int j = 0; j<br_kolona; j++)
		{
			std::cin >> m.at(i).at(j);
		}
	}
	return m;
}

Matrica NajvecaPlaninaMatrice (Matrica m)
{
	Matrica planina;
	for (int i = 0; i<m.size(); i++)
	{
		for (int j = 0; j<m.at(i).size(); j++)
		{
			if ()
		}
	}
	return planina; 
}

void IspisiMatricu (Matrica m)
{
	for (int i = 0; i<m.size(); i++)
	{
		for (int j = 0; j<m.at(i).size(); j++)
		{
			std::cout << m.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
}

int main ()
{
	try{
	int m, n;
	
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	std::cout << "Unesite elemente matrice: ";
	Matrica A(UnesiMatricu(m, n));
	
	std::cout << std::endl;
	std::cout << "Najveca planina unesene matrice je: ";
	
	}
	catch (std::domain_error izuzetak)
	{
		std::cout << "IZUZETAK: " << izuzetak.what() << std::endl;
	}
	
	return 0;
}