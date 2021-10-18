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

typedef std::vector<std::vector<double>> Matrica;
Matrica Vertikalno_Ogledalo(std::vector<std::vector<double>> v) {
	int vel=v.size();
	for(int i(0); i<vel/2; i++) {
		for(int j(0); j<v[i].size(); j++) {
			double pomocna;
			pomocna=v[i][j];
			v[i][j]=v[vel-i-1][j];
			v[vel-i-1][j]=pomocna;
		}
	}
	return v;
}

typedef std::vector<std::vector<double>> Matrica;
Matrica Horiznotalno_Ogledalo(std::vector<std::vector<double>> h) {
	int vel=h.size();
	for(int i(0); i<vel; i++) {
		for(int j(0); j<h[i].size(); j++) {
			double pomocna=h[i][j];
			h[i][j]=h[i][h[i].size()-j-1];
			h[i][h[i].size()-j-1]=pomocna;
		}
	}
	return h;
}

typedef std::vector<std::vector<double>> Matrica;
Matrica Kombinovano_Ogledalo(std::vector<std::vector<double>> hv) {
	hv=Vertikalno_Ogledalo(v);
	hv=Horiznotalno_Ogledalo(v);
	
	return hv;
}


typedef std::vector<std::vector<double>> Matrica;
Matrica OgledaloMatrica(std::vector<std::vector<double>> mat) {
	int m=mat.size(); 
	int n=mat[0].size();
	for(int i(0); i<3*m; i++) {
		for(int j(0); j<3*n; j++) {
			
		}
	}
}

typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int br_redova, int br_kolona) {
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

typedef std::vector<std::vector<double>> Matrica;
Matrica UnesiMatricu(int br_redova, int br_kolona) {
	auto m(KreirajMatricu(br_redova, br_kolona));
	for(int i(0); i<br_redova; i++) {
		for(int j(0); j<br_kolona; j++) {
			std::cin >> m[i][j];
		}
	}
}

int main ()
{
	int n, m;
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> n >> m;
	if(n<0 || m<0) 
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	
	std::cout << "Unesite elemente matrice: ";
	auto Mat(UnesiMatricu(n, m));
	std::cout << std::endl;
	
	std::cout << "Rezultantna matrica: " << std::endl;
	auto m1(OgledaloMatrica(Mat));
	std::cout << m1 << std::endl;
	
	return 0;
}