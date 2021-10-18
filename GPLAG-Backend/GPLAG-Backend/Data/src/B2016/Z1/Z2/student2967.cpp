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

using namespace std;

vector<vector<double>> OgledaloMatrica(vector<vector<double>> matrica, int m, int n){
	vector<vector<double>> h(m, vector<double>(n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			h[i][j]=matrica[i][n-j-1];
		}
	}
	vector<vector<double>> v(m,vector<double>(n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			v[i][j]=matrica[m-i-1][j];
		}
	}
	vector<vector<double>> hv(m,vector<double>(n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			hv[i][j]=matrica[m-i-1][n-j-1];
		}
	}
	int a,b;
	a=3*m;
	b=3*n;
	vector<vector<double>> matricetina(a,vector<double>(b));
	
	
	
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			if(i<m && j<n){
				matricetina[i][j]=hv[i][j];
			}
			else if(i<m && j>=n && j<n*2){
				matricetina[i][j]=v[i][j-n];
			}
			else if(i<m && j>=n*2 && j<n*3){
				matricetina[i][j]=hv[i][j-(n*2)];
			}
			else if(i>=m && i<m*2 && j<n){
				matricetina[i][j]=h[i-m][j];
			}
			else if(i>=m && i<m*2 && j>=n && j<n*2){
				matricetina[i][j]=matrica[i-m][j-n];
			}
			else if(i>=m && i<m*2 && j>=n*2 && j<n*3){
				matricetina[i][j]=h[i-m][j-(n*2)];
			}
			else if(i>=m*2 && i<m*3 && j<n){
				matricetina[i][j]=hv[i-(m*2)][j];
			}
			else if(i>=m*2 && i<m*3 && j>=n && j<n*2){
				matricetina[i][j]=v[i-(m*2)][j-n];
			}
			else if(i>=m*2 && i<m*3 && j>=n*2 && j<n*3){
				matricetina[i][j]=hv[i-(m*2)][j-(n*2)];
			}
		}
	}
	return matricetina;
}

int main ()
{
	int m,n;
	
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	
	if(m<0 || n<0){
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	vector<vector<double>> matrica(m,vector<double>(n));
	cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> matrica[i][j];
		}
	}
	int a;
	a=3*m;
	int b;
	b=3*n;
	vector<vector<double>> KonacnaMatrica(a,vector<double>(b));
	KonacnaMatrica=OgledaloMatrica(matrica,m,n);
	cout << "\nRezultantna matrica: \n";
	
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cout << setw(4) << KonacnaMatrica[i][j];
		}
		cout << endl;
	}
	return 0;
		
	
}