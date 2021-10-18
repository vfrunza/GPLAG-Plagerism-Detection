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
typedef std::vector<std::vector<double>> matra;

matra h(matra M){
	int m,n;
	m=M.size();
	n=M[0].size();
	matra rez=M;
for(int i=0;i<m;i++)
for(int j=0;j<n;j++){
	rez[i][j]=M[i][n-j-1];
}
return rez;
}

matra v(matra M){
	matra rez=M;
int m,n;
	m=M.size();
	n=M[0].size();
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			rez[i][j] = M[m-i-1][j];
		}
		return rez;
}
matra hv(matra M){
	M=h(M);
	return v(M);
}
matra OgledaloMatrica(matra M){
	if(M.size()==0)return M;
	if(M.size()==0 || M[0].size()==0) {
		M.resize(3*M.size());
		M[0].resize(3*M[0].size());
		return M;
	}
	matra rez;
	int m,n;
		m = M.size();
		n = M[0].size();
		rez.resize(3*m);
		matra hvmat=hv(M), hmat=h(M), vmat=v(M);
		for(int i=0;i<3*m;i++) rez[i].resize(3*n);
		for(int i=0;i<3*m;i++)
		for(int j=0;j<3*n;j++){
			if(i<m){
				if(j<n)rez[i][j]=hvmat[i][j];
				if(j>n-1 && j<2*n) rez[i][j]=vmat[i][j-n];
				if(j>2*n-1 && j<3*n)rez[i][j]=hvmat[i][j-2*n];
			}
			else if(i>m-1 && i<2*m){
				if(j<n)rez[i][j]=hmat[i-m][j];
				if(j>n-1 && j<2*n)rez[i][j]=M[i-m][j-n];
				if(j>2*n-1 && j<3*n)rez[i][j]=hmat[i-m][j-2*n];
			}
			else if(i>2*m-1 && i<3*m){
				if(j<n)rez[i][j]=hvmat[i-2*m][j];
				if(j>n-1 && j<2*n)rez[i][j]=vmat[i-2*m][j-n];
				if(j>2*n-1 && j<3*n)rez[i][j]=hvmat[i-2*m][j-2*n];
			}
			else rez[i][j]=0;
			
		}
		return rez;
		
}

int main(){
	
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m;
	std::cin>>m;
	int n;
	std::cin>>n;   
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matra x; 
	x.resize(m);
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	for(int i=0; i<m;i++)x[i].resize(n);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++){
		
		std::cin>>x[i][j];
	}
	matra rez;        
	rez = OgledaloMatrica(x);
	std::cout<<"Rezultantna matrica:"<<std::endl;
	for(auto temp: rez){
		for(auto y: temp) std::cout<<std::setw(4)<<y;
		std::cout<<std::endl;
	}
	return 0;
}


 
     
     

  