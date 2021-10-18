/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int br_redova, int br_kolona)
{
    return Matrica(br_redova, vector<double>(br_kolona));
}
Matrica UnesiMatricu(int m, int n){
	Matrica a(KreirajMatricu(m,n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}}
	return a;
}
Matrica OgledaloMatrica(Matrica a){
	Matrica m;
	if(a.size()==0) return m;
	for(int i=0;i<a.size()-1;i++){
		if(a[i].size()!=a[i+1].size()) throw std::domain_error("Matrica nije korektna");
	}
	Matrica mat(KreirajMatricu(3*a.size(),3*a[0].size()));
	Matrica h(KreirajMatricu(a.size(),a[0].size()));
	Matrica v(KreirajMatricu(a.size(),a[0].size()));
	Matrica hv(KreirajMatricu(a.size(),a[0].size()));
	for(int i=0;i<a.size();i++){
	for(int j=0;j<a[0].size();j++){
		h[i][a[0].size()-j-1]=a[i][j]; 
		v[a.size()-i-1][j]=a[i][j];
		hv[a.size()-i-1][a[0].size()-j-1]=a[i][j];
		}
	}
	for(int i=0;i<mat.size()/3;i++){
		for(int j=0;j<mat[0].size();j++){
			if(j<mat[0].size()/3){
			mat[i][j]=hv[i][j];	}
			if(j>=mat[0].size()/3 && j<2*mat[0].size()/3){
			mat[i][j]=v[i][j-mat[0].size()/3];}
			if(j>=2*mat[0].size()/3 && j<mat[0].size()){
			mat[i][j]=hv[i][j-2*mat[0].size()/3];}
		}
	}
	for(int i=mat.size()/3;i<2*mat.size()/3;i++){
		for(int j=0;j<mat[0].size();j++){
			if(j<mat[0].size()/3){
			mat[i][j]=h[i-mat.size()/3][j];	}
			if(j>=mat[0].size()/3 && j<2*mat[0].size()/3){
			mat[i][j]=a[i-mat.size()/3][j-mat[0].size()/3];}
			if(j>=2*mat[0].size()/3 && j<mat[0].size()){
			mat[i][j]=h[i-mat.size()/3][j-2*mat[0].size()/3];}
		}
	}
	for(int i=2*mat.size()/3;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			if(j<mat[0].size()/3){
			mat[i][j]=hv[i-2*mat.size()/3][j];	}
			if(j>=mat[0].size()/3 && j<2*mat[0].size()/3){
			mat[i][j]=v[i-2*mat.size()/3][j-mat[0].size()/3];}
			if(j>=2*mat[0].size()/3 && j<mat[0].size()){
			mat[i][j]=hv[i-2*mat.size()/3][j-2*mat[0].size()/3];}
		}
	}
	return mat;
	}
int main ()
{
	try{
	Matrica mat;
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0){ cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	cout<<"Unesite elemente matrice: ";
    mat=UnesiMatricu(m,n);
	Matrica velika=OgledaloMatrica(mat);
	cout<<endl<<"Rezultantna matrica:"<<endl;
	for(int i=0;i<velika.size();i++){
		cout<<" ";
		for(int j=0;j<velika[0].size();j++){
			cout<<setw(3)<<velika[i][j]<<" ";
		}
		cout<<endl;
	}}
	catch(std::domain_error izuzetak){cout<<izuzetak.what()<<endl;}
	return 0;
}