#include <iostream>
#include <vector>
#include <iomanip> 
#include <stdexcept>
std::vector<std::vector<double>> HorizontalnoOgledalo (std::vector<std::vector<double>>mat){
		std::vector<std::vector<double>>nova(mat.size(), std::vector<double>(mat[0].size()));
		for(int i=0; i<mat.size(); i++){
			int k=mat[0].size();
			for(int j=0; j<mat[0].size(); j++){
				nova[i][j]=mat[i][k-1];
				k--;
			}
		}

return nova;
}
std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>>mat){
			std::vector<std::vector<double>>nova(mat.size(), std::vector<double>(mat[0].size()));
			int k=mat.size()-1;
			for(int i=0; i<mat.size(); i++){
				for(int j=0; j<mat[0].size(); j++){
					nova[i][j]=mat[k][j];
				}
				k--;
			}

return nova;	
}
std::vector<std::vector<double>>KombinovanoOgledalo(std::vector<std::vector<double>>mat){
	std::vector<std::vector<double>>nova(mat.size(), std::vector<double>(mat[0].size()));
		int l=mat.size()-1;
			for(int i=0; i<mat.size(); i++){
				int k=mat[0].size();
				for(int j=0; j<mat[0].size(); j++){
					nova[i][j]=mat[l][k-1];
					k--;
				}
				l--;
			}
	return nova;
}
std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> mat){
	if(mat.size()==0) return mat;
	std::vector<std::vector<double>>nova(3* mat.size(), std::vector<double>(3*(mat[0].size())));
	int nekorektna(0);
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat.size(); j++){
			if(mat[i].size()!=mat[j].size()){ nekorektna=1; break;}
		}
	}
	if(nekorektna) throw std::domain_error("Matrica nije korektna");
	int r(nova.size()/3), k(nova[0].size()/3);
	for(int i=0; i<nova.size(); i++){
		for(int j=0; j<nova[0].size(); j++){
		if(i<r && j<k) nova[i][j]=(KombinovanoOgledalo(mat))[i][j];
		if(i<r && j>=k && j<2*k)	nova[i][j]=(VertikalnoOgledalo(mat))[i][j-k];
		if(i<r && j>=2*k && j<3*k) nova[i][j]=(KombinovanoOgledalo(mat))[i][j-2*k];
		if(i>=r && i<2*r && j<k) nova[i][j]=(HorizontalnoOgledalo(mat))[i-r][j];
		if(i>=r && i<2*r && j>=k && j<2*k) nova[i][j]=mat[i-r][j-k];
		if(i>=r && i<2*r && j>=2*k && j<3*k) nova[i][j]=(HorizontalnoOgledalo(mat))[i-r][j-2*k];
		if(i>=2*r && i<3*r && j<k) nova[i][j]=(KombinovanoOgledalo(mat))[i-2*r][j];	
		if(i>=2*r && i<3*r && j>=k && j<2*k) nova[i][j]=(VertikalnoOgledalo(mat))[i-2*r][j-k];
		if(i>=2*r && i<3*r && j>=2*k && j<3*k) nova[i][j]=KombinovanoOgledalo(mat)[i-2*r][j-2*k];	
		}
		
	}
	return nova;
}

int main ()
{
	try{
	int m, n;
	std::vector<std::vector<double>>nova;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	std::vector<std::vector<double>> mat(m, std::vector<double>(n)); 

	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>mat[i][j];
		}
	}
	nova=OgledaloMatrica(mat);
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica: ";
	std::cout<<std::endl;
		if(mat.size()==0) return 0;

	for(int i=0; i<3*m; i++){
		for(int j=0; j<3*n; j++)
			std::cout << std::setw(4) << nova[i][j];
            std::cout << std::endl;
	}
	}
	catch(std::domain_error izuzetak){
	   std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}