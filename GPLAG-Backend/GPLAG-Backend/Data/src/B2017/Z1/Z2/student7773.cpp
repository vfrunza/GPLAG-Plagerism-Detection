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
#include <iomanip>
#include <stdexcept>

std::vector<std::vector<double>>NajvecaPlaninaMatrice(std::vector<std::vector<double>> mat){
	int max(0),k,l,m;
	std::vector<double> red;
	std::vector<std::vector<double>> matrica;

if(mat.size()==0 || mat.at(0).size()==0){
	red={};
	matrica.push_back(red);
}

 if(mat.size()!=0 && mat.at(0).size()!=0){
  for(int i=0;i<mat.size();i++){
     if(mat.at(0).size()!=mat.at(i).size()) throw std::domain_error("Matrica nije korektna");
  }


  if(mat.size()<3 || mat.at(0).size()<3){
  	double vrh(mat.at(0).at(0));
   	for(int i=0;i<mat.size();i++){
   		for(int j=0;j<mat.at(i).size();j++){
   			if(mat.at(i).at(j)>=vrh) {
   				vrh=mat.at(i).at(j);
   				k=i;
   				l=j;
   			}
   		}
   	}
   red.push_back(mat.at(k).at(l));
   matrica.push_back(red);
  }
  else{
	for(int i=1;i<mat.size()-1;i++){
		for(int j=1;j<mat.at(i).size()-1;j++){
			int br(1),n;
			double suma=mat.at(i-br).at(j-br)+mat.at(i-br).at(j)+mat.at(i-br).at(j+br)+mat.at(i).at(j-br)+
			      mat.at(i).at(j+br)+mat.at(i+br).at(j-br)+mat.at(i+br).at(j)+mat.at(i+br).at(j+br);
			if(mat.at(i).at(j)>suma){
				br++;
				n=3;
			
				while(i-br>=0 && i+br<mat.size() && j-br>=0 && j+br<mat.size()){
					double suma1(0);
				
					for(int x=i-br;x<=i+br;x++){
						for(int y=j-br;y<=j+br;y++){
							if((x==i-br || x==i+br) && (y>=j-br && y<=j+br)) suma1+=mat.at(x).at(y);
							if((y==j-br || y==j+br) && (x>i-br && x<i+br)) suma1+=mat.at(x).at(y);
						}
					}
                       
			        if(suma1<suma){
			        	br++;
			        	n+=2;
			        	suma=suma1;
			             
			        }
			        else break;
			        
			        
				}

		
			}	
		           	
		           	
		           	if(n==max){
		           		if(mat.at(i).at(j)>mat.at(k).at(l)){
		           			k=i;
		           			l=j;
		           			m=br;
		           		}
		           		if(mat.at(i).at(j)==mat.at(k).at(l)){
		           			if(i<k){
		           		    k=i;
		           			l=j;
		           			m=br;
		           			}
                            else if(i==k && j<l){
                            	
                            		k=i;
		           			        l=j;
		           			        m=br;
      
                            }		  
		           		}
		           	}
		           	else if(n>max){
				        max=n;
			         	k=i;
				        l=j;
			        	m=br;
			         }     
		}
		             
	}
	int a=m-max;
	int b=m-max;
	
	for(int i=k+a;i<k+a+max;i++){
		for(int j=l+b;j<l+a+max;j++){
			red.push_back(mat.at(i).at(j));
		}
		matrica.push_back(red);
		red.resize(0);
	}
  }
}
   
	return matrica;
}


int main ()
{
  try{
    int m,n;

	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
  
  try{
	
	std::vector<std::vector<double>> mat(m, std::vector<double> (n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>mat.at(i).at(j);
		}
	}
	
		
	std::vector<std::vector<double>>planina=NajvecaPlaninaMatrice(mat);
	
	
	std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
	for(int i=0;i<planina.size();i++){
		for(int j=0;j<planina.at(i).size();j++){
			std::cout<<std::setw(6)<<planina.at(i).at(j);
		}
		std::cout<<std::endl;
	}
  }
  
catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
  
  }
  
  
  catch(std::domain_error izuzetak){
  	std::cout<<izuzetak.what();
  }
	return 0;
}

