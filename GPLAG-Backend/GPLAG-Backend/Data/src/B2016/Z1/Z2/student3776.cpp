
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::vector<double>>Matrica;



void IspisiMatricu(Matrica Mat){
		for(auto red: Mat){
			for(auto x: red)
				std::cout<<std::setw(4)<<x;
				std::cout<<"\n";
		}			
}
Matrica Horizont(std::vector<std::vector<double>>M){
long long int m=M.size();
long long int n=M[0].size();
	Matrica M3(m,std::vector<double>(n,0));
    	for(int i=0;i<m;i++){
    		int k=0;
    		for(int j=n-1;j>=0;j--){
    			M3[i][k]=M[i][j];
    			k++;
		}
	}
		return M3;
}
Matrica Vertikal(std::vector<std::vector<double>>M) {
	long int  m=M.size();
	long int n=M[0].size();
	Matrica M3(m,std::vector<double>(n,0));
	for(int i=m-1,r=0;i>=0,r<m;i--,r++){
		for(int j=0;j<n;j++){
			M3[r][j]=M[i][j];
			
			}
		}
	return M3;
}

Matrica Kombajn (std::vector<std::vector<double>>M) {
	long int  m=M.size();
	long int n=M[0].size();
		Matrica M3(m,std::vector<double>(n,0));
	 M3=Vertikal(Horizont(M));
return M3;
}

Matrica OgledaloMatrica(Matrica M){
	long long int m,n;
	
 	if(!std::cin) {
 		throw std::range_error("Parametri matrice nekorektni!");
 	}
	if (M.size()!=0)  {
		m=M.size();  
		n=M[0].size();
	}
    	else {
		return Matrica(M.size(),std::vector<double>(0,0));
	}
	
	

	Matrica m1=Horizont(M);
	Matrica m0=M;
	Matrica m2=Vertikal(M);
	Matrica m3=Kombajn(M);
	const int rred=3*m;
	const int kol=3*n;
	std::vector<std::vector<double>> Ogledalce (rred,std::vector<double>(kol,0));
	
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            Ogledalce[i][j]=m3[i][j];
        }
    }
	for(int i=0;i<m;i++){
	    for(int j=n, k=0;j<2*n,k<n;k++,j++){
	        Ogledalce[i][j]=m2[i][k];
	    }
	}
	
	for(int i=0;i<m;i++){
	    for(int j=2*n,r=0;j<3*n,r<n;r++,j++){
	        Ogledalce[i][j]=m3[i][r];
	    }
	}
	
	for(int i=m, d=0;i<=2*m,d<m;d++,i++){
	    for(int j=0;j<n;j++){
	        Ogledalce[i][j]=m1[d][j];
	    }
	}
	for(int i=m,g=0;g<m,i<2*m;g++,i++){
	    for(int j=n,f=0;f<n,j<2*n;f++,j++){
	        Ogledalce[i][j]=m0[g][f];
	    }
	}
	
	for(int i=m,t=0;t<m,i<2*m;t++,i++){
	    for(int j=2*n,h=0;j<3*n,h<n;h++,j++){
	        Ogledalce[i][j]=m1[t][h];
	    }
	}
	for(int i=2*m,e=0;i<3*m,e<m;e++,i++){
	    for(int j=0,z=0;z<n,j<n;j++,z++){
	        Ogledalce[i][j]=m3[e][z];
	    }
	}
	for(int i=2*m,s=0;i<3*n,s<m;s++,i++){
	    for(int j=n,l=0;j<3*m,l<n;j++,l++){
	        Ogledalce[i][j]=m2[s][l];
	    }
	}
	
	for(int i=2*m,u=0;u<m,i<3*m;i++,u++){
	    for(int j=2*n,q=0;q<n,j<3*n;j++,q++){
	        Ogledalce[i][j]=m3[u][q];
	    }
	}
int O=Ogledalce.size();
		for(int i=0;i<O;i++)
		if(Ogledalce[0].size()!=Ogledalce[i].size() ) 	throw std::domain_error("Matrica nije korektna");
	return Ogledalce;
}

int main ()
{  
	
	std::cout<<"Unesite dimenzije matrice (m n): ";
    long long int m,n;
    try{
    	std::cin>>m>>n;
  	  if(m<0 or n<0 ){ std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
    std::vector<std::vector<double>> Mat1(m,std::vector<double>(n));
    std::cout<<"Unesite elemente matrice: "<<std::endl;
    for(long long int i=0;i<m;i++){
        for(long long int j=0;j<n;j++){
    	std::cin >> Mat1[i][j];
        }
    }
    std::cout<<"Rezultantna matrica: "<<std::endl;
    
	std::vector<std::vector<double>>Rezultantna(m,std::vector<double>(n));
		try{
		 Rezultantna=OgledaloMatrica(Mat1);
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
		
	}
	Rezultantna=OgledaloMatrica(Mat1);
	IspisiMatricu(Rezultantna);
    
    }
    catch(std::range_error izuzetak){
    		std::cout<<izuzetak.what();
    }
   /*for(;;){
    	std::cin>>m>>n;
    	if(std::cin) break;
    	std::cout<<"Esi mi dobar?"<<std::endl<<"Unesite dimenzije matrice (m n): ";
    	std::cin.clear();
    	std::cin.ignore(100000,'\n');
    }*/
  
	return 0;
}  