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
#include <cmath>

enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke(int broj)
{

	double x=std::log2(broj);
	int y=x;
	if(x==double(y)) return true;
	return false;

}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor, enum Smjer smjer)
{
	std::deque<std::vector<int>> DekVektora;
	std::vector<int> PomocniVektor;
	int brojac(0);

	if(smjer==Rastuci) {

		for(int i=0; i<vektor.size(); i++) {

			if(i+1<vektor.size()) {

				if (vektor.at(i)<=vektor.at(i+1)) {

					PomocniVektor.clear();
					brojac=0;
					for(int j=i; j<vektor.size(); j++) {

						if(j+1<vektor.size()) {

							if(vektor.at(j)<=vektor.at(j+1) && StepenDvojke(vektor.at(j))) {
								PomocniVektor.push_back(vektor.at(j));
								if(j==vektor.size()-2 && vektor.at(j)<=vektor.at(vektor.size()-1) && StepenDvojke(vektor.at(vektor.size()-1)))
									PomocniVektor.push_back(vektor.at(vektor.size()-1));

								else if(j+2<vektor.size()) {
									if((vektor.at(j+1)>vektor.at(j+2)) || (StepenDvojke(vektor.at(j+2)==false))) {
										if(StepenDvojke(vektor.at(j+1))) {
											PomocniVektor.push_back(vektor.at(j+1));
											brojac--;
											if(j+2==vektor.size()-1) j++;
										}
									}
								}
								brojac++;
							}

							else {

								break;
							}
						}

					}
					if(PomocniVektor.size()>1) {
						DekVektora.push_back(PomocniVektor);
						i+=brojac;
					}
				}
			}
		}
	}

	else if(smjer==Opadajuci) {
		for(int i=0; i<vektor.size(); i++) {

			if(i+1<vektor.size()) {

				if(vektor.at(i)>=vektor.at(i+1)) {

					PomocniVektor.clear();
					brojac=0;

					for(int j=i; j<vektor.size(); j++) {

						if(j+1<vektor.size()) {

							if(vektor.at(j)>=vektor.at(j+1) && StepenDvojke(vektor.at(j))) {
								PomocniVektor.push_back(vektor.at(j));
								if(j==vektor.size()-2 && vektor.at(j)>=vektor.at(vektor.size()-1) && StepenDvojke(vektor.at(vektor.size()-1))) {
									PomocniVektor.push_back(vektor.at(vektor.size()-1));

								} else if(j+2<vektor.size()) {

									if((vektor.at(j+1)<vektor.at(j+2)) || (StepenDvojke(vektor.at(j+2)==false))) {
										if(StepenDvojke(vektor.at(j+1))) {
											PomocniVektor.push_back(vektor.at(j+1));
											brojac--;
											if(j+2==vektor.size()-1) j++;
										}
									}
								}
								brojac++;
							} else {
								break;
							}
						}
					}

					if(PomocniVektor.size()>1) {
						DekVektora.push_back(PomocniVektor);
						i+=brojac;
					}

				}
			}
		}

	}

	return DekVektora;
}

int main ()
{
	int BrElemenata;
	std::vector<int> Vektor_Brojeva;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> BrElemenata;

	int Element_Vektora;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<BrElemenata; i++) {
		std::cin >> Element_Vektora;
		Vektor_Brojeva.push_back(Element_Vektora);
	}

	int Vrsta_podniza;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> Vrsta_podniza;

	Smjer Nacin_podniza;
	if(Vrsta_podniza==1) Nacin_podniza=Rastuci;
	else if(Vrsta_podniza==2) Nacin_podniza=Opadajuci;
	auto m(MaksimalniPodnizoviStepenaDvojke(Vektor_Brojeva,Nacin_podniza));

	if(Vrsta_podniza==1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else if(Vrsta_podniza==2) std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.at(i).size(); j++)
			std::cout << m.at(i).at(j) << " ";
		std::cout  << std::endl;
	}
	return 0;
}