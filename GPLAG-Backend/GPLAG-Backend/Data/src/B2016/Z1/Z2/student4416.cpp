/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include<vector>
#include<stdexcept>
#include<iomanip>
typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica;
Matrica OgledaloMatrica (Matrica a){
	int m(a.size());
	int n;
	if(m!=0) n=a[0].size();
	else n = 0;
	for(int i=0;i<m;i++) if(a[i].size()!=n) throw std::domain_error("Matrica nije korektna");
	Matrica b(3*m,Vektor(3*n));
	Matrica h(m,Vektor(n)),hv(m,Vektor(n)),v(m,Vektor(n));
	int i,j,k,l;
	for(i=0;i<m;i++){
		v[i]=a[m-1-i];
		}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			h[i][j]=a[i][n-1-j];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			hv[i][j]=v[i][n-1-j];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++) b[i][j]=hv[i][j];
		for(k=0;k<n;k++) b[i][k+j]=v[i][k];
		for(l=0;l<n;l++) b[i][l+k+j]=hv[i][l];
	}
	for(i=m;i<2*m;i++){
		for(j=0;j<n;j++) b[i][j]=h[i-m][j];
		for(k=0;k<n;k++) b[i][k+j]=a[i-m][k];
		for(l=0;l<n;l++) b[i][l+k+j]=h[i-m][l];
	}
	for(i=2*m;i<3*m;i++){
		for(j=0;j<n;j++) b[i][j]=hv[i-2*m][j];
		for(k=0;k<n;k++) b[i][k+j]=v[i-2*m][k];
		for(l=0;l<n;l++) b[i][l+k+j]=hv[i-2*m][l];
	}
	return b;
}
int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || m<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica a(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice:\n";
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++) std::cin>>a[i][j];
	}
	auto b(OgledaloMatrica(a));
	std::cout<<"Rezultantna matrica:\n";
	for(i=0;i<3*m;i++){
		for(j=0;j<3*n;j++){
			std::cout<<std::setw(4)<<b[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}