/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v) {
	Matrica M;
	int i(0), k, velicina(0);
	while (i < v.size()-1) {
		for (k = i+1; (v[k]-v[k-1] >= 0); k++) {
			if (k == v.size()-1) {
				++k;
				break;
			}
		}
		if (k-i > 1) {
			M.resize(++velicina);
			while (i < k) M[velicina-1].push_back(v[i++]); 
		}
		else ++i;
	}
	return M;
}
Matrica OpadajuciPodnizovi(std::vector<double> v) {
	Matrica M;
	int i(0), k, velicina(0);
	while (i < v.size()-1) {
		for (k = i+1; (v[k]-v[k-1] <= 0); k++) {
			if (k == v.size()-1) {
				k++;
				break;
			}
		}
		if (k-i > 1) {
			M.resize(++velicina);
			while (i < k) M[velicina-1].push_back(v[i++]);
		}
		else ++i;
	}
	return M;
}


int main ()
{
	std::vector<double> v;
	int n, broj;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	if (n < 0) {
		std::cout << "Broj elemenata mora biti nenegativan!";
		return 0;
	}
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < n; i++) {
		std::cin >> broj;
		v.push_back(broj);
	}
	Matrica w(RastuciPodnizovi(v));
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for (int i = 0; i < w.size(); i++) {
		for (int j = 0; j < w[i].size(); j++) std::cout << w[i][j] << " ";
		std::cout << std::endl;
	}
	w = OpadajuciPodnizovi(v);
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i = 0; i < w.size(); i++) {
		for (int j = 0; j < w[i].size(); j++) std::cout << w[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}