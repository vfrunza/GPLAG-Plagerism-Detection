/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
typedef std::vector<std::vector<double>> MATRICA;
typedef std::vector<double> vektor;
MATRICA horizontalna(MATRICA mat){
	MATRICA hm(mat.size(),vektor(mat[0].size()));
	int g;
	for(int i=0; i<mat.size(); i++){
		g=mat[0].size()-1;
		for(int j=0; j<mat[0].size(); j++){
			hm[i][j]=mat[i][g];
			g--;
		}
	}
	return hm;
}
MATRICA vertikalna(MATRICA mat){
	MATRICA vm(mat.size(),vektor(mat[0].size()));
	int g(mat.size()-1);
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[0].size(); j++){
			vm[i][j]=mat[g][j];
			
		}
		g--;
	}
	return vm;
}
MATRICA OgledaloMatrica(MATRICA matrica){
	int m=matrica.size();
	if(m==0) return MATRICA();
	for(int i=0; i<matrica.size()-1; i++)
		if(matrica[i].size()!=matrica[i+1].size()) throw std::domain_error("Matrica nije korektna");
	int n=matrica[0].size();
	MATRICA mat((m*3),vektor((n*3),0));
	if(n==0) return mat;
	auto hm(horizontalna(matrica));
	auto vm(vertikalna(matrica));
	auto hvm(horizontalna(vm));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			mat[i][j]=hvm[i][j];
			mat[i+2*m][j]=hvm[i][j];
			mat[i][j+2*n]=hvm[i][j];
			mat[i+2*m][j+2*n]=hvm[i][j];
		}
	for(int i=0; i<m; i++)
		for(int j=n; j<2*n; j++){
			mat[i][j]=vm[i][j-n];
			mat[i+2*m][j]=vm[i][j-n];
		}
	for(int i=m; i<2*m; i++)
		for(int j=0; j<n; j++){
			mat[i][j]=hm[i-m][j];
			mat[i][j+2*n]=hm[i-m][j];
		}
	for(int i=m; i<2*m; i++)
		for(int j=n; j<2*n; j++){
			mat[i][j]=matrica[i-m][j-n];
		}
	return mat;
}
int main ()
{
	try{
		int m, n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<<"Unesite elemente matrice: ";
	MATRICA mat(m,vektor(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>mat[i][j];
	MATRICA Matrica;
	Matrica=OgledaloMatrica(mat);
	cout<<endl<<"Rezultantna matrica: "<<endl;
	for(int i=0; i<3*m; i++){
		for(int j=0; j<3*n; j++)
			cout<<std::setw(4)<<Matrica[i][j];
		cout<<endl;
	}}
	catch(std::domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}
	return 0;
}