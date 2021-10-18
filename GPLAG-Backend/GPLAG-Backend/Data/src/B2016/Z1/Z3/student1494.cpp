/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
	
	std::vector<std::vector<double>> matrica;

	for(int i(0); i<v.size()-1; i++) {
			if(v[i]<=v[i+1]) {
				int j(i);
				std::vector<double> podniz;
				while(j<v.size()-1 && (v[j] <= v[j+1])) {
						podniz.push_back(v[j]);
						j++;
				}
						podniz.push_back(v[j]);
						if(podniz.size()>0) {
						matrica.push_back(podniz);
						podniz.resize(0);
						i=j;
						}
				}
	}
	return matrica;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {

	std::vector<std::vector<double>> matrica;
	
	for(int i(0); i<v.size()-1; i++) {
			if(v[i]>=v[i+1]) {
				int k(i);
				std::vector<double> podniz;
				while(k<v.size()-1 && (v[k] >= v[k+1])) {
						podniz.push_back(v[k]);
						k++;
				}
						podniz.push_back(v[k]);
						if(podniz.size()>0) {
						matrica.push_back(podniz);
						podniz.resize(0);
						i=k;
						}
			}
	}
	return matrica;
}


int main ()
{
	
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::vector<double> vektor;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i<n; i++) {
		double x;
		std::cin >> x;
		vektor.push_back(x);
	}
	
	std::vector<std::vector<double>> rez1;
	rez1=RastuciPodnizovi(vektor);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl; 
	for(auto x : rez1) {
		for(int m(0); m<x.size(); m++)
	std::cout << x[m] << " ";
	std::cout << std::endl;
	}
	
	std::vector<std::vector<double>> rez2;
	rez2=OpadajuciPodnizovi(vektor);
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(auto x : rez2) {
		for(int b(0); b<x.size(); b++)
		std::cout << x[b] << " ";
	}
	
	return 0;
}