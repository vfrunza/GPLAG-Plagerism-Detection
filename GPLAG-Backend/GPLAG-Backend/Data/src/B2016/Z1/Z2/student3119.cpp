/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat){
	for(int i=0; i<mat.size(); i++) if(mat[i].size()!=mat[0].size()) throw std::domain_error ("Matrica nije korektna");
	
	//AKO JE mat.size()==0, NE SMIJE SE UOPSTE PRISTUPITI mat[0].size()!!!!! (Sjeti se predavanja) ->ovo je rijeseno narednim if-om
	if(mat.size()==0) {
		std::vector<std::vector<double>> prazna_matrica;
		return prazna_matrica;
	}
	
	std::vector<std::vector<double>> nova_mat(3*mat.size(), std::vector<double> (3*mat[0].size()));
	int k(0), z(0); //k je za red, a z je za kolonu

	//Ostale vrste matrica (radi i za matricu formata mx0):
	//Prva matrica (hv)
	for(int i=mat.size()-1; i>=0; i--){
		for(int j=mat[i].size()-1; j>=0; j--){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=0;
		k++;
	}
	
	//Druga matrica (v)
	k=0; 
	z=mat[0].size();
	for(int i=mat.size()-1; i>=0; i--){
		for(int j=0; j<mat[i].size(); j++){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=mat[0].size();
		k++;
	}
	
	//Treca matrica (hv)
	k=0;
	z=2*mat[0].size();
	for(int i=mat.size()-1; i>=0; i--){
		for(int j=mat[i].size()-1; j>=0; j--){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=2*mat[0].size();
		k++;
	}
	
	//Cetvrta matrica (h)
	k=mat.size();
	z=0;
	for(int i=0; i<mat.size(); i++){
		for(int j=mat[i].size()-1; j>=0; j--){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=0;
		k++;
	}
	
	//Peta matrica (glavna)
	k=mat.size();
	z=mat[0].size();
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=mat[0].size();
		k++;
	}
	
	//Sesta matrica (h)
	k=mat.size();
	z=2*mat[0].size();
	for(int i=0; i<mat.size(); i++){
		for(int j=mat[i].size()-1; j>=0; j--){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=2*mat[0].size();
		k++;
	}
	
	//Sedma matrica (hv)
	k=2*mat.size();
	z=0;
	for(int i=mat.size()-1; i>=0; i--){
		for(int j=mat[i].size()-1; j>=0; j--){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=0;
		k++;
	}
	
	//Osma matrica (v)
	k=2*mat.size();
	z=mat[0].size();
	for(int i=mat.size()-1; i>=0; i--){
		for(int j=0; j<mat[i].size(); j++){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=mat[0].size();
		k++;
	}
	
	//Deveta matrica (hv)
	k=2*mat.size();
	z=2*mat[0].size();
	for(int i=mat.size()-1; i>=0; i--){
		for(int j=mat[i].size()-1; j>=0; j--){
			nova_mat[k][z]=mat[i][j];
			z++;
		}
		z=2*mat[0].size();
		k++;
	}
	
	
	return nova_mat;
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0) { std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; }
	std::vector<std::vector<double>> mat(m, std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>mat[i][j];
		}
		std::cout<<std::endl;
	}
	
	
	try{
		std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
		std::vector<std::vector<double>> M (OgledaloMatrica(mat));
		for(int i=0; i<M.size(); i++){
			for(int j=0; j<M[i].size(); j++){
				std::cout<<std::setw(4)<<M[i][j];
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	
	
	return 0;
}