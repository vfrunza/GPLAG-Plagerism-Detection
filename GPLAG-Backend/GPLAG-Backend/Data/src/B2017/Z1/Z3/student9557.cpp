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


enum Smjer {Rastuci=1, Opadajuci};

bool StepenDvojke(int br)
{
	for(int i=1; i<=br; i*=2) {
		if(br==i) return true;
	}
	return false;
}

std::vector<int> IzdvojiStepenDvojke(std::vector<int>v)
{
	std::vector<int> v1;
	for(int i=0; i<v.size(); i++) {
		for(int j=1; j<=v.at(i); j*=2) {
			if(v.at(i)==j) v1.push_back(v.at(i));
		}
	}
	return v1;
}

std::vector<int> IzbrisiSusednePonovljene(std::vector<int> v)
{
	for(int i=0; i<v.size()-1; i++) {
		if(v.at(i)==v.at(i+1)) v.erase(v.begin()+i+1);
	}
	return v;
}

std::deque<std::vector<int>> IzdvojiRastuce(std::vector<int> v)
{
	std::vector<int> v1;
	std::deque<std::vector<int>>mat(10);
	int i(0), j(0);

	while(i<v.size()) {
		while(i<v.size()-1 && StepenDvojke(v.at(i+1))) {
			 if (i<v.size()-1 && v.at(i)<v.at(i+1)) {
				v1.push_back(v.at(i));
				v1.push_back(v.at(i+1));

				v1=IzdvojiStepenDvojke(IzbrisiSusednePonovljene(v1));
				mat.at(j).resize(v1.size());

				for(int k=0; k<v1.size(); k++) {
					mat.at(j).at(k)=v1.at(k);
				}
			} else {
				if(v1.size()==0) j--;
				v1.resize(0);
				j++;
			}
			i++;
		}
		i++;
	}
	return mat;
}

std::deque<std::vector<int>> IzdvojiOpadajuce(std::vector<int> v)
{
	std::vector<int>v1;
	std::deque<std::vector<int>>mat(v.size());
	int  i(0), j(0);
	while(i<v.size()) {
		while(i<v.size()-1 && StepenDvojke(v.at(i+1))){
		if(i<v.size()-1 && v.at(i)>v.at(i+1)) {
			v1.push_back(v.at(i));
			v1.push_back(v.at(i+1));
			v1=IzdvojiStepenDvojke(IzbrisiSusednePonovljene(v1));

			mat.at(j).resize(v1.size());
			for(int k=0; k<v1.size(); k++) {
				mat.at(j).at(k)=v1.at(k);
			}
		} else {
			if(v1.size()==0) j--;
			v1.resize(0);
			j++;
		}
		i++;
		}
		i++;
	}

	return mat;

}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)
{
	std::deque<std::vector<int>>DekVektora;
	if(s==1) {
		DekVektora=IzdvojiRastuce(v);
	} else if(s==2) {
		DekVektora=IzdvojiOpadajuce(v);
	}
	return DekVektora;
}

int main ()
{
	int br_el, element;
	int n;
	std::vector<int>vektor;
	std::deque<std::vector<int>> v1;

	std::cout<< "Unesite broj elemenata vektora: ";
	std::cin >> br_el;

	std::cout << "Unesite elemente vektora: ";
	do {
		std::cin >> element;
		vektor.push_back(element);
	} while(vektor.size()<br_el);


	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> n;

	if(n==1) {
		v1=MaksimalniPodnizoviStepenaDvojke(vektor, Rastuci);
		std::cout<< "Maksimalni rastuci podnizovi: " << std::endl;
	} else if(n==2) {
		v1=MaksimalniPodnizoviStepenaDvojke(vektor, Opadajuci);
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	}

	for(int i=0; i<v1.size(); i++) {
		for(int j=0; j<v1.at(i).size(); j++) {
			std::cout << v1.at(i).at(j) << " ";
		}
		std::cout<< std::endl;
	}
	return 0;
}