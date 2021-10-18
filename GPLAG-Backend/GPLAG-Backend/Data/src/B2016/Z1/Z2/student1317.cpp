//B 2016/2017, Zadaća 1, Zadatak 2

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

typedef std::vector<std::vector<double>> Matrica;
// Funkcija Vertikalna obrce redove matrice
Matrica Vertikalna(Matrica m)
{
	for(int i=0; i<m.size()/2; i++)
	{
		for(int j=0; j<m[i].size(); j++)
		{
			double temp(m[i][j]);
			m[i][j]=m[m.size()-1-i][j];
			m[m.size()-1-i][j]=temp;
		}
	}
	
	return m;
}
// Funkcija Horizontalna obrce kolone matrice
Matrica Horizontalna(Matrica m)
{
	for(int i=0; i<m.size(); i++)
	{
		for(int j=0; j<m[i].size()/2; j++)
		{
			double temp(m[i][j]);
			m[i][j]=m[i][m[i].size()-1-j];
			m[i][m[i].size()-1-j]=temp;
		}
	}
	
	return m;
}

Matrica OgledaloMatrica(Matrica mat)
{
	Matrica matrica;

	for(int i=1; i<mat.size(); i++)
	{
		if(mat[i].size()!=mat[i-1].size()) throw std::domain_error("Matrica nije korektna");
	}
	Matrica h(Horizontalna(mat));
	Matrica v(Vertikalna(mat));
	Matrica hv(Horizontalna(Vertikalna(mat)));
	
	vector<double> red_mat;
	// Popunjavanje izlazne matrice kombinovanim ogledalom matrice mat,
	// vertikalnim ogledalom matrice mat i kombinovanim ogledalom matrice mat.
	for(int i=0; i<mat.size(); i++)
	{
		vector<double> prazni;
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(hv[i][j]);
		
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(v[i][j]);
		
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(hv[i][j]);
			
		matrica.push_back(red_mat);
		red_mat=prazni;
	}
	// Popunjavanje izlazne matrice horizontalnim ogledalom matrice mat,
	// vertikalnim ogledalom mat i horizontalnim ogledalom matrice mat.
	for(int i=0; i<mat.size(); i++)
	{
		vector<double> prazni;
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(h[i][j]);
		
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(mat[i][j]);
		
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(h[i][j]);
			
		matrica.push_back(red_mat);
		red_mat=prazni;
	}
	// Popunjavanje izlazne matrice kombinovanim ogledalom matrice mat,
	// vertikalnim ogledalom matrice mat i kombinovanim ogledalom matrice mat.
	for(int i=0; i<mat.size(); i++)
	{
		vector<double> prazni;
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(hv[i][j]);
		
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(v[i][j]);
		
		for(int j=0; j<mat[0].size(); j++)
			red_mat.push_back(hv[i][j]);
			
		matrica.push_back(red_mat);
		red_mat=prazni;
	}
	
	return matrica;
}

int main ()
{
	try
	{
		int m(0), n(0);
		cout << "Unesite dimenzije matrice (m n): ";
		cin >> m >> n;
	
		if(m<0 || n<0)
		{
			cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
	
		Matrica mat(m, vector<double>(n));
	
		cout << "Unesite elemente matrice: ";
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin >> mat[i][j];
			}
		}
		Matrica matrica(OgledaloMatrica(mat));
		
		cout << endl << "Rezultantna matrica: " << endl;
		for(int i=0; i<matrica.size(); i++)
		{
			for(int j=0; j<matrica[i].size(); j++)
			{
				cout << std::setw(4) << matrica[i][j];
			}
			cout << endl;
		}
	}
	catch(std::domain_error izuzetak)
	{
		cout << izuzetak.what() << endl;
	}
	return 0;
}


