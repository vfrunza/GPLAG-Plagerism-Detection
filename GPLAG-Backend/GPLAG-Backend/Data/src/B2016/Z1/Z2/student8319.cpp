/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica horizontalna(Matrica mat) {
	Matrica rezz(mat.size(), std::vector<double>(mat[0].size()));
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat[i].size(); j++) {
			rezz[i][j] = mat[i][mat[i].size() - 1 - j];
		}
	}
	return rezz;
}

Matrica vertikalna(Matrica mat) {
	Matrica rezz(mat.size(), std::vector<double>(mat[0].size()));
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat[i].size(); j++) {
			rezz[i][j] = mat[mat.size() - 1 - i][j];
		}
	}
	return rezz;
}

Matrica hv(Matrica mat) {
	Matrica rezz(mat.size(), std::vector<double>(mat[0].size()));
	rezz = horizontalna(mat);
	rezz = vertikalna(rezz);
	return rezz;
}

Matrica OgledaloMatrica (Matrica mat) {
	if(mat.size() > 1) {
	for(int i = 0; i < mat.size() - 1; i++) {
		if(mat[i].size() != mat[i + 1].size()) throw std::domain_error("Matrica nije korektna");
	}
	}
	if(mat.size() == 0) {
		Matrica rezz;
		return rezz;
	}
	Matrica rezz(3 * mat.size(), std::vector<double>(3 * mat[0].size()));
	Matrica pom1(horizontalna(mat));
	Matrica pom2(vertikalna(mat));
	Matrica pom3(hv(mat));
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat[i].size(); j++) {
			rezz[i][j] = pom3[i][j];
		}
	}
	
	for(int i = 0; i < mat.size(); i++) {
		for(int j = mat[i].size(); j < 2 * mat[i].size(); j++) {
			rezz[i][j] = pom2[i][j - mat[i].size()];
		}
	}
	
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 2* mat[i].size(); j < 3 * mat[i].size(); j++) {
			rezz[i][j] = pom3[i][j - 2 * mat[i].size()];
		}
	}
	
	for(int i = mat.size(); i < 2 * mat.size(); i++) {
		for(int j = 0; j < mat[0].size(); j++) {
			rezz[i][j] = pom1[i - mat.size()][j];
		}
	}
	
	for(int i = mat.size(); i < 2 * mat.size(); i++) {
		for(int j = mat[0].size(); j < 2 * mat[0].size(); j++) {
			rezz[i][j] = mat[i - mat.size()][j - mat[0].size()];
		}
	}
	
	for(int i = mat.size(); i < 2 * mat.size(); i++) {
		for(int j = 2 * mat[0].size(); j < 3 * mat[0].size(); j++) {
			rezz[i][j] = pom1[i - mat.size()][j - 2 * mat[0].size()];
		}
	}
	
	for(int i = 2 * mat.size(); i < 3 * mat.size(); i++) {
		for(int j = 0; j < mat[0].size(); j++) {
			rezz[i][j] = pom3[i - 2 * mat.size()][j];
		}
	}
	
	for(int i = 2 * mat.size(); i < 3 * mat.size(); i++) {
		for(int j = mat[0].size(); j < 2 * mat[0].size(); j++) {
			rezz[i][j] = pom2[i - 2 * mat.size()][j - mat[0].size()];
		}
	}
	
	for(int i = 2 * mat.size(); i < 3 * mat.size(); i++) {
		for(int j = 2 * mat[0].size(); j < 3 * mat[0].size(); j++) {
			rezz[i][j] = pom3[i - 2 * mat.size()][j - 2 * mat[0].size()];
		}
	}
	
 	return rezz;
}

int main ()
{
	try{
	//Matrica a(10);
	//for(int i = 0; i < 10; i++) a[i].resize(i + 1);
	//Matrica b(OgledaloMatrica(a));
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	Matrica mat(m, std::vector<double>(n));
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat[i].size(); j++) {
			double broj;
			std::cin >> broj;
			mat[i][j] = broj;
		}
	}
	std::cout << std::endl;
	std::cout << "Rezultantna matrica: " << std::endl;
	Matrica rezz(OgledaloMatrica(mat));
	for(int i = 0; i < rezz.size(); i++) {
		for(int j = 0; j < rezz[i].size(); j++) {
			std::cout << std::setw(4) << rezz[i][j];
		}
		std::cout << std::endl;
	}
	}
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}