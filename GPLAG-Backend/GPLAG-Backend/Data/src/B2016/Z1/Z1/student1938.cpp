#include <iostream>
#include <vector>
#include <cmath>

int opak(int x);
bool vecIma(std::vector<int> v, int x);

bool javljaSe(std::vector<int> v, int x){
	for(int i = 0; i < int(v.size()); i++){
		if(v[i] == x)
			return true;
	}
	return false;
}

std::vector<int> dajTern(int x){
	//ako je primio nulu onda vracamo samo nulu
	std::vector<int> v;
	if(x == 0)
		v.push_back(0);
	while(x != 0){
		v.push_back(std::abs(x%3));
		x /= 3;
	}
	return v;
}
std::vector<int> IzdvojiGadne( std::vector<int> v, bool opaki){
	std::vector<int> ret;
	for(int i = 0; i < int(v.size()); i++){
		if(int(opaki) == opak(v[i]) && !vecIma(ret, v[i]))
			ret.push_back(v[i]);
	}
	return ret;
}
int opak(int x){
	//funkcija vraca 1 ako je broj opak, 0 ako nije, else - 1
	//u slucaju da se posalje nula, vracamo da broj ima neparan broj cifara
	
	std::vector<int> v(dajTern(x));
	std::vector<int> brojPon;
	bool gadan(1);
	int suma;
	for(int i = 0; i < 3; i++){
		suma = 0;
		if(!javljaSe(v, i))
			continue;
		for(int j = 0; j < int(v.size()); j++){
			if(v[j] == i){
				suma++;
			}
				
		}
		brojPon.push_back(suma%2);
		if(brojPon.size() > 1 && brojPon[brojPon.size()-1] != brojPon[brojPon.size() - 2])
			gadan = 0;
	}
	if(gadan)
		return !brojPon.at(0);
	return -1;
}
bool vecIma(std::vector<int> v, int x){
	for(int i = 0; i < int(v.size()); i++){
		if(v[i] == x)
			return true;
	}
	return false;
}
int main () {
	int tmp;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v,opa,odv;
	for(;;){
		std::cin>> tmp;
		if(tmp == 0)
			break;
		v.push_back(tmp);
	}
	std::cout << "Opaki: ";
	opa = IzdvojiGadne(v, true);
	odv = IzdvojiGadne(v, false);
	for(int i = 0; i < int(opa.size()); i++){
		std::cout << opa[i] << " ";
	}
	std::cout << std::endl << "Odvratni: ";
	for(int i = 0; i < int(odv.size()); i++){
		std::cout << odv[i] << " ";
	}
	return 0;
}
