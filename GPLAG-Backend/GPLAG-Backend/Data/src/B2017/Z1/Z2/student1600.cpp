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


typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova, int broj_kolona)
{
	return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

int BrojRedova(Matrica a)
{
	return a.size();
}

int BrojKolona(Matrica a)
{
	return a.at(0).size();
}

Matrica NajvecaPlaninaMatrice(Matrica a)
{
	Matrica q=KreirajMatricu(0,0);
	if(a.size()==0 || a.at(0).size()==0)
		return q;
	int temp=BrojKolona(a);
	for(int i=1; i<BrojRedova(a); i++) {
		if(temp!=a.at(i).size())
			throw std::domain_error("Matrica nije korektna");
	}
	int max=a.at(0).at(0);
	auto x (KreirajMatricu(1,1));

	for(int i=0; i<BrojRedova(a); i++) {
		for(int j=0; j<BrojKolona(a); j++) {
			if(a[i][j]>max)
				max=a.at(i).at(j);
		}
	}
	for(int i=0; i<1; i++) {
		for(int j=0; j<1; j++)
			x.at(i).at(j)=max;
	}
	return x;
}

int main ()
{
	try {

		int m,n;
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>>m>>n;

		if(m<0 || n<0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 1;
		}

		std::cout<<"Unesite elemente matrice:";

		auto a(KreirajMatricu(m,n));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				std::cin>>a.at(i).at(j);
			}
		}

		auto p (NajvecaPlaninaMatrice(a));

		std::cout<<"\nNajveca planina unesene matrice je: \n";
		for(int i=0; i<BrojRedova(p); i++) {
			for(int j=0; j<BrojKolona(p); j++) {
				std::cout<<std::setw(6)<<p.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	} catch (const std::domain_error &e) {
		std::cout << "Izuzetak: " << e.what() << std::endl;
	} catch(...) {
		std::cout << "Pogrešan izuzetak!";
	}
	return 0;
}