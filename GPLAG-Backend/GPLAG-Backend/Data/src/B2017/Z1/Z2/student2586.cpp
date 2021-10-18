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

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> mat)
{
	std::vector<std::vector<double>> planina(mat);
	if(mat.size()==0) {
		planina.resize(0);
		return planina;
	}
	for(int i(0); i<mat.size(); i++) {								//bacanje izuzetka
		if(mat.at(0).size()!=mat.at(i).size()) throw std::domain_error("Matrica nije korektna");
	}
	int max(mat.at(0).at(0));						//trazenje maximalnog elementa u matrici
	for(int i(0); i<mat.size(); i++) {
		for(int j(0); j<mat.at(i).size(); j++) {
			if(mat.at(i).at(j)>max) max=mat.at(i).at(j);
		}
	}
	if(mat.size()<3 or mat.at(0).size()<3) {	//kad su dimenzije m i n manje od 3 vracamo najveci element
		std::vector<double> pomoc;
		planina.resize(0);
		pomoc.push_back(max);
		planina.push_back(pomoc);
		return planina;
	}
	int suma(0);
	for(int i(0); i<mat.size(); i++) {
		for(int j(0); j<mat.at(i).size(); j++) {
			if(mat.at(i).at(j)==max) {
				for(int k(i-1); k<i+2; k++ ) {
					for(int g(j-1); g<j+2; g++) {
						suma+=mat.at(k).at(g);
					}
				}
				suma=suma-max;
				if(suma<max) {
					planina.resize(0);
					for(int k(i-1); k<i+2; k++ ) {
						std::vector<double>  pomocni;
						for(int g(j-1); g<j+2; g++) {
							pomocni.push_back(mat.at(k).at(g));
						}
						planina.push_back(pomocni);
					}
					break;
				}
			}
		}
	}
	return planina;
}

int main ()
{

	try {
		std::cout << "Unesite dimenzije matrice (m i n): " ;
		int m,n;
		std::cin >> m;
		std::cin >> n;
		if(m<0 or n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!" ;
			return 0;
		}
		std::cout << "Unesite elemente matrice: " << std::endl;
		std::vector<std::vector<double>> matrica;
		for(int i(0); i<m; i++) {
			std::vector<double> pomocni;
			for(int j(0); j<n; j++) {
				double broj;
				std::cin >> broj;
				pomocni.push_back(broj);
			}
			matrica.push_back(pomocni);
			pomocni.resize(0);
		}
		std::cout << "Najveca planina unesene matrice je: " << std::endl;
		std::vector<std::vector<double>> najvecaPlanina(NajvecaPlaninaMatrice(matrica));

		for(std::vector<double>  vek: najvecaPlanina) {
			for(double broj: vek) {
				std::cout << std::right <<std::setw(6)<< broj ;
			}
			std::cout  << std::endl;
		}
	} catch(std::domain_error poruka) {
		std::cout << poruka.what();
	}
	return 0;
}