#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica horizontalna(Matrica m)
{
	Matrica nova(m.size());
	
	for(int i{0}; i < m.size(); i++)
		for(int j{m[i].size() - 1}; j >= 0; j--)
			nova[i].push_back(m[i][j]);
	
	return nova;
}

Matrica vertikalna(Matrica m)
{
	Matrica nova;
	
	for(int i{m.size() - 1}; i >= 0; i--)
		nova.push_back(m[i]);
	
	return nova;
}

Matrica kombinovana(Matrica m)
{
	Matrica nova(m.size());
	
	nova = vertikalna(m);
	nova = horizontalna(nova);
	return nova;
}


void IspisiMatricu(Matrica m)
{
	for(int i{0}; i < m.size(); i++)
	{
		for(int j{0}; j < m[i].size(); j++)
			std::cout << std::setw(4) << m[i][j];
		std::cout << std::endl;
	}
}

int IndexSegmenta(int i, int j)
{
	//hv - 0
	//v - 1
	//h - 2
	//m - 3 
	if(i == 0 || i == 2)
	{
		if(j == 0 || j == 2) return 0;
		if(j == 1) return 1;
	}
	
	if(i == 1)
	{
		if(j == 0 || j == 2) return 2;
		if(j == 1) return 3;
	}
	
	
}

int mapirajSegment(int i, int vel)
{
	if(i < vel) return 0;
	if(i < vel * 2) return 1;
	if(i < vel * 3) return 2;
}

Matrica OgledaloMatrica(Matrica m)
{
	if(m.size() == 0) 
	{
		Matrica nova(0);
		return nova;
	}
	
	for(int i{0}; i < m.size()-1; i++)
		for(int j{i+1}; j < m.size(); j++)
			if(m[i].size() != m[j].size()) throw std::domain_error("Matrica nije korektna");
	
	
	
	int redovi{m.size()};
	int kolone{m[0].size()};
	
	redovi *= 3;
	kolone *= 3;
	
	Matrica nova(redovi, std::vector<double>(kolone));

	Matrica h;
	Matrica v;
	Matrica hv;
	h = horizontalna(m);
	v = vertikalna(m);
	hv = kombinovana(m);
	
	std::vector<Matrica> segmentMatrice{hv, v, h, m};
	
	for(int i{0}; i < nova.size(); i ++)
	{
		for(int j{0}; j < nova[0].size(); j++)
		{
			int redSegmenta = mapirajSegment(i, m.size());
			int kolonaSegmenta = mapirajSegment(j, m[0].size());
			
			Matrica trenutna = segmentMatrice[IndexSegmenta(redSegmenta, kolonaSegmenta)];
			nova[i][j] = trenutna[i % m.size()][j % m[0].size()];
			
		}
	}

	return nova;	
}

Matrica UnesiMatricu(int m, int n)
{
	Matrica mat(m, std::vector<double>(n));
	
	for(int i{0}; i < m; i ++)
		for(int j{0}; j < n; j++)
			std::cin >> mat[i][j];
	
	return mat;
}

int main ()
{
	Matrica mat;
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m < 0 || n < 0) 
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cin.clear();
	std::cout << "Unesite elemente matrice: ";
	mat = UnesiMatricu(m,n);
	
	Matrica nova;
	try
	{
		nova = OgledaloMatrica(mat);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << izuzetak.what();
		return 0;
	}
	std::cout << std::endl << "Rezultantna matrica:" << std::endl;
	IspisiMatricu(nova);
	
	return 0;
}