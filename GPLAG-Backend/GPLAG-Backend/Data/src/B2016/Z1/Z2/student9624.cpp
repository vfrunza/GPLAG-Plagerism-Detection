/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include<stdexcept>
typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> matrica;

matrica KreirajMatricu(int m , int n){
	return matrica(m , vektor(n));
}

matrica UnesiMatricu(int m , int n){
	auto x(KreirajMatricu(m,n));
for(int i=0 ; i<x.size(); i++)
			for(int j=0 ; j<x[i].size(); j++)
			std::cin>>x[i][j];
			return x;
	
}
matrica HorizontalnoOgledalo(matrica m){
	for(int i=0 ; i<m.size(); i++){
			for(int j=0 ; j<m[i].size()/2; j++){
				double x(m[i][j]);
				m[i][j]=m[i][m[i].size()-1-j];
				m[i][m[i].size()-1-j]=x;
			}
	}
	return m;
}

matrica VertikalnoOgledalo(matrica m){
	for(int i=0 ; i<m.size()/2; i++){
			for(int j=0 ; j<m[i].size(); j++){
				double x(m[i][j]);
				m[i][j]=m[m.size()-1-i][j];
				m[m.size()-1-i][j]=x;
			}
	}
		
	return m;
}

matrica OgledaloMatrica(matrica m){
	
	int d, s;
	
	if(m.size()==0 ){ 
	    d=0;
		s=0; 
		
	}
	if(m.size()>0 && m[0].size()==0){
		d=m.size();
		s=0;
	}
	else if(m.size()>0 && m[0].size()>0) {
	d=m.size();
	s=m[0].size();
	}
	matrica mat(3*d,vektor(3*s));
	matrica v=VertikalnoOgledalo(m);
	matrica h=HorizontalnoOgledalo(m);
	matrica hv=VertikalnoOgledalo(HorizontalnoOgledalo(m));
	
    for(int i = 0 ; i < d ; i++){
    	for(int j = 0 ; j < (3*s) ; j++){
    		if(m[i].size()!=s) throw std::domain_error ("Matrica nije korektna");
    		if(j<s) mat[i][j]=hv[i][j];
    		if(j>=s && j<(2*s)) mat[i][j]=v[i][j-s];
    		if(j>=(2*s)) mat[i][j]=hv[i][j-(s*2)];
    	}
    }
 
   for(int i = d ; i < (2*d) ; i++){
    	for(int j = 0 ; j < (3*s) ; j++){
    		if(m[i-d].size()!=s) throw std::domain_error ("Matrica nije korektna");
    		if(j<s) mat[i][j]=h[i-d][j];
    		if(j>=s && j<(2*s)) mat[i][j]=m[i-d][j-s];
    		if(j>=(2*s)) mat[i][j]=h[i-d][j-(s*2)];
    	}
    }
    
      for(int i = (2*d) ; i < (3*d) ; i++){
    	for(int j = 0 ; j < (3*s) ; j++){
    		if(m[i-(2*d)].size()!=s) throw std::domain_error ("Matrica nije korektna");
    		if(j<s) mat[i][j]=hv[i-(2*d)][j];
    		if(j>=s && j<(2*s)) mat[i][j]=v[i-(2*d)][j-s];
    		if(j>=(2*s)) mat[i][j]=hv[i-(2*d)][j-(s*2)];
    	}
    }
	return mat;
}
int main ()
{
	 try {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m >>n;
	if(m<0 || n<0) throw std::domain_error ("Dimenzije matrice moraju biti nenegativne!");
	
		std::cout<<"Unesite elemente matrice:";
	    matrica x(0);
		x=UnesiMatricu(m,n);
		matrica y(0);
		y=OgledaloMatrica(x);
		std::cout<<std::endl<<"Rezultantna matrica: ";
		std::cout<<std::endl;
		 for(int i=0 ; i<y.size(); i++){
			for(int j=0 ; j<y[i].size(); j++){
				std::cout<<std::setw(4)<<y[i][j];
			}
			std::cout<<std::endl;
		 }
	}
	
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}