#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

// prazan vektor
// paziti unos
// UNOS DRUGE VRIJEDNOSTI
// PRAZNA MATRICA

enum Smjer {Rastuci=1, Opadajuci=2};

bool JeLiStepenBrojaDva(int broj){
	for(int i=0; i<=(std::sqrt(broj)+10); i++){
		if(broj == pow(2,i)){
			return true;
		}
	}
	return false;
}

// RASTUCI NIZOVI
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> VEKTOR, Smjer opcija){
	std::deque<std::vector<int>> prazna_matrica(0);
	if(VEKTOR.size() == 0){
		return prazna_matrica;
	}
	std::deque<std::vector<int>> MATRICA_RASTUCIH;
	std::deque<std::vector<int>> MATRICA_OPADAJUCIH;
	if(opcija == 1){
		//Trazimo samo rastuce
		for(int i=0; i<VEKTOR.size()-1; i++){
			std::vector<int> pomocni;
			if(VEKTOR.at(i+1)>VEKTOR.at(i) && JeLiStepenBrojaDva(VEKTOR.at(i))==true && JeLiStepenBrojaDva(VEKTOR.at(i+1))==true){
				while(VEKTOR.at(i+1)>VEKTOR.at(i) && JeLiStepenBrojaDva(VEKTOR.at(i))==true && JeLiStepenBrojaDva(VEKTOR.at(i+1))==true){
					pomocni.push_back(VEKTOR.at(i));
					i++;
					if(i==VEKTOR.size()-1){
						break;
					}
				}
				pomocni.push_back(VEKTOR.at(i));
				MATRICA_RASTUCIH.push_back(pomocni);
			} else {
				continue;
			}
		}
		if(MATRICA_RASTUCIH.size() == 0){
			return prazna_matrica;
		}
		return MATRICA_RASTUCIH;
	}
	if(opcija == 2){
		// Trazimo samo opadajuce
		for(int i=0; i<VEKTOR.size()-1; i++){
			std::vector<int> pomocni;
			if(VEKTOR.at(i+1)<VEKTOR.at(i) && JeLiStepenBrojaDva(VEKTOR.at(i))==true && JeLiStepenBrojaDva(VEKTOR.at(i+1))==true){
				while(VEKTOR.at(i+1)<VEKTOR.at(i) && JeLiStepenBrojaDva(VEKTOR.at(i))==true && JeLiStepenBrojaDva(VEKTOR.at(i+1))==true){
					pomocni.push_back(VEKTOR.at(i));
					i++;
					if(i==VEKTOR.size()-1){
						break;
					}
				}
				pomocni.push_back(VEKTOR.at(i));
				MATRICA_OPADAJUCIH.push_back(pomocni);
			} else {
				continue;
			}
		}
		if(MATRICA_OPADAJUCIH.size() == 0){
			return prazna_matrica;
		}
		return MATRICA_OPADAJUCIH;
	}
}

int main (){
	//std::vector<int> vektor = {1,4,2,4,32,16,10,4,8,4,2,1,7};
	//std::vector<std::vector<int>> tmp = RastuciPodNizovi(vektor, trueg);
	int broj_elemenata;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	
	std::vector<int> vektor;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<broj_elemenata; i++){
		int tmp;
		std::cin >> tmp;
		vektor.push_back(tmp);
	}
	
	int opcija;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> opcija;
	
	Smjer izbor = Smjer(opcija);
	
	std::deque<std::vector<int>> nizovi = MaksimalniPodnizoviStepenaDvojke(vektor, izbor);
	
	if(opcija == 1){
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	} else if(opcija == 2){
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	}
	
	for(std::vector<int> tmp : nizovi){
		for(int i=0; i<tmp.size(); i++){
			std::cout << tmp.at(i) << " ";
		}
		std::cout << std::endl;
	}
	// for(std::deque<int>::iterator it = nizovi.begin(); it!=nizovi.end(); it++){
	return 0;
}