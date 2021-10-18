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
#include <stdexcept>
#include <iomanip>

const double eps (0.00001);

double ZbirRubnihElemenata (std::vector<std::vector<double>> m, int i, int j, int vel)
{
	double zbir(0.0);
	for (int k (j) ; k < j + vel ; k++) {
		zbir += m.at(i).at(k);
	}
	for (int k(i + 1) ; k < i + vel ; k++) {
		zbir += m.at(k).at(j) + m.at(k).at(j + vel - 1);
	}
	for (int k(j + 1) ; k < j + vel - 1 ; k++) {
		zbir += m.at(i + vel - 1).at(k);
	}
	return zbir;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> m)
{
	if (m.size() == 1) {
		double max(m.at(0).at(0));
		for (int i = 0 ; i < 1 ; i++) {
			for (int j = 0 ; j < m.at(0).size() ; j++) {
				if (m.at(i).at(j) > max)
					max = m.at(i).at(j);
			}
		}
		std::vector<std::vector<double>> matrica(1, std::vector<double>(1, max));

		return matrica;
	}

	else {

		std::vector<std::vector<double>> planina;
		// provjera da li je poslana matrica 0x0, 0xn, nx0
		if (m.size() == 0 || m.at(0).size() == 0)
			return planina;

		//provjera da li je matrica grbava
		for (int i = 1 ; i < m.size() ; i++)
			if (m.at(i).size() != m.at(i - 1).size())
				throw std::domain_error ("Matrica nije korektna");


		int pozicijaI(1), pozicijaJ(1), maxVel(1), minI(m.size() - 1), minJ(m.at(0).size() - 1);
		double najveciVrh = m.at(1).at(1);
		//prolazak kroz primljenu matricu i potraga za planinom
		for (int i = 1 ; i < m.size() - 1 ; i++) {
			for (int j = 1 ; j < m.at(i).size() - 1 ; j++) {
				int k(i - 1), l(j - 1), vel(3);
				double prethodni(m.at(i).at(j));
				double trenutni;
				while (k >= 0 && l >= 0 && k + vel <= m.size() && l + vel <= m.at(i).size()) {
					trenutni = ZbirRubnihElemenata(m, k, l, vel);
					if (trenutni >= prethodni)
						break;

					k--;
					l--;
					vel += 2;
					prethodni = trenutni;
				}
				if (fabs(trenutni - prethodni) < eps) {
					k++;
					l++;
					vel -= 2;

					if (vel > maxVel) {
						maxVel = vel;
						pozicijaI = k;
						pozicijaJ = l;
					} else if (vel == maxVel && m.at(i).at(j) > najveciVrh) {
						najveciVrh = m.at(i).at(j);
						pozicijaI = k;
						pozicijaJ = l;
					} else if (vel == maxVel && fabs(m.at(i).at(j) - najveciVrh) < eps) {
						if (i < minI) {
							minI = i;
							pozicijaI = i;
							pozicijaJ = j;
						} else if (i == minI && j < minJ) {
							minJ = j;
							pozicijaI = i;
							pozicijaJ = j;
						}
					}

				}
			}
		}
		// prepisivanje planine u novi vektor vektora
		for (int i(pozicijaI) ; i < pozicijaI + maxVel ; i++) {
			std::vector<double> red;
			for (int j(pozicijaJ) ; j < pozicijaJ + maxVel ; j++) {
				red.push_back(m.at(i).at(j));
			}
			planina.push_back(red);
		}

		return planina;
	}
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m, n;
	std::cin >> m >> n;
	if (m < 0 || n < 0)
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
	else {
		std::cout << "Unesite elemente matrice: ";

		std::vector<std::vector<double>> matrica (m, std::vector<double>(n));

		for (int i = 0 ; i < matrica.size() ; i++) {
			for (int j = 0 ; j < matrica.at(i).size() ; j++) {
				std::cin >> matrica.at(i).at(j);

			}
		}


		std::vector<std::vector<double>> b (NajvecaPlaninaMatrice(matrica));
		try {
			std::cout << std::endl << "Najveca planina unesene matrice je: " << std::endl;
			for (int i = 0 ; i < b.size() ; i++) {
				for (int j = 0 ; j < b.at(i).size() ; j++) {
					std::cout << std::setw(6) << b.at(i).at(j);
				}
				std::cout << std::endl;
			}
		} catch (std::domain_error izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	}


	return 0;
}