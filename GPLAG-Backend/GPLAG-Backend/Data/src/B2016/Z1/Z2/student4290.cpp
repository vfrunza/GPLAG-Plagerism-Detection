#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
int BrRed(Matrica m){
	return m.size();
}
int BrKol(Matrica m){
		for(int i=0;i<m.size();i++)
		return m[m.size()-1].size();
}
Matrica VertikalnoOgledalo(Matrica mat){
	
	for(int i=0;i<BrRed(mat)/2;i++){
		for(int j=0;j<BrKol(mat);j++){
			double temp=mat[i][j];
			mat[i][j]=mat[BrRed(mat)-1-i][j];
			mat[BrRed(mat)-1-i][j]=temp;
		}
	}
	return mat;
}
Matrica HorizontalnoOgledalo(Matrica mat){
	for(int i=0;i<BrRed(mat);i++){
		for(int j=0;j<BrKol(mat)/2;j++){
			double temp=mat[i][j];
			mat[i][j]=mat[i][BrKol(mat)-1];
			mat[i][BrKol(mat)-1]=temp;
		}
	}
	return mat;
}
Matrica HV(Matrica mat){
	return VertikalnoOgledalo(HorizontalnoOgledalo(mat));
}
Matrica OgledaloMatrica(Matrica m){
	Matrica hora=HorizontalnoOgledalo(m);
	Matrica vera=VertikalnoOgledalo(m);
	Matrica hvo=HV(m);
	Matrica mat(3*BrRed(m),std::vector<double> (3*BrKol(m)));
	for(int i=0;i<BrRed(m);i++){
		for(int j=0;j<BrKol(m);j++){
			mat[i][j]=hvo[i][j];
			mat[i][j+BrKol(m)]=vera[i][j];
			mat[i][j+2*BrKol(m)]=hvo[i][j];
			mat[i+BrRed(m)][j]=hora[i][j];
			mat[i+BrRed(m)][j+BrKol(m)]=m[i][j];
			mat[i+BrRed(m)][j+2*BrKol(m)]=hora[i][j];
			mat[i+2*BrRed(m)][j]=hvo[i][j];
			mat[i+2*BrRed(m)][j+BrKol(m)]=vera[i][j];
			mat[i+2*BrRed(m)][j+2*BrKol(m)]=hvo[i][j];
		}
	}
	return mat;
}
int main (){
	
		int n,m;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(n<0 || m<0){
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		Matrica ma(m,std::vector<double> (n));
		std::cout<<"Unesite elemente matrice: ";
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
					std::cin>>ma[i][j];			
			}
		}
		Matrica mat=OgledaloMatrica(ma);
		std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
		for(int i=0;i<BrRed(mat);i++){
			for(int j=0;j<BrKol(mat);j++){
				std::cout<<std::setw(4)<<mat[i][j];
			}
			std::cout<<std::endl;
		}
	
	
	return 0;
}