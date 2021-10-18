/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
typedef vector<vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica matra){
	Matrica glavna; if(matra.size()==0) return glavna;
	Matrica	red_matra(matra.size(), vector<double> (matra[0].size()) ), kolona_matra(matra.size(), vector<double> (matra[0].size()) ) ,rk_matra(matra.size(), vector<double> (matra[0].size()) );
	
		for(int j = 0;j < matra.size()/2 ;j++){
			int p(matra.size()-1);
			
			red_matra[j]=matra[p];
			red_matra[p]=matra[j];
		
			rk_matra[j]=matra[p];
			rk_matra[p]=matra[j];
		
		p--;
	}
	if(matra.size()%2 != 0) {
		for(int i = matra[0].size() - 1 ;i >= 0 ;i--){
			red_matra[matra.size()/2][i]=matra[matra.size()/2][i];
			rk_matra[matra.size()/2][i]=matra[matra.size()/2][i];
		}	
	}
	
	for(int i = 0 ;i < matra.size() ;i++)
		for(int j = 0; j < matra[0].size() / 2 ;j++){
			int p(matra[0].size()-1);
		
		kolona_matra[i][j]=matra[i][p];
		kolona_matra[i][p]=matra[i][j];
		
		double temp(rk_matra[i][j]);
		rk_matra[i][j]=rk_matra[i][p];
		rk_matra[i][p]=temp;
		
		p++;
		}
		
		if(matra[0].size()%2 != 0) {
		for(int i = matra.size() - 1 ;i >= 0 ;i-- ){
			kolona_matra[i][matra[0].size()/2]=matra[i][matra[0].size()/2];
			rk_matra[i][matra[0].size()/2]=rk_matra[i][matra[0].size()/2];
		}
	}
	
	int m(matra.size()) , n(matra[0].size());
	glavna.resize(3*m);
	for(int i = 0 ;i < 3*m ; i++) glavna[i].resize(3*n);
	
	// ispis
	int p(0);
	for(int i = 0 ;i <m ;i++ ){
		int q(0);
		for(int j = n ;j < 2*n ; j++ ){
			glavna[i][j] = red_matra[p][q];
			q++;
		}															//9.1, 4.2, 1.1},{.5, .1, -12}, {321, 123, 311},
    
		p++;
	}
	p=0;
	for(int i = 2*m; i < 3*m ; i++){
		int q(0);
		for(int j = n ;j < 2*n ;j++ ){
			
			glavna[i][j] = red_matra[p][q];
			q++;
		}
		p++;
	}
	p=0;
	for(int i = 0; i < m ; i++){
		int q(0);
		for(int j = 0 ;j < n ;j++ ){
			
			glavna[i][j] = rk_matra[p][q];
			q++;
		}
		p++;
	}
	p=0;
	for(int i = 0; i < m ; i++){
		int q(0);
		for(int j = 2*n ;j < 3*n ;j++ ){
			
			glavna[i][j] = rk_matra[p][q];
			 q++;
		}
		p++;
	}
	p=0;
	for(int i = 2*m; i < 3*m ; i++){
		int q(0);
		for(int j = 0 ;j < n ;j++ ){
			
			glavna[i][j] = rk_matra[p][q];
			q++;
		}
		p++;
	}
	p=0;
	for(int i = 2*m; i < 3*m ; i++){
		int q(0);
		for(int j = 2*n ;j < 3*n ;j++ ){
			
			glavna[i][j] = rk_matra[p][q];
			q++;
		}
		p++;
	}
	p=0;
	for(int i = m; i < 2*m ; i++){
		int q(0);
		for(int j = 0 ;j < n ;j++ ){
			
			glavna[i][j] = kolona_matra[p][q];
			q++;
		}
		p++;
	}
	p=0;
	for(int i = m; i < 2*m ; i++){
		int q(0);
		for(int j = 2*n ;j < 3*n ;j++ ){
			
			glavna[i][j] = kolona_matra[p][q];
			q++;
		}
		p++;
	}
	p=0;
	for(int i = m; i < 2*m ; i++){
		int q(0);
		for(int j = n ;j < 2*n ;j++ ){
			
			glavna[i][j] = matra[p][q];
			q++;
		}
		p++;
	}
	return glavna;
}

int main ()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0) { cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; }
	Matrica matra,glavna;
	cout<<"Unesite elemente matrice: ";
	matra.resize(m);
	for(int i = 0 ;i < m ;i++) matra[i].resize(n);
	for(int i = 0 ;i < m ;i++){
	for(int j = 0 ;j < n ;j++){
		double a;
		cin>>a;
		matra[i][j]=a;
		}
	}
	glavna=OgledaloMatrica(matra);
	
	
cout<<endl<<"Rezultantna matrica: "<<endl;
for(int i = 0; i < glavna.size() ;i++ ){
	cout<<" ";
	for(int j = 0; j < glavna[0].size() ;j++ ){
		cout<<right<<setw(3)<<glavna[i][j]<<" ";
		}
		cout<<endl;
	}		
	return 0;
}

