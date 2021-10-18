/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <cmath>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(double br_redova, double br_kolona)
{
    return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu(double br_redova, double br_kolona)
{

    auto Mat(KreirajMatricu(br_redova, br_kolona));
    for (int i = 0; i <br_redova; i++)
        for (int j = 0; j < br_kolona; j++) {
            std::cin >> Mat[i][j];
        }
    return Mat;
}

int NajvecaPlaninaMatrice (Matrica mat,double m, double n){
	
	int a(1);
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if ((mat.at(i).at(j))  >  ((mat.at(i).at(j-1)) + mat.at(i).at(j+1)) + (mat.at(i-1).at(j) + (mat.at(i-1).at(j+1) + mat.at(i-1).at(j+2)) + (mat.at(i+1).at(j) + mat.at(i+1).at(j+1) + mat.at(i+1).at(j+2))))
			std::cout << "Nekim cudom radi";
			
		}
	}
	return a;
}


int main ()
{	
	Matrica mat;
	double m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	while (m < 0 or n < 0) {
	std::cout << "Dimenzije matrice moraju biti nenegativne!";
	return 1; }
	
	std::cout << "Unesite elemente matrice: ";
	UnesiMatricu(m,n);
	
	NajvecaPlaninaMatrice(mat,m,n);
	return 0;
}