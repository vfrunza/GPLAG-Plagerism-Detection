#include <limits>
#include <deque>
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

enum Smjer {Rastuci=1, Opadajuci};

// funkcija provjerava je li proslijedjeni broj stepen broja 2
int JeLiStepenDvojke (int broj) {
	double p=log2(broj);
	int y=p;
	if (p==double(y)) return 1;
	return 0;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> vektor, Smjer smer) {
	std::deque<std::vector<int>> dek ( vektor.size()/2, std::vector<int> (vektor.size()) );
	int l(0), j(0), znak(1);
	// slucaj kada trazimo rastuce nizove
	if (smer==Rastuci) {
		for (int i=0; i<vektor.size(); i++) {
			int k(0), znak(1);			
			if (i==vektor.size()-1) break;
			if (JeLiStepenDvojke(vektor.at(i))==1) {
				j=i;
				j++;
				// ako dva uzastopna zadovoljavaju, onda postoji podniz
				if (JeLiStepenDvojke(vektor.at(j))==1 and vektor.at(j)>=vektor.at(j-1)) { // stavljamo operator >= jer mogu biti jednaki uzastopni stepeni
					dek.at(l).at(k)=(vektor.at(j-1));
					k++;
					dek.at(l).at(k)=(vektor.at(j));
					k++;
					if (j==vektor.size()-1) znak=0;
					if (znak==1) {
						j++;
						while (JeLiStepenDvojke(vektor.at(j))==1 and vektor.at(j)>=vektor.at(j-1)) {
							dek.at(l).at(k)=(vektor.at(j));
							k++;
							if (j==vektor.size()-1) break;
							j++;
						}
					}
					dek.at(l).resize(k);
					l++;
					i=j-1;
				}
			}
		}
		dek.resize(l);
	}
	l=0, j=0;
	// slucaj kada trazimo opadajuce nizove, slican blok naredbi
	if (smer==Opadajuci) {
		for (int i=0; i<vektor.size(); i++) {
			int k(0), znak(1);
			if (i==vektor.size()-1) break;
			if (JeLiStepenDvojke(vektor.at(i))==1) {
				j=i;
				j++;
				if (JeLiStepenDvojke(vektor.at(j))==1 and vektor.at(j)<=vektor.at(j-1)) {
					dek.at(l).at(k)=(vektor.at(j-1));
					k++;
					dek.at(l).at(k)=(vektor.at(j));
					k++;
					if (j==vektor.size()-1) znak=0;
					if (znak==1) {
						j++;
						while (JeLiStepenDvojke(vektor.at(j))==1 and vektor.at(j)<=vektor.at(j-1)) {
							dek.at(l).at(k)=(vektor.at(j));
							k++;
							if (j==vektor.size()-1) break;
							j++;
						}
					}
					dek.at(l).resize(k);
					l++;
					i=j-1;
				}
			}
		}
		dek.resize(l);
	}
	return dek;
}

int main ()
{
	std::vector<int> vektor;
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	int k;
	for (int i=0; i<n; i++) {
		std::cin >> k;
		vektor.push_back(k);
		if (i==n-1) break;
	}
	int e;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> e;
	Smjer t=Smjer(e);
	std::deque<std::vector<int>> deq=MaksimalniPodnizoviStepenaDvojke(vektor, t);
	if (t==Rastuci) {
		std::cout << "Maksimalni rastuci podnizovi: ";
		for (int i=0; i<deq.size(); i++) {
			std::cout << "\n";
			for (int j=0; j<deq.at(i).size(); j++) {
					std::cout << deq.at(i).at(j) << " ";
					if (j==deq.at(i).size()-1) break;
			}
			if (i==deq.size()-1) break;
		}
	}
	if (t==Opadajuci) {
		std::cout << "Maksimalni opadajuci podnizovi: ";
		for (int i=0; i<deq.size(); i++) {
			std::cout << "\n";
			for (int j=0; j<deq.at(i).size(); j++) {
					std::cout << deq.at(i).at(j) << " ";
					if (j==deq.at(i).size()-1) break;
			}
			if (i==deq.size()) break;
		}
	}
	return 0;
}