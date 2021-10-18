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

using namespace std;

typedef vector<vector<double>> Matrica;

//Obrtanje matrica oko osa
Matrica hflip (Matrica mat) {
	int m(mat.size());
	int n(mat[0].size());
	
	Matrica h(m, vector<double>(n));
	
	for (int  i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			h[i][j] = mat[i][n - 1 - j];
		}
	}
	
	return h;
}

Matrica vflip (Matrica mat) {
	int m(mat.size());
	int n(mat[0].size());

	Matrica v(m, vector<double>(n));

	for (int  i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j] = mat[m - i - 1][j];
		}
	}

	return v;
}

Matrica hvflip(Matrica mat) {
	Matrica hv(vflip(mat));
	hv = hflip(hv);
	
	return hv;
}

//Pravljenje velike matrice i ubacivanje manjih u specificirana mjesta
Matrica OgledaloMatrica (Matrica mat) {
	if (mat.size() == 0) return mat;
	
	int m(mat.size() * 3);
	int n(mat[0].size() * 3);
	
	Matrica h(hflip(mat));
	Matrica v(vflip(mat));
	Matrica hv(hvflip(mat));
	
	Matrica ogledalo (m, vector<double>(n));
	
	//Postavljanje manjih matrica u vecu matricu
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j ++) {
			//Upis matrica obrnute po horizontali i vertikali
			ogledalo[i][j] = hv[i][j];
			ogledalo[i + 2 * mat.size()][j] = hv[i][j];
			ogledalo[i][j + 2 * mat[i].size()] = hv[i][j];
			ogledalo[i + 2 * mat.size()][j + 2 * mat[i].size()] = hv[i][j];
			//Upis matrica obrnutih samo po vertikali
			ogledalo[i][j + mat[i].size()] = v[i][j];
			ogledalo[i + 2 * mat.size()][j + mat[i].size()] = v[i][j];
			//Upis matrica obrnutih samo po horizontali
			ogledalo[i + mat.size()][j] = h[i][j];
			ogledalo[i + mat.size()][j + 2 * mat[i].size()] = h[i][j];
			//Upis obicne matrice u sredinu
			ogledalo[i + mat.size()][j + mat[i].size()] = mat[i][j];
		}
	}
	
	return ogledalo;
	
}

int main ()
{
	int m, n;
	try {
		cout << "Unesite dimenzije matrice (m n): ";
		cin >> m >> n;
		if (m < 0 || n < 0) throw domain_error("Dimenzije matrice moraju biti nenegativne!");
		
		
		Matrica mat(m, vector<double>(n));
		cout << "Unesite elemente matrice:" << endl;
		for (int  i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}
		
		Matrica ogledalo(OgledaloMatrica(mat));
		
		int mo(ogledalo.size());
		int no(ogledalo[0].size());
		
		cout << "Rezultantna matrica:" << endl;
		for (int i = 0; i < mo; i++) {
			for (int j = 0; j < no; j++) {
				cout << setw(4) << ogledalo[i][j];
			}
			cout << endl;
		}
		
		return 0;
	}
	catch (domain_error izuzetak) {
		cout << izuzetak.what();
		return 0;
	}
}