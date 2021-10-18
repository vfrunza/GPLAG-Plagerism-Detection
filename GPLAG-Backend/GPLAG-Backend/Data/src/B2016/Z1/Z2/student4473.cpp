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

matrica KreirajMatricu(int broj_redova,int broj_kolona){
	return matrica(broj_redova,std::vector<double>(broj_kolona));
}
matrica OgledaloMatrica (matrica a){
	if(a.size()==0)
		return a;
	int m(a.size()),n(a[0].size());
	matrica glavna(KreirajMatricu(3*m,3*n));
	//if(m==0) return glavna.resize(0);
	matrica hv(KreirajMatricu(m,n)),v(KreirajMatricu(m,n));
	matrica h(KreirajMatricu(m,n));
	for(int i=0;i<m-1;i++){
		for(int j=0;j<n;j++){
			if(a[i].size()!=a.at(i+1).size()) 
			throw std::domain_error ("Matrica nije korektna.");
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			v[i][j]=a[m-1-i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			h[i][j]=a[i][n-1-j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			hv[i][j]=a[m-1-i][n-1-j];
		}
	}
	for(int i=0;i<3*m;i++){
		for(int j=0;j<3*n;j++){
			if(i<m and j<n)	glavna[i][j]=hv[i][j];
			else if(i<m and j>=n and j<2*n)	glavna[i][j]=v[i%m][j%n];
			else if(i<m and j>=2*n and j<3*n) glavna[i][j]=hv[i%m][j%n];
			else if(i>=m and i<2*m and j<n) glavna[i][j]=h[i%m][j%n];
			else if(i>=m and i<2*m and j>=n and j<2*n) glavna[i][j]=a[i%m][j%n];
			else if(i>=m and i<2*m and j>=2*n) glavna[i][j]=h[i%m][j%n];
			else if(i>=2*m and j<n) glavna[i][j]=hv[i%m][j%n];
			else if(i>=2*m and j>=n and j<2*n) glavna[i][j]=v[i%m][j%n];
			else if(i>=2*m and j>=2*n) glavna[i][j]=hv[i%m][j%n];
		}
	}
	
	return glavna;
}

int main ()
{	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 or n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrica glavna(KreirajMatricu(m,n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		std::cin>>glavna[i][j];
	}
	matrica novamatrica;
	try{
	novamatrica=OgledaloMatrica(glavna);	
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	for(auto red:novamatrica){
		for(auto x:red)
			std::cout<<std::setw(4)<<x;
			std::cout<<std::endl;
	}
	return 0;
}