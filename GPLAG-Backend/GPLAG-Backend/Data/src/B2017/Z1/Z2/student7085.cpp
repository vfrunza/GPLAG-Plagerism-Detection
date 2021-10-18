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
#include <algorithm>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int broj_redova, int broj_kolona)
{

	return Matrica(broj_redova, std::vector<double>(broj_kolona));

}

int BrojRedova (Matrica m)
{
	return m.size();
}

int BrojKolona (Matrica m)
{
	return m.at(0).size();
}

Matrica UnesiMatricu (int broj_redova, int broj_kolona)
{
	Matrica m(KreirajMatricu(broj_redova,broj_kolona));
	for (int i = 0; i < broj_redova; i++) {
		for (int j=0; j< broj_kolona; j++) {
			std::cin >> m.at(i).at(j);
		}
	}
	return m;
}

void IspisiMatricu (Matrica m)
{
	for (auto red : m) {
		for (auto x : red) std::cout << std::setw(6) << x;
		std::cout << std::endl;
	}
}


int NajveciElementRed (Matrica a)  			// Radi
{
	double povratna = a.at(0).at(0);
	int povratna1;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.at(0).size(); j++) {
			if (a.at(i).at(j) > povratna) {
				povratna1 = i;
				povratna = a.at(i).at(j);
			}
		}
	}
	return povratna1;
}

int NajveciElementKolona(Matrica a)
{
	double povratna = a.at(0).at(0);
	int povratna1;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.at(0).size(); j++) {
			if (a.at(i).at(j) > povratna) {
				povratna1 = j;
				povratna = a.at(i).at(j);
			}
		}
	}
	return povratna1;
}

double NajveciElement(Matrica a)
{
	double povratna(a.at(0).at(0));

	for (int i = 0; i < BrojRedova(a); i++) {
		for (int j = 0; j < BrojKolona(a); j++) {
			if (a.at(i).at(j) > povratna) povratna = a.at(i).at(j);
		}
	}
	return povratna;
}

Matrica NajvecaPlaninaMatrice (Matrica a)
{
	for (int v = 0; v < BrojRedova(a); v++)
		if (a.at(0).size()!=a.at(v).size()) throw std::domain_error("Matrica nije korektna");

	Matrica kralj;
	std::vector<double> povratna;
	double suma=0;
	int z = 0;
	int m = NajveciElementRed(a);
	int n = NajveciElementKolona(a);
	int brojac=0;


	if (a.at(0).at(0)==NajveciElement(a)) {
		povratna.push_back(NajveciElement(a));
		kralj.push_back(povratna);
		return kralj;
	}
	
	if ((m==0 || n==0 || m==BrojRedova(a)-1 || n==BrojKolona(a)-1))
		{ // Ova radi perfect

		povratna.push_back(NajveciElement(a));
		kralj.push_back(povratna);
		return kralj;
	}


	if (BrojKolona(a)<=2 && BrojRedova(a)<=2 ) { // Ova radi perfect

		povratna.push_back(NajveciElement(a));
		kralj.push_back(povratna);
		return kralj;
	}
	
	do {	// I_Z_B_A_C_I RUBNE I POPRAVI PROGRAM!

		if (z>m) break;
		if (z>n) break;
		if (brojac>0) suma = 0;
		if (brojac>0) kralj.clear();

		for (int i = m-z; i<=n+z; i++) {
			if (i==a.size()) break;
			for (int j=n-z; j<=n+z; j++) {
				if (j==a.at(0).size()) break;
				suma = suma+ a.at(i).at(j);
				povratna.push_back(a.at(i).at(j));
			}
			kralj.push_back(povratna);
			povratna.clear();
		}
		brojac++;

		if ((NajveciElement(a)>suma-NajveciElement(a))) {
			z++;
		} else break;

	} while (true);

	return kralj;
}

int main ()
{
	int m, n;

	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;

	if (m<0 ||n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;

	}

	std::cout << "Unesite elemente matrice: " << std::endl;

	Matrica A(UnesiMatricu(m,n));
	A = NajvecaPlaninaMatrice(A);

	
	try {
		NajvecaPlaninaMatrice(A);
	} catch (const std::domain_error &e) {
		std::cout << "Izuzetak: " << e.what() << std::endl;
		return 0;
	} catch(...) {
		std::cout << "Pogrešan izuzetak!";
		return 0;
	}
	std::cout<< "Najveca planina unesene matrice je:\n";
	IspisiMatricu(A);
	return 0;
}