#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>

typedef std::vector<std::vector<double>> matrica;

matrica Najveci(matrica mat)
{
	double max = mat.at(0).at(0);
	matrica mat2;
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat.at(i).size(); j++) {
			if(mat.at(i).at(j) > max) max = mat.at(i).at(j);
		}
	}
	mat2.resize(1);
	mat2.at(0).push_back(max);
	return mat2;
}

bool Dalijekorektna(matrica m)
{
	int duzina(m.at(0).size());
	if(m.size() > 1) {
		for(int i = 1; i < m.size(); i++) {
			if(duzina != m.at(i).size()) return false;
		}
	}
	return true;
}

matrica NajvecaPlaninaMatrice(matrica m)
{
	int suma(0),suma1(0);
	bool ivica(false),prvi(false);
	matrica vratit,vratit2,maxvratit;
	
	if(m.size() == 0 || m.at(0).size() == 0) return vratit;
	if(Dalijekorektna(m) == false) throw std::domain_error("Matrica nije korektna");
	if(m.size() < 3 || m.at(0).size() < 3) return Najveci(m);

	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m.at(i).size(); j++) { // prvi prolazak
			ivica = false;
			if((i != 0 && j != 0) && (i != m.size()-1 && j != m.at(i).size()-1)) {
				suma1 = m.at(i).at(j);
				int vel;
				if(m.size() < m.at(i).size())  vel = m.size();
				else vel = m.at(i).size();
				for(int n = 1; n <= vel/2; n++) {
					if(ivica == true) break; // ako je neki element u sumi na ivici ne ne siriti dalje
					suma = 0;
					vratit.resize(2*n);
					vratit.insert(vratit.begin() + 0, std::vector<double> (0));
					for(int p = 0; p < vratit.size(); p++) {
						vratit.at(p).resize(0);
					}
					int broj(0);
					for(int l = 0; l < m.size(); l++) {
						for(int k = 0; k < m.at(i).size(); k++) { // drugi prolazak

							if(abs(i - l) == n && abs(k - j) <= n && (l != i)) {
								suma += m.at(l).at(k);
								if(l == 0 || k == 0 || l == m.size()-1 || k == m.at(0).size()-1) ivica = true;
							} else if(abs(k - j) == n && abs(i - l) <= n && (k != j)) {
								suma += m.at(l).at(k);
								if(l == 0 || k == 0 || l == m.size()-1 || k == m.at(0).size()-1) ivica = true;
							}

							if(abs(i - l) <= n && abs(k - j) <= n && (l != i)) {
								vratit.at(broj).push_back(m.at(l).at(k));
								if(vratit.at(broj).size() == (2*n+1)) broj++;
							} else if(abs(k - j) <= n && abs(i - l) <= n && (k != j)) {
								vratit.at(broj).push_back(m.at(l).at(k));
								if(vratit.at(broj).size() == (2*n+1)) broj++;
							} else if(l == i && k == j) {
								vratit.at(broj).push_back(m.at(l).at(k));
								if(vratit.at(broj).size() == (2*n+1)) broj++;
							}
						} // k petlja(j)
					}
					if(suma >= suma1) {
						vratit.resize(0);
						break;
					}
					vratit2 = vratit;
					if(prvi == false) {
						maxvratit = vratit2;
						prvi = true;
					} else {
						if(vratit2.size() > maxvratit.size()) maxvratit = vratit2;
						else if(vratit2.size() == maxvratit.size()) {
							if(vratit2.at(vratit2.size()/2).at(vratit2.size()/2) > maxvratit.at(maxvratit.size()/2).at(maxvratit.size()/2))
								maxvratit = vratit2;
						}
					}
					suma1 = suma;
				}
			} // prvi if
		} // j petlja

	}
	return maxvratit;
}

int main ()
{
	matrica mat,mat2;
	int m,n;
	try {
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m >> n;
		if(m < 0 || n < 0) throw "Dimenzije matrice moraju biti nenegativne!";
		mat.resize(m);
		for(int i = 0; i < m; i++) mat.at(i).resize(n);

		std::cout << "Unesite elemente matrice:" << std::endl;
		for(int i = 0; i < mat.size(); i++) {
			for(int j = 0; j < mat.at(i).size(); j++) {
				std::cin >> mat.at(i).at(j);
			}
		}

		mat2 = NajvecaPlaninaMatrice(mat);
		std::cout << "Najveca planina unesene matrice je:" << std::endl;
		for(int i = 0; i < mat2.size(); i++) {
			for(int j = 0; j < mat2.at(i).size(); j++) {
				std::cout <<std::setw(6)<< mat2.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	} catch(const char tekst[]) {
		std::cout << tekst;
	}

	return 0;
}