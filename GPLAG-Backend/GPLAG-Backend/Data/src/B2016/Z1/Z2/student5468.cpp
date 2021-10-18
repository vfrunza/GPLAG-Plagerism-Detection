#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> matrica;

matrica OgledaloMatrica(matrica mat){
	if(mat.size()==0)
		return mat;
	bool logicka(false);
	for(int i=0; i<int(mat.size())-1; i++){
		if(mat[i].size()!=mat[i+1].size())
			logicka=true;
	}
	if(logicka)
		 throw std::domain_error("Matrica nije korektna");
	matrica a(3*mat.size(), std::vector<double> (mat[0].size()*3));
	for(int i=0; i<mat.size(); i++){                     //gore lijevo
		for(int j=0; j<mat[i].size(); j++){
			a[mat.size()-i-1][mat[i].size()-j-1]=mat[i][j];
		}
	} 
		for(int i=0; i<mat.size(); i++){    // sredina
		//	std::cout<<i;
		for(int j=mat[i].size()-1; j>=0; j--){
			//std::cout<<j;
		a[mat.size()+i][mat[i].size()+j]=mat[i][j];
		}
	} 
		for(int i=0; i<mat.size(); i++){     //sredina lijevo
		//	std::cout<<i;
		for(int j=mat[i].size()-1; j>=0; j--){
			//std::cout<<mat.size()+i<<","<<mat[i].size()-j;
		a[mat.size()+i][mat[i].size()-j-1]=mat[i][j];
		}
	}     
		for(int i=0; i<mat.size(); i++){    //sredina desno
		//	std::cout<<i;
		for(int j=mat[i].size()-1; j>=0; j--){
			//std::cout<<j;
		a[mat.size()+i][3*mat[i].size()-j-1]=mat[i][j];
		}
	}     
		for(int i=0; i<mat.size(); i++){                     //gore sredina
			for(int j=0; j<mat[i].size(); j++){
				a[mat.size()-i-1][mat[i].size()+j]=mat[i][j];
		}
	} 
	for(int i=0; i<mat.size(); i++){                     //dolje sredina
			for(int j=0; j<mat[i].size(); j++){
				a[3*mat.size()-i-1][mat[i].size()+j]=mat[i][j];
		}
	} 

		for(int i=0; i<mat.size(); i++){         //dolje lijevo
		for(int j=0; j<mat[i].size(); j++){
			a[mat.size()*3-i-1][mat[i].size()-j-1]=mat[i][j];
		}
	}
		for(int i=0; i<mat.size(); i++){                     //gore desno
		for(int j=0; j<mat[i].size(); j++){
			a[mat.size()-i-1][3*mat[i].size()-j-1]=mat[i][j];
		}
	}

	for(int i=0; i<mat.size(); i++){                     //gore desno
		for(int j=0; j<mat[i].size(); j++){
			a[mat.size()-i-1][3*mat[i].size()-j-1]=mat[i][j];
		}
	}
	for(int i=0; i<mat.size(); i++){                     //dolje desno
		for(int j=0; j<mat[i].size(); j++){
			a[3*mat.size()-i-1][3*mat[i].size()-j-1]=mat[i][j];
		}
	}
	return a;
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int n;
	std::cin>>n;
	int m;
	std::cin>>m;
	if(m<0 or n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
		try{
	matrica mat(n,std::vector<double>(m));
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			std::cin>>mat[i][j];
		}		
	}
	mat=OgledaloMatrica(mat);
	std::cout<<"Rezultantna matrica: "<<std::endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			std::cout<<std::setw(4)<<mat[i][j];
		}		
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error izuzetak) {
 		std::cout << izuzetak.what() << std::endl;
	}
	
	return 0;
}