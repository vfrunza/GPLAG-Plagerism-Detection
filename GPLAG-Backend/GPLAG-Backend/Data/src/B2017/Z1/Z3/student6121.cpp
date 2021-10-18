#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

enum Smjer {Rastuci=1, Opadajuci=2};

bool StepenDvojke (int n) {
	if(n<0) return false;
		for (int i=0; i<=n; i++) {
		if (n==(int)pow(2,i)) 	return true;
	}
	 return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer a) {
	
	std::deque<std::vector<int>> makspodnizovi;
	for (int i=0; i<v.size(); i++) {
		if (StepenDvojke(v.at(i))) {
		 int j=i+1;
		if (a==Rastuci) {while(j<v.size() && StepenDvojke(v.at(j))  && v.at(j)>v.at(j-1)) j++; 
			std::vector<int> pomocni(0);
			for(int k=i; k<j; k++)  pomocni.push_back(v.at(k));
				if(j-i>1)	makspodnizovi.push_back(pomocni);
			}
		else {
				while (j<v.size() && StepenDvojke(v.at(j)) &&  v.at(j)<v.at(j-1)) {
					j++;
				}
				std::vector<int> pomocni(0);
				for (int k=i; k<j; k++) pomocni.push_back(v.at(k));
				if (j-i>1)	makspodnizovi.push_back(pomocni);
			}
			i+=j-i-1;
		}
		
	}

	return makspodnizovi;
	
}


int main () {
		
		int brojel;
		std::cout<<"Unesite broj elemenata vektora: ";
		std::cin>>brojel;
//std::cin.ignore(10000, '\n');
		
		std::cout<<"Unesite elemente vektora: ";
		
		int element;
		std::vector<int>vektor(brojel);
		for (int i=0; i<brojel; i++) {
			std::cin>>element;
			vektor.push_back(element);
		}
		int opcija(0);
		std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin>>opcija;
//		std::cout<< (std::cin.peek());
		
		if (opcija == 1) {
			std::deque<std::vector<int>> vraceni = MaksimalniPodnizoviStepenaDvojke (vektor, Rastuci);
			std::cout<<"Maksimalni rastuci podnizovi: \n";

			for (int i=0; i<vraceni.size(); i++) {
				for (int j=0; j<vraceni.at(i).size(); j++) {
					std::cout<<vraceni.at(i).at(j)<<" ";
				}
				std::cout<<std::endl;
			} 	}
		
		else if (opcija == 2) {
			std::deque<std::vector<int>> vraceni2 = MaksimalniPodnizoviStepenaDvojke (vektor, Opadajuci);
			std::cout<<"Maksimalni opadajuci podnizovi: \n";
		for (int i=0; i<vraceni2.size(); i++) {
			for (int j=0; j<vraceni2.at(i).size(); j++) {
				std::cout<<vraceni2.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		} } 
	
		return 0;
}