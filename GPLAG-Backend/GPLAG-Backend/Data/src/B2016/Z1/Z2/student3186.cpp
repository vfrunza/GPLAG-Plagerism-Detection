//B 2016/2017, Zadaća 1, Zadatak 2
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>

typedef std::vector<std::vector<double>> Matrica_inc;

Matrica_inc OgledaloMatrica (Matrica_inc mat)
{	
	if (mat.size() == 0) return Matrica_inc(0);
	for (int i=0; i<mat.size(); ++i)
		if (mat[0].size() == mat[i].size())	continue;
		else throw std::domain_error ("Matrica nije korektna");
		
	int x(0), y(0);
	Matrica_inc hmat(mat.size(), std::vector<double>(mat[0].size()));
	for (int i=0; i<mat.size(); ++i) {
		for (int j=mat[i].size()-1; j >= 0; --j) {
			hmat[y][x] = mat[i][j];
			x++;
		}	x=0; y++;
	}
	
	x=0; y=0;
	Matrica_inc vmat(mat.size(), std::vector<double>(mat[0].size()));
	for (int i=mat.size()-1; i >= 0; --i) {
		for (int j=0; j<mat[i].size(); ++j) {
			vmat[y][x] = mat[i][j];
			x++;
		}	x=0; y++;
	}
	
	x=0; y=0;
	Matrica_inc hvmat(mat.size(), std::vector<double>(mat[0].size()));
	for (int i=mat.size()-1; i >= 0; --i) {
		for (int j=mat[i].size()-1; j >= 0; --j) {
			hvmat[y][x] = mat[i][j];
			x++;
		}	x=0; y++;
	}
	
	Matrica_inc output_matrica(3*mat.size(), std::vector<double>(3*mat[0].size()));
	for (int i=0; i<hvmat.size(); ++i)
		for (int j=0; j<hvmat[i].size(); ++j)
		{	
			// hvmat - matrica po coskovima.
			output_matrica[i][j] = hvmat[i][j];
			output_matrica[i+2*hvmat.size()][j] = hvmat[i][j];
			output_matrica[i][j+2*hvmat[i].size()] = hvmat[i][j];
			output_matrica[i+2*hvmat.size()][j+2*hvmat[i].size()] = hvmat[i][j];
			// vmat - matrica po vertikali.
			output_matrica [i][j+vmat[i].size()] = vmat[i][j];
			output_matrica [i+2*vmat.size()][j+vmat[i].size()] = vmat[i][j];
			// mat - matrica u centru.
			output_matrica [i+mat.size()][j+mat[i].size()] = mat[i][j];
			// hmat - matrica po horizontali.
			output_matrica [i+hmat.size()][j] = hmat[i][j];
			output_matrica [i+hmat.size()][j+2*hmat[i].size()] = hmat[i][j];
		}
	return output_matrica;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if (m<0 or n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout << "Unesite elemente matrice: " << std::endl;
	Matrica_inc matrica (m, std::vector<double>(n));
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			std::cin >> matrica[i][j];
	
	try {		
		std::cout << "Rezultantna matrica: " << std::endl;
		for (auto red : OgledaloMatrica(matrica)) {
			for (auto x : red)	std::cout << std::setw(4) << x;
			std::cout << std::endl;
		}
	}	catch (std::domain_error greska)	{
		std::cout << greska.what() << std::endl;
	}	return 0;
}