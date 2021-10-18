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
#include <limits>
#include <stdexcept>
#include <iomanip>

double ElementiOkoPlanine (std::vector<std::vector<double>> matrica, int y, int x, int broj, double prvasuma) {
	if (x==0 || y==0 || matrica.size() == y + 1 || matrica.at(0).size() == x + 1 || x - broj/2 < 0 || x + broj/2 > matrica.at(0).size() - 1 || y - broj/2 < 0 || y + broj/2 > matrica.size() - 1) {
		return 0;
	}
	
	double suma(0), temp(0);
	
	for (int i(-broj/2); i < broj/2 + 1; i++) {
		for (int j(-broj/2); j < broj/2 + 1; j++) {
			if (j == -broj/2 || j == broj/2 || i == broj/2 || i == -broj/2) {
				temp += matrica.at(y + 1).at(x + j);
			}
			suma += temp;
			temp = 0;
		}
			if (suma < prvasuma) {
				return suma;
			}
			return 0;
	}
}

bool DaLiJeGrbava (std::vector<std::vector<double>> matrica) {
	if (matrica.size() == 0) return false;
	else {
		int m(matrica.size()), n(matrica.at(0).size());
		
		for (int i(0); i < matrica.size(); i++) {
			for (int j(0); j < matrica.at(i).size(); j++) {
				if (m == matrica.size()) break;
				else throw std::domain_error("Matrica nije korektna");
			}
			if(!(n==matrica.at(i).size())) throw std::domain_error("Matrica nije korektna");
		}
	}
	return false;
}

std::vector<std::vector<double>> SaljiUMatricu (std::vector<std::vector<double>> matrica, int x, int y, int broj) {
	std::vector<std::vector<double>> novamatrica;
	
	std::vector<double> pomocni;
	
	for (int i(-broj/2); i < broj/2 + 1; i++) {
		for (int j(-broj/2); j < broj/2 + 1; j++) {
			pomocni.push_back(matrica.at(y + 1).at(x + j));
		}
		novamatrica.push_back(pomocni);
		pomocni.clear();
	}
		return novamatrica;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> matrica) {
	bool postoji(false);
	postoji = DaLiJeGrbava(matrica);
	
	std::vector<std::vector<double>> nova;
	
	std::vector<double> pomocni;
	
	double vrh(0), suma(0), nb(0), jednodimenzionalnivrh(0);
	int broj(3), max(0), y(0), x(0), mini = std::numeric_limits<int>::min();
	
	for (auto i : matrica) {
		for (auto j : i) {
			if (j > mini) {
				vrh = j;
				jednodimenzionalnivrh=vrh;
				suma=ElementiOkoPlanine(matrica, y, x, broj, vrh);
				if (suma != 0) {
				    while(1) {
						if (postoji==false && max < broj/2) {
							nova = SaljiUMatricu(matrica, y, x, broj);
							postoji=true;
							max++;
						}
						broj += 2;
						nb=ElementiOkoPlanine(matrica, y, x, broj, suma);
						if(nb != 0) {
							postoji = false;
							suma = nb;
						}
						if (postoji == true) break;
					}
				}
				broj = 3;
				suma = 0;
			}
			x++;
		}
		x=0;
		y++;
	}
	if(nova.size() == 0 && matrica.size() != 0) {
		pomocni.push_back(jednodimenzionalnivrh);
		nova.push_back(pomocni);
	}
	return nova;
}


int main ()
{
	
	try {
		int m(0), n(0);
		double unos(0);
		std::vector<double> pomocni;
		std::vector<std::vector<double>> pomocna1;
		std::vector<std::vector<double>> pomocna2;
		
		std::cout << "Unesite dimenzije matrice (m i n): ";
		
		while(1) {
			std::cin >> unos;
			if(int(unos)/unos==1) {
				m=unos;
				break;
			}
			std::cout << "Dimenzije moraju biti cijeli brojevi!!!";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		while(1) {
			std::cin >> unos;
			if(int(unos)/unos==1) {
				n=unos;
				break;
			}
			std::cout << "Dimenzije moraju biti cijeli brojevi!!!";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		if (m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
		}
		std::cout << "Unesite elemente matrice: ";
		for (int i(0); i<m; i++) {
			for (int j(0); j<n; j++) {
				while(1) {
					while (!std::cin) {
						std::cout << "To nije broj!";
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}
					if (std::cin) {
						pomocni.push_back(unos);
						break;
					}
				}
			}
			pomocna1.push_back(pomocni);
			pomocni.clear();
		}
		pomocna2=NajvecaPlaninaMatrice(pomocna1);
		std::cout << std::endl << "Najveca planina matrice je: " << std::endl;
		for (auto i : pomocna2) {
			for (auto j : i) {
				std::cout << std::setw(6) << j;
			}
			std::cout << std::endl;
		}
		}
		catch (...) {
			std::cout << std::endl;
		}
	return 0;
}