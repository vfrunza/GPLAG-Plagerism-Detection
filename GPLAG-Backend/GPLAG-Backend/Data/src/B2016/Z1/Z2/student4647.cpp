
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica (Matrica m) {
	int red=m.size();
	int kol;
	if(m.size()==0) kol=0;
	else kol=m[0].size();
	for (int i=0; i<m.size(); i++) {
		if (m[i].size()!=m[0].size()) {
			throw std::domain_error("Matrica nije korektna");
			break;
		}
	}

	Matrica hm(red, std::vector<double>(kol));     //horizontalno ogledalo
	for(int i=0; i<red; i++) {
		int k=kol-1;
		for(int j=0; j<kol; j++) {
			hm[i][j]=m[i][j+k];
			k=k-2;
		}
	}
	
	Matrica vm(red, std::vector<double>(kol));     //vertikalno ogledalo
	for(int j=0; j<kol; j++) {
		int r=red-1;
		for(int i=0; i<red; i++) {
			vm[i][j]=m[i+r][j];
			r=r-2;
		}
	}
	
	Matrica hvm(red,std::vector<double>(kol));     //kombinovano ogledalo
	for(int i=0; i<red; i++) {
		int k=kol-1;
		for(int j=0; j<kol; j++) {
			hvm[i][j]=vm[i][j+k];
			k=k-2;
		}
	}
	
	Matrica matrica(red*3, std::vector<double>(kol*3));
	
	for(int i=0; i<red; i++) for(int j=0; j<kol; j++) matrica[i][j]=hvm[i][j];
	for(int i=0; i<red; i++) for(int j=kol; j<kol*2; j++) matrica[i][j]=vm[i][j-kol];
 	for(int i=0; i<red; i++) for(int j=kol*2; j<kol*3; j++) matrica[i][j]=hvm[i][j-kol*2];
 	
	for(int i=red; i<red*2; i++) for(int j=0; j<kol; j++) matrica[i][j]=hm[i-red][j];
	for(int i=red; i<red*2; i++) for(int j=kol; j<kol*2; j++)	matrica[i][j]=m[i-red][j-kol];
 	for(int i=red; i<red*2; i++) for(int j=kol*2; j<kol*3; j++)	matrica[i][j]=hm[i-red][j-kol*2];
 	
	for(int i=red*2; i<red*3; i++) for(int j=0; j<kol; j++) matrica[i][j]=hvm[i-red*2][j];
	for(int i=red*2; i<red*3; i++) for(int j=kol; j<kol*2; j++)	matrica[i][j]=vm[i-red*2][j-kol];
 	for(int i=red*2; i<red*3; i++) for(int j=kol*2; j<kol*3; j++) matrica[i][j]=hvm[i-red*2][j-kol*2];
 	
 	return matrica;
}

int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	
	try {
	std::cin>>m>>n;
	if (m<0 || n<0) throw "Dimenzije matrice moraju biti nenegativne!";

	Matrica matr(m, std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++) 
		for(int j=0; j<n; j++) {
			std::cin>>matr[i][j];
		}
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;;
	for(int i=0; i<m*3; i++)  {
		for(int j=0; j<n*3; j++) {
			std::cout<<std::setw(4)<<OgledaloMatrica(matr)[i][j];
		}
		std::cout<<std::endl;
	}
	}
	catch (const char poruka[]) {
		std::cout<<poruka;
	}
	
	return 0;
}