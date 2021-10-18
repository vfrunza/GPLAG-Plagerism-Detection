/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

/*long long int Stepen (int baza, int eksponent) {
	long long int pom(1);
	for (int i = 0; i < eksponent; i++)
		pom *= baza;
	return pom;
}*/

long long int PretvoriUTernarni (int x) {
	long long int ter(0);
	for (int i = 0; x != 0; i++) {
		ter = ter + (x % 3) * pow(10,i);
		x /= 3;
	}
	return ter;
}

std::vector<int> PrebrojiPonavljanja (long long int x) {
	if (x < 0) x *= (-1);
	std::vector<int> brojaci(3);
	while (x != 0) {
		brojaci[x%10]++;
		x /= 10;
	}
	return brojaci;
}

bool DaLiJeOpak (int x) {
	bool istinitost(true);
	std::vector<int> brojPonavljanja(PrebrojiPonavljanja(PretvoriUTernarni(x)));
	for (int i = 0; i < 3; i++) {
		if (brojPonavljanja[i] % 2 != 0) {
			istinitost = false;
			break;
		}
	}
	return istinitost;
}

bool DaLiJeOdvratan (int x) {
	bool istinitost(true);
	std::vector<int> brojPonavljanja(PrebrojiPonavljanja(PretvoriUTernarni(x)));
	for (int i = 0; i < 3; i++) {
		if (brojPonavljanja[i] % 2 == 0 && brojPonavljanja[i] != 0) {
			istinitost = false;
			break;
		}
	}
	return istinitost;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool b) {
	std::vector<int> tempVector;
	if (b == true) {
		for (int i = 0; i < v.size(); i++) {
			if (DaLiJeOpak(v.at(i)) == true)
				tempVector.push_back(v.at(i));
		}
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			if (DaLiJeOdvratan(v.at(i)) == true)
				tempVector.push_back(v.at(i));
		}
	}
	
	for (int i = 0; i < tempVector.size(); i++) {
		if (i == tempVector.size() - 1 || tempVector.size() == 0) break;
		for (int j = i + 1; j < tempVector.size(); j++) {
			if (tempVector.at(i) == tempVector.at(j)) {
				tempVector.erase(tempVector.begin() + j);
				j--;
			}
		}
	}
	return tempVector;
}

int main ()
{
	std::vector<int> v;
	int a, brojac(0);
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	/*std::cin >> a;
	while (a != 0) {
		v.push_back(a);
		std::cin >> a;
	}*/
	do {
		std::cin >> a;
		v.push_back(a);
		brojac++;
	} while(a != 0);
	if (brojac > 1) v.erase(v.begin() + brojac - 1);
	std::vector<int> Opaki(IzdvojiGadne(v,true));
	std::vector<int> Odvratni(IzdvojiGadne(v,false));
	if (Opaki.size() != 0) {
		std::cout << "Opaki:";
		for (int i = 0; i < Opaki.size(); i++) {
			std::cout << " " << Opaki.at(i);
		}
		std::cout << std::endl;
	}
	if (Odvratni.size() != 0) {
		std::cout << "Odvratni:";
		for (int i = 0; i < Odvratni.size(); i++) {
			std::cout << " " << Odvratni.at(i);
		}
		std::cout << std::endl;
	}
	return 0;
}