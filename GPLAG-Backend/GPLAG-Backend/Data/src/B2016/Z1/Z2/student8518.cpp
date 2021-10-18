/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iomanip>
#include <iostream>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>>Matrica ;

Matrica OgledaloMatrica ( Matrica M )
{
    if(M.size()==0) {
        return M;
    }

    for( int i=0; i<M.size(); i++ ) {
        if(M[i].size()!=M[0].size()) {
            throw std::domain_error("Matrica nije korektna");
        }
    }


    Matrica h (M),v(M),hv(M);
    int m(0),n(0);
    m=M.size();
    n=M[0].size();


    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            h[j][i]=M[j][n-1-i];

        }
    }


    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            v[i][j]=M[m-1-i][j];
            hv[i][j]=h[m-1-i][j];
        }
    }

    Matrica konacna(3*m, std::vector<double>(3*n) );

    for(int i=0; i<3*m; i++) {
        for(int j=0; j<3*n; j++) {
            if(i<m) {
                if(j<n) {
                    konacna[i][j]=hv[i][j];
                }
                if(j>=n && j<2*n) {
                    konacna[i][j]=v[i][j-n];
                }
                if(j>=2*n && j<3*n) {
                    konacna[i][j]=hv[i][j-2*n];
                }
            }
            if(i>=m && i<2*m) {
                if(j<n) {
                    konacna[i][j]=h[i-m][j];
                }
                if(j>=n && j<2*n) {
                    konacna[i][j]=M[i-m][j-n];
                }
                if(j>=2*n && j<3*n) {
                    konacna[i][j]=h[i-m][j-2*n];
                }
            }

            if(i>=2*m && i<3*m) {
                if(j<n) {
                    konacna[i][j]=hv[i-2*m][j];
                }
                if(j>=n && j<2*n) {
                    konacna[i][j]=v[i-2*m][j-n];
                }
                if(j>=2*n && j<3*n) {
                    konacna[i][j]=hv[i-2*m][j-2*n];
                }
            }

        }
    }
    return konacna;
}

int main ()
{
    try {
        int m(0),n(0);
        std::cout <<"Unesite dimenzije matrice (m n): ";
        std::cin >> m >>n ;
        if(m<0 || n<0) {
            std::cout << "Dimenzije matrice moraju biti nenegativne!" ;
            return 0;
        }
        std::cout << "Unesite elemente matrice: "<<std::endl;

        Matrica M( m, std::vector<double>(n) );
        double e(0);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                std::cin >> e;
                M[i][j]=e;
            }
        }

        std::cout <<"Rezultantna matrica: "<< std::endl;
        for(std::vector<double>x : OgledaloMatrica(M)) {
            for( double y : x ) {
                std::cout <<std::setw(4)<< y;
            }
            std::cout << std::endl;
        }
    } catch( std:: domain_error izuzetak ) { // poznati kao standardni izuzeci definirani u biblioteci “stdexcept”.
        std::cout << izuzetak.what() << std::endl; // pozivom funkcije “what” (bez parametara), ispisujemo text koji smo koristili za kreiranje izuzetka !!!
    }

    return 0;
}
