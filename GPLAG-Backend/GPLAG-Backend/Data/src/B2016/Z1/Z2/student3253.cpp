/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream>
#include <vector>
#include <iomanip>

// typedef std::vector<std::vector<double> > Matrica;

void PrintajMatricu(std::vector<std::vector<double> > matrica) {
	for (int i=0; i<matrica.size(); i++) {
		for (int j=0; j<matrica[i].size(); j++) {
			std::cout << std::setw(4) << matrica[i][j];
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<double> > OgledaloMatrica (std::vector<std::vector<double> > M) {

    std::vector<std::vector<double> > hM(M.size(), std::vector<double>(M[0].size(), 0));
    std::vector<std::vector<double> > vM(M.size(), std::vector<double>(M[0].size(), 0));
    std::vector<std::vector<double> > hvM(M.size(), std::vector<double>(M[0].size(), 0));
    std::vector<std::vector<double> > rezultat(3*M.size(), std::vector<double>(3*M[0].size(), 0));
    
    for (int i=0; i<hM.size(); i++) {
    	for (int j=0; j<hM[i].size(); j++) {
    		int opposite_col_idx = hM[i].size() - j - 1;
    		hM[i][j] = M[i][opposite_col_idx];
    	}
    }
    
    for (int i=0; i<vM.size(); i++) {
    	int opposite_row_idx = vM.size() - i - 1;
    	for (int j=0; j<vM[i].size(); j++) {
    		vM[i][j] = M[opposite_row_idx][j];
    	}
    }
    
    for (int i=0; i<hvM.size(); i++) {
    	int opposite_row_idx = hvM.size() - i - 1;
    	for (int j=0; j<hvM[i].size(); j++) {
    		int opposite_col_idx = hvM[i].size() - j - 1;
    		hvM[i][j] = M[opposite_row_idx][opposite_col_idx];
    	}
    	}
    	
    	int broj_redova = M.size();
    	for (int i=0; i<broj_redova; i++) {
    		for (int j=0; j<M[i].size(); j++) {
    			rezultat[i][j] = hvM[i][j];
    			rezultat[i][j+broj_redova+1] = vM[i][j];
    			rezultat[i][j+2*(broj_redova+1)] = hvM[i][j];
    		}
    	}
    	
    	for (int i=0; i<broj_redova; i++) {
    		for (int j=0; j<M[i].size(); j++) {
    			rezultat[i+M.size()][j] = hM[i][j];
    			rezultat[i+M.size()][j+broj_redova+1] = M[i][j];
    			rezultat[i+M.size()][j+2*(broj_redova+1)] = hM[i][j];
    		}
    	}
    	
    	for (int i=0; i <broj_redova; i++) {
    		for (int j=0; j<M[i].size(); j++){
    			rezultat[i+2*broj_redova][j] = hvM[i][j];
    			rezultat[i+2*broj_redova][j+broj_redova+1] = vM[i][j];
    			rezultat[i+2*broj_redova][j+2*(broj_redova+1)] = hvM[i][j];
    		}
    	}
    	PrintajMatricu(rezultat);
    	return rezultat;
}
int main ()
{ 
	//std::vector<int> brojevi2 { 1, 3, 2, 6, 7, 9, 10, 4, 3, 1, 7 };
	std::vector<std::vector<double> > ulaz( 2, std::vector<double>(3,0) );
	ulaz[0][0] = 1; ulaz[0][1] = 2; ulaz[0][2] = 3;
	ulaz[1][0] = 4; ulaz[1][1] = 5; ulaz[1][2] = 6;
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if ( m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	int broj;
	std::vector<std::vector<double> > ulaz2( m, std::vector<double>(n, 0) );
	std::cout << "Unesite elemente matrice:";
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			std::cin >> broj;
			ulaz2[i][j] = broj;
		}
	}
	if (m==0 || n==0) {
		std::cout << std::endl << "Rezultantna matrica:" << std::endl;
		return 0;
	}
	
	std::vector<std::vector<double> > rezultat;
	std::cout << std::endl << "Rezultantna matrica:" << std::endl;
	rezultat = OgledaloMatrica(ulaz2);
	
	return 0;
}

