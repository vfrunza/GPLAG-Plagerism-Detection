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
#include <cmath>

enum Smjer {Rastuci = 1, Opadajuci};

bool DaLiJeStepenDvojke(int x){
	if(x == 0) return false;
	if(x == 1) return true;
	while(x != 2){
		if(x % 2 != 0) return false;
		x /= 2;
	}
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer ){
	std::deque<std::vector<int>> d;

	if(smjer == Rastuci){
		for(int i(0); i < v.size(); i++){
	
			if(DaLiJeStepenDvojke(v.at(i))){
				std::vector<int> vekt;
				for(int j(i+1); j < v.size(); j++){
			
					if(DaLiJeStepenDvojke(v.at(j))){
						if(v.at(j-1) < v.at(j)){
							vekt.push_back(v.at(j-1));
							if(j == v.size()-1) vekt.push_back(v.at(j));
							i = j;
						}
						else{
							vekt.push_back(v.at(j-1));
							i = j-1;
							break;
						}
					}
					else{
						vekt.push_back(v.at(j-1));
						i = j-1;
						break;
					}
					i = j-1;
			
			}
			if(vekt.size() > 1) d.push_back(vekt);
			}
		}
	}
	else if(smjer == Opadajuci){
		for(int i(0); i < v.size(); i++){
	
			if(DaLiJeStepenDvojke(v.at(i))){
				std::vector<int> vekt;
				for(int j(i+1); j < v.size(); j++){
			
					if(DaLiJeStepenDvojke(v.at(j))){
				
						if(v.at(j-1) > v.at(j)){
							vekt.push_back(v.at(j-1));
							if(j == v.size()-1){ vekt.push_back(v.at(j));
								i = j;
							}
						}
						else{
							vekt.push_back(v.at(j-1));
							i = j-1;
							break;
						}
					}
					else{
						vekt.push_back(v.at(j-1));
						i = j-1;
						break;
					}
				
					i = j-1;
				}
			if(vekt.size() > 1) d.push_back(vekt);
		}
	
		}
	}
	return d;
}
int main ()
{
	int BrElemenata;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin >>BrElemenata;
	std::vector<int> v;
	int element;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i < BrElemenata; i++){
		std::cin >> element;
		v.push_back(element);
	}
	
	Smjer smjer;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	std::cin >> a;
	smjer = Smjer(a);
	
	std::deque<std::vector<int>> dek(MaksimalniPodnizoviStepenaDvojke(v,smjer));
	
	if(smjer == Rastuci){
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else if(smjer == Opadajuci)
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i(0); i < dek.size(); i++){
		for(int j(0); j < dek.at(i).size(); j++){
			std::cout<<dek.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}