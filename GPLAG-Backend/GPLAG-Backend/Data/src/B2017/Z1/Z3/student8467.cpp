/*B 2017/2018, Zadaća 1, Zadatak 4
	SLUČAJNO SAM ZADATAK POČEO RADITI U ZADATKU 4, PREKOPIRAO SAM GA U ZADATAK 3, AKO DOBIJEM STRIKE DA SAM PREPISAO BITI ĆU JAKO UZNEMIREN...
*/
#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci, Opadajuci};

bool DaLiJeStepenDvojke(int broj){
	return (broj >= 1 && !(broj&(broj-1)));
}

bool nejednakost(int a, int b, bool manje){
	if(a < b){
		if(manje)return true;
		else return false;
	}else if(a > b){
		if(manje) return false;
		else return true;
	}else if(a == b) return true;
	return false;
}

std::vector<int> Podniz(std::vector<int> v, int *i, bool smjer){
	
	std::vector<int> vektor; //true-rastući false - opadajuci
	vektor.push_back(v.at(*i));
	
	while(*i < v.size()){
		if(*i < v.size() - 1 && nejednakost(v.at(*i),v.at(*i + 1),smjer) && DaLiJeStepenDvojke(v.at(*i + 1))){
			vektor.push_back(v.at(*i + 1));
		/*}else if(i == v.size() - 1 && vektor.size() > 1 && DaLiJeStepenDvojke(v.at(i)) && nejednakost(v.at(i-1),v.at(i),smjer)){
			vektor.push_back(v.at(i));
			return vektor;*/
		}else if(vektor.size() > 1){
			return vektor;
		}else{
			return std::vector<int>(0);
		}
		(*i)++;
	}
	return vektor;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s){
	std::deque<std::vector<int>> dek;
	bool smjer(true);
	if(s == Opadajuci) smjer = false;
	int i = 0;
	while(i < v.size()){
		if(DaLiJeStepenDvojke(v.at(i))){
			std::vector<int> za_ubacit(Podniz(v,&i,smjer));
			if(za_ubacit.size() > 1) dek.push_back(za_ubacit);
			if(i >= v.size() - 1){
				return dek;	
				break;
			}
		}
		i++;
	}
	return dek;
}

int main ()
{
	int broj_elemenata;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	std::vector<int> v;
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < broj_elemenata; i++){
		int broj;
		std::cin >> broj;
		v.push_back(broj);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int izbor;
	std::cin >> izbor;
	
	
	std::deque<std::vector<int>> dek;
	dek = MaksimalniPodnizoviStepenaDvojke(v,Smjer(izbor - 1));
	
	if(izbor == 1){
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl; 
	}else if(izbor == 2){
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	}else{
		std::cout << "Greska u izboru!";
		return 0;
	}

	for(std::vector<int> a : dek){
		for(int b : a){
			std::cout << b << " "; 
		}
		std::cout << std::endl;
	}
	return 0;
}