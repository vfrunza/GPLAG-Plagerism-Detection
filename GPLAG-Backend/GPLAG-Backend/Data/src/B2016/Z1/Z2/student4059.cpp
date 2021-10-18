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

typedef std::vector<std::vector<double> > Matrica;

using namespace std;

Matrica v(Matrica matrica) {
	for(int i = 0; i < matrica.size()/2; i++) {
		std::vector<double> temp = std::move(matrica[i]);
		matrica[i] = std::move(matrica[matrica.size()-1 - i]);
		matrica[matrica.size()-1 - i] = std::move(temp);
	}
	return matrica;
}

Matrica h(Matrica matrica) {
	for(int i = 0; i < matrica.size(); i++) {
		for(int j = 0; j < matrica[i].size()/2; j++) {
			double temp = matrica[i][j];
			matrica[i][j] = matrica[i][matrica[i].size()-1 - j];
			matrica[i][matrica[i].size()-1 - j] = temp;
		}
	}
	return matrica;
}

Matrica hv(Matrica matrica) {
	matrica = h(matrica);
	matrica = v(matrica);
	return matrica;
}

Matrica OgledaloMatrica (Matrica matrica) {
	
	if(matrica.size() == 0)
		return matrica;
		
	for(int i = 1; i < matrica.size(); i++) {
		if(matrica[0].size() != matrica[i].size())
			throw std::domain_error("Matrica nije korektna");
	}
	
	Matrica hmatrica = h(matrica);
	Matrica vmatrica = v(matrica);
	Matrica hvmatrica = hv(matrica);
	
	int m = matrica.size();
	int n = matrica[0].size();
	Matrica ogledalo;
	
	ogledalo.resize(3*m);
	for(int i = 0; i < 3*m; i++)
		ogledalo[i].resize(3*n);
		
	for(int i = 0; i < ogledalo.size(); i++) {
		for(int j = 0; j < ogledalo[i].size(); j++) {
			if(i < m) {
				if(j < n) {
					ogledalo[i][j] = hvmatrica[i][j];
				}
				else if(j < 2*n) {
					ogledalo[i][j] = vmatrica[i][j - n];
				}
				else {
					ogledalo[i][j] = hvmatrica[i][j - 2*n];
				}
			}
			else if(i < 2*m) {
				if(j < n) {
					ogledalo[i][j] = hmatrica[i - m][j];
				}
				else if(j < 2*n) {
					ogledalo[i][j] = matrica[i - m][j - n];
				}
				else {
					ogledalo[i][j] = hmatrica[i - m][j - 2*n];
				}
			}
			else {
				if(j < n) {
					ogledalo[i][j] = hvmatrica[i - 2*m][j];
				}
				else if(j < 2*n) {
					ogledalo[i][j] = vmatrica[i - 2*m][j - n];
				}
				else {
					ogledalo[i][j] = hvmatrica[i - 2*m][j - 2*n];
				}
			}
		}
	}
	
	return ogledalo;
}

int main () {
	int m,n;
	Matrica matrica;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m;
	std::cin >> n;
	if(m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrica.resize(m);
	for(int i = 0; i < matrica.size(); i++) {
		matrica[i].resize(n);
	}
	std::cout << "Unesite elemente matrice:";
	for(int i = 0; i < m; i++) 
		for(int j = 0; j < n; j++)
			cin >> matrica[i][j];
			cout << endl;
	std::cout << "Rezultantna matrica: ";
	cout << endl;
	Matrica ogledalo;
	ogledalo = OgledaloMatrica(matrica);
	for(int i = 0; i < ogledalo.size(); i++) {
		for( int j = 0; j < ogledalo[i].size(); j++) {
			cout << std::setw(4);
			cout << ogledalo[i][j];
		}
		cout << endl;
	}
	return 0;
}