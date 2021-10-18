#include <iostream>
#include <vector>
#include <stdexcept>


std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> MATRICA) {
	
	std::vector<std::vector<double>> pmatrica(0);
	std::vector<double> V;
	double ZbirElemenat(0) ;

	if(MATRICA.size()==0) return pmatrica;
	if(MATRICA.size() > 0) {
	if(MATRICA.size()!=MATRICA[0].size()) throw std::domain_error("Matrica nije korektna");
	}

	int MAX=MATRICA[0][0];
	int r(0),k(0);
	
	
	//Najveci element
	for (int i = 0; i< MATRICA.size(); i++) {
		for(int j=0 ; j < MATRICA[0].size() ; j++) {
			if(MATRICA[i][j]>MAX){
				MAX=MATRICA[i][j];
				r=i;
				k=j;
			}
		}
	}
	
	int m(1);
	double rez(0);
	
	for (int i = 0; i< MATRICA.size(); i++) {
		for(int j=0 ; j < MATRICA[0].size(); j++) {

	while(true){
		
		for(int b=r-m ; b<=r+m ; b++) {
			for(int c=k-m; c<=k+m ;c++) {
				
				rez=rez+MATRICA[b][c];
			}
		}
		
		if(MAX>rez)  {
			pmatrica.push_back(std::vector<double> ());
			pmatrica[0].push_back(MAX);
			
		} else if (MAX<rez) {
				
		for(int b=r-m ; b<=r+m ; b++) {
			pmatrica.push_back(std::vector<double> ());
			for(int c=k-m; c<=k+m ;c++) {
				pmatrica[b].push_back(MATRICA[b][c]);
			}
			
		}
		}
		else break;
	}
		}
	}

	return pmatrica;
	
	
}
	
	


int main ()
{
	try {
	std::vector<std::vector<double>> MATRICA;
	std::vector<double> V;
	int m,n;
	double a;
	
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0)  {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}

	std::cout<<"Unesite elemente matrice: ";
	
	for(int i=0;i<m;i++) {
		MATRICA.push_back(V);
		for(int j=0;j<n;j++) {
			std::cin>>a;
			MATRICA[i].push_back(a);
			
		}
	}
	
	for(auto v: NajvecaPlaninaMatrice(MATRICA)) {
		for( auto m : v) 
			std::cout<<m<<" ";
			std::cout<<std::endl;
	}
	}catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}

	
	return 0;
}