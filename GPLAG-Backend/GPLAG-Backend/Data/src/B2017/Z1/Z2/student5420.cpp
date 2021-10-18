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

bool DaLiJeGrbava (Matrica mat) {
	for (int i=0; i<mat.size(); i++) 
		if (mat.at(i).size()!=mat.at(0).size())
			return true;
	return false;
}

Matrica NajvecaPlaninaMatrice (Matrica mat) {
	if (DaLiJeGrbava(mat)) throw std::domain_error ("Matrica nije korektna");
	Matrica np;
	if (mat.size()==0 || mat.at(0).size()==0) return np;
	int m(mat.size());
	int n(mat.at(0).size());
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			int k(1),p(i),r(i),q(j),w(j),br(1);
			double suma(0),x(mat.at(i).at(j));
			if (i!=0 && i!=m-1 && j!=0 && j!=n-1) {
				while (p>0 && r<m-1 && q>0 && w<n-1) {
					suma = mat.at(i-k).at(j-k) + mat.at(i-k).at(j) + mat.at(i-k).at(j+k) + mat.at(i).at(j-k) + mat.at(i).at(j+k) +
					   	mat.at(i+k).at(j-k) + mat.at(i+k).at(j) + mat.at(i+k).at(j+k);
					p=i-k;
					r=i+k;
					q=j-k;
					w=j+k;
					if (suma<x) {
						x=suma;
						k++;
						br+=2;
					}
					else break;
				}
				if (br>1 && br>np.size()) {
					np.resize(0);
					int h=br/2;
					for (int x=i-h; x<=i+h; x++) {
						std::vector<double> v;
						for (int y=j-h; y<=j+h; y++) 
							v.push_back(mat.at(x).at(y));
						np.push_back(v);
					}
				}
			}
		}
	}
	return np;
}

int main ()
{
	try{
		int m,n;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m >> n;
		if (m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		Matrica g(m,std::vector<double>(n));
		std::cout << "Unesite elemente matrice: " << std::endl;
		for (int i=0; i<m; i++) 
			for (int j=0; j<n; j++)
				std::cin >> g.at(i).at(j); 
		Matrica mat(NajvecaPlaninaMatrice(g));
		std::cout << "Najveca planina unesene matrice je: " << std::endl;
		for (int i=0; i<mat.size(); i++) {
			for (int j=0; j<mat.at(i).size(); j++)
				std::cout << std::setw(6) << mat.at(i).at(j);
			std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}