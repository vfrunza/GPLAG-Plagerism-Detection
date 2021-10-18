
#include <iostream>
#include <vector> 
#include <cmath>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

std::vector<std::vector<double>> KreirajMatricu(int broj_redova,int broj_kolona) {
   return std::vector<std::vector<double>>(broj_redova, std::vector<double>(broj_kolona));
}

bool Grbava(Matrica mat){
	for(int i=0; i<mat.size();i++){
		for(int j=0; j<mat.size();j++){
			if(mat[i].size()!=mat[j].size())
				return false;
		}
		return true;
	}
	return true;	
}

Matrica  OgledaloMatrica (Matrica mat){
	
	if(!Grbava(mat)) throw std::domain_error("Matrica nije korektna");
	
	Matrica a;
	int x(mat.size()); 
	if(mat.size()==0)
		return a;
	int y(mat[0].size());
	for(int i=0; i<3*x;i++){
		a.push_back(std::vector<double>{});
	}
	int brojac(0);
	int i(0),j(0);
	int n=0;
	while (brojac<9){
		
		
		if(brojac==0 || brojac==2 || brojac==6 || brojac==8){
			for(i=0; i<x;i++){
				for(j=0;j<y;j++){
			     	a.at(n).push_back(mat[x-i-1][y-j-1]);	
				}
				n++;
			}
			if(brojac==2) n=0;
		    brojac++;
		}
		
		if(brojac==1 || brojac==7){
			for(i=0; i<x;i++){
				for(j=0;j<y;j++){
			     	a[n].push_back(mat[i][y-j-1]);	
				}
				n++;
			}
		    brojac++;
		}
		
		if(brojac==3 || brojac==5){
			for(i=0; i<x;i++){
				for(j=0;j<y;j++){
			     	a[n].push_back(mat[x-i-1][j]);
				}
				n++;
			}
			if(brojac==5) n=0;
		    brojac++;
		}
		if(brojac==4){
			for(i=0;  i<x;  i++){
				for(j=0; j<y; j++){
			     	a[n].push_back(mat[i][j]);	
				}
				n++;
			}
		    brojac++;
		}
	}
	
 return a;	
}

int main ()
{ 
    std::cout << "Unesite dimenzije matrice (m n): ";
    int m, n;
    std::cin >> m >> n;
    if(m<0 || n<0) {
    	std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
    	return 0;}
    std::cout << "Unesite elemente matrice: " ;
    Matrica mat(KreirajMatricu(m,n));
    double x;
    for(int i =0; i<m; i++){
    	for(int j=0; j<n; j++){
	    	std::cin >> x;
	        while (!std::cin) {
			            std::cin.clear();
			            std::cin.ignore(10000, '\n');
			            //std::cout << "Niste unijeli broj!\n";
			            //std::cout << "Unesite brojeve (0 za prekid unosa): ";
			            std::cin >> x;
                }
    	    mat[i][j]=x;
    	}
    }
    try {
	    Matrica rez(OgledaloMatrica(mat));
		std::cout << "\nRezultantna matrica:" << std::endl;
		for(int i =0; i<rez.size(); i++){
	    	for(int j=0; j<rez[0].size(); j++){
	    		std::cout.width(4);
	    		std::cout<<std::right << rez[i][j];
	    	}
	    	std::cout << "\n" << std::endl;
	    }
    }
    catch (std::domain_error error) {
    	std::cout << error.what() << std::endl;
    }
     
	return 0;
}