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

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> mat){
	std::vector<std::vector<double>> pomocna;
	if(mat.size()==0 || mat.at(0).size()==0) return pomocna;
	for(int i=0; i<mat.size(); i++){
		if(mat.size()!=mat.at(i).size()) throw std::domain_error("Matrica nije korektna");
			int vel=mat.size();
		
	for(int j=0; j<mat.size(); j++){
		
		if(mat.size()==1 && mat.at(0).size()==1) return pomocna;
		    /*while(vel!=0)1{
		    	if(vel%2!=0){
					int suma{};
					for(int k=i; k<vel-1; k++) {
						for(int l=j; l<vel-1; l++){
					-		if(k!=(vel/2) && l!=(vel/2)) {
							suma+=mat.at(k).at(l);
							}
						}
			    	
				if(mat.at(vel/2).at(vel/2)>suma)
				pomocna.push_back(mat.at(i));
		    	}
		    vel--;
			}
		}
	}

	}
	*/
	}
}
	return pomocna;
}
int main ()
{

	int m{},n{};
	std::cout<<"Unesite dimenzije matrice (m i n): ";
try{
	std::cin>>m>>n;
	if(m<0 || n<0) { std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	    return 0;
	}
	if(m==0 || n==0) return 0; 

	std::vector<std::vector<double>> mat(m,std::vector<double> (n));
	std::cout<<"Unesite elemente matrice:\n";
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			std::cin>>mat.at(i).at(j);
		}
	}

	std::cout<<"Najveca planina unesene matrice je: ";
	std::vector<std::vector<double>> rezultat=NajvecaPlaninaMatrice(mat);
	for(auto x:rezultat){
		for(auto y:x)
			std::cout<<y<<" ";
	}
}

catch(std::domain_error izuzetak){
	std::cout<<izuzetak.what();
}
	
	return 0;
}