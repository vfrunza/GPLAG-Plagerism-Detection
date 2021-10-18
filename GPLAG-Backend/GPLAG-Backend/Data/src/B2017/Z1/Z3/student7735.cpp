#include <iostream>
#include <vector>
#include <deque>

enum Smjer{Opadajuci, Rastuci};

bool DaLiJeStepenDvojke(int a){
	if(a <= 0) return false;
	while(a > 1){
		if(a % 2 != 0) return false;
		a /= 2;
	}
	return true;
}

bool DaLiJeSadrzan(std::vector<int> v1, std::vector<int> v2){
	if(v1.size() <= v2.size()){
		for(int i = 0; i < v1.size(); i++){
			if(v1.at(i) != v2.at(i)) return false;
		}
		return true;
	}
	else{
		for(int i = 0; i < v2.size(); i++){
			if(v1.at(i) != v2.at(i)) return false;
		}
		return true;
	}
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, enum Smjer smjer){
	std::deque<std::vector<int>> rezultat;
	std::vector<int> podniz;
	if(smjer == Rastuci){
		for(int i = 0; i <= v.size() - 1; i++){
			if((v.size() - 1) == i && i != 0){
				if((DaLiJeStepenDvojke(v.at(i))) && v.at(i) >= v.at(i-1)) podniz.push_back(v.at(i));
				if(podniz.size() >= 2) rezultat.push_back(podniz);
				podniz.resize(0);
			}
			else if(i != v.size() - 1){
				if(v.at(i) <= v.at(i + 1) && DaLiJeStepenDvojke(v.at(i))){
					podniz.push_back(v.at(i));
				}
				else{
					if((DaLiJeStepenDvojke(v.at(i)))) podniz.push_back(v.at(i));
					if(podniz.size() >= 2) rezultat.push_back(podniz);
					podniz.resize(0);
				}
			}
		}
	}
	else{
		for(int i = 0; i <= v.size() - 1; i++){
			if(v.size() - 1 == i && i != 0){
				if((DaLiJeStepenDvojke(v.at(i))) && v.at(i) <= v.at(i-1)) podniz.push_back(v.at(i));
				if(podniz.size() >= 2) rezultat.push_back(podniz);
				podniz.resize(0);
			}
			else if(i != v.size() - 1){
				if(v.at(i) >= v.at(i + 1) && DaLiJeStepenDvojke(v.at(i))){
					podniz.push_back(v.at(i));
				}
				else{
					if((DaLiJeStepenDvojke(v.at(i)))) podniz.push_back(v.at(i));
					if(podniz.size() >= 2) rezultat.push_back(podniz);
					podniz.resize(0);
				}
			}
		}
	}
	for(int i = 0; i < rezultat.size(); i++){
	for(int j = 0; j < rezultat.size(); j++){
			if(DaLiJeSadrzan(rezultat.at(i),rezultat.at(j)) && i != j) rezultat.erase(rezultat.begin()+i);
	}
	}
	return rezultat;
}

int main ()
{
	std::vector<int> niz;
	int velicina,x,izbor;
	enum Smjer smjer;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> velicina;
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < velicina; i++) {
		std::cin >> x;
		niz.push_back(x);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> izbor;
	if(izbor == 1) smjer = Rastuci;
	else smjer = Opadajuci;
	std::deque<std::vector<int>> novi = MaksimalniPodnizoviStepenaDvojke(niz,smjer);
	if(izbor == 1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i = 0; i < novi.size(); i++){
		for(auto x : novi.at(i)) std::cout << x << " ";
		std::cout << std::endl;
	}
	return 0;
}


//1 1 1,37.linija,56.linija