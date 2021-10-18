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
#include <deque>

bool ProvjeriProst(int broj) {
	bool prost = true;
	broj = abs(broj);
	
	for (int i=2; i<broj-1; i++) {
		if (broj % i == 0) {
			// ako je broj djeljiv sa i bez ostatka to znaci da ima djelitelja osim 1 i samog sebe tj. nije prost 
			prost = false;
			break;
		}
	}
	
	return prost;
}

bool ProvjeriTernarniSimetrican(int broj) {
	// 59 je ternarno jednak 2012
	// 59 / 3 = 19 i ost. 2
	// 19 / 3 = 6 i ost. 1
	// 6 / 3 = 2 i ost. 0
	// 2 / 3 = 0 i ost. 2
	int cifra = 0;
	std::deque<int> ternarni;
	broj = abs(broj);
	
	while (broj != 0) {
		cifra = broj % 3;
		ternarni.push_front(cifra);
		broj = broj / 3;
	}
	
	int ternarni_size = ternarni.size();
	bool simetrican = true;
	for (int i=0; i < ternarni_size / 2; i++) {
		if (ternarni.at(i) != ternarni.at(ternarni_size - i - 1)) {
			simetrican = false;
			break;
		}
	}
	
	//for (auto c:ternarni) {
	//	std::cout << c; 
	//}
	//std::cout << std::endl;

	return simetrican;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool prosti) {
	std::vector<int> rezultat;
	for (auto el:v) {
		if (ProvjeriProst(el) == prosti && ProvjeriTernarniSimetrican(el) == true) {
	
			bool prisutan = false;
			for (auto r:rezultat) {
				if (el == r) {
					prisutan = true;
					break;
				}
			}
			if (prisutan == false) {
				rezultat.push_back(el);	
			}
		}	
	}
	
	return rezultat;
}

int main ()
{
	std::vector<int> niz;
	int broj;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	
	while (true) {
		std::cin >> broj;
		if (broj == -1) {
			break;
		}
		niz.push_back(broj);
	}
	
	int prosti;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while (true) {
		std::cin >> prosti;
		if (prosti != 0 && prosti != 1) {
			std::cout << "Neispravan unos! Unesite ponovo: ";
		} else {
			break;
		}
	}
	
	std::vector<int> izlaz = IzdvojiSimetricneTernarne(niz, prosti);

	if (izlaz.size() > 0) {
		if (prosti) {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
		} else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		}
		int el;
		for (int i=0; i<izlaz.size(); i++) {
			el = izlaz.at(i);
			if(i == izlaz.size() - 1) {
				std::cout << el << ".";
			} else {
				std::cout << el << ", ";
			}
		}
		std::cout << std::endl;
	} else {
		if (prosti) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru." << std::endl;
		} else {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru." << std::endl;			
		}
	}

	return 0;
}