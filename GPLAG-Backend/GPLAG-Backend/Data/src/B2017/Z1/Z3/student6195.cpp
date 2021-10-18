/*B 2017/2018, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/ // ne moze - i 0 biti stepen dvojke
//d<v<int>> ();
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke (long long int n)
{
	if(n <= 0) return false;
	int brojac(0);
	long long int broj = n;
	while (n != 0) {
		n /= 2;
		brojac++;
	}
	brojac--;
	if(broj == std::pow(2, brojac)) return true;
	else return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer s)
{
	std::vector<int> pomocni;
	std::deque<std::vector<int>> dek;
	if(v.size()==0) return std::deque<std::vector<int>>();
	if(s == Smjer::Rastuci) {
		for(int j(0); j < v.size(); j++) { //idemo kroz vektor i uzimamo svaki clan pojedinacno
			if(j == v.size()-1) break;
			if(v.at(j) <= v.at(j+1) && StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1)) && pomocni.size() == 0)
				pomocni.push_back(v.at(j)); 	//ako zadovoljava if, smjesti taj clan, ali ovo je samo za prvi clan
			if(v.at(j) <= v.at(j+1) && StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1)))
				pomocni.push_back(v.at(j+1));
		    else if(v.at(j) >= v.at(j+1) || !StepenDvojke(v.at(j)) || !StepenDvojke(v.at(j+1))) {
				dek.push_back(pomocni);
				pomocni.resize(0);
			}
		}
		dek.push_back(pomocni);
		if(dek.size()==0) return std::deque<std::vector<int>>();
		
	} if(s == Smjer::Opadajuci) {
		for(int j(0); j < v.size(); j++) {
			if(j == v.size()-1) break;
			if(v.at(j) >= v.at(j+1) && StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1)) && pomocni.size() == 0)
				pomocni.push_back(v.at(j));
			if(v.at(j) >= v.at(j+1) && StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1)))
				pomocni.push_back(v.at(j+1));
			else if (v.at(j) <= v.at(j+1) || !StepenDvojke(v.at(j)) || !StepenDvojke(v.at(j+1))) {
				dek.push_back(pomocni);
				pomocni.resize(0);
			}
		}
		dek.push_back(pomocni);
		if(dek.size()==0) return std::deque<std::vector<int>>();
	}
	return dek;
}
int main ()
{
	int broj_elemenata;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	std::vector<int> v(broj_elemenata);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i < v.size(); i++)
		std::cin>>v.at(i);
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int izborni;
	std::cin>>izborni;
	if(izborni == 1) {
	std::deque<std::vector<int>> dek = (MaksimalniPodnizoviStepenaDvojke(v, Rastuci));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i(0); i < dek.size(); i++) {
		for(int j(0); j < (dek.at(i)).size(); j++)
			std::cout<<dek.at(i).at(j)<<" ";
			if((dek.at(i)).size())
			std::cout<<std::endl;
		}
	}
	if(izborni == 2) {
	std::deque<std::vector<int>> dek = (MaksimalniPodnizoviStepenaDvojke(v, Opadajuci));
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;;
	for(int i(0); i < dek.size(); i++) {
		for(int j(0); j < (dek.at(i)).size(); j++) 
			std::cout<<dek.at(i).at(j)<<" ";
			if((dek.at(i)).size())
			std::cout<<std::endl;
		}
	}
		return 0;
}