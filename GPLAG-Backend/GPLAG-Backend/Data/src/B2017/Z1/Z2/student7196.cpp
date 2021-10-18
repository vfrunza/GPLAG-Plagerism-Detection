#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

double SrednjiElement(std::vector<std::vector<double>> matrica) {
	int srednji((matrica.size())/2);
	return matrica.at(srednji).at(srednji);
}

int MinUdaljenostOdRuba(std::vector<std::vector<double>> matrica, int i, int j) {
	int min;
	min=i;
	if (matrica.size()-(i+1)<min) min=matrica.size()-(i+1);
	if (j<min) min=j;
	if ((matrica.at(i)).size()-(j+1)<min) min=(matrica.at(i)).size()-(j+1);
	return min;
}

double MaxElementMatrice(std::vector<std::vector<double>> matrica) {
	double max;
	max=matrica.at(0).at(0);
	for (int i=0; i<matrica.size(); i++) {
		for (int j=0; j<(matrica.at(i)).size(); j++) {
			if (matrica.at(i).at(j)>max) max=matrica.at(i).at(j);
		}
	}
	return max;
}

double SumaPrstenaKtogReda(std::vector<std::vector<double>> matrica, int i, int j, int k) {
	if (k==0) return matrica.at(i).at(j);
	double suma(0);
	for (int x=j-k; x<j+k; x++) suma+=matrica.at(i-k).at(x);
	for (int x=j-k; x<j+k; x++) suma+=matrica.at(i+k).at(x);
	for (int x=i-k; x<j+k; x++) suma+=matrica.at(x).at(j-k);
	for (int x=i-k; x<j+k; x++) suma+=matrica.at(x).at(j+k);
	return suma;
}

bool GrbavaMatrica(std::vector<std::vector<double>> matrica) {
	for (int i=0; i<matrica.size(); i++) {
		for (int j=i+1; j<matrica.size(); j++) {
			if ((matrica.at(i)).size()!=(matrica.at(j)).size()) return true;
		}
	}
	return false;
}

double MaxElement(std::vector<double> v) {
	double max;
	max=v.at(0);
	for (int i=1; i<v.size(); i++) {
		if (v.at(i)>max) max=v.at(i);
	}
	return max;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> maxplanina;
	
	if (matrica.size()==0) return maxplanina;
	
	for (int i=0; i<matrica.size(); i++) {
		if ((matrica.at(i)).size()==0) return maxplanina;
	}
	
	if (GrbavaMatrica(matrica)) throw std::domain_error("Matrica nije korektna");
	
	if (matrica.size()==1) {
		std::vector<double> vektor;
		vektor=matrica.at(0);
		double max(MaxElement(vektor));
		maxplanina.resize(1);
		(maxplanina.at(0)).push_back(max);
		return maxplanina;
	}
	
	maxplanina.resize(1);
	(maxplanina.at(0)).push_back(MaxElementMatrice(matrica));
	int iks(0), ipsilon(0);
	int pomocna(0);
	for (int i=0; i<matrica.size(); i++) {
		for (int j=0; j<(matrica.at(i)).size(); j++) {
			if (matrica.at(i).at(j)==MaxElementMatrice(matrica)) {
				iks=i;
				ipsilon=j;
				pomocna=5;
				break;
			}
		}
		if (pomocna==5) break;
	}
	for (int i=0; i<matrica.size(); i++) {
		for (int j=0; j<(matrica.at(i)).size(); j++) {
			double trenutna(0), nova(0);
			for (int k=1; k<=MinUdaljenostOdRuba(matrica, i, j); k++) {
				trenutna=SumaPrstenaKtogReda(matrica, i, j, k-1);
				nova=SumaPrstenaKtogReda(matrica, i, j, k);
				if (nova>=trenutna) {
					if (k-1>maxplanina.size()/2 || (k>1 && k-1==maxplanina.size()/2 && matrica.at(i).at(j)>SrednjiElement(maxplanina)) 
					|| (k>1 && k-1==maxplanina.size()/2 && matrica.at(i).at(j)==SrednjiElement(maxplanina) && i<iks) 
					|| (k>1 && k-1==maxplanina.size()/2 && matrica.at(i).at(j)==SrednjiElement(maxplanina) && i==iks && j<ipsilon)) {
						std::vector<std::vector<double>> novamatrica;
						novamatrica.resize(2*(k-1)+1);
						int brojac(0);
						for (int x=i-k; x<=i+k; x++) {
							for (int y=j-k; y<=j+k; y++) {
								(novamatrica.at(brojac)).push_back(matrica.at(x).at(y));
							}
							brojac++;
						}
						maxplanina=novamatrica;
						iks=i;
						ipsilon=j;
						break;
					}
				}
				else if (k==MinUdaljenostOdRuba(matrica, i, j)) {
					if (k>maxplanina.size()/2 || (k==maxplanina.size()/2 && matrica.at(i).at(j)>SrednjiElement(maxplanina)) 
					|| (k==maxplanina.size()/2 && matrica.at(i).at(j)==SrednjiElement(maxplanina) && i<iks) 
					|| (k==maxplanina.size()/2 && matrica.at(i).at(j)==SrednjiElement(maxplanina) && i==iks && j<ipsilon)) {
						std::vector<std::vector<double>> novamatrica;
						novamatrica.resize(2*k+1);
						int brojac(0);
						for (int x=i-k; x<=i+k; x++) {
							for (int y=j-k; y<=j+k; y++) {
								(novamatrica.at(brojac)).push_back(matrica.at(x).at(y));
							}
							brojac++;
						}
						maxplanina=novamatrica;
						iks=i;
						ipsilon=j;
						break;
					}
				}
			}
		}
	}
	return maxplanina;
}

int main ()
{
	int m, n, broj;
	std::vector<std::vector<double>> matrica;
	
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 1;
	}
	matrica.resize(m);
	std::cout << "Unesite elemente matrice: ";
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			std::cin >> broj;
			matrica.at(i).push_back(broj);
		}
	}
	
	std::cout << std::endl << "Najveca planina unesene matrice je:" << std::endl;
	std::vector<std::vector<double>> nova;
	nova=NajvecaPlaninaMatrice(matrica);
	
	for (int i=0; i<nova.size(); i++) {
		for (int j=0; j<(nova.at(0)).size(); j++) {
			std::cout << std::right << std::setw(6) << nova.at(i).at(j);
		}
		std::cout << std::endl;
	}
	
	return 0;
}