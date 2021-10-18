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
typedef std:: vector<double> vektor;
typedef std:: vector<std:: vector<double>> matrica;
using std:: cin;
using std :: cout;
using std:: endl;

matrica vertikalna (matrica m){
	int s;
	if(m.size()==0){
	  s=0;
	}
	else s=m[0].size();

	matrica n(m.size(), vektor(s));
	int k(0);
	for(int j=m.size()-1; j>=0; j--){
			n[k]=m[j];
			k++;
		}
	
	return n;
	
}
matrica horizontalna(matrica m){
	

	int s;
	if(m.size()==0){
	  s=0;
	}
	else s=m[0].size();
	
	matrica n(m.size(), vektor(s));
	
		for (int i=0; i<m.size(); i++){
			int p=(0);
			for(int j=m.at(i).size()-1; j>=0; j--){
				for(int k=p; k<m.at(i).size(); k++){
						n[i][k]=m[i][j];
						p++;
						break;
				}
    		 }

		}
	
		return n;}

matrica OgledaloMatrica(matrica m){
	int s;
	if(m.size()==0){
	  s=0;
	}
	else s=m[0].size();
	int grbava (0);
	for(int p=0; p<m.size(); p++){
		if(m[p].size()!=m[0].size()) grbava=1;
	}
	if(grbava==1)  throw std :: domain_error("Matrica nije korektna");
	matrica M (3*m.size(), vektor(3*s));
	matrica hv (horizontalna(vertikalna (m)));
	int i, k, j(0);
	for (i=0; i < m.size(); i++){
		for (j=0; j<m.at(i).size(); j++){
			M[i][j]=hv[i][j];
		}
	}
		matrica v(vertikalna(m));
	for (i=0; i < m.size(); i++){
		for (k=j; k<2*m.at(i).size(); k++){
			M[i][k]=v[i][k-j];
		}
	}
	
	for (i=0; i < m.size(); i++){
		for (j=k; j<3*m.at(i).size(); j++){
			M[i][j]=hv[i][j-k];
		}
	}

	int l;
	matrica h(horizontalna(m));
	for (l=i; l<2*m.size(); l++){
		for (j=0; j<m.at(l-i).size(); j++){
			M[l][j]=h[l-i][j];
		}
	}
		for (l=i; l<2*m.size(); l++){
			for (k=j; k<2*m.at(l-i).size(); k++){
			M[l][k]=m[l-i][k-j];
		}
	}
	for (l=i; l<2*m.size(); l++){
		for (j=k; j<3*m.at(l-i).size(); j++){
			M[l][j]=h[l-i][j-k];
		}
		
	}
	for(i=l; i<3*m.size(); i++){
		for (j=0; j<m.at(i-l).size(); j++){
			M[i][j]=hv[i-l][j];
		}
	}
	for(i=l; i<3*m.size(); i++){
		for (k=j; k<2*m.at(i-l).size(); k++){
			M[i][k]=v[i-l][k-j];
		}
	}
	for(i=l; i<3*m.size(); i++){
		for (j=k; j<3*m.at(i-l).size(); j++){
			M[i][j]=hv[i-l][j-k];
		}
		
	}
	
	
	
	return M;
}

int main ()
{
	try{
	cout << "Unesite dimenzije matrice (m n): ";
	int a, b;
	cin>> a >> b;
	if (a<0 || b<0) cout << "Dimenzije matrice moraju biti nenegativne!";
	else {
	matrica m(a, vektor(b));
	cout << "Unesite elemente matrice: " << endl; ;
	for (int i=0; i<a; i++){
		for (int j=0; j<b; j++){
			cin >> m[i][j];
		}
	}
	matrica n(OgledaloMatrica(m));
		cout << "Rezultantna matrica: " << endl;
		for (vektor red : n){
		for(double x : red) cout  << std ::setw(4)<< x  ;
		cout << endl;}
	
	}
	}
catch (std :: domain_error){
	cout << "Matrica nije korektna";
}
	return 0;
}