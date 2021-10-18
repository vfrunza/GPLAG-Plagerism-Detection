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
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;


Matrica NajvecaPlaninaMatrice(Matrica m)
{

	Matrica mat(m);
	
	//ako je grbava matrica bacam izuzetak
	for(int i=0; i<m.size(); i++) {
		if(mat.at(i).size()!=mat.at(0).size()) {
			throw std::domain_error ("Matrica nije korektna");
		}
	}

	return mat;
}


int main ()
{
	try {
		int m,n;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m;
		std::cin >> n;

		if(n<0 || m<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
			return 0;
		}

		Matrica mat(m,std::vector<double>(n));

		std::cout << "Unesite elemenete matrice: " << std::endl;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				std::cin >> mat.at(i).at(j);
			}
		}

		Matrica final(NajvecaPlaninaMatrice(mat));

		std::cout << "Najveca planina unesene matrice je: " << std::endl;

		for(int i=0; i<final.size(); i++) {
			std::cout << std::endl;
			for(int j=0; j<final.at(0).size(); j++) {
				std::cout << std::setw(4) << final.at(i).at(j);
			}
		}
	} catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}



	return 0;
}