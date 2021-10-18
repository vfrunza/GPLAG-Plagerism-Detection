#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> Vektor;

bool DaLiJeGrbava(Matrica M){
	for(int i=0;i<M.size();i++){
		if(M[0].size()!=M[i].size()){
			return true; //Znaci Grbava je
		}
	}
	return false;
}
Matrica KreirajMatricu(int m, int n){
	if(m==0 || n==0) return(Matrica(m, Vektor(n)));
	return Matrica(m, Vektor(n));
}
Matrica UnesiMatricu(int m, int n){
	auto Mat(KreirajMatricu(m,n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>Mat[i][j];
		}
	}
	return Mat;
}
void IspisiMatricu(Matrica Mat){
	for(int i=0; i<Mat.size(); i++){
		for(int j=0; j<Mat[0].size(); j++){
			std::cout<<std::setw(4)<< Mat[i][j];
		}
		std::cout<<std::endl;
	}
}

Matrica Horizontalna(Matrica M){
	Matrica C(KreirajMatricu(M.size(), M[0].size()));
	for(int i=0;i<M.size(); i++){
		for(int j=0;j<M[0].size();j++){
			C[i][j]=M[i][M[i].size()-1-j];
		}
	}
	return C;
}
Matrica Vertikalna(Matrica M){
	Matrica B(KreirajMatricu(M.size(), M[0].size()));
	for(int i=0; i<M.size(); i++){
		for(int j=0; j<M[0].size();j++){
			B[i][j]=M[M.size()-1-i][j];
		}
	}
	return B;
}
Matrica Hor_Ver(Matrica M){
	Matrica C(KreirajMatricu(M.size(), M[0].size()));
	C=Horizontalna(M);
	return Vertikalna(C);
}

Matrica OgledaloMatrica(Matrica M){
	if(M.size()==0) return M;
 	if(DaLiJeGrbava(M)) throw std::domain_error("Matrica nije korektna!");
	Matrica D(KreirajMatricu(M.size()*3, M[0].size()*3)); //Ovdje mi javlja gresku ako mi unese (m,n) 0,0 
	Matrica A(Hor_Ver(M));
	Matrica B(Vertikalna(M));
	Matrica C(Horizontalna(M));
	
	for(int i=0; i<D.size(); i++){
		for(int j=0; j<D[0].size(); j++){
			if(i<A.size()){
				if(j<A[0].size()) D[i][j]=A[i][j];
				if(j<A[0].size()*2 && j>A[0].size()-1) D[i][j]=B[i][j-A[0].size()]; 
				if(j>A[0].size()*2-1) D[i][j]=A[i][j-2*A[0].size()];
			}
			
			if(i>A.size()-1 && i<2*A.size()){
				if(j<A[0].size()) D[i][j]=C[i-A.size()][j];
				if(j<A[0].size()*2 && j>A[0].size()-1) D[i][j]=M[i-A.size()][j-A[0].size()]; 
				if(j>A[0].size()*2-1) D[i][j]=C[i-A.size()][j-2*A[0].size()];
			}
			if(i>2*A.size()-1){
				if(j<A[0].size()) D[i][j]=A[i-2*A.size()][j];
				if(j<A[0].size()*2 && j>A[0].size()-1) D[i][j]=B[i-2*A.size()][j-A[0].size()]; 
				if(j>A[0].size()*2-1) D[i][j]=A[i-2*A.size()][j-2*A[0].size()];
			}
		}
	}
	return D;
}

int main (){ 
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0){std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	auto M(UnesiMatricu(m,n));
/*	
	std::cout<<"Matrica M glasi: "<<std::endl;
	IspisiMatricu(M);
	
	std::cout<<"Horizontalna matrica glasi: "<<std::endl;
	Matrica HZ{Horizontalna(M)};
	IspisiMatricu(HZ);
	std::cout<<std::endl;
	IspisiMatricu(Vertikalna(M));
	
	std::cout<<std::endl;
	IspisiMatricu(Hor_Ver(M));
	std::cout<<std::endl;
*/	
	std::cout<<"Rezultantna matrica: "<<std::endl;
	try{
	IspisiMatricu(OgledaloMatrica(M));
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}