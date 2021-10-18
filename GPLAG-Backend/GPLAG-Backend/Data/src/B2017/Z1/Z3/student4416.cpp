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

enum Smjer {Rastuci, Opadajuci};

typedef std::deque<std::vector<int>> NizVektora;

bool StepenDvojke(int broj)
{
	if(broj<=0) return false;
	while(broj!=1) {
		if(broj%2!=0) return false;
		broj/=2;
	}
	return true;
}

Smjer RastuciPoredak(int prvi, int drugi)
{
	if(prvi>drugi) return Opadajuci;
	return Rastuci;
}

NizVektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> ulazni, Smjer monotonost)
{
	NizVektora izlazna;
	int i;
	std::vector<int> podniz;
	for(i=0; i<ulazni.size(); i++) {
		int element=ulazni.at(i);
		if(StepenDvojke(element)) {
			if(podniz.size()==0) podniz.push_back(element);
			else {
				if(podniz.at(podniz.size()-1)==element || RastuciPoredak(podniz.at(podniz.size()-1), element)==monotonost) {
					podniz.push_back(element);
				} else {
					if(podniz.size()>=2) izlazna.push_back(podniz);
					podniz=std::vector<int> (1, element);
				}
			}
		} else {
			if(podniz.size()>=2) izlazna.push_back(podniz);
			podniz.resize(0);
		}
	}
	if(i==ulazni.size() && podniz.size()>=2) izlazna.push_back(podniz);
	return izlazna;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int duzina_vektora;
	while(!(std::cin >> duzina_vektora), duzina_vektora<0);
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> pocetni(duzina_vektora);
	for(int i(0); i<duzina_vektora; i++) {
		std::cin >>pocetni.at(i);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int n;
	Smjer smjer;
	while(!(std::cin >> n), !(n==1 || n==2));
	if(n==1) {
		std::cout << "Maksimalni rastuci podnizovi: \n";
		smjer=Rastuci;
	} else {
		std::cout << "Maksimalni opadajuci podnizovi: \n";
		smjer=Opadajuci;
	}
	NizVektora podnizovi(MaksimalniPodnizoviStepenaDvojke(pocetni, smjer));
	for(std::vector<int> i: podnizovi) {
		for(int j: i) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}