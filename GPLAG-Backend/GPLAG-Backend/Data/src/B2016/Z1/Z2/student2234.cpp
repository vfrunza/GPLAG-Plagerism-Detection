/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
typedef std::vector<std::vector<double>>Matrica;
Matrica HorizontalnoOgledalo(Matrica mat){
	Matrica hor(mat.size(),std::vector<double>(mat[0].size()));
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[0].size();j++){
			hor[i][j]=mat[i][mat[0].size()-j-1];
		}
	}
	return hor;
}
Matrica VertikalnoOgledalo(Matrica mat){
	Matrica ver(mat.size(),std::vector<double>(mat[0].size()));
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[0].size();j++){
			ver[i][j]=mat[mat.size()-i-1][j];
		}
	}
	return ver;
}
Matrica KombinovanoOgledalo(Matrica mat){
	Matrica komb(mat.size(),std::vector<double>(mat[0].size()));
		for(int i(0);i<mat.size();i++){
			for(int j(0);j<mat[0].size();j++){
				komb[i][j]=mat[mat.size()-i-1][mat[0].size()-j-1];
			}
		}
		return komb;
}
Matrica OgledaloMatrica(Matrica mat){
	for(int i(0);i<mat.size();i++){
		if(mat[i].size()!=mat[0].size())throw std::domain_error("Matrica nije korektna");
	}
	if(mat.size()==0)return Matrica(0,std::vector<double>(0));
	if(mat[0].size()==0)return Matrica(3*mat.size(),std::vector<double>(0));
	Matrica ogledalo(3*mat.size(),std::vector<double>(3*mat[0].size()));
	Matrica komb=KombinovanoOgledalo(mat);
	Matrica hor=HorizontalnoOgledalo(mat);
	Matrica ver=VertikalnoOgledalo(mat);
		for(int i(0);i<ogledalo.size();i++){
			for(int j(0);j<ogledalo[0].size();j++){
				if((i>=0 && i<=mat.size()-1) && (j>=0 && j<=mat[0].size()-1)) ogledalo[i][j]=komb[i][j];
				else if((i>=0 && i<=mat.size()-1) && (j>=mat[0].size() && j<=2*mat[0].size()-1))ogledalo[i][j]=ver[i][j-mat[0].size()];
				else if((i>=0 && i<=mat.size()-1) && (j>=2*mat[0].size() && j<=3*mat[0].size()-1))ogledalo[i][j]=komb[i][j-2*mat[0].size()];
				else if((i>=mat.size() && i<=2*mat.size()-1) && (j>=0 && j<=mat[0].size()-1))ogledalo[i][j]=hor[i-mat.size()][j];
				else if((i>=2*mat.size() && i<=3*mat.size()-1) && (j>=0 && j<=mat[0].size()-1))ogledalo[i][j]=komb[i-2*mat.size()][j];
				else if((i>=mat.size() && i<=2*mat.size()-1) && (j>=mat[0].size() && j<=2*mat[0].size()-1))ogledalo[i][j]=mat[i-mat.size()][j-mat[0].size()];
				else if((i>=mat.size() && i<=2*mat.size()-1) && (j>=2*mat[0].size() && j<=3*mat[0].size()-1))ogledalo[i][j]=hor[i-mat.size()][j-2*mat[0].size()];
				else if((i>=2*mat.size() && i<=3*mat.size()-1) && (j>=2*mat[0].size() && j<=3*mat[0].size()-1))ogledalo[i][j]=komb[i-2*mat.size()][j-2*mat[0].size()];
				else if((i>=2*mat.size() && i<=3*mat.size()-1) && (j>=mat[0].size() && j<=2*mat[0].size()-1))ogledalo[i][j]=ver[i-2*mat.size()][j-mat[0].size()];
			}
		}
	return ogledalo;
}
int main (){
	try{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(n<0 || m<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica mat(m, std::vector<double>(n));
	for(int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			std::cin>>mat[i][j];
		}
	}
	Matrica glavna=OgledaloMatrica(mat);
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	for(int i(0);i<glavna.size();i++){
		for(int j(0);j<glavna[0].size();j++){
			std::cout<<std::setw(4)<<glavna[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
	}
	catch(std::domain_error greska){
		std::cout<<greska.what();
	}
}