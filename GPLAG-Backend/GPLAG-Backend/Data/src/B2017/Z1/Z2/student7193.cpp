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
#include <cmath>
#include<iomanip>
#define eps 0.00001

bool Poredi (double a, double b) {
	return fabs(a - b) < eps;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> Planina, pomocnaPlanina;
	
	if (matrica.size() == 0) {
		return Planina;
	}
	
	for (int i = 0; i < matrica.size(); i++) {
		if (matrica.at(i).size() != matrica.at(0).size()) {
			throw std::domain_error ("Matrica nije korektna");
		}
	}
	
	
	int i,j,k,l=0, korak(3);
	double suma=0, novaSuma(0);
	for(i=0; i<matrica.size(); i++) {
		for(j=0; j<matrica.size(); j++) {
			
			if (i == 0 || i == matrica.size()-1 || j == 0 || j == matrica.at(0).size()-1) {
				continue;
			}
			k=i-1;
			l=j-1;
			
			for(int m=k; m<k+3; m++) { //prva 3*3
				for(int n=l; n<l+3; n++) {
					if(m == i && n == j) {
						continue;
					}
					else {
						suma+=matrica.at(m).at(n);
					}
				}
			}
			if (suma < matrica.at(i).at(j)) {
			
				if (k == 0 || l == 0) {
					int g(0);
					pomocnaPlanina.resize(korak);
					for (int m = k; m < k+korak; m++) {
						pomocnaPlanina.at(g++).resize(0);
						for(int n=k; n<l+korak; n++) {
							pomocnaPlanina.at(m).push_back(matrica.at(m).at(n));
						}
					}
				} else {
					ponovo:
					k--;
					l--;
					novaSuma = suma;
					korak += 2;
					if (k < 0 || korak > matrica.size() || korak > matrica.at(0).size()) {
						break;
					}
					
					for (int m = k; m < k+korak; k++) {
						for(int n=k; n<l+korak; n++) {
							if (k == m || l == n || m == k+korak-1 || n == l+korak-1) {
								suma+=matrica.at(m).at(n);
							}
						}
					}
					if (suma < novaSuma) {
						pomocnaPlanina.resize(korak);
						int g=0;
						for (int m = k; m < k+korak; m++) {
							pomocnaPlanina.at(g++).resize(korak);
							for (int n = l; n < l+korak; n++) {
								pomocnaPlanina.at(m).push_back(matrica.at(m).at(n));
							}
						}
						if (k != 0 || l != 0) {
							goto ponovo;
						}
					} else {
						break;
					}
					
				}
				
			}
			if (pomocnaPlanina.size() > Planina.size()) {
				
				Planina.resize(pomocnaPlanina.size());
				for (int m = 0; m < pomocnaPlanina.size(); m++) {
					Planina.at(m).resize(pomocnaPlanina.at(0).size());
					for (int n = 0; n < pomocnaPlanina.at(0).size(); n++) {
						Planina.at(m).at(n) = pomocnaPlanina.at(m).at(n);
					}
				}
			} else if (pomocnaPlanina.size() == Planina.size()) {
				int a((Planina.size()/2)+1), b((pomocnaPlanina.size()/2)+1);
				if (Poredi(Planina.at(a).at(a), pomocnaPlanina.at(b).at(b))) {
					Planina.resize(pomocnaPlanina.size());
					for (int m = 0; m < pomocnaPlanina.size(); m++) {
						Planina.at(m).resize(pomocnaPlanina.at(0).size());
						for (int n = 0; n < pomocnaPlanina.at(0).size(); n++) {
							Planina.at(m).at(n) = pomocnaPlanina.at(m).at(n);
						}
					}
				}
			}
		}
	}
	return Planina;
}
int main ()
{
	try {

		std::vector<std::vector<double>> mat;
		int m, n;
		double element;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin>>m>>n;
		 if (m<0 ||  n<0)
		{ std::cout << "Dimenzije matrice moraju biti nenegativne!"; return 0; }
		
	
		
		std::cout << "Unesite elemente matrice: " << std::endl;
		mat.resize(m);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> element;
				mat.at(m).push_back(element);
			}
		}	
		std::vector<std::vector<double>> planina(NajvecaPlaninaMatrice(mat));
		std::cout<<"Najveca planina unesene matrice je"<<std::endl;
		for (int i = 0; i < planina.size(); i++) {
			for (int j = 0; j < planina.size(); j++) {
				std::cout <<std::setw(6)<< planina.at(i).at(j);
			}
			std::cout << std::endl;
		}
		
	}
	catch (std::domain_error error) {
		std::cout << error.what() << std::endl;
	}
	
	
	
	return 0;
}