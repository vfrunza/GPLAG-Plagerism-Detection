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

double SumaKvadrata (Matrica m) {
	int BrRedova (m.size());
	double max (m.at(BrRedova/2).at(BrRedova/2));
	double suma;
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m.at(i).size(); j++) {
		if (i!=BrRedova/2 && j!=BrRedova/2)		suma = suma + m.at(i).at(j);	
		}
	}
	if (suma > max) return suma;
	return 0;
}

bool GrbavaMatrica (Matrica m) {
	for (int i=0; i<m.size(); i++) {
		if (m.at(0).size() != m.at(i).size()) return true;
	}
	return false;
}

double MAX (Matrica m) {
	double max(m.at(0).at(0));
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m.at(i).size(); j++) {
			if (m.at(i).at(j)>max) max = m.at(i).at(j);
		}
	}
	return max;
}

Matrica NajvecaPlaninaMatrice (Matrica m) {
	
	Matrica Najveca;
	
	if (m.size()==0 || m.at(0).size()==0) return Najveca;
	if (GrbavaMatrica(m)) throw std::domain_error ("Matrica nije korektna");
	
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++) {
			
		}
	}
	
	return m;
}

int main ()
{
	try {
		int m, n;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m >> n;
		if (m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		//if (m==0 || n==0)
		double broj;															// unos matrice
		Matrica mat;
		std::cout << "Unesite elemente matrice: ";
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				std::cin >> broj;
				mat.at(i).at(j) = broj;
			}
		}
		
		Matrica planina = NajvecaPlaninaMatrice(mat);							// ispis matrice
		for (int i=0; i<planina.size(); i++) {
			for (int j=0; j<planina.at(i).size(); j++)
				std::cout << std::left << std::setw(6) << planina.at(i).at(j);
			std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	
	return 0;
}