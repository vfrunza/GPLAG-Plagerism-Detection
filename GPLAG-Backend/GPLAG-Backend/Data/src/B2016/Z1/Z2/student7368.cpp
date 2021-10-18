#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
std::vector<std::vector<double>>OgledaloMatrica(std::vector<std::vector<double>>mat) {
	std::vector<std::vector<double>>horM;
	std::vector<std::vector<double>>verM;
	std::vector<std::vector<double>>komM;
	
	for (int i=1; i<mat.size(); i++) {
		if (mat[i].size()!=mat[0].size())
		throw ("Matrica nije korektna!");
	}
	horM=mat; verM=mat; komM=mat;
	//OBRTANJE KOLONA
	for (int i=0; i<horM.size(); i++) {
		for (int j=0; j<horM[i].size()/2; j++) {
			double temp = horM[i][j];
			horM[i][j]= horM[i][horM[i].size()-1-j];
			horM[i][horM[i].size()-1-j]=temp;
		}
	}
	//VERTIKALNO OBRTANJE
	for (int i=0; i<verM.size()/2; i++) {
		for (int j=0; j<verM[i].size(); j++) {
			double temp = verM[i][j];
			verM[i][j]= verM[verM.size()-1-i][j];
			verM[mat.size()-1-i][j]=temp;
		}
	}
	// KOMBINOVANO OBRTANJE
	for (int i=0; i<komM.size(); i++) {
		for (int j=0; j<komM[i].size()/2; j++) {
			double temp = komM[i][j];
			komM[i][j]= komM[i][komM[i].size()-j-1];
			komM[i][komM[i].size()-j-1]=temp;
		}
	}
	for (int i=0; i<komM.size()/2; i++) {
		for (int j=0; j<komM[i].size(); j++) {
			double temp = komM[i][j];
			komM[i][j]= komM[komM.size()-1-i][j];
			komM[komM.size()-1-i][j]=temp;
		}
	}
	std::vector<std::vector<double>>OglM;
	int br_kolona;
    if (OglM == mat) br_kolona=0;
    else br_kolona=mat[0].size();
	OglM.resize(mat.size()*3);
	for (int i=0; i<OglM.size(); i++) {
		OglM[i].resize(br_kolona*3);
	}
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat[i].size(); j++) {
			
			OglM[i][j]=komM[i][j];
			OglM[i][j+mat[i].size()]=verM[i][j];
			OglM[i][j+mat[i].size()*2]=komM[i][j];
			
			OglM[i+mat.size()][j]=horM[i][j];
			OglM[i+mat.size()][j+mat[i].size()]=mat[i][j];
			OglM[i+mat.size()][j+mat[i].size()*2]=horM[i][j];
			
			
			OglM[i+mat.size()*2][j]=komM[i][j];
			OglM[i+mat.size()*2][j+mat[i].size()]=verM[i][j];
			OglM[i+mat.size()*2][j+mat[i].size()*2]=komM[i][j];
		}
	}
	return OglM;
}
int main () {
	
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if (m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>>mat;
	mat.resize(m);
	for (int i=0; i<mat.size(); i++) {
		mat[i].resize(n);
	}
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat[i].size(); j++) {
			std::cin>>mat[i][j];
		}
	}
	std::vector<std::vector<double>>matrica;
	try {
	matrica=OgledaloMatrica(mat);
	}
	catch (std::domain_error izuzetak) {
		std::cout<<"izuzetak.what()"<<std::endl;
	}
	std::cout<<"Rezultantna matrica: "<<std::endl;
	
	for (int i=0; i<matrica.size(); i++) {
		for (int j=0; j<matrica[i].size(); j++) {
			std::cout<<std::setw(4)<<std::right<<matrica[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}