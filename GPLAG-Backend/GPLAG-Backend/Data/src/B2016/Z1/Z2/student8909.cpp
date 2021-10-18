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

Matrica OgledaloMatrica (Matrica mat) {
	//int br_red(mat.size()), br_kol(mat[0].size());
	int br_red(mat.size()), br_kol(0);
	if (mat.size()>0) br_kol=mat[0].size();
	for (int i=1; i<br_red; i++) {
		if (br_kol!=mat[i].size()) throw std::domain_error ("Matrica nije korektna");
	}
	Matrica o_mat(3*br_red, std::vector<double>(3*br_kol));
	Matrica h_mat(br_red, std::vector<double>(br_kol));
	//horizontalna matrica
	for (int i=0; i<br_red; i++) {
		for (int j=0; j<br_kol; j++) {
			h_mat[i][j]=mat[i][br_kol-1-j];
		}
	}
	Matrica v_mat(br_red, std::vector<double>(br_kol));
	//vertikalna matrica
	for (int i=0; i<br_red; i++) {
		for (int j=0; j<br_kol; j++) {
			v_mat[i][j]=mat[br_red-1-i][j];
		}
	}
	Matrica hv_mat(br_red, std::vector<double>(br_kol));
	//kombinovana matrica
	for (int i=0; i<br_red; i++) {
		for (int j=0; j<br_kol; j++) {
			hv_mat[i][j]=mat[i][br_kol-1-j];
		}
	}
	Matrica mat_2(hv_mat);
	for (int i=0; i<br_red; i++) {
		for (int j=0; j<br_kol; j++) {
			hv_mat[i][j]=mat_2[br_red-1-i][j];
		}
	}
	for (int i=0; i<3*br_red; i++) {
		for (int j=0; j<3*br_kol; j++) {
			if (i<br_red && j<br_kol) o_mat[i][j]=hv_mat[i][j];
				else if (i<br_red && j>=br_kol && j<2*br_kol) o_mat[i][j]=v_mat[i][j-br_kol];
					else if (i<br_red && j>=2*br_kol) o_mat[i][j]=hv_mat[i][j-2*br_kol];
						else if (i>=br_red && i<2*br_red && j<br_kol) o_mat[i][j]=h_mat[i-br_red][j];
							else if (i>=br_red && i<2*br_red && j>=br_kol && j<2*br_kol) o_mat[i][j]=mat[i-br_red][j-br_kol];
								else if (i>=br_red && i<2*br_red && j>=2*br_kol) o_mat[i][j]=h_mat[i-br_red][j-2*br_kol];
									else if (i>=2*br_red && j<br_kol) o_mat[i][j]=hv_mat[i-2*br_red][j];
										else if (i>=2*br_red && j>=br_kol && j<2*br_kol) o_mat[i][j]=v_mat[i-2*br_red][j-br_kol];
											else if (i>=2*br_red && j>=2*br_kol) o_mat[i][j]=hv_mat[i-2*br_red][j-2*br_kol];
		}
	}
	return o_mat;
}

int main ()
{
	try {
		std::cout << "Unesite dimenzije matrice (m n): ";
		int m, n;
		std::cin >> m >> n;
		if (m<0 || n<0) throw std::domain_error ("Dimenzije matrice moraju biti nenegativne!");
		std::cout << "Unesite elemente matrice: ";
		Matrica mat(m, std::vector<double>(n));
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				std::cin >> mat[i][j];
			}
		}
		std::cout << std::endl << "Rezultantna matrica:" << std::endl;
		//ispis
		Matrica o_mat(OgledaloMatrica(mat));
		for (int i=0; i<m*3; i++) {
			for (int j=0; j<n*3; j++) {
				std::cout << std::right<< std::setw(4) << o_mat[i][j];
			}
			std::cout << std::endl;
		}
		return 0;
		}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
}