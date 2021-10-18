/*B 2017/2018, Zadaća 1, Zadatak 3

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

enum Smjer {Rastuci, Opadajuci};
typedef std::deque<std::vector<int>> Dek_vektora;

bool StepenDvojke(int broj) {
	if (broj < 1) return false;
	
	while (broj != 1) {
		if (broj % 2 != 0) return false;
		broj = broj / 2;
	}	
	
	return true;
}

bool MozeIciDesno(int lijevi, int desni, Smjer s) {
	if (!StepenDvojke(lijevi) || !StepenDvojke(desni)) return false;
	
	if (s == Rastuci) {
		return lijevi <= desni;
	} else if (s == Opadajuci) {
		return lijevi >= desni;
	}
	
	return false;
}

Dek_vektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s) {
	Dek_vektora rezultat;
	int glava = 0, rep = 0;
	int duzina = v.size();
	while (true) {
		if (glava < duzina-1 && MozeIciDesno(v.at(glava), v.at(glava+1), s)) {
			glava++;	
		} else {
			// ako je "vektor" duzine samo jednog elementa, zanemari ga i ne dodaji u dek
			if (glava != rep) {
				std::vector<int> tmp;
				// dodaj podniz u tmp pa u dek
				for (int i = rep; i <= glava; i++) {
					tmp.push_back(v.at(i));
				}
				rezultat.push_back(tmp);
			}
			// ako smo na samom kraju nizu, iskoci iz petlje
			if (glava == duzina - 1) break;
			rep = ++glava;
		}
	}

	return rezultat;
}


int main ()
{
	int n, izbor, e;
	std::vector<int> v;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >> e;
		v.push_back(e);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> izbor;


	if(izbor == 1) {
		Dek_vektora d(MaksimalniPodnizoviStepenaDvojke(v, Rastuci));
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				std::cout << d.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	} else if(izbor == 2) {
		Dek_vektora d(MaksimalniPodnizoviStepenaDvojke(v, Opadajuci));
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				std::cout << d.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}

	}
	return 0;
}