
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

std::vector<std::vector<double>> MatricaHorizontalna(std::vector<std::vector<double>> mat){
    int n(mat.size());
    int m(mat[0].size());
    std::vector<std::vector<double>> mat1(n, std::vector<double> (m));
    for(int i(0); i<n; i++){
        for(int j(0); j<m; j++){
                mat1[i][j]=mat[i][m-1-j];
}
    }
return mat1;
			}

std::vector<std::vector<double>> MatricaVertikalna(std::vector<std::vector<double>> mat){
    int n(mat.size());
    int m(mat[0].size());
    std::vector<std::vector<double>> mat1(n, std::vector<double> (m));
    for(int i(0); i<n; i++){
        for(int j(0); j<m; j++){
                mat1[i][j]=mat[n-1-i][j];
}
    }
return mat1;
			}

std::vector<std::vector<double>> MatricaHorizontalnaIVertikalna(std::vector<std::vector<double>> mat){
    int n(mat.size());
    int m(mat[0].size());
    std::vector<std::vector<double>> mat1(n, std::vector<double> (m));
    for(int i(0); i<n; i++){
        for(int j(0); j<m; j++){
                mat1[i][j]=mat[n-1-i][m-1-j];
}
    }
return mat1;
			}





std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat){
	if(mat.size() == 0) return mat;
	for(int i(1); i < mat.size(); i++){
		if(mat[i-1].size() != mat[i].size()) throw std::domain_error("Matrica nije korektna");
	}
	
	std::vector<std::vector<double>> a,b,c;
	std::vector<std::vector<double>> matP(3*mat.size(), std::vector<double> (3*mat[0].size()));
	a=MatricaHorizontalna(mat);
	b=MatricaVertikalna(mat);
	c=MatricaHorizontalnaIVertikalna(mat);
	int s(0), p(0);
	
	for(int i(0); i < mat.size(); i++){ // prvi upis
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = c[i][j];
			p++;
		}
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = b[i][j];
			p++;
		}
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = c[i][j];
			p++;
		}
		p=0; s++;
	}
	
	for(int i(0); i < mat.size(); i++){ // drugi upis
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = a[i][j];
			p++;
		}
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = mat[i][j];
			p++;
		}
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = a[i][j];
			p++;
		}
		p=0; s++;
	}
	
	for(int i(0); i < mat.size(); i++){ // treci upis
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = c[i][j];
			p++;
		}
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = b[i][j];
			p++;
		}
		for(int j(0); j < mat[i].size(); j++){
			matP[s][p] = c[i][j];
			p++;
		}
		p=0; s++;
	}
	
	return matP;
}

int main (){

	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m;
	std::cin>>n;
	if(m < 0 || n < 0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> mat(m, std::vector<double> (n));
	std::cout<<"Unesite elemente matrice:\n";
	for(int i=0; i<m; i++){
         for(int j=0; j<n; j++){
            std::cin>>mat[i][j];
         }
            std::cout<<std::endl;

         }
    std::vector<std::vector<double>> a;
try{
    a=OgledaloMatrica(mat);
    std::cout<<"Rezultantna matrica:\n";
    for(int i=0; i<a.size(); i++){
         for(int j=0; j<a[i].size(); j++){
            std::cout<<std::setw(4)<<a[i][j];
         }
            std::cout<<std::endl;

         }
}catch(std::domain_error e){
	std::cout<<"Izuzetak: "<<e.what();
}
	return 0;
}
