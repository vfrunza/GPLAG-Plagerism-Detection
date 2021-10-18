
#include <iostream>
#include <vector> 
#include <deque>
#include <stdexcept>
#include <iomanip>

typedef  std::vector<std::vector<double>> matrica;
matrica OgledaloMatrica(std::vector<matrica M>)
{ 
	try{   
		matrica ogledalo;
	for(int i(0);i<M.size(){
		for(int j(0);j<M[i].size){
					if(M[i].size()==M[i+1].size()) throw std::domain_error("Matrica nije korektna.");
				ogledalo=M[]
	                
		}    
	}
	matrica transponovana;
	  for(int i(0);M.size();i++){
	  	for(int j(0);j<M[i].size();j++)
	  	transponovana=M[j][i];
	  }
	  matrica vpermutacija;
	  for(int i(0);i<M.size){
	  	
	  }
	  
	matrica hpermutacija;
for(int (0);i<M)
	         
	}             
	catch(std::domain_error izuzetak){      
		std::cout<<izuzetak.what()<<std::endl;
	}
}              

int main ()      
                         
{       
	int a, b;         
	std::cout<<"Unesite broj redova matrice: ";
	std::cin>>a;                         
	std::cout<<"Unesite broj kolona matrice: ";         
	std::cin>>b;
	     
	try{
	matrica M(a, std::vector<real> b);   
	for(int i(0);i<M.size();i++){
		for(int j(0);j<M[i].size();j++){        
 			std::cout<<"Element: ("<<i+1<<","<<j+1<<"): ";
			std::cin>>M[i][j];
		}
	}
	
	matrica rezultantna(OgledaloMatrica(M));
	
	for(int i(0);i<rezultantna.size();i++){
		for(int j(0);j<rezultantna[i].size();j++){ 
			std::cout<<rezultantna[i][j];
		}
		std::cout<<endl;
	}
	}
	catch(...){
		cout<<"Unesena matrica nije korektna!";
	}                  
	return 0;
}