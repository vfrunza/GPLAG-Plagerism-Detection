#include <iostream>
#include <vector>

bool DaLiJeTerarniSimetrican(int a){
	int br_cifara (0);
	int pom;
	if(a < 0) pom = a * -1;
	else pom = a;
	while(pom > 0){
		br_cifara++;
		pom /= 3;
	}
	std::vector<int> terarni(br_cifara);
	if(a < 0) pom = a * -1;
	else pom = a;
	while(pom > 0){
		terarni[--br_cifara] = pom % 3;
		pom /= 3;
	}
	for(int i = 0; i < terarni.size() / 2; i++){
		if(terarni.at(i) != terarni.at(terarni.size() - i - 1)) return false;
	}
	return true;
}

bool DaLiJeProst(int a){
	if(a < 0) a *= -1;
	if(a < 2) return false;
	for(int i = 2; i < a; i++){
		if(a % i == 0) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor, bool istina){
	std::vector<int> rezultat;
	for(auto x : vektor){
		bool ima(false);
		if(DaLiJeTerarniSimetrican(x) && istina == DaLiJeProst(x)){
			for(int i = 0; i < rezultat.size(); i++){
				if(x == rezultat.at(i)) ima = true;
			}
			if(!ima) rezultat.push_back(x);
		}
	}
	return rezultat;
	
}

int main ()
{
	int x;
	std::vector<int> niz;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	while(true){
		std::cin >> x;
		if(x == - 1) break;
		else niz.push_back(x);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(true){
		std::cin >> x;
		if(x != 1 && x != 0){
			std::cout << "Neispravan unos! Unesite ponovo: ";
		}
		else break;
	}
	bool uslov(x);
	std::vector<int> novi = IzdvojiSimetricneTernarne(niz,uslov);
	if(uslov && novi.size() != 0){
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i = 0; i < novi.size(); i++){
			if(i != novi.size() - 1) std::cout << novi.at(i) << ", ";
			else std::cout << novi.at(i) << ".";
		}
	}
	else if(!uslov && novi.size() != 0) {
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i = 0; i < novi.size(); i++){
			if(i != novi.size() - 1) std::cout << novi.at(i) << ", ";
			else std::cout << novi.at(i) << ".";
		}
	}
	else if(uslov && novi.size() == 0)
		std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else{
		std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}