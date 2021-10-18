#include <iostream>
#include <vector>
#include <cmath>

bool parna (int n) {

	if (n % 2 == 0)
		return true;
	return false;
}

 std::vector<long int> baza_tri (int n) {
	std::vector<long int> vektor;
	long int pomocni (1);
	do {
		long double ostatak = fabs (n % 3);
		n /= 3;
		vektor.push_back(ostatak);
		pomocni = pomocni * 10;
	} while (n != 0);
	
	return vektor;
}

int parnost (int n) {
	
	std::vector<long int> v (baza_tri(n));
	std::vector<long int> pomocni (3);
	for (int i=0; i<v.size(); i++) {
		long int a (v[i]);
		if (a == 0)
			pomocni[0]++;
		else if (a == 1)
			pomocni[1]++;
		else if (a == 2)
			pomocni[2]++;
	}
	std::vector<long int> bez_nula;
	for (int i=0; i<pomocni.size(); i++) {
		if (pomocni[i] != 0) 
			bez_nula.push_back(pomocni[i]);
	}
	bool ista_parnost(true);
	
	for (int i=1; i<bez_nula.size(); i++) {
		if (parna(bez_nula[i-1]) != parna(bez_nula[i] )) {
			ista_parnost = 0;
			break;
		}
	}
	if (ista_parnost == 0)
		return 0;
	return bez_nula[0];
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool vrijednost) {
	if (v.size() == 0)
		return v;
		
	
	std::vector<int> v1;
	if (vrijednost == false) {
		for (int i(0); i<v.size(); i++) {
			if (parnost(v[i]) % 2 != 0)
				v1.push_back(v[i]);
		}
	}
	else {
		for (int i=0; i<v.size(); i++) {
			if (parnost(v[i]) % 2 == 0 && parnost(v[i]) != 0)
				v1.push_back(v[i]);
		}
	}
	for (int i=0; i<v1.size(); i++) {
		for (int j=i+1; j<v1.size(); j++) {
			if (v1[i] == v1[j])
				v1.erase (v1.begin() + j);
		}
	}
	
	for (int i=0; i<v1.size(); i++) {
		for (int j=i+1; j<v1.size(); j++) {
			if (v1[i] == v1[j])
				v1.erase(v1.begin() + j);
		}
	}
	return v1;
}

int main ()
{
	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for (;;) {
		int a;
		std::cin >> a;
		if (a == 0)
			break;
		else
			v.push_back(a);
	}
	
	std::vector<int> pomocni(v);
	
	std::cout << "Opaki: ";
	v = IzdvojiGadne(v, true);
	for (int i=0; i<v.size(); i++)
		std::cout << v[i] << " ";
		
	std::cout << std::endl << "Odvratni: ";
	pomocni = IzdvojiGadne(pomocni, false);
	for (int i=0; i<pomocni.size(); i++)
		std::cout << pomocni[i] << " ";
	
	return 0;
}