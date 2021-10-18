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
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };


template <typename Tip_Kont>
Tip_Kont Rotiraj (Tip_Kont kont, SmjerKretanja smjer) {
	auto rotirani_kont(kont);
	for (int i=0; i<kont.size(); i++) {
		for (int j=0; j<kont.size(); j++) {
			for (int k=0; k<kont.size(); k++) {
				if (smjer==SmjerKretanja::DoljeGore) rotirani_kont.at(i).at(j).at(k)=kont.at(i).at(kont.size()-j-1).at(k);
				else if (smjer==SmjerKretanja::DesnoLijevo) rotirani_kont.at(i).at(j).at(k)=kont.at(i).at(k).at(kont.size()-j-1);
				else if (smjer==SmjerKretanja::LijevoDesno) rotirani_kont.at(i).at(j).at(k)=kont.at(i).at(k).at(j);
				else if (smjer==SmjerKretanja::NazadNaprijed) rotirani_kont.at(i).at(j).at(k)=kont.at(kont.size()-j-1).at(i).at(k);
				else if (smjer==SmjerKretanja::NaprijedNazad) rotirani_kont.at(i).at(j).at(k)=kont.at(j).at(i).at(k);
			}
		}
	}
	return rotirani_kont;
}

template <typename Tip_Kont>
bool Kocka(Tip_Kont kont) {
	int velicina(kont.size());
	for (int i=0; i<velicina; i++) {
		if (kont.at(i).size()!=velicina) return false;
		for (int j=0; j<velicina; j++) {
			if (kont.at(i).at(j).size()!=velicina) return false;
		}
	}
	return true;
}

template <typename Tip_Kont>
Tip_Kont PjescaniSat (Tip_Kont kont, SmjerKretanja smjer) {
	
	if (kont.size()<=0) return kont;
	else if (!Kocka(kont)) throw std::domain_error("3D matrica nema oblik kocke");
	else if (kont.size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	
	kont=Rotiraj(kont, smjer);
	auto pokazivac(&kont.at(0).at(0).at(0));
	
	for (int i=0; i<kont.size(); i++) {
		for (int j=0; j<kont.size(); j++) {
			
			if (j<=kont.size()/2) {
				pokazivac=std::copy(&kont.at(i).at(j).at(j), &kont.at(i).at(j).at(kont.size()-j-1)+1, &kont.at(i).at(j).at(0));
				kont.at(i).at(j).resize(pokazivac-&kont.at(i).at(j).at(0));
			}
			else {
				pokazivac=std::copy (&kont.at(i).at(j).at(kont.size()-j-1), &kont.at(i).at(j).at(j)+1, &kont.at(i).at(j).at(0));
				kont.at(i).at(j).resize(pokazivac-&kont.at(i).at(j).at(0));
			}
		}
	}
	return kont;
}



int main ()
{
	int n;
	std::cout << "Unesite dimenziju (x/y/z): ";
	while (std::cin >> n, n<0) std::cout << "Dimenzija nije ispravna, unesite opet: ";
	std::vector<std::deque<std::deque<int>>> kontejner;
	kontejner.resize(n);
	for (int i=0; i<n; i++) kontejner.at(i).resize(n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			kontejner.at(i).at(j).resize(n);
		}
	}
	
	std::cout << "Unesite elemente kontejnera: ";
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				std::cin >> kontejner.at(i).at(j).at(k);
			}
		}
	}
	int izbor;
	std::cout << "Unesite smjer kretanja [0 - 5]:";
	while (std::cin >> izbor, izbor<0 || izbor>5) std::cout << " Smjer nije ispravan, unesite opet: ";
	
	
	try {
	
		kontejner=PjescaniSat(kontejner, SmjerKretanja(izbor));
	
		std::cout << std::endl << "Pjescani sat unesene matrice je:" << std::endl;
		for (int i=0; i<kontejner.size(); i++) {
			for (int j=0; j<kontejner.size(); j++) {
				if (j>0 && j<=kontejner.size()/2) std::cout << std::setw(4*j) << " ";
				else if (j!=kontejner.size()-1 && j>kontejner.size()/2) std::cout << std::setw((kontejner.size()-j-1)*4) << " ";
				for (int k=0; k<kontejner.at(i).at(j).size(); k++) {
					std::cout << std::setw(4) << kontejner.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
	catch (std::exception &izuzetak) {
		std::cout << std::endl << "Izuzetak: " << izuzetak.what();
	}
	
	return 0;
}