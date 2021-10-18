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

using std::cout;
using std::cin;
using std::vector;

typedef vector<vector<double>> Matrica;

/*void IspisiMatricu(Matrica m){
	for (int i(0); i<m.size(); i++){
		for (int j(0); j<m[i].size(); j++){
			if (j==m[i].size()-1) cout << std::setw(3) << m[i][j];
			else cout << std::setw(4) << std::right << m[i][j] << " ";
		}
		cout << std::endl;
	}
} */

void IspisiMatricu(Matrica m){
	for (int i(0); i<m.size(); i++){
		for (int j(0); j<m[i].size(); j++){
			cout << std::setw(4) << m[i][j];
		}
		cout << std::endl;
	}
} 
  
  Matrica Horizontalna(Matrica a, int m, int n){
  	for (int i(0); i<m; i++){
  		for (int j(0); j<n/2; j++) {
  			double pom;
  			pom=a[i][j];
  			a[i][j]=a[i][n-j-1];
  			a[i][n-j-1]=pom;
  		}
  	}
  	return a;
  }
  
  Matrica Vertikalna(Matrica a, int m, int n){
  	for (int i(0); i<m/2; i++){
  		vector<double> pomocni;
  		pomocni=a[i];
  		a[i]=a[m-1-i];
  		a[m-1-i]=pomocni;
  	}
  	return a;
  }
  
  
 Matrica OgledaloMatrica(Matrica a){
 	if (a[0].size()==0) return a;
 	for (int i(0); i<a.size()-1; i++){
 		for (int j(0); j<a[i].size(); j++){
			if (a[i].size()!=a[i+1].size()) throw std::domain_error ("Matrica nije korektna."); } }

	Matrica horizontalna,vertikalna,HV,ogledalo;
	horizontalna = Horizontalna(a, a.size(), a[0].size());
	vertikalna = Vertikalna(a, a.size(), a[0].size());
	HV = Horizontalna(vertikalna, vertikalna.size(), vertikalna[0].size());

	int m;
	int n;
	m=a.size();
	n=a[0].size();
	ogledalo.resize(3*m);
/*	for (int i(0); i<3*m; i++){
		ogledalo[i].resize(3*n);
	} */
	int k(0);
		int q(0);
		int pomocna,element;
	for (int i(0); i<3*m; i++){
		
		for (int j(0); j<3*n; j++){
			
			if (i<m && j<n) {  
				ogledalo[i].push_back(HV[q][k]); 
				pomocna=HV[q][k];
				element=ogledalo[i][j];
			k++;
			if (k==n) k=0; 
			 }
			else if (i<m && j<2*n) {ogledalo[i].push_back(vertikalna[q][k]); 
			pomocna=vertikalna[q][k];
			element=ogledalo[i][j]; 
			k++;
			 if (k==n) k=0;
				 
			}
			else if (i<m && j<3*n)  {ogledalo[i].push_back(HV[q][k]); 
			pomocna=HV[q][k];
			element=ogledalo[i][j]; 
			k++;
			 if (k==n) k=0;
				
			}
			else if (i<2*m && j<n) { ogledalo[i].push_back(horizontalna[q][k]); 
			pomocna=horizontalna[q][k];
			element=ogledalo[i][j];
			k++;
			 if (k==n) k=0; 
				
			}
			else if (i<2*m && j<2*n) { ogledalo[i].push_back(a[q][k]); 
			pomocna=a[q][k];
			element=ogledalo[i][j]; 
			k++;
			 if (k==n) k=0;
				
			}
			else if (i<2*m && j<3*n) { ogledalo[i].push_back(horizontalna[q][k]); 
			pomocna=horizontalna[q][k];
			element=ogledalo[i][j];
			k++;
			 if (k==n) k=0;
				
			}
			else if (i<3*m && j<n)  { ogledalo[i].push_back(HV[q][k]); 
			pomocna=HV[q][k];
			element=ogledalo[i][j]; 
			k++;
			 if (k==n) k=0;
				
			}
			else if (i<3*m && j<2*n) { ogledalo[i].push_back(vertikalna[q][k]); 
			pomocna=vertikalna[q][k];
			element=ogledalo[i][j]; 
			k++;
			 if (k==n) k=0;
				
			}
			else if (i<3*m && j<3*n) {  ogledalo[i].push_back(HV[q][k]); 
			pomocna=HV[q][k];
			element=ogledalo[i][j]; 
			k++;
			if (k==n) k=0;
				
			}
		}
		q++; if (q==m) q=0;
	}
	
	
	return ogledalo;
}





int main ()
{
	try {
	cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	cin >> m >> n;
if (m<0 || n<0) { printf("Dimenzije matrice moraju biti nenegativne!"); return 0; }
	cout << "Unesite elemente matrice:" << std::endl;
	Matrica a;
	if (m==0 && n==0) {
			a.resize(m);
	for (int i(0); i<m; i++){
		a[i].resize(n); }
		goto ovdje;
	}
	if (m==0 || n==0) {
		a.resize(m);
	for (int i(0); i<m; i++){
		a[i].resize(n);
	}  goto ovdje; 
	}
	a.resize(m);
	for (int i(0); i<m; i++){
		a[i].resize(n);
	}
	
	for (int i(0); i<m; i++){
		for (int j(0); j<n; j++) cin >> a[i][j];
	}
	a = OgledaloMatrica(a);
	
	ovdje:
	cout << "Rezultantna matrica: " << std::endl;
	
	IspisiMatricu(a);
	
	return 0;
	}
	 catch(std::domain_error izuzetak){
      cout << izuzetak.what();
   }
   
}