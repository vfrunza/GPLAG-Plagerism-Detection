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
#include <deque>
#include <vector>
#include <cmath>

enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke (int n) {
	if (n==0) return false;
	while (n!=1) {
		if(n%2 != 0) return false;
		n/=2;
	}
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> vektor, Smjer smjer) {
	std::deque<std::vector<int>> dek(1);
	int br(0);
	int velicina(0);
	for (int i=0; i<vektor.size(); i+=velicina) {
		bool kraj(false);
		velicina=1;
		int prvi=vektor.at(i);
		if (StepenDvojke(vektor.at(i))) {
			for (int j=i+1; j<vektor.size(); j++) {
				if(StepenDvojke(vektor.at(j))) {
					if(smjer==Rastuci) {
						if(vektor.at(i)>vektor.at(j)) {
							if (dek.at(br).size()!=0) {
								velicina=dek.at(br).size();
								br++;
								dek.resize(br+1);
							}
							break;
						}
						if(int(dek.at(br).size())==0) dek.at(br).push_back(prvi);
						dek.at(br).push_back(vektor.at(j));
						vektor.at(i)=vektor.at(j);
					} else {
						if (vektor.at(i)<vektor.at(j)) {
							if(dek.at(br).size()!=0) {
								velicina=dek.at(br).size();
								br++;
								dek.resize(br+1);
							}
							break;
						}
						if(dek.at(br).size()==0) dek.at(br).push_back(prvi);
						dek.at(br).push_back(vektor.at(j));
						vektor.at(i)=vektor.at(j);
					}
				} else {
					if(dek.at(br).size()!=0) {
						br++;
						dek.resize(br+1);
					}
					velicina=1;
					break;
				}
				if(j==vektor.size()-1) kraj=true;
			}
		}
		if(kraj) break;
	}
	
	return dek;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::vector<int>vektor(n);
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		std::cin >> vektor.at(i);
	}
	int opcija;
	do {
		std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin >> opcija;
	} while (opcija!=1 && opcija!=2);
	
	Smjer smjer;
	if(opcija==1) smjer=Rastuci;
	else smjer=Opadajuci;
	
	std::deque<std::vector<int>>dek;
	if(opcija==1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else if (opcija==2) std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	
	dek=MaksimalniPodnizoviStepenaDvojke(vektor, smjer);
	for (int i=0; i<dek.size(); i++) {
		for (int j=0; j<dek.at(i).size(); j++) {
			std::cout << dek.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}

	
	return 0;
}