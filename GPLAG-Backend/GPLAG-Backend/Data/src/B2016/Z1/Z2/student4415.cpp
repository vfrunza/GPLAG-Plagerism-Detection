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



typedef std::vector<std::vector<double>> Matrica;

bool grbava (Matrica a)
{
	if (a.empty()) return false;
	int n = a[0].size();
	for (auto i : a) {
		if (i.size() != n) return true;
	}
	return false;
}
Matrica KrMatricu (int broj_redova, int broj_kolona)
{
	return Matrica (broj_redova,std::vector<double> (broj_kolona));
}

Matrica v_M (Matrica a)
{
	if (a.size() == 0) return a;
	Matrica b;
	for (int i = a.size()-1; i >= 0; i--) {
		b.push_back(a[i]);
	}
	return b;
}

Matrica h_M (Matrica a)
{
	if (a.size() == 0) return a;
	std::vector<double> b(0);
	if (a[0].size() == 0) return a;

	for (int i = 0; i < a.size(); i++) {
		b.resize(0);
		for (int j = a[i].size()-1; j >= 0; j--) {
			b.push_back(a[i][j]);
		}
		a[i] = b;
	}


	return a;
}

Matrica hv_M (Matrica a)
{
	Matrica b = h_M(a);
	b = v_M(b);
	return b;
}

Matrica OgledaloMatrica (Matrica a)
{
	if (a.empty()) return Matrica (0);
	if (grbava(a)) throw std::domain_error("Matrica nije korektna");
	int redovi = a.size();
	int kolone = a[0].size();
	Matrica b = KrMatricu(3*a.size(),3*a[0].size());
	Matrica h = h_M(a);
	Matrica v = v_M(a);
	Matrica hv = hv_M(a);

	for (int i = 0; i < 3*redovi; i++) {
		for (int j = 0; j < 3*kolone; j++) {
			if (i < redovi and j < kolone) b[i][j] = hv[i][j]; // gornja lijeva

			else if (i >= redovi and i < 2*redovi && j < kolone) b[i][j] = h[i-redovi][j]; // srednja lijeva

			else if (i >= 2*redovi and j < kolone) b[i][j] = hv [i-2*redovi][j];// donja lijeva

			else if (i < redovi and j >= kolone and j < 2*kolone) b[i][j] = v[i][j-kolone];// gornja sredjna

			else if (i < redovi and j >= 2*kolone) b[i][j] = hv[i][j-2*kolone]; // gornja desna

			else if (i >= redovi and i < 2*redovi and j >= kolone and j < 2*kolone) b[i][j] = a[i-redovi][j-kolone]; // sred sred

			else if (i >= redovi and i < 2*redovi and j >= 2*kolone) b[i][j] = h[i-redovi][j-2*kolone]; // sred desna

			else if (i >= 2*redovi and j >= kolone and j < 2*kolone) b[i][j] = v[i-2*redovi][j-kolone]; // donja sred

			else if (i >= 2*redovi and j >= 2*kolone) b[i][j] = hv[i-2*redovi][j-2*kolone];// donja desna
		}
	}
	return b;
}

int main ()
{

	int m,n;

	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if (m < 0 or n < 0 ) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	std::cout << "Unesite elemente matrice: " << std::endl;
	Matrica a = KrMatricu(m,n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
	try {
		Matrica b = OgledaloMatrica(a);
		std::cout << "Rezultantna matrica: " << std::endl;
		for (auto i : b) {
			for (auto i2 : i) {
				std::cout << std::setw(4) << i2;
			}
			std::cout  << std::endl;
		}
	} catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}
