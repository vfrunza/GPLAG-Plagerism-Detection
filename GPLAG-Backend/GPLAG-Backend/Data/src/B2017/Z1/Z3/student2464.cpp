#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>


enum Smjer {Opadajuci, Rastuci};

bool StepenDvojke(int broj)
{

	if(broj<1) return false;


	while(broj!=0) {
		int cifra=broj%2;
		if(cifra==1 && broj==1) return true;
		if(cifra==1) return false;

		broj=broj/2;
	}
	return true;

}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)
{
	if(s!=0 && s!=1) throw std::range_error ("Prekoracenje parametra!");
	std::deque<std::vector<int>> dek(0);
	std::vector<int> k(0);
	int i(0);

	if(s) {

		while(i!=v.size()) {
			k.resize(0);
			int temp(0);
//Prvo pronadjemo prvi broj koji je stepen dvojke i stavljamo u pomocni vektor k
			if(StepenDvojke(v.at(i))) {
				temp=v.at(i);
				k.push_back(v.at(i));
				i++;

//Ako je naredni broj stepen dvojke i veci od prvog nadjenog prije njega stavljamo ga u pomocni vektor k
				while(i<v.size() && StepenDvojke(v.at(i)) && v.at(i)>=temp) {

					temp=v.at(i);
					k.push_back(v.at(i));
					i++;
				}
				i--;
			}
//Ako je velicina pronadjenog rastuceg podniza k veca od 1 (2 broja) dodajemo ga u dek
			if(k.size()>1) {
				dek.push_back(k);

			}

			i++;
		}
	}

//Analogno za opadajuce...
	else {

		while(i!=v.size()) {
			k.resize(0);
			int temp(0);
			if(StepenDvojke(v.at(i))) {
				temp=v.at(i);
				k.push_back(v.at(i));
				i++;

				while(i<v.size() && StepenDvojke(v.at(i)) && v.at(i)<=temp) {
					temp=v.at(i);
					k.push_back(v.at(i));
					i++;
				}
				i--;
			}

			if(k.size()>1) {
				dek.push_back(k);

			}

			i++;
		}
	}

	return dek;
}


int main ()
{
	int n,broj;
	int s;
	std::deque<std::vector<int>> dek;
	std::vector<int> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>> broj;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<broj; i++) {
		std::cin>> n;
		v.push_back(n);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>> s;

	if(s==1) {
		dek=MaksimalniPodnizoviStepenaDvojke(v, Smjer(1));
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}

	else if(s==2) {
		dek=MaksimalniPodnizoviStepenaDvojke(v, Smjer(0));
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}

	for(int i=0; i<dek.size(); i++) {
		for(int j=0; j<dek.at(i).size(); j++) {
			std::cout<<dek.at(i).at(j);
			std::cout<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}