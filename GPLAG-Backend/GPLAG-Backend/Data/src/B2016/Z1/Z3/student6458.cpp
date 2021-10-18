/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v) {
	std::vector<std::vector<double>> returnValue(v.size());
	int k(0);
	int brojac(0);
	for (int i = 0; i < v.size() - 1; i++) {
		if (returnValue.size() == 0) break;
		if (v[i] <= v[i+1]) {
			returnValue[k].push_back(v[i]);
			brojac++;
			if (i == v.size() - 2 && v[i] <= v[v.size() - 1]) {
				returnValue[k].push_back(v[v.size() - 1]);
				k++;
			}
		}
		if (v[i+1] < v[i] && brojac >= 1 ) {
			returnValue[k].push_back(v[i]);
			k++;
			brojac = 0;
		}
	}
	returnValue.resize(k);
	return returnValue;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v) {
	std::vector<std::vector<double>> returnValue(v.size());
	int k(0);
	int brojac(0);
	for (int i = 0; i < v.size() - 1; i++) {
		if (returnValue.size() == 0) break;
		if (v[i] >= v[i+1]) {
			returnValue[k].push_back(v[i]);
			brojac++;
			if (i == v.size() - 2 && v[i] >= v[v.size() - 1]) {
				returnValue[k].push_back(v[v.size() - 1]);
				k++;
			}
		}
		if (v[i+1] > v[i] && brojac >= 1 ) {
			returnValue[k].push_back(v[i]);
			k++;
			brojac = 0;
		}
	}
	returnValue.resize(k);
	return returnValue;
}

int main ()
{
	std::vector<double> v;
	int nElemenata;
	double element;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> nElemenata;
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < nElemenata; i++) {
		std::cin >> element;
		v.push_back(element);
	}
	std::cout << "Maksimalni rastuci podnizovi:" << std::endl;
	std::vector<std::vector<double>> v2 (RastuciPodnizovi(v));
	for (int i = 0; i < v2.size(); i++) {
		for (int j = 0; j < v2[i].size(); j++) {
			std::cout << v2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi:" << std::endl;
	std::vector<std::vector<double>> v3 (OpadajuciPodnizovi(v));
	for (int i = 0; i < v3.size(); i++) {
		for (int j = 0; j < v3[i].size(); j++) {
			std::cout << v3[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}