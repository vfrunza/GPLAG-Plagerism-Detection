#include<iostream>
#include<vector>
#include<deque>
#include<cmath>
enum Smjer {Rastuci=1,Opadajuci=2};

bool StepenDvojke (int broj) {
	for(int i(0); i<broj; i++) {
		int stepen(pow(2,i));
		if(stepen==broj) return true;
		else if(stepen>pow(2,i)) break;
	}
	return false;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer s) {
	std::deque<std::vector<int>> makspodnizovi;
	std::vector<int> podniz;
	for(int i(1); i<v.size(); i++) {
		if(s==Rastuci) {
			if(v.at(i-1)<v.at(i) && StepenDvojke(v.at(i-1))) podniz.push_back(v.at(i-1));
			else if(v.at(i-1)>v.at(i) && StepenDvojke(v.at(i-1))) {
				podniz.push_back(v.at(i-1));
				if(podniz.size()>1) makspodnizovi.push_back(podniz);
				podniz.resize(0);
			}
			else{
				if(podniz.size()>1) makspodnizovi.push_back(podniz);
				podniz.resize(0);
			}
		}
		else {
			if(v.at(i-1)>v.at(i) && StepenDvojke(v.at(i-1))) podniz.push_back(v.at(i-1));
			else if(v.at(i-1)<v.at(i) && StepenDvojke(v.at(i-1))) {
				podniz.push_back(v.at(i-1));
				if(podniz.size()>1) makspodnizovi.push_back(podniz);
				podniz.resize(0);
			}
			else {
				if(podniz.size()>1) makspodnizovi.push_back(podniz);
				podniz.resize(0);
			}
		}
	}
	if(podniz.size()!=0) {
		if(StepenDvojke(v.at(v.size()-1))) podniz.push_back(v.at(v.size()-1));
		if(podniz.size()>1) makspodnizovi.push_back(podniz);
	}
	return makspodnizovi;
}
int main () {
	int vel;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>vel;
	std::vector<int> v(vel);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i<v.size(); i++) std::cin>>v.at(i);
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int smjer;
	std::cin>>smjer;
	std::deque<std::vector<int>> mpodnizovi(MaksimalniPodnizoviStepenaDvojke(v,Smjer(smjer)));
	if(smjer==1) {
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<int> podniz: mpodnizovi) {
		for(int broj: podniz) std::cout<<broj<<" ";
		std::cout<<std::endl;
	}
	return 0;
}