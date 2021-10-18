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

std::vector<std::vector<double> > OgledaloMatrica(std::vector<std::vector<double> > mat){
	int m=mat.size(), n;
	if(m==0){
		return mat;
	}
	n=mat[0].size();
	for(auto i:mat){
		if(i.size()!=n)throw std::domain_error("Matrica nije korektna");
	}
	std::vector<std::vector<double> > r;
	std::vector<double> temp;
	for(int i=0;i<3*m;i++){
		r.push_back(temp);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			r[i].push_back(mat[m-i-1][n-j-1]);
			r[2*m+i].push_back(mat[m-i-1][n-j-1]);
			r[m+i].push_back(mat[i][n-j-1]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			r[i].push_back(mat[m-i-1][j]);
			r[2*m+i].push_back(mat[m-i-1][j]);
			r[m+i].push_back(mat[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			r[i].push_back(mat[m-i-1][n-j-1]);
			r[2*m+i].push_back(mat[m-i-1][n-j-1]);
			r[m+i].push_back(mat[i][n-j-1]);
		}
	}
	return r;
}

int main ()
{
	int n, m;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double> > a(m, std::vector<double> (n));
	std::cout<<"Unesite elemente matrice:\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>a[i][j];
		}
	}
	std::vector<std::vector<double> > r=OgledaloMatrica(a);
	std::cout<<"Rezultantna matrica:\n";
	for(auto i:r){
		for(auto j:i){
			std::cout<<std::setw(4)<<std::right<<j;
		}
		std::cout<<"\n";
	}
	return 0;
}