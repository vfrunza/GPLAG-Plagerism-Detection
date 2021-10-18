/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	..
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double>niz) {
	Matrica m;
	std::vector<double>v;
	double eps=1e-10;
	
	
	for(int i=0; i<int(niz.size())-1; i++) {
		bool nadjen(false);
		while(i<int(niz.size())-1 && (niz[i]<niz[i+1] || fabs(niz[i]-niz[i+1])<eps)) {
			v.push_back(niz[i]);
			i++;
			nadjen=true;
		}
		if(nadjen) {
			if(niz[i-1]<niz[i] || fabs(niz[i-1]-niz[i])<eps) v.push_back(niz[i]); 
			if(v.size()>1) m.push_back(v);
		}
		if(i==int(niz.size())-1) break;
		v.resize(0);
	}
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double>niz) {
	Matrica m;
	std::vector<double>v;
	double eps=1e-10;
	
	
	for(int i=0; i<int(niz.size())-1; i++) {
		bool nadjen(false);
		while(i<int(niz.size())-1 && (niz[i]>niz[i+1] || fabs(niz[i]-niz[i+1])<eps)) {
			v.push_back(niz[i]);
			i++;
			nadjen=true;
		}
		if(nadjen) {
			if(niz[i-1]>niz[i] || fabs(niz[i-1]-niz[i])<eps) v.push_back(niz[i]); 
			if(v.size()>1) m.push_back(v);
		}
		if(i==int(niz.size())-1) break;
		v.resize(0);
	}
	return m;
}

int main () {
	int broj_el;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_el;
	std::vector<double>v(broj_el);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<broj_el; i++) std::cin >> v[i];
	std::cout << "Maksimalni rastuci podnizovi: \n";
	{ auto m=RastuciPodnizovi(v);
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) std::cout << std::setprecision(10) << m[i][j] << " ";
		std::cout << "\n";
	}
	}
	auto m=OpadajuciPodnizovi(v);
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) std::cout << std::setprecision(10) <<m[i][j] << " ";
		std::cout << "\n";
	}
	return 0;
}