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
enum Smjer {Rastuci = 1, Opadajuci = 2};

bool StepenDvojke(int broj)
{
	if(broj < 1) return false;

	int stepen(1);
	while(stepen < broj) {
		stepen *=2;
	}
	if(stepen == broj) return true;
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>v, Smjer izbor)
{
	std::vector<int>brojevi;
	std::deque<std::vector<int>> dek, finalni_dek;

	//pravimo podnizove uzastopnih stepena dvojke
	for (int i=0; i < v.size(); i++) {
		if(StepenDvojke(v.at(i))) {
			brojevi.push_back(v.at(i));
		} else if(brojevi.size() >=0) {
			dek.push_back(brojevi);
			brojevi.resize(0);
		}
	}
	if(brojevi.size() >=0) {
		dek.push_back(brojevi);
		brojevi.resize(0);
	}

	std::vector<int>ubaci;	

	if(Rastuci == izbor){
		for(auto x: dek) {
			for(int i=0; i<x.size(); i++){
				if (i<x.size()-1 && x.at(i) <= x.at(i+1))
					ubaci.push_back(x.at(i));
					
				else {
					if(ubaci.size()>0){
						ubaci.push_back(x.at(i));
						finalni_dek.push_back(ubaci);
					}
					ubaci.resize(0);
				}			
				
			}
			
		}
	
	}
	if (Opadajuci == izbor){
		for(auto x: dek) {
			for(int i=0; i<x.size(); i++){
				if (i<x.size()-1 && x.at(i) >= x.at(i+1))
					ubaci.push_back(x.at(i));
					
				else {
					if(ubaci.size()>0){
						ubaci.push_back(x.at(i));
						finalni_dek.push_back(ubaci);
					}
					ubaci.resize(0);
				}			
				
			}
			
		}
	}

	return finalni_dek;
}



int main ()
{
	int izbor_korisnika;
	int n, broj;
	std::vector<int>v;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;

	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >>broj;
		v.push_back(broj);
	}

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> izbor_korisnika;

	std::deque<std::vector<int>>dek;

	if(izbor_korisnika == 1) {
		dek = MaksimalniPodnizoviStepenaDvojke(v,Smjer(izbor_korisnika));
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(auto x: dek) {
			for(int i=0; i<x.size(); i++)
				std::cout << x.at(i) << " ";
			std::cout << std::endl;
		}
	}

	if(izbor_korisnika == 2) {
		dek = MaksimalniPodnizoviStepenaDvojke(v,Smjer(izbor_korisnika));
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(auto x: dek) {
			for(int i=0; i<x.size(); i++)
				std::cout << x.at(i) << " ";
			std::cout << std::endl;
		}
	}

	return 0;
}