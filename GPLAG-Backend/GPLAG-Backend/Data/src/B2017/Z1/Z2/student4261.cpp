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
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

void Ispisi (Matrica mat) {
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(0).size(); j++) {
			std::cout << std::setw(6) << mat.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

bool Grbava (Matrica mat) {
	int red(mat.at(0).size());
	for (int i=0; i<mat.size(); i++) {
		if (mat.at(i).size()!=red) return true;
	}
	return false;
}

double zbir (Matrica mat, int red, int kolona, int lvl) {
	double suma(0);
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(0).size(); j++) {
			if ((i==red-lvl || i==red+lvl) && (j>=kolona-lvl && j<=kolona+lvl)) suma+=mat.at(i).at(j);
			else if ((i>red-lvl && i<red+lvl) && (j==kolona-lvl || j==kolona+lvl)) suma+=mat.at(i).at(j);
		}
	}
	return suma;
}

Matrica Kreiraj (Matrica mat, int red, int kolona, int lvl) {
	Matrica m;
	m.resize(lvl*2-1);
	for (int i=0; i<lvl*2-1; i++) m.at(i).resize(lvl*2-1);
	for (int i=0; i<lvl*2-1; i++) {
		for (int j=0; j<lvl*2-1; j++) {
			m.at(i).at(j)=mat.at(red-lvl+1+i).at(kolona-lvl+1+j);
		}
	}
	return m;
}

Matrica NajvecaPlaninaMatrice (Matrica mat) {
	Matrica max;
	if (mat.size()<=0) return max;
	else if (Grbava(mat)) throw std::domain_error("Matrica nije korektna");
	else if (mat.at(0).size()==0) return max;
	
	max.resize(1); max.at(0).resize(1); max.at(0).at(0)=mat.at(0).at(0);
	int max_lvl(1), koordinata_i(0), koordinata_j(0);
	double centar(mat.at(0).at(0));
	
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(0).size(); j++) {
			int lvl(1);
			
			if (max_lvl==1 && mat.at(i).at(j)>centar) {
				centar=mat.at(i).at(j);
				max=Kreiraj(mat, i, j, lvl);
			}
			
			if (i+lvl<mat.size() && i-lvl>=0 && j-lvl>=0  && j+lvl<mat.at(0).size() && mat.at(i).at(j)>zbir(mat, i, j, lvl)) {
				lvl++;
				while (i+lvl<mat.size() && i-lvl>=0 && j-lvl>=0  && j+lvl<mat.at(0).size() && zbir(mat, i, j, lvl-1)>zbir(mat, i, j, lvl)) {
					lvl++;
				}
				if (lvl>max_lvl || (lvl==max_lvl && centar<mat.at(i).at(j)) || (lvl==max_lvl && std::fabs(centar-mat.at(i).at(j))<0.001 && i<koordinata_i) || (lvl==max_lvl && std::fabs(centar-mat.at(i).at(j))<0.001 && i==koordinata_i && j<koordinata_j)) {
					max_lvl=lvl;
					koordinata_i=i;
					koordinata_j=j;
					centar=mat.at(i).at(j);
					max=Kreiraj(mat, i, j, lvl);
				}
			}
		}
	}
	
	return max;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 1;
	} 
	Matrica mat;
	mat.resize(m);
	for (int i=0; i<m; i++) mat.at(i).resize(n);
	
	std::cout << "Unesite elemente matrice:" << std::endl;
	
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(0).size(); j++) {
			std::cin >> mat.at(i).at(j);
		}
	}
	try {
		std::cout << "Najveca planina unesene matrice je:" << std::endl;
		Ispisi (NajvecaPlaninaMatrice(mat));
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}