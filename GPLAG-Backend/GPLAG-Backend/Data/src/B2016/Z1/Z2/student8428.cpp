#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica StvoriMatricu(int n, int m)
{
	Matrica mat;
	mat.resize(n);
	for(int j(0); j < n; j++)
		mat[j].resize(m);
	return mat;
}
void Ispisimatricu(Matrica m)
{
	for(int i(0); i < m.size(); i++)
	{
		for(int j(0); j < m[0].size(); j++)
			std::cout << std::setw(4) << m[i][j] ;
			
		std::cout << "\n";
	}
}
Matrica Horizontalna(Matrica m)
{
	Matrica temp = StvoriMatricu(m.size(), m[0].size());
	for(int i(0); i < m.size(); i++)
	{
		for(int j(0); j < m[0].size(); j++)
		{
			temp[i][j] = m[i][m[0].size() - j - 1];
		}
	}
	return temp;
}
Matrica Vertikalna(Matrica m)
{
	Matrica temp = StvoriMatricu(m.size(), m[0].size());
	for(int i(0); i < m.size(); i++)
	{
		for(int j(0); j < m[0].size(); j++)
		{
			temp[i][j] = m[m.size() - 1 - i][j];
		}
	}
	return temp;
}
Matrica Kombinovana(Matrica m)
{
	Matrica temp = StvoriMatricu(m.size(), m[0].size());
	for(int i(0); i < m.size(); i++)
	{
		for(int j(0); j < m[0].size(); j++)
		{
			temp[i][j] = m[m.size() - 1 - i][m[0].size() - j - 1];
		}
	}
	return temp;
}

void ProvjeraIspravnostiMatrice(Matrica mat)
{
	auto red = mat[0].size();
	for(int i = 1; i < int(mat.size()); ++i)
		if(red != int(mat[i].size()))
			throw std::domain_error("Matrica nije korektna");
}

Matrica OgledaloMatrica(Matrica mat)
{
	if(mat.size() == 0)
		return mat;
	ProvjeraIspravnostiMatrice(mat);
	int m = mat.size();
	int n = mat[0].size();
	Matrica temp = StvoriMatricu(m * 3, n * 3);
	Matrica hor = Horizontalna(mat);
	Matrica ver = Vertikalna(mat);
	Matrica komb = Kombinovana(mat);
	
	for(int i(0); i < temp.size(); i++)
	{
		for(int j(0); j < temp[0].size(); j++)
		{
			if(i < m && j < n)
				temp[i][j] = komb[i][j];
				
			else if(i < m && j >= n && j < n * 2)
				temp[i][j] = ver[i][j - n];
				
			else if(i < m && j >= n * 2)
				temp[i][j] = komb[i][j - 2 * n];
				
				
			else if(i >= m && i < m * 2 && j < n)
				temp[i][j] = hor[i - m][j];
				
			else if(i >= m && i < m * 2 && j >= n && j < n * 2 )
				temp[i][j] = mat[i - m][j - n];
				
			else if(i >= m && i < m * 2 && j >= n * 2)
				temp[i][j] = hor[i - m][j - 2 * n];
			
				
			else if(i >= 2 * m && j < n)
				temp[i][j] = komb[i - 2 * m][j];
			
			else if(i >= 2 * m && j >= n && j < n * 2)
				temp[i][j] = ver[i - 2 * m][j - n];
				
			else if(i >= 2 * m && j >= n * 2)
				temp[i][j] = komb[i - 2 * m][j - 2 * n];
		}
	}
	return temp;
}
int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin >> m >> n;
	if( m < 0 ||n < 0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat = StvoriMatricu(m, n);
	std::cout << "Unesite elemente matrice:\n";
	for(int i(0); i < m; i++)
	{
		for(int j(0); j < n; j++)
		{
			std::cin >> mat[i][j];
		}
	}
	std::cout << "Rezultantna matrica:\n";
	Ispisimatricu(OgledaloMatrica(mat));
	return 0;
}