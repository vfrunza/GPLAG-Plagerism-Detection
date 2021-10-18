#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
typedef std::vector<int> Vektor;
typedef std::deque<std::vector<int>> DekVektora;
enum Smjer{Rastuci,Opadajuci};

bool StepenDvojke(int broj) {
	if(broj==1) return true;
	int i;
	for(i=1;i<=broj;i*=2);
	if(i!=2*broj) return false;
	else return true;
}

DekVektora MaksimalniPodnizoviStepenaDvojke(Vektor x, Smjer AiE) {
	if(AiE==Rastuci) {
		DekVektora dek;
		for(int i=0;i<x.size();i++) {
			int brojac=0;
			Vektor pomocni(0);
			if(StepenDvojke(x.at(i))==true) {
				pomocni.push_back(x.at(i));
				for(int j=i+1;j<x.size();j++) {
					if(x.at(j)>=x.at(j-1) && StepenDvojke(x.at(j))==true) {
						pomocni.push_back(x.at(j));
						brojac++;
					}
					  else {
					  	break;
					  }
				}
			}
			else continue;
			if(brojac>=1) {
				dek.push_back(pomocni);
			}
				i+=brojac;
		}
		return dek;
	}
	else if(AiE==Opadajuci) {
		DekVektora dek;
		for(int i=0;i<x.size();i++) {
			int brojac=0;
			Vektor pomocni(0);
			if(StepenDvojke(x.at(i))==true) {
				pomocni.push_back(x.at(i));
				for(int j=i+1;j<x.size();j++) {
					if(x.at(j)<=x.at(j-1) && StepenDvojke(x.at(j))==true) {
						pomocni.push_back(x.at(j));
						brojac++;
					}
					  else {
					  	break;
					  }
				}
			}
			else continue;
			if(brojac>=1) {
				dek.push_back(pomocni);
			}
			i+=brojac;
		}
		return dek;
	}
}

int main () {
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	Vektor v(n);
	int broj;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0;i<n;i++) {
		std::cin >> broj;
		v.push_back(broj);
	}
	int podniz;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> podniz;
	DekVektora dek=MaksimalniPodnizoviStepenaDvojke(v,Smjer(podniz-1));
	if(podniz==1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else if(podniz==2) std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i=0;i<dek.size();i++) {
		for(int j=0;j<dek[i].size();j++) {
		std::cout << dek[i][j]<<" ";
	    }
	std::cout << std::endl;
	}
	return 0;
}