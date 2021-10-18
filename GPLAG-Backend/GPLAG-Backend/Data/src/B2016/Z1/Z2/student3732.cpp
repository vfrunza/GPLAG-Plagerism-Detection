
#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int m, int n) {
	return Matrica(m,std::vector<double>(n));
}
Matrica UnesiMatricu(int m,int n) {
	Matrica A(KreirajMatricu(m,n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin>>A[i][j];
		}
	}
return A;
}

void IspisiMatricu(Matrica A)  {
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<A[i].size(); j++) {
			std::cout<<" "<<A[i][j];
		}
		std::cout<<std::endl;
	}
}
Matrica Horizontalna(Matrica A) {
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<(A[i].size()/2); j++) {
			int pomocna;
			pomocna=A[i][A[i].size()-1-j];
			A[i][A[i].size()-1-j]=A[i][j];
			A[i][j]=pomocna;
		}
	}
	return A;
}
Matrica Vertikalna(Matrica A) {
	for(int i=0; i<A.size()/2; i++) {
		for(int j=0;j<A[i].size(); j++) {
			int pomocna;
			pomocna=A[i][j];
			A[i][j]=A[A.size()-1-i][j];
			A[A.size()-1-i][j]=pomocna;
		}
	}
	return A;
}
Matrica Kombinovana(Matrica A) {
	Matrica D=Horizontalna(A);
	Matrica C=Vertikalna(D);
	return C;
}
Matrica OgledaloMatrica(Matrica A){
	Matrica V=Vertikalna(A);
	Matrica H=Horizontalna(A);
	Matrica K=Kombinovana(A);
	if(A.size()==0 || A[0].size()==0) {
		Matrica Nula;
		Nula.resize(3*A.size());
		return Nula;
	}
	else {
		int a=A.size();
		int b=A[0].size();
		if(a<0 || b<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		Matrica Nova(KreirajMatricu(3*a,3*b));
		for(int i=0;i<a;i++) {
			for(int j=0;j<b;j++) {
				Nova[i][j]=K[i][j];
			}
		}
		for(int i=0;i<a;i++) {
			for(int j=b;j<2*b;j++) {
				Nova[i][j]=V[i][j-b];
			}
		}
		for(int i=0;i<a;i++) {
			for(int j=2*b;j<3*b;j++) {
				Nova[i][j]=K[i][j-2*b];
			}
		}
		for(int i=a;i<2*a;i++) {
			for(int j=0;j<b;j++) {
				Nova[i][j]=H[i-a][j];
			}
		}
		for(int i=a;i<2*a;i++) {
			for(int j=b;j<2*b;j++) {
				Nova[i][j]=A[i-a][j-b];
			}
		}
		for(int i=a;i<2*a;i++) {
			for(int j=2*b;j<3*b;j++) {
				Nova[i][j]=H[i-a][j-2*b];
			}
		}
		for(int i=2*a;i<3*a;i++) {
			for(int j=0;j<b;j++) {
				Nova[i][j]=K[i-2*a][j];
			}
		}
		for(int i=2*a;i<3*a;i++) {
			for(int j=b;j<2*b;j++) {
				Nova[i][j]=V[i-2*a][j-b];
			}
		}
		for(int i=2*a;i<3*a;i++) {
			for(int j=2*b;j<3*b;j++) {
				Nova[i][j]=K[i-2*a][j-2*b];
			}
		}
		return Nova;
	}
}
int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	std::cout<<"Unesite elemente matrice:\n";
	auto A(UnesiMatricu(m,n));
	std::cout<<"Rezultantna matrica: \n";
	IspisiMatricu(OgledaloMatrica(A));
	return 0;
}