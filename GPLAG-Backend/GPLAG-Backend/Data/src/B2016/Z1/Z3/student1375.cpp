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
#include <limits>

typedef std::vector<std::vector<double>> Matrica;


Matrica RastuciPodnizovi (std::vector<double> v) {
	Matrica rastuci;
	std::vector<double> ubaci;
	for(int i=0;i<v.size();i++) {
		if(i==0) {
			if(v[i]<=v[i+1]) ubaci.push_back(v[i]);
			continue;
		}
		if(i==v.size()-1) {
			if(v[i]>=v[i-1]) {
				ubaci.push_back(v[i]);
				if(ubaci.size()>0) {
					rastuci.push_back(ubaci);
					ubaci.clear();
					ubaci.resize(0);
					break;
				}
			}
		}		
		else if(v[i]<=v[i+1]) {
			ubaci.push_back(v[i]);
			continue;
		}
		if(v[i]>=v[i-1] && v[i]>=v[i+1]) ubaci.push_back(v[i]);
		if(ubaci.size()>0) {
			rastuci.push_back(ubaci);
			ubaci.clear();
			ubaci.resize(0);
		}
	}
	if(ubaci.size()>1) rastuci.push_back(ubaci);
	return rastuci;
}

Matrica OpadajuciPodnizovi (std::vector<double> v) {
	Matrica opadajuci;
	std::vector<double> ubaci;
	for(int i=0;i<v.size();i++) {
		if(i==0) {
			if(v[i]>=v[i+1]) ubaci.push_back(v[i]);
			continue;
		}
		if(i==v.size()-1) {
			if(v[i]<=v[i-1]) {
				ubaci.push_back(v[i]);
				if(ubaci.size()>0) {
					opadajuci.push_back(ubaci);
					ubaci.clear();
					ubaci.resize(0);
					break;
				}
			}
		}
		else if(v[i]>=v[i+1]) {
			ubaci.push_back(v[i]);
			continue;
		}
		if(v[i]<=v[i-1] && v[i]<=v[i+1]) ubaci.push_back(v[i]);
		if(ubaci.size()>0) {
			opadajuci.push_back(ubaci);
			ubaci.clear();
			ubaci.resize(0);
		}
	}
	if(ubaci.size()>1) opadajuci.push_back(ubaci);
	return opadajuci;
}

int main ()
{
	std::vector<double> v;
	int n;
	double x;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	while(v.size()<n) {
		std::cin >> x;
		v.push_back(x);
	}
	Matrica a=RastuciPodnizovi(v),b=OpadajuciPodnizovi(v);
	std::cout << "Maksimalni rastuci podnizovi:" << std::endl;
	for(auto i:a) {
		for(auto j:i) { 
		std::cout << std::setprecision(12) << j<< " "; 
		}
	std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi:" << std::endl;
	for(auto i:b) {
		for(auto j:i) {
			std::cout << std::setprecision(12) << j << " ";
		}
	std::cout << std::endl;	
	}
	return 0;
}