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

#define pb push_back
std::vector<double> ObrniVektor(std::vector<double> vect) {
	std::vector<double> ret;
	for (int i = vect.size() - 1; i >= 0; i--) ret.pb(vect.at(i));
	return ret;
}
std::vector<std::vector<double>> HorizontalnoOgledalo(std::vector<std::vector<double>> ma) {
	std::vector<std::vector<double>> ret;
	for (int i = 0; i < ma.size(); i++) {
		ret.pb(ObrniVektor(ma.at(i)));
	}
	return ret;
}
std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>> ma) {
	std::vector<std::vector<double>> ret;
	for (int i = ma.size() - 1; i >= 0; i--)
		ret.pb(ma.at(i));
	return ret;
}
bool GrbavaMatrica(std::vector<std::vector<double>> ma) {
	for (int i = 1; i < ma.size(); i++)
		if (ma.at(i).size() != ma.at(0).size()) return 1;
	return 0;
}
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> ma) {
	
	if (GrbavaMatrica(ma)) {
		throw std::domain_error("Matrica nije korektna");
	}
	std::vector<std::vector<double>> ret;
	std::vector<double> tmp;
	std::vector<std::vector<double>> horizontalna, vertikalna, kombinovana;
	horizontalna = HorizontalnoOgledalo(ma);
	vertikalna = VertikalnoOgledalo(ma);
	kombinovana = VertikalnoOgledalo(horizontalna);
	// prvi red (hv v hv)
	for (int i = 0; i < kombinovana.size(); i++) {
		for (int j = 0; j < kombinovana[i].size(); j++)
			tmp.pb(kombinovana.at(i).at(j));
		for (int j = 0; j < kombinovana[i].size(); j++)
			tmp.pb(vertikalna.at(i).at(j));
		for (int j = 0; j < kombinovana[i].size(); j++)
			tmp.pb(kombinovana.at(i).at(j));
		ret.pb(tmp);
		tmp.clear();
	}
	// drugi red (h m h)
	for (int i = 0; i < horizontalna.size(); i++) {
		for (int j = 0; j < horizontalna[i].size(); j++)
			tmp.pb(horizontalna.at(i).at(j));
		for (int j = 0; j < horizontalna[i].size(); j++)
			tmp.pb(ma.at(i).at(j));
		for (int j = 0; j < horizontalna[i].size(); j++)
			tmp.pb(horizontalna.at(i).at(j));
		ret.pb(tmp);
		tmp.clear();
	}
	// treci red (hv v hv)
	for (int i = 0; i < kombinovana.size(); i++) {
		for (int j = 0; j < kombinovana[i].size(); j++)
			tmp.pb(kombinovana.at(i).at(j));
		for (int j = 0; j < kombinovana[i].size(); j++)
			tmp.pb(vertikalna.at(i).at(j));
		for (int j = 0; j < kombinovana[i].size(); j++)
			tmp.pb(kombinovana.at(i).at(j));
		ret.pb(tmp);
		tmp.clear();
	}
	return ret;
}
int main ()
{
	int n, m;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> n >> m;
	if (m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!\n";
		return 0;
	}
	double tmp;
	std::cout << "Unesite elemente matrice: ";
	std::vector<std::vector<double>> ma;
	std::vector<double> row;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> tmp;
			row.pb(tmp);
		}
		ma.pb(row);
		row.clear();
	}
	try {
		std::vector<std::vector<double>> sol = OgledaloMatrica(ma);
		std::cout << "\nRezultantna matrica:\n";
		for (auto x1 : sol) {
			for (auto x2 : x1) std::cout << std::setw(4) << x2;
			std::cout << "\n";
		}
	}
	catch(std::domain_error smece) {
		std::cout << smece.what();
	}
	return 0;
}