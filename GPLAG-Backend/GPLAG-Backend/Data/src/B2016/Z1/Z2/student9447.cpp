/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

int BrojRedova(Matrica m) {
	return m.size();
}

int BrojKolona(Matrica m) {
	return m[0].size();
}

Matrica horizontalnoOgledalo(std::vector<std::vector<double>> mat) {
	Matrica m;
	m.resize(BrojRedova(mat));
	
	for(int i = 0; i < BrojRedova(m); i++)
	   m[i].resize(BrojKolona(mat));
	
	for(int i = 0; i < BrojRedova(m); i++) {
		for(int j = 0; j < BrojKolona(m) ; j++) {
			m[i][j] = mat[i][BrojKolona(m) - 1 - j];
		}
	} 
	return m;
	   
}

Matrica vertikalnoOgledalo(Matrica mat) {
	Matrica m;
	m.resize(BrojRedova(mat));
	
	for(int i = 0; i < BrojRedova(m); i++)
	  m[i].resize(BrojKolona(mat));
	  
	for(int i = 0; i < BrojRedova(m) ; i++) {
		for(int j = 0; j < BrojKolona(m); j++) {
			m[i][j] = mat[BrojRedova(m) - 1 - i][j];
		}
	}
	return m;
}

Matrica kombinovanoOgledalo(Matrica mat) {
	
	Matrica m;
	m = horizontalnoOgledalo(mat);
	m = vertikalnoOgledalo(m);
	
	return m;
}

bool daLiJeGrbava(Matrica mat) {
	for(int i = 1; i < BrojRedova(mat); i++)
	  if(mat[i].size() != BrojKolona(mat)) return true;
	  
	return false;
}

Matrica OgledaloMatrica(Matrica mat) {
	if(daLiJeGrbava(mat)) throw std::domain_error("Matrica nije korektna");
	Matrica rezMat;
	Matrica mat3 = horizontalnoOgledalo(mat);
	Matrica mat2 = vertikalnoOgledalo(mat);
	Matrica mat1 = kombinovanoOgledalo(mat);
	rezMat.resize(3 * BrojRedova(mat));
	
	for(int i = 0; i < BrojRedova(rezMat); i++)
	   rezMat[i].resize(3 * BrojKolona(mat));
	
	int m(0), n, poc1, poc2;                                     // gornja lijeva
	for(int i = 0; i < BrojRedova(mat); i++) { 
		n = 0;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat1[i][j];
			n++;
		}
		m++;
	}
	poc1 = n;
	m = 0;                                              // gornja srednja
	for(int i = 0; i < BrojRedova(mat); i++) {                 
		n = poc1;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat2[i][j];
			n++;
		}
		m++;
	}
	poc1 = n;
	m = 0;                                              // gornja desna
	for(int i = 0; i < BrojRedova(mat); i++) {
		n = poc1;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat1[i][j];
			n++;
		}
		m++;
	}
	// m = 2, n = 9;
	poc2 = m;                                            // srednja lijeva
	for(int i = 0; i < BrojRedova(mat); i++) {
		n = 0;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat3[i][j];
			n++;
		}
		m++;
	}
	poc1 = n;
	m = poc2;                                               // srednja
	for(int i = 0; i < BrojRedova(mat); i++) {
		n = poc1;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat[i][j];
			n++;
		}
		m++;
	}
	poc1 = n;
	m = poc2;                                              // srednja desna
	for(int i = 0; i < BrojRedova(mat); i++) {
		n = poc1;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat3[i][j];
			n++;
		}
		m++;
	}
	poc2 = m;                                            // donja lijeva
	for(int i = 0; i < BrojRedova(mat); i++) {
		n = 0;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat1[i][j];
			n++;
		}
		m++;
	}
	poc1 = n;
	m = poc2;                                             // donja srednja
	for(int i = 0; i < BrojRedova(mat); i++) {
		n = poc1;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat2[i][j];
			n++;
		}
		m++;
	}
	poc1 = n;
	m = poc2;                                           // donja desna
	for(int i = 0; i < BrojRedova(mat); i++) {
		n = poc1;
		for(int j = 0; j < BrojKolona(mat); j++) {
			rezMat[m][n] = mat1[i][j];
			n++;
		}
		m++;
	}
	
   return rezMat;	   
}

int main ()
{
	try {
		std::cout << "Unesite dimenzije matrice (m n): ";
		int m, n;
		std::cin >> m >> n;
		if (m < 0 || n < 0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
			return 0;
		}
		std::cout << "Unesite elemente matrice: ";
		Matrica mat, rezultantnaMatrica;
		mat.resize(m);
		
		for(int i = 0; i < BrojRedova(mat); i++)
		   mat[i].resize(n);
		   
		for(int i = 0; i < BrojRedova(mat); i++)
		   for(int j = 0; j < BrojKolona(mat); j++)
		      std::cin >> mat[i][j];
		
		rezultantnaMatrica.resize(3 * BrojRedova(mat));
		for(int i = 0; i < BrojRedova(rezultantnaMatrica); i++) rezultantnaMatrica[i].resize(BrojKolona(mat));
		      
		rezultantnaMatrica = OgledaloMatrica(mat);
		
		std::cout << std::endl << "Rezultantna matrica: " << std::endl;
		
		for(int i = 0; i < BrojRedova(rezultantnaMatrica); i++){
		   for(int j = 0; j < BrojKolona(rezultantnaMatrica); j++) {
		      std::cout << std::setw(4) << rezultantnaMatrica[i][j];
		   }
		   std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	
	return 0;
}