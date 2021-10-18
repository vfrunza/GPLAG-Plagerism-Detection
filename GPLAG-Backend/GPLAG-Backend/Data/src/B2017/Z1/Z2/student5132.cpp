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

typedef Matrica Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona) {
    return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica NajvecaPlaninaMatrice(Matrica matrica) {
	Matrica najpl;
	std::vector<double> sume;
	
	
	
	return najpl;
}

int main ()
{
	int m, n;
	
	std::cout << "Unesite dimenzije matrice m i n: ";
	std::cin >> m >> n;
	
	Matrica matrica;
	
	matrica = KreirajMatricu(m, n);
	
	Matrica planina(NajvecaPlaninaMatrice(matrica));
	
	return 0;
}