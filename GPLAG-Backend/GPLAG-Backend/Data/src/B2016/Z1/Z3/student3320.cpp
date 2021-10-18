/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>


std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>nizovi1) {
	std::vector<std::vector<double>>POMOCNI;
	int red=0;
	int brojac=1;
	for(int i=1; i<nizovi1.size(); i++) {
		if(nizovi1[i] <= nizovi1[i-1]) {
			if(brojac) {
				POMOCNI.resize(red+1);
					POMOCNI[red].push_back(nizovi1[i-1]);
					brojac=0;
			}
			POMOCNI[red].push_back(nizovi1[i]);
		} else {
			brojac=1;
			if(POMOCNI.size() != red) {
			red++;
			}
		}
	}
	return POMOCNI;
}


std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>nizovi1) {
	std::vector<std::vector<double>>POMOCNI;
	int red=0;
	int brojac=1;
	for(int i=1; i<nizovi1.size(); i++) {
		if(nizovi1[i] >= nizovi1[i-1]) {
			if(brojac) {
				POMOCNI.resize(red+1);
					POMOCNI[red].push_back(nizovi1[i-1]);
					brojac=0;
			}
			POMOCNI[red].push_back(nizovi1[i]);
		} else {
			brojac=1;
			if(POMOCNI.size() != red) {
			red++;
			}
		}
	}
	return POMOCNI;
}
int main () {
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double>nizovi;
	
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		double temp;
		std::cin >> temp;
		nizovi.push_back(temp);
	}
	
	std::vector<std::vector<double>>POMOCNI;
	std::cout << "Maksimalni rastuci podnizovi: ";
	std::cout << std::endl;
	POMOCNI=RastuciPodnizovi(nizovi);
	for(int i=0; i<POMOCNI.size(); i++) {
		for(int j=0; j<POMOCNI[i].size(); j++) {
			std::cout << POMOCNI[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi: ";
	std::cout << std::endl;
	POMOCNI=OpadajuciPodnizovi(nizovi);
	for(int i=0; i<POMOCNI.size(); i++) {
		for(int j=0; j<POMOCNI[i].size(); j++) {
			std::cout << POMOCNI[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}