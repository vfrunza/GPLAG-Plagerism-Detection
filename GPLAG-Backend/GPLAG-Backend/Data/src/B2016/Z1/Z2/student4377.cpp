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

void IspisiMatricu(std::vector<std::vector<double>> m) 
{
 	for(auto red : m) 
 	{
 		for(auto x : red) std::cout << std::right << std::setw(4) << x;
 		std::cout << std::endl;
 	}
}

std::vector<std::vector<double>> HorizontalnoOgledalo(std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> ogledalo(matrica.size());
	for(int i=0; i < matrica.size(); i++)
	for(int j=matrica[i].size()-1; j >= 0; j--) ogledalo[i].push_back(matrica[i][j]);
	
	return ogledalo;
}

bool IsGrbava(std::vector<std::vector<double>> m)
{
	for(int i = 0; i<m.size(); i++)
	{
		int vel = m[0].size();
		if(m[i].size() != vel) return true;
	}
	return false;
}

std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> ogledalo(matrica.size());

	for(int i = matrica.size()-1; i >= 0; i--)
	for(int j = 0; j<matrica[i].size(); j++) ogledalo[matrica.size()-1-i].push_back(matrica[i][j]);
	
	return ogledalo;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> g)
{
	if(IsGrbava(g)) throw std::domain_error("Matrica nije korektna"); 
	std::vector<std::vector<double>> vo(g.size()),ho(g.size()), ko(g.size()), ogledalo(3*g.size());
	
	ho = HorizontalnoOgledalo(g);
	vo = VertikalnoOgledalo(g);
	ko = HorizontalnoOgledalo(vo);
	
	for(int br = 0; br < 3; br++)
	{
		if(br == 0 || br == 2)
		{
			int vel = g.size();
			for(int i = 0; i < vel; i++)
			for(int j = 0; j < g[i].size(); j++)
			ogledalo[br*vel+i].push_back(ko[i][j]);
			
			for(int i = 0; i < vel; i++)
			for(int j = 0; j < g[i].size(); j++)
			ogledalo[br*vel+i].push_back(vo[i][j]);
			
			for(int i = 0; i < vel; i++)
			for(int j = 0; j < g[i].size(); j++)
			ogledalo[br*vel+i].push_back(ko[i][j]);
		}
		else if(br == 1)
		{
			int vel = g.size();
			for(int i = 0; i < vel; i++)
			for(int j = 0; j < g[i].size(); j++)
			ogledalo[br*vel+i].push_back(ho[i][j]);
			
			for(int i = 0; i < vel; i++)
			for(int j = 0; j < g[i].size(); j++)
			ogledalo[br*vel+i].push_back(g[i][j]);
			
			for(int i = 0; i < vel; i++)
			for(int j = 0; j < g[i].size(); j++)
			ogledalo[br*vel+i].push_back(ho[i][j]);
		}
	}
	return ogledalo;
}


int main ()
{
	
	std::cout << "Unesite dimenzije matrice (m n): "; 
	int m, n;
	if(std::cin >> m >> n, m < 0 || n < 0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> matrica(m);
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++)
	{
		double el;
		std::cin >> el; 
		matrica[i].push_back(el);
	}
	
	try
	{
		matrica = OgledaloMatrica(matrica);
		std::cout << std::endl << "Rezultantna matrica: " << std::endl;
		IspisiMatricu(matrica);
	}
	catch(std::domain_error izuzetak) 
	{
 		std::cout << izuzetak.what() << std::endl;
	}

	return 0;
}