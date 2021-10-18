#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
    return fabs(x - y) <= Eps * (fabs(x) + fabs(y));
}

void Grbava(Matrica mat) {
	for (int i = 0; i < mat.size(); i++) { 
		if(i != 0 && mat.at(i-1).size() != mat.at(i).size()) throw std::domain_error("Matrica nije korektna");
		if (i == mat.size()-1) break;
	}
}

Matrica NajvecaPlaninaMatrice(Matrica mat) {
	Grbava(mat);
	Matrica planina;
	bool imaVrh(false);
	int imax, jmax, maxsirina(0);
	double maxvrh;
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat.at(i).size(); j++) {
			if (i >= 0 && i < mat.size() && j >= 0 && j < mat.at(i).size()) {
				double vrh(mat.at(i).at(j)), prethodna(vrh), nova(0);
				int sirina (1);
				while (i-sirina >= 0 && i+sirina < mat.size() && i+sirina > 0 && j-sirina >= 0 && j+sirina < mat.at(i).size() && j+sirina > 0) {
					nova = 0;
					for (int k = i-sirina; k <= i+sirina; k++) 
						for (int l = j-sirina; l <= j+sirina; l++) 
							if (k == i-sirina || k == i+sirina || l == j-sirina || l == j+sirina) nova += mat.at(k).at(l);
					if (prethodna < nova || JesuLiJednaki(prethodna,nova)) break;
					sirina++;
					prethodna = nova;
				} //ispitivanje velicine planine
				if (sirina-1 > maxsirina || (sirina-1 == maxsirina && (!imaVrh || vrh > maxvrh))) {
					maxsirina = sirina-1;
					imax = i; jmax = j;
					maxvrh = vrh;
					imaVrh = true;
				} //da li je nadjena planina najveca
			}
			if (j == mat.at(i).size()-1) break;
		}
		if (i == mat.size()-1) break;
	}
	if (imaVrh) {
		for (int i = imax - maxsirina; i <= imax + maxsirina; i++) {
			std::vector<double> redovi;
			for (int j = jmax - maxsirina; j <= jmax + maxsirina; j++) { 
				redovi.push_back(mat.at(i).at(j));
				if (j == jmax+maxsirina) break;
			}
			planina.push_back(redovi);
			if (i == imax+maxsirina) break;
		}
	} //kreiranje matrice
	return planina;
}

Matrica UnosMatrice(int m, int n) {
	Matrica mat;
	for (int i = 0; i < m; i++) {
		std::vector<double> v;
		double x;
		for (int j = 0; j < n; j++) {
			std::cin >> x;
			v.push_back(x);
		}
		mat.push_back(v);
	}
	return mat;
}

void IspisiMatricu(Matrica mat) {
	for (auto x : mat) {
		for (auto y : x) 
			std::cout << std::setw(6) << y;
		std::cout << std::endl;
	}
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	if (std::cin >> m >> n, m < 0 || n < 0) 
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
	else {
		std::cout << "Unesite elemente matrice:" << std::endl;
		Matrica mat(UnosMatrice(m,n));
		try {
			Matrica planina(NajvecaPlaninaMatrice(mat));
			std::cout << "Najveca planina unesene matrice je:" << std::endl;
			IspisiMatricu(planina);
		}
		catch(std::domain_error izuzetak) {
			std::cout << izuzetak.what();
		}
		catch(std::range_error izuzetak) {
			std::cout << izuzetak.what();
		}
	}	
	return 0;
}