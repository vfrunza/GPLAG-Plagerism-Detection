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
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica HorizontalnoOgledalo (Matrica mat, int x, int y) { 
	int a(x), b(y);																		//  Pomocna funkcija koja pravi
	Matrica v(a, std::vector<double>(b));												//  horizontalno ogledalo
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			v[i][j] = mat[i][b-(1+j)];
		}
	}
	return v;
}

Matrica VertikalnoOgledalo (Matrica mat, int x, int y) {								//  Pomocna funkcija koja pravi
	int a(x), b(y);																		//  vertikalno ogledalo
	Matrica v(a, std::vector<double>(b));																			
	for (int i=0; i<a; i++) {
		v[i] = mat[a-(1+i)];
	}
	return v;
}

Matrica KombinovanoOgledalo (Matrica mat,int x, int y) {								//  Pomocna funkcija koja pravi
	Matrica v (HorizontalnoOgledalo(mat,x,y));											//  kombinovano ogledalo
	v = VertikalnoOgledalo(v,x,y);
	return v;
}

Matrica OgledaloMatrica (Matrica mat) {
	int a, b, c, d;
	if (mat.size()>0 && mat[0].size()>0) {
		a = mat.size()*3;
		b = mat[0].size()*3;
		c = mat.size();
		d = mat[0].size();
	}
	else {
		a = mat.size()*3;
		b = 0;
		c = mat.size();
		d = 0;
	}
	for (int i=0; i<c; i++) {
		for (int j=i; j<c; j++) {
			if (mat[i].size()!=mat[j].size()) {
				throw std::domain_error ("Matrica nije korektna");
			}
		}
	}
	Matrica v(a, std::vector<double>(b)), v1(HorizontalnoOgledalo(mat,c,d));
	Matrica v2(VertikalnoOgledalo(mat,c,d)), v3(KombinovanoOgledalo(mat,c,d));
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			if (i<c) {
				if (j<d) {
					v[i][j] = v3[i][j];
				}
				if (j>=d && j<d*2) {
					v[i][j] = v2[i][j-d];
				}
				if (j>=d*2) {
					v[i][j] = v3[i][j-d*2];
				}
			}
			if (i>=c && i<c*2) {
				if (j<d) {
					v[i][j] = v1[i-c][j];
				}
				if (j>=d && j<d*2) {
					v[i][j] = mat[i-c][j-d];
				}
				if (j>=d*2) {
					v[i][j] = v1[i-c][j-d*2];
				}
			}
			if (i>=c*2) {
				if (j<d) {
					v[i][j] = v3[i-c*2][j];
				}
				if (j>=d && j<d*2) {
					v[i][j] = v2[i-c*2][j-d];
				}
				if (j>=d*2) {
					v[i][j] = v3[i-c*2][j-d*2];
				}
			}
 		}
	}
	return v;
}

int main () {
	try {
		int m, n;
		std::cout << "Unesite dimenzije matrice (m n): ";
		std::cin >> m >> n;
		if (m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cin.ignore(10000,'\n');
		Matrica v(m, std::vector<double>(n));
		std::cout << "Unesite elemente matrice: ";
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				std::cin >> v[i][j];
			} 
		}
		Matrica matrica(OgledaloMatrica(v));
		std::cout << std::endl << "Rezultantna matrica: " << std::endl;
		for (int i=0; i<m*3; i++) {
			for (int j=0; j<n*3; j++) {
				std::cout << std::setw(4) << matrica[i][j];
			}
			std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}