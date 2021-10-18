#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

Matrica obrni_kolone (Matrica mat) {
	Matrica pomocna (mat.size(), std::vector<double> (mat[0].size()));
		for (int i=0; i<pomocna.size(); i++) {
			for (int j=0; j<pomocna[i].size(); j++) 
			pomocna.at(i).at(j) = mat.at(i).at((mat[0].size() - 1 - j)) ;
		}
	return pomocna;
}

Matrica obrni_redove (Matrica mat) {
	Matrica pomocna (mat.size(), std::vector<double> (mat[0].size()));
	for (int i=mat.size()-1, j=0; i>=0; i--,j++) 
			pomocna.at(j) = mat.at(i);
	return pomocna;
}

Matrica obrni_sve (Matrica mat) {
	Matrica pomocna (mat.size(), std::vector<double> (mat[0].size()));
	for (int i=0; i<pomocna.size(); i++) {
		for (int j=0; j<pomocna[i].size(); j++)
			pomocna = obrni_kolone(obrni_redove(mat));
	}
	return pomocna;
}
Matrica OgledaloMatrica (Matrica mat) {
	Matrica prazna;
	if (mat.size() == 0)
		return prazna;
		
	for (int i=0; i<mat.size()-1; i++) {
			if (mat[i].size() != mat[i+1].size())
				throw std::domain_error ("Matrica nije korektna");
	}
	if (mat[0].size() == 0)
		return Matrica (3*mat.size());
	
	Matrica pomocna (3*mat.size(), std::vector<double> (3*mat[0].size() ));
	Matrica Horizontalno_Ogledalo (obrni_kolone(mat));
	Matrica Vertikalno_Ogledalo (obrni_redove(mat));
	Matrica Kombinovano_Ogledalo (obrni_sve(mat));
	
	int br_redova = mat.size();
	int br_kolona = mat[0].size();
	
	for (int i=0; i<pomocna.size(); i++) {
		
		for (int j=0; j<pomocna[i].size(); j++) {
			
			if (i>=0 && i<br_redova && j>=0 && j<br_kolona)
				pomocna.at(i).at(j) = Kombinovano_Ogledalo.at(i).at(j);
				
			if (i>=0 && i<br_redova && j>=br_kolona && j<(2*br_kolona))
				pomocna.at(i).at(j) = Vertikalno_Ogledalo.at(i).at((j-br_kolona));
				
			if ((i>=br_redova && i<=(br_redova*2)-1) && (j>=0 && j<br_kolona))
				pomocna.at(i).at(j) = Horizontalno_Ogledalo.at((i-br_redova)).at(j);
				
			if (i>=0 && i<br_redova && j>=2*br_kolona && j<3*br_kolona)
				pomocna.at(i).at(j) = Kombinovano_Ogledalo.at(i).at((j- 2*br_kolona));
				
			if (i>=br_redova && i<=(br_redova*2)-1 && j>=br_kolona && j<2*br_kolona)
				pomocna.at(i).at(j) = mat.at((i-br_redova)).at((j-br_kolona));
				
			if (i>=br_redova && i<=(br_redova*2)-1 && j>=2*br_kolona && j<3*br_kolona)
				pomocna.at(i).at(j) = Horizontalno_Ogledalo.at((i-br_redova)).at((j-2*br_kolona));
				
			if (i>=br_redova*2 && i<=(br_redova*3)-1 && j>=0 && j<br_kolona)
				pomocna.at(i).at(j) = Kombinovano_Ogledalo.at((i-2*br_redova)).at(j);
				
			if (i>=br_redova*2 && i<=(br_redova*3)-1 && j>=br_kolona && j<2*br_kolona)
				pomocna.at(i).at(j) = Vertikalno_Ogledalo.at((i-2*br_redova)).at((j-br_kolona));
			
			if (i>=br_redova*2 && i<=(br_redova*3)-1 && j>=2*br_kolona && j<3*br_kolona)
				pomocna.at(i).at(j) = Kombinovano_Ogledalo.at((i-2*br_redova)).at((j-2*br_kolona));
		}
	}

	return pomocna;
}
int main ()
{
	int n;
	int m;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> n >> m;
	if (n < 0 || m < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat (n, std::vector<double> (m));
	std::cout << "Unesite elemente matrice: ";
		for (int i=0; i<mat.size(); i++) {
			for (int j=0; j<mat[i].size(); j++) 
				std::cin>> mat[i][j];
		}
		
	try {
		mat = OgledaloMatrica(mat);
		std::cout << std::endl << "Rezultantna matrica: ";
		std::cout << std::endl;
		for (int i=0; i<mat.size(); i++) {
			for (int j=0; j<mat[i].size(); j++)
				std::cout << std::setw(4) << mat[i][j];
			std::cout << std::endl;
		}
	}
	catch (std::domain_error poruka) {
		std::cout << poruka.what() << std::endl;
	}
	catch (...) {
		std::cout << "Desila se greska koja se nije trebala desiti!";
	}
	return 0;
}