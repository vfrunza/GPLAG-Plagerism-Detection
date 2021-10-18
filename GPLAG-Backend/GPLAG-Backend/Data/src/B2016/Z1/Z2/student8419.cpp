/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>

std::vector<std::vector<double>>HorizontalnoOgledalo(std::vector<std::vector<double>> mat){
	if(mat.size()==0) return mat;
	if(mat[0].size()%2!=0){
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<(mat[i].size()/2); j++){
			for(int k=mat[i].size()-1-j; k>(mat[i].size()/2); k--){
				double tmp=mat[i][j];
				mat[i][j]=mat[i][k];
				mat[i][k]=tmp;
				break;
			}
		}
	}
	}
	else{
		for(int i=0; i<mat.size(); i++){
			for(int j=0; j<mat[i].size()/2; j++){
				for(int k=mat[i].size()-1-j; k>(mat[i].size()/2)-1; k--){
					double tmp=mat[i][j];
					mat[i][j]=mat[i][k];
					mat[i][k]=tmp;
					break;
				}
			}
		}
	}
	return mat;
}

std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>> mat){
	if(mat.size()==0) return mat;
	if(mat.size()%2!=0){
		for(int i=0; i<mat.size()/2; i++){
			for(int j=mat.size()-1-i; j>mat.size()/2; j--){
				for(int k=0; k<mat[0].size(); k++){
					double tmp=mat[i][k];
					mat[i][k]=mat[j][k];
					mat[j][k]=tmp;
				}
				break;
			}
		}
	}
	else{
		for(int i=0; i<mat.size()/2; i++){
			for(int j=mat.size()-1-i; j>(mat.size()/2)-1; j--){
				for(int k=0; k<mat[0].size(); k++){
					double tmp=mat[i][k];
					mat[i][k]=mat[j][k];
					mat[j][k]=tmp;
				}
				break;
			}
		}
	}
	return mat;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat){
	for(int i=0; i<mat.size(); i++){
		if(mat[0].size()!=mat[i].size()) throw std::domain_error("Matrica nije korektna.");
	}
	std::vector<std::vector<double>> H=HorizontalnoOgledalo(mat);
	std::vector<std::vector<double>> V=VertikalnoOgledalo(mat);
	std::vector<std::vector<double>> HV=HorizontalnoOgledalo(V);
	if(mat.size()==0) return mat;
	else{ std::vector<std::vector<double>> konacna(3*mat.size(), std::vector<double>(3*mat[0].size()));
	for(int i=0; i<mat.size(); i++){
		
		for(int j=0; j<HV[i].size(); j++){
			konacna[i][j]=HV[i][j];
		}
		for(int j=HV[i].size(); j<2*V[i].size(); j++){
			konacna[i][j]=V[i][j-V[i].size()];
		}
		for(int j=2*HV[i].size(); j<3*HV[i].size(); j++){
			konacna[i][j]=HV[i][j-(2*V[i].size())];
		}
		
	}
	for(int i=mat.size(); i<2*mat.size(); i++){
		
		for(int j=0; j<H[0].size(); j++){
			konacna[i][j]=H[i-mat.size()][j];
		}
		for(int j=mat[0].size(); j<2*mat[0].size(); j++){
			konacna[i][j]=mat[i-mat.size()][j-mat[0].size()];
		}
		for(int j=2*mat[0].size(); j<3*mat[0].size(); j++){
			konacna[i][j]=H[i-mat.size()][j-2*mat[0].size()];
		}
	}
	for(int i=2*mat.size(); i<3*mat.size(); i++){
		
		for(int j=0; j<HV[0].size(); j++){
			konacna[i][j]=HV[i-(2*mat.size())][j];
		}
		for(int j=V[0].size(); j<2*V[0].size(); j++){
			konacna[i][j]=V[i-(2*mat.size())][j-mat[0].size()];
		}
		for(int j=2*HV[0].size(); j<3*HV[0].size(); j++){
			konacna[i][j]=HV[i-(2*mat.size())][j-(2*mat[0].size())];
		}
	} 
	return konacna; }
}



int main ()
{
	try{ 
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) throw "Dimenzije matrice moraju biti nenegativne!";
	
	std::vector<std::vector<double>> mat(m, std::vector<double> (n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin >> mat[i][j];
		}
	}
	
	std::vector<std::vector<double>> Konacna=OgledaloMatrica(mat); 
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	for(int i=0; i<Konacna.size(); i++){
		for(int j=0; j<Konacna[i].size(); j++){
			std::cout << std::setw(4)<<Konacna[i][j];
		}
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what() << std::endl;
	}
	catch(const char poruka[]){
		std::cout<<poruka<<std::endl;
	}
	return 0;
}