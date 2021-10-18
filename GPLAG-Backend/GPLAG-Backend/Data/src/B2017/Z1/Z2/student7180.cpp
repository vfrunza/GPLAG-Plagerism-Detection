//B 2017/2018, Zadaća 1, Zadatak 2
#include <iostream>
#include <vector> 
#include <stdexcept>
#include <iomanip>
#include <complex>

typedef std::vector<std::vector<double>> Matrica;

int NajvecaPlaninaMatrice ( Matrica mat )
{
	for ( int i = 0; i < mat.size(); i++ ) {
		for ( int j = 0; j < mat.size(); j++ ) {
			std::cout << std::setw(3) << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	double PlaninaMax(mat.at(0).at(0)), duzinaMatricePlanine(0);
	std::complex<int> AdresaPlanine(0,0);
	
	for ( int i = 0; i < mat.size(); i++ ){
		for ( int j = 0; j < mat.size(); j++) {
			if (( i == 0 ) || ( j == 0 ) || ( i == mat.size()-1 ) || ( j == mat.size()-1 )) continue;
			double maxi( mat.at(i).at(j) );
			int i2(i-1), j2(j-1), duz(3);
			bool t(0);

			while ( ( t == 0 ) && ((( i2 >= 0 ) && ( j2 >= 0 )) && (( i2+duz-1 < mat.size()) && ( j2+duz-1 < mat.size() ))) ) {
				double sum(0);
				for ( int i3 = i2; i3 < i2+duz; i3++ ) {
					for ( int j3 = j2; j3 < j2+duz; j3++ ) {
						if (( i3 == i2 ) || ( j3 == j2 ) || ( j3 == j2+duz-1) || ( i3 == i2+duz-1)) sum += mat.at(i3).at(j3);
					}
				}
				
				if ( sum > maxi ) {t = 1; std::cout << maxi << " " << std::endl;}
				i2--; j2--; duz+=2;
			}
			if ( t == 0 ) {
				if (( PlaninaMax < maxi ) || (( PlaninaMax == maxi ) && ( i > AdresaPlanine.real())) || (( PlaninaMax == maxi ) && ( j > AdresaPlanine.imag()))) {
					PlaninaMax = maxi;
					std::complex<int> temp(i, j);
					AdresaPlanine = temp;
					duzinaMatricePlanine = ( duz - 2 );
				}
			}
		}
	}
	
	Matrica NajvecaPlaninaMatrica( duzinaMatricePlanine, std::vector<double> (duzinaMatricePlanine));

	
	return 0;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice ( m i n ): ";
	int m, n;
	std::cin >> m >> n;
	std::cout << "Unesite elemente matrice: ";
	Matrica mat (m, std::vector<double> (n));
	for ( int i = 0; i < m; i++ ) {
		for ( int j = 0; j < n ; j++ ) {
			double a;
			std::cin >> a;
			mat[i][j] = a;
		}
	}
	
	Matrica NajvecaPlaninaMatrica (NajvecaPlaninaMatrice(mat), std::vector<double> (0));
	std::cout << "Planina matrice je: " << std::endl;
	
	for ( int i =0; i < m; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			std::cout << std::setw(3) << NajvecaPlaninaMatrica.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}