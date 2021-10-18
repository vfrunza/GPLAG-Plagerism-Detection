#include <iostream>
#include <vector> 
#include <deque>
#include <cmath>

enum Smjer{ Rastuci = 1, Opadajuci = 2};

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor, Smjer monotonost){
	std::deque<std::vector<int>> podnizovi;
	std::vector<int> podniz;
	if(monotonost == 1){
		for(int i = 0; i<vektor.size()-1; i++){
			podniz.resize(0);
			while(vektor.at(i)>0 && log2(vektor.at(i)) == int (log2(vektor.at(i)))){
			if(vektor.at(i) > vektor.at(i+1)){
				if(log2(vektor.at(i)) == int (log2(vektor.at(i))))
				podniz.push_back(vektor.at(i));
				if(podniz.size() == 1) goto tamo;
				podnizovi.push_back(podniz);
				tamo:
				podniz.resize(0);
				break;
			}
			podniz.push_back(vektor.at(i));
			i++;
		}
	}
}	
	
	else if(monotonost == 2){
		for(int i = 0; i<vektor.size()-1; i++){
			
			podniz.resize(0);
			while(vektor.at(i)>0 && log2(vektor.at(i)) == int (log2(vektor.at(i)))){
			if(vektor.at(i) < vektor.at(i+1)){
				if(vektor.at(i)>0 && log2(vektor.at(i)) == int (log2(vektor.at(i))))
				podniz.push_back(vektor.at(i));
				if(podniz.size() == 1) goto vamo;
				podnizovi.push_back(podniz);
				vamo:
				podniz.resize(0);
				break;
			}
			podniz.push_back(vektor.at(i));
			i++;
			if(i==vektor.size()-1){
				if(vektor.at(i)>0 && vektor.at(i)<vektor.at(i-1) && log2(vektor.at(i) == int(log2(vektor.at(i))) && log2(vektor.at(i-1)) == int(log2(vektor.at(i-1))))){
					podniz.push_back(vektor.at(i));
					break;
				}
				break;
			}
			
		}
		podnizovi.push_back(podniz);
	}
}
return podnizovi;
}
int main(){
	int brojel;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>brojel;
	int el;
	std::vector<int> vektor;
	std::cout<<"Unesite elemente vektora: ";
	for(int i = 0; i<brojel; i++){
		std::cin>>el;
		vektor.push_back(el);
	}
	int monotonost;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>monotonost;
	if(monotonost == 1) std::cout<<"Maksimalni rastuci podnizovi: ";
	else if(monotonost == 2) std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(vektor, (monotonost==1)?Smjer::Rastuci:Smjer::Opadajuci));
	std::cout << std::endl;
	for(int i = 0; i<dek.size(); i++){
		for(int j = 0; j<dek.at(i).size(); j++) std::cout<<dek.at(i).at(j)<<" ";
		std::cout<<std::endl;
	}
	return 0;
}