//B 2017/2018, Zadaća 1, Zadatak 2

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iomanip>

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica){
	double const epsilon(1e-6);
    for(int i=0; i<matrica.size(); i++)
	    	if(matrica.at(i).size() != matrica.at(0).size()) 
	    	       throw std::domain_error("Matrica nije korektna");
	std::vector<std::vector<double>> vrati;
	int x;
	if(matrica.size() <= matrica.at(0).size()) x=matrica.size();
	else x=matrica.at(0).size();
	if(x%2 == 0) x--;
	for(int n=x; n>0; n-=2){
		double mozda;
    	int mozdaX, mozdaY;
    	bool ima{false};
    	for(int i=0; i<matrica.size(); i++){
    		for(int j=0; j<matrica.at(i).size(); j++){
    			if(i>=(n-1)/2 && j>=(n-1)/2 && i+(n-1)/2<matrica.size() && j+(n-1)/2<matrica.at(i).size()){
    				double sredina{matrica.at(i).at(j)}, okolina{0};
    				if(n > 1){
    					if(!ima || sredina >= mozda){
    				    	for(int a=i-1; a<=i+1; a++)
    			     		    for(int b=j-1; b<=j+1; b++)
    				    	        okolina+=matrica.at(a).at(b);
    				    	okolina-=sredina;
    			     		if(sredina > okolina && (!ima || (sredina > mozda || (fabs(sredina-mozda) <= epsilon && (i<mozdaX || j<mozdaY))))){
    			     			mozda=sredina;
    		         			mozdaX=i;
    		         			mozdaY=j;
    		         			ima=true;
    			     		}
    					}
    				}
    				else if(!ima || (sredina>mozda || (fabs(sredina-mozda) <= epsilon && (i<mozdaX || j<mozdaY)))){ 
    					mozda=sredina;
    					mozdaX=i;
    					mozdaY=j;
    					ima=true;
    				}
    			}
    		}
    	}
    	if(ima){
    		vrati=std::vector<std::vector<double>> (n);
    		int c=0;
    		for(int a=mozdaX-(n-1)/2; a<=mozdaX+(n-1)/2; a++){
    		    for(int b=mozdaY-(n-1)/2; b<=mozdaY+(n-1)/2; b++){
    		    	vrati.at(c).push_back(matrica.at(a).at(b));
    		    }
    		    c++;
    		}
    		break;
    	} 
	}
	return vrati;
} 

int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m, n;
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice:" << std::endl;
	std::vector<std::vector<double>>matrica(m, std::vector<double> (n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin >> matrica.at(i).at(j);
		}
	}
	std::cout << "Najveca planina unesene matrice je:" << std::endl;
	try{
    	matrica=NajvecaPlaninaMatrice(matrica);
    	for(auto i:matrica){
    		for(auto j:i) std::cout << std::setw(6) << j;
     		std::cout << std::endl;
        }
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}