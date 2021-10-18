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
enum Smjer {Rastuci=true, Opadajuci=false};

// Funkcija koja provjerava da li je broj stepen dvojke ili ne
bool DaLiJeStepenDvojke (int n) {
	if (n==0) return false;
	while (n!=1) {
		if (n%2!=0) return false;
		n/=2;
	}
	return true;
}

// Funkcija koja izdvaja elemente vektora u rastuce/opadajuce
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>v, enum Smjer logic) {
	std::deque<std::vector<int>> rastuci;
	std::deque<std::vector<int>> opadajuci;
	std::vector<int>pomocni;
	
	// Dio koda koji izdvaja rastuce vektore u dek vektora
	for (int i=0; i<int(v.size()-1); i++) {
		
		if (DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1))) {
			if (v.at(i)<v.at(i+1)) {
				pomocni.push_back(v.at(i));
			}
			else {
				if (pomocni.size()>0) {
					if (DaLiJeStepenDvojke(v.at(i))) pomocni.push_back(v.at(i));
					rastuci.push_back(pomocni);
				}
				pomocni.resize(0);
			}
		}
		else {
			if (pomocni.size()>0) {
				if (DaLiJeStepenDvojke(v.at(i))) pomocni.push_back(v.at(i));
				rastuci.push_back(pomocni);
				pomocni.resize(0);
			}
		}
	}
	if (pomocni.size()>0) {
		if (DaLiJeStepenDvojke(v.at(v.size()-1))) {
			pomocni.push_back(v.at(v.size()-1));
			rastuci.push_back(pomocni);
		}
	}
	pomocni.resize(0);
	
	
	
	// Dio koda koji izdvaja opadajuce vektore u dek vektora
	for (int i=0; i<int(v.size()-1); i++) {
		
		if (DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1))) {
			if (v.at(i)>v.at(i+1)) {
				pomocni.push_back(v.at(i));
			}
			else {
				if (pomocni.size()>0) { 
					if (DaLiJeStepenDvojke(v.at(i))) pomocni.push_back(v.at(i));
					opadajuci.push_back(pomocni);
				}
				pomocni.resize(0);
			}
		}
		
		else {
			if (pomocni.size()>0) {
				if (DaLiJeStepenDvojke(v.at(i))) pomocni.push_back(v.at(i));
				opadajuci.push_back(pomocni);
				pomocni.resize(0);
			}
		}
	}
	if (pomocni.size()>0) {
		if (DaLiJeStepenDvojke(v.at(v.size()-1))) {
			pomocni.push_back(v.at(v.size()-1));
			opadajuci.push_back(pomocni);
		}
	}
	pomocni.resize(0);
	
	if (logic) return rastuci;
	return opadajuci;
}

int main () {
	
	int broj_elemenata, broj, ulaz(0);
	std::vector<int>v;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<broj_elemenata; i++) {
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cin>>std::ws;
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>ulaz;
	
	if (ulaz==1) {
		auto d1(MaksimalniPodnizoviStepenaDvojke(v, Rastuci));
		std::cout<<"Maksimalni rastuci podnizovi: ";
		std::cout<<std::endl;
		for (auto v : d1) {
			for (auto x : v) {
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	}
	
	else if (ulaz==2) {
		auto d2(MaksimalniPodnizoviStepenaDvojke(v, Opadajuci));
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		std::cout<<std::endl;
		for (auto v : d2) {
			for (auto x : v) {
				std::cout<<x<<" ";
			}
			std::cout<<std::endl;
		}
	}
	else {
		std::cout<<"Pogresan unos!";
		return 0;
	}
	return 0;
}