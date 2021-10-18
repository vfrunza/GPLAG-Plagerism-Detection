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

std::vector<std::vector<double>> Horizontalna(std::vector<std::vector<double>> matrica){
	for(int i = 0; i < matrica.size(); i++){
		if(matrica[i].size() == 1) return matrica;
		for(int j = 0; j < matrica[i].size()/2; j++){
 			int pomocna = matrica[i][j];
			matrica[i][j] = matrica[i][matrica[i].size()-1-j];
			matrica[i][matrica[i].size()-1-j] = pomocna;
		}
	}
	return matrica;
}

std::vector<std::vector<double>> Vertikalna(std::vector<std::vector<double>> matrica){
	for(int i = 0; i < matrica.size()/2; i++){
	if(matrica.size() == 1) return matrica;
	for(int j = 0; j < matrica[i].size(); j++){
		int pomocna = matrica[i][j];
		matrica[i][j] = matrica[matrica.size()-1-i][j];
		matrica[matrica.size()-1-i][j] = pomocna;		
		}
	}
	return matrica;	
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica){
	if(matrica.size() == 0){ return matrica; }
	
	std::vector<std::vector<double>> rez;
	rez.resize(3*matrica.size());
	for(int i = 0; i < rez.size(); i++){ rez[i].resize(matrica[0].size()*3); }
	std::vector<std::vector<double>> hv = Horizontalna(Vertikalna(matrica));
	std::vector<std::vector<double>> v = Vertikalna(matrica);
	std::vector<std::vector<double>> h = Horizontalna(matrica);
	int kolona = matrica[0].size();
	int redovi = matrica.size();
	for(int i = 0; i < matrica.size(); i++){
		for(int j = 0; j < matrica[0].size(); j++){
			rez[i+redovi][j+kolona] = matrica[i][j];
			rez[i][j] = hv[i][j];
			rez[i][j+kolona] = v[i][j];
			rez[i+redovi*2][j+kolona] = v[i][j];
			rez[i+redovi][j] = h[i][j];
			rez[i+redovi][j+kolona*2] = h[i][j];
			rez[i][j+kolona*2] = hv[i][j];
			rez[i+redovi*2][j] = hv[i][j];
			rez[i+redovi*2][j+kolona*2] = hv[i][j];
		}
	}
	return rez;
}

int main (){
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin >> m >> n;
	if(m < 0 || n < 0){ std::cout << "Dimenzije matrice moraju biti nenegativne!"; return 0; }
	std::vector<std::vector<double>> mat(m,std::vector<double>(n));
	std::cout << "Unesite elemente matrice: \n";
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){ std::cin >> mat[i][j]; }
	}
	mat = OgledaloMatrica(mat);
	std::cout << "Rezultantna matrica: \n";
	for(int i = 0; i < mat.size(); i++){
		for(int j = 0; j < mat[i].size(); j++) std::cout << std::right << std::setw(4) << mat[i][j];
	std::cout << std::endl;
	}
	return 0;
}