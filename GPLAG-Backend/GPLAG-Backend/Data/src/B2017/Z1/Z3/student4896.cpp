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

typedef std::vector<int> Vektor;

enum Smjer {Rastuci=1, Opadajuci=2};

bool StepenDvojke(int n)
{
	bool a(true);
	if(n<=0) return false;
	int k(n);
	while(k!=1) {
		if(k%2==0) {
			k/=2;
			if(k==1) return a;
		} else {
			return false;
		}
	}
	return a;
}

std::deque<Vektor> MaksimalniPodnizoviStepenaDvojke(Vektor V, Smjer S)
{
	Vektor rastuci, opadajuci;
	std::deque<Vektor> povratni;
	if(S==Rastuci) {
		for(int i=0; i<V.size()-1; i++) {
			rastuci.resize(0);
			if(StepenDvojke(V.at(i))) {
				rastuci.push_back(V.at(i));
				if(V.at(i)<=V.at(i+1) && StepenDvojke(V.at(i+1))==true) {
					while(V.at(i)<=V.at(i+1) && StepenDvojke(V.at(i+1))==true) {
						rastuci.push_back(V.at(i+1));
						i++;
						if(i==V.size()-1) break;
					}
				}
			}
			if(rastuci.size()>1) {
				povratni.push_back(rastuci);
			}
		}
	} else {
		for(int i=0; i<V.size()-1; i++){
			opadajuci.resize(0);
			if(StepenDvojke(V.at(i))) {
				opadajuci.push_back(V.at(i));
				if(V.at(i)>=V.at(i+1) && StepenDvojke(V.at(i+1))==true) {
					while(V.at(i)>=V.at(i+1) && StepenDvojke(V.at(i+1))==true) {
						opadajuci.push_back(V.at(i+1));
						i++;
						if(i==V.size()-1) break;
					}
				}
			}
			if(opadajuci.size()>1){
				povratni.push_back(opadajuci);
			}
		}
	}
	return povratni;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	int k;
	Vektor v;
	for(int i=0; i<n; i++) {
		std::cin >> k;
		v.push_back(k);
	}
	int m;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> m;
	if(m==1) {
		std::deque<Vektor> novi(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(int i=0; i<novi.size(); i++) {
			for(int j=0; j<novi.at(i).size(); j++) {
				std::cout << novi.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	} else {
		std::deque<Vektor> novi(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(int i=0; i<novi.size(); i++){
			for(int j=0; j<novi.at(i).size(); j++){
				std::cout << novi.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}