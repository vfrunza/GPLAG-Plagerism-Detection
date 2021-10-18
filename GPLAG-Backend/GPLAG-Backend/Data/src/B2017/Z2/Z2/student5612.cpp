#include <iostream>
#include <vector>
#include <stdexcept>
#include <deque>
#include<iomanip>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename Kontejner>
Kontejner PjescaniSat(Kontejner kont, SmjerKretanja s)
{
	Kontejner novi;
	novi.resize(kont.size());
	for(int i = 0; i < novi.size(); i++) {
		novi.at(i).resize(kont.at(i).size());
		int p(0);
		for(int j = kont.at(i).size()/2; j >= 0; j--) {
			novi.at(i).at(j).resize(2*p + 1);
			p++;
		}
		int p1(0);
		for(int k = kont.at(i).size()/2; k < kont.at(i).size(); k++) {
			novi.at(i).at(k).resize(2*p1 + 1);
			p1++;
		}
	}

	if(s == SmjerKretanja::GoreDolje) {
		for(int i = 0; i < kont.size(); i++) {
			int pomocna_kolona(0);
			auto matrica_original(kont.at(i));
			auto matrica_nova(novi.at(i));


			for(int red = 0; red <=  matrica_original.size()/2 ; red++) {
				int kolona_nova1(0);

				for(int kolona = pomocna_kolona; kolona < matrica_original.at(0).size() - pomocna_kolona; kolona++) {
					novi.at(i).at(red).at(kolona_nova1) = (matrica_original.at(red).at(kolona));
					kolona_nova1++;
				}
				pomocna_kolona++;
			}
			pomocna_kolona-=2;
			for(int red = matrica_original.size()/2 + 1; red < matrica_original.size(); red++) {
				int kolona_nova2(0);
				for(int kolona = pomocna_kolona; kolona < matrica_original.at(0).size() - pomocna_kolona; kolona++) {
					novi.at(i).at(red).at(kolona_nova2) = matrica_original.at(red).at(kolona);
					kolona_nova2++;
				}
				pomocna_kolona--;
			}
		}
	} else if(s == SmjerKretanja::DoljeGore) {
		for(int i = 0; i < kont.size(); i++) {
			int pomocna_kolona(0);
			auto matrica_original(kont.at(i));
			int red_novi(0);

			for(int red = matrica_original.size() - 1; red >= matrica_original.size()/2; red--) {
				int kolona_nova1(0);
				for(int kolona = pomocna_kolona; kolona < matrica_original.at(0).size() - pomocna_kolona; kolona++) {
					novi.at(i).at(red_novi).at(kolona_nova1) = matrica_original.at(red).at(kolona);
					kolona_nova1++;
				}
				pomocna_kolona++;
				red_novi++;

			}
			pomocna_kolona-=2;

			for(int red = matrica_original.size()/2 - 1; red >= 0; red--) {
				int kolona_nova2(0);

				for(int kolona = pomocna_kolona; kolona < matrica_original.at(0).size() - pomocna_kolona; kolona++) {
					novi.at(i).at(red_novi).at(kolona_nova2) = matrica_original.at(red).at(kolona);
					kolona_nova2++;
				}
				pomocna_kolona--;
				red_novi++;

			}
		}
	} else if(s == SmjerKretanja::DesnoLijevo) {
		for(int i = 0; i < kont.size(); i++) {
			int red_novi(0);
			int pomocna_red(0);
			auto matrica_original(kont.at(i));

			for(int kolona = matrica_original.at(0).size() - 1; kolona >= matrica_original.at(0).size()/2; kolona--) {
				int kolona_nova1(0);

				for(int red = pomocna_red; red < matrica_original.size() - pomocna_red; red++) {
					novi.at(i).at(red_novi).at(kolona_nova1) = matrica_original.at(red).at(kolona);
					kolona_nova1++;
				}
				red_novi++;
				pomocna_red++;

			}
			pomocna_red-=2;
			for(int kolona = matrica_original.at(0).size()/2 - 1; kolona >= 0; kolona--) {
				int kolona_nova2(0);
				for(int red = pomocna_red; red < matrica_original.size() - pomocna_red; red++) {
					novi.at(i).at(red_novi).at(kolona_nova2) = matrica_original.at(red).at(kolona);
					kolona_nova2++;
				}
				red_novi++;
				pomocna_red++;
			}
		}
	} else if(s == SmjerKretanja::LijevoDesno) {
		for(int i = 0; i < kont.size(); i++) {
			int red_novi(0);
			int pomocna_red(0);
			auto matrica_original(kont.at(i));

			for(int kolona = 0; kolona <= matrica_original.at(0).size()/2; kolona++) {
				int kolona_nova1(0);
				for(int red = pomocna_red; red < matrica_original.size() - pomocna_red; red++) {
					novi.at(i).at(red_novi).at(kolona_nova1) = matrica_original.at(red).at(kolona);
					kolona_nova1++;
				}
				pomocna_red++;
				red_novi++;
			}
			pomocna_red-=2;
			for(int kolona = matrica_original.at(0).size()/2 + 1; kolona < matrica_original.at(0).size(); kolona++) {
				int kolona_nova2(0);
				for(int red = pomocna_red; red < matrica_original.size() - pomocna_red; red++) {
					novi.at(i).at(red_novi).at(kolona_nova2) = matrica_original.at(red).at(kolona);
					kolona_nova2++;
				}
				red_novi++;
				pomocna_red++;
			}
		}
	} else if(s == SmjerKretanja::NaprijedNazad) {

		for(int red = 0; red < kont.size(); red++) {
			int pomocna_kolona(0);
			for(int i = 0; i <= kont.size()/2; i++) {
				int j(0);
				for(int kolona = pomocna_kolona; kolona < kont.at(red).at(i).size() - pomocna_kolona; kolona++) {
					novi.at(red).at(i).at(j) = kont.at(i).at(red).at(kolona);
					j++;
				}
				pomocna_kolona++;
			}

			pomocna_kolona-=2;
			for(int i = kont.size()/2 + 1; i < kont.size(); i++) {
				for(int kolona = pomocna_kolona; kolona < kont.at(red).at(i).size() - pomocna_kolona; kolona++) {
					novi.at(red).at(i).at(kolona) = kont.at(i).at(red).at(kolona);
				}
				pomocna_kolona--;
			}
		}

	} else if(s == SmjerKretanja::NazadNaprijed) {
		for(int red = 0; red < kont.size(); red++) {
			int pomocna_kolona(0);
			int k(0);
			for(int i = kont.size() - 1; i >= kont.size()/2; i--) {
				int j(0);
				for(int kolona = pomocna_kolona; kolona < kont.at(red).at(i).size() - pomocna_kolona; kolona++) {
					novi.at(red).at(k).at(j) = kont.at(i).at(red).at(kolona);
					j++;
				}
				pomocna_kolona++;
				k++;
			}
			pomocna_kolona-=2;
			for(int i = kont.size()/2 - 1; i >= 0; i--) {
				int j=0;
				for (int kolona = pomocna_kolona; kolona < kont.at(red).at(i).size() - pomocna_kolona; kolona++) {
					novi.at(red).at(k).at(j) = kont.at(i).at(red).at(kolona);
					j++;
				}
				pomocna_kolona--;
				k++;
			}
		}

	}
	return novi;
}

