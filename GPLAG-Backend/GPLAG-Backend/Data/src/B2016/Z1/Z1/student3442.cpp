#include <iostream>
#include <vector> 
#include <cmath>

std::vector<int> ternarni(int n) {
	std::vector<int> t_vektor;
	if(n == 0) t_vektor.push_back(0);
	int n_temp;
	while(n != 0) {
		n_temp = n; 
		n /= 3;
		t_vektor.push_back(n_temp - n * 3);
	}
	
	for(auto &x : t_vektor) {
		if(x < 0) x *= -1;
	}
	return t_vektor;
}

bool DaLiJeOpaki(std::vector<int> v) {
	int nula = 0, jedan = 0, dva = 0; 
	
	for(int x : v) {
		if(x == 0) nula++;
		else if(x == 1) jedan++;
		else if(x == 2) dva++;
	}
	
	if(nula % 2 == 0 && jedan % 2 == 0 && dva % 2 == 0) return true;
	return false;
}

bool DaLiJeOdvratni(std::vector<int> v) {
	int nula = 0, jedan = 0, dva = 0; 
	
	for(int x : v) {
		if(x == 0) nula++;
		else if(x == 1) jedan++;
		else if(x == 2) dva++;
	}
	
	if(nula == 0) nula = 1;
	if(jedan == 0) jedan = 1;
	if(dva == 0) dva = 1;
	 
	if(nula % 2 != 0 && jedan % 2 != 0 && dva % 2 !=0) return true;
	return false;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opaki) {
	std::vector<int> novi_vektor;
	
	for(int x : v) {
		if(DaLiJeOpaki(ternarni(x)) && opaki) {
			novi_vektor.push_back(x);
		}
		else if(DaLiJeOdvratni(ternarni(x)) && opaki == false) {
			novi_vektor.push_back(x);
		}
	}
	// izbacivanje duplikata...
	for(int i = 0; i < novi_vektor.size(); i++) {
		for(int j = i+1; j < novi_vektor.size(); j++) {
			if(novi_vektor[i] == novi_vektor[j]) {
				novi_vektor.erase(novi_vektor.begin() + j);
				j--;
			}
		}
	}
	return novi_vektor;
}

int main()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int n;
	do {
		std::cin >> n; 

		if(n!=0) v.push_back(n);
	}while(n!=0);
	
	std::cout << "Opaki: ";
	for(auto x : IzdvojiGadne(v, true)) std::cout << x << " ";
	std::cout << "\nOdvratni: ";
	for(auto x : IzdvojiGadne(v, false)) std::cout << x << " ";
	
	return 0;
}