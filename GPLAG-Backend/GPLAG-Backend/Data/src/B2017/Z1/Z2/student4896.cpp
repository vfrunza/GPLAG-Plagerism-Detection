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
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu (int br_redova, int br_kolona)
{
	Matrica m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++) {
			std::cin >> m.at(i).at(j);
		}
	}
	return m;
}

void IspisiMatricu(Matrica m)
{
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.size(); j++) {
			std::cout << std::setw(6) << m.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

int Indeks(Matrica m, int kolona)
{
	int max(0);
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.at(i).size(); j++) {
			if(j==kolona) {
				if(m.at(i).at(j)>=max) {
					max=m.at(i).at(j);
				}
			}
		}
	}
	return max;
}

Matrica NajvecaPlaninaMatrice(Matrica mat)
{
	int broj(mat.at(0).size());
	for(int i=1; i<mat.size(); i++) {
		if(mat.at(i).size()!=broj) {
			throw std::domain_error("Matrica nije korektna");
		}
	}
	Matrica pov_mat;
	return pov_mat;
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice:" << std::endl;
	Matrica mat(UnesiMatricu(m,n));
	try {
		Matrica M(NajvecaPlaninaMatrice(mat));
		std::cout << "Najveca planina unesene matrice je:";
		IspisiMatricu(M);
	} catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
		return 0;
	}
	return 0;
}