/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std :: vector<double> > matrica;

matrica KreirajMatricu(int redovi, int kolone)
{
	return matrica(redovi, std::vector<double>(kolone));
}


matrica Unesimatricu(int m, int n)
{
	matrica k(KreirajMatricu(m,n));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> k[i][j];
		}
	}
	return k;
}


int brojredova(matrica m)
{
	//DIMENZIJE
	return m.size();
}
int brojkolona(matrica m)
{
	return m[0].size();
}

bool dalijegrbava(matrica m)
{
	//NE SMIJE BITI GRBAVA
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			if (m[i].size()!=m[j].size()) return false;
		}
	}
	return true;
}

void ispisimatricu(matrica m)
{
	for(int i = 0; i < brojredova(m); i++) {
		for(int j = 0; j < brojkolona(m); j++) {
			std::cout <<std :: right<< std :: setw(4)<<m[i][j];
		}
		std :: cout << std :: endl;
	}
}

matrica vertikalna(matrica mat)
{
	//VERTIKALNA MATRICA
	int	n=brojredova(mat);
	std::vector<double> temp;
	for(int i=0; i<n/2; i++) {
		temp=mat[i];
		mat[i]=mat[n-i-1];
		mat[n-i-1]=temp;
	}
	return mat;
}

matrica horizontalna(matrica mat)
{
	//HORIZONTALNA MATRICA
	int m=brojkolona(mat);
	int n=brojredova(mat);
	double temp;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m/2; j++) {
			temp=mat[i][j];
			mat[i][j]=mat[i][m-j-1];
			mat[i][m-1-j]=temp;
		}
	}
	return mat;
}

matrica mjesovita(matrica mat)
{
	//MJESOVITA MATRICA
	matrica k(horizontalna(mat));
	matrica z(vertikalna(k));
	return z;
}

matrica OgledaloMatrica(matrica mat)
{

	if(mat.size()==0) return mat;
	if (!dalijegrbava(mat)) throw std :: domain_error("Matrica nije korektna");

	int n=brojredova(mat);
	int m=brojkolona(mat);
	matrica nova(KreirajMatricu(3*n,3*m));

	matrica h=horizontalna(mat);
	matrica v=vertikalna(mat);
	matrica hv=mjesovita(mat);
     //PETLJA KROZ CITAVU MATRICU
	for(int i=0; i<3*n; i++) {                                                       
		for(int j=0; j<3*m; j++) {
			if (i<n && j<m) {
				nova[i][j]=hv[i][j];
				nova[i+2*n][j]=hv[i][j];
				nova[i+2*n][2*m+j]=hv[i][j];
				nova[i][j+2*m]=hv[i][j];
			}

			if (i<n && j>=m && j<2*m ) {
				nova[i][j]=v[i][j-m];
				nova[2*n+i][j]=v[i][j-m];
			}

			if (i>=n && i<2*n && j<m) {
				nova[i][j]=h[i-n][j];
				nova[i][2*m+j]=h[i-n][j];
			}

			if (i>=n && i<2*n && j>=m && j<2*m) {
				nova[i][j]=mat[i-n][j-m];
			}
		}
	}
	return nova;
}


int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): " ;
	int m,n;
	std::cin >> m>>n;
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
	} else {
		std::cout << "Unesite elemente matrice: " << std::endl;
		matrica a(Unesimatricu(m,n));
		try {
			matrica nova(OgledaloMatrica(a));
			std :: cout << "Rezultantna matrica:"<<std :: endl;
			ispisimatricu(nova);
		} catch (std :: domain_error izuzetcic) {
			std::cout << izuzetcic.what();
		}
	}
	return 0;
}