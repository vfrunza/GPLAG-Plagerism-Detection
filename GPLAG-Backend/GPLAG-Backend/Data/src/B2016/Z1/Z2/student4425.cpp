#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
//soIcantest
int Rows(std::vector<std::vector<double>> m) {
	return m.size();
}

int Columns(std::vector<std::vector<double>> m) {
	return m[0].size();
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> M) {
	std::vector<std::vector<double>> hM(Rows(M)), vM(Rows(M)), hvM(Rows(M));
	int i(0), k(0), l(0);
	
	bool grbava(false);
	for (i = 1; i < Rows(M); i++) {
		if (M[i].size() != M[i - 1].size()) {
			grbava = true;
			break;
		}
	}
	
	if (grbava) throw std::domain_error("Matrica nije korektna");
	
	//making hM
	for (i = 0; i < Rows(M); i++) {
		for (int j = Columns(M) - 1; j >= 0; j--) {
			hM[i].push_back(M[i][j]);
		}
	}
	
	//making vM
	for (i = 0; i < Rows(M); i++) {
		for (int j = 0; j < Columns(M); j++) {
			vM[Rows(M) - 1 - i].push_back(M[i][j]);
		}
	}
	
	//making hvM
	for (i = 0; i < Rows(vM); i++) {
		for (int j = Columns(vM) - 1; j >= 0; j--) {
			hvM[i].push_back(vM[i][j]);
		}
	}
	
	std::vector<std::vector<double>> m1(3*Rows(M)), m2(3*Rows(M));
	
	for (i = 0; i < 3*Rows(M); i++) {
		m1[i].resize(Columns(M));
		m2[i].resize(Columns(M));
	}
	
	//making m1
	for (i = 0; i < Rows(M); i++) {
		for (int j = 0; j < Columns(M); j++) {
			m1[i][j] = hvM[i][j];
		}
	}
	
	for (k = i; k < 2*Rows(M); k++) {
		for (int j = 0; j < Columns(M); j++) {
			m1[k][j] = hM[k-i][j];
		}
	}
	
	for (l = k; l < 3*Rows(M); l++) {
		for (int j = 0; j < Columns(M); j++) {
			m1[l][j] = hvM[l-k][j];
		}
	}
	
	//making m2
	for (i = 0; i < Rows(M); i++) {
		for (int j = 0; j < Columns(M); j++) {
			m2[i][j] = vM[i][j];
		}
	}
	
	for (k = i; k < 2*Rows(M); k++) {
		for (int j = 0; j < Columns(M); j++) {
			m2[k][j] = M[k-i][j]; 
		}
	}
	
	for (l = k; l < 3*Rows(M); l++) {
		for (int j = 0; j < Columns(M); j++) {
			m2[l][j] = vM[l-k][j];
		}
	}
	
	//final concatenation
	std::vector<std::vector<double>> mirror(3*Rows(M));
	for (i = 0; i < 3*Rows(M); i++) mirror[i].resize(3*Columns(M));
	int j(0), s(0), z(0);
	//i k l ROWS
	//j s z COLS
	
	for (i = 0; i < 3*Rows(M); i++) {
		for (j = 0; j < Columns(M); j++) {
			mirror[i][j] = m1[i][j];
		}
	}
	
	for (i = 0; i < 3*Rows(M); i++) {
		for (s = j; s < 2*Columns(M); s++) {
			mirror[i][s] = m2[i][s-j];
		}
	}
	
	for (i = 0; i < 3*Rows(M); i++) {
		for (z = s; z < 3*Columns(M); z++) {
			mirror[i][z] = m1[i][z-s];
		}
	}
	
	return mirror;
}

int main () {
	
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout << "Unesite elemente matrice: ";
	std::vector<std::vector<double>> matrica(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			std::cin >> num;
			matrica[i].push_back(num);
		}
	}
	
	std::vector<std::vector<double>> ispisi;
	
	try {
		ispisi = OgledaloMatrica(matrica);
	}
	catch (std::domain_error exc) {
		std::cout << exc.what(); 
	}

	std::cout << std::endl << "Rezultantna matrica: " << std::endl;
	for (int i = 0; i < 3*m; i++) {
		for (int j = 0; j < 3*n; j++) {
			std::cout << std::setw(4) << ispisi[i][j];
		}
		std::cout << std::endl;
	}
	
	return 0;
}