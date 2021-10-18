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

Matrica ispuni(Matrica mat) {
	Matrica pomocna(mat.size() * 3, std::vector<double> (mat[0].size() * 3));
	int x(0), y(0);
	for (int i = 0; i < pomocna.size(); i++) {
		for (int j = 0; j < pomocna[0].size(); j++) {
			if (x == mat.size()) x = 0;
			if (y == mat[0].size()) y = 0;
			pomocna[i][j] = mat[x][y];
			y++;
		}
		x++;
	}
	return pomocna;
}

Matrica horizontala(Matrica mat) {
	for (int i = 0; i < mat.size(); i++) {
		int j(0), k(mat[i].size() - 1);
		while (j <= k) {
			double tmp(mat[i][j]);
			mat[i][j] = mat[i][k];
			mat[i][k] = tmp;
			j++; k--;
		}
	}
	return ispuni(mat);
}

Matrica vertikalna(Matrica mat) {
	int i(0), j(mat.size() - 1);
	while (i <= j) {
		std::vector<double> tmp(mat[i]);
		mat[i] = mat[j];
		mat[j] = tmp;
		i++; j--;
	}
	return ispuni(mat);
}

Matrica OgledaloMatrica(Matrica mat) {
	if (mat.size() == 0) return {};
	for (int i = 0; i < mat.size(); i++)
		if (mat[0].size() != mat[i].size()) throw std::domain_error("Matrica nije korektna");
	Matrica rez(mat.size() * 3, std::vector<double> (mat[0].size() * 3));
	Matrica hor(horizontala(mat));
	Matrica ver(vertikalna(mat));
	Matrica kom(vertikalna(horizontala(mat)));
	kom.resize(mat.size() * 3);
	for (int i = 0; i < mat.size(); i++)
		kom[i].resize(mat[0].size());
	int red(mat.size()), kolone(mat[0].size());
	rez = ispuni(mat);
	for (int i = 0; i < rez.size(); i++)
		for (int j = 0; j < rez[0].size(); j++) {
			if ((i < red or i >= red * 2) and (j < kolone or j >= kolone * 2)) // kombinovana
				rez[i][j] = kom[i][j];
			else if ( (i >= red and i < red * 2) and (j < kolone or j >= kolone * 2) ) // horizontalna 
				rez[i][j] = hor[i][j];
			else if ((i < red or i >= red * 2 ) and (j >= kolone and j < kolone * 2)) // vertikalna
				rez[i][j] = ver[i][j];
	}
	return rez;
}

int main () {
	try {
		std::cout << "Unesite dimenzije matrice (m n): ";
		int m, n;
		std::cin >> m >> n;
		if (m < 0 or n < 0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		Matrica mat(m, std::vector<double>(n));
		std::cout << "Unesite elemente matrice: ";
		for (int i = 0; i < m; i++) 
			for (int j = 0; j < n; j++)
				std::cin >> mat[i][j];
		mat = OgledaloMatrica(mat);
		std::cout << "\nRezultantna matrica:\n";
		for (std::vector<double> x : mat) {
			for (double y : x)
				std::cout << std::setw(4) << y;
			std::cout << "\n";
		}
	}
	catch(std::domain_error e) {
		std::cout << e.what();
	}
	return 0;
}