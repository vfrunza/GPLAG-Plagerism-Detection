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
#include <stdexcept>

std::vector<std::vector<double>> horizontalna(std::vector<std::vector<double>> mat){

	for(int i=0;i<mat.size();i++){
		for(int j=0;j<(mat.at(i).size())/2;j++){
		
			 double temp=mat[i][j];
			 mat[i][j]=mat[i][mat.at(i).size()-1-j];
			 mat[i][mat.at(i).size()-1-j]=temp;
		}
	}
	return mat;
}

std::vector<std::vector<double>> vertikalna(std::vector<std::vector<double>> mat){
	int m=mat.size();
	
	for(int i=0;i<m/2;i++){
		int n=mat.at(i).size();
		for(int j=0;j<n;j++){
			
			double temp=mat[i][j];
			 mat[i][j]=mat[m-1-i][j];
			 mat[m-1-i][j]=temp;
		}
	}
	return mat;
} 

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat){
//	int m=mat.size();

   for(int i=0;i<mat.size();i++){
    if(mat[i].size()!=mat[0].size()) throw std::domain_error("Matrica nije korektna");
  }

	 std::vector<std::vector<double>> velika;
	 velika.resize(3*mat.size());
	 
	 std::vector<std::vector<double>> hv;
	 hv=horizontalna(vertikalna(mat));
	 
	 std::vector<std::vector<double>> v;
	 v=vertikalna(mat);
	 
	 std::vector<std::vector<double>> h;
	 h=horizontalna(mat);
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i].push_back(hv[i][j]);
	 	}
	 }
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i].push_back(v[i][j]);
	 	}
	 }
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i].push_back(hv[i][j]);
	 	}
	 }
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i+mat.size()].push_back(h[i][j]);
	 	}
	 }
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i+mat.size()].push_back(mat[i][j]);
	 	}
	 }
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i+mat.size()].push_back(h[i][j]);
	 	}
	 }
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i+(2*mat.size())].push_back(hv[i][j]);
	 	}
	 }
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i+(2*mat.size())].push_back(v[i][j]);
	 	}
	 }
	 
	 for(int i=0;i<mat.size();i++){
	 	for(int j=0;j<mat[i].size();j++){
	 		velika[i+(2*mat.size())].push_back(hv[i][j]);
	 	}
	 }

	return velika;
}

int main ()
{
	int m,n;
	try{
	
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std:: cin>>m>>n;
	if(m<0 || n<0) throw "Dimenzije matrice moraju biti nenegativne!";

	std::cout<<"Unesite elemente matrice: ";

   std::vector<std::vector<double>> mat(m,std::vector<double>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>mat[i][j];
		}
	}
	std::vector<std::vector<double>> rezultat;
	rezultat=OgledaloMatrica(mat);
	std::cout<<"\n";
	std::cout<<"Rezultantna matrica: ";
	std::cout<<"\n";
	
	for(int i=0;i<rezultat.size();i++){
		for(int j=0;j<rezultat[i].size();j++){
			std::cout<<std::setw(4)<<rezultat[i][j];
		}
		std::cout<<"\n";
	} 
	}
	catch(const char poruka[]){
	 std::cout<<poruka;}
	 
	 catch(std::domain_error izuzetak){
	 	std::cout<<izuzetak.what()<<std::endl;
	 }
	
	return 0;
}