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
#include <iomanip>

bool ispravanIndeks(int i, int j, int m, int n){
	if(i>=0 && j>=0 && i<m && j<n)
		return true;
	return false;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> mat){
	
	std::vector<std::vector<double>> rez;
	
	if(mat.size()==0 || mat.at(0).size()==0){
		return rez;
	} 
	
	int sirina = mat.at(0).size();
	
	for(int i=0;i<mat.size();i++){
		if(mat.at(i).size()!=sirina){
			throw std::domain_error("Matrica nije korektna");
		}
	}
	
	int a=-5,b=-5;
	int najvecaPlanina = 0;
	
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat.at(i).size();j++){
			
			int x=1;
			double suma=0;
			double prethodnaSuma = mat.at(i).at(j);
			for ( ; ; ){
				suma=0;
				
				for(int k = i-x; k <= i+x ; k++){
					if(ispravanIndeks(k,j-x,mat.size(),mat.at(0).size()))
					{
					suma+=mat.at(k).at(j-x);}
				}
				
				for(int k=i-x ; k<= i+x ; k++){
					if(ispravanIndeks(k,j+x,mat.size(),mat.at(0).size()))
					{
					suma+=mat.at(k).at(j+x);}
				}
				
			for(int k = j-x; k<= j+x; k++){
					if(ispravanIndeks(i-x,k,mat.size(),mat.at(0).size()))
					{
						suma+=mat.at(i-x).at(k);}
				}
				for(int k=j-x; k<= j+x; k++){
					if(ispravanIndeks(i+x,k,mat.size(),mat.at(0).size()))
					{
						suma+=mat.at(i+x).at(k);}
				}
				
				
				if(ispravanIndeks(i-x,j-x,mat.size(),mat.at(0).size()))
				suma=suma-mat.at(i-x).at(j-x);
				
				if(ispravanIndeks(i-x,j+x,mat.size(),mat.at(0).size()))
				suma=suma-mat.at(i-x).at(j+x);
				
				if(ispravanIndeks(i+x,j-x,mat.size(),mat.at(0).size()))
				suma=suma-mat.at(i+x).at(j-x);
				
				if(ispravanIndeks(i+x,j+x,mat.size(),mat.at(0).size()))
				suma=suma-mat.at(i+x).at(j+x);
				
				if(suma<prethodnaSuma){
					x++;
					prethodnaSuma = suma;
					suma = 0;
					continue;
				}
				
				if(x>najvecaPlanina){
					najvecaPlanina=x;
					a=i; b=j;
				}
				else if(x==najvecaPlanina){
					if(a==-5 || (mat.at(i).at(j)>mat.at(a).at(b))){
						a=i; b=j;
					}
				}
				break;
			
			}
			
			
			
		}
		
	}
	
	if(a==-5){
		return rez;
	}
	
	rez.resize(0);
	
	for(int i=a-najvecaPlanina+1;i<a+najvecaPlanina;i++){
		std::vector<double> pom;
		for(int j=b-najvecaPlanina+1; j<b+najvecaPlanina;j++){
			if(ispravanIndeks(i,j,mat.size(),mat.at(0).size()))
				pom.push_back(mat.at(i).at(j));
			
		}
		if(pom.size())
		rez.push_back(pom);
	}
	
	
	return rez;
	
	
}




int main ()
{
	
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	
	int m,n;
	
	std::cin>>m>>n;
	
	std::vector<std::vector<double>> mat;
	
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	mat.resize(m);
	for(int i=0;i<m;i++)
		mat.at(i).resize(n);
		
		std::cout<<"Unesite elemente matrice: "<<std::endl;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>mat.at(i).at(j);
		}
	}
	
	try{auto rez = NajvecaPlaninaMatrice(mat);
	
	std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	
	for(int i=0;i<rez.size();i++){
		for(int j=0;j<rez.at(i).size();j++){
			std::cout<<std::setw(6)<<rez.at(i).at(j);
		}
		std::cout<<std::endl;
	}}
	catch(std::domain_error e){
		std::cout<<e.what()<<std::endl;
	}
	
	return 0;
}