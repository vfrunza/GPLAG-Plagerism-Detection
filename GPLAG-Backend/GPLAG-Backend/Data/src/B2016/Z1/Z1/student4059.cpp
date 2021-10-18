/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int PretvoriUTernarni (int broj) {
	int ternarni = 0;
	int i = 0;
	
	while(broj != 0) {
		int cifra = broj % 3;
		ternarni = ternarni + pow(10, i)*cifra;
		ternarni /= 3;
		i++;
	}
	
	return ternarni;
}

bool JeOpak (int ternarni) {
	int brojacDvica = 0;
	int brojacJedinica = 0;
	int brojacNula = 0;
	
	while (ternarni != 0) {
		int cifra = ternarni % 3;
		switch (cifra) {
			case 2:
			case -2:
				brojacDvica++;
				break;
			case 1:
			case -1:
				brojacJedinica++;
				break;
			case 0:
				brojacNula++;
				break;
	}
	ternarni /= 3;
}
if (((brojacNula == 0) || (brojacNula > 0 && brojacNula % 2 == 0)) &&
   ((brojacJedinica == 0) || (brojacJedinica > 0 && brojacJedinica %2 == 0)) &&
   ((brojacDvica == 0) || (brojacDvica > 0 && brojacDvica %2 == 0)))
	return true;
else 
	return false;
}

bool JeOdvratan (int ternarni) {
	int brojacDvica = 0;
	int brojacJedinica = 0;
	int brojacNula = 0;
	
	while (ternarni != 0) {
		int cifra = ternarni % 3;
		switch (cifra) {
		case 2:
		case -2:
			brojacDvica++;
			break;
		case 1:
		case -1:
			brojacJedinica++;
			break;
		case 0:
			brojacNula++;
			break;
		}
		ternarni /= 3;
	}

if (((brojacNula == 0) || (brojacNula > 0 && brojacNula % 2 == 1)) &&
   ((brojacJedinica == 0) || (brojacJedinica > 0 && brojacJedinica %2 == 1)) &&
   ((brojacDvica == 0) || (brojacDvica > 0 && brojacDvica %2 == 1)))
	return true;
else 
	return false;
}

vector<int> IzdvojiGadne(vector<int> brojevi, bool morebitbidne) {
	if(morebitbidne == true) {
		for(int i = 0; i < brojevi.size(); i++) {
			int broj = brojevi[i];
			if(!JeOpak(broj)) {
				brojevi.erase(brojevi.begin() + i);
				i--;
		}
	}
}
	else {
		for(int i = 0; i < brojevi.size(); i++) {
			int broj = brojevi[i];
			if(!JeOdvratan(broj)) {
				brojevi.erase(brojevi.begin() + i);
				i--;
			}
		}
	}
	
	for(int i = 0; i < brojevi.size(); i++) {
		for(int j = i+1; j < brojevi.size(); j++) {
			if(brojevi[i] == brojevi[j]) {
				brojevi.erase(brojevi.begin() + j);
				j--;
			}
		}
	}
	return brojevi;
}

int main () {
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> brojevi;
	int broj;
	do {
		std::cin >> broj;
		if(broj != 0) {
			brojevi.push_back(broj);
		}
	} while(broj != 0);
	std::vector<int> opaki = IzdvojiGadne(brojevi, true);
	std::vector<int> odvratni = IzdvojiGadne(brojevi, false);
	std::cout << "Opaki: ";
	for(int i = 0; i < opaki.size(); i++) {
		std::cout << opaki[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int i = 0; i < odvratni.size(); i++) {
		std::cout << odvratni[i] << " ";
	}
	return 0;
}