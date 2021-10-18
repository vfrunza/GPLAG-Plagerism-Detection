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

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> mat) {
	std::vector<std::vector<double>> planina;
	int m,n;
	m=mat.size();
	if(m>0) {
		n=mat.at(0).size();
	for(int i=0; i<mat.size(); i++) 
		if(n!=mat.at(i).size()) throw std::domain_error("Matrica nije korektna");
	}
	if(m==0 || n==0) return planina;
	
	if(m<3 || n<3) {
		int  max(mat.at(0).at(0));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(mat.at(i).at(j)>max) max=mat.at(i).at(j);
			}
		}
		planina.resize(1);
		planina.at(0).push_back(max);
		return planina;
	}
	
	else {
	int format(0);
	int I(1),J(1);
	
	for(int i=1; i<mat.size()-1; i++) {
		for(int j=1; j<mat.at(0).size()-1; j++) {
			int vrh(mat.at(i).at(j));
			int brojac(1);
				
			while(i-brojac>=0 && i+brojac<mat.size() && j-brojac>=0 && j+brojac<mat.at(0).size()) {
				int suma(0);
				for(int z=0; z<=brojac; z++) {
				if(z==0) suma = suma + mat.at(i-brojac).at(j) + mat.at(i+brojac).at(j);	
				else suma = suma + mat.at(i-brojac).at(j-z) + mat.at(i-brojac).at(j+z) + mat.at(i+brojac).at(j-z) + mat.at(i+brojac).at(j+z);
				}
				for(int k=0; k<brojac; k++) {
					if(k==0) suma = suma + mat.at(i).at(j-brojac) + mat.at(i).at(j+brojac);
					else suma = suma + mat.at(i-k).at(j-brojac) + mat.at(i-k).at(j+brojac) + mat.at(i+k).at(j-brojac) + mat.at(i+k).at(j+brojac);
				}
			
			if(suma<vrh) {
				vrh=suma;
				brojac++;
			}
			else break;
			}
			brojac--;
		  
		  if(brojac>format) {
		  	format=brojac;
		  	I=i;
		  	J=j;
		  }
		  else if(brojac==format && mat.at(i).at(j)>mat.at(I).at(J)) {
		  	I=i;
		  	J=j;
		  }
		  else if(brojac==format && mat.at(i).at(j)==mat.at(I).at(J) && (i<I || j<J)) {
		  	I=i; 
		  	J=j;
		  }
		}
	}
	
	if(format>0) {
	planina.resize(2*format+1);
	for(int i=0; i<2*format+1; i++) {
		int k(0);
		while(k<2*format+1) {
			planina.at(i).push_back(mat.at(I-format+i).at(J-format+k));
			k++;
		}
	}
	return planina;
	}
	
	}
	int max(mat.at(0).at(0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(mat.at(i).at(j)>max) max=mat.at(i).at(j);
		}
	}
	planina.resize(1);
	planina.at(0).push_back(max);
	return planina;
	
}




int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n; 
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	std::vector<std::vector<double>> mat;
	mat.resize(m);
	double broj;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin>>broj;
			mat.at(i).push_back(broj);
		}
	}
	
	try {
		std::vector<std::vector<double>> planina(NajvecaPlaninaMatrice(mat));
		std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
		for(std::vector<double> v : planina) {
			for(double x : v) std::cout<<std::setw(6)<<x;
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error poruka) {
		std::cout<<"IZUZETAK: "<<poruka.what()<<std::endl;
	}
	
	return 0;
}