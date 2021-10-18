/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector <std::vector <double>> Matrica;

Matrica v (Matrica m) {
	
	if (m.empty()) 
	    return {};
	    
	Matrica rezultat = m;
	int broj_redova = rezultat.size();
	int broj_kolona = rezultat[0].size();
	double temp;
	
	for (int i = 0; i < broj_redova/2; i++) {

		
		for (int j = 0; j != broj_kolona; j++) {
			temp = rezultat[i][j];
			rezultat[i][j] = rezultat [broj_redova - 1 - i][j];
			rezultat [broj_redova - 1 - i][j] = temp;
		}
	}
	
	return rezultat;
}

Matrica h(Matrica m) {
	Matrica rezultat = m;
	
	
	if (m.empty()) {

	    return {} ;
	}

	int broj_kolona = rezultat[0].size();
	
	for (int i = 0; i < rezultat.size(); i++) {
		
		double temp;
		
		for (int j = 0; j < rezultat[0].size() / 2; j++) {
			temp = rezultat[i][j];
			rezultat[i][j] = rezultat[i][broj_kolona - 1 - j];
			rezultat[i][broj_kolona - 1 - j] = temp;
		}
	}
	return rezultat;
}

Matrica hv (Matrica m) {
	
	Matrica rezultat = m;
	rezultat = v(rezultat);
	rezultat = h(rezultat);
	return rezultat;
}


Matrica OgledaloMatrica (Matrica m1) {

	if (m1.empty()) {
		return {};
	}
	
	for (int i = 0; i < m1.size() - 1; i++) {
			if (m1[i].size() != m1[i+1].size()) {
				throw std::domain_error ("Matrica nije korektna");
			}
		}
	Matrica ho = h(m1);
	Matrica vo = v(m1);
	Matrica hov = hv(m1);
	
	
	const int m = m1.size();
	const int n = m1[0].size();
	
	Matrica rezultat (3 * m, std::vector <double> (3 * n));
	
	for (int i = 0; i < 3 * m; i++) {
		for (int j = 0; j < 3 * n; j++) {
			if (i < m) {
				if (j >= n && j < 2 * n) {
					rezultat [i][j]=vo[i][j%n];	
				}
				else {
					rezultat [i][j]=hov[i][j%n];
				}
			}
			
			if (i >= m && i < 2 * m) {
				if (j >= n && j < 2 * n) {
					
					rezultat[i][j] = m1 [i%m][j%n];
				}
				else {
					rezultat[i][j] = ho [i%m][j%n];
				}
			}
				if (i >= 2 * m && i <= 3 * m - 1) {
					if (j >= n && j < 2 * n) {
						rezultat[i][j] = vo [i%m][j%n];
					}
					else {
						rezultat[i][j] = hov [i%m][j%n];
					}
				}
		}
		
	}
	return rezultat;
}

int main ()
{
	try {
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica glavna (m, std::vector<double> (n));

	std::cout << "Unesite elemente matrice:" << std::endl;
	for (int i=0; i<glavna.size(); i++) {
		for(int j=0; j<glavna[0].size(); j++) {
			std::cin >> glavna[i][j];
		}
	}
	
	Matrica Krajnja = OgledaloMatrica(glavna);
	std::cout << "Rezultantna matrica:" << std::endl;
		for (int i=0; i < Krajnja.size(); i++) {
			for (int j=0; j < Krajnja[0].size(); j++) {
			std::cout << std::setw(4) << Krajnja [i][j];
			}
			std::cout << std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}