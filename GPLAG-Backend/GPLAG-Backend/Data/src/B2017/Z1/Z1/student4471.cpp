#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

int Stepen(int x, int n) noexcept {
	if (n == 0) return 1;
	int a(x);
	for (int i = 2; i <= n; i++)
		a *= x;
	return a;
}

int MaxTernarni(int x) {
	int max(0);
	while (abs(x) >= 3) {
		x /= 3;
		max++;
	}
	return max;
}

unsigned long long Ternarni(int x) {
	unsigned long long ter(0);
	int stepen(MaxTernarni(x)), a;
	x = abs(x);
	while (stepen >= 0) {
		a = Stepen(3,stepen);
		ter = ter*10 + x/a;
		if(a <= x) x -= (x/a)*a;
		stepen--;
	}
	return ter;
}

bool Simetrican(unsigned long long x) {
	unsigned long long a(x), b(0);
	while (a != 0) {
		b = b*10 + a%10;
		a /= 10;
	}
	return x == b;
}

bool Prost(int x) {
	for (int i = 2; i <= sqrt(abs(x)); i++)
		if (x % i == 0) return false;
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vekt, bool ps) {
	std::vector<int> novi;
	if (ps) 
		for (int x : vekt) {
			bool isti(false);
			if (Prost(x) && Simetrican(Ternarni(x)) && x != 1) {
				for (int y : novi) if (y == x) isti = true;
				if (!isti) novi.push_back(x);
			}
		}
	else
		for (int x : vekt) {
			bool isti(false);
			if (!Prost(x) && Simetrican(Ternarni(x)) && x != 1) {
				for (int y : novi) if (y == x) isti = true;
				if (!isti) novi.push_back(x);
			}
		}
	return novi;
}

int main ()
{
	std::vector<int> vekt;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	int a, bul;
	while (std::cin >> a, a != -1) vekt.push_back(a);
	bool ps;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(std::cin >> bul, bul != 1 && bul != 0) std::cout << "Neispravan unos! Unesite ponovo: ";
	ps = bul;
	std::vector<int> novi(IzdvojiSimetricneTernarne(vekt,ps));
	if (ps) {
		if (novi.size() == 0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else std::cout << "Prosti simetricni brojevi iz vektora su: ";
	}
	else {
		if (novi.size() == 0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	}
	try {
		if (novi.size() != 0) {
			for (int i = 0; i < novi.size(); i++) {
				std::cout << novi.at(i);
				if (i != novi.size()-1) std::cout << ", ";
				if (i == novi.size()-1) break;
			}
			std::cout << ".";
		}
	}
	catch (std::range_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}