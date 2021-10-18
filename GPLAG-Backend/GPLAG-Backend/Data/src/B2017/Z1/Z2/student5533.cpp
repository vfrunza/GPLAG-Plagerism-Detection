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
typedef std::vector <std::vector<double> > Matrica;

Matrica NajvecaPlaninaMatrice (Matrica mat)
{
	//int maxi(1), maxj(1), k(0);
	Matrica mat1;
	for (int i=0; i<mat.size(); i++) {
		if (mat.at(i).size()!=mat.at(0).size()) {
			throw std::domain_error ("Matrica nije korektna");
		}
	}
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(i).size(); j++) {
			if (mat.size()<0 || mat.at(i).size()<0) {
				throw std::domain_error ("Dimenzije matrice moraju biti nenegativne!");
			}
		}
	}
	/*for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(i).size(); j++) {
			if (i>0 && i<mat.size()-1 && j>0 && j<mat.at(i).size()-1 ) {
				if ((mat.at(i-1).at(j-1)+mat.at(i-1).at(j)+mat.at(i-1).at(j+1)+mat.at(i).at(j-1)+mat.at(i).at(j+1)+mat.at(i+1).at(j-1)+mat.at(i+1).at(j)+mat.at(i).at(j))<mat.at(i+1).at(j+1) {
					mat1.push_back ()
				
			    }
		    }
	    }
    }*/
return mat1;
}



int main ()
{
	try {
		Matrica mat, mat1;
		int m,n;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m >> n;
		if (m<0 || n<0) {
			std::cout<< "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		mat.resize (m);
		for (int i=0; i<m; i++) {
			mat.at(i).resize(n);
		}
		std::cout << "Unesite elemente matrice: ";
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				std::cin >> mat.at(i).at(j);
			}
		}
	} catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}