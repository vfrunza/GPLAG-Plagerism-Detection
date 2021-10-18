/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<iomanip>
#include<vector>

using std::vector;

typedef vector<vector<double>> Matrica;

Matrica OgledaloMatrica(vector<vector<double>> M){
	int a(0), b(0);
	a=M.size();
	b=M[0].size();
	Matrica h(a, vector<double> (b));
	Matrica v(a, vector<double> (b));
	Matrica hv(a, vector<double> (b));
	Matrica mat(3*a, vector<double> (3*b));
	int i(0), j(0);
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			h[i][b-j-1]=M[i][j];
		}
	}
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			v[a-i-1][j]=M[i][j];
			hv[a-i-1][j]=h[i][j];
		}
	}
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			// Prvi red
			mat[i][j]=hv[i][j];
			mat[i][b+j]=v[i][j];
			mat[i][2*b+j]=hv[i][j];
			// Drugi red
			mat[a+i][j]=h[i][j];
			mat[a+i][b+j]=M[i][j];
			mat[a+i][2*b+j]=h[i][j];
			// Treci red
			mat[2*a+i][j]=hv[i][j];
			mat[2*a+i][b+j]=v[i][j];
			mat[2*a+i][2*b+j]=hv[i][j];
		}
	}
	return mat;
}

int main ()
{
	int a(0), b(0);
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>a>>b;
	if(a<0 || b<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	if(a==0 || b==0){
		std::cout<<"Unesite elemente matrice:\nRezultantna matrica: \n"<<"";
		return 0;
	}
	Matrica M(a, vector<double> (b));
	std::cout<<"Unesite elemente matrice: ";
	int i(0), j(0);
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			std::cin>>M[i][j];
		}
	}
	std::cout<<"\nRezultantna matrica: \n";
	M=OgledaloMatrica(M);
	for(i=0;i<3*a;i++){
		for(j=0;j<3*b;j++){
			std::cout<<std::fixed<<std::setw(4)<<std::setprecision(0)<<std::right<<M[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}



