/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> vektor) {
	std::vector<std::vector<double>> matrica;
	std::vector<double> pomocni;
	/*int s(1);*/
	for(int i(0); i<vektor.size(); i++) {
		pomocni.push_back(vektor[i]);
		if(i==vektor.size()-1) {
			if(vektor[i]>vektor[i-1]) {
				if(pomocni.size()==1) {
					pomocni.erase(pomocni.begin()+0);
				} else {
					/*matrica.resize(s);
					for(int j(0); j<pomocni.size(); j++) {
						matrica[s-1].push_back(pomocni[j]);
					}*/
					matrica.push_back(pomocni);
					int velicina_pomocnog=pomocni.size();
					for(int k(0); k<velicina_pomocnog; k++) {
						pomocni.erase(pomocni.begin()+0);
					}
					/*s++;*/
				}
			}
			if(pomocni.size()>1) {
			/*	matrica.resize(s);
				for(int j(0); j<pomocni.size(); j++) {
					matrica[s-1].push_back(pomocni[j]);
				}*/
				matrica.push_back(pomocni);
			}
			break;
		} else {
			if(vektor[i]>vektor[i+1]) {
				if(pomocni.size()==1) {
					pomocni.erase(pomocni.begin()+0);
				} else {
					/*matrica.resize(s);
					for(int j(0); j<pomocni.size(); j++) {
						matrica[s-1].push_back(pomocni[j]);
					}*/
					matrica.push_back(pomocni);
					int velicina_pomocnog=pomocni.size();
					for(int k(0); k<velicina_pomocnog; k++) {
						pomocni.erase(pomocni.begin()+0);
					}
				/*	s++;*/
				}
			}
		}
	}
	return matrica;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> vektor) {
	std::vector<std::vector<double>> matrica;
	std::vector<double> pomocni;
	/*int s(1);*/
	for(int i(0); i<vektor.size(); i++) {
		pomocni.push_back(vektor[i]);
		if(i==vektor.size()-1) {
			if(vektor[i]<vektor[i-1]) {
				if(pomocni.size()==1) {
					pomocni.erase(pomocni.begin()+0);
				} else {
				/*	matrica.resize(s);
					for(int j(0); j<pomocni.size(); j++) {
						matrica[s-1].push_back(pomocni[j]);
					}*/
					matrica.push_back(pomocni);
					int velicina_pomocnog=pomocni.size();
					for(int k(0); k<velicina_pomocnog; k++) {
						pomocni.erase(pomocni.begin()+0);
					}
				/*	s++;*/
				}
			}
			if(pomocni.size()>1) {
				/*matrica.resize(s);
				for(int j(0); j<pomocni.size(); j++) {
					matrica[s-1].push_back(pomocni[j]);
				}*/
				matrica.push_back(pomocni);
			}
			break;
		} else {
			if(vektor[i]<vektor[i+1]) {
				if(pomocni.size()==1) {
					pomocni.erase(pomocni.begin()+0);
				} else {
					/*matrica.resize(s);
					for(int j(0); j<pomocni.size(); j++) {
						matrica[s-1].push_back(pomocni[j]);
					}*/
					matrica.push_back(pomocni);
					int velicina_pomocnog=pomocni.size();
					for(int k(0); k<velicina_pomocnog; k++) {
						pomocni.erase(pomocni.begin()+0);
					}
				/*	s++;*/
				}
			}
		}
	}
	return matrica;
}

int main () {
	int velicina;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> velicina;
	if(!std::cin) {
		std::cout << "Nije unesen broj!" << std::endl;
		return 0;
	}
	if(velicina<0) {
		std::cout << "Broj elemenata vektora ne moze biti negativan!" << std::endl;
		return 0;
	} else if (velicina==0) {
		std::cout << "Vektor je prazan." << std::endl;
		return 0;
	}
	std::vector<double> vektor;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i<velicina; i++) {
		double element;
		std::cin >> element;
		if(!std::cin) {
			std::cout << "Nije unesen broj." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else {
			vektor.push_back(element);
		}
	}
	auto rastuci(RastuciPodnizovi(vektor));
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(auto red: rastuci) {
		for(auto x: red) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	auto opadajuci(OpadajuciPodnizovi(vektor));
	std::cout << std::endl << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(auto red: opadajuci) {
		for(auto x: red) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}