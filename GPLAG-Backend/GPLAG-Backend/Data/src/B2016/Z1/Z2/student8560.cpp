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
std::vector<std::vector<double>> horizontalna(std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> hor(matrica.size(), std::vector<double> (matrica[0].size()));
	for(int i(0); i < matrica.size(); i++) {
		int p = 0;
		for(int j(matrica[0].size()-1); j >= 0; j--) {
			hor[i][p++] = matrica[i][j];
		}
	}
	return hor;
}

std::vector<std::vector<double>> vertikalna(std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> vert;
	for(int i(matrica.size()-1); i >= 0; i--) {
		vert.push_back(matrica[i]);
	}
	
	return vert;
}

std::vector<std::vector<double>> hv(std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> M;
	std::vector<std::vector<double>> N;
	M = vertikalna(matrica);
	N = horizontalna(M);
	
	
return N;	
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica) {
	
	for(int j(0); j<matrica.size(); j++) {
		if(matrica[0].size() != matrica[j].size()) {
			throw std::domain_error("Matrica nije korektna!");
		}
	}	
	
		int m(matrica.size()), n(matrica[0].size());
	std::vector<std::vector<double>> konacno(3*m, std::vector<double> (3*n)), hove(hv(matrica)), ho(vertikalna(matrica)), ve(horizontalna(matrica));
	
	
	for(int i(0); i < 3*m; i++) {
		for(int j(0); j < 3*n; j++) {
			if (i < m && j < n) konacno[i][j] = hove[i][j];
			else if (i >= m && i < 2*m && j < n) konacno[i][j] = ve[i-m][j]; 
			else if (i >= 2*m && i < 3*m && j < n) konacno[i][j] = hove[i-2*m][j]; 
			else if (i < m && j >= n && j < 2*n) konacno[i][j] = ho[i][j-n];
			else if (i >= m && i < 2*m && j >=n && j < 2*n) konacno[i][j] = matrica[i-m][j-n];
			else if (i >= 2*m && i < 3*m && j >= n && j < 2*n) konacno[i][j] = ho[i-2*m][j-n];
			else if (i < m && j >= 2*n && j < 3*n) konacno[i][j] = hove[i][j-2*n];
			else if (i >= m && i < 2*m && j >= 2*n && j < 3*n) konacno[i][j] = ve[i-m][j-2*n];
			else if (i >= 2*m && i < 3*m && j >= 2*n && j < 3*n) konacno[i][j] = hove[i-2*m][j-2*n];
		}
	}
	
	
	return konacno;
}
void Ispisimatricu(std::vector<std::vector<double>> matrica) {
	for(int i(0); i < matrica.size(); i++) {
		for(int j(0); j < matrica[0].size(); j++) {
			std::cout << std::right << std::setw(4) << matrica[i][j];
		}
		std::cout << std::endl;
	}
}

int main () {
	
	int m, n;
	std::vector<std::vector<double>> nova;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> M(m, std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	
	if(m == 0 && n == 0) {
		std::cout<<std::endl<<"Rezultantna matrica: ";
		return 0;
	}
	for(int i(0); i < m; i++) {
		for(int j(0); j < n; j++) {
			std::cin >> M[i][j];
		}
	}
	try {
		nova = OgledaloMatrica(M);
		std::cout << std::endl <<"Rezultantna matrica: "<<std::endl;
		Ispisimatricu(nova);
		
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
		
		

	
	
	return 0;
}