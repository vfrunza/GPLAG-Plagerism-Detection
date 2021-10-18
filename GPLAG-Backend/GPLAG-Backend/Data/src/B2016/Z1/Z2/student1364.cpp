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
#include <stdexcept> //u njoj su definirani standardni izuzeci

using std::cin; using std::cout; using std::endl; using std::vector;
typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu (int br_redova, int br_kolona) {
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica HorizontlnoOgledalo (Matrica m) {
	Matrica pomocna;
	int br_redova(m.size()), br_kolona(m[0].size());
	
	pomocna=KreirajMatricu(br_redova, br_kolona); //m nije grbava?
	for (int i=0; i<br_redova; i++) {
		for (int j=0; j<br_kolona; j++) {
			pomocna[i][j]=m[i][br_kolona-j-1];
		}
	}
	return pomocna;
}

Matrica VertikalnoOgledalo (Matrica m) {
	Matrica pomocna;
	int br_redova(m.size()), br_kolona(m[0].size());
	
	pomocna=KreirajMatricu(br_redova, br_kolona); //m nije grbava?
	for (int i=0; i<br_redova; i++) {
		for (int j=0; j<br_kolona; j++) {
			pomocna[i][j]=m[br_redova-i-1][j];
		}
	}
	return pomocna;
}

Matrica KombinovanoOgledalo (Matrica m) {
	Matrica pomocna;
	int br_redova(m.size()), br_kolona(m[0].size());
	
	pomocna=KreirajMatricu(br_redova, br_kolona); //m nije grbava?
	for (int i=0; i<br_redova; i++) {
		for (int j=0; j<br_kolona; j++) {
			pomocna[i][j]=m[br_redova-i-1][br_kolona-j-1];
		}
	}
	return pomocna;
}

Matrica OgledaloMatrica (Matrica m) {
	Matrica pomocna, math, matv, mathv;
	//Provjerimo da li je matrica ispravnog formata
	for (int i=1; i<m.size(); i++) {
		if (m[i].size() != m[0].size()) throw std::domain_error ("Matrica nije korektna");
	}
	//Ako je m formata 0x0 vracamo matricu formata 0x0
	if (m.size()==0) return KreirajMatricu(0,0);
	int br_redova(m.size()), br_kolona(m[0].size());
	
	pomocna=KreirajMatricu(3*br_redova, 3*br_kolona);
	math=HorizontlnoOgledalo(m);
	matv=VertikalnoOgledalo(m);
	mathv=KombinovanoOgledalo(m);
	
	for (int i=0; i<pomocna.size(); i++) {
		for (int j=0; j<pomocna[0].size(); j++) {
			//Popunimo matricu sa kombinovanim ogledalima
			if (i<br_redova && j<br_kolona) {
				pomocna[i][j]=mathv[i][j];
				continue;
			}
			if (i>(2*br_redova-1) && j<br_kolona) {
				pomocna[i][j]=mathv[i-2*br_redova][j];
				continue;
			}
			if (i<br_redova && j>(2*br_kolona-1)) {
				pomocna[i][j]=mathv[i][j-2*br_kolona];
				continue;
			}
			if (i>(2*br_redova-1) && j>(2*br_kolona-1)) {
				pomocna[i][j]=mathv[i-2*br_redova][j-2*br_kolona];
				continue;
			}
			//Popunimo sada vertikalna ogledala
			if (i<br_redova && j<(2*br_kolona) && j>(br_kolona-1)) {
				pomocna[i][j]=matv[i][j-br_kolona];
				continue;
			}
			if (i>(2*br_redova-1) && j<(2*br_kolona) && j>(br_kolona-1)) {
				pomocna[i][j]=matv[i-2*br_redova][j-br_kolona];
				continue;
			}
			//Popunimo sada horizontalna ogledala
			if (i>(br_redova-1) && i<(2*br_redova) && j<br_kolona) {
				pomocna[i][j]=math[i-br_redova][j];
				continue;
			}
			if (i>(br_redova-1) && i<(2*br_redova) && j>=2*br_kolona) {
				pomocna[i][j]=math[i-br_redova][j-2*br_kolona];
				continue;
			}
			//Popunimo sada sa pocetnom matricom
			else {
				pomocna[i][j]= m[i-br_redova][j-br_kolona];
			}
		}
	}
	return pomocna;
}

int main ()
{
	int m, n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	if (m<0 || n<0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat, mat1, mat2, mat3, mat4;
	mat=KreirajMatricu(m, n);
	cout << "Unesite elemente matrice: ";
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}
	cout << endl;
	
/*	mat1=HorizontlnoOgledalo(mat);
	cout << "Horizontalno ogledalo matrice je: " << endl;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cout << mat1[i][j] << " ";
		}
		cout << endl;
	}
	mat2=VertikalnoOgledalo(mat);
	cout << "Vertikalno ogledalo matrice je: " << endl;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cout << mat2[i][j] << " ";
		}
		cout << endl;
	}
	
	mat3=KombinovanoOgledalo(mat);
	cout << "Kombinovano ogledalo matrice je: " << endl;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cout << mat3[i][j] << " ";
		}
		cout << endl;
	}*/
	
	try {
		mat4=OgledaloMatrica(mat);
	}
	catch (std::domain_error izuzetak) {
      cout << izuzetak.what() << endl;
   }
	cout << "Rezultantna matrica: " << endl;
	for (int i=0; i<mat4.size(); i++) {
		for (int j=0; j<mat4[0].size(); j++) {
			cout <<std::setw(4) << mat4[i][j];
		}
		cout << endl;
	}
	
	return 0;
}