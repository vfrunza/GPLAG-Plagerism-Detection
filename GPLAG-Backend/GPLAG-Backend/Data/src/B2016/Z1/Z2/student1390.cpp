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
typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica mat){
		if(mat.size()==0){
		Matrica m(3*mat.size(),std::vector<double>(0));
		return m;
	}
	Matrica horizontalna(mat.size(),std::vector<double>(mat[0].size()));
	Matrica vertikalna(mat.size(),std::vector<double>(mat[0].size()));
	Matrica mix(mat.size(),std::vector<double>(mat[0].size()));
	
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			horizontalna[i][j]=mat[i][mat[0].size()-j-1];
		}
	}
	int pomocna(0);
	for(int i=0;i<mat.size();i++){
		for(int j=0; j<mat[0].size(); j++){
			vertikalna[i][j]=mat[mat.size()-pomocna-1][j];
		}
		pomocna++;
	}
	int pomocna2(0);
	for(int i=0;i<mat.size();i++){
		int pomocna1(0);
		for(int j=0;j<mat[0].size();j++){
			mix[i][j]=mat[mat.size()-pomocna2-1][mat[0].size()-pomocna1-1];
			pomocna1++;
		}
		pomocna2++;
	}
	Matrica velika(3*mat.size(),std::vector<double>(3*mat[0].size()));
	for(int i=0;i<3*mat.size();i++){
		for(int j=0;j<3*mat[0].size();j++){
			if((i>=0 && i<mat.size() && j>=0 && j<mat[0].size()) || (i>=2*mat.size() && i<3*mat.size() && j>=0 && j<mat[0].size()) || (i>=0 && i<mat.size() && j>=2*mat[0].size() && j<3*mat[0].size()) || (i>=2*mat.size() && i<3*mat.size() && j>=2*mat[0].size() && j<3*mat[0].size())){
				if(j>=2*mat[0].size() && i<mat.size()){
					velika[i][j]=mix[i][j-2*mat[0].size()];
				}
				if(i>=2*mat.size() && j<mat[0].size())velika[i][j]=mix[i-2*mat.size()][j];
				if(i>=2*mat.size() && j>=2*mat[0].size())velika[i][j]=mix[i-2*mat.size()][j-2*mat[0].size()];
				if(i<mat.size() && j<mat[0].size())velika[i][j]=mix[i][j];
			}
			if((j>=mat[0].size() && j<2*mat[0].size() && i<mat.size()) || (j>=mat[0].size() && j<2*mat[0].size() && i<3*mat.size() && i>=2*mat.size())){
				if(i>=2*mat.size())velika[i][j]=vertikalna[i-2*mat.size()][j-mat[0].size()];
				else velika[i][j]=vertikalna[i][j-mat[0].size()];
			}
			if((i>=mat.size() && i<2*mat.size() && j<mat[0].size()) || (i>=mat.size() && i<2*mat.size() && j<3*mat[0].size() && j>=2*mat[0].size())){
				if(j>=2*mat[0].size())velika[i][j]=horizontalna[i-mat.size()][j-2*mat[0].size()];
				else velika[i][j]=horizontalna[i-mat.size()][j];
			}
			else if(j>=mat[0].size() && j<2*mat[0].size() && i>=mat.size() && i<2*mat.size())velika[i][j]=mat[i-mat.size()][j-mat[0].size()];
		}
	}
	
	return velika;
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	try {
		if(m<0)throw m;
		if(n<0)throw n;
	}
	catch (int e) {
		std::cout <<"Dimenzije matrice moraju biti nenegativne! " << std::endl;
		return 0;
	}
	Matrica M(m,std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>M[i][j];
		}
	}
	if(m==0 && n==0){
		std::cout<< std::endl;
		std::cout << "Rezultantna matrica: " << std::endl;
		return 0;
	}
	Matrica konacna=OgledaloMatrica(M);
	std::cout << std::endl;
	std::cout << "Rezultantna matrica: " << std::endl;
	for(int i=0;i<3*m;i++){
		for(int j=0;j<3*n;j++){
			std::cout.width(4);
			std::cout << konacna[i][j];
		}
		std::cout<<std::endl;
	}
	
	return 0;
}