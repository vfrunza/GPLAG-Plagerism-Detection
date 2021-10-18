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
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica vertikalno(Matrica matrica)
{
	double pomocni;
	for (int i=0; i<matrica.size()/2; i++) {
		for (int j=0; j<matrica[0].size(); j++) {
			pomocni=matrica[i][j];
			matrica[i][j]=matrica[matrica.size()-1-i][j];
			matrica[matrica.size()-1-i][j]=pomocni;
		}
	}
	return matrica;
}

Matrica horizontalno(Matrica matrica)
{
	double pomocni;
	for (int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size()/2; j++) {
			pomocni=matrica[i][j];
			matrica[i][j]=matrica[i][matrica[0].size()-1-j];
			matrica[i][matrica[0].size()-1-j]=pomocni;
		}
	}
	return matrica;
}

Matrica OgledaloMatrica (Matrica matrica)
{
	Matrica povratna;
	if (matrica.size()==0 || matrica[0].size()==0) {
		povratna.resize(3*matrica.size());
		return povratna;
	}
	povratna.resize(3*matrica.size());
	for (int i=0; i<3*matrica.size(); i++) povratna[i].resize(3*matrica[0].size());
	bool grbava(true);
	for (int i=0; i<matrica.size(); i++) {
		for (int j=i; j<matrica.size(); j++) {
			if (matrica[i].size()!=matrica[j].size()) {
				grbava=false;
				throw std::domain_error("Matrica nije korektna.");
			}
		}
	}
	Matrica v(vertikalno(matrica));
	Matrica hv(horizontalno(vertikalno(matrica)));
	Matrica h(horizontalno(matrica));
	int a(povratna.size());
	int b(povratna[0].size());
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			if (i<a/3 && j<b/3) povratna[i][j]=hv[i][j];
			if (i<a/3 && j>=b/3 && j<2*b/3) povratna[i][j]=v[i][j-b/3];
			if (i<a/3 && j>=2*b/3) povratna[i][j]=hv[i][j-2*b/3];
			if (i>=a/3 && i<2*a/3 && j<b/3) povratna[i][j]=h[i-a/3][j];
			if (i>=a/3 && i<2*a/3 && j>=b/3 && j<2*b/3) povratna[i][j]=matrica[i-a/3][j-b/3];
			if (i>=a/3 && i<2*a/3 && j>=2*b/3) povratna[i][j]=h[i-a/3][j-2*b/3];
			if (i>=2*a/3 && j<b/3) povratna[i][j]=hv[i-2*a/3][j];
			if (i>=2*a/3 && j>=b/3 && j<2*b/3) povratna[i][j]=v[i-2*a/3][j-b/3];
			if (i>=2*a/3 && j>=2*b/3) povratna[i][j]=hv[i-2*a/3][j-2*b/3];
		}
	}
	return povratna;
}


int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin >> m >> n;
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica matrica;
	matrica.resize(m);
	for (int i=0; i<m; i++) matrica[i].resize(n);
	std::cout << "Unesite elemente matrice:" << std::endl;
	double x;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			std::cin >> x;
			matrica[i][j]=x;
		}
	}
	std::cout << "Rezultantna matrica: " << std::endl;
	try {
		matrica=OgledaloMatrica(matrica);
		for (int i=0; i<matrica.size(); i++) {
			for (int j=0; j<matrica[0].size(); j++) {
				std::cout << std::right << std::setw(4) << matrica[i][j];
			}
			std::cout << std::endl;
		}
	} catch(std::domain_error tekst) {
		std::cout << tekst.what() << std::endl;
	}
	return 0;
}