/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> matrica;

matrica horizontalna (matrica a){
	matrica m(a);
	int r,k;
	double x;
	r=a.size();
	k=a[0].size();
	m=a;
	for( int i(0);i<r;i++){
		for(int j(0);j<k/2;j++){
			x=m[i][j];
			m[i][j]=m[i][k-1-j];
			m[i][k-1-j]=x;
		}
	}
	return m;
	
}

matrica vertikalna (matrica a){
	matrica m(a);
	double x;
	int r,k;
	r=a.size();
	k=a[0].size();
	for(int i(0); i<r/2;i++){
		for(int j(0); j<k;j++){
			x=m[i][j];
			m[i][j]=m[r-1-i][j];
			m[r-1-i][j]=x;
		
	}
}
return m;
}

matrica OgledaloMatrica (matrica a){
	for(int i(1);i<a.size();i++){
		if(a[i].size()!= a[0].size() ) throw std::domain_error ("Matrica nije korektna");
	}
	int x, y;
	x=3 * a.size();
	if(a.size()!=0) y=3 * a[0].size();
	else y=0;
	std::vector<std::vector<double>> m (x, std::vector<double> (y)) ;
	if(a.size()==0) return m;
	matrica v,h,vh;
	v=vertikalna(a);
	h=horizontalna(a);
	vh=horizontalna(vertikalna(a));
	int r,k;
	r=a.size();
	k=a[0].size();
	for(int i(0);i<r;i++){
		for(int j(0);j<k;j++){
			m[i][j]=vh[i][j];
			m[i][2*k+j]=vh[i][j];
			m[2*r+i][j]=vh[i][j];
			m[2*r+i][2*k+j]=vh[i][j];
			m[i][k+j]=v[i][j];
			m[2*r+i][k+j]=v[i][j];
			m[r+i][k+j]=a[i][j];
			m[r+i][j]=h[i][j];
			m[r+i][2*k+j]=h[i][j];
		}
	}
	
	return m;
	
	
}

int main ()
{
	try{
	int m, n;
	double x;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m>>n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	matrica a(m,std::vector<double> (n));
	std::cout << "Unesite elemente matrice:" << std::endl;
	for(int i(0); i<m;i++){
		for(int j(0);j<n;j++){
			std::cin >> x;
			a[i][j]=x;
		}
	}
	
	matrica q (3*m, std::vector<double> (3*n));
	q=OgledaloMatrica(a);
	std::cout <<  std::endl;
	std::cout << "Rezultantna matrica:" << std::endl;
	for(int i(0);i<3*m;i++){
		for(int j(0);j<3*n;j++){
			std::cout << std::setw(4)<<q[i][j];
		}
		std::cout << std::endl;
	}
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}