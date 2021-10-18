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

using namespace std;

void Ispis(vector<vector<double>> matrica)
{
	for(int i(0);i<matrica.size();i++){
		for(int j(0);j<matrica[i].size();j++){
			cout<<setw(4)<<matrica[i][j];
		}
		cout<<endl;
	}
}




vector<vector<double>> OgledaloMatrica(vector<vector<double>> matrica)

{
	if(matrica.size()==0) return matrica;
	int m(matrica.size());
	int n(matrica[0].size());
	vector<vector<double>>nova(3*m,vector<double>(3*n));
	for(int i(1);i<m;i++)
	if(matrica[i].size()!=matrica[0].size()) throw domain_error("Matrica nije korektna");
	if(n==0) return nova;
	
	for(int i=0;i<3*m;i++){
		for(int j=0;j<3*n;j++){
			if(i<m && j<n) nova[i][j]=matrica[m-1-i][n-j-1];
			else if(j>=n && j<2*n){
				nova[i][j]=nova[i][n-1-j%n];
			}
			else if(j>=2*n && j<3*n){
				nova[i][j]=nova[i][j%n];
			}
			else if(i>=m && i<2*m){
				nova[i][j]=nova[m-1-i%m][j];
			}
			else{
				nova[i][j]=nova[i%m][j];
			}
		}
	}
	return nova;
}
	
	
	
	
	
int main()
{
	int m,n;
	vector<vector<double>> mat;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0) { cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	mat.resize(m);
	for(int i=0;i<mat.size();i++) mat[i].resize(n);
	cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	cout<<endl;
	try{
		cout<<"Rezultantna matrica: "<<endl;
		Ispis(OgledaloMatrica(mat));
	}
	catch(domain_error e)
	{
		cout<<e.what();
	}
	return 0;
}

	
	








