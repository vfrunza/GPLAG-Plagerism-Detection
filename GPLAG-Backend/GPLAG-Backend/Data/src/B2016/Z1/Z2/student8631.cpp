/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std; 

vector<vector<double>>H(vector<vector<double>>v){

			 for(unsigned int i=0; i<v.size(); i++){
			 	for(unsigned int j=0; j<v[i].size()/2; j++){
			 	v[i][j]=v[j][i]; 	
			 		
			 		/*
			     double temp=v[i][j];
                 v[i][j]=v[i][v[i].size()-j-1]; 
                 v[i][v[i].size()-j-1]=temp;*/
		      }
		}
	
	return v; 
}
vector<vector<double>>V(vector<vector<double>>v){

			 for(unsigned int i=0; i<v.size()/2; i++){
			 	
			     vector<double> temp=v[i];
                 v[i]=v[v.size()-i-1]; 
                 v[v.size()-i-1]=temp;
		      }
		
	
	return v; 
}

vector<vector<double>>OgledaloMatrica(vector<vector<double>>mat){

for(int i=0;i<mat.size();i++)
	if(mat[i].size()!=mat[0].size()) throw domain_error("Ne valja");

	vector<vector<double>>a=V(mat); 
	vector<vector<double>>b=H(mat); 
	vector<vector<double>>c=V(H(mat));

	vector<vector<double>>E(3*mat.size()); 
	for(unsigned int i=0;i<E.size();i++)
		E[i].resize(3*mat[0].size());
	
	
    for(unsigned int i=0; i<E.size(); i++){
		for(unsigned int j=0; j<E[i].size(); j++){
				  
				if(i<E.size()/3 && j<E[i].size()/3) 
					 E[i][j]=c[i][j];
   	            else if(i<E.size()/3 && j>= E[i].size()/3+mat[i].size()) 
   	                 E[i][j]=c[i][j-(E[i].size()/3+mat[i].size())];
 	            else if(i>=E.size()/3+mat.size() && j<E[i].size()/3) 
 	                 E[i][j]=c[i-(E.size()/3+mat.size())][j];
   	            else if(i>=E.size()/3+mat.size()&& j>=E[i].size()/3+mat[0].size())
                	 E[i][j]=c[i-(E.size()/3 + mat.size())][j-(E[i].size()/3+mat[0].size())]; 
   	              
   	            else if(i>=E.size()/3 && i<E.size()/3+mat.size() && j<E[i].size()/3)
   			         E[i][j]=b[i-E.size()/3][j]; 
   	            else if(i>=E.size()/3 && i<E.size()/3+mat.size() && j>=E[i].size()/3+mat[0].size())
   	        	     E[i][j]=b[i-E.size()/3][j-(E[i].size()/3+mat[0].size())]; 
   	            
   	            else if(j>=E[i].size()/3 && j<E[i].size()/3+mat[0].size() && i<E.size()/3) 
   	            	  E[i][j]=a[i][j-E[i].size()/3]; 
   	            else if(j>=E[i].size()/3 && j<E[i].size()/3+mat[0].size() && i>=E.size()/3+mat.size())
   	            	  E[i][j]=a[i-(E.size()/3+mat.size())][j-E[i].size()/3];
   	            
   	            else E[i][j]=mat[i-mat.size()][j-mat[0].size()]; 
   	       
	}
}
	return E;
}

int main(){
	try{
	int m, n; 
	cout<<"Unesite dimenzije matrice (m n): "; 
	cin>>m>>n; 
	if(m<0 || n<0){cout<<"Dimenzije matrice moraju biti nenegativne!";return 0;}
	std::cout << "Unesite elemente matrice: " << std::endl;
	std::vector<vector<double>>mat(m, std::vector<double>(n)) ;
	
	for(unsigned int i=0; i<mat.size(); i++){
		for(unsigned int j=0; j<mat[i].size(); j++){
		cin>>mat[i][j];
		}
	}
	std::vector<std::vector<double>>E=OgledaloMatrica(mat); 
	cout<<"Rezultantna matrica: "<<endl;
	for(unsigned int i=0; i<E.size(); i++){
		for(unsigned int j=0; j<E[0].size(); j++){
			cout<<setw(4)<<E[i][j]; 
		}
		cout<<endl;
	}} 
catch(domain_error izuzetak){
	cout<<izuzetak.what()<<endl;
        
    }

	return 0; 
}













