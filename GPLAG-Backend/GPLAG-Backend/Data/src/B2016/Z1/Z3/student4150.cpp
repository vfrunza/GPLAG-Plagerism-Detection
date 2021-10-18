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
std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> vektor) {
	std::vector<std::vector<double>> matrica;
	
	for(int i(0); i < vektor.size()-1; i++) { 
		std::vector<double> novi;
		int j; 
		for(j = i; j < vektor.size()-1; j++) {
			if(vektor[j] > vektor[j+1]) break;
			novi.push_back(vektor[j]);
		}
		if(novi.size() > 0) {
			novi.push_back(vektor[j]);
			matrica.push_back(novi);
		}
		i = j;
		if(i >= vektor.size()) break;
	}
	
	return matrica;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vektor) {
	std::vector<std::vector<double>> matrica;
	for(int i(0); i < vektor.size()-1; i++) {
		std::vector<double> novi;
		int j;
		for(j = i; j < vektor.size()-1; j++) {
			if(vektor[j] < vektor[j+1]) break;
			novi.push_back(vektor[j]);
		}
		if(novi.size() > 0) {
			novi.push_back(vektor[j]);
			matrica.push_back(novi);
		}
		i = j;
		if(i >= vektor.size()) break;
	
	}
	
	return matrica;
}
void Ispisi(std::vector<std::vector<double>> matrica) {
	for(int i(0); i < matrica.size(); i++) {
		for(int j(0); j < matrica[0].size(); j++) {
			std::cout << matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main () {
	
	int n;
	double broj;
	std::vector<double> v;
	std::vector<std::vector<double>> matrica;
	std::vector<std::vector<double>> matrica2;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i < n; i++) {
		std::cin >> broj;
		v.push_back(broj);
	}
	matrica = RastuciPodnizovi(v);
	matrica2 = OpadajuciPodnizovi(v);
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	Ispisi(matrica);
	std::cout << std::endl;
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	Ispisi(matrica2);
	return 0;
}