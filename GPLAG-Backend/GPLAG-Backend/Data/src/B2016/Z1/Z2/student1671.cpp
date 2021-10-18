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

Matrica h(Matrica m) {
	Matrica M(m.size());
	for (int i = 0; i < M.size(); i++) M[i].resize(m[0].size());
	int k(0);
	for (int i = 0; i < m.size(); i++) {
		k = 0;
		for (int j = m[0].size()-1; j >= 0; j--) M[i][k++] = m[i][j];
	}
	return M;
}

Matrica v(Matrica m) {
	Matrica M(m.size());
	for (int i = 0; i < M.size(); i++) M[i].resize(m[0].size());
	int k(0);
	for (int i = m.size()-1; i >= 0; i--) {
		for (int j = 0; j < m[0].size(); j++) M[k][j] = m[i][j];
		k++;
	}
	return M;
}

Matrica OgledaloMatrica(Matrica m) {
	Matrica M(3*m.size());
	for (int i = 0; i < M.size(); i++) M[i].resize(3*m[0].size());
	Matrica ve(v(m)), ho(h(m)), veho(v(ho));
	int redovi(m.size()), kolone;
	if (redovi) {
		kolone = m[0].size();
	}
	else kolone = 0;
	for (int g = 0; g < 3; g++) {
		for (int h = 0; h < 3; h++) {
			if ((g == 0 || g == 2) && (h == 0 || h == 2)) {
				for (int i = 0; i < veho.size(); i++)
					for (int j = 0; j < veho[0].size(); j++) M[redovi*g+i][kolone*h+j] = veho[i][j];
			}
			else if ((g == 0 || g == 2) && h == 1) {
				for (int i = 0; i < ve.size(); i++)
					for (int j = 0; j < ve[0].size(); j++) M[redovi*g+i][kolone*h+j] = ve[i][j];
			}
			else if (g == 1 && (h == 0 || h == 2)) {
				for (int i = 0; i < ho.size(); i++)
					for (int j = 0; j < ho[0].size(); j++) M[redovi*g+i][kolone*h+j] = ho[i][j];
			}
			else {
				for (int i = 0; i < m.size(); i++) 
					for (int j = 0; j < m[0].size(); j++) M[redovi*g+i][kolone*h+j] = m[i][j];
			}
		}
	}
	return M;
}

int main () {
Matrica M;
	int m, n, broj;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if (m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	M.resize(m);
	std::cout << "Unesite elemente matrice: ";
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) {
			std::cin >> broj;
			M[i].push_back(broj);
		}
	try {
		M = OgledaloMatrica(M);
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	std::cout << "\nRezultantna matrica: " << std::endl;
	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M[0].size(); j++) std::cout << std::setw(4) << M[i][j];
		std::cout << std::endl;
	}
	return 0;
}