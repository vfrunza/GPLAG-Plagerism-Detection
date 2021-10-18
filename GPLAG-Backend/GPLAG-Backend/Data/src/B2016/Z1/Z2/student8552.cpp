/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using std::vector;

vector<vector<double>> VertikalnoOgledalo (vector<vector<double>> pocetna_mat) {
	int m(pocetna_mat.size()), n;
	if (m==0)
		n=0;
	else
		n=pocetna_mat[0].size();
	vector<vector<double>> vertikalna_mat(m,vector<double>(n));
	for (int i=m-1; i>=0; i--) {
		for (int j=0; j<n; j++) {
			vertikalna_mat[m-1-i][j]=pocetna_mat[i][j];
		}
	}
	return vertikalna_mat;
}

vector<vector<double>> HorizontalnoOgledalo (vector<vector<double>> pocetna_mat) {
	int m(pocetna_mat.size()), n;
	if (m==0)
		n=0;
	else
		n=pocetna_mat[0].size();
	vector<vector<double>> horizontalna_mat(m,vector<double>(n));
	for (int i=0; i<m; i++) {
		for (int j=n-1; j>=0; j--) {
			horizontalna_mat[i][n-1-j]=pocetna_mat[i][j];
		}
	}
	return horizontalna_mat;
}

vector<vector<double>> KombinovanoOgledalo (vector<vector<double>> pocetna_mat) {
	pocetna_mat=VertikalnoOgledalo(pocetna_mat);
	pocetna_mat=HorizontalnoOgledalo(pocetna_mat);
	return pocetna_mat;
}

vector<vector<double>> OgledaloMatrica (vector<vector<double>> pocetna_mat) {
	for (int i=0; i<pocetna_mat.size(); i++) {
		if (pocetna_mat[i].size()!=pocetna_mat[0].size()) throw std::domain_error("Matrica nije korektna");
	}
	int m(pocetna_mat.size()), n;
	if (m==0)
		n=0;
	else
		n=pocetna_mat[0].size();
	int p(3*m), q(3*n);
	vector<vector<double>> velika_mat(p, vector<double>(q));
	vector<vector<double>> horiz_mat(HorizontalnoOgledalo(pocetna_mat));
	vector<vector<double>> vertik_mat(VertikalnoOgledalo(pocetna_mat));
	vector<vector<double>> komb_mat(KombinovanoOgledalo(pocetna_mat));
	for (int i=0; i<p; i++) {
		for (int j=0; j<q; j++) {
			if ((i<p/3 && j<q/3) || (i<p/3 && j>=2*(q/3)) || (i>=2*(p/3) && j<q/3) || (i>=2*(p/3) && j>=2*(q/3))) {
				for (int k=0; k<m; k++) {
					for (int l=0; l<n; l++) {
						velika_mat[k+i][l+j]=komb_mat[k][l];
					}
				}
				j+=n-1;
			}
			else if ((i<p/3 && j>=q/3 && j<2*(q/3)) || (i>=2*(p/3) && j>=q/3 && j<2*(q/3))) {
				for (int k=0; k<m; k++) {
					for (int l=0; l<n; l++) {
						velika_mat[k+i][l+j]=vertik_mat[k][l];
					}
				}
				j+=n-1;
			}
			else if ((i>=p/3 && i<2*(p/3) && j<q/3) || (i>=p/3 && i<2*(p/3) && j>=2*(q/3))) {
				for (int k=0; k<m; k++) {
					for (int l=0; l<n; l++) {
						velika_mat[k+i][l+j]=horiz_mat[k][l];
					}
				}
				j+=n-1;
			}
			else {
				for (int k=0; k<m; k++) {
					for (int l=0; l<n; l++) {
						velika_mat[k+i][l+j]=pocetna_mat[k][l];
					}
				}
				j+=n-1;
			}
		}
		i+=m-1;
	}
	return velika_mat;
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	try {
		vector<vector<double>> mat(m, vector<double>(n));
		std::cout << "Unesite elemente matrice: " << std::endl;
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++)
				std::cin >> mat[i][j];
		}
	
		vector<vector<double>> rezultantna_mat(OgledaloMatrica(mat));
		std::cout << "Rezultantna matrica:" << std::endl;
		for (int i=0; i<rezultantna_mat.size(); i++) {
			for (int j=0; j<rezultantna_mat[0].size(); j++)
				std::cout << std::setw(4) << rezultantna_mat[i][j];
			std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	
	return 0;
}