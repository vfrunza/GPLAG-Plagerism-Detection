#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst(int n, bool p)
{
	if (n==1) {
		if (p)
			return false;
		else
			return true;
	}
	if (n<0) n*=-1;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i==0) {
			if (p)
				return false;
			else
				return true;
		}
	}
	if (p)
		return true;
	else
		return false;
}

unsigned long long int Obrni(unsigned long long int n)
{
	unsigned long long int novi_broj(0);
	unsigned long long int temp(n);
	int brojac(0);
	do {
		temp/=10;
		brojac++;
	} while(temp!=0);
	for (; brojac!=0; brojac--) {
		novi_broj+=n%10*(unsigned long long int)(pow(10,brojac-1));
		n/=10;
	}
	return novi_broj;
}

bool Simetrican(int n)
{
	unsigned long long int broj(0);
	if (n<0) n*=-1;
	for (int i = 0; n!=0; i++) {
		broj+=(n%3)*(unsigned long long int)(pow(10,i));
		n/=3;
	}
	unsigned long long int ob_broj=Obrni(broj);
	if (ob_broj==broj)
		return true;
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool prosti)
{
	std::vector<int> novi;
	for (int i = 0; i < v.size(); i++) {
		if (DaLiJeProst(v.at(i),prosti) && Simetrican(v.at(i))) {
			int j(0);
			for (j = 0; j < novi.size(); j++) {
				if (v.at(i)==novi.at(j))
					break;
			}
			if (j==novi.size())
				novi.push_back(v.at(i));
		}
	}
	return novi;
}


int main ()
{
	std::vector<int> v;
	int broj;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> broj;
		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Neispravan unos! Unesite ponovo: ";
		} else {
			if (broj==-1)
				break;
			v.push_back(broj);
		}
	} while(1);

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin >> broj;
		if (!std::cin || (broj!=0 && broj!=1)) {
			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			std::cout << "Neispravan unos! Unesite ponovo: ";
		} else
			break;
	} while(1);

	std::vector<int> novi_v=IzdvojiSimetricneTernarne(v, broj);

	if (broj==1) {
		if (!novi_v.size()) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		} else
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
	} else {
		if (!novi_v.size()) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		} else
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	}
	for (int i = 0; i < novi_v.size(); i++) {
		if (i==novi_v.size()-1)
			std::cout << novi_v.at(i) << ".";
		else
			std::cout << novi_v.at(i) << ", ";
	}

	return 0;
}