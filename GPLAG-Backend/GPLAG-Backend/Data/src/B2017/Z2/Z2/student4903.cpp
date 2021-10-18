/*B 2017/2018, Zadaća 2, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <deque>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

typedef std::vector<std::deque<std::deque<int>>> Matrica3D;

template <typename Kontejner>
Kontejner PjescaniSat(Kontejner kont, SmjerKretanja kretanje)
{
	Kontejner pjescani;
	if(kont.size()==0) return pjescani;
	for(int i(0); i<kont.size(); i++) {
		if(kont.at(i).size()!=kont.size()) throw std::domain_error("3D matrica nema oblik kocke");
		for(int j(0); j<kont.size(); j++) {
			if(kont.at(i).at(j).size()!=kont.size()) throw std::domain_error("3D matrica nema oblik kocke");
		}
	}
	if(kont.size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	for(int i(0); i<kont.size(); i++) {
		pjescani.push_back(typename std::remove_reference<decltype(kont[0])>::type ());
		for(int j(0); j<kont.size(); j++) {
			pjescani.at(i).push_back(typename std::remove_reference<decltype(kont[0][0])>::type ());
		}
	}
	if(kretanje==SmjerKretanja::GoreDolje || kretanje==SmjerKretanja::DoljeGore) {
		for(int i(0); i<kont.size(); i++) {
			for(int j(0); j<=kont.size()/2+1; j++) {
				for(int k(j); k<kont.size()-j; k++) {
					pjescani.at(i).at(j).push_back(kont.at(i).at(j).at(k));
					if(j<kont.size()/2) pjescani.at(i).at(kont.size()-j-1).push_back(kont.at(i).at(kont.size()-j-1).at(k));
				}
			}
		}
		if(kretanje==SmjerKretanja::DoljeGore) {
			for(int i(0); i<kont.size(); i++) {
				std::reverse(pjescani.at(i).begin(), pjescani.at(i).end());
			}
		}
	} else if(kretanje==SmjerKretanja::NaprijedNazad || kretanje==SmjerKretanja::NazadNaprijed) {
		for(int i(0); i<kont.size(); i++) {
			for(int j(0); j<=kont.size()/2+1; j++) {
				for(int k(j); k<kont.size()-j; k++) {
					pjescani.at(i).at(j).push_back(kont.at(j).at(i).at(k));
					if(j<kont.size()/2) pjescani.at(i).at(kont.size()-j-1).push_back(kont.at(kont.size()-j-1).at(i).at(k));
				}
			}
		}
		if(kretanje==SmjerKretanja::NazadNaprijed) {
			for(int i(0); i<kont.size(); i++) {
				std::reverse(pjescani.at(i).begin(), pjescani.at(i).end());
			}
		}
	} else {
		for(int i(0); i<kont.size(); i++) {
			for(int j(0); j<=kont.size()/2+1; j++) {
				for(int k(j); k<kont.size()-j; k++) {
					pjescani.at(i).at(j).push_back(kont.at(i).at(k).at(j));
					if(j<kont.size()/2) pjescani.at(i).at(kont.size()-j-1).push_back(kont.at(i).at(k).at(kont.size()-j-1));
				}
			}
		}
		if(kretanje==SmjerKretanja::DesnoLijevo) {
			for(int i(0); i<kont.size(); i++) {
				std::reverse(pjescani.at(i).begin(), pjescani.at(i).end());
			}
		}
	}
	return pjescani;
}

int main ()
{
	std::cout << "Unesite dimenziju (x/y/z): ";
	int n;
	while(!(std::cin >> n), n<0) std::cout << "Dimenzija nije ispravna, unesite opet: ";
	try {
		Matrica3D kocka(n, std::deque<std::deque<int>> (n,std::deque<int> (n)));
		std::cout << "Unesite elemente kontejnera: ";
		for(int i(0); i<n; i++) {
			for(int j(0); j<n; j++) {
				for(int k(0); k<n; k++) {
					std::cin >> kocka.at(i).at(j).at(k);
				}
			}
		}
		std::cout << "Unesite smjer kretanja [0 - 5]: ";
		int p;
		while(!(std::cin >> p), !(p>=0 && p<=5)) std::cout << "Smjer nije ispravan, unesite opet: ";
		SmjerKretanja kretanje(SmjerKretanja::NaprijedNazad);
		if(p==1) kretanje=SmjerKretanja::NazadNaprijed;
		else if(p==2) kretanje=SmjerKretanja::GoreDolje;
		else if(p==3) kretanje=SmjerKretanja::DoljeGore;
		else if(p==4) kretanje=SmjerKretanja::LijevoDesno;
		else if(p==5) kretanje=SmjerKretanja::DesnoLijevo;
		kocka=PjescaniSat(kocka, kretanje);
		std::cout << "\nPjescani sat unesene matrice je:\n";
		for(int i(0); i<kocka.size(); i++) {
			for(int j(0); j<kocka.size(); j++) {
				for(int k(0); k<(n-kocka.at(i).at(j).size())/2; k++) std::cout  << std::setw(4) << std::setfill(' ') << "  ";
				for(int k(0); k<kocka.at(i).at(j).size(); k++) {
					std::cout << std::setw(4) << std::setfill(' ') << kocka.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	} catch(std::domain_error p) {
		std::cout << "\nIzuzetak: " << p.what() << std::endl;
	} catch(std::length_error p) {
		std::cout << "\nIzuzetak: " << p.what() << std::endl;
	} catch(std::bad_alloc) {
		std::cout << "\nIzuzetak: Nedovoljno memorije!\n";
	}
	return 0;
}