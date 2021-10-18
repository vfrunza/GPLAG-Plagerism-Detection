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
#include <cmath>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int red, int kolona)
{
	return Matrica (red, std::vector<double>(kolona));
}

int BrojRedova (Matrica m)
{
	return m.size();
}

int BrojKolona (Matrica m)
{
	return m.at(0).size();
}

Matrica UnesiMatricu (int red, int kolona)
{
	auto m(KreirajMatricu(red, kolona));
	for (int i=0; i<red; i++)
		for (int j=0; j<kolona; j++) {
			std::cin >> m.at(i).at(j);
		}
	return m;
}

void IspisiMatricu (Matrica m)
{
	for (int i=0; i<BrojRedova(m); i++) {
		for (int j=0; j<BrojKolona(m); j++) {
			std::cout << std::setw(6) << m.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

Matrica MaxBroj (Matrica m)
{
	double max=m.at(0).at(0);
	for (int i=0; i<BrojRedova(m); i++) {
		for (int j=0; j<BrojKolona(m); j++) {
			if (max<m.at(i).at(j))
				max=m.at(i).at(j);
		}
	}
	Matrica nova(KreirajMatricu(1,1));
	nova.at(0).at(0)=max;
	return nova;
}


Matrica	NajvecaPlaninaMatrice (Matrica m)
{
	Matrica Najveca;
	Matrica NajvecaSam;
	if (BrojKolona(m)==0 || BrojRedova(m)==0) {
		return Najveca;
	} else if (BrojKolona(m)==1 && BrojRedova(m)==1) {
		return m;
	} else if ((BrojKolona(m)==1 && BrojRedova(m)!=1)||(BrojKolona(m)!=1 && BrojRedova(m)==1)) {
		return MaxBroj(m);
	}
else
{

	int tmp=BrojKolona(m);
	for (int i=1; i<m.size(); i++) {
		if (tmp!=m.at(i).size()) {
			throw std::domain_error ("Matrica nije korektna");
		}
	}

	double suma=0;
	for (int i=1; i<BrojRedova(m)-1; i++) {
		for (int j=1; j<BrojKolona(m)-1; j++) {
			suma=m.at(i-1).at(j-1)+m.at(i-1).at(j)+m.at(i-1).at(j+1)+m.at(i).at(j-1)+m.at(i).at(j+1)+m.at(i+1).at(j-1)+m.at(i+1).at(j)+m.at(i+1).at(j-1);
			if (m.at(i).at(j)>suma) {
				NajvecaSam=KreirajMatricu(i+2,j+2);
			}
		}
		suma=0;
	}

	return MaxBroj(m);

}
}

int main()
{

	std::cout << "Unesite dimenzije matrice (m i n): " ;
	int m,n;
	std::cin >> m >> n;
	if (m<0 || n<0) std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;

	if (m>0 && n>0) {

		std::cout << "Unesite elemente matrice: "<<std::endl;

		KreirajMatricu(m,n);
		auto mat(UnesiMatricu(m,n));
		std::cout << "Najveca planina unesene matrice je:" << std::endl;
		IspisiMatricu(NajvecaPlaninaMatrice(mat));

	}
	return 0;
}