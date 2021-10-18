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

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int broj_redova, int broj_kolona)
{
	return Matrica(broj_redova, std::vector<double> (broj_kolona));
}

Matrica UnesiMatricu (int broj_redova, int broj_kolona)
{
	Matrica mat(KreirajMatricu(broj_redova,broj_kolona));
	
	for (int i = 0; i < broj_redova; i++)
	{
		for (int j = 0; j < broj_kolona; j++)
		{
			std::cin >> mat[i][j];
		}
	}
	
	return mat;
}

Matrica NajvecaPlaninaMatrice (Matrica mat)
{
	Matrica vrati_matricu;
	
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			if (mat[i].size() != mat[i+1].size()) throw std::domain_error ("Matrica nije korektna");
		}
	}
}
int main ()
{
	try
	{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	if (m <= 0 || n <= 0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout << "Unesite elemente matrice: ";
	Matrica mat;
    mat = UnesiMatricu(m,n);
	}
	
	catch (std::domain_error izuzetak)
	{
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}