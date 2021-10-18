#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

bool Jel_grbava (Matrica a) {
	for(int i=1;i<a.size();i++) {
		if(a[i].size()!=a[0].size()) return true;
	}
	return false;
}

Matrica ver_ogledana (Matrica a) {
	Matrica a1(a.size(),std::vector<double>(a[0].size()));
	int k=0;
	for(int i=a.size()-1;i>=0;i--) {
		for(int j=0;j<a[0].size();j++) 
			a1[k][j]=a[i][j];
			k++;
		
	}
	return a1;
}

Matrica hor_ogledana (Matrica a) {
	Matrica a1(a.size(),std::vector<double>(a[0].size()));
	for(int i=0;i<a.size();i++) {
		int k=0;
		for(int j=a[0].size()-1;j>=0;j--) {
			a1[i][k]=a[i][j];
			k++;
		}
	}
	return a1;
}

Matrica komb_ogledana (Matrica a) {
	a=hor_ogledana(a);
	Matrica a1(a.size(),std::vector<double>(a[0].size()));
	int k=0;
	for(int i=a.size()-1;i>=0;i--) {
		for(int j=0;j<a[0].size();j++) 
			a1[k][j]=a[i][j];
			k++;

	}
	return a1;
}

Matrica OgledaloMatrica (Matrica a1) {
	if(a1.size()==0) return a1;
	if(Jel_grbava(a1)==true) throw std::domain_error("Matrica nije korektna");
	Matrica a(3*a1.size(),std::vector<double>(a1[0].size()*3));
	Matrica o=hor_ogledana(a1);
	Matrica m=ver_ogledana(a1);
	Matrica g=komb_ogledana(a1);
	if(a1.size()==1 and a1[0].size()==1) {
		for(int i=0;i<a.size();i++) {
			for(int j=0;j<a[0].size();j++) a[i][j]=a1[0][0] ;
		}
		return a ;
	}
	int d=0;
	for(int i=0;i<a.size();i++) {
		int k=0;
		for(int j=0;j<g[0].size();j++) {
			if(i<a.size()/3 || i>=2*a.size()/3) {
				if(k<a[0].size()/3 || k>=2*a[0].size()/3) a[i][k]=g[d][j];
				else if(k>=a[0].size()/3 and k<2*a[0].size()/3) a[i][k]=m[d][j];
			}
			else if(i>=a.size()/3 and i<2*a.size()/3) {
				if(k<a[0].size()/3 || k>=2*a[0].size()/3) a[i][k]=o[d][j];
				else if(k>=a[0].size()/3 and k<2*a[0].size()/3) a[i][k]=a1[d][j];
			}
			k++;
			if(k==a[0].size()/3 or k==2*a[0].size()/3) j=-1;
		}
		d++;
		if(d==g.size()) d=0;
	}
	return a;
}

int main () {
	std::cout << "Unesite dimenzije matrice (m n): " ;
	int m,n;
	std::cin >> m >> n ;
	if(m<0 or n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica a(m,std::vector<double>(n));
	std::cout << "Unesite elemente matrice: " ;	
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			int d;
			std::cin >> d ;
			a[i][j]=d;
		}
	} 
	std::cout << std::endl << "Rezultantna matrica: " << std::endl ;
	if(n==0) {
		for(int i=0;i<=m*3;i++) {
			std::cout << std::endl;
		}
		return 0;
	}
	try {
		a=OgledaloMatrica(a);
		/*for(int i=0;i<a.size();i++) {
			for(int j=0;j<a[i].size();j++) {
				std::cout << std::setw(4) << a[i][j] ;
			}
			std::cout << std::endl; */
		}
	// }
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() ;
		return 0;
	}
	for(int i=0;i<a.size();i++) {
			for(int j=0;j<a[i].size();j++) {
				std::cout << std::setw(4) << a[i][j] ;
			}
			std::cout << std::endl;
	return 0;
}