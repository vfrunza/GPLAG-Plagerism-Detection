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
typedef std::vector<std::vector<double>> Matrica;

int sirinaMatrice(Matrica matrica)
{
	if(matrica.size() == 0)
		return 0;
	else
		return matrica[0].size();
}

Matrica HorizontalnaMatrica(Matrica matrica)
{
	Matrica pomocna;
	for(int i = 0; i < matrica.size(); i++)
	{
		std::vector<double> pom;
		for(int j = matrica[i].size() - 1; j >= 0; j--)
			pom.push_back(matrica[i][j]);
		pomocna.push_back(pom);
	}
	return pomocna;	
}

Matrica VertikalnaMatrica(Matrica matrica)
{
	Matrica pomocna;
	for(int i = matrica.size() - 1; i >= 0; i--)
	{
		std::vector<double> pom;
		for(int j = 0; j < matrica[i].size(); j++)
			pom.push_back(matrica[i][j]);
		pomocna.push_back(pom);
	}
	return pomocna;
}

Matrica KombinovanaMatrica(Matrica matrica)
{
	return HorizontalnaMatrica(VertikalnaMatrica(matrica));
}

Matrica OgledaloMatrica(Matrica matrica)
{
	for(int i = 0; i < matrica.size(); i++)
	{
		int vel = matrica[0].size();
		if(matrica[i].size() != vel)
			throw std::domain_error("Matrica nije korektna");
	}
	Matrica h{HorizontalnaMatrica(matrica)}, v{VertikalnaMatrica(matrica)}, hv{KombinovanaMatrica(matrica)};
	Matrica ogledalo(3 * h.size(), std::vector<double>(3 * sirinaMatrice(matrica)));
	if(sirinaMatrice(matrica) == 0)
		return ogledalo;
	
	//Unos prve tri matrice
	for(int i = 0; i < hv.size(); i++)
		for(int j = 0; j < hv[0].size(); j++)
			ogledalo[i][j] = hv[i][j];
	for(int i = 0; i < v.size(); i++)
		for(int j = hv[0].size(); j < hv[0].size() + v[0].size(); j++)
			ogledalo[i][j] = v[i][j - v[0].size()];
	for(int i = 0 ; i < hv.size(); i++)
		for(int j = hv[0].size() + v[0].size(); j < ogledalo[0].size(); j++)
			ogledalo[i][j] = hv[i][j - hv[0].size() - v[0].size()];
	
	//Unos druge tri matrice
	for(int i = hv.size(); i < hv.size() + h.size(); i++)
		for(int j = 0; j < h[0].size(); j++)
			ogledalo[i][j] = h[i - hv.size()][j];
	for(int i = v.size(); i < v.size() + matrica.size(); i++)
		for(int j = h[0].size(); j < h[0].size() + matrica[0].size(); j++)
			ogledalo[i][j] = matrica[i - v.size()][j - h[0].size()];
	for(int i = hv.size(); i < hv.size() + h.size(); i++)
		for(int j = h[0].size() + matrica[0].size(); j < ogledalo[0].size(); j++)
			ogledalo[i][j] = h[i - hv.size()][j - h[0].size() - matrica[0].size()];
	
	//Unos trece tri matrice
	for(int i = hv.size() + h.size(); i < ogledalo.size(); i++)
		for(int j = 0; j < hv[0].size(); j++)
			ogledalo[i][j] = hv[i - hv.size() - h.size()][j];
	for(int i = hv.size() + h.size(); i < ogledalo.size(); i++)
		for(int j = hv[0].size(); j < hv[0].size() + v[0].size(); j++)
			ogledalo[i][j] = v[i - hv.size() - h.size()][j - hv[0].size()];
	for(int i = hv.size() + h.size(); i < ogledalo.size(); i++)
		for(int j = hv[0].size() + h[0].size(); j < ogledalo[0].size(); j++)
			ogledalo[i][j] = hv[i - hv.size() - h.size()][j - hv[0].size() - h[0].size()];
	return ogledalo;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m = 0, n = 0;
	std::cin >> m >> n;
	if(m < 0 || n < 0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	std::cout << "Unesite elemente matrice: " << std::endl;
	Matrica matrica(m, std::vector<double>(n));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			std::cin >> matrica[i][j];
	Matrica ogledalo;
	try
	{
		ogledalo = OgledaloMatrica(matrica);
	}
	catch(std::domain_error greska)
	{
		std::cout << "Izuzetak: " << greska.what() << std::endl;
		return 0;
	}
	std::cout << "Rezultantna matrica: " << std::endl;
	for(std::vector<double> red : ogledalo)
	{
		for(double element : red)
			std::cout << std::setw(4) << element;
		std::cout << std::endl;
	}
	return 0;
}