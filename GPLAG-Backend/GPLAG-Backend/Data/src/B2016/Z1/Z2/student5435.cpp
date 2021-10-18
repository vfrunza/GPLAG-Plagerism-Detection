#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double> > Matrica;

Matrica UnesiMatricu(int br_redova, int br_kolona) {
	Matrica m(br_redova, std::vector<double>(br_kolona));
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++)
			std::cin >> m[i][j];
	}
	return m;
}

void IspisMatrice(Matrica m) {
	for(std::vector<double> red:m){
		for(double i : red)
			std::cout << std::setw(4) << i;
		std::cout << std::endl;
	}
}

Matrica v_ogledalo(Matrica v) {
	Matrica x;
	for(int i=v.size()-1; i>=0; i--) { 
      x.push_back(v[i]);
    }
	return x;
}

Matrica h_ogledalo(Matrica v) {
	Matrica x(v.size(), std::vector<double> (v[0].size()));
	int k(0);	
	for(int i=0; i<v.size(); i++) {
		k=0;
		for(int j=v[0].size()-1; j>=0; j--) {
			x[i][k]=v[i][j];
			k++;
		}
	}
	return x;
}

Matrica OgledaloMatrica (Matrica m) {
	for(int i=0; i<m.size()-1; i++) {
		if(m[i].size()!=m[i+1].size()) {
			throw std::domain_error("Matrica nije korektna");
			return m;
		}
	}
	int p(m.size()), n(m[0].size());
	Matrica x(3*p, std::vector<double> (3*n));
	Matrica vh(v_ogledalo(h_ogledalo(m))), v(v_ogledalo(m)), h(h_ogledalo(m));
	for(int i=0; i<3*p; i+=p) {
		for(int j=0; j<3*n; j+=n) {
			if(i==p && j==n) {
				int s(0), r(0);
				for(int k=i; k<i+p; k++) {
					for(int l=j; l<j+n; l++) {
						x[k][l]=m[r][s];
						s++;
					}
					s=0;
					r++;
				}
			}
			if((i==0 && j==0) || (i==2*p && j==0) || (j==2*n && i==0) || (i==2*p && j==2*n)) {
				int s(0), r(0);
				for(int k=i; k<i+p; k++) {
					for(int l=j; l<j+n; l++) {
						x[k][l]=vh[r][s];
						s++;
					}
					s=0;
					r++;
				}
			}
			 if((i==p && j==0) || (i==p && j==2*n)) {
				int s(0), r(0);
				for(int k=i; k<i+p; k++) {
					for(int l=j; l<j+n; l++) {
						x[k][l]=h[r][s];
						s++;
					}
					s=0;
					r++;
				}
			}
			if((i==0 && j==n) || (i==2*p && j==n)) {
				int s(0), r(0);
				for(int k=i; k<i+p; k++) {
					for(int l=j; l<j+n; l++) {
						x[k][l]=v[r][s];
						s++;
					}
					s=0;
					r++;
				}
			}
		}
	}
	return x;	
}

int main () {
	int p, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> p >> n;
	if(p<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!" ;
		return 0;
	}
	std::cout << "Unesite elemente matrice:";
	Matrica m(UnesiMatricu(p,n));
	std::cout << std::endl << "Rezultantna matrica:" << std::endl;
	if(p==0 || n==0) return 0;
	IspisMatrice(OgledaloMatrica(m));
	std::cout << std::endl;

	return 0;
}