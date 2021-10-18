/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica m) {
	
	if(m.size()) {
		for(std::vector<double>v : m) if(v.size()!=m[0].size()) throw std::domain_error("Matrica nije korektna");
	}
	else return Matrica (3*m.size(), std::vector<double>(0));
	
	Matrica ogledalo(3*m.size(), std::vector<double>(3*m[0].size()));
	
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i][j]=m[m.size()-1-i][m[0].size()-1-j];
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i][j+m[0].size()]=m[m.size()-1-i][j];
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i][j+2*m[0].size()]=m[m.size()-1-i][m[0].size()-1-j];
	
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i+m.size()][j]=m[i][m[0].size()-1-j];
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i+m.size()][j+m[0].size()]=m[i][j];
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i+m.size()][j+2*m[0].size()]=m[i][m[0].size()-1-j];
	
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i+2*m.size()][j]=m[m.size()-1-i][m[0].size()-1-j];
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i+2*m.size()][j+m[0].size()]=m[m.size()-1-i][j];
	for(int i=0; i<m.size(); i++) for(int j=0; j<m[0].size(); j++) ogledalo[i+2*m.size()][j+2*m[0].size()]=m[m.size()-1-i][m[0].size()-1-j];
	
	return ogledalo;
}

int main () {
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat(m, std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++) for(int j=0; j<n; j++) std::cin >> mat[i][j];
	mat=OgledaloMatrica(mat);
	std::cout << "\nRezultantna matrica: \n";
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[0].size(); j++) std::cout << std::setw(4) << mat[i][j];
		std::cout << "\n";
	}
	return 0;
}