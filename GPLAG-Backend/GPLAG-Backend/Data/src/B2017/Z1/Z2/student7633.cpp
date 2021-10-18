#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

typedef std::vector<std::vector<double> > matrix;

matrix UnesiMatricu(int x,int y)
{
	std::cout<<"Unesite elemente matrice: ";
	matrix matrica(x, std::vector<double> (y));
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			std::cin>>matrica.at(i).at(j);
	return matrica;
}

void IspisiMatricu(matrix matrica){
	for(auto red:matrica){
		for(auto element:red)
		std::cout<<std::setw(6)<<element;
		std::cout<<std::endl;
	}
}

int SrednjiElementMatrice(matrix matrica){
	return matrica.at(matrica.size()/2).at(matrica.size()/2);
}
int ZbirElemenataOmotaca(matrix matrica,int omotac){
	int zbir(0);
	for(int i=0;i<matrica.size();i++)
	   for(int j=0;j<matrica.at(0).size();j++){
	   	int pom1=std::min(matrica.size()- 1 -i,matrica.at(0).size()- 1 -j);
	   	int pom2=std::min(i,j);
	   	int minimalan=std::min(pom1,pom2);
	   	if(minimalan==omotac)
	   	     zbir+=matrica.at(i).at(j);
	   }
	   return zbir;
}

matrix IzvuciMatricu(matrix matrica,int x,int y,int velicina)
{
	matrix ekstraktovana(velicina,std::vector<double>(velicina));
	for(int i=0; i<velicina; i++)
		for(int j=0; j<velicina; j++)
			ekstraktovana.at(i).at(j)=matrica.at(i+x).at(j+y);
	return ekstraktovana;
}


bool JeLiPlanina(matrix matrica)
{
	for(int i=1; i<matrica.size()/2; i++)
		if(ZbirElemenataOmotaca(matrica,i) <= ZbirElemenataOmotaca(matrica,i-1))
			return false;
	return true;
}
matrix NajvecaPlaninaMatrice(matrix matrica)
{
	bool flag(false);
	for(int i=0;i<matrica.size();i++){
		if(matrica.at(0).size()!=matrica.at(i).size()) flag=true;
	}
	if(flag==true) throw std::domain_error("Matrica nije korektna");
	int manja =std::min(matrica.size(),matrica.at(0).size());
	matrix rezultat;
	for(int velicina=1; velicina<=manja; velicina++) {
		for(int i=0; i<=matrica.size()-velicina; i++) {
			for(int j=0; j<=matrica.at(0).size()-velicina; j++) {
				matrix mat=IzvuciMatricu(matrica,i,j,velicina);
				bool pomoc2=(mat.size()==rezultat.size()) && (SrednjiElementMatrice(mat)>SrednjiElementMatrice(rezultat));
				bool pomoc1=mat.size()>rezultat.size();
				if(JeLiPlanina(mat) && (pomoc1 || pomoc2)) rezultat=IzvuciMatricu(matrica,i,j,velicina);
			}
		}
	}
	return rezultat;
}


int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrix matrica=UnesiMatricu(m,n);
	std::cout<<std::endl;
	std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
	try{
		IspisiMatricu(NajvecaPlaninaMatrice(matrica));
	}
	catch (const std::domain_error& e){
		std::cout<<"Izuzetak: "<< e.what() <<std::endl;
	}
	catch(...){
		std::cout<<"Pogresan izuzetak!";
	}
	return 0;
}