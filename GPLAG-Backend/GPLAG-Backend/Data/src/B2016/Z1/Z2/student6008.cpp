#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> matrica;

matrica horizontalna(matrica m){
	matrica m1;
	m1.resize(m.size());
	for(int i=0; i<m.size(); i++)
		m1[i].resize(m[i].size());
	int k(0);
		for(int j=m[k].size()-1; j>=0; j--){
			for(int i=0; i<m.size(); i++){
			m1[i][k]=m[i][j];
			}
			k++;
		}
		return m1;
}
matrica vertikalna(matrica m){
	int k(0);
	matrica m1;
	m1.resize(m.size());
	for(int i=0; i<m.size(); i++)
		m1[i].resize(m[i].size());
	for(int j=0; j<m[k].size(); j++){
		for(int i=m.size()-1; i>=0; i--){
			m1[k][j]=m[i][j];
			k++;
		}
		k=0;
	}
	return m1;
}
matrica horiz_vert(matrica m){
	matrica m1;
	m1.resize(m.size());
	for(int i=0; i<m.size(); i++)
		m1[i].resize(m[i].size());
	m1=horizontalna(m);
	m1=vertikalna(m1);
	return m1;
}
matrica OgledaloMatrica(matrica m){
	matrica m1, c;
	matrica h, v, hv;
	if(m.size()==0){
		c.resize(0);
		
		return c;
	}
	
	if(m.size()!=0 && m[0].size()==0){
		c.resize(3* m.size());
		return c;
	}
	if(m.size()==0 && m[0].size()!=0){
		c[0].resize(3* m[0].size());
		return c;
	}
	m1.resize(3*m.size());
	for(int i=0; i<m1.size(); i++) {
		m1[i].resize(3* m[0].size());
	}
	int M(m.size()), N(m[0].size());
	
	
	h.resize(M);
	v.resize(M);
	hv.resize(M);
	
	for(int i=0; i<M; i++){
		h[i].resize(N);
		v[i].resize(N);
		hv[i].resize(N);
	}
	h=horizontalna(m);
	v=vertikalna(m);
	hv=horiz_vert(m);
	
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m1[i].size(); j++){
			if((i < M && j < N) || (i < M && j >= 2*N) || (i >= 2*M && j < N) || ( i>= 2*M && j >= 2*N))
				m1[i][j] = hv[i%M][j%N];
			else if((i < M && N <= j && j < 2*N) || (i >= 2*M && N <= j && j < 2*N))
				m1[i][j] = v[i%M][j%N];
			else if((j < N && M <= i && i < 2*M) || (j >= 2*N && M <= i && i < 2*M))
				m1[i][j] = h[i%M][j%N];
			else m1[i][j] = m[i%M][j%N];
		}
	}
	return m1;
}

int main ()
{
	matrica a, c;
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>> m >> n;
	if (m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
	} 
	else {
		a.resize(m);
		for(int i=0; i<m; i++)
			a[i].resize(n);
		std::cout<<"Unesite elemente matrice: ";
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				std::cin>>a[i][j];
			}
		}
		std::cout<<std::endl;
		
		c=OgledaloMatrica(a);
		
		std::cout<<"Rezultantna matrica:\n";
		for(int i=0; i<c.size(); i++){
			for(int j=0; j<c[i].size(); j++){
				std::cout<<std::setw(4) << c[i][j];
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}