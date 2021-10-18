/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

bool DaLiJeGrbava (std::vector<std::vector<double>> m) {
	for (int i = 0; i < m.size(); i++) {
		for (int j = i; j < m.size(); j++){
			if (m[i].size() != m[j].size()) 
				return true;
		}
	}
	return false;
}

std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> m) {
	if (DaLiJeGrbava(m) == true) throw std::domain_error("Matrica nije korektna");
	int brRedova, brKolona;
	if (m.size() == 0) {
		brRedova = 0; brKolona = 0;
	}
	else {
		brRedova = m.size() * 3; brKolona = m[0].size() * 3;
	}
	std::vector<std::vector<double>> mat(brRedova, std::vector<double> (brKolona));
	for (int i = 0; i <= brRedova - 1; i++) {
		for (int j = 0; j <= brKolona - 1; j++) {
			if (i >= 0 && i <= m.size() - 1) {
				if (j >= 0 && j <= m[0].size() - 1)								//hv matrice red 1 
					mat[i][j] = m[m.size()-1-i][m[0].size()-1-j];				//hv matrice red 1
				else if (j <= brKolona - 1 && j >= brKolona - m[0].size())		//hv matrice red 1
					mat[i][j] = m[m.size()-1-i][brKolona-j-1];					//hv matrice red 1
				else if (j >= m[0].size() && j <= brKolona - m[0].size() - 1)	//v matrica red 1
					mat[i][j] = m[m.size()-1-i][j-m[0].size()];					//v matrica red 1
				continue;
			}
			else if (i >= m.size() && i <= brRedova - m.size() - 1) {
				if (j >= 0 && j <= m[0].size() - 1)								//h matrice red 2
					mat[i][j] = m[i - m.size()][m[0].size()-j-1];				//h matrice red 2
				else if (j <= brKolona - 1 && j >= brKolona - m[0].size())		//h matrice red 2
					mat[i][j] = m[i - m.size()][brKolona-j-1];					//h matrice red 2
				else if (j >= m[0].size() && j <= brKolona - m[0].size() - 1)	//matrica red 2
					mat[i][j] = m[i - m.size()][j-m[0].size()];					//matrica red 2
				continue;
			}
			else if (i >= brRedova - m.size() && i <= brRedova - 1) {
				if (j >= 0 && j <= m[0].size() - 1)
					mat[i][j] = m[brRedova - i - 1][m[0].size() - 1 - j];
				else if (j <= brKolona - 1 && j >= brKolona - m[0].size()) 
					mat[i][j] = m[brRedova - i - 1][brKolona-1-j];
				else if (j >= m[0].size() && j <= brKolona - m[0].size() - 1)
					mat[i][j] = m[brRedova - i - 1][j-m[0].size()];
				continue;
			}
		}
	}
	return mat;
}

#include <iostream>
#include <vector>

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if (m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> matrica(m, std::vector<double> (n));
	std::cout << "Unesite elemente matrice:" << std::endl;
	double element;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> element;
			matrica[i][j] = element;
		}
	}
	try {
		std::vector<std::vector<double>> mat(OgledaloMatrica(matrica));
		std::cout << "Rezultantna matrica:" << std::endl;
		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[0].size(); j++) {
				std::cout << std::setw(4) << mat[i][j];
			}
			std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}