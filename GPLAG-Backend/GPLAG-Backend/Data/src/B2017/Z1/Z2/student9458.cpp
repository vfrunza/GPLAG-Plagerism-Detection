/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> mat){
	std::vector<std::vector<double>> konacna;
	 if(mat.size()<0 || mat[0].size()<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	int planina=0;
	int cuvaj,cuvaj2;
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
	
			if(i>0 && j>0 && i<mat.size()-1 && j<mat[0].size()-1 && mat[i][j]>mat[i-1][j-1]+mat[i-1][j]+mat[i-1][j+1]+mat[i][j-1]+mat[i][j+1]+mat[i+1][j-1]+mat[i+1][j]+mat[i+1][j+1]){
		      planina=1;
			cuvaj=i;
			cuvaj2=j;
			break;
	}
		}
	}
	konacna.resize(cuvaj+2);
	if(planina){
		for(int p=i;p>=0;p--){
			for(int x=j;x>=0;x--){
				
			}
		}
		for(int k=0;k<=cuvaj+1;k++){
			for(int m=0;m<=cuvaj2+1;m++){
				konacna[k].push_back(mat[k][m]);
			}
		}
	}
	for(int)
	return konacna;
}
int main ()
{
	int n,m;

	std::cout <<"Unesite dimenzije matrice (m i n): ";
	std::cin >>m;
	std::cin >>n;
   if(m<0 || n<0) std::cout <<"Dimenzije matrice moraju biti nenegativne!";
   else{
	std::cout <<"Unesite elemente matrice: ";
	std::vector<std::vector<double>> a(m,std::vector<double>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		std::cin>>a[i][j];
		}
	}
	std::vector<std::vector<double>> nova;
	try{
	nova=NajvecaPlaninaMatrice(a);}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	for(int i=0;i<nova.size();i++){
		for(int j=0;j<nova[i].size();j++){
			std::cout<<nova[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
   }
	return 0;
}