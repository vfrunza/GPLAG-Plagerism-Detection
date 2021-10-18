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

typedef std::vector<std::vector<double>> Matrica;

bool DaLiJeGrbava (Matrica m) {
	for (int i=0; i<m.size(); i++) 
		if (m[i].size()!=m[0].size())
		    return true;
    return false;
}

Matrica HorizontalnoOgledalo (Matrica m) {
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++) {
			double tmp(0);
			if (j<(m[i].size())/2) {
				tmp=m[i][j];
				m[i][j]=m[i][m[i].size()-1-j];
				m[i][m[i].size()-1-j]=tmp;
			}
		}
	}
	return m;
}

Matrica VertikalnoOgledalo (Matrica m) {
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++) {
			double tmp(0);
			if (i<(m.size())/2) {
				tmp=m[i][j];
				m[i][j]=m[m.size()-1-i][j];
				m[m.size()-1-i][j]=tmp;
			}
		}
	}
	return m;
}

Matrica OgledaloMatrica (Matrica m) {
	if (DaLiJeGrbava(m)) throw std::domain_error("Matrica nije korektna");
	Matrica hm=HorizontalnoOgledalo(m);
	Matrica vm=VertikalnoOgledalo(m);
	Matrica hvm=HorizontalnoOgledalo(m);
	hvm=VertikalnoOgledalo(hvm);
	Matrica M;
	if (m.size()==0) return M;
	int p=3*m.size();
	int q=3*m[0].size();
	M.resize(p);
	for (int i=0; i<p; i++)
	    M[i].resize(q);
	for (int i=0; i<p; i++) {
		for (int j=0; j<q; j++) {
            if (i<p/3 && j<q/3)
                M[i][j]=hvm[i][j];
            else if (i<p/3 && j>=q/3 && j<2*q/3)
                M[i][j]=vm[i][j-q/3];
            else if (i<p/3 && j>=2*q/3)
                M[i][j]=hvm[i][j-2*q/3];
            else if (i>=p/3 && i<2*p/3 && j<q/3)
                M[i][j]=hm[i-p/3][j];
            else if (i>=2*p/3 && j<q/3)
                M[i][j]=hvm[i-2*p/3][j];
            else if (i>=p/3 && i<2*p/3 && j>=q/3 && j<2*q/3)
                M[i][j]=m[i-p/3][j-q/3];
            else if (i>=p/3 && i<2*p/3 && j>=2*q/3)
                M[i][j]=hm[i-p/3][j-2*q/3];
            else if (i>=2*p/3 && j>=q/3 && j<2*q/3)
                M[i][j]=vm[i-2*p/3][j-q/3];
            else if (i>=2*p/3 && j>=2*q/3)
                M[i][j]=hvm[i-2*p/3][j-2*q/3];
		}
	}
	return M;
}

int main ()
{
	try {
		int m,n;
		std::cout << "Unesite dimenzije matrice (m n): ";
		std::cin >> m >> n;
		if (m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		Matrica mat(m, std::vector<double> (n));
		std::cout << "Unesite elemente matrice: " << std::endl;
		for (int i=0; i<m; i++) 
		    for (int j=0; j<n; j++)
		        std::cin >> mat[i][j];
		Matrica MAT=OgledaloMatrica(mat);
		std::cout << "Rezultantna matrica: " << std::endl;
		for (int i=0; i<MAT.size(); i++) {
			for (int j=0; j<MAT[i].size(); j++) {
				std::cout << std::setw(4) << MAT[i][j];
			}
			std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	} 
	return 0;
}