/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(std::vector<double> niz){
	int brojac(0);
	for(int i(0); i<int(niz.size()-1); i++){
		if(niz[i]<=niz[i+1]){
			while(niz[i]<=niz[i+1]){
				i++;
				if(i==niz.size()-1) break;
			}
			brojac++;
		}
	}
	matrica podnizovi;
	podnizovi.resize(brojac);
	int redovi(0);
	for(int i(0); i<int(niz.size()-1); i++){
		if(niz[i]<=niz[i+1]){
			while(niz[i]<=niz[i+1]){
				podnizovi[redovi].push_back(niz[i]);
				i++;
				if(i==int(niz.size()-1)) break;
			}
			if(niz[i]>=niz[i-1]) podnizovi[redovi].push_back(niz[i]);
			redovi++;
		}
	}
	return podnizovi;
}

matrica OpadajuciPodnizovi(std::vector<double> niz){
	int brojac(0);
	for(int i(0); i<int(niz.size()-1); i++){
		if(niz[i]>=niz[i+1]){
			while(niz[i]>=niz[i+1]){
				i++;
				if(i==niz.size()-1) break;
			}
			brojac++;
		}
	}
	matrica podnizovi;
	podnizovi.resize(brojac);
	int redovi(0);
	for(int i(0); i<int(niz.size()-1); i++){
		if(niz[i]>=niz[i+1]){
			while(niz[i]>=niz[i+1]){
				podnizovi[redovi].push_back(niz[i]);
				i++;
				if(i==int(niz.size()-1)) break;
			}
			if(niz[i]<=niz[i-1]) podnizovi[redovi].push_back(niz[i]);
			redovi++;
		}
	}
	return podnizovi;
}

int main (){
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> niz;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i<n; i++){
		double temp;
		std::cin >> temp;
		niz.push_back(temp);
	}
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	matrica rastuca(RastuciPodnizovi(niz));
	for(int i(0); i<rastuca.size(); i++){
		for(int j(0); j<rastuca[i].size(); j++)
			std::cout << rastuca[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	matrica opadajuca(OpadajuciPodnizovi(niz));
	for(int i(0); i<opadajuca.size(); i++){
		for(int j(0); j<opadajuca[i].size(); j++)
			std::cout << opadajuca[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}