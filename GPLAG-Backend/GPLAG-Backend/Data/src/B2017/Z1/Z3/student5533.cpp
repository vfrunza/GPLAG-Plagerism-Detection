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

bool JeLiStepenDvojke (int n)
{
	for (int i=0; i<n; i++) {
		if ((pow(2,i))==n) return true;
	}
	return false;
}
enum Smjer {Rastuci, Opadajuci};

std::deque <std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer s) {
	std::deque <std::vector<int>> d;
	std::vector<int> v1, v2;
	int brojac(0);
	for (int i=0; i<v.size()-1; i++) {
		brojac=0;
		v1=v2;
		if (s==Rastuci) {
			if ((v.at(i)<=v.at(i+1)) && (JeLiStepenDvojke(v.at(i)))) {
				while (((v.at(i+1))>=v.at(i)) && (JeLiStepenDvojke(v.at(i)))) {
					v1.push_back(v.at(i)); 
					brojac++;
					i++;
					if (i==v.size()-1 && (!(JeLiStepenDvojke(v.at(i))))) break;
					if ((i==(v.size()-1)) && (v.at(i)>=v.at(i-1)) && (JeLiStepenDvojke(v.at(i)))) {
						v1.push_back(v.at(i)); 
						brojac++; break;
					}
					else if ((v.at(i)>=v.at(i-1)) && (v.at(i)>=v.at(i+1)) && (JeLiStepenDvojke(v.at(i)))) { 
						v1.push_back(v.at(i));
						brojac++;
				    }
				}
				if (brojac>=2)
				   d.push_back (v1);
			}
		}
		else if (s==Opadajuci) {
			if ((v.at(i)>=v.at(i+1)) && (JeLiStepenDvojke(v.at(i)))) {
				while (((v.at(i))>=v.at(i+1)) && (JeLiStepenDvojke(v.at(i)))) {
					v1.push_back(v.at(i));
					i++;
					brojac++;
					if (i==v.size()-1 && (!(JeLiStepenDvojke(v.at(i))))) break;
					if ((i==v.size()-1) && (v.at(i)<=v.at(i-1)) && (JeLiStepenDvojke(v.at(i)))) {
						v1.push_back(v.at(i));
						brojac++;
						break;
					}
					
					else if ((v.at(i)<=v.at(i-1)) && (v.at(i)<=v.at(i+1)) && (JeLiStepenDvojke(v.at(i)))) {
						v1.push_back(v.at(i));
						brojac++;
					}
				}
				if (brojac>=2) {
					d.push_back(v1);
				}
			}
		}
	}
	return d;
} 

int main ()
{
	int broj, k;
	std::deque <std::vector<int>> d;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj;
	std::vector<int> v(broj);
	std::cout<<"Unesite elemente vektora: ";
	std::cin.clear();
	
	//std::cin.ignore(10000, '\n');
	for (int i=0; i<v.size(); i++) {
		std::cin>>v.at(i);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	do {
		std::cin >>k;
	} while (k!=1 && k!=2);
	Smjer s;
	if (k==1)
		s=Rastuci;
	else if (k==2)
		s=Opadajuci;
	d=MaksimalniPodnizoviStepenaDvojke(v,s);
	if (s==Rastuci) {
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for (int i=0; i<d.size(); i++) {
			for (int j=0; j<d.at(i).size(); j++) {
				std::cout<< d.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
			
		}
	} 
	else if (s==Opadajuci) {
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for (int i=0; i<d.size(); i++) {
			for (int j=0; j<d.at(i).size(); j++) {
				std::cout<<  d.at(i).at(j) <<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}