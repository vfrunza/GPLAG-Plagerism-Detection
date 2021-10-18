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

using std::cin;
using std::endl;
using std::cout;
typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;


bool Grbava (const Matrica matrica) {
	for (int i(0); i<matrica.size()-1; i++) {
			if(matrica.at(i).size() != matrica.at(i+1).size())
				return true;
	}
	return false;
}

long double SumaOkolnihElemenata (int xkoord, int ykoord, int brojprstena, Matrica matrica) {
	long double sumaokolnih(0);
	for (int i(xkoord-brojprstena); i<=xkoord+brojprstena; i++) {
		for (int j(ykoord-brojprstena); j<=ykoord+brojprstena; j++) {
			sumaokolnih = sumaokolnih + matrica.at(i).at(j);
		}
	}
	return sumaokolnih;
}

bool JednakiVrhovi (int brojprstena, int brkk) {
	return (brojprstena==brkk);
}

void Poredjenje (Matrica matrica,  int &xkv, int &ykv, int i, int j, long double &vrh) {

	if(matrica.at(i).at(j) > vrh) {
		vrh = matrica.at(i).at(j);
		xkv = i;
		ykv = j;
	}
}

Matrica NapraviNajvecuPlaninuMatrice (int brojredova, int brojkolona, int kk, Matrica matrica) {

	int velicina(0);
	Matrica NPM;
	for (int i(brojredova-kk); i<=brojredova+kk; i++) {
		velicina+=1;
		NPM.resize(velicina);
		for (int j(brojkolona-kk); j<=brojkolona+kk; j++) {
			NPM.at(velicina-1).push_back(matrica.at(i).at(j));
		}
	}
	return NPM;
}

Matrica NajvecaPlaninaMatrice (Matrica matrica) {
	
	Matrica trazena;
	if(matrica.size()==0 || matrica.at(0).size()==0) return trazena;
	else if(Grbava(matrica)) throw std::domain_error("Matrica nije korektna");
	
	else {
		int xkv(0), ykv(0), brkk(0);
		long double vrh(matrica.at(0).at(0));
		for (int i(0); i<matrica.size(); i++) {
			for (int j(0); j<matrica.at(i).size(); j++) {
				int brojprstena(1);
				long double trenutnasuma(matrica.at(i).at(j)), privremenasuma;
				while (brojprstena+i<matrica.size() && brojprstena+j<matrica.at(i).size() && i-brojprstena>=0 && j-brojprstena>=0) {
					privremenasuma = SumaOkolnihElemenata(i, j, brojprstena, matrica) - matrica.at(i).at(j);	//Ogranicava max sirinu planine matrice
					if (trenutnasuma<=privremenasuma) break;
					else {
						brojprstena++;
						trenutnasuma = privremenasuma;
					}
					brojprstena--;
					if(brkk<brojprstena){
						brkk = brojprstena;
						xkv = i;
						ykv = j;
						vrh = matrica.at(i).at(j);
					}
					if (JednakiVrhovi(brojprstena, brkk))
						Poredjenje(matrica, xkv, ykv, i, j, vrh);
				}
			}
		}
	trazena = NapraviNajvecuPlaninuMatrice(xkv, ykv, brkk, matrica);
}
	return trazena;
}



int main ()
{
	cout << "Unesite dimenzije Matrice (m i n): ";
	int m, n;
	cin >> m >> n;
	if(m<0 || n<0) {
		cout << "Dimenzije Matrice moraju biti nenegativne:";
		return 0;
	}
	
	Matrica matrica;
	cout << "Unesite elemente Matrice: ";
	for (int i(0); i<m; i++) {
		matrica.resize(1+i);
		for (int j(0); j<n; j++) {
			double clan;
			cin >> clan;
			matrica.at(i).push_back(clan);
		}
	}
	
	Matrica trazenaMatrica = NajvecaPlaninaMatrice(matrica);
	cout << endl << "Najveca planina unesene Matrice je: " << endl;
	for (int i(0); i<trazenaMatrica.size(); i++){
		for (int j(0); j<trazenaMatrica.at(i).size(); j++)
			cout << std::right << std::setw(6) << trazenaMatrica.at(i).at(j);
		cout << endl;
	}
	return 0;
}