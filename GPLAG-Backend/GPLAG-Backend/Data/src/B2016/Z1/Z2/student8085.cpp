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

typedef std::vector<std::vector<double>> matrica;

matrica OgledaloMatrica(matrica m){
	matrica mat(3*m.size(),std::vector<double>(3*m[0].size()));
	
	for(int i=0; i<m.size(); i++){ //baca izuzetak ako je grbava
		
	    if(m[0].size()!=m[i].size()) throw std::domain_error("Matrica nije korektna");
	}
	
	matrica hv(m.size(),std::vector<double>(m[0].size()));
	for(int i=0; i<m.size(); i++){ // horizontalna-vertikalna matrica za rubove
		for(int j=0; j<m[i].size(); j++){
			hv[i][j]=m[m.size()-1-i][m[i].size()-1-j];
		}
	}
	matrica v(m.size(),std::vector<double>(m[0].size()));
	for(int i=0; i<m.size(); i++){ //vertikalna matrica između hv
		for(int j=0; j<m[i].size(); j++)
		v[i][j]=m[m.size()-1-i][j];
	}
	matrica h(m.size(),std::vector<double>(m[0].size()));
	for(int i(0); i<m.size(); i++){
		for(int j(0); j<m[i].size(); j++){
			h[i][j]=m[i][m[i].size()-1-j];
		}
	}
	
	for(int i(0); i<m.size(); i++){
		for(int j(0); j<3*m[i].size(); j++){
			if(j<m[i].size()) mat[i][j]=hv[i][j];
			if(j>=m[i].size() && j<2*m[i].size()) mat[i][j]=v[i][j-m[i].size()];
			if(j>=2*m[i].size()) mat[i][j]=hv[i][j-2*m[i].size()];
		}
	}
	for(int i(0); i<m.size(); i++){
		for(int j(0); j<3*m[i].size(); j++){
			if(j<m[i].size()) mat[i+m.size()][j]=h[i][j];
			if(j>=m[i].size() && j<2*m[i].size()) mat[i+m.size()][j]=m[i][j-m[i].size()];
			if(j>=2*m[i].size()) mat[i+m.size()][j]=h[i][j-2*m[i].size()];
		}
	}	
	for(int i(0); i<m.size(); i++){
		for(int j(0); j<3*m[i].size(); j++){
			if(j<m[i].size()) mat[i+2*m.size()][j]=hv[i][j];
			if(j>=m[i].size() && j<2*m[i].size()) mat[i+2*m.size()][j]=v[i][j-m[i].size()];
			if(j>=2*m[i].size()) mat[i+2*m.size()][j]=hv[i][j-2*m[i].size()];
		}
	}
	return mat;
}

int main ()
{
	int m, n;
	
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	

	matrica mat(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i(0); i<m; i++){
		for(int j(0); j<n; j++){
			std::cin>>mat[i][j];
		}
	}
	std::cout<<std::endl;
	matrica a(3*m,std::vector<double>(3*n));
	std::cout<<"Rezultantna matrica: "<<std::endl;
	if(m!=0 || n!=0){
	try{
		a=OgledaloMatrica(mat);
		for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout<<std::setw(4)<<a[i][j];
		}
		std::cout<<std::endl; }
	}
	catch(std::domain_error e){
		std::cout<<e.what();
	}
	}
	return 0;
}