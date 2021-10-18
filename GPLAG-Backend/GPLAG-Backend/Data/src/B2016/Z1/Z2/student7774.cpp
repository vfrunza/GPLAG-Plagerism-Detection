#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<std::vector<double>> Matrica;

  bool Grbava(Matrica mat) {
	
//	if(mat.size()==1)
//		return false;
		
	for (int i = 0; i < mat.size()-1; i++) {
		if(mat[i+1].size()!=mat[i].size())
			return true;
	}
	return false;
}

void IspisiMatricu(Matrica m) {
	
	std::cout << "Rezultantna matrica:" << std::endl;
  
	for(int i=0; i<m.size(); i++) {
      for(int j=0; j<m[0].size(); j++) {
         cout << std::setw(4) << m[i][j];
      }
      cout << endl;
   }
}

Matrica UnosMatrice(int m, int n) {

	double broj;
	Matrica mat(m,std::vector<double>(n));

	for(int i=0; i<m; i++) {
    	for(int j=0; j<n; j++) {
    		cin >> broj;
    		mat[i][j]=broj;
    	}
	}
	return mat;
}

Matrica DajHorizontalnu (Matrica mat) {

	Matrica hor(mat.size(),std::vector<double>(mat[0].size()));
	int k;

	for(int i=0; i<mat.size(); i++) {
		k=mat[0].size()-1;
		for(int j=0; j<mat[0].size(); j++){
			hor[i][j]=mat[i][k];
			k--;
		}
	}
	return hor;
}

Matrica DajVertikalnu (Matrica mat) {

	Matrica vert(mat.size(),std::vector<double>(mat[0].size()));
	int k;

	k=mat.size();
	for(int i=0; i<mat.size(); i++) {
		k--;
		for(int j=0; j<mat[0].size(); j++) {
			vert[i][j]=mat[k][j];
		}
	}
	return vert;
}

Matrica DajHorVer (Matrica mat) {
	return DajHorizontalnu(DajVertikalnu(mat));
}

Matrica OgledaloMatrica(Matrica mat) {
	
	if(mat.size()==0)
		return Matrica (0,std::vector<double>(0));
		
	if(Grbava(mat))
		throw std::domain_error("Matrica nije korektna");	

	int m(mat.size()),n(mat[0].size());
	Matrica ogledalo(3*m,std::vector<double>(3*n));
    Matrica hv(DajHorVer(mat)),v(DajVertikalnu(mat)),h(DajHorizontalnu(mat));

    for(int i=0; i<3*m; i++) {
		for(int j=0; j<3*n; j++) {
			if(i<m && j<n)
				ogledalo[i][j]=hv[i][j];
			else if(i<m && j>=n && j<2*n)
				ogledalo[i][j]=v[i][j-n];
			else if(i<m && j>=2*n && j<3*n)
				ogledalo[i][j]=hv[i][j-(2*n)];
			else if(i>=m && i<2*m && j<n)
				ogledalo[i][j]=h[i-m][j];
			else if(i>=m && i<2*m && j>=n && j<2*n)
				ogledalo[i][j]=mat[i-m][j-n];
			else if(i>=m && i<2*m && j>=2*n && j<3*n)
				ogledalo[i][j]=h[i-m][j-(2*n)];
			else if(i>=2*m && j<n)
				ogledalo[i][j]=hv[i-(2*m)][j];
			else if(i>=2*m && j>=n && j<2*n)
				ogledalo[i][j]=v[i-(2*m)][j-n];
			else if(i>=2*m && j>=2*n && j<3*n)
				ogledalo[i][j]=hv[i-(2*m)][j-(2*n)];
		}
	}
	return ogledalo;
}

int main ()
{
	int m,n;

	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	
	if(m<0 || n<0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}	

	cout << "Unesite elemente matrice:" << endl;
	
	try {
		IspisiMatricu(OgledaloMatrica(UnosMatrice(m,n)));
	}
	catch (std::domain_error err) {
		std::cout << err.what() << std::endl;
	}
	
	
	
	return 0;
}