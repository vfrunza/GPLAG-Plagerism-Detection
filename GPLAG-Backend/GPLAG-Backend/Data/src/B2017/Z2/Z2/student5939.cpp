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
#include <stdexcept>
#include <vector>
#include <deque>
#include <iomanip>
#include <type_traits>

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Tip>
	bool KvadratnaMatrica(Tip matrica) {
		int broj_redova(matrica.size());
		for (int i=0; i<broj_redova; i++) {
			if (broj_redova!=matrica.at(i).size()) return false;
		}
		return true;
	}

template <typename Tip>
	Tip PjescaniSat(Tip kont, SmjerKretanja smjer) {
		Tip pjescani;
		if (kont.size()==0) return pjescani;
		for (int i=0; i<kont.size(); i++) {
			if (!KvadratnaMatrica(kont.at(i))) throw std::domain_error("3D matrica nema oblik kocke");
		}
		for (int i=0; i<kont.size(); i++) {
			for (int j=0; j<i; j++) {
				if (kont.at(i).size()!=kont.at(j).size()) throw std::domain_error("3D matrica nema oblik kocke");
			}
		}
		for (int i=0; i<kont.size(); i++) {
			if (kont.size()!=kont.at(i).size()) throw std::domain_error("3D matrica nema oblik kocke");
		}
		for (int i=0; i<kont.size(); i++) {
			if ((kont.at(i).size())%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		}
		int dim(kont.size());
		if (smjer==SmjerKretanja::GoreDolje) {
			for (int i=0; i<dim; i++) {
				typename std::remove_reference<decltype(kont.at(i))>::type matrica;
				for (int j=0; j<=(dim/2); j++) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=j; k<dim-j; k++) {
						red.push_back(kont.at(i).at(j).at(k));
					}
					matrica.push_back(red);
				}
				for (int j=(dim/2)+1; j<dim; j++) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=dim-j-1; k<j+1; k++) {
						red.push_back(kont.at(i).at(j).at(k));
					}
					matrica.push_back(red);
				}
				pjescani.push_back(matrica);
			}
		}
		else if (smjer==SmjerKretanja::DoljeGore) {
			for (int i=0; i<dim; i++) {
				typename std::remove_reference<decltype(kont.at(i))>::type matrica;
				for (int j=dim-1; j>=(dim/2)+1; j--) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=dim-j-1; k<j+1; k++) {
						red.push_back(kont.at(i).at(j).at(k));
					}
					matrica.push_back(red);
				}
				for (int j=(dim/2); j>=0; j--) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=j; k<dim-j; k++) {
						red.push_back(kont.at(i).at(j).at(k));
					}
					matrica.push_back(red);
				}
				pjescani.push_back(matrica);
			}
		}
		else if (smjer==SmjerKretanja::DesnoLijevo) {
			for (int i=0; i<dim; i++) {
				typename std::remove_reference<decltype(kont.at(i))>::type matrica;
				for (int j=dim-1; j>=(dim/2)+1; j--) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=dim-j-1; k<j+1; k++) {
						red.push_back(kont.at(i).at(k).at(j));
					}
					matrica.push_back(red);
				}
				for (int j=(dim/2); j>=0; j--) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=j; k<dim-j; k++) {
						red.push_back(kont.at(i).at(k).at(j));
					}
					matrica.push_back(red);
				}
				pjescani.push_back(matrica);
			}
		}
		else if (smjer==SmjerKretanja::LijevoDesno) {
			for (int i=0; i<dim; i++) {
				typename std::remove_reference<decltype(kont.at(i))>::type matrica;
				for (int j=0; j<=(dim/2); j++) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=j; k<dim-j; k++) {
						red.push_back(kont.at(i).at(k).at(j));
					}
					matrica.push_back(red);
				}
				for (int j=(dim/2)+1; j<dim; j++) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=dim-j-1; k<j+1; k++) {
						red.push_back(kont.at(i).at(k).at(j));
					}
					matrica.push_back(red);
				}
				pjescani.push_back(matrica);
			}
		}
		else if (smjer==SmjerKretanja::NaprijedNazad) {
			for (int i=0; i<dim; i++) {
				typename std::remove_reference<decltype(kont.at(i))>::type matrica;
				for (int j=0; j<=(dim/2); j++) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=j; k<dim-j; k++) {
						red.push_back(kont.at(j).at(i).at(k));
					}
					matrica.push_back(red);
				}
				for (int j=(dim/2)+1; j<dim; j++) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=dim-j-1; k<j+1; k++) {
						red.push_back(kont.at(j).at(i).at(k));
					}
					matrica.push_back(red);
				}
				pjescani.push_back(matrica);
			}
		}
		else if (smjer==SmjerKretanja::NazadNaprijed) {
			for (int i=0; i<dim; i++) {
				typename std::remove_reference<decltype(kont.at(i))>::type matrica;
				for (int j=dim-1; j>=(dim/2)+1; j--) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=dim-j-1; k<j+1; k++) {
						red.push_back(kont.at(j).at(i).at(k));
					}
					matrica.push_back(red);
				}
				for (int j=(dim/2); j>=0; j--) {
					typename std::remove_reference<decltype(kont.at(i).at(j))>::type red;
					for (int k=j; k<dim-j; k++) {
						red.push_back(kont.at(j).at(i).at(k));
					}
					matrica.push_back(red);
				}
				pjescani.push_back(matrica);
			}
		}
		return pjescani;
	}

