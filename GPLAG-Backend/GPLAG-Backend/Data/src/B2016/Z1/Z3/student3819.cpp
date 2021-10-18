/*B 2016/2017, Zadaæa 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(std::vector<double> v) {
	Matrica m;
	std::vector<double> pomocni;
	if(v.size()==0) return m;
	int temp=0;
	for(int i(0); i<v.size()-1; i++) {
		if(v[i]<=v[i+1]) {
			pomocni.push_back(v[i]);
			temp=1;
		}
		else if(temp) {
			pomocni.push_back(v.at(i));
			m.push_back(pomocni);
			pomocni.clear();
			temp=0;
		}
		if(i==v.size()-2) {
			if(v[i]<=v[i+1])
				pomocni.push_back(v[i+1]);
		}
	}
	if(temp)
		m.push_back(pomocni);
	return m;
}
Matrica OpadajuciPodnizovi(std::vector<double> v) {
	Matrica m;
	std::vector<double> pomocni;
	if(v.size()==0) return m;
	int temp=0;
	for(int i(0); i<v.size()-1; i++) {
		if(v[i]>=v[i+1]) {
			pomocni.push_back(v.at(i));
			temp=1;
		}
		else if(temp) {
			pomocni.push_back(v.at(i));
			m.push_back(pomocni);
			pomocni.clear();
			temp=0;
		}
		if(i==v.size()-2) {
			if(v[i]>=v[i+1])
				pomocni.push_back(v[i+1]);
		}
	}
	if(temp)
		m.push_back(pomocni);
	return m;
}
int main() {
	int n;
	std::vector<double> v;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	Matrica m;
	Matrica m1;
	for(int i(0); i<n; i++) {
		int element;
		std::cin >> element;
		v.push_back(element);
	}
	m=RastuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi: \n";
	for(int i(0); i<m.size(); i++) {
		for(int j(0); j<m[i].size(); j++) {
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
	m1=OpadajuciPodnizovi(v);
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	for(int i(0); i<m1.size(); i++) {
		for(int j(0); j<m1[i].size(); j++) {
			std::cout << m1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}