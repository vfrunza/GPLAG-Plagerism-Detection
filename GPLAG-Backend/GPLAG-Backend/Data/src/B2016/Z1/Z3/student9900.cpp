/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> a) {
	std::vector<std::vector<double>> v;
	int br1(0);
	for (int i=0; i<a.size()-1; i++) {
		int br(0);
		if (a[i+1]>=a[i]) {
			v.resize(br1+1);
			v[br1].push_back(a[i]);
		}
		for (int j=i; j<a.size()-1; j++) {
			if (a[j+1]>=a[j]) {
				v[br1].push_back(a[j+1]);
				br++;
			}
			else {
				break;
			}
		}
		if (br>0) {
			br1++;
			i+=br-1;
		}
	}
	return v;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> a) {
	std::vector<std::vector<double>> v;
	int br1(0);
	for (int i=0; i<a.size()-1; i++) {
		int br(0);
		if (a[i+1]<=a[i]) {
			v.resize(br1+1);
			v[br1].push_back(a[i]);
		}
		for (int j=i; j<a.size()-1; j++) {
			if (a[j+1]<=a[j]) {
				v[br1].push_back(a[j+1]);
				br++;
			}
			else {
				break;
			}
		}
		if (br>0) {
			br1++;
			i+=br-1;
		}
	}
	return v;
}

int main () {
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> v(n);
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		std::cin >> v[i];
	}
	std::vector<std::vector<double>> x(RastuciPodnizovi(v)), y(OpadajuciPodnizovi(v));
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for (int i=0; i<x.size(); i++) {
		for (int j=0; j<x[i].size(); j++) {
			std::cout << x[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i=0; i<y.size(); i++) {
		for (int j=0; j<y[i].size(); j++) {
			std::cout << y[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}