int main ()
{
	try {

		std::cout << "Unesite dimenziju (x/y/z): ";
		int duzina;
		std::cin >> duzina;

		if(duzina < 0) {
			do {
				std::cout << "Dimenzija nije ispravna, unesite opet: ";
				std::cin >> duzina;
			} while(duzina < 0);
		}

		std::cout << "Unesite elemente kontejnera: ";
		std::vector<std::deque<std::deque<int>>> m1;
		std::vector<std::deque<std::deque<int>>> m2;


		m1.resize(abs(duzina));
		for(int i = 0; i < m1.size(); i++) {
			m1.at(i).resize(abs(duzina));
		}
		for(int i = 0; i < m1.size(); i++) {
			for(int j = 0; j < m1.at(i).size(); j++) {
				m1.at(i).at(j).resize(abs(duzina));
			}
		}
		for(int i = 0; i < abs(duzina); i++) {
			for(int j = 0; j < abs(duzina); j++) {
				for(int k = 0; k < abs(duzina); k++) {
					std::cin >> m1.at(i).at(j).at(k);
				}
			}
		}
		for(int i = 0; i < abs(duzina); i++) {
			if(m1.at(i).size() != m1.size()) throw std::domain_error("3D matrica nema oblik kocke");
		}
		m2.resize(m1.size());
		for(int i = 0; i < m2.size(); i++) {
			m2.at(i).resize(m1.at(i).size());
			int p(0);
			for(int j = m1.at(i).size()/2; j >= 0; j--) {
				m2.at(i).at(j).resize(2*p + 1);
				p++;
			}
			int p1(0);
			for(int k = m1.at(i).size()/2; k < m1.at(i).size(); k++) {
				m2.at(i).at(k).resize(2*p1 + 1);
				p1++;
			}
		}
		std::cout << "Unesite smjer kretanja [0 - 5]: ";
		do {
			int smjer(0);
			std::cin >> smjer;
			if(smjer < 0 || smjer > 5) {
				do {
					std::cout << "Smjer nije ispravan, unesite opet: ";
					std::cin >> smjer;
				} while(smjer < 0 || smjer > 5);
			}
			std::cout << std::endl;
			if(smjer == 0) {
				m2 = PjescaniSat(m1,SmjerKretanja::NaprijedNazad);
				break;
			} else if(smjer == 1) {
				m2 = PjescaniSat(m1,SmjerKretanja::NazadNaprijed);
				break;
			} else if(smjer == 2) {
				m2 = PjescaniSat(m1,SmjerKretanja::GoreDolje);
				break;
			} else if(smjer == 3) {
				m2 = PjescaniSat(m1,SmjerKretanja::DoljeGore);
				break;
			} else if(smjer == 4) {
				m2 = PjescaniSat(m1,SmjerKretanja::LijevoDesno);
				break;
			} else if(smjer == 5) {
				m2 = PjescaniSat(m1,SmjerKretanja::DesnoLijevo);
				break;
			}
		} while(1);
		if(duzina % 2 == 0) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");

		std::cout << "\nPjescani sat unesene matrice je:" << std::endl;

		for(int i = 0; i < duzina; i++) {
			int l(0);
			for(int red = 0; red < m2.at(i).size(); red++) {
				for(int kolona = 0; kolona < m2.at(i).at(red).size(); kolona++) {
					if(kolona == 0 && red <= m2.at(i).size()/2) {
						std::cout << std::setw(4 + l) << m2.at(i).at(red).at(kolona);
						l+=4;
					} else if(kolona == 0 && red > m2.at(i).size()/2) {
						std::cout << std::setw(l-4) << m2.at(i).at(red).at(kolona);
						l-=4;
					} else {

						std::cout << std::setw(4) << m2.at(i).at(red).at(kolona);
					}
				}
				std::cout << "\n";
			}
		}
	} catch(std::length_error e1) {
		std::cout <<"Izuzetak: " << e1.what() << std::endl;
	} catch(std::domain_error e2) {
		std::cout << "Izuzetak: "<< e2.what() << std::endl;
	}
	return 0;
}