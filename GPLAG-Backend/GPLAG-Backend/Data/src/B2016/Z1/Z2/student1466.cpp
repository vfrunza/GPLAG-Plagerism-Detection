#include<iostream>
#include<vector>
#include<iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double> > Matrica;

Matrica KreirajMatricu (int m, int n) {
	
	
	return Matrica (m, std::vector<double> (n));
	
}
void IspisiMatricu (Matrica m) {

for (int i = 0; i < m.size(); i++) {

for (int j = 0; j < m[0].size(); j++)  {
	
	std::cout<<std::setw(4)<<m[i][j];
	

}
std::cout<<std::endl;
}
		
}

Matrica UnesiMatricu (int m, int n) {
	
	Matrica b (KreirajMatricu(m,n));
	
	for (int i = 0; i<m ; i++) {
	
	for (int j = 0; j<n; j++)  {

	std::cin>>b[i][j];
	
	}
	}
 return b;
}
			




Matrica OgledaloMatrica(Matrica a) {

	

if (a.size()==0) return Matrica(0,std::vector<double>(0));

int sir = a[0].size();
for (int i=1; i< a.size(); i++) {
	
	if (a[i].size() != sir) {
		
		throw std::domain_error("Matrica nije korektna");
	}
	
}





Matrica m=KreirajMatricu(3*a.size(),3*a[0].size());	

			for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       						m[i][j]=a[a.size()-1-i][a[0].size()-1-j];
	}
	    
    
    
    
    			for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       					    m[i][j+a[0].size()]=a[a.size()-1-i][j];
	}
	
	
			for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       						m[i][j+2*a[0].size()]=a[a.size()-1-i][a[0].size()-1-j];
	}
	
		for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       						m[i+a.size()][j]=a[i][a[0].size()-1-j];
	}
	
		for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       						m[i+a.size()][j+a[0].size()]=a[i][j];
	}
	
	for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       						m[i+a.size()][j+2*a[0].size()]=a[i][a[0].size()-1-j];
	}
	
	
		for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       						m[i+2*a.size()][j]=a[a.size()-1-i][a[0].size()-1-j];
	}
	    
    
    
    
    			for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       					    m[i+2*a.size()][j+a[0].size()]=a[a.size()-1-i][j];
	}
	
	
			for (int i = 0; i<a.size(); i++) 
       					for (int j = 0; j<a[0].size(); j++) {
       	
       						m[i+2*a.size()][j+2*a[0].size()]=a[a.size()-1-i][a[0].size()-1-j];
       						
       							}
	

	return m;
	
}
			








int main ()
{


std::cout<<"Unesite dimenzije matrice (m n): ";

int m, n;

std::cin>>m;
std::cin>>n;

if(m<0  || n<0) {
	
	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
	
}




std::cout<<"Unesite elemente matrice: "<<std::endl;

try {

Matrica x=UnesiMatricu(m,n);



std::cout<<"Rezultantna matrica: "<<std::endl;


Matrica y=UnesiMatricu(3*m,3*n);

IspisiMatricu(OgledaloMatrica(x));

}

catch (std::domain_error izuzetak) {
	
	std::cout<<izuzetak.what();
	
}
return 0;
}
