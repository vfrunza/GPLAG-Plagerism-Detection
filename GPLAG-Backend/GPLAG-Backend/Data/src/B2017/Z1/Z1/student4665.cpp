/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor, bool prost){
	std::vector<int> prosti;
	std::vector<int> slozeni;
	std::vector<int> stepeniTrice;
	int max = vektor.at(0);
	bool postoji = false, slozen = false;
	for (int i = 0; i < vektor.size(); i++) {
	//	if(vektor.at(i) < 0) vektor.at(i) = -1 * vektor.at(i);
		if(max < abs(vektor.at(i))) max = abs(vektor.at(i));
			for(int j = 2; j < abs(vektor.at(i)) - 1; j++) {
				if(abs(vektor.at(i)) % j == 0) {
					slozen = true;
					for(int k = 0 ; k < slozeni.size(); k++){
						if(vektor.at(i) == slozeni.at(k)) {
							postoji = true;
							break;
						}
					}
					if(!postoji) slozeni.push_back(vektor.at(i));
					postoji = false; 
					break;
				}
			}
			if(!slozen) {
				for(int k = 0 ; k < prosti.size(); k++){
					if(vektor.at(i) == prosti.at(k)) {
						postoji = true;
						break;
					}
				}
				if(!postoji) prosti.push_back(vektor.at(i));
			}
			postoji = false;
			slozen = false;
		}
	std::vector<int> trice;
	for (int i = 1; i <= max; i *= 3) {
		trice.insert(trice.begin(), i);
	}
	std::vector<int> simetricni;
	if (prost) {
		for (int i = 0; i < prosti.size(); i++) {
			for (int j = 0; j < trice.size(); j++) {
				if(abs(prosti.at(i)) > trice.at(j)) {
					int cifra = 1, broj = abs(prosti.at(i));
					std::vector<int> cifre;
					for(int k = j; k < trice.size(); k++) cifra *= 10;
					int cifraProvjera = 0;
					for(int k = j; k < trice.size(); k++) {
						cifra /= 10;
						if(broj > trice.at(k) * 2 || broj >= trice.at(k) * 2) {
							broj -= trice.at(k)*2;
							cifraProvjera += 2 * cifra;
							cifre.push_back(2);
						} else if (broj > trice.at(k) || broj >= trice.at(k)) {
							broj -= trice.at(k);
							cifraProvjera += cifra;
							cifre.push_back(1);
						} else {
							cifre.push_back(0);
						}
					}
					bool simetrican = true;
					for(int e = 0; e < cifre.size(); e++) {
						if (cifre.at(e) != cifre.at(cifre.size() - 1 - e)) simetrican = false;
					}
					if(simetrican) simetricni.push_back(prosti.at(i));
					break;
				}
			}
		}
		return simetricni;
	} else {
		for (int i = 0; i < slozeni.size(); i++) {
			for (int j = 0; j < trice.size(); j++) {
				if(abs(slozeni.at(i)) > trice.at(j)) {
					int cifra = 1, broj = abs(slozeni.at(i));
					std::vector<int> cifre;
					for(int k = j; k < trice.size(); k++) cifra *= 10;
					int cifraProvjera = 0;
					for(int k = j; k < trice.size(); k++) {
						cifra /= 10;
						if(broj > trice.at(k) * 2 || broj >= trice.at(k) * 2) {
							broj -= trice.at(k)*2;
							cifraProvjera += 2 * cifra;
							cifre.push_back(2);
						} else if (broj > trice.at(k) || broj >= trice.at(k)) {
							broj -= trice.at(k);
							cifraProvjera += cifra;
							cifre.push_back(1);
						} else {
							cifre.push_back(0);
						}
					}
					bool simetrican = true;
					for(int e = 0; e < cifre.size(); e++) {
						if (cifre.at(e) != cifre.at(cifre.size() - 1 - e)) simetrican = false;
					}
					if(simetrican) simetricni.push_back(slozeni.at(i));
					break;
				}
			}
		}
		return simetricni;
	}
}
int main ()
{
	std::vector<int> prosti;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;) {
		int broj;
		std::cin >> broj;
		if(broj == -1) break;
		else prosti.push_back(broj);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int broj;
	for(;;) {
		std::cin >> broj;
		if(broj == 1 || broj == 0) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	if(broj == 1) {
		std::vector<int> brojevi = IzdvojiSimetricneTernarne(prosti, true);
		if(brojevi.size()) {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for (int i = 0; i < brojevi.size(); i++) {
				if(i != brojevi.size() - 1)
					std::cout << brojevi.at(i) << ", ";
				else 
					std::cout << brojevi.at(i) << ".";
			}
		} else {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		}
	} else if (broj == 0) {
		std::vector<int> brojevi = IzdvojiSimetricneTernarne(prosti, false);
		if(brojevi.size()) {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i = 0; i < brojevi.size(); i++) {
				if(i != brojevi.size() - 1)
					std::cout << brojevi.at(i) << ", ";
				else 
					std::cout << brojevi.at(i) << ".";
			}
		} else {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		}
	} 
	return 0;
}