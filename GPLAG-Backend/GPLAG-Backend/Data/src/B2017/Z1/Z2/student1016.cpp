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
#include <stdexcept>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int broj_redova, int broj_kolona) {
	return Matrica (broj_redova, std::vector<double>(broj_kolona));
}

int BrojRedova (Matrica mat) {
	return mat.size();
}

int BrojKolona (Matrica mat) {
	return mat.at(0).size();
}

Matrica NajvecaPlaninaMatrice (Matrica mat) {
	Matrica pomocna;
	
	// Vraca se matrica formata 0x0 u slucaju da je proslijedjena prazna matrica
	if (BrojRedova(mat)==0 || BrojKolona(mat)==0) {
		return pomocna;
	}
	
	// Bacanje izuzetka u slucaju da je proslijedjena grbava matrica
	int sirina(BrojKolona(mat));
	for (int i=0; i<mat.size(); i++) {
		if (mat.at(i).size()!=sirina) throw std::domain_error ("Matrica nije korektna");
	}
	return pomocna;
}

int main () {
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	
	if (m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	auto mat(KreirajMatricu(m, n));
	std::cout<<"Unesite elemente matrice: ";
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			std::cin>>mat.at(i).at(j);
		}
	}
	try {
		std::cout<<std::endl;
		std::cout<<"Najveca planina unesene matrice je: ";
		auto matrica(NajvecaPlaninaMatrice(mat));
		
		for (int i=0; i<BrojRedova(matrica); i++) {
			for (int j=0; j<BrojKolona(matrica); j++) {
				std::cout<<matrica.at(i).at(j)<<" ";
			}
		}

	}
	catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
		return 0;
	}
	
	
	return 0;
}