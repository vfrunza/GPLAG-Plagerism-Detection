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
using std::cout;
using std::cin;
using std::vector;
using std::setprecision;
typedef vector<vector<double>> Matrica;

Matrica OgledaloMatrica(vector<vector<double>> v){
	int n(0),m(0);
	n=v.size();
	if(n==0 && m==0)
	return Matrica (0,vector<double>(0));
	m=v[0].size();
	if(n==0)
	return Matrica (0,vector<double>(3*m));
	if(m==0)
	return Matrica (3*n,vector<double>(0));
	Matrica vh(n,vector<double>(m));
	Matrica vv(n,vector<double>(m));
	Matrica vhv(n,vector<double>(m));
	Matrica mat(3*n,vector<double>(3*m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			vh[i][m-j-1]=v[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			vv[n-i-1][j]=v[i][j];
			vhv[n-i-1][j]=vh[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			mat[i][j]=vhv[i][j]; mat[i][m+j]=vv[i][j]; mat[i][2*m+j]=vhv[i][j];
			mat[n+i][j]=vh[i][j]; mat[n+i][m+j]=v[i][j]; mat[n+i][2*m+j]=vh[i][j];
			mat[2*n+i][j]=vhv[i][j]; mat[2*n+i][m+j]=vv[i][j]; mat[2*n+i][2*m+j]=vhv[i][j];
		}
	}
	
		return mat;
}

int main ()
{
	int n(0),m(0);
	std::cout<<"Unesite dimenzije matrice (m n): ";
	cin>>n>>m;
	if(n<0 || m<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	if(n==0 || m==0){
		cout<<"Unesite elemente matrice:\nRezultantna matrica: \n"<<"";
		return 0;
	}
	Matrica v(n,vector<double>(m));
	cout<<"Unesite elemente matrice:";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
		}
	}
	cout<<"\nRezultantna matrica: \n";
	v=OgledaloMatrica(v);
	for(int i=0;i<3*n;i++){
		for(int j=0;j<3*m;j++)
		cout<<std::fixed<<std::setw(4)<<setprecision(0)<<std::right<<v[i][j];
		cout<<"\n";
	}
	
	return 0;
}