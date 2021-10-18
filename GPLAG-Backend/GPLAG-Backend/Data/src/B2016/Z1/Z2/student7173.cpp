/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;
using std::vector;

typedef vector<vector<double>> Matrica;

void printMatrica (Matrica mat) {
	for (vector<double> vec : mat) {
		for (double d : vec) {
			cout.width(4);
			cout << d;
		}
		
		cout << std::endl;
	}
}

Matrica KreirajMatricu(int broj_redova, int broj_kolona) {
	return Matrica(broj_redova, vector<double>(broj_kolona));
}

Matrica OgledaloMatrica (Matrica mat) {
	
	int len1(mat.size()), len2(0);
	if (len1 > 0) len2 = mat[0].size();
	for (vector<double> v : mat) {
		if (v.size() != len2) throw std::domain_error("Matrica nije korektna");
	}
	
	Matrica nova(KreirajMatricu(3 * len1, 3 * len2));
	
	// M u sredinu i h(M) sa strana
	for (int i(0); i < len1; i++) {
		for (int j(0); j < len2; j++) {
			double broj(mat[i][j]);
			nova[len1 + i][len2 + j] = broj;
			nova[len1 + i][len2 - 1 - j] = broj;
			nova[len1 + i][3*len2 - 1 - j] = broj;
		}
	}
	
	// Koristimo M i h(M) u novoj matrici da dobijemo v(M) i hv(M) = v(h(M))
	for (int i(0); i < len1; i++) {
		for (int j(0); j < 3*len2; j++) {
			nova[len1 - 1 - i][j] = nova[len1 + i][j];
			nova[3*len1 - 1 - i][j] = nova[len1 + i][j];
		}
	}
	
	return nova;
}


int main () {
	// Matrica v{{1.0, 2.7, 3.8}, {4.0, 5.9/*, 6*/}};
	
	Matrica elems;
	int m(0), n(0);
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	
	if (m < 0 || n < 0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	elems = KreirajMatricu(m, n);
	cout << "Unesite elemente matrice:\n";
	for (int i(0); i < m; i++) {
		for (int j(0); j < n; j++) {
			cin >> elems[i][j];
		}
	}
	try {
		cout << "Rezultantna matrica:\n";
		printMatrica(OgledaloMatrica(elems));
	}
	catch (std::domain_error except) {
		cout << except.what() << std::endl;
	}

	return 0;
}




