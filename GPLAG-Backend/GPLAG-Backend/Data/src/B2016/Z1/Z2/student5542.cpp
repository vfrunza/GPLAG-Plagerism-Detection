#include <iostream>
#include <vector> 
#include <iomanip>
#include <stdexcept>

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> m) {
	for(int i(0); i<m.size(); i++) {
		if(m[i].size()!=m[0].size()) { throw std::domain_error("Matrica nije korektna"); break; }
	}
	if(m.size()==0) {
		std::vector<std::vector<double>> n(0,std::vector<double>(0));
		return n;
	}

	
	
	else {
	std::vector<std::vector<double>> h(m.size(), std::vector<double>(m[0].size())), 
	v(m.size(), std::vector<double>(m[0].size())), hv(m.size(), std::vector<double>(m[0].size())), n(3*m.size(), std::vector<double>(3*m[0].size()));
	
	
	
	int brojredova=m.size();
	int brojkolona=m[0].size();
	
	for(int i=0; i< m.size(); i++) {
		brojkolona=m[0].size();
		for(int j=0; j<m[0].size(); j++) {
			
		h[i][j]=m[i][brojkolona-1];
		brojkolona--;
		
		}
	}
	
	brojkolona=m[0].size();
	
	for(int i=0; i< m.size(); i++) {
		for(int j=0; j<m[0].size(); j++) {
			
		v[i][j]=m[brojredova-1][j];
		}
		brojredova--;
		
	}
	
	brojredova=m.size();
	brojkolona=m[0].size();
	std::vector<std::vector<double>> p(m.size(), std::vector<double>(m[0].size()));
	
	for(int i=0; i< m.size(); i++) {
		brojkolona=m[0].size();
		for(int j=0; j<m[0].size(); j++) {
			
		p[i][j]=m[i][brojkolona-1];
		brojkolona--;
		
		}
	}

	brojkolona=m[0].size();
	
	
	for(int i=0; i< m.size(); i++) {
		for(int j=0; j<m[0].size(); j++) {
			
		hv[i][j]=p[brojredova-1][j];
		}
		brojredova--;
		
	}
    
	int z(0), q(0);
	for(int i=0; i<hv.size(); i++) {
		for(int j=0; j<hv[0].size(); j++) {
			
			n[i][j]=hv[i][j];
			}
	}
	
	for(int i=0; i<v.size(); i++) {
		q=0;
		for(int j=hv[0].size(); j<hv[0].size()+v[0].size(); j++) {
			n[i][j]=v[z][q];
			q++;
		}
		z++;
	}
	z=0;
	for(int i=0; i<hv.size(); i++) {
		q=0;
		for(int j=hv[0].size()+v[0].size(); j<hv[0].size()+v[0].size()+hv[0].size(); j++) {
			n[i][j]=hv[z][q];
			q++;
		}
		z++;
	}
	z=0;
	for(int i=hv.size(); i<hv.size()+hv.size(); i++) {
		q=0;
		for(int j=0; j<hv[0].size(); j++) {
			n[i][j]=h[z][q];
			q++;
		}
		z++;
	}
	z=0;
	for(int i=hv.size(); i<hv.size()+hv.size(); i++) {
		q=0;
		for(int j=hv[0].size(); j<hv[0].size()+hv[0].size(); j++) {
			n[i][j]=m[z][q];
			q++;
		}
		z++;
	}
	z=0;
	for(int i=hv.size(); i<hv.size()+hv.size(); i++) {
		q=0;
		for(int j=hv[0].size()+hv[0].size(); j<hv[0].size()+hv[0].size()+hv[0].size(); j++) {
			n[i][j]=h[z][q];
			q++;
		}
		z++;
	}
	
	z=0;
	for(int i=hv.size()+hv.size(); i<hv.size()+hv.size()+hv.size(); i++) {
		q=0;
		for(int j=0; j<hv[0].size(); j++) {
			n[i][j]=hv[z][q];
			q++;
		}
		z++;
	}
	z=0;
	for(int i=hv.size()+hv.size(); i<hv.size()+hv.size()+hv.size(); i++) {
		q=0;
		for(int j=hv[0].size(); j<hv[0].size()+hv[0].size(); j++) {
			n[i][j]=v[z][q];
			q++;
		}
		z++;
	}
	z=0;
	for(int i=hv.size()+hv.size(); i<hv.size()+hv.size()+hv.size(); i++) {
		q=0;
		for(int j=hv[0].size()+hv[0].size(); j<hv[0].size()+hv[0].size()+hv[0].size(); j++) {
			n[i][j]=hv[z][q];
			q++;
		}
		z++;
	}

	
	return n;
}
}

int main ()
{ 
	try {
	int m,n;
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if(m<0 || n<0) 
	std::cout << "Dimenzije matrice moraju biti nenegativne!";
	else {
	std::vector<std::vector<double>> matrica(m, std::vector<double> (n)), mat2;
	
	
	std::cout << "Unesite elemente matrice: " << std::endl;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> matrica[i][j];
		}
	} 
	
	
	mat2=OgledaloMatrica(matrica);
	

	
	std::cout << "Rezultantna matrica: " << std::endl;
	
	for(int i=0; i<mat2.size(); i++) {
		for(int j=0; j<mat2[0].size(); j++) {
			std::cout << std::setw(4) << mat2[i][j];
		}
		std::cout << std::endl;
	}
	}
	
	
	return 0; 
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
}