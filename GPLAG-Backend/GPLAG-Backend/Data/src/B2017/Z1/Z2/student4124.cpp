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
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica ;

Matrica KreirajMatricu (int r, int k)
{
    return Matrica(r,std::vector<double>(k));
}

int BrojRedova (Matrica A)
{
    return A.size();
}

int BrojKolona (Matrica A)
{
    return A[0].size();
}

Matrica UnosMatrice (int br, int bk)
{
    auto M(KreirajMatricu (br, bk));
    for (int i=0; i<br; i++)
        for (int j=0; j<bk; j++) {
            std::cout << "Element A[" << i+1 << "]["<< j+1<<"] ";
            std::cin>> M[i][j];
        }

    return M;
}


void IspisMatrice (Matrica M)
{
    for (int i=0; i<BrojRedova(M); i++) {
        for (int j=0; j<BrojKolona(M); j++)


            std::cout << std::setw(10) << M[i][j];
        std::cout<<std::endl;

    }
}



int main()
{
    int m,n;
    Matrica F;
    std::cout<< "Unesite dimenzije matrice (m i n): ";
    std::cin>>m>>n;
    std::cout<<"Unesi elemente matrice \n";
    auto A(UnosMatrice(m,n));
   IspisMatrice(A);
    return 0;
}
