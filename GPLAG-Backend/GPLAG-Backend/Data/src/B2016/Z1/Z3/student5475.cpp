/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

typedef std::vector<std::vector<double>> Matrica;

bool Manji(double a, double b) {
	return ((a-b) <= std::numeric_limits<double>::min());
}

Matrica RastuciPodnizovi(std::vector<double> v) {
	Matrica mat;
	for(int i=0; i<v.size(); i++) {
		double prvi(v[i]);
		std::vector<double> pomocni{prvi};
		i++;
		while(i < v.size() && Manji(prvi, v[i])) {
			pomocni.push_back(v[i]);
			prvi = v[i];
			i++;
		}
		i--;
		if(pomocni.size() != 1) mat.push_back(pomocni);
	}
	return mat;
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
	Matrica mat;
	for(int i=0; i<v.size(); i++) {
		double prvi(v[i]);
		std::vector<double> pomocni{prvi};
		i++;
		while(i < v.size() && Manji(v[i], prvi)) {
			pomocni.push_back(v[i]);
			prvi = v[i];
			i++;
		}
		i--;
		if(pomocni.size() != 1) mat.push_back(pomocni);
	}
	return mat;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> v(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++)
		std::cin >> v[i];
	Matrica rastuci(RastuciPodnizovi(v));
	Matrica opadajuci(OpadajuciPodnizovi(v));
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i=0; i<rastuci.size(); i++) {
		for(int j=0; j<rastuci[i].size(); j++)
			std::cout << rastuci[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0; i<opadajuci.size(); i++) {
		for(int j=0; j<opadajuci[i].size(); j++)
			std::cout << opadajuci[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}