int main ()
{
	int dimenzija;
	std::cout << "Unesite dimenziju (x/y/z): ";
	std::cin >> dimenzija;
	while (dimenzija<0) {
		std::cout << "Dimenzija nije ispravna, unesite opet: ";
		std::cin >> dimenzija;
	}
	
	std::vector<std::deque<std::deque<int>>> kon;
	std::cout << "Unesite elemente kontejnera: ";
	int broj;
	for (int i=0; i<dimenzija; i++) {
		std::deque<std::deque<int>> ploha;
		for (int j=0; j<dimenzija; j++) {
			std::deque<int> red;
			for (int k=0; k<dimenzija; k++) {
				std::cin >> broj;
				red.push_back(broj);
			}
			ploha.push_back(red);
		}
		kon.push_back(ploha);
	}
	
	int smjer_broj;
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	std::cin >> smjer_broj;
	while (smjer_broj<0 || smjer_broj>5) {
		std::cout << "Smjer nije ispravan, unesite opet: ";
		std::cin >> smjer_broj;
	}
	std::cout << std::endl;
	
	try {
		std::vector<std::deque<std::deque<int>>> pjescani;
		pjescani=PjescaniSat<std::vector<std::deque<std::deque<int>>>>(kon, SmjerKretanja(smjer_broj));
		std::cout << "Pjescani sat unesene matrice je: " << std::endl << std::endl;
		for (int i=0; i<pjescani.size(); i++) {
			for (int j=0; j<=(pjescani.at(i).size())/2; j++) {
				for (int k=0; k<j; k++) std::cout << "    ";
				for (int k=0; k<pjescani.at(i).at(j).size(); k++) {
					std::cout << std::right << std::setw(4) << pjescani.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			for (int j=(pjescani.at(i).size())/2+1; j<pjescani.at(i).size(); j++) {
				for (int k=0; k<pjescani.at(i).size()-j-1; k++) std::cout << "    ";
				for (int k=0; k<pjescani.at(i).at(j).size(); k++) {
					std::cout << std::right << std::setw(4) << pjescani.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl << std::endl;
		}
	}
	catch(std::domain_error e) {
		std::cout << "Izuzetak: " << e.what();
	}
	catch(std::length_error e) {
		std::cout << "Izuzetak: " << e.what();
	}
	return 0;
}