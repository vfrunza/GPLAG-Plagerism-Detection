#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

typedef std::vector<std::vector<double>> Matrica;

void IspisiMatricu(const Matrica m)
{
	for(int i=0; i< m.size(); i++) {
		for(int j=0; j<m[i].size(); j++)
			std::cout << std::setw(4) << m[i][j];
		std::cout << std::endl;
	}
}

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

bool JeLiGrbava(const Matrica m)
{
	bool Jeste(false);
	int duzina = m[0].size();
	for(int i=0; i< m.size(); i++) {
		if(m[i].size() != duzina) {
			Jeste = true;
			break;
		}

	}
	return Jeste;
}

Matrica OgledaloMatrica(const Matrica m)
{
	if(m.size()==0) return Matrica();
	if(JeLiGrbava(m)) throw std::domain_error("Matrica nije korektna");
	Matrica nova(KreirajMatricu(3*m.size(), 3*m[0].size()));

	int duzina = m[0].size();
	int visina = m.size();
	int k(0),l(0);

	// popunjava elemente sve

	for(int i=0; i < nova.size(); i++) {
		for(int j=0; j < nova[i].size(); j++) {
			nova[i][j] = m[k][l];
			l++;
			if(l == duzina) l=0;
		}
		k++;
		if(k == visina) k=0;
	}

	int mVisina = nova.size();
	int mSirina = nova[0].size();
	int trecinaV;
	int trecinaH;

	if(mVisina>=3) trecinaV = mVisina / 3;
	else trecinaV = mVisina;
	if(mSirina>=3) trecinaH = mSirina / 3;
	else trecinaH = mSirina;

	int h(0);

	// obrcemo potrebne vertiklane redove m.size()/3

	for(int i=0; i < mVisina; i++) {
		if(mVisina==1) break;
		for(int j=0; j < mSirina; j++) {
			if(i < (trecinaV+1)/2 && i<trecinaV-1) {				// po vertikali prve
				double swap = nova[i][j];
				nova[i][j] = nova[trecinaV-1-i][j];
				nova[trecinaV-1-i][j] = swap;
			}
			if(i>= mVisina-trecinaV && i<mVisina -(trecinaV+1)/2) {		// po vertikali zadnje

				if(i==mVisina-1) break;
				double swap = nova[i][j];
				nova[i][j] = nova[mVisina-1-h][j];
				nova[mVisina-1-h][j] = swap;
			}
		}
		if(i>= mVisina-trecinaV) h++;
	}

	// obrcemo potrebne horizontalne kolone m[i].size()/3

	int z=0;
	for(int i=0; i < mVisina; i++) {
		for(int j=0; j < mSirina; j++) {

			if(j<(trecinaH+1)/2 && j<trecinaH-1) {	// po horizontali prve

				double swap = nova[i][j];
				nova[i][j] = nova[i][trecinaH-1-j];
				nova[i][trecinaH-1-j] = swap;
			}
			if(j >= mSirina-trecinaH && j<mSirina -(trecinaH+1)/2) {		// po horizontali zadnje

				if(j==(mSirina-trecinaH/2)) break;
				if(j==mSirina-1) break;
				double swap = nova[i][j];
				nova[i][j] = nova[i][mSirina-1-z];
				nova[i][mSirina-1-z] = swap;
			}

			if(j >= mSirina-trecinaH) z++;
		}
		z=0;
	}

	return nova;
}


int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}

	try {
		Matrica matrix(KreirajMatricu(m,n));

		double element;
		std::cout << "Unesite elemente matrice: " << std::endl;
		for(int i=0; i<matrix.size(); i++) {
			for(int j=0; j<matrix[i].size(); j++) {
				std::cin >> element;
				matrix[i][j] = element;
			}
		}

		std::cout << "Rezultantna matrica:" << std::endl;
		IspisiMatricu(OgledaloMatrica(matrix));
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}