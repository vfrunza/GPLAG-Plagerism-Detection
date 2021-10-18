#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke(int broj) {
	if (broj==0) return false;
	if (broj%2!=0 && broj!=1) return false;
	if (broj==1) return true;
	broj/=2;
	if (StepenDvojke(broj)==false) return false;
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s) {
	std::deque<std::vector<int>> dek;
	if (v.size()==0) return dek;
	std::vector<int> pomocni;
	if (s==Rastuci) {
		if (StepenDvojke(v.at(0))) pomocni.push_back(v.at(0));
		for (int i=1; i<v.size(); i++) {
			if (i==v.size()-1) {
				if (StepenDvojke(v.at(i)) && v.at(i)>=v.at(i-1)) pomocni.push_back(v.at(i));
				if (pomocni.size()>=2) dek.push_back(pomocni);
			}
			else {
				if (StepenDvojke(v.at(i)) && v.at(i)>=v.at(i-1)) pomocni.push_back(v.at(i));
				else if (StepenDvojke(v.at(i))) {
					if (pomocni.size()>=2) dek.push_back(pomocni);
					pomocni.clear();
					pomocni.push_back(v.at(i));
				}
				else {
					if (pomocni.size()>=2) dek.push_back(pomocni);
					pomocni.clear();
				}
			}
		}
	}
	else if (s==Opadajuci) {
		if (StepenDvojke(v.at(0))) pomocni.push_back(v.at(0));
		for (int i=1; i<v.size(); i++) {
			if (i==v.size()-1) {
				if (StepenDvojke(v.at(i)) && v.at(i)<=v.at(i-1)) pomocni.push_back(v.at(i));
				if (pomocni.size()>=2) dek.push_back(pomocni);
			}
			else {
				if (StepenDvojke(v.at(i)) && v.at(i)<=v.at(i-1)) pomocni.push_back(v.at(i));
				else if (StepenDvojke(v.at(i))) {
					if (pomocni.size()>=2) dek.push_back(pomocni);
					pomocni.clear();
					pomocni.push_back(v.at(i));
				}
				else {
					if (pomocni.size()>=2) dek.push_back(pomocni);
					pomocni.clear();
				}
			}
		}
	}
	return dek;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	int broj;
	std::vector<int> vektor;
	
	for (int i=0; i<n; i++) {
		std::cin >> broj;
		vektor.push_back(broj);
	}
	int opcija;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> opcija;

	std::deque<std::vector<int>> dek;
	if (opcija==1) {
		dek=MaksimalniPodnizoviStepenaDvojke(vektor, Rastuci);
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for (std::vector<int> v : dek) {
			for (int clan : v) {
				std::cout << clan << " ";
			}
			std::cout << std::endl;
		}
	}
	else if (opcija==2) {
		dek=MaksimalniPodnizoviStepenaDvojke(vektor, Opadajuci);
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for (std::vector<int> v : dek) {
			for (int clan : v) {
				std::cout << clan << " ";
			}
			std::cout << std::endl;
		}
	}
	
	return 0;
}