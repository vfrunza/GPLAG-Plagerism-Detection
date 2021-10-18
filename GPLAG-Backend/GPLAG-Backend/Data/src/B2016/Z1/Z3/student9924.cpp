/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> niz){
	Matrica vracena;
	for(int i=1; i<niz.size(); i++){
		std::vector<double> pomocna;
		bool istina(true);
		if(niz[i-1]<=niz[i]){
			while(i<niz.size() && niz[i-1]<=niz[i]){
				if(istina){
					pomocna.push_back(niz[i-1]);
					pomocna.push_back(niz[i]);
					istina=false;
					i++;
				} else {
					pomocna.push_back(niz[i]);
					i++;
				}
			}
		}
		vracena.push_back(pomocna);
	}
	return vracena;
}

Matrica OpadajuciPodnizovi(std::vector<double> niz){
	Matrica vracena;
	for(int i=1; i<niz.size(); i++){
		std::vector<double> pomocna;
		bool istina(true);
		if(niz[i-1]>=niz[i]){
			while(i<niz.size() && niz[i-1]>=niz[i]){
				if(istina){
					pomocna.push_back(niz[i-1]);
					pomocna.push_back(niz[i]);
					istina=false;
					i++;
				} else {
					pomocna.push_back(niz[i]);
					i++;
				}
			}
		}
		vracena.push_back(pomocna);
	}
	return vracena;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> uneseni;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		int x;
		std::cin >> x;
		uneseni.push_back(x);
	}
	std::cout << "Maksimalni rastuci podnizovi: ";
	Matrica rastuca;
	rastuca=RastuciPodnizovi(uneseni);
	std::cout << std::endl;
	for(int i=0; i<rastuca.size(); i++){
		for(int j=0; j<rastuca[i].size(); j++){
			std::cout << rastuca[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: ";
	Matrica opadajuca;
	opadajuca=OpadajuciPodnizovi(uneseni);
	std::cout << std::endl;
	for(int i=0; i<opadajuca.size(); i++){
		for(int j=0; j<opadajuca[i].size(); j++){
			std::cout << opadajuca[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}