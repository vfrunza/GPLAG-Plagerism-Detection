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
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::move;
using std::setw;
using std::domain_error;

typedef vector<vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica mat){
	int br_kolona;
	if(mat.size()==0){
		return mat;
	}
	if(mat.size()>0 && mat[0].size()==0){
		return Matrica(3*mat.size(),vector<double> (3*(mat[0].size())));
	}
	if(mat.size()>0){
		br_kolona=mat[0].size();
	}
	for(int i=0;i<mat.size();i++){
		if(mat[i].size()!=br_kolona){
			throw domain_error("Matrica nije korektna");
		}
	}
	Matrica v(mat);
	for(int i=0;i<v.size()/2;i++){
		vector<double> pomocni=move(v[i]);
		v[i]=move(v[v.size()-1-i]);
		v[v.size()-1-i]=move(pomocni);
	}
	Matrica h(mat);
	for(int i=0;i<h.size();i++){
		for(int j=0;j<h[i].size()/2;j++){
			double pomocni=h[i][j];
			h[i][j]=h[i][h[i].size()-1-j];
			h[i][h[i].size()-1-j]=pomocni;
		}
	}
	Matrica hv(h);
	for(int i=0;i<hv.size()/2;i++){
		vector<double> pomocni=move(hv[i]);
		hv[i]=move(hv[hv.size()-1-i]);
		hv[hv.size()-1-i]=move(pomocni);
	}

	Matrica mat1(3*mat.size(),vector<double> (3*(mat[0].size())));
	for(int i=0;i<hv.size();i++){
		for(int j=0;j<hv[i].size();j++){
			mat1[i][j]=hv[i][j];
			mat1[i][j+2*hv[i].size()]=hv[i][j];
			
			mat1[i+2*hv.size()][j]=hv[i][j];
			mat1[i+2*hv.size()][j+2*hv[i].size()]=hv[i][j];
		}
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			mat1[i][j+v[i].size()]=v[i][j];
			mat1[i+2*v.size()][j+v[i].size()]=v[i][j];
		}
	}
	for(int i=0;i<h.size();i++){
		for(int j=0;j<h[i].size();j++){
			mat1[i+hv.size()][j]=h[i][j];
			mat1[i+hv.size()][j+h[i].size()+mat[i].size()]=h[i][j];
		}
	}
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			mat1[i+hv.size()][j+h[i].size()]=mat[i][j];
		}
	}
	return mat1;
}

int main ()
{
	try{
		int m,n;
		cout<<"Unesite dimenzije matrice (m n): ";
		cin>>m;
		cin>>n;
		if(m<0 || n<0){
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		cout<<"Unesite elemente matrice: ";
		Matrica mat(m,vector<double>(n));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>mat[i][j];
			}
		}
		Matrica mat1=OgledaloMatrica(mat);
		cout<<endl<<"Rezultantna matrica:";
		for(int i=0;i<mat1.size();i++){
			cout<<endl;
			for(int j=0;j<mat1[i].size();j++){
				cout<<setw(4)<<mat1[i][j];
			}
		}
	}
	catch(domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}
	return 0;
}