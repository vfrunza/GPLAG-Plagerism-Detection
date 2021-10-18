/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>

typedef std::vector <std::vector <double>> Matrica;
typedef std::vector <double> Unos;

void ispisMatrice (Matrica m) {
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j < m[i].size(); j++) {
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Matrica RastuciPodnizovi (Unos V) {
	
	if (V.empty()) 
	    return {};
	    
	int broj_elemenata = V.size();
	Matrica rezultat(broj_elemenata);
	
	int j(0);
	
	int kraj=V.size()-1;
	bool status=false;
	
	for (int i=0; i < kraj; i++) {
		if (V[i+1] >= V[i]) {
			status=true;
			rezultat[j].push_back(V[i]);
			
			if(i+1 == kraj) {
				rezultat[j].push_back(V[i+1]);
			}
		}
			else {
				if (V[i] >= V[i+1] && status) {
					rezultat[j].push_back(V[i]);
					j++;
				}
				status=false;
			}
	}
			for (int i = rezultat.size()-1; i > j; i--) {
				rezultat.erase(rezultat.begin() + i);
			}
		
	
	return rezultat;
}


Matrica OpadajuciPodnizovi (Unos V) {
	
	int broj_elemenata = V.size();
	
	if (V.empty()) {
		
		return {};
		
	}
	Matrica rezultat (broj_elemenata);
	
	int j(0);
	
	int kraj=V.size()-1;
	
	bool poceo_dodavanje = false;
	bool zavrsio_dodavanje = false;
	int ukupno (0);
	Unos temp (0);
	
	for (int i = 0; i < kraj; i++) {
		
		if(V[i] >= V[i + 1]) {
			poceo_dodavanje = true;
			temp.push_back(V[i]);
			++ukupno;
		}
		
		else {
			if (V[i + 1] >= V[i] && ukupno >= 2) {
					temp.push_back(V[i]);
					zavrsio_dodavanje = true;
					rezultat[j] = std::move(temp);
					temp.clear();
					ukupno = 0;
					++j;
					zavrsio_dodavanje = true;
			}
			
			if (!poceo_dodavanje) {
				temp.clear();
				ukupno = 0;
			}
			
			poceo_dodavanje = false;
			zavrsio_dodavanje = false;
		}
		
	} 
		
	return rezultat;
	
	
}
		

int main() {
	int broj_elemenata;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	std::vector <double> unos(broj_elemenata);
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i < broj_elemenata; i++) {
		std::cin >> unos[i];
	}
	
	Matrica rezultat1 = RastuciPodnizovi(unos);
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	ispisMatrice (rezultat1);
	Matrica rezultat2 = OpadajuciPodnizovi(unos);
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	ispisMatrice (rezultat2);
	
	return 0;
}