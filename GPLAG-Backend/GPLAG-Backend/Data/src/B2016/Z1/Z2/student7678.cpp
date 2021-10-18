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
using std::setw;


typedef vector<vector<double>> matrica;
typedef vector<double> vec;

matrica HorizontalnoOgledalo(matrica m){
	int broj_redova=m.size();
	int broj_kolona=m[0].size();
	
	matrica nova(broj_redova,vec(broj_kolona));
	
	for(int i=0; i<broj_redova; i++){
		for(int j=0; j<broj_kolona; j++){
			nova[i][broj_kolona-j-1]=m[i][j];
		}
	}
	
	return nova;
}

matrica VertikalnoOgledalo (matrica m){
	int broj_redova=m.size();
	int broj_kolona=m[0].size();
	
	matrica nova(broj_redova,vec(broj_kolona));;
	
	for(int i=0; i<broj_redova; i++){
		for(int j=0; j<broj_kolona; j++){
			nova[broj_redova-1-i][j]=m[i][j];
		}
	}
	
	return nova;
}

matrica KombinovanoOgledalo(matrica m){
	int broj_redova=m.size();
	int broj_kolona=m[0].size();
	
	matrica nova(broj_redova,vec(broj_kolona));
	matrica medju_matrica(broj_redova,vec(broj_kolona));
	
	medju_matrica=HorizontalnoOgledalo(m);
	nova=VertikalnoOgledalo(medju_matrica);
	
	return nova;
}

matrica OgledaloMatrica(matrica mat){
	
	int broj_redova=mat.size();
	if(broj_redova==0)return mat;
	int broj_kolona=mat[0].size();
	int m=broj_redova;
	int n=broj_kolona;
	
	int isti=0;
	for(int i=0; i<m-1; i++){
		if(mat[i].size()==mat[i+1].size()){isti++; continue;}
		else break;
	}
	
	if(isti!=(mat.size()-1))throw std::domain_error("Matrica nije korektna");
	
	
	matrica hv(m,vec(n));
	matrica v(m,vec(n));
	matrica h(m,vec(n));
	hv=KombinovanoOgledalo(mat);
	v=VertikalnoOgledalo(mat);
	h=HorizontalnoOgledalo(mat);
	matrica nova(3*broj_redova,vec(3*broj_kolona));
	
	for(int i=0; i<3*m; i++){
		for(int j=0; j<3*n; j++){
			if(i<m && j<n){nova[i][j]=hv[i][j];}
			if(i>=m && i<2*m && j<n){nova[i][j]=h[i-m][j];}
			if(i>=2*m && i<3*m && j<n){nova[i][j]=hv[i-2*m][j];}
			if(i<m && j>=n && j<2*n)nova[i][j]=v[i][j-n];
			if(i>=m && i<2*m && j>=n && j<2*n)nova[i][j]=mat[i-m][j-n];
			if(i>=2*m && i<3*m && j>=n && j<2*n)nova[i][j]=v[i-2*m][j-n];
			if(i<m && j>=2*n && j<3*n)nova[i][j]=hv[i][j-2*n];
			if(i>=m && i<2*m && j>=2*n && j<3*n)nova[i][j]=h[i-m][j-2*n];
			if(i>=2*m && i<3*m && j>=2*n && j<3*n)nova[i][j]=hv[i-2*m][j-2*n];
		}
	}
	
	return nova;
	
	
	
}

int main ()
{
	try{
	int m,n;
	
	matrica rez;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0){cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	matrica mat(m,vec(n));
	cout<<"Unesite elemente matrice: "<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>mat[i][j];
		}
	}
	
	rez=OgledaloMatrica(mat);
	cout<<"Rezultantna matrica: "<<endl;
	for(int i=0; i<3*m; i++){
		for(int j=0; j<3*n; j++){
			cout<<setw(4)<<rez[i][j];
		}
		cout<<endl;
	}
	}
	
	catch(std::domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}
	
	return 0;
}