/*B 2017/2018, Zadaća 1, Zadatak 3*/

#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci=1, Opadajuci=2};

bool DaLiJeStepenDvojke (int a) {
	if (a<=0) return false;
	while (a!=1) {
		if (a%2!=0) return false;
		a/=2;
	}
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer x) {
	std::deque<std::vector<int>> zavrsni;
	std::vector<int> vektori;
	if (!v.size() ) return zavrsni;
	int brojac(0);

	
	for (int i=0 ; i<v.size(); i++) {
		if (DaLiJeStepenDvojke(v.at(i))==true) {
			if (i!=(v.size()-1)) {
				if (brojac==0) {
					if (DaLiJeStepenDvojke(v.at(i+1))==true && ( (x==Rastuci && v.at(i)<=v.at(i+1)) || (x==Opadajuci && v.at(i)>=v.at(i+1)) ) ) {
						vektori.push_back(v.at(i));
						brojac++;
					}
					else {
						brojac=0;
						vektori.clear();
					}
				}
				else {
					if ( ( x==Rastuci && v.at(i)>=vektori.at(vektori.size()-1)) || (x==Opadajuci && v.at(i)<=vektori.at(vektori.size()-1)) ) {
						vektori.push_back(v.at(i));
						brojac++;
					}
					else {
						if (brojac>=2)
							zavrsni.push_back(vektori);
						brojac=0;
						vektori.clear();
						if (DaLiJeStepenDvojke(v.at(i+1))==true && ((x==Rastuci && v.at(i)<=v.at(i+1)) || (x==Opadajuci && v.at(i)>=v.at(i+1)))) {
							vektori.push_back(v.at(i));
							brojac++;
						}
						else {
							brojac=0;
							vektori.clear();
						}
					}
				}
			}
			else {
				if (brojac>=1 && ( (x==Rastuci && v.at(i)>=vektori.at(vektori.size()-1)) || (x==Opadajuci && v.at(i)<=vektori.at(vektori.size()-1)) ) ) {
					vektori.push_back(v.at(i));
					zavrsni.push_back(vektori);
				}
				else {
					if (brojac>=2) 
						zavrsni.push_back(vektori);
					brojac=0;
					vektori.clear();
				}
			}
		}
		else {
			if (brojac>=2)
				zavrsni.push_back(vektori);
			brojac=0;
			vektori.clear();
		}
	}
	
	return zavrsni;
}



int main ()
{
	int br_el;
	int br;
	std::vector<int> v;
	std::deque<std::vector<int>> rez;
	int br_smjer;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>br_el;
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<br_el; i++) {
		std::cin>>br;
		v.push_back(br);
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>br_smjer;
	
	if (br_smjer==1) rez=MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
	else rez=MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
	
	std::cout<<"Maksimalni ";
	if (br_smjer==1) std::cout<<"rastuci podnizovi: "<<std::endl;
	else std::cout<<"opadajuci podnizovi: "<<std::endl;
	
	for (int i=0; i<rez.size(); i++) {
		for (int j=0; j<rez.at(i).size(); j++)
			std::cout<<rez.at(i).at(j)<<" ";
		std::cout<<std::endl;
	}
	return 0;
}