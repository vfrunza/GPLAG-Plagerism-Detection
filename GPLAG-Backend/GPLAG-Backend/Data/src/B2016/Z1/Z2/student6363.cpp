#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double> > matrica;

bool DaLiJeGrbava(matrica M){
	for(unsigned int i(0); i<M.size(); i++){
		for(unsigned int j(i); j<M.size(); j++){
			if(M[i].size() != M[j].size() ) return true;
		}
	}
	return false;
}

matrica DajHorizontalnu(matrica M){
	for(unsigned int i(0); i< M.size(); i++){
		for(int j(0), k(M[0].size()-1); j < int(M[0].size()/2); j++,k--){
			double temp = M[i][j]; M[i][j]=M[i][k]; M[i][k] = temp;
		}
	}
	return M;
}

matrica DajVertikalnu(matrica M){
	for(int i(0), j(M.size()-1); i<int(M.size()/2); i++, j--){
		std::vector<double> temp;
		temp = std::move(M[i]); M[i]= std::move(M[j]); M[j]=std::move(temp); //moguca greska jer moraju da idu sve poredu
	}
	return M;
}

matrica OgledaloMatrica(matrica M){
	if(DaLiJeGrbava(M)) throw std::domain_error("Matrica nije korektna");
	if(M.size()==0) return matrica(0);
	matrica N (3*M.size(), std::vector<double>(3*M[0].size()));
	matrica H = DajHorizontalnu(M);
	matrica V = DajVertikalnu(M);     
	matrica K = DajHorizontalnu(V);
	 int i(0), j(0), m(M.size()*3), n(M[0].size()*3);
	for(;;){
		if((i == 0 && (j == 0 || j == 2*(n/3))) || (i == 2*(m/3) && (j == 0 || j == 2*(n/3)))){
			int temp(j);
			for(int a(0); a<m/3 ; a++, i++){
				for(int b(0); b<n/3; b++, j++){
					N[i][j]= K[a][b];
				}
				j=temp;
			}
	        j+=n/3;
	        i-=m/3;
		}
		else if(j==n/3 && (i==0 || i==2*(m/3))){
			int temp (j);
			for(int a(0) ; a<m/3; a++, i++){
				for(int b(0) ; b<n/3; b++, j++){
					N[i][j]= V[a][b];
				}
				j=temp;
			}
			j+=n/3;
			i-=m/3;
		} 
		else if(i==m/3 && (j==0 || j==2*(n/3))){
			int temp(j);
			for(int a(0) ; a<m/3 ; a++, i++){
				for(int b(0); b<n/3; b++, j++){
					N[i][j] = H[a][b];
				}
				j=temp;
			}
			j+=n/3;
			i-=m/3;
		}
		else {
			int temp(j);
			for(int a(0); a<m/3; a++, i++){
				for(int b(0); b< n/3; b++, j++){
					N[i][j] = M[a][b];
				}
				j=temp;
			}
			j+=n/3;
			i-=m/3;
		}
		if(j==n && i==0){
			i=m/3;
			j=0;
		}
		if(i==m/3 && j==n){
			i=2*(m/3);
			j=0;
		}
		if( j == n && i == 2*(m/3)) break;
	}
	return N;
}
	
matrica KreirajMatricu(int m, int n){
	if(m<0 || n <0 ) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	std::cout << "Unesite elemente matrice: " ;
	if(m==0 && n==0) return matrica(0);
	
	matrica M(m, std::vector<double>(n));
	
	for(unsigned int i(0); i<m; i++){
		for(unsigned int j(0); j<n; j++){
			std::cin>> M[i][j];
		}
	}
	return M;
}	

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	try{
		matrica M = KreirajMatricu(m,n);
	   	M =	OgledaloMatrica(M);
	   	std::cout  << std::endl<<"Rezultantna matrica: "<<std::endl;
	   	for(std::vector<double> x : M){
		for (double y : x) std::cout <<" "<<std::setw(3)<< y;
		std::cout  << std::endl;
		}
	}
	catch(std::domain_error e){
		std::cout << e.what() << std::endl;
	}
	
	
	
	return 0;
}