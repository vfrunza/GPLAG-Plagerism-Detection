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

std::vector<std::vector<double>>Horizontalna(std::vector<std::vector<double>>mat){
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size()/2;j++){
			double pomocni=mat[i][j];
			mat[i][j]=mat[i][mat[i].size()-1-j];
			mat[i][mat[i].size()-1-j]=pomocni;
		}
	}
	return mat;
}

std::vector<std::vector<double>> Vertikalna(std::vector<std::vector<double>>mat){
	for(int i=0;i<mat.size()/2;i++){
		std::vector<double> pomocni=mat[i];
		mat[i]=mat[mat.size()-i-1];
		mat[mat.size()-1-i]=pomocni;
	}
	return mat;
}

std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> mat){
	for(int i=1;i<mat.size();i++){
		if(mat[i].size()!=mat[0].size()) throw std::domain_error("Matrica nije korektna");
	}
	std::vector<std::vector<double>> h=Horizontalna(mat);
	std::vector<std::vector<double>> v=Vertikalna(mat);
	std::vector<std::vector<double>> hv=Horizontalna(v);
	std::vector<std::vector<double>> matrica(3*mat.size());
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<hv[i].size();j++){
			matrica[i].push_back(hv[i][j]);
		}
		for(int j=0;j<v[i].size();j++){
			matrica[i].push_back(v[i][j]);
		}
		for(int j=0;j<hv[i].size();j++){
			matrica[i].push_back(hv[i][j]);
		}
	}
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<h[i].size();j++){
			matrica[i+mat.size()].push_back(h[i][j]);
		}
		for(int j=0;j<mat[i].size();j++){
			matrica[i+mat.size()].push_back(mat[i][j]);
		}
		for(int j=0;j<h[i].size();j++){
			matrica[i+mat.size()].push_back(h[i][j]);
		}
	}
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<hv[i].size();j++){
			matrica[i+2*mat.size()].push_back(hv[i][j]);
		}
		for(int j=0;j<v[i].size();j++){
			matrica[i+2*mat.size()].push_back(v[i][j]);
		}
		for(int j=0;j<hv[i].size();j++){
			matrica[i+2*mat.size()].push_back(hv[i][j]);
		}
	}
	return matrica;
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> matrica(m,std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin >> matrica[i][j];
		}
	}
	try{
		matrica=OgledaloMatrica(matrica);
		std::cout << std::endl <<"Rezultantna matrica: "<< std::endl;
		for(int i=0;i<matrica.size();i++){
			for(int j=0;j<matrica[i].size();j++){
				std::cout << std::setw(4)<<  matrica[i][j] ;
			}
			std::cout << std::endl;
		}
	}catch(std::domain_error izuzetak){
		std::cout << izuzetak.what()<< std::endl;
	}
	return 0;
}