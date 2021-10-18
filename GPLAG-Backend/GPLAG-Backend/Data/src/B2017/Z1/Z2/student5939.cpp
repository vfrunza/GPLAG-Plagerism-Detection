/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>


typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu (int br_redova, int br_kolona) {
	return Matrica(br_redova, std::vector<double>(br_kolona));
}
void IspisiMatricu (Matrica m) {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j<m[0].size(); j++) {
			std::cout << std::setw(6) << m[i][j];
			std::cout << std::endl;
		}
	}
}
bool Isti (Matrica m) {
	
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[0].size(); j++) {
			if(m[i][j] != m[0][0]) return false;
		}
	}
	
	return true;
}
Matrica NajvecaPlaninaMatrice (Matrica m) {
	
	Matrica rez;
	if(m.size() == 0 || m[0].size() == 0) return rez;
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[0].size(); j++) {
			if(m[i].size() != m[0].size()) throw std::domain_error ("Matrica nije korektna");
		}
	}
}

int main ()
{
	try {
		
		std::cout << "Unesite dimenzije matrice (m i n): ";
		int m, n;
		std::cin >> m >> n;
		if (m < 0 || n < 0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout << "Unesite elemente matrice:";
		Matrica mat;
		mat = KreirajMatricu(m, n);
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				std::cin >> mat[i][j];
			}
		}
		
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	
	return 0;
	
}