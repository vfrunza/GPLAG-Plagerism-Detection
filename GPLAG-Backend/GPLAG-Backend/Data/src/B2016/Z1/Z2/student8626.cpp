/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<algorithm>

typedef std::vector<std::vector<double>> Matrix;

void HOgledalo(Matrix M){
	for(int i(0); i<M.size();i++){
		for(int j(0); j<M[0].size()/2; j++){
			swap(M[i][j], M[i][M[0].size()-j-1]);
		}
	}
}

void VOgledalo(Matrix M){
	for(int i(0); i<M[0].size(); i++){
		for(int j(0); j<M.size()/2; j++){
			swap(M[i][j], M[M.size()-i-1][j]);
		}
	}
}

void HVOgledalo(Matrix M){
	for(int i(0); i<M[0].size(); i++){
		for(int j(0); j<M.size()/2; j++){
			swap(M[i][j], M[M.size()-i-1][j]);
		}
	}
	for(int i(0); i<M.size(); i++){
		for(int j(0); j<M[0].size()/2; j++){
			swap(M[i][j], M[i][M[0].size()-j-1]);
		}
	}
}

Matrix OgledaloMatrica(Matrix M){
	if(M.size() == 0) return M;
	
	for(int i(1); i<(int) M.size();i++){
		if(M[0].size() != M[i].size())
		   throw domain_error ("Matrica nije korektna");
	}
	int m=3*M.size(), n=3*M[0].size();
	Matrix Trazena(m*n);
	for(int i(0); i<m;i++){
		for(int j(0); j<n;j++){
			if(i<m && j<n){
				M[i][j]=Trazena[i%m][j%n];
			}
		    if(){
				
			}
			if((j==0 && i==m/2) || (j==n-1 && i==m/2)){
				
			}
			
		}
	}
	return Trazena;
}

int main ()
{
	return 0;
}