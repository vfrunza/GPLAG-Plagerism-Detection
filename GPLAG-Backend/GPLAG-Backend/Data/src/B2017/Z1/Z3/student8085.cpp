#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

enum Smjer {Rastuci, Opadajuci};

bool jeLiStepenBrojaDva(int broj) {
	int stepenDvojke = 1;
	while (stepenDvojke < broj) {
		stepenDvojke *= 2;
	}
	
	return broj == stepenDvojke;
}

std::vector<int> dajPodniz(std::vector<int> niz, int donjaGranica, int gornjaGranica) {
	std::vector<int> podniz;
	while(donjaGranica < gornjaGranica) {
		podniz.push_back(niz.at(donjaGranica++));
	}
	return podniz;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s){
	std::deque<std::vector<int>> dek;
	int donjaGranica = 0; 
	int gornjaGranica = 1;
	while(donjaGranica < v.size() && gornjaGranica < v.size()) {
		if(jeLiStepenBrojaDva(v.at(gornjaGranica)) && jeLiStepenBrojaDva(v.at(gornjaGranica - 1))) {
			if((s == (v.at(gornjaGranica) < (v.at(gornjaGranica - 1)))) || (v.at(gornjaGranica) == v.at(gornjaGranica - 1))) {
				gornjaGranica++;
			} else {
				if(gornjaGranica - donjaGranica > 1) {
					dek.push_back(dajPodniz(v,donjaGranica,gornjaGranica));	
				}
				donjaGranica = gornjaGranica;
				gornjaGranica += 1;
			}
		} else {
			if(gornjaGranica - donjaGranica > 1) {
				dek.push_back(dajPodniz(v,donjaGranica,gornjaGranica));	
			}
			donjaGranica = gornjaGranica ;
			gornjaGranica += 1;
		}
	}
	
	if(gornjaGranica - donjaGranica > 1) {
		dek.push_back(dajPodniz(v,donjaGranica,gornjaGranica));	
	}
	
	return dek;
}

int main ()
{
	std::vector<int> v;
	int vel,x;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>vel;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<vel; i++){
		std::cin>>x;
		v.push_back(x);
	}
	int n;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>n;
	
	if(n==1){
		Smjer prvi(Rastuci);
		std::deque<std::vector<int>>dek;
		dek=MaksimalniPodnizoviStepenaDvojke(v,prvi);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(int i=0; i<dek.size(); i++){
			for(int j=0; j<dek.at(i).size(); j++){
				std::cout<<dek.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	} else {
		Smjer prvi(Opadajuci);
		std::deque<std::vector<int>>dek;
		dek=MaksimalniPodnizoviStepenaDvojke(v,prvi);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=0; i<dek.size(); i++){
			for(int j=0; j<dek.at(i).size(); j++){
				std::cout<<dek.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	
	return 0;
}