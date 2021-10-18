#include <iostream>
#include <vector>  
#include <stdexcept>
#include <iomanip>  

typedef std::vector<std::vector<double>> Matrica ;

Matrica KreirajMatricu(int m, int n) {
	return Matrica(m, std::vector<double>(n));
}

Matrica UnesiMatricu(int m, int n) {
	auto matrica(KreirajMatricu(m, n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> matrica[i][j];
		}
	}
	return matrica;
}

void IspisiMatricu(Matrica m) {
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) {
			
			std::cout << std::setw(4) << m[i][j];
		}
		std::cout << std::endl;
	}
}
Matrica OgledaloMatrica(Matrica m) {
	if(m.size()==0) return m;
	bool isti(true);
	for(int i=0; i<m.size(); i++) {
		if(i<m.size()-1) {
			if(m[0].size()!=m[i+1].size()) {
				isti=false;
				break;
			}
		}
	}
	if(!isti) throw std::domain_error("Matrica nije korektna");
	
	Matrica h,v,hv,mat;
	h.resize(m.size());
	v.resize(m.size());
	hv.resize(m.size());
	mat.resize(3*m.size());

	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[0].size(); j++) {
			v[i].push_back(m[m.size()-i-1][j]);
		}
	}
	
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[0].size(); j++) {
			h[i].push_back(m[i][m[0].size()-j-1]);
		}
	}
	
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[0].size(); j++) {
			hv[i].push_back(m[m.size()-i-1][m[0].size()-j-1]);
		}
	}
	
	//konacna 
	for(int i=0; i<3*m.size(); i++) {
		for(int j=0; j<m[0].size(); j++) {
			if(i<m.size()) mat[i].push_back(hv[i][j]);
			else if(i>=m.size() && i<2*m.size()) mat[i].push_back(h[i-m.size()][j]);
			else if(i>=2*m.size() && i<3*m.size()) mat[i].push_back(hv[i-2*m.size()][j]);
		}
	}
	
	for(int i=0; i<3*m.size(); i++) {
		for(int j=m[0].size(); j<2*m[0].size(); j++) {
			if(i<m.size()) mat[i].push_back(v[i][j-m[0].size()]);
			if(i>=m.size() && i<2*m.size()) mat[i].push_back(m[i-m.size()][j-m[0].size()]);
			if(i>=2*m.size() && i<3*m.size()) mat[i].push_back(v[i-2*m.size()][j-m[0].size()]);
		}
	}
	
	for(int i=0; i<3*m.size(); i++) {
		for(int j=2*m[0].size(); j<3*m[0].size(); j++) {
			if(i<m.size()) mat[i].push_back(hv[i][j-2*m[0].size()]);
			if(i>=m.size() && i<2*m.size()) mat[i].push_back(h[i-m.size()][j-2*m[0].size()]);
			if(i>=2*m.size() && i<3*m.size()) mat[i].push_back(hv[i-2*m.size()][j-2*m[0].size()]);
		}
	}   
	return mat;
}

int main () {
	
	try {
	
	int m,n;
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: " << std::endl;
	
	auto A(UnesiMatricu(m, n));
	auto B(OgledaloMatrica(A));
	
	std::cout << "Rezultantna matrica: " << std::endl;
	IspisiMatricu(B);
	
	} catch (std::domain_error izuzetak) {
	std::cout << izuzetak.what();
	}

	return 0;
}