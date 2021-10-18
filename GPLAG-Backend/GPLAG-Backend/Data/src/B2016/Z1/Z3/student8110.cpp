#include<iostream>
#include<vector>
#include<cmath>
#include <iomanip>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v) {
	const double E = 10e-12;
	std::vector<double> rastuci;
	std::vector<std::vector<double>> a;
	if(v.size()==0) return a;
	for(int i=0; i<v.size()-1; i++) {
		if(v[i]<v[i+1] || std::fabs(v[i]-v[i+1])<E) {
			for(int j=i; j<v.size(); j++) {
				if(j<v.size()-1 && (v[j]<v[j+1] || std::fabs(v[j]-v[j+1])<E)) continue;
				else {
					for(int k=i; k<=j; k++) {
						rastuci.push_back(v[k]);
					}
					a.push_back(rastuci);
					rastuci.resize(0);
					i = j;
					break;
				}
			}
		}
	}
	return a;
}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v) {
	const double E = 10e-12;
	std::vector<double> opadajuci;
	std::vector<std::vector<double>> b;
	if(v.size()==0) return b;
	for(int i=0; i<v.size()-1; i++) {
		if(v[i]>v[i+1] || std::fabs(v[i]-v[i+1])<E) {
			for(int j=i; j<v.size(); j++) {
				if(j<v.size()-1 && (v[j]>v[j+1] || std::fabs(v[j]-v[j+1])<E)) continue;
				else {
					for(int k=i; k<=j; k++) {
						opadajuci.push_back(v[k]);
					}
					b.push_back(opadajuci);
					opadajuci.resize(0);
					i = j;
					break;
				}
			}
		}
	}
	return b;
}


int main () {
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v;
	for(int i=0; i<n; i++) {
		double element;
		std::cin >> element;
		v.push_back(element);
	}
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> a = RastuciPodnizovi(v);
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a[i].size(); j++) {
			std::cout << std::setprecision(12) << a[i][j] << " " ;
		}
		std::cout << std:: endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> b = OpadajuciPodnizovi(v);
	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<b[i].size(); j++) {
			std::cout << std::setprecision(12) << b[i][j] << " " ;
		}
		std::cout << std:: endl;
	}
	return 0;
}