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
#include <stdexcept>
#include <iomanip>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice(Matrica ulazna)
{
	Matrica izlazna;
	if(ulazna.size()==0) return izlazna;
	else if(ulazna.at(0).size()==0) return izlazna;
	for(int i(0); i<ulazna.size(); i++) {
		if(ulazna.at(i).size()!=ulazna.at(0).size()) throw std::domain_error("Matrica nije korektna");
	}
	izlazna.push_back(std::vector<double> (1, ulazna.at(0).at(0)));
	int red(1), i_koordinata(0), j_koordinata(0);
	double vrh(ulazna.at(0).at(0));
	int manja_dimenzija(ulazna.size());
	if(manja_dimenzija>ulazna.at(0).size()) manja_dimenzija=ulazna.at(0).size();
	if(manja_dimenzija%2==0) manja_dimenzija--;
	for(int duzina(manja_dimenzija); duzina>=1; duzina-=2) {
		for(int i(duzina/2); i<ulazna.size()-duzina/2; i++) {
			for(int j(duzina/2); j<ulazna.at(i).size()-duzina/2; j++) {
				double suma(0);
				if(duzina!=1) {
					for(int i1(i-1); i1<=i+1; i1++) {
						for(int j1(j-1); j1<=j+1; j1++) {
							if(!(i1==i && j1==j)) {
								suma+=ulazna.at(i1).at(j1);
							}
						}
					}
				}
				if((duzina==1 || suma<ulazna.at(i).at(j)) && duzina>=red) {
					Matrica pomocna(duzina, std::vector<double>(duzina));
					for(int i1(i-duzina/2); i1<=i+duzina/2; i1++) {
						for(int j1(j-duzina/2); j1<=j+duzina/2; j1++) {
							pomocna.at(i1-i+duzina/2).at(j1-j+duzina/2)=ulazna.at(i1).at(j1);
						}
					}
					double vrh_pomocne(ulazna.at(i).at(j));
					if(duzina>red) {
						izlazna=pomocna;
						red=duzina;
						i_koordinata=i;
						j_koordinata=j;
						vrh=vrh_pomocne;
					} else if(duzina==red) {
						if(vrh_pomocne>vrh) {
							izlazna=pomocna;
							i_koordinata=i;
							j_koordinata=j;
							vrh=vrh_pomocne;
						} else if(!(fabs(vrh-vrh_pomocne)>0.0)) {
							if(i<i_koordinata || (i_koordinata==i && j<j_koordinata)) {
								izlazna=pomocna;
								i_koordinata=i;
								j_koordinata=j;
								vrh=vrh_pomocne;
							}
						}
					}
				}
			}
		}
	}
	return izlazna;
}

int main ()
{
	Matrica pocetna;
	int m, n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	for(int i(0); i<m; i++) {
		pocetna.push_back(std::vector<double>(n));
	}
	std::cout << "Unesite elemente matrice:\n";
	for(int i(0); i<m; i++) {
		for(int j(0); j<n; j++) {
			std::cin >> pocetna.at(i).at(j);
		}
	}
	try {
		Matrica najveca(NajvecaPlaninaMatrice(pocetna));
		std::cout << "Najveca planina unesene matrice je:\n";
		for(std::vector<double> x: najveca) {
			for(double y: x) {
				std::cout << std::right << std::setw(6) << y;
			}
			std::cout << std::endl;
		}
	} catch(std::domain_error &p) {
		std::cout << "Izuzetak: " << p.what() << std::endl;
	}
	return 0;
}