#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

Matrica FormirajMatricu (int m, int n)
{
	return Matrica(m, std::vector<double> (n));
}

bool ProvjeraDimenzija (Matrica ulaz)
{
	int broj_kolona (ulaz.at(0).size());
	for(int i = 0; i < ulaz.size(); i++) {
		if(ulaz.at(i).size() != broj_kolona)
			throw std::domain_error ("Matrica nije korektna");
	}

	return true;
}

Matrica KreirajPodmatricu (Matrica ulaz, int m, int n, int dimenzija)
{

	int duzina (dimenzija * 2 + 1);
	Matrica planina (FormirajMatricu(duzina, duzina));

	int b(0), c(0);

	for(int i = m; i < dimenzija *2 + 1 + m; i++) {
		for (int j = n; j < dimenzija * 2 + 1 + n; j++) {
			planina.at(b).at(c) = ulaz.at(i).at(j);
			c++;
		}
		c = 0;
		b++;
	}
	return planina;
}

bool PorediPodmatrice (Matrica nova, Matrica stara)
{
	if (nova.size() == 0 && stara.size() == 0) return true;
	if(nova.size() > stara.size() ) return true;
	else if(nova.size() < stara.size()) return false;
	else {
		double vrh1 (nova.at(0).at(0));
		double vrh2 (stara.at(0).at(0));

		for(int i = 0; i < nova.size() ; i++ ) {
			for(int j = 0; j < nova.size(); j++) {
				if(nova.at(i).at(j) > vrh1) vrh1 = nova.at(i).at(j);
			}
		}
		for(int i = 0; i < stara.size() ; i++ ) {
			for(int j = 0; j < stara.size(); j++) {
				if(stara.at(i).at(j) > vrh2) vrh2 = stara.at(i).at(j);
			}
		}

		if(vrh1 > vrh2) return true;
		else return false;
	}
	return false;

}

int ManjaDimenzija (int m, int n)
{
	if (m < n && m % 2 != 0) return m;
	else if( m < n && m % 2 == 0) return m -1 ;
	else if (n < m && n % 2 == 0) return n -1;
	else if ( m == n && m % 2 == 0) return m -1;
	else
		return n;
}

Matrica NajvecaPlaninaMatrice (Matrica ulaz)
{

	Matrica Planina, testna;

	if(ulaz.size() == 0 || ulaz.at(0).size() == 0) return Planina;

	if(!ProvjeraDimenzija(ulaz)) exit(1);

	int manja (ManjaDimenzija(ulaz.size(), ulaz.at(0).size()));

	if(manja < 3) {

		double testna(ulaz.at(0).at(0));
		for(int i = 0; i < ulaz.size(); i++) {
			for(int j = 0; j <ulaz.at(0).size(); j++) {
				if(ulaz.at(i).at(j) > testna) {
					testna = ulaz.at(i).at(j);
				}
			}
		}

		Planina.resize(manja);
		Planina.at(0).push_back(testna);
	}


	for(int dimenzija = 0; dimenzija < manja-1; dimenzija+=2) {
		double suma_prstena (0), vanjski (std::numeric_limits<double>::lowest());

		for(int k = 0; k < ulaz.size() - (manja - dimenzija) + 1; k++) {
			for(int l = 0; l < ulaz.at(0).size() - (manja-dimenzija) + 1; l++) {

				for(int p = 0; p <= (manja-dimenzija)/2 ; p++ ) {

					for(int i = 0; i < ulaz.size(); i++) {
						for(int j = 0; j < ulaz.at(0).size(); j++) {

							if((i == k + p || j == l + p || i ==  manja - p - 1 + k || j == manja - p - 1 + l) &&
							        i <= manja - p - 1 + k && j <= manja - p - 1 + l && i >= p + k && j >= p + l)
								suma_prstena += ulaz.at(i).at(j);

							if(p == (manja - dimenzija)/2  && (i == ulaz.size() - 1) && (j == ulaz.at(0).size() - 1) && (suma_prstena > vanjski)) {

								int prvi_ulaz = k;
								int drugi_ulaz = l;
								testna = KreirajPodmatricu (ulaz, prvi_ulaz, drugi_ulaz, p);
								if(PorediPodmatrice(testna, Planina)) Planina = testna;

								vanjski = std::numeric_limits<double>::lowest();
							}
						}

					}

					if(suma_prstena > vanjski) {
						vanjski = suma_prstena;
						suma_prstena = 0;

					} else {
						vanjski = std::numeric_limits<double>::lowest();
						break;
					}
				}
				suma_prstena = 0;
				if(Planina.size() != 0) return Planina;

			}
		}
		if(Planina.size() == 0) {
			double trazilica(ulaz.at(0).at(0));
			for(int i = 0; i < ulaz.size(); i++) {
				for(int j = 0; j < ulaz.at(0).size(); j++)
					if(ulaz.at(i).at(j) > trazilica) trazilica = ulaz.at(i).at(j);
			}
			Planina.resize(1);
			Planina.at(0).push_back(trazilica);
		}

	}
	return Planina;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m, n;

	std::cin >> m >> n;

	if(m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}

	std::cout << "Unesite elemente matrice: " << std::endl;

	auto vektor_vektora (FormirajMatricu(m,n));

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> vektor_vektora.at(i).at(j);
		}
	}

	std::cout << "Najveca planina unesene matrice je: " << std::endl;

	auto rezultat (NajvecaPlaninaMatrice(vektor_vektora));

	for(int i = 0; i < rezultat.size(); i++) {
		for (int j = 0; j < rezultat.at(0).size(); j++) {
			std::cout << std::setw(6) << rezultat.at(i).at(j);
		}
		std::cout << std::endl;

	}

	return 0;